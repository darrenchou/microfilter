/*****************************************************************************
 * osornoconf.h
 *
 * begin   : Wed Jun 26 14:19:17 2013
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
 * Copyright Osorno Enterprises Inc., 2013
 *
 * OSAUT and OSORNOD project
 * (c) Osorno Enterprises Inc., 2013: http://www.osorno.ca/
 * 
 ****************************************************************************/
  
#ifndef _OSORNOCONF_H_
#define _OSORNOCONF_H_

#include <confuse.h>

#if 0
#define DEFAULT_REACTOR  "160"
#define DEFAULT_PUMPTYPE "6"
#define DEFAULT_MAINFLOW "no"
#define DEFAULT_PH_CORR  "no"
#define DEFAULT_CONCENTR "online"

#define DEFAULT_CALIBR_1 1000
#define DEFAULT_CALIBR_2 1000
#define DEFAULT_CALIBR_3 1000

#define REACTOR_1 "160 ml"
#define REACTOR_2 "1380 ml"

#define PUMPTYPE_1 "6 l/h or less"
#define PUMPTYPE_2 "6 - 12 l/h"

#define MAINFLOW_1 "No"
#define MAINFLOW_2 "Analogue"
#define MAINFLOW_3 "Ethernet"
#define MAINFLOW_4 "USB"

#define PH_CORRECTION_1 "No"
#define PH_CORRECTION_2 "Yes"

#define CONC_MEASURING_1 "Online measuring"
#define CONC_MEASURING_2 "Offline measuring"

#endif
#define DEF_CALIBR_VAL  0


#define CONFIG_FILE  "osorno.conf"
#define OPCODE_VERSION  0x12

#define DEF_STP_PORT    6679
/*#define DEF_MAGM_PORT   56679
#define DEF_WTP_PORT    56680
#define DEF_SENS_PORT   6679
#define DEF_LIFT_PORT   56681
*/
#define BIN_CONFIG_CSV  "./CSV/bin_config_tbl.csv"
#define INT_CONFIG_CSV  "./CSV/int_config_tbl.csv"
#define BLD_ALARMS_CSV  "./CSV/build_alrm_tbl.csv"

//! boolean config options
//! enum values should fit to init_bin_opts[] array (bio_config.cpp)
enum {
  /*BUILD_ALARMS = 0,
  WATER_PLANT  ,
  CH1A_SENSORS ,
  CH1B_SENSORS ,
  CH_3_SENSORS ,
  LIFT_STATION ,
  LIFT_ST_ETH  ,
  LIFT_SENSOR  ,
  ACTUATOR_OPT ,
  ACTUATOR_ETH ,
  MAGMETER_OPT ,
  MAGMETER_ETH ,
  BLOWER1A_OPT ,
  BL1A_3_PHASE ,
  BL1A_S_START ,
  BL1A_PRES_SW ,
  BLOWER1B_OPT ,
  BL1B_3_PHASE ,
  BL1B_S_START ,
  BL1B_PRES_SW ,
  BLOWER2_OPT  ,
  BL2_3_PHASE  ,
  BL2_S_START  ,
  BL2_PRES_SW  ,
  SOLENOID_OPT ,
  T3_SENS_OPT  ,
  T3_SENS_ETH  ,
  T3_LOW_OPT   ,
  T3_HIGH_OPT  ,
  T3_PUMP1_OPT ,
  T3_PUMP2_OPT ,
  UV_UNIT_OPT  ,
  UV_UNIT_ETH  ,
  FLOW_SW_OPT  , //33
 
  //OTHER CONFIG
  ALTER_BLOW_2 ,
  ALTER_PUMPS  ,
  SHOW_LVLSENS ,
  SHOW_CH3_LVL ,
 

  //++++++++new added
  /*SYSTEM_AUTO_MODE ,  //1
  SYSTEM_SERVICE_MODE ,
  SERVICE_ACCEPT ,
  SERVICE_REQUIRED ,*/
  PS1_PRESENT ,
  PS2_PRESENT ,
  PS_AIR_PRESENT ,
  MAGMIN_PRESENT ,
  MAGMOUT_PRESENT ,
  CIP_PRESENT ,
  RESERVOIR_PRESENT,
  SOL_S1_PRESENT ,
  SOL_S2_PRESENT ,
  SOL_S3_PRESENT ,
  SOL_S4_PRESENT ,
  SOL_S5_PRESENT ,
  SOL_S6_PRESENT ,
  UF1_PRESENT ,
  UF2_PRESENT ,
  DP_PRESENT ,
  /*SOL_S1_MAN ,
  SOL_S2_MAN ,
  SOL_S3_MAN ,
  SOL_S4_MAN ,
  SOL_S5_MAN ,
  SOL_S6_MAN ,
  SOL_S7_MAN ,
  SOL_S8_MAN ,
  SOL_S9_MAN ,
  SOL_SA1_MAN ,
  SOL_SA2_MAN ,
  DP_MAN ,    //31*/

  CONFIG_FORCE ,
  NUM_CONFIG_BIN
};

