/*****************************************************************************
 * logger.cpp
 *
 * begin   : Tue Feb 04 14:39:24 2014
 *
 * This file is part of OSAUT and OSORNOD projects. OSAUT is a free definition,
 * ehich may be used under the Creative Commons Share-alike license with the
 * additional condition of notifying the original author(s) of deviations and
 * expansion of the work.OSORNOD is intended to be released in the near future
 * as free software that you then can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free 
 * Software Foundation, version 3. However,up to that point, OSORNOD software
 * and any or all of its components are proprietary and may not be modified or
 * distributed without express approval of Osorno Enterprises Inc.
 *
 * This program is distributed WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * A copy of the GNU General Public License can be obtained from the Free 
 * Software Foundation, Inc., 51  Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301 USA.
 *
 * Copyright Osorno Enterprises Inc., 2014
 *
 * OSAUT and OSORNOD project
 * (c) Osorno Enterprises Inc., 2014: http://www.osorno.ca/
 * 
 ****************************************************************************/

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <bzlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <string.h>
#include <stdarg.h>
#include <time.h>
#include <unistd.h>

#include "logger.h"
//#include "shamembio.h"
#include "shamemchl.h"
const char *message_types[7] = {
  "",       //! LOG_UNDEFINED
  "error",  //! LOG_MSG_CRIT error printed into the log-file & message-table
  "warning",//! LOG_MSG_WARN warning printed into the log-file & message-table
  "info",   //! LOG_MSG_INFO info-msg printed into the log-file & message-table
  "error",  //! LOG_CRITICAL error printed only into the log-file
  "warning",//! LOG_WARNING  warning printed only into the log-file
  "info"    //! LOG_INFORM   info-msg printed only into the log-file
};


const char* msg_imgs[7] = {
 EMPTY_IMAGE,    //! empty   image, used in masks 1,3,4
 ALERT_COLOR,    //! alert   image, used in mask  3
 WARNING_COLOR,  //! warning image, used in mask  3
 INFORM_COLOR,   //! info    image, used in mask  3
 ALERT_GREY,     //! alert   image, used in masks 1,4
 WARNING_GREY,   //! warning image, used in masks 1.4
 INFORM_GREY     //! info    image, used in masks 1,4
};

//!****************************************************************************
void log_init()
{
  FILE *fp = NULL;
  int   c;             //! IMPORTANT!  int (not char) for the EOF 
  
  if (access(LOGFILE, F_OK) != -1){
     fp = fopen(LOGFILE, "r");

     if (fp == NULL){
        printf ("log_init(): fp == NULL\n");
        fclose(fp);
     } else {
        while ((c = fgetc(fp)) != EOF){
            if (c == '\n' ){
               log_line_count++;
            }
        }
        fclose(fp);
     }
  } else {
     //! global variable
     log_line_count = 0;
  }
  printf ("log_init(): log_line_count = %ld\n", log_line_count);
}

//!*******************************************************************************
void compress_log_file(const char *log_filename, char *bz2_filename)
{
  const int BLOCK_MULTIPLIER = 7;
  int     bz_error;
  int     bytes_read;
  
  char buf[CHUNK];

  FILE   *log_fp = NULL;
  FILE   *bz2_fp = NULL;
  BZFILE *bzp    = NULL;
  
  log_fp = fopen(log_filename, "r");

  if (log_fp == NULL) {
     printf("compress_log_file() failed opening file %s\n", log_filename);
     return;
  }

  bz2_fp = fopen(bz2_filename, "w");
  
  if (bz2_fp == NULL) {
     printf("compress_log_file() failed opening file %s\n", bz2_filename);
     fclose(log_fp);
     return;
  }
  
  bzp = BZ2_bzWriteOpen( &bz_error, bz2_fp, BLOCK_MULTIPLIER, 0, 0);
  
  if (bz_error == BZ_OK){
     fseek(log_fp, SEEK_SET, 0);
     while ((bytes_read = (int)fread(buf, 1, sizeof buf, log_fp)) > 0){

           BZ2_bzWrite(&bz_error, bzp, buf, bytes_read);
     }
  } else {
     printf("compress_log_file() failed BZ2_bzWriteOpen() call\n");
  }
  
  BZ2_bzWriteClose(&bz_error, bzp, 0, NULL, NULL);
  fclose(log_fp);
  fclose(bz2_fp);
  
  return;
}
 
