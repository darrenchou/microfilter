/*****************************************************************************
 * simpledate.h
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

#ifndef _SIMPLEDATE_H_
#define _SIMPLEDATE_H_

#define UNDEF_UNSIGNEDINT -1

#define NUM_DAYS_IN_WEEK    7
#define NUM_DAYS_IN_MONTH   31
#define NUM_DAYS_IN_A_YEAR  365
#define NUM_DAYS_LEAP_YEAR  366
#define NUM_HOURS_IN_DAY    24
#define MINUTES_IN_HOUR     60

#define START_COMP_YEAR     1900
#define MILLENNIUM_YEAR     2000
#define OSORNOD_MIN_YEAR    2012
#define OSORNOD_MAX_YEAR    2076

extern const int reg_days_in_month[12];
extern const int leap_days_in_month[12];

enum SET_KEY {
   SET_DATE_NO_FLAG = 0,
   SET_DATE_BY_YMD,
   SET_DATE_BY_YWD,
};

enum TIME_KEY {
   CURRENT_SEC  = 0,
   CURRENT_MIN  ,
   CURRENT_HOUR ,
   CURRENT_DAY  ,
   CURRENT_WEEK ,
   CURRENT_WDAY ,
   CURRENT_MONTH,
   CURRENT_YEAR
};

typedef struct simple_date
{
  unsigned int year;        //! (2012 - 2076)
  unsigned int month;       //! (1 - 12)
  unsigned int week;        //! (0 - 53)
  unsigned int day;         //! (1 - 31)
  unsigned int week_day;    //! (1 - 7) Monday-first
  unsigned int hour;        //! (0 - 23)
  unsigned int minute;      //! (0 - 59)
  unsigned int second;      //! (0 - 59)
  
} simple_date_t;

extern void zeroing_simple_date(simple_date_t *date);
extern int set_simple_time(simple_date_t *date, int hour, int minute, int second);
extern void set_min_time(simple_date_t *date);
extern void set_max_time(simple_date_t *date);
extern void convert_unix_time_to_simple_date(long int unix_time, simple_date_t *date);
extern void set_cur_date(simple_date_t *date);
extern void set_the_latest_osornod_date(simple_date_t *date);
extern void set_the_earliest_osornod_date(simple_date_t *date);
extern int set_date_by_ymd(simple_date_t *date, int y, int mo, int d);
extern int set_date_by_ywd(simple_date_t *date, int y, int w, int wd);
extern int set_datetime(simple_date_t *date, int y, int mo, int w, int wd, int d,
                                             int h, int mi, int s, int set_flag);
extern int set_date_mintime(simple_date_t *date, int y, int m, int d);
extern int set_date_maxtime(simple_date_t *date, int y, int m, int d);
extern int set_date_hour(simple_date_t *date, int y, int m, int d, int h);
extern int is_a_leap_year(int year_to_check);
extern int is_valid_year(int year);
extern int is_valid_month(int month);
extern int is_valid_week(int week, int year);
extern int is_valid_date(int year, int month, int day);
extern int is_valid_weekdate(int year, int week, int wday);
extern int is_valid_time(int hour, int minute, int second);
extern int is_current_date(int y, int mo, int d);
extern int is_future_date(simple_date_t *date_to_check);
extern unsigned int get_cur_second();
extern unsigned int get_cur_minute();
extern unsigned int get_cur_hour();
extern unsigned int get_cur_day();
extern unsigned int get_cur_wday();
extern unsigned int get_cur_week();
extern unsigned int get_cur_month();
extern unsigned int get_cur_year();
extern int getWeekDay(int year, int month, int day);
extern int getWeek(int year, int month, int day);
extern int set_day_month_by_year_abs_day(simple_date *date, int year, int abs_day);
extern int set_week_day_by_week(simple_date *date, int year, int week, int week_day);
extern int setWeekDay_1(simple_date_t *date, int year, int month, int day, int week);
extern int setWeekDay_7(simple_date_t *date, int year, int month, int day, int week);
extern int setCurWeekDay(simple_date_t *date, int year, int month, int day, int week);
extern int set_prev_month_last_day(simple_date_t *date, simple_date_t *prev_date);
extern int set_next_month_first_day(simple_date_t *date, simple_date_t *next_date);

#endif