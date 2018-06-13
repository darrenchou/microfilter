/*****************************************************************************
 * logger.h
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
#ifndef _LOGGER_H_
#define _LOGGER_H_

#define __MSG_TYPE__ int
#define MAX_LOGFILE_RECORDS      30000  //! maximum lines in the log file
#define CHUNK                    1024   //! read 1024 bytes at a time    

#define MAX_TBLFILE_RECORDS      99

#define BZ2_EXT                  "bz2"
#define LOG_PATH                 "./LOG/"
#define LOGFILE                  "./LOG/osornod.log"
#define MSG_FILE                 "./CSV/messages_tbl.csv"

#define IMG_SENS_BLANK           "images/blank22.png"
#define IMG_SENS_ACTIVE          "images/semGreenSs.png"
#define IMG_SENS_INACTIVE        "images/semGreySs.png"
#define IMG_SENS_ERROR           "images/semRedSs.png"

#define IMG_SW_INACTIVE          "images/LvlSwGrey.png"
#define IMG_SW_ACTIVE_LOW        "images/LvlSwLow.png"
#define IMG_SW_ACTIVE_HIGH       "images/LvlSwHigh.png"
#define IMG_SW_ERROR             "images/LvlSwRed.png"

#define EMPTY_IMAGE              "images/empty32.png"
#define ALERT_COLOR              "images/alert32.png"
#define WARNING_COLOR            "images/warning32.png"
#define INFORM_COLOR             "images/info32.png"
#define ALERT_GREY               "images/alert.png"
#define WARNING_GREY             "images/warning.png"
#define INFORM_GREY              "images/info.png"

//!----------------------------------------------------------------------------
//! LOGIN AND LOGOUT ROUTINAS MANIPULATION MESSAGES
//!----------------------------------------------------------------------------
#define MSG_USER_LOGIN_SUCCEED   "Client from IP address: %s was successfully CONNECTED as OBSERVER.\t"
#define MSG_OPER_LOGIN_SUCCEED   "Client from IP address: %s was successfully CONNECTED as OPERATOR.\t"
#define MSG_SERV_LOGIN_SUCCEED   "Client from IP address: %s was successfully CONNECTED as SERVICE.\t"
#define MSG_CLIENT_LOGGED_OUT    "Client from IP address: %s was successfully LOGED OUT.\t"
#define MSG_CLIENT_QUIT_SESSION  "Session from ip address: %s was closed by Client.\t"
#define MSG_SESSION_TIMED_OUT    "Session from ip address: %s was TIMED OUT.\t"

#define MSG_CLIENT_LOGIN_FAILED  "Attempt to Login as %s from the host with IP address: %s failed.\t"
#define MSG_USER_LOGIN_FAILED    "Attempt to Login from the host with IP address: %s failed.\t"
#define MSG_REMOTE_OPER_LOGIN    "Attempt to login as OPERATOR from remote host. Connection REFUSED.\t"

#define MSG_NO_SERV_SYSTEM_BUSY  "Connection to SCADA from IP address: %s as SERVICE failed. System is busy. OPERATOR activity.\t"
#define MSG_USER_LOGIN_IS_BUSY   "Attempt to login from IP address: %s failed. Connections limit was reached.\t"
#define MSG_SERV_LOGIN_IS_BUSY   "Attempt to login from IP address: %s failed. SERVICE permission is active.\t"

#define MSG_AUTHENTICATION_OK    "Successful %s authentication.\t"
#define MSG_CLIENT_IP_CONNECTED  "Client with IP address: %s connected.\t"
#define MSG_CLIENT_DISCONNECTED  "Client with IP address: %s disconnected.\t"
#define MSG_PVS_WAS_TERMINATED   "Received termination signal for PVS daemon id: %d...\t"

//!----------------------------------------------------------------------------
//! SYSTEM PRODUCTION MESSAGES
//!----------------------------------------------------------------------------
#define MSG_PLANT_WAS_STARTED    "Microfiltration plant was started.\t"
#define MSG_PLANT_WAS_STOPPED    "Microfiltration plant was stopped.\t"
#define MSG_SCADACONFIGOK        "SCADA Configuration is complete. SCADA is ready for monitoring.\t"
#define MSG_SCADA_NOT_CONFIGURED "SCADA Configuration is incomplete. Contact MAINTENANCE.\t"
//! reaction on system startup:
#define MSG_CRITICAL_CONFIG      "Configuration critical error! %s.\t"
//! on ui configuration changes:
#define MSG_NEW_CONFIG_ERROR     "New config settings error! %s.\t"
#define MSG_SCADA_WAS_STOPPED    "SCADA application must be terminated. Contact MAINTENANCE.\t"
#define MSG_EXIT_SCADA_PROGRAM   "SCADA application was stopped.\t"
#define MSG_CONFIG_PLC_TO_SCADA  "PLC Configuration settings were uploaded to SCADA."
#define MSG_CONFIG_SCADA_TO_PLC  "SCADA Configuration settings were uploaded to PLC."
#define MSG_CONFIG_UIMAN_TO_PLC  "Saving Configuration Changes from UI to PLC."

#define MSG_NEW_CONFIG_SAVED     "New SCADA Configuration was saved into configuration file.\t"
#define MSG_ATTEMPT_CHANGE_FIXED "Attempt to change fixed configuration option(s):%s was refused.\t"
#define MSG_SCADA_CONFIG_ERRORS  "SCADA Configuration was updated using PLC configuration settings.\t"
#define SCADA_PLC_CONFIG_ERRORS  "SCADA and PLC configurations both have critical errors.\t"
#define CRUCIAL_SCADA_CONFLICT   "Crucial conflict. SCADA software is incompatible with PLC program.\t"
#define MSG_CONFLICT_CONFIGS     "Conflict in configuration between PLC and SCADA was detected.\t"
#define MSG_NO_CONFLICTS         "No Conflicts in configuration between PLC and SCADA were detected.\t"
#define MSG_CRITICAL_ERROR       "A Critical Error forced to stop SCADA Application.\nPlease contact OSORNO company for explanation:"

#define MSG_REQUEST_SOLVED       "Request to PLC was RESOLVED.\t"
#define MSG_REQUEST_TIMEOUT      "Request to PLC TIMED OUT: %s\t"

#define MSG_T3_PUMPS_DUAL_FORCE   "Tank-3 pumps mode WAS FORCED TO THE DUAL-PUMPING.\t"
#define MSG_PUMPS_DUAL_FORCE_ENDS "Tank-3 pumps FORCED DUAL-PUMPING mode was RESOLVED.\t "
#define MSG_LIFT_ST_LVL_HIGH      "Lift Station level high issue.\t"
#define MSG_LIFT_ST_LVL_HIGH_ENDS "Lift Station level high issue RESOLVED.\t"

//! MANUAL OPERATING EVENTS:
#define MSG_SERVICE_START        "Pressed 'Service Start' button from Manual Operation."
#define MSG_SERVICE_FINISH       "Pressed 'Service Stop' button from Manual Operation."
#define MSG_SERVICE_PC_REBOOT    "Pressed 'SCADA Reboot' button from Manual Operation."
#define MSG_SERVICE_CIP_START    "Pressed 'STP Start' button from Manual Operation."
#define MSG_SERVICE_CIP_STOP     "Pressed 'STP Stop' button from Manual Operation."
#define MSG_SERVICE_ERR_ACK      "Pressed 'PLC Error Ack' button from Manual Operation."
#define MSG_SERVICE_ALL_TO_MAN   "Pressed 'All to Manual' button from Manual Operation."
#define MSG_SERVICE_ALL_TO_AUTO  "Pressed 'All to AUTO' button from Manual Operation."


//! SWITCHING SERVICE INTO MANUAL MODE 
#define MSG_INTO_MAN_BL1A        "Blower_1A: pressed 'Switch to Manual' from Manual Operation."
#define MSG_INTO_MAN_BL1B        "Blower_1B: pressed 'Switch to Manual' from Manual Operation."
#define MSG_INTO_MAN_BL2         "Blower_2 pressed 'Switch to Manual' from Manual Operation."
#define MSG_INTO_MAN_PUMPS       "Pumps: pressed 'Switch to Manual' from Manual Operation."
#define MSG_INTO_MAN_UV          "UV-Lamp: pressed 'Switch to Manual' from Manual Operation."
#define MSG_INTO_MAN_SOL         "Solenoid: pressed 'Switch to Manual' from Manual Operation."
#define MSG_INTO_MAN_ACT         "Actuator: pressed 'Switch to Manual' from Manual Operation."
#define MSG_INTO_MAN_LIFT        "Lift Station: pressed 'Switch to Manual' from Manual Operation."
//! SWITCHING SERVICE INTO AUTOMATION MODE 
#define MSG_INTO_AUTO_BL1A       "Blower_1A: pressed 'Switch to Auto' from Manual Operation."
#define MSG_INTO_AUTO_BL1B       "Blower_1B: pressed 'Switch to Auto' from Manual Operation."
#define MSG_INTO_AUTO_BL2        "Blower_2 pressed 'Switch to Auto' from Manual Operation."
#define MSG_INTO_AUTO_PUMPS      "Pumps: pressed 'Switch to Auto' from Manual Operation."
#define MSG_INTO_AUTO_UV         "UV-Lamp: pressed 'Switch to Auto' from Manual Operation."
#define MSG_INTO_AUTO_SOL        "Solenoid: pressed 'Switch to Auto' from Manual Operation."
#define MSG_INTO_AUTO_ACT        "Actuator: pressed 'Switch to Auto' from Manual Operation."
#define MSG_INTO_AUTO_LIFT       "Lift Station: pressed 'Switch to Auto' from Manual Operation."

//! SWITCHING DEVICE STATUS TO ENABLED
#define MSG_INTO_ENBL_BL1A       "Blower_1A: pressed 'Enable' from Manual Operation."
#define MSG_INTO_ENBL_BL1B       "Blower_1B: pressed 'Enable' from Manual Operation."
#define MSG_INTO_ENBL_BL2        "Blower_2: pressed 'Enable' from Manual Operation."
#define MSG_INTO_ENBL_PUMP1      "Pump_1: pressed 'Enable' from Manual Operation."
#define MSG_INTO_ENBL_PUMP2      "Pump_2: pressed 'Enable' from Manual Operation."
#define MSG_INTO_ENBL_UV         "UV-Lamp: pressed 'Enable' from Manual Operation."
#define MSG_INTO_ENBL_SOL        "Solenoid: pressed 'Enable' from Manual Operation."
#define MSG_INTO_ENBL_LIFT       "Lift Station: pressed 'Enable' from Manual Operation."
//! SWITCHING DEVICE STATUS TO DISABLED
#define MSG_INTO_DIS_BL1A        "Blower_1A: pressed 'Disable' from Manual Operation."
#define MSG_INTO_DIS_BL1B        "Blower_1B: pressed 'Disable' from Manual Operation."
#define MSG_INTO_DIS_BL2         "Blower_2: pressed 'Disable' from Manual Operation."
#define MSG_INTO_DIS_PUMP1       "Pump_1: pressed 'Disable' from Manual Operation."
#define MSG_INTO_DIS_PUMP2       "Pump_2: pressed 'Disable' from Manual Operation."
#define MSG_INTO_DIS_UV          "UV-Lamp: pressed 'Disable' from Manual Operation."
#define MSG_INTO_DIS_SOL         "Solenoid: pressed 'Disable' from Manual Operation."
#define MSG_INTO_DIS_LIFT        "Lift Station: pressed 'Disable' from Manual Operation."
//! TURNING DEVICE ON FROM MANUAL MODE
#define MSG_DEV_STARTED_BL1A     "Blower_1A: pressed 'Start' from Manual Operation."
#define MSG_DEV_STARTED_BL1B     "Blower_1B: pressed 'Start' from Manual Operation."
#define MSG_DEV_STARTED_BL2      "Blower_2: pressed 'Start' from Manual Operation."
#define MSG_DEV_STARTED_PUMP1    "Pump_1: pressed 'Start' from Manual Operation."
#define MSG_DEV_STARTED_PUMP2    "Pump_2: pressed 'Start' from Manual Operation."
#define MSG_DEV_STARTED_UV       "UV-Lamp: pressed 'Start' from Manual Operation."
#define MSG_DEV_STARTED_SOL      "Solenoid: pressed 'Start' from Manual Operation."
#define MSG_DEV_STARTED_LIFT     "Lift Station: pressed 'Start' from Manual Operation."
//! TURNING DEVICE OFF FROM MANUAL MODE
#define MSG_DEV_STOPED_BL1A      "Blower_1A: pressed 'Stop' from Manual Operation."
#define MSG_DEV_STOPED_BL1B      "Blower_1B: pressed 'Stop' from Manual Operation."
#define MSG_DEV_STOPED_BL2       "Blower_2: pressed 'Stop' from Manual Operation."
#define MSG_DEV_STOPED_PUMP1     "Pump_1: pressed 'Stop' from Manual Operation."
#define MSG_DEV_STOPED_PUMP2     "Pump_2: pressed 'Stop' from Manual Operation."
#define MSG_DEV_STOPED_UV        "UV-Lamp: pressed 'Stop' from Manual Operation."
#define MSG_DEV_STOPED_SOL       "Solenoid: pressed 'Stop' from Manual Operation."
#define MSG_DEV_STOPED_LIFT      "Lift Station: pressed 'Stop' from Manual Operation."


#define MSG_ACTUATOR_STEP_UP     "Actuator: pressed 'Step +' from Manual Operation."
#define MSG_ACTUATOR_STEP_DOWN   "Actuator: pressed 'Step -' from Manual Operation."

#define MSG_UPDATE_SYSTEM_DATA   "PLC SYSTEM DATA were updated.\t"

#define MSG_MAINTENANCE_REMINDER "%d months passed since last MAINTENANCE. Please connect with MAINTENANCE crew as soon as possible.\t"
#define MSG_EMRG_EMAIL_WAS_SENT  "Emergency e-mail was sent.\t"
#define MSG_EMERGENCY_STOP       "EMERGENCY DETECTED: BioCompact System WAS STOPPED."

#define MSG_ACTIVATED_SENS_PAGE  "Sensors ui page with IP = %s was activated."

//++++++++new added messages
//! TURNING DEVICE ON FROM MANUAL MODE
#define MSG_DEV_STARTED_SOL1     "SOL1: pressed 'Start' from Manual Operation."
#define MSG_DEV_STARTED_SOL2     "SOL2: pressed 'Start' from Manual Operation."
#define MSG_DEV_STARTED_SOL3     "SOL3: pressed 'Start' from Manual Operation."
#define MSG_DEV_STARTED_SOL4     "SOL4: pressed 'Start' from Manual Operation."
#define MSG_DEV_STARTED_SOL5     "SOL5: pressed 'Start' from Manual Operation."
#define MSG_DEV_STARTED_SOL6     "SOL6: pressed 'Start' from Manual Operation."
#define MSG_DEV_STARTED_SOL7     "SOL7: pressed 'Start' from Manual Operation."
#define MSG_DEV_STARTED_SOL8     "SOL8: pressed 'Start' from Manual Operation."
#define MSG_DEV_STARTED_SOL9     "SOL9: pressed 'Start' from Manual Operation."

//! TURNING DEVICE OFF FROM MANUAL MODE
#define MSG_DEV_STOPED_SOL1      "SOL1: pressed 'Stop' from Manual Operation."
#define MSG_DEV_STOPED_SOL2      "SOL2: pressed 'Stop' from Manual Operation."
#define MSG_DEV_STOPED_SOL3      "SOL3: pressed 'Stop' from Manual Operation."
#define MSG_DEV_STOPED_SOL4      "SOL4: pressed 'Stop' from Manual Operation."
#define MSG_DEV_STOPED_SOL5      "SOL5: pressed 'Stop' from Manual Operation."
#define MSG_DEV_STOPED_SOL6      "SOL6: pressed 'Stop' from Manual Operation."
#define MSG_DEV_STOPED_SOL7      "SOL7: pressed 'Stop' from Manual Operation."
#define MSG_DEV_STOPED_SOL8      "SOL8: pressed 'Stop' from Manual Operation."
#define MSG_DEV_STOPED_SOL9      "SOL9: pressed 'Stop' from Manual Operation."

//! MANUAL OPERATING EVENTS:
//#define MSG_SERVICE_CIP_START    "Pressed 'CIP Start' button from Manual Operation."
#define MSG_SERVICE_CIP_STOP     "Pressed 'STP Stop' button from Manual Operation."
#define MSG_SERVICE_ERR_ACK      "Pressed 'PLC Error Ack' button from Manual Operation."
#define MSG_SERVICE_ALL_TO_MAN   "Pressed 'All to Manual' button from Manual Operation."
#define MSG_SERVICE_ALL_TO_AUTO  "Pressed 'All to AUTO' button from Manual Operation."


#define TXT_SERV_START   "Start Service"
#define TXT_SERV_STOP    "Stop Service"
#define TXT_PROCESSING   "Processing..."
#define TXT_STP_START    "Plant Start"
#define TXT_STP_STOP     "Plant Stop"
#define TXT_ALL_TO_REQ   "All to ..."
#define TXT_ALL_TO_MAN   "All to Manual"
#define TXT_ALL_TO_AUTO  "All to Auto"
#define TXT_SWITCH_MAN   "Switch to Manual"
#define TXT_SWITCH_AUTO  "Switch to Auto"
#define TXT_SWITCH_ENBL  "Enable"
#define TXT_SWITCH_DIS   "Disable"
#define TXT_TURN_ON      "Start"
#define TXT_TURN_OFF     "Stop"
#define TXT_NO_LIFT_LVL  " N/A (cm)"
#define TXT_NO_ACT_VAL   " N/A %"
#define TXT_NO_TANK3_LVL " N/A (cm)"
#define TXT_DEV_NA_LONG  "                   device is not available" 
#define TXT_DEV_NA_SHORT "   device is not available"

#define EMPTY_STRING     ""

//#define LOG_PRINT(...) log_print(__SIZEOF_INT__, __VA_ARGS__)
//#define TBL_PRINT(...) tbl_print(__VA_ARGS__)

enum {
  LOG_UNDEFINED = 0,
  
  //! messages supposed to be shown in the table and written into the log-file
  LOG_MSG_CRIT,  //! critical
  LOG_MSG_WARN,  //! warning
  LOG_MSG_INFO,  //! information
  
  //! messages supposed to be written only into the log-file
  LOGFILE_CRIT,  //! critical
  LOGFILE_WARN,  //! warning
  LOGFILE_INFO   //! information
};

enum {
  EMPTY_MESSAGE_TYPE = 0,
  ALERT_COLOR_MSG_TYPE,
  WARN_COLOR_MSG_TYPE,
  INFO_COLOR_MSG_TYPE,
  ALERT_GREY_MSG_TYPE,
  WARN_GREY_MSG_TYPE,
  INFO_GREY_MSG_TYPE,
};

typedef struct info_msg{
  
  int    msg_type;         //! undefined, error, warning, information
  int    selected;         //! record selection flag 1/0
  char   msg[256];    //! text of the message
  char   time_txt[24];  
  //! time in the text format "Mon-DD-YYYY HH:MM XM", where:
  //! Mon    three-letters month abreviation Jan, Feb, Mar, Apr...;
  //! DD     day of the month (01 - 31);
  //! YYYY   year (2013 - 9999);
  //! HH     hour of the day (01 - 12);
  //! MM     minute of the hour (00 - 59);
  //! XM     part of the day abreviation "AM" or "PM";
 
  char   time_num[24];   
  //! time in the digital representation "YYDDDHHMMSSssssss", where:
  //! YY     last two digits of the year (00 - 99);
  //! DDD    day of the year (001 - 365);
  //! HH     hour of the day (00 - 23);
  //! MM     minute of the hour (00 - 59);
  //! SS     second of the minute (00 - 59);
  //! ssssss number of microseconds (000000 - 999999);
  
} info_msg_t;

typedef struct info_msg_tbl{
  
  int         rows_num;
  info_msg_t  rows[MAX_TBLFILE_RECORDS];
  
}info_msg_tbl_t;

extern void log_init();
extern void log_print(int msg_type, char *fmt,...);
extern void erase_selected_rows();


extern void record_calibration_time(char *timerecord);

extern const char* msg_imgs[7];
extern unsigned long log_line_count;
extern info_msg_tbl_t  *msg_tbl;


#endif