//!****************************************************************************
void rotate_log_file(const char *log_filename)
{
  char old_fname[_SIZE_QK] = "";
  char new_fname[_SIZE_QK] = "";
  char bz2_fname[_SIZE_QK] = "";
  int  nn = 0;
  
  //! counting the number of existed compressed log-files
  do{
     nn++;
     sprintf(bz2_fname, "%s.%d.%s", log_filename, nn, BZ2_EXT);
     
  }while (access(bz2_fname, F_OK) != -1);
  
  //! rotation for existed compressed log-files
  for (int i = nn; i > 1; i--){
      sprintf(new_fname, "%s.%d.%s", log_filename, i,   BZ2_EXT);
      sprintf(old_fname, "%s.%d.%s", log_filename, i-1, BZ2_EXT);
      
      if (rename(old_fname, new_fname) == 0){
         printf("File renamed successfully\n");
      } else {
         printf("Error: unable to rename the file\n");
      }
  }
  //! the newest compressed log-file always has the name "<name>.log.1.bz2"
  sprintf(bz2_fname, "%s.1.%s", log_filename, BZ2_EXT);
  
printf("rotate_log_file(): bz2_fname = %s\n", bz2_fname);  
  compress_log_file(log_filename, bz2_fname);
}

//!****************************************************************************
//! buf - output timeprint in the text format: 'Month-dd-yy hh:mm' 
//! val - output timeprint - string which represent abs number: yydddhhmmssmks
//!       (foe example: 1400105595999999 - 1 mks before Jan-1 2014 6:00 am )
//!****************************************************************************
void print_time(char *buf, char *val)
{
  char mks[10] = "";
  time_t rawtime;
  struct tm *timeinfo;
  struct timeval t0;

  time (&rawtime);
  gettimeofday (&t0, 0);
  timeinfo = localtime(&rawtime);
 
  if (buf != NULL){
     strftime (buf,24,"%h-%d-%y %I:%M %p",timeinfo);
  }
  
  if (val != NULL){
     strftime (val,24,"%y%j%H%M%S",timeinfo);
     sprintf(mks, "%06ld", (long int)t0.tv_usec);
     strcat(val, mks);
  }
}

//!****************************************************************************
void record_calibration_time(char *timerecord)
{
  time_t rawtime;
  struct tm *timeinfo;

  time (&rawtime);
  timeinfo = localtime(&rawtime);
 
  if (timerecord != NULL){
     strftime (timerecord,24,"%y%j",timeinfo);
  }
}

//!****************************************************************************
static void copy_one_msg_tbl_record(int dst, int srs)
{
  (msg_tbl->rows[dst]).selected = (msg_tbl->rows[srs]).selected;
  (msg_tbl->rows[dst]).msg_type = (msg_tbl->rows[srs]).msg_type;
  strcpy ((msg_tbl->rows[dst]).msg,      (msg_tbl->rows[srs]).msg);
  strcpy ((msg_tbl->rows[dst]).time_txt, (msg_tbl->rows[srs]).time_txt);
  strcpy ((msg_tbl->rows[dst]).time_num, (msg_tbl->rows[srs]).time_num);
}

//!****************************************************************************
static void clear_one_msg_tbl_record(int i)
{
  (msg_tbl->rows[i]).selected = 0;
  (msg_tbl->rows[i]).msg_type = LOG_UNDEFINED;
  strcpy ((msg_tbl->rows[i]).msg,      "");
  strcpy ((msg_tbl->rows[i]).time_txt, "");
  strcpy ((msg_tbl->rows[i]).time_num, "");
}