//! integer config options
//! enum values should fit to int_opt_tbl[] array (bio_config.cpp)
enum {
  /*PLANT_ID = 0,
  OFFTIME_BL1A,
  ONTIME_BL1A,
  OFFTIME_BL1B,
  ONTIME_BL1B,
  OFFTIME_BL2,
  ONTIME_BL2,
  T3SEN_SLOPE,
  T3SEN_OFFSET,
  MAGM_MINFLOW,
  MAGM_MAXFLOW,
  MAGM_PULSE,
  T3_MIN_DIST,
  T3_MAX_DIST,
  LIFT_MINDIST,
  LIFT_MAXDIST,
  ACT_STEP_DELAY,
  ACT_LOW_FLOW,
  ACT_HIGH_FLOW, //18 */
  
  MAX_MAGMIN_FLOW,  //1
  MAGMIN_PULSE_VALUE,
  MAX_MAGMOUT_FLOW,
  MAGMOUT_PULSE_VALUE,
  /*TOTALIZERIN_LOW,
  TOTALIZERIN_HIGH,
  TOTALIZEROUT_LOW,
  TOTALIZEROUT_HIGH,  //8*/
  NUM_CONFIG_INT
};

enum {
  BLD_STAT_UNDEF = 0, //! building alarm status: normal   (blue color)
  BLD_STAT_NORM,      //! building alarm status: normal   (green color)
  BLD_STAT_INAC,      //! building alarm status: inactive (grey color)
  BLD_STAT_ALRM       //! building alarm status: alarm    (red color)
};

typedef struct bool_config {
  char name[64];
  long int cur_val;
  long int new_val;
  int fixed;
  char description[256];
} bool_config_t;

typedef struct int_config {
  char name[64];
  long int cur_val;
  long int new_val;
  long int lo_bound;
  long int hi_bound;
  int fixed;
  char description[256];
} int_config_t;

//! ip devices could be communicated with SCADA
//! enum values should fit to init_ip_opts[] array (bio_config.cpp)
enum {
   SCADAIP = 0,
   STP_PLC,
   STP_MGM,
   WTP_PLC,
   WTP_MGM,
   SENS_1,
   SENS_2,
   SENS_3,
   LIFT_ST,
   NUM_CONFIG_IP
};

typedef struct ip_config{
   char name[64];
   char *ip;
}ip_config_t;

//! ldap configuration settings
typedef struct ldap_conf {
   char *plant_name;   //! plant name
   char *user_login;   //! OBSERVER user login entry
   char *oper_login;   //! OPERATOR user login entry
   char *serv_login;   //! SERVICE user login entry

   //! ip-address of the ldap servers:
   char *ldap_prime;   //! primary:   main LDAP server
   char *ldapsecond;   //! secondary: on SECURE WALL device
       
   char *prime_cred;   //! ldap credentials for primary server
   char *local_cred;   //! ldap credentials for local server
   
   //! emergency communication settings   
   char *emrgemail1;   //! e-mail address for emergency issues
   char *emrgemail2;   //! e-mail address for emergency issues
   
}ldap_conf_t;


//! mysql database configuration settings
typedef struct mysql_conf {
   char *mysql_user;   //! authorisated mysql user name
   char *mysql_pswd;   //! authorisated mysql user password 
   char *mysql_dbname; //! mysql database name
   
}mysql_conf_t;


typedef struct chlorine_conf {

   char *client_ip;   // 
   char *server_ip;

   long int check_client;   // forcing to check External SCADA ip address
       
   char *plant_name;   //! plant name
   char *user_login;   //! OBSERVER user login entry
   char *oper_login;   //! OPERATOR user login entry
   char *serv_login;   //! SERVICE user login entry

   //! ip-address of the ldap servers:
   char *ldap_prime;   //! primary:   main LDAP server
   char *ldapsecond;   //! secondary: on SECURE WALL device
       
   char *prime_cred;   //! ldap credentials for primary server
   char *local_cred;   //! ldap credentials for local server
   
   //! emergency communication settings   
   char *emrgemail1;   //! e-mail address for emergency issues
   char *emrgemail2;   //! e-mail address for emergency issues

       /*uint PS1_present:1;
       uint PS2_present:1;
       uint PS_AIR_present:1;
       uint MagmIN_present:1;
       uint MagmOUT_present:1;
       uint CIP_present:1;
       uint reservoir_present:1;
       uint sol_S1_present:1;
       uint sol_S2_present:1;
       uint sol_S3_present:1;
       uint sol_S4_present:1;
       uint sol_S5_present:1;
       uint sol_S6_present:1;
       */
}chlorine_conf_t;



extern chlorine_conf_t config;
extern ldap_conf_t   *ldap_config;
extern mysql_conf_t  *db_config;
extern cfg_t  *cfg;

extern bool_config_t  init_bin_opts[NUM_CONFIG_BIN];
extern int_config_t   init_int_opts[NUM_CONFIG_INT];
extern ip_config_t    init_ip_opts[NUM_CONFIG_IP];

extern bool_config_t *bin_opts[NUM_CONFIG_BIN];
extern int_config_t  *int_opts[NUM_CONFIG_INT];
extern ip_config_t   *ip_opts[NUM_CONFIG_IP];


extern int save_bio_c_conf_bin();
extern int save_bio_c_conf_int();

extern int save_bin_config_csv();
extern int save_int_config_csv();


extern void init_ip_opts_tbl();
extern void init_bin_opts_tbl();
extern void init_int_opts_tbl();

extern int  udjustable_min_max_int_option(int int_opt_id);
#endif
