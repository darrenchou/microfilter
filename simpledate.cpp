/*****************************************************************************
 * simpledate.cpp
 *
 * begin   : Thu Aug 11 10:16:02 2016
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
 * Copyright Osorno Enterprises Inc., 2016
 *
 * OSAUT and OSORNOD project
 * (c) Osorno Enterprises Inc., 2016: http://www.osorno.ca/
 * 
 ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include "simpledate.h"

const int reg_days_in_month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
const int leap_days_in_month[12] = {31,29,31,30,31,30,31,31,30,31,30,31};

//!****************************************************************************
void zeroing_simple_date(simple_date_t *date)
{
  if (date != NULL){
     date->year     = 0;
     date->month    = 0;
     date->week     = 0;
     date->day      = 0;
     date->week_day = 0;
     date->hour     = 0;
     date->minute   = 0;
     date->second   = 0;
  }
}

//!****************************************************************************
int set_simple_time(simple_date_t *date, int hour, int minute, int second)
{
  int succeed = 0;
  
  if (date != NULL && is_valid_time(hour, minute, second)){
     date->hour     = hour;
     date->minute   = minute;
     date->second   = second;
     succeed        = 1;
  }
  return succeed;
}

//!****************************************************************************
void set_min_time(simple_date_t *date)
{
  if (date != NULL){
     date->hour     = 0;
     date->minute   = 0;
     date->second   = 0;
  }
}

//!****************************************************************************
void set_max_time(simple_date_t *date)
{
  if (date != NULL){
     date->hour     = 23;
     date->minute   = 59;
     date->second   = 59;
  }
}

//!****************************************************************************
void convert_unix_time_to_simple_date(long int unix_time, simple_date_t *date)
{
  char tmp[64] = "";
  struct tm *timeinfo;

  if (date == NULL) return;
  
  timeinfo = localtime(&unix_time);
  
  strftime (tmp, 64, "%Y", timeinfo); //! Year full number
  date->year = (unsigned int)(atoi(tmp));

  strftime (tmp, 64, "%m", timeinfo); //! Month as a decimal number (01-12)
  date->month = (unsigned int)(atoi(tmp));

  strftime (tmp, 64, "%W", timeinfo); //! Week of the year number (0-53)
  date->week = (unsigned int)(atoi(tmp));
  
  strftime (tmp, 64, "%d", timeinfo); //! Day of the month (01-31)
  date->day = (unsigned int)(atoi(tmp));

  strftime (tmp, 64, "%u", timeinfo); //! Week day (1-7) Monday - the first
  date->week_day = (unsigned int)(atoi(tmp));

  strftime (tmp, 64, "%H", timeinfo); //! Hour of the day (0-23)
  date->hour = (unsigned int)(atoi(tmp));

  strftime (tmp, 64, "%M", timeinfo); //! Minute of the hour (0-59)
  date->minute = (unsigned int)(atoi(tmp));

  strftime (tmp, 64, "%S", timeinfo); //! Second of the minute (0-59)
  date->second = (unsigned int)(atoi(tmp));
}

//!****************************************************************************
void set_cur_date(simple_date_t *date)
{
  time_t rawtime;
  struct tm *timeinfo;

  if (date == NULL) return;
  
  time (&rawtime);
  timeinfo = localtime(&rawtime);
  convert_unix_time_to_simple_date(rawtime, date);
}

//!****************************************************************************
void set_the_latest_osornod_date(simple_date_t *date)
{
  if (date != NULL){
     date->year  = OSORNOD_MAX_YEAR;
     date->month = 12;
     date->day   = 31;
     date->week  = 52;
     set_max_time(date);
  }
}

//!****************************************************************************
void set_the_earliest_osornod_date(simple_date_t *date)
{
  if (date != NULL){
     date->year  = OSORNOD_MIN_YEAR;
     date->month = 1;
     date->day   = 1;
     date->week  = 0;
     set_min_time(date);
  }
}

//!****************************************************************************
int set_date_by_ymd(simple_date_t *date, int y, int mo, int d)
{
  int succeed = 0;
  
  if (date != NULL && is_valid_date(y,mo,d)){
     date->year     = y;
     date->month    = mo;
     date->week     = getWeek(y, mo, d);
     date->day      = d;
     date->week_day = getWeekDay(y, mo, d);
     succeed        = 1;
  }
  return succeed;
}

//!****************************************************************************
int set_date_by_ywd(simple_date_t *date, int y, int w, int wd)
{
  int succeed      = 0;
  int leap_year    = 0;
  int days_counter = 0;
  int absolute_day = 0;
  int month_days   = 0;
  int max_days_num = NUM_DAYS_IN_A_YEAR;
  
  if (date != NULL && is_valid_weekdate(y,w,wd)){
     date->year     = y;
     date->week     = w;
     date->week_day = wd;
     
     absolute_day = w * NUM_DAYS_IN_WEEK + wd;
     
     leap_year    = is_a_leap_year(y);
     max_days_num = (leap_year)? max_days_num+1: max_days_num;
     
     for (int i = 0; i < 12; i++){
         month_days = (leap_year)? leap_days_in_month[i]: reg_days_in_month[i];
         days_counter = days_counter + month_days;
         
         if (days_counter >= absolute_day){
            date->month = i+1;
            date->day   = absolute_day - (days_counter - month_days);
            break;
         }
     }
     succeed = 1;
  }
  return succeed;
}

//!****************************************************************************
int set_datetime(simple_date_t *date, int y, int mo, int w, int wd, int d,
                                      int h, int mi, int s, int set_flag)
{
  int succeed = 0;
  
  if (date != NULL && is_valid_time(h, mi, s)){
     date->hour     = h;
     date->minute   = mi;
     date->second   = s;
     
     if (set_flag == SET_DATE_BY_YMD){
        succeed = set_date_by_ymd(date, y, mo, d);
     }
     
     if (set_flag == SET_DATE_BY_YWD){
        succeed = set_date_by_ywd(date, y, w, wd);
     }
     
     if (set_flag != SET_DATE_BY_YMD && set_flag != SET_DATE_BY_YWD){
        if (is_valid_date(y,mo,d)){
           succeed = set_date_by_ymd(date, y, mo, d);
        } else if (is_valid_weekdate(y,w,wd)){
           succeed = set_date_by_ywd(date, y, w, wd);
        }
     }
  }
  if (!succeed){
     printf("set_datetime() ERROR: wrong setting value(s)!\n");
  }
  return succeed;
}

//!****************************************************************************
int set_date_mintime(simple_date_t *date, int y, int mo, int d)
{
  return set_datetime(date, y, mo, 0, 0, d, 0, 0, 0, SET_DATE_BY_YMD);
}

//!****************************************************************************
int set_date_maxtime(simple_date_t *date, int y, int mo, int d)
{
  return set_datetime(date, y, mo, 0, 0, d, 23, 59, 59, SET_DATE_BY_YMD);
}

//!****************************************************************************
int set_date_hour(simple_date_t *date, int y, int mo, int d, int h)
{
  return set_datetime(date, y, mo, 0, 0, d, h, 0, 0, SET_DATE_BY_YMD);
}

//!****************************************************************************
int is_a_leap_year(int year_to_check)
{
  int answer = 0;
  int leap_year = MILLENNIUM_YEAR; //! 2000

  do{
    if (year_to_check == leap_year){
       answer = 1;
       break;
    }
    leap_year = leap_year + 4;
  } while (year_to_check >= leap_year);

  return answer;
}

//!****************************************************************************
int is_valid_year(int year)
{
  return (year >= OSORNOD_MIN_YEAR && year < OSORNOD_MAX_YEAR);
}

//!****************************************************************************
int is_valid_month(int month)
{
  return (month > 0  && month <= 12);
}

//!****************************************************************************
int is_valid_week(int week, int year)
{
  int last_week = 0, valid = 0;
  
  last_week = getWeek(year,12,31);
  valid = (week >= 0 && week <= last_week);
  
  return valid;
}

//!****************************************************************************
int is_valid_date(int year, int month, int day)
{
  int valid = 0;
  int last_day = 0;
  
  if (is_valid_year(year) && is_valid_month(month)){
    
     if (is_a_leap_year(year)){
        last_day = leap_days_in_month[month-1];
     } else {
        last_day = reg_days_in_month[month-1];
     }

     if (day > 0 && day <= last_day){
           valid = 1;
     }
  }
  return valid;
}

//!****************************************************************************
int is_valid_weekdate(int year, int week, int wday)
{
  int valid = 0;
  int first_wday = 0, last_wday = 0, last_week = 0;
  
  if (is_valid_year(year)){
     first_wday = getWeekDay(year, 1, 1);
     last_wday  = getWeekDay(year,12,31);
     last_week  = getWeek(year,12,31);
     
     if (week >= 0 && week <= last_week && wday > 0 && wday <= 7){
        valid = ((week == 0 && wday >= first_wday) ||
                 (week == last_week && wday <= last_wday) ||
                 (week > 0 && week < last_week && wday > 0 && wday <= 7));
     }
  }
  return valid;
}

//!****************************************************************************
int is_valid_time(int hour, int minute, int second)
{
  return (hour >= 0 && hour < 24 && minute >= 0 && minute < 60 &&
          second>= 0 && second < 60);
}

//!****************************************************************************
int is_current_date(int y, int mo, int d)
{
   return (y == get_cur_year() && mo == get_cur_month() && d == get_cur_day());
}

//!****************************************************************************
int is_future_date(simple_date_t *date_to_check)
{
  int result = 0;
  simple_date_t  cur_date;

  if (date_to_check == NULL) return 0;
  
  set_cur_date(&cur_date);
  if (is_valid_date(date_to_check->year,date_to_check->month,date_to_check->day)){
     result = (result || date_to_check->year > cur_date.year);
     result = (result || (date_to_check->year == cur_date.year &&
                          date_to_check->month > cur_date.month));
     result = (result || (date_to_check->year == cur_date.year &&
                          date_to_check->month == cur_date.month &&
                          date_to_check->day > cur_date.day));
  }
  return result;
}

//!****************************************************************************
static unsigned int get_cur_time_value(int time_key)
{
  simple_date_t  cur_date;

  set_cur_date(&cur_date);
  switch (time_key){
     case CURRENT_SEC  :return cur_date.second;
     case CURRENT_MIN  :return cur_date.minute;
     case CURRENT_HOUR :return cur_date.hour;
     case CURRENT_DAY  :return cur_date.day;
     case CURRENT_WDAY :return cur_date.week_day;
     case CURRENT_WEEK :return cur_date.week;
     case CURRENT_MONTH:return cur_date.month;
     case CURRENT_YEAR :return cur_date.year;
  }
}

//!****************************************************************************
unsigned int get_cur_second()
{
  return get_cur_time_value(CURRENT_SEC);
}

//!****************************************************************************
unsigned int get_cur_minute()
{
  return get_cur_time_value(CURRENT_MIN);
}

//!****************************************************************************
unsigned int get_cur_hour()
{
  return get_cur_time_value(CURRENT_HOUR);
}

//!****************************************************************************
unsigned int get_cur_day()
{
  return get_cur_time_value(CURRENT_DAY);
}

//!****************************************************************************
unsigned int get_cur_wday()
{
  return get_cur_time_value(CURRENT_WDAY);
}

//!****************************************************************************
unsigned int get_cur_week()
{
  return get_cur_time_value(CURRENT_WEEK);
}

//!****************************************************************************
unsigned int get_cur_month()
{
  return get_cur_time_value(CURRENT_MONTH);
}

//!****************************************************************************
unsigned int get_cur_year()
{
  return get_cur_time_value(CURRENT_YEAR);
}

//!****************************************************************************
//! Calculating the week day (1-7: Monday-Sunday) for the input date
//!****************************************************************************
//! arguments: int: year, month (1-12), day (1-28/29/30/31)
//! returns  : week day if succeed or 0 if not
//!****************************************************************************
int getWeekDay(int year, int month, int day)
{
  int week_day = 0;
  char timebuf[64];
  struct tm tm;

  memset(&tm, 0, sizeof(struct tm));

  if (is_valid_date(year, month, day)){
    
     //tm.tm_sec = 0;
     //tm.tm_min = 0;
     //tm.tm_hour = 0;
     tm.tm_mday = day;
     tm.tm_mon  = month - 1;
     tm.tm_year = year - START_COMP_YEAR;
     
     mktime(&tm);

     //! '%u' ISO 8601 weekday as number with Monday as 1 (1-7)
     strftime (timebuf, sizeof(timebuf),"%u", &tm);
     //printf("getWeekDay(): week day number = %s\n", timebuf);

     //! convert char to int
     week_day = atoi(timebuf);
  }
  return week_day;
}

//!****************************************************************************
//! Calculating absolute week number for the input date
//!****************************************************************************
//! arguments: int: year, month (1-12), day (1-31)
//! returns  : week number if succeed or UNDEF_UNSIGNEDINT if not
//!****************************************************************************
int getWeek(int year, int month, int day)
{
  int week = UNDEF_UNSIGNEDINT;
  char timebuf[64];
  struct tm tm;

  memset(&tm, 0, sizeof(struct tm));

  if (is_valid_date(year, month, day)){
    
     //tm.tm_sec = 0;
     //tm.tm_min = 0;
     //tm.tm_hour = 0;
     tm.tm_mday = day;
     tm.tm_mon  = month - 1;
     tm.tm_year = year - START_COMP_YEAR;
     
     mktime(&tm);
     //! Week number with the first Monday as the first day of week one (00-53)
     strftime (timebuf, sizeof(timebuf),"%W", &tm);
     //printf("getWeek(): week number = %s\n", timebuf);
     //! convert char to int
     week = atoi(timebuf);
  } else {
     printf("ERROR in getWeek(): arguments are not valid.");
  }
  return week;
}

//!****************************************************************************
//! Calculating date and month by year and absolute day number (1-365/366).
//!****************************************************************************
//! arguments: int: year, week (0-53), week_day ('1' or '7' - Monday or Sunday)
//! output   : date->year, date->month, date->day, date->week, date->week_day
//! returns  : '1' if succeed, '0' if failed
//!****************************************************************************
int set_day_month_by_year_abs_day(simple_date *date, int year, int abs_day)
{
  int tmp_day = 0, leap_year = 0;
  int is_valid_input = 1;

  if (is_valid_year(year)){
     leap_year  = is_a_leap_year(year);
     
     is_valid_input = (leap_year)? (abs_day > 0 && abs_day <= 366):
                                   (abs_day > 0 && abs_day <= 365);
     if (!is_valid_input){
        printf("set_day_month_by_abs_day_and_year() ERROR: abs_day value\n");
     }
  } else {
     printf("set_day_month_by_abs_day_and_year() ERROR: year value\n");
     is_valid_input = 0;
  }

  if (date == NULL || !is_valid_input) return 0;

  tmp_day = abs_day;
  for (int i = 0; i < 12; i++){
     if (leap_year){
        if (tmp_day - leap_days_in_month[i] > 0){
           tmp_day = tmp_day - leap_days_in_month[i];
        } else {
           date->month = i+1;
           date->day   = tmp_day;
           break;
        }
     } else {
        if (tmp_day - reg_days_in_month[i] > 0){
           tmp_day = tmp_day - reg_days_in_month[i];
        } else {
           date->month = i+1;
           date->day   = tmp_day;
           break;
        }
     }
  }
  return 1;
}

//!****************************************************************************
//! Calculating date for Monday or Sunday by year & week number.
//!****************************************************************************
//! arguments: int: year, week (0-53), week_day ('1' or '7' - Monday or Sunday)
//! output   : date->year, date->month, date->day, date->week, date->week_day
//! returns  : '1' if succeed, '0' if failed
//!****************************************************************************
int set_week_day_by_week(simple_date *date, int year, int week, int week_day)
{
  int succeed = 1;
  int jan1_week_day = 0;  //! week day of January 1-st of the year
  int abs_day       = 0;  //! 1-365 (or 1-366 if a leap year)
  int days_shift    = 0, prev_shift = 0;
  int leap_year     = 0, leap_prev  = 0;

  if (date == NULL) return 0;
  
  if (is_valid_year(year) && is_valid_week(week, year))
  {
    //! week-day of the January 1-st of the input year
    jan1_week_day = getWeekDay(year, 1, 1); 
    
    //! days_shift iz zero if January 1-st is Monday
    days_shift = jan1_week_day - 1;  
    leap_year  = is_a_leap_year(year);
    
    //! week-day of the January 1-st of the previous year
    jan1_week_day = getWeekDay(year - 1, 1, 1);
    leap_prev = is_a_leap_year(year-1);
    prev_shift = jan1_week_day - 1;

  } else {
    printf("set_week_day_by_week() ERROR: not valid arguments\n");
    return 0;
  }

  date->week_day = week_day;

  switch (week_day){
    
    case 1: //! week day is Monday
            if (week == 0){
               if (days_shift == 0){ //! year starts on Monday
                  date->year  = year;
                  date->month = 1;
                  date->day   = 1;
                  date->week  = 0; 

               } else { //! Monday is at the previous year
                  date->year  = year - 1;
                  date->month = 12;
                  date->day   = 31 - (days_shift - 1);
                  //! week 53 might be valid just and only in following case:
                  //! year is a leap year and the day of January 1-st is Sunday
                  //! then December 31 is Monday of the 53-th week
                  date->week = (leap_prev && prev_shift == 6)? 53: 52;
               }
            } else if (week == 53 && leap_year && days_shift == 6){
               //! week 53 might be valid just and only in following case:
               //! year is a leap year and the day of January 1-st is Sunday
               //! then December 31 is Monday of the 53-th week
               date->year  = year;
               date->month = 12;
               date->week  = week;
               date->day   = 31;

            } else if (week > 0 && week <= 52) {
               date->year  = year;
               date->week  = week;

               //! abs_day is an absolute day number in a year (1-365/366)
               abs_day = (week * 7 - days_shift + 1);
               //printf("set_week_day_by_week(): abs_day = %d\n", abs_day);

               succeed = set_day_month_by_year_abs_day(date, year, abs_day);

            } else {
                printf("set_week_day_by_week() ERROR: ");
                printf("ineligible condition, week day #1: week = %d\n",week);
                succeed = 0;
            }
            break;

    case 7: //! week day is Sunday
            if (week == 53){
               //! week 53 might be valid just and only in following case:
               //! year is a leap year and January 1-st falls on a Sunday
               //! then December 31 is Monday of the 53-th week
               if (leap_year && days_shift == 6){
                  date->year  = year + 1;
                  date->month = 1;
                  date->day   = 6;
                  date->week  = 0;

               } else {
                  //! ineligible situation, - error !!!
                  printf("set_week_day_by_week() ERROR: no Sunday at 53-d week\n");
                  succeed = 0;
               }
            } else if ((leap_year && week == 52 && days_shift < 5) ||
                      (!leap_year && week == 52 && days_shift < 6)){
               //! date of Sunday is located in the next year
               date->year  = year + 1;
               date->month = 1;
               date->day   = (leap_year)? 5-days_shift: 6-days_shift;
     
            } else if (week >= 0 && week <= 52) {
               date->year  = year;
               date->week  = week;

               abs_day = (week * 7 - days_shift + 7);
               succeed = set_day_month_by_year_abs_day(date, year, abs_day);

            } else {
                printf("set_week_day_by_week() ERROR: ");
                printf("ineligible condition, week day #7: week = %d\n",week);
                succeed = 0;
            }
            break;

      default: succeed = 0;
  }
  return succeed;
}

//!****************************************************************************
//! Calculating the date of the 1-st day of the week (Monday) by two ways:
//! a) according to the date: year, month & day (week suppose to be undefined);
//! b) according to the year & week (month & day suppose to be undefined);
//! note: if all arguments are defined, the date is more powerfull condition.
//!****************************************************************************
//! args   : int: year, month (1-12), day (1-31), week (0-53)
//! output : date->year, date->month, date->day, date->week, date->week_day = 1
//! returns: '1' if succeed, '0' if failed
//!****************************************************************************
int setWeekDay_1(simple_date_t *date, int year, int month, int day, int week)
{
  int succeed = 1;
  int week_day = 0, last_day = 0;

  if (date == NULL) return 0;
  
  if (month == UNDEF_UNSIGNEDINT && day == UNDEF_UNSIGNEDINT &&
      (is_valid_year(year) && is_valid_week(week, year))){

     succeed = set_week_day_by_week(date, year, week, 1);
    
  } else if (is_valid_date(year, month, day)){
    
     week_day = getWeekDay(year, month, day);
     
     if (day - week_day >= 0){
        date->day   = day-(week_day-1);             //! date of day-1 (Monday)
        date->month = month;                        //! same month
        date->year  = year;                         //! same year
       
     } else {
        if (month == 1){
           date->day   = day-(week_day-1)+31;       //! date of day-1 (Monday)
           date->month = 12;                        //! month of December
           date->year  = year - 1;                  //! previous year
          
        } else {
           if (is_a_leap_year(year)){
              last_day = leap_days_in_month[month-2];
           } else {
              last_day = reg_days_in_month[month-2];
           }
           date->day   = day-(week_day-1)+last_day; //! date of day-1 (Monday)
           date->month = month - 1;                 //! previous month
           date->year  = year;                      //! same year
        }
     }
     date->week_day = 1;
     date->week     = getWeek(year, month, day);

  } else {
    printf("ERROR: setWeekDay_1() arguments are not valid!\n");
    succeed = 0;
  }
  return succeed;
}

//!****************************************************************************
//! Calculating the date of the 7-th day of the week (Sunday) by two ways:
//! a) according to the date: year, month & day (week suppose to be undefined);
//! b) according to the year & week (month & day suppose to be undefined);
//! note: if all arguments are defined, the date is more powerfull condition.
//!****************************************************************************
//! args   : int: year, month (1-12), day (1-31), week (0-53)
//! output : date->year, date->month, date->day, date->week, date->week_day = 7
//! returns: '1' if succeed, '0' if failed
//!****************************************************************************
int setWeekDay_7(simple_date_t *date, int year, int month, int day, int week)
{
  int succeed = 1;
  int week_day = 0, last_day = 0;

  if (date == NULL) return 0;
  
  if (month == UNDEF_UNSIGNEDINT && day == UNDEF_UNSIGNEDINT &&
      (is_valid_year(year) && is_valid_week(week, year))){
    
     succeed = set_week_day_by_week(date, year, week, 7);
    
  } else if (is_valid_date(year, month, day)){
    
     week_day = getWeekDay(year, month, day);

     if (is_a_leap_year(year)){
        last_day = leap_days_in_month[month-1];
     } else {
        last_day = reg_days_in_month[month-1];
     }

     if ((7-week_day)+day <= last_day){
        date->day   = (7-week_day)+day;             //! date of day-7 (Sunday)
        date->month = month;                        //! same month
        date->year  = year;                         //! same year
       
     } else {
        if (month == 12){
           date->day   = (7-week_day)+day-31;       //! date of day-7 (Sunday)
           date->month = 1;                         //! next month is January
           date->year  = year + 1;                  //! next year
           
        } else {
           date->day   = (7-week_day)+day-last_day; //! date of day-7 (Sunday)
           date->month = month + 1;                 //! next month
           date->year  = year;                      //! same year
        }
     }
     date->week_day = 7;
     date->week     = getWeek(year, month, day);

  } else {
     printf("ERROR: setWeekDay_7() not valid arguments\n");
     succeed = 0;
  }
  return succeed;
}

//!****************************************************************************
//! Calculating the date of the curent day of the week by two ways:
//! a) according to the date: year, month & day (week suppose to be undefined);
//! b) according to the year & week (month & day suppose to be undefined),
//!    in this case the current day will be set on Monday; 
//! note: if all arguments are defined, the date is more powerfull condition.
//!****************************************************************************
//! args   : int: year, month (1-12), day (1-31), week (0-53)
//! output : date->year, date->month, date->day, date->week, date->week_day
//! returns: '1' if succeed, '0' if failed
//!****************************************************************************
int setCurWeekDay(simple_date_t *date, int year, int month, int day, int week)
{
  int succeed = 1;

  if (date == NULL) return 0;

  if (month == UNDEF_UNSIGNEDINT && day == UNDEF_UNSIGNEDINT &&
      (is_valid_year(year) && is_valid_week(week, year))){
    
     succeed = set_week_day_by_week(date, year, week, 1);
    
  } else if (is_valid_date(year, month, day)){
     
     date->day      = day;
     date->month    = month;
     date->year     = year;
     date->week_day = getWeekDay(year, month, day);
     date->week     = getWeek(year, month, day);
     set_min_time(date);
     
  } else {
     printf("ERROR: setCurWeekDay() not valid arguments\n");
     succeed = 0;
  }
  return succeed;
}

//!****************************************************************************
int set_prev_month_last_day(simple_date_t *date, simple_date_t *prev_date)
{
  int year, month, day;
  int succeed = 1;

  if (date == NULL || prev_date == NULL) return 0;
  
  year  = date->year;
  month = date->month;
  day   = date->day;
  if (is_valid_date(year, month, day)){
     
     if (month > 1){
        prev_date->year  = year;
        prev_date->month = month - 1;
        if (is_a_leap_year(year)){
           prev_date->day = leap_days_in_month[month-1];
        } else {
           prev_date->day = reg_days_in_month[month-1];
        }
     } else if (is_valid_year(year - 1)){
        prev_date->year  = year - 1;
        prev_date->month = 12;
        prev_date->day   = 31;
     } else {
        printf("ERROR: set_prev_month_last_day() year is out of the range\n");
        succeed = 0;
     }
     
     if (succeed){
        prev_date->week_day = getWeekDay(prev_date->year, prev_date->month,
                                                          prev_date->day);
        prev_date->week     = getWeek(prev_date->year, prev_date->month,
                                                       prev_date->day);
        set_min_time(prev_date);
     }
  } else {
     printf("ERROR: set_prev_month_last_day() input date is not valid\n");
     succeed = 0;
  }
  return succeed;
}

//!****************************************************************************
int set_next_month_first_day(simple_date_t *date, simple_date_t *next_date)
{
  int succeed = 1;

  if (date == NULL || next_date == NULL) return 0;
  
  if (is_valid_date(date->year, date->month, date->day)){
     
     if (date->month < 12){
        next_date->year  = date->year;
        next_date->month = date->month + 1;
     } else if (is_valid_year(date->year + 1)){
        next_date->year  = date->year + 1;
        next_date->month = 1;
     } else {
        printf("ERROR: set_next_month_first_day() year is out of the range\n");
        succeed = 0;
     }
     
     if (succeed){
        next_date->day      = 1;
        next_date->week_day = getWeekDay(next_date->year, next_date->month,
                                                          next_date->day);
        next_date->week     = getWeek(next_date->year, next_date->month,
                                                       next_date->day);
        set_max_time(next_date);
     }
  } else {
     printf("ERROR: set_next_month_first_day() input date is not valid\n");
     succeed = 0;
  }
  return succeed;
}