//!****************************************************************************
void log_print(int msg_type, char* fmt,...)
{
  char *p, *r, val[24] = "", buf[24] = "";
  char tmp[_SIZE_EK] = "", raw_msg[_SIZE_QK] = "";
  int  e, index, add_tbl_row = 0;
  FILE *log_fp = NULL;
  va_list list;

printf("log_print(): >>>>>>>>>>>>>>>>>>>>\n");
  if (log_line_count < MAX_LOGFILE_RECORDS){
     log_fp = fopen (LOGFILE,"a+");
  } else {
     rotate_log_file(LOGFILE);
     log_fp = fopen (LOGFILE,"w");
     log_line_count = 0;
  }

  if (log_fp == NULL) return;

  add_tbl_row = (msg_type == LOG_MSG_CRIT ||
                 msg_type == LOG_MSG_WARN ||
                 msg_type == LOG_MSG_INFO);

  print_time(buf, val);
  fprintf(log_fp, "%s\t", buf);
  fprintf(log_fp, "%s\t", message_types[msg_type]);

  va_start(list, fmt);
  for (p = fmt ; *p ; ++p){
      if (*p != '%'){ 
         //! if simple string 
         sprintf (tmp, "%c", *p);
         fputc(*p, log_fp);
      } else {
         switch (*++p){
            //! string 
            case 's': r = va_arg (list, char *);
                      sprintf (tmp, "%s", r);
                      fprintf(log_fp,"%s", r);
                      break;
            //! integer 
            case 'd': e = va_arg (list, int);
                      sprintf (tmp, "%d", e);
                      fprintf(log_fp,"%d", e);
                      break;
            default:  sprintf (tmp, "%c", *p);
                      fputc(*p, log_fp);
         }
      }
      strcat(raw_msg, tmp);
  }
  va_end(list);

  fputc('\n', log_fp);
  log_line_count++;
  
  fclose(log_fp);

  if (add_tbl_row){
    
     index = msg_tbl->rows_num - 1;
     
     if (index == MAX_TBLFILE_RECORDS-1){ //! clear the oldest record
        clear_one_msg_tbl_record(index);

        msg_tbl->rows_num -=1;
        index--;
     }

     for (int i = index; i >= 0; i--){ //! shift all records one row downward
         copy_one_msg_tbl_record(i+1, i);
     }
     //! new record initializing
     (msg_tbl->rows[0]).selected = 0;
     (msg_tbl->rows[0]).msg_type = msg_type;
     strcpy ((msg_tbl->rows[0]).msg, raw_msg);
     strcpy ((msg_tbl->rows[0]).time_txt, buf);
     strcpy ((msg_tbl->rows[0]).time_num, val);
     
     msg_tbl->rows_num += 1;
  }
}

#if 0
//!****************************************************************************
void erase_selected_row(int index)
{
  if (index < 0 || index > MAX_TBLFILE_RECORDS-1) return;
  
  free (msg_tbl->rows[index]);
  if (index == MAX_TBLFILE_RECORDS-1){
     msg_tbl->rows[index] = NULL;
  } else {
     for (int i = index; i < MAX_TBLFILE_RECORDS-1; i++){
        if (msg_tbl->rows[i+1] != NULL){
            msg_tbl->rows[i] = msg_tbl->rows[i+1];
        } else {
            msg_tbl->rows[i] = NULL;
            break;
        }
     }
  }
  msg_tbl->rows_num -= 1;
}
#endif

//!****************************************************************************
void erase_selected_rows()
{
  int j = 0, erased = 0;

  for (int i = 0; i < msg_tbl->rows_num; i++){
      if ((msg_tbl->rows[i]).selected == 1){
         clear_one_msg_tbl_record(i);
         erased++;
      }
  }
  
  if (erased == msg_tbl->rows_num){

     msg_tbl->rows_num = 0;
     return;
     
  } else {
     for (int i = 0; i < msg_tbl->rows_num; i++){
         //! 'j' is the first unchecked for nill array member
         if ((msg_tbl->rows[i]).msg_type != LOG_UNDEFINED){
            j += 1;   
            continue;
         }

         while ((msg_tbl->rows[j]).msg_type == LOG_UNDEFINED &&
                j < msg_tbl->rows_num){
            j += 1;   
         }

         if ((msg_tbl->rows[j]).msg_type != LOG_UNDEFINED){

            copy_one_msg_tbl_record(i, j);
            clear_one_msg_tbl_record(j);
            j += 1;
         }
     }
     msg_tbl->rows_num -= erased;
  }
}