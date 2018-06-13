/*****************************************************************************
 * dispatcher.cpp
 *
 * begin   : Thu Mar 7 14:56:00 2014
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
 * (c) Osorno Enterprises Inc., 2013: http://www.osorno.ca/
 * 
 ****************************************************************************/
//1. comment void proceed_constant_event(int ind)
#include "pvapp.h"
#include "osaut.h"
#include "shamemchl.h"
#include "osornoconf.h"
#include "bio_errors.h"
#include "dispatcher.h"
#include "logger.h"
#include "simpledate.h"
//#include "db_bio_pemh.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/time.h>

//!!!!!!!  IMPORTANT !!!!!!!!!!  IMPORTANT  !!!!!!!!  IMPORTANT !!!!!!!!!!
//!  -----------------------------------------------------------------  //
//!   all zeroing .event_go members are processed  by pvserver daemon   //
//!   all changes in this array might be done only by pvserver daemon   //
//!      for other processes eve_request[] array is just read only      //
//!  -----------------------------------------------------------------  //
//!!!!!!!  IMPORTANT !!!!!!!!!!  IMPORTANT  !!!!!!!!  IMPORTANT !!!!!!!!!!

static event_request_t init_tbl_eve_request[] = {
 //!     event_id            event_go       eve_info      event_val
 { EVE_USER_LOGIN_SUCCEED  , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_OPER_LOGIN_SUCCEED  , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_SERV_LOGIN_SUCCEED  , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_CLIENT_LOGGED_OUT   , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_CLIENT_QUIT_SESSION , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_SESSION_TIMED_OUT   , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_CLIENT_LOGIN_FAILED , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_USER_LOGIN_FAILED   , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_REMOTE_OPER_LOGIN   , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_NO_SERV_SYSTEM_BUSY , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_USER_LOGIN_IS_BUSY  , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_SERV_LOGIN_IS_BUSY  , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_CLIENT_IP_CONNECTED , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_CLIENT_DISCONNECTED , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_PVS_WAS_TERMINATED  , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_PLC_CONNECTION_ERR  , PLC_EVENT_B2B, EMPTY_STRING, UNDEF_INT },
 { EVE_SEN1_CONNECTION_ERR , PLC_EVENT_B2B, EMPTY_STRING, UNDEF_INT },
 { EVE_SEN2_CONNECTION_ERR , PLC_EVENT_B2B, EMPTY_STRING, UNDEF_INT },
 { EVE_SEN3_CONNECTION_ERR , PLC_EVENT_B2B, EMPTY_STRING, UNDEF_INT },
 { EVE_ACTUATOR_ERR        , PLC_EVENT_B2B, EMPTY_STRING, UNDEF_INT },
 { EVE_ACT_NO_SIGNAL_ERR   , PLC_EVENT_B2B, EMPTY_STRING, UNDEF_INT },
 { EVE_ACT_POSITION_ERR    , PLC_EVENT_B2B, EMPTY_STRING, UNDEF_INT },
 { EVE_MAGM_NO_SIGNAL_ERR  , PLC_EVENT_B2B, EMPTY_STRING, UNDEF_INT },
 { EVE_SOFT_START_1A_ERR   , PLC_EVENT_B2B, EMPTY_STRING, UNDEF_INT },
 { EVE_PRESSURE_SW1A_ERR   , PLC_EVENT_B2B, EMPTY_STRING, UNDEF_INT },
 { EVE_SOFT_START_1B_ERR   , PLC_EVENT_B2B, EMPTY_STRING, UNDEF_INT },
 { EVE_PRESSURE_SW1B_ERR   , PLC_EVENT_B2B, EMPTY_STRING, UNDEF_INT },
 { EVE_SOFT_START_2_ERR    , PLC_EVENT_B2B, EMPTY_STRING, UNDEF_INT },
 { EVE_PRESSURE_SW_2_ERR   , PLC_EVENT_B2B, EMPTY_STRING, UNDEF_INT },
 { EVE_T3_LVL_SENSOR_ERR   , PLC_EVENT_B2B, EMPTY_STRING, UNDEF_INT },
 { EVE_LVL_SEN_NO_SIG_ERR  , PLC_EVENT_B2B, EMPTY_STRING, UNDEF_INT },
 { EVE_T3_SWITCHES_ERR     , PLC_EVENT_B2B, EMPTY_STRING, UNDEF_INT },
 { EVE_PUMP_ONE_ERR        , PLC_EVENT_B2B, EMPTY_STRING, UNDEF_INT },
 { EVE_PUMP_TWO_ERR        , PLC_EVENT_B2B, EMPTY_STRING, UNDEF_INT },
 { EVE_MAIN_LINE_ERR       , PLC_EVENT_B2B, EMPTY_STRING, UNDEF_INT },
 { EVE_LINE1_PHASE_ERR     , PLC_EVENT_B2B, EMPTY_STRING, UNDEF_INT },
 { EVE_LINE2_PHASE_ERR     , PLC_EVENT_B2B, EMPTY_STRING, UNDEF_INT },
 { EVE_LINE3_PHASE_ERR     , PLC_EVENT_B2B, EMPTY_STRING, UNDEF_INT },
 { EVE_UV_SEN_NO_SIG_ERR   , PLC_EVENT_B2B, EMPTY_STRING, UNDEF_INT },
 { EVE_LIFT_NO_SIGN_ERR    , PLC_EVENT_B2B, EMPTY_STRING, UNDEF_INT },

 { EVE_ACTUATOR_EMERGENCY  , PLC_EVENT_B2B, EMPTY_STRING, UNDEF_INT },
 { EVE_MAGMETER_EMERGENCY  , PLC_EVENT_B2B, EMPTY_STRING, UNDEF_INT },
 { EVE_CHAMBER3_EMERGENCY  , PLC_EVENT_B2B, EMPTY_STRING, UNDEF_INT },
 { EVE_PUMPS_EMERGENCY     , PLC_EVENT_B2B, EMPTY_STRING, UNDEF_INT },
 { EVE_LIFT_ST_LVL_EMRGENCY, PLC_EVENT_B2B, EMPTY_STRING, UNDEF_INT },
 { EVE_POWER_FAILURE_EMERG , PLC_EVENT_B2B, EMPTY_STRING, UNDEF_INT },
 { EVE_SYSTOPED_EMERGENCY  , PLC_EVENT_B2B, EMPTY_STRING, UNDEF_INT },
 { EVE_EMERGENCY_ISSUE     , NO_EVENT     , EMPTY_STRING, UNDEF_INT },

 { EVE_SCADA_CONFIG_STATUS , PLC_EVENT_B2B, EMPTY_STRING, UNDEF_INT },
 { EVE_SCADA_CONFIG_ERRORS , PLC_EVENT    , EMPTY_STRING, UNDEF_INT },
 { EVE_CRITICAL_CONFIG     , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_NEW_CONFIG_ERROR    , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_CONFLICT_CONFIGS    , PLC_EVENT_B2B, EMPTY_STRING, UNDEF_INT },
 { EVE_EXIT_SCADA_PROGRAM  , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_CONFIG_PLC_TO_SCADA , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_CONFIG_SCADA_TO_PLC , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_CONFIG_UIMAN_TO_PLC , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_NEW_CONFIG_SAVED    , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_ATTEMPT_CHANGE_FIXED, NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_REQUEST_TIMEOUT     , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_PLANT_WAS_STARTED   , PLC_EVENT    , EMPTY_STRING, UNDEF_INT },
 { EVE_PLANT_WAS_STOPPED   , PLC_EVENT    , EMPTY_STRING, UNDEF_INT },
 { EVE_T3_PUMPS_DUAL_FORCE , PLC_EVENT_B2B, EMPTY_STRING, UNDEF_INT },
 { EVE_LIFT_ST_LVL_HIGH    , PLC_EVENT_B2B, EMPTY_STRING, UNDEF_INT },
 { EVE_SERVICE_START       , NO_EVENT     , EMPTY_STRING, UNDEF_INT }, //! MANUAL OPERATING SERVICES
 { EVE_SERVICE_FINISH      , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_SERVICE_PC_REBOOT   , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_SERVICE_STP_START   , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_SERVICE_STP_STOP    , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_SERVICE_ERR_ACK     , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_SERVICE_ALL_TO_MAN  , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_SERVICE_ALL_TO_AUTO , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 
 { EVE_INTO_MAN_BL1A       , NO_EVENT     , EMPTY_STRING, UNDEF_INT }, //! SWITCHING DEVICES MODE INTO MANUAL MODE
 { EVE_INTO_MAN_BL1B       , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_INTO_MAN_BL2        , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_INTO_MAN_PUMPS      , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_INTO_MAN_UV         , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_INTO_MAN_SOL        , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_INTO_MAN_ACT        , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_INTO_MAN_LIFT       , NO_EVENT     , EMPTY_STRING, UNDEF_INT },

 { EVE_INTO_AUTO_BL1A      , NO_EVENT     , EMPTY_STRING, UNDEF_INT }, //! SWITCHING DEVICES MODE INTO AUTO MODE
 { EVE_INTO_AUTO_BL1B      , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_INTO_AUTO_BL2       , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_INTO_AUTO_PUMPS     , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_INTO_AUTO_UV        , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_INTO_AUTO_SOL       , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_INTO_AUTO_ACT       , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_INTO_AUTO_LIFT      , NO_EVENT     , EMPTY_STRING, UNDEF_INT },

 { EVE_INTO_ENBL_BL1A      , NO_EVENT     , EMPTY_STRING, UNDEF_INT }, //! SWITCHING TO ENABLE DEVICE
 { EVE_INTO_ENBL_BL1B      , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_INTO_ENBL_BL2       , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_INTO_ENBL_PUMP1     , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_INTO_ENBL_PUMP2     , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_INTO_ENBL_UV        , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_INTO_ENBL_SOL       , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_INTO_ENBL_LIFT      , NO_EVENT     , EMPTY_STRING, UNDEF_INT },

 { EVE_INTO_DIS_BL1A       , NO_EVENT     , EMPTY_STRING, UNDEF_INT }, //! SWITCHING TO DISABLE DEVICE
 { EVE_INTO_DIS_BL1B       , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_INTO_DIS_BL2        , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_INTO_DIS_PUMP1      , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_INTO_DIS_PUMP2      , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_INTO_DIS_UV         , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_INTO_DIS_SOL        , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_INTO_DIS_LIFT       , NO_EVENT     , EMPTY_STRING, UNDEF_INT },

 { EVE_SWITCH_ON_BL1A      , NO_EVENT     , EMPTY_STRING, UNDEF_INT }, //! MANUAL START OF THE DEVICE
 { EVE_SWITCH_ON_BL1B      , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_SWITCH_ON_BL2       , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_SWITCH_ON_PUMP1     , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_SWITCH_ON_PUMP2     , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_SWITCH_ON_UV        , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_SWITCH_ON_SOL       , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_SWITCH_ON_LIFT      , NO_EVENT     , EMPTY_STRING, UNDEF_INT },

 { EVE_SWITCH_OFF_BL1A     , NO_EVENT     , EMPTY_STRING, UNDEF_INT }, //! MANUAL STOP OF THE DEVICE
 { EVE_SWITCH_OFF_BL1B     , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_SWITCH_OFF_BL2      , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_SWITCH_OFF_PUMP1    , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_SWITCH_OFF_PUMP2    , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_SWITCH_OFF_UV       , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_SWITCH_OFF_SOL      , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_SWITCH_OFF_LIFT     , NO_EVENT     , EMPTY_STRING, UNDEF_INT },

 { EVE_ACTUATOR_STEP_UP    , NO_EVENT     , EMPTY_STRING, UNDEF_INT }, //! ACTUATOR MANUAL OPERATIONS
 { EVE_ACTUATOR_STEP_DOWN  , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 
 { EVE_UPDATE_SYSTEM_DATA  , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_AUTHENTICATION_OK   , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_MAINTENANCE_REMINDER, NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_EMRG_EMAIL_WAS_SENT , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_EMERGENCY_STOP      , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_ACTIVATED_SENS_PAGE , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_DB_RECORD_ON_CHANGE , PLC_EVENT    , EMPTY_STRING, UNDEF_INT },
 { EVE_MINUTELY_DB_RECORD  ,CONSTANT_EVENT, EMPTY_STRING, UNDEF_INT },

 //new added
 { EVE_SWITCH_ON_SOL1      , NO_EVENT     , EMPTY_STRING, UNDEF_INT }, //! MANUAL START OF THE DEVICE (SOL1 to SOL9)
 { EVE_SWITCH_ON_SOL2      , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_SWITCH_ON_SOL3      , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_SWITCH_ON_SOL4      , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_SWITCH_ON_SOL5      , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_SWITCH_ON_SOL6      , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_SWITCH_ON_SOL7      , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_SWITCH_ON_SOL8      , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_SWITCH_ON_SOL9      , NO_EVENT     , EMPTY_STRING, UNDEF_INT },

 { EVE_SWITCH_OFF_SOL1     , NO_EVENT     , EMPTY_STRING, UNDEF_INT }, //! MANUAL STOP OF THE DEVICE (SOL1 to SOL9)
 { EVE_SWITCH_OFF_SOL2     , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_SWITCH_OFF_SOL3     , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_SWITCH_OFF_SOL4     , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_SWITCH_OFF_SOL5     , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_SWITCH_OFF_SOL6     , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_SWITCH_OFF_SOL7     , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_SWITCH_OFF_SOL8     , NO_EVENT     , EMPTY_STRING, UNDEF_INT },
 { EVE_SWITCH_OFF_SOL9     , NO_EVENT     , EMPTY_STRING, UNDEF_INT },

    //! add more events here, define new events ids in dispatcher.h
 { EVE_MAX_NUMBER          , NO_EVENT     , EMPTY_STRING, UNDEF_INT }
};

//!!!!!!!  IMPORTANT !!!!!!!!!!  IMPORTANT  !!!!!!!!  IMPORTANT !!!!!!!!!!
//!  -----------------------------------------------------------------  //
//!  all changes in this array might be done only by dispatcher daemon  //
//!     for other processes eve_proceed[] array is just read only       //
//!  -----------------------------------------------------------------  //
//!!!!!!!  IMPORTANT !!!!!!!!!!  IMPORTANT  !!!!!!!!  IMPORTANT !!!!!!!!!!
static event_dsptch_t init_tbl_proceed[] = {
 //!    event_id              event_type       event_msg               back_msg      event_val  event_run timer init start cycle
 { EVE_USER_LOGIN_SUCCEED  , LOG_MSG_INFO, MSG_USER_LOGIN_SUCCEED  , EMPTY_STRING  , UNDEF_INT, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_OPER_LOGIN_SUCCEED  , LOG_MSG_INFO, MSG_OPER_LOGIN_SUCCEED  , EMPTY_STRING  , UNDEF_INT, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_SERV_LOGIN_SUCCEED  , LOG_MSG_INFO, MSG_SERV_LOGIN_SUCCEED  , EMPTY_STRING  , UNDEF_INT, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_CLIENT_LOGGED_OUT   , LOGFILE_INFO, MSG_CLIENT_LOGGED_OUT   , EMPTY_STRING  , UNDEF_INT, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_CLIENT_QUIT_SESSION , LOGFILE_INFO, MSG_CLIENT_QUIT_SESSION , EMPTY_STRING  , UNDEF_INT, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_SESSION_TIMED_OUT   , LOGFILE_INFO, MSG_SESSION_TIMED_OUT   , EMPTY_STRING  , UNDEF_INT, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_CLIENT_LOGIN_FAILED , LOGFILE_CRIT, MSG_CLIENT_LOGIN_FAILED , EMPTY_STRING  , UNDEF_INT, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_USER_LOGIN_FAILED   , LOGFILE_CRIT, MSG_USER_LOGIN_FAILED   , EMPTY_STRING  , UNDEF_INT, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_REMOTE_OPER_LOGIN   , LOG_MSG_WARN, MSG_REMOTE_OPER_LOGIN   , EMPTY_STRING  , UNDEF_INT, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_NO_SERV_SYSTEM_BUSY , LOGFILE_WARN, MSG_NO_SERV_SYSTEM_BUSY , EMPTY_STRING  , UNDEF_INT, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_USER_LOGIN_IS_BUSY  , LOGFILE_WARN, MSG_USER_LOGIN_IS_BUSY  , EMPTY_STRING  , UNDEF_INT, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_SERV_LOGIN_IS_BUSY  , LOGFILE_WARN, MSG_SERV_LOGIN_IS_BUSY  , EMPTY_STRING  , UNDEF_INT, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_CLIENT_IP_CONNECTED , LOGFILE_INFO, MSG_CLIENT_IP_CONNECTED , EMPTY_STRING  , UNDEF_INT, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_CLIENT_DISCONNECTED , LOG_MSG_INFO, MSG_CLIENT_DISCONNECTED , EMPTY_STRING  , UNDEF_INT, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_PVS_WAS_TERMINATED  , LOGFILE_CRIT, MSG_PVS_WAS_TERMINATED  , EMPTY_STRING  , UNDEF_INT, NO_EVENT,  0  , 0  ,  0  ,  0  },
 //! PLC ERROR EVENTS
 { EVE_PLC_CONNECTION_ERR  , LOG_MSG_CRIT, MSG_PLC_NO_CONNECTION   , MSG_PLC_CONNECTED , UNDEF_INT, NO_EVENT, 0  ,0  , 0  , 0  },
 { EVE_SEN1_CONNECTION_ERR , LOG_MSG_WARN, MSG_SEN1_NO_CONNECTION  , MSG_SEN1_CONNECTED, UNDEF_INT, NO_EVENT, 0  ,0  , 0  , 0  },
 { EVE_SEN2_CONNECTION_ERR , LOG_MSG_WARN, MSG_SEN1_NO_CONNECTION  , MSG_SEN1_CONNECTED, UNDEF_INT, NO_EVENT, 0  ,0  , 0  , 0  },
 { EVE_SEN3_CONNECTION_ERR , LOG_MSG_WARN, MSG_SEN1_NO_CONNECTION  , MSG_SEN1_CONNECTED, UNDEF_INT, NO_EVENT, 0  ,0  , 0  , 0  },
 { EVE_ACTUATOR_ERR        , LOG_MSG_CRIT, MSG_ACTUATOR_ERR        , MSG_ACTUATOR_IS_OK, UNDEF_INT, NO_EVENT, 0  ,0  , 0  , 0  },
 { EVE_ACT_NO_SIGNAL_ERR   , LOG_MSG_CRIT, MSG_ACT_NO_SIGNAL_ERR   , MSG_ACT_SYGN_IS_OK, UNDEF_INT, NO_EVENT, 0  ,0  , 0  , 0  },
 { EVE_ACT_POSITION_ERR    , LOG_MSG_CRIT, MSG_ACT_POSITION_ERR    , MSG_ACTU_POS_IS_OK, UNDEF_INT, NO_EVENT, 0  ,0  , 0  , 0  },
 { EVE_MAGM_NO_SIGNAL_ERR  , LOG_MSG_CRIT, MSG_MAGM_NO_SIGNAL_ERR  , MSG_MAGMETER_IS_OK, UNDEF_INT, NO_EVENT, 0  ,0  , 0  , 0  },
 { EVE_SOFT_START_1A_ERR   , LOG_MSG_CRIT, MSG_SOFT_START_1A_ERR   , MSG_SSTART1A_IS_OK, UNDEF_INT, NO_EVENT, 0  ,0  , 0  , 0  },
 { EVE_PRESSURE_SW1A_ERR   , LOG_MSG_CRIT, MSG_PRESSURE_SW1A_ERR   , MSG_PRESSW1A_IS_OK, UNDEF_INT, NO_EVENT, 0  ,0  , 0  , 0  },
 { EVE_SOFT_START_1B_ERR   , LOG_MSG_CRIT, MSG_SOFT_START_1B_ERR   , MSG_SSTART1B_IS_OK, UNDEF_INT, NO_EVENT, 0  ,0  , 0  , 0  },
 { EVE_PRESSURE_SW1B_ERR   , LOG_MSG_CRIT, MSG_PRESSURE_SW1B_ERR   , MSG_PRESSW1B_IS_OK, UNDEF_INT, NO_EVENT, 0  ,0  , 0  , 0  },
 { EVE_SOFT_START_2_ERR    , LOG_MSG_CRIT, MSG_SOFT_START_2_ERR    , MSG_SSTART_2_IS_OK, UNDEF_INT, NO_EVENT, 0  ,0  , 0  , 0  },
 { EVE_PRESSURE_SW_2_ERR   , LOG_MSG_CRIT, MSG_PRESSURE_SW_2_ERR   , MSG_PRESSW_2_IS_OK, UNDEF_INT, NO_EVENT, 0  ,0  , 0  , 0  },
 { EVE_T3_LVL_SENSOR_ERR   , LOG_MSG_CRIT, MSG_T3_LVL_SENSOR_ERR   , MSG_T3LVLSEN_IS_OK, UNDEF_INT, NO_EVENT, 0  ,0  , 0  , 0  },
 { EVE_LVL_SEN_NO_SIG_ERR  , LOG_MSG_CRIT, MSG_LVL_SEN_NO_SIG_ERR  , MSG_T3LVLSEN_IS_OK, UNDEF_INT, NO_EVENT, 0  ,0  , 0  , 0  },
 { EVE_T3_SWITCHES_ERR     , LOG_MSG_CRIT, MSG_T3_SWITCHES_ERR     , MSG_SWITCHES_IS_OK, UNDEF_INT, NO_EVENT, 0  ,0  , 0  , 0  },
 { EVE_PUMP_ONE_ERR        , LOG_MSG_CRIT, MSG_PUMP_ONE_ERR        , MSG_PUMP_ONE_IS_OK, UNDEF_INT, NO_EVENT, 0  ,0  , 0  , 0  },
 { EVE_PUMP_TWO_ERR        , LOG_MSG_CRIT, MSG_PUMP_TWO_ERR        , MSG_PUMP_TWO_IS_OK, UNDEF_INT, NO_EVENT, 0  ,0  , 0  , 0  },
 { EVE_MAIN_LINE_ERR       , LOG_MSG_CRIT, MSG_MAIN_LINE_ERR       , MSG_MAINLINE_IS_OK, UNDEF_INT, NO_EVENT, 0  ,0  , 0  , 0  },
 { EVE_LINE1_PHASE_ERR     , LOG_MSG_CRIT, MSG_LINE1_PHASE_ERR     , MSG_L1_PHASE_IS_OK, UNDEF_INT, NO_EVENT, 0  ,0  , 0  , 0  },
 { EVE_LINE2_PHASE_ERR     , LOG_MSG_CRIT, MSG_LINE2_PHASE_ERR     , MSG_L2_PHASE_IS_OK, UNDEF_INT, NO_EVENT, 0  ,0  , 0  , 0  },
 { EVE_LINE3_PHASE_ERR     , LOG_MSG_CRIT, MSG_LINE3_PHASE_ERR     , MSG_L3_PHASE_IS_OK, UNDEF_INT, NO_EVENT, 0  ,0  , 0  , 0  },
 { EVE_UV_SEN_NO_SIG_ERR   , LOG_MSG_CRIT, MSG_UV_SEN_NO_SIG_ERR   , MSG_UV_SENOR_IS_OK, UNDEF_INT, NO_EVENT, 0  ,0  , 0  , 0  },
 { EVE_LIFT_NO_SIGN_ERR    , LOG_MSG_CRIT, MSG_LIFT_NO_SIGN_ERR    , MSG_LIFT_SEN_IS_OK, UNDEF_INT, NO_EVENT, 0  ,0  , 0  , 0  },
 //! PLC EMERGENCY EVENTS
 { EVE_ACTUATOR_EMERGENCY  , LOG_MSG_CRIT, MSG_ACTUATOR_EMERGENCY  , MSG_ACTUATOR_EMRG_ENDS, UNDEF_INT, NO_EVENT, 0, 0, 0 , 0  },
 { EVE_MAGMETER_EMERGENCY  , LOG_MSG_CRIT, MSG_MAGMETER_EMERGENCY  , MSG_MAGMETER_EMRG_ENDS, UNDEF_INT, NO_EVENT, 0, 0, 0 , 0  },
 { EVE_CHAMBER3_EMERGENCY  , LOG_MSG_CRIT, MSG_CHAMBER3_EMERGENCY  , MSG_CHAMBER3_EMRG_ENDS, UNDEF_INT, NO_EVENT, 0, 0, 0 , 0  },
 { EVE_PUMPS_EMERGENCY     , LOG_MSG_CRIT, MSG_PUMPS_EMERGENCY     , MSG_PUMPS_EMRG_ENDS   , UNDEF_INT, NO_EVENT, 0, 0, 0 , 0  },
 { EVE_LIFT_ST_LVL_EMRGENCY, LOG_MSG_CRIT, MSG_LIFT_ST_LVL_EMRGENCY, MSG_LIFT_ST_LVL_EMRG_ENDS,UNDEF_INT,NO_EVENT,0, 0, 0 , 0  },
 { EVE_POWER_FAILURE_EMERG , LOG_MSG_CRIT, MSG_POWER_EMERGENCY     , MSG_POWER_EMRG_ENDS   , UNDEF_INT, NO_EVENT, 0, 0, 0 , 0  },
 { EVE_SYSTOPED_EMERGENCY  , LOG_MSG_CRIT, MSG_SYSTOPED_EMERGENCY  , MSG_SYSTOPED_EMRG_ENDS, UNDEF_INT, NO_EVENT, 0, 0, 0 , 0  },
 { EVE_EMERGENCY_ISSUE     , LOGFILE_INFO, MSG_EMERGENCY_ISSUE     , EMPTY_STRING, UNDEF_INT, NO_EVENT, 0, 0, 0 , HALF_HOUR_SEC},
 //! PLC-SCADA CONFIGURATION EVENTS
 { EVE_SCADA_CONFIG_STATUS , LOG_MSG_WARN, MSG_SCADA_NOT_CONFIGURED, MSG_SCADACONFIGOK,UNDEF_INT,NO_EVENT, 0  , 0  ,  0  ,  0  },
 { EVE_SCADA_CONFIG_ERRORS , LOG_MSG_WARN, MSG_SCADA_CONFIG_ERRORS , MSG_NO_CONFLICTS, UNDEF_INT,NO_EVENT, 0  , 0  ,  0  ,  0  },
 { EVE_CRITICAL_CONFIG     , LOG_MSG_CRIT, MSG_CRITICAL_CONFIG     , EMPTY_STRING  ,   UNDEF_INT,NO_EVENT, 0  , 0  ,  0  ,  0  },
 { EVE_NEW_CONFIG_ERROR    , LOG_MSG_WARN, MSG_NEW_CONFIG_ERROR    , MSG_NO_CONFLICTS, UNDEF_INT,NO_EVENT, 0  , 0  ,  0  ,  0  },
 { EVE_CONFLICT_CONFIGS    , LOG_MSG_WARN, MSG_CONFLICT_CONFIGS    , MSG_NO_CONFLICTS, UNDEF_INT,NO_EVENT, 0  , 0  ,  0  ,  0  },
 { EVE_EXIT_SCADA_PROGRAM  , LOG_MSG_CRIT, MSG_EXIT_SCADA_PROGRAM  , EMPTY_STRING  , UNDEF_INT, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_CONFIG_PLC_TO_SCADA , LOG_MSG_WARN, MSG_CONFIG_PLC_TO_SCADA , EMPTY_STRING  , UNDEF_INT, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_CONFIG_SCADA_TO_PLC , LOG_MSG_INFO, MSG_CONFIG_SCADA_TO_PLC , EMPTY_STRING  , 1, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_CONFIG_UIMAN_TO_PLC , LOG_MSG_INFO, MSG_CONFIG_UIMAN_TO_PLC , EMPTY_STRING  , 1, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_NEW_CONFIG_SAVED    , LOG_MSG_INFO, MSG_NEW_CONFIG_SAVED    , EMPTY_STRING  , UNDEF_INT, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_ATTEMPT_CHANGE_FIXED, LOG_MSG_WARN, MSG_ATTEMPT_CHANGE_FIXED, EMPTY_STRING  , UNDEF_INT, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_REQUEST_TIMEOUT     , LOGFILE_WARN, MSG_REQUEST_TIMEOUT     , EMPTY_STRING  , UNDEF_INT, NO_EVENT,  0  , 0  ,  0  ,  0  },
 //! PLC-SCADA ROUTINE EVENTS
 { EVE_PLANT_WAS_STARTED   , LOG_MSG_INFO, MSG_PLANT_WAS_STARTED   , EMPTY_STRING  , UNDEF_INT, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_PLANT_WAS_STOPPED   , LOG_MSG_WARN, MSG_PLANT_WAS_STOPPED,    EMPTY_STRING  , UNDEF_INT, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_T3_PUMPS_DUAL_FORCE , LOG_MSG_WARN, MSG_T3_PUMPS_DUAL_FORCE , MSG_PUMPS_DUAL_FORCE_ENDS, UNDEF_INT, NO_EVENT, 0, 0, 0, 0},
 { EVE_LIFT_ST_LVL_HIGH    , LOG_MSG_WARN, MSG_LIFT_ST_LVL_HIGH    , MSG_LIFT_ST_LVL_HIGH_ENDS, UNDEF_INT, NO_EVENT, 0, 0, 0, 0},
 //! SCADA SERVICES EVENTS
 { EVE_SERVICE_START       , LOGFILE_INFO, MSG_SERVICE_START       , EMPTY_STRING  , 1, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_SERVICE_FINISH      , LOGFILE_INFO, MSG_SERVICE_FINISH      , EMPTY_STRING  , 0, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_SERVICE_PC_REBOOT   , LOGFILE_INFO, MSG_SERVICE_PC_REBOOT   , EMPTY_STRING  , 1, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_SERVICE_STP_START   , LOGFILE_INFO, MSG_SERVICE_CIP_START   , EMPTY_STRING  , 1, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_SERVICE_STP_STOP    , LOGFILE_INFO, MSG_SERVICE_CIP_STOP    , EMPTY_STRING  , 1, NO_EVENT,  0  , 0  ,  0  ,  0  },
 
 { EVE_SERVICE_ERR_ACK     , LOGFILE_INFO, MSG_SERVICE_ERR_ACK     , EMPTY_STRING  , 1, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_SERVICE_ALL_TO_MAN  , LOGFILE_INFO, MSG_SERVICE_ALL_TO_MAN  , EMPTY_STRING  , 1, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_SERVICE_ALL_TO_AUTO , LOGFILE_INFO, MSG_SERVICE_ALL_TO_AUTO , EMPTY_STRING  , 0, NO_EVENT,  0  , 0  ,  0  ,  0  },
 //! SWITCHING DEVICES MODE INTO MANUAL
 
 { EVE_INTO_MAN_BL1A       , LOGFILE_INFO, MSG_INTO_MAN_BL1A       , EMPTY_STRING  , 1, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_INTO_MAN_BL1B       , LOGFILE_INFO, MSG_INTO_MAN_BL1B       , EMPTY_STRING  , 1, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_INTO_MAN_BL2        , LOGFILE_INFO, MSG_INTO_MAN_BL2        , EMPTY_STRING  , 1, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_INTO_MAN_PUMPS      , LOGFILE_INFO, MSG_INTO_MAN_PUMPS      , EMPTY_STRING  , 1, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_INTO_MAN_UV         , LOGFILE_INFO, MSG_INTO_MAN_UV         , EMPTY_STRING  , 1, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_INTO_MAN_SOL        , LOGFILE_INFO, MSG_INTO_MAN_SOL        , EMPTY_STRING  , 1, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_INTO_MAN_ACT        , LOGFILE_INFO, MSG_INTO_MAN_ACT        , EMPTY_STRING  , 1, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_INTO_MAN_LIFT       , LOGFILE_INFO, MSG_INTO_MAN_LIFT       , EMPTY_STRING  , 1, NO_EVENT,  0  , 0  ,  0  ,  0  },
 //! SWITCHING DEVICES MODE INTO AUTO
 { EVE_INTO_AUTO_BL1A      , LOGFILE_INFO, MSG_INTO_AUTO_BL1A      , EMPTY_STRING  , 0, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_INTO_AUTO_BL1B      , LOGFILE_INFO, MSG_INTO_AUTO_BL1B      , EMPTY_STRING  , 0, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_INTO_AUTO_BL2       , LOGFILE_INFO, MSG_INTO_AUTO_BL2       , EMPTY_STRING  , 0, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_INTO_AUTO_PUMPS     , LOGFILE_INFO, MSG_INTO_AUTO_PUMPS     , EMPTY_STRING  , 0, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_INTO_AUTO_UV        , LOGFILE_INFO, MSG_INTO_AUTO_UV        , EMPTY_STRING  , 0, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_INTO_AUTO_SOL       , LOGFILE_INFO, MSG_INTO_AUTO_SOL       , EMPTY_STRING  , 0, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_INTO_AUTO_ACT       , LOGFILE_INFO, MSG_INTO_AUTO_ACT       , EMPTY_STRING  , 0, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_INTO_AUTO_LIFT      , LOGFILE_INFO, MSG_INTO_AUTO_LIFT      , EMPTY_STRING  , 0, NO_EVENT,  0  , 0  ,  0  ,  0  },
 //! SWITCHING TO ENABLE DEVICE
 { EVE_INTO_ENBL_BL1A      , LOGFILE_INFO, MSG_INTO_ENBL_BL1A      , EMPTY_STRING  , 1, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_INTO_ENBL_BL1B      , LOGFILE_INFO, MSG_INTO_ENBL_BL1B      , EMPTY_STRING  , 1, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_INTO_ENBL_BL2       , LOGFILE_INFO, MSG_INTO_ENBL_BL2       , EMPTY_STRING  , 1, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_INTO_ENBL_PUMP1     , LOGFILE_INFO, MSG_INTO_ENBL_PUMP1     , EMPTY_STRING  , 1, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_INTO_ENBL_PUMP2     , LOGFILE_INFO, MSG_INTO_ENBL_PUMP2     , EMPTY_STRING  , 1, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_INTO_ENBL_UV        , LOGFILE_INFO, MSG_INTO_ENBL_UV        , EMPTY_STRING  , 1, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_INTO_ENBL_SOL       , LOGFILE_INFO, MSG_INTO_ENBL_SOL       , EMPTY_STRING  , 1, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_INTO_ENBL_LIFT      , LOGFILE_INFO, MSG_INTO_ENBL_LIFT      , EMPTY_STRING  , 1, NO_EVENT,  0  , 0  ,  0  ,  0  },
 //! SWITCHING TO DISABLE DEVICE
 { EVE_INTO_DIS_BL1A       , LOGFILE_INFO, MSG_INTO_DIS_BL1A       , EMPTY_STRING  , 0, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_INTO_DIS_BL1B       , LOGFILE_INFO, MSG_INTO_DIS_BL1B       , EMPTY_STRING  , 0, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_INTO_DIS_BL2        , LOGFILE_INFO, MSG_INTO_DIS_BL2        , EMPTY_STRING  , 0, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_INTO_DIS_PUMP1      , LOGFILE_INFO, MSG_INTO_DIS_PUMP1      , EMPTY_STRING  , 0, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_INTO_DIS_PUMP2      , LOGFILE_INFO, MSG_INTO_DIS_PUMP2      , EMPTY_STRING  , 0, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_INTO_DIS_UV         , LOGFILE_INFO, MSG_INTO_DIS_UV         , EMPTY_STRING  , 0, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_INTO_DIS_SOL        , LOGFILE_INFO, MSG_INTO_DIS_SOL        , EMPTY_STRING  , 0, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_INTO_DIS_LIFT       , LOGFILE_INFO, MSG_INTO_DIS_LIFT       , EMPTY_STRING  , 0, NO_EVENT,  0  , 0  ,  0  ,  0  },
 //! MANUAL START OF THE DEVICE
 { EVE_SWITCH_ON_BL1A      , LOGFILE_INFO, MSG_DEV_STARTED_BL1A    , EMPTY_STRING  , 1, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_SWITCH_ON_BL1B      , LOGFILE_INFO, MSG_DEV_STARTED_BL1B    , EMPTY_STRING  , 1, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_SWITCH_ON_BL2       , LOGFILE_INFO, MSG_DEV_STARTED_BL2     , EMPTY_STRING  , 1, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_SWITCH_ON_PUMP1     , LOGFILE_INFO, MSG_DEV_STARTED_PUMP1   , EMPTY_STRING  , 1, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_SWITCH_ON_PUMP2     , LOGFILE_INFO, MSG_DEV_STARTED_PUMP2   , EMPTY_STRING  , 1, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_SWITCH_ON_UV        , LOGFILE_INFO, MSG_DEV_STARTED_UV      , EMPTY_STRING  , 1, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_SWITCH_ON_SOL       , LOGFILE_INFO, MSG_DEV_STARTED_SOL     , EMPTY_STRING  , 1, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_SWITCH_ON_LIFT      , LOGFILE_INFO, MSG_DEV_STARTED_LIFT    , EMPTY_STRING  , 1, NO_EVENT,  0  , 0  ,  0  ,  0  },
 //! MANUAL STOP OF THE DEVICE
 { EVE_SWITCH_OFF_BL1A     , LOGFILE_INFO, MSG_DEV_STOPED_BL1A     , EMPTY_STRING  , 0, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_SWITCH_OFF_BL1B     , LOGFILE_INFO, MSG_DEV_STOPED_BL1B     , EMPTY_STRING  , 0, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_SWITCH_OFF_BL2      , LOGFILE_INFO, MSG_DEV_STOPED_BL2      , EMPTY_STRING  , 0, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_SWITCH_OFF_PUMP1    , LOGFILE_INFO, MSG_DEV_STOPED_PUMP1    , EMPTY_STRING  , 0, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_SWITCH_OFF_PUMP2    , LOGFILE_INFO, MSG_DEV_STOPED_PUMP2    , EMPTY_STRING  , 0, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_SWITCH_OFF_UV       , LOGFILE_INFO, MSG_DEV_STOPED_UV       , EMPTY_STRING  , 0, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_SWITCH_OFF_SOL      , LOGFILE_INFO, MSG_DEV_STOPED_SOL      , EMPTY_STRING  , 0, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_SWITCH_OFF_LIFT     , LOGFILE_INFO, MSG_DEV_STOPED_LIFT     , EMPTY_STRING  , 0, NO_EVENT,  0  , 0  ,  0  ,  0  },
 //! ACTUATOR MANUAL OPERATIONS
 { EVE_ACTUATOR_STEP_UP    , LOGFILE_INFO, MSG_ACTUATOR_STEP_UP    , EMPTY_STRING  , 1, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_ACTUATOR_STEP_DOWN  , LOGFILE_INFO, MSG_ACTUATOR_STEP_DOWN  , EMPTY_STRING  , 1, NO_EVENT,  0  , 0  ,  0  ,  0  },
 
 { EVE_UPDATE_SYSTEM_DATA  , LOG_MSG_WARN, MSG_UPDATE_SYSTEM_DATA  , EMPTY_STRING  , 1, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_AUTHENTICATION_OK   , LOGFILE_INFO, MSG_AUTHENTICATION_OK   , EMPTY_STRING  , UNDEF_INT, NO_EVENT,  0, 0, 0, 0  },
 { EVE_MAINTENANCE_REMINDER, LOG_MSG_CRIT, MSG_MAINTENANCE_REMINDER, EMPTY_STRING  , UNDEF_INT, NO_EVENT,SIX_MONTHS_SEC,0,0,ONE_DAYS_SEC},
 { EVE_EMRG_EMAIL_WAS_SENT , LOGFILE_INFO, MSG_EMRG_EMAIL_WAS_SENT , EMPTY_STRING  , UNDEF_INT, NO_EVENT,  0, 0, 0, 0  },
 { EVE_EMERGENCY_STOP      , LOG_MSG_CRIT, MSG_EMERGENCY_STOP      , EMPTY_STRING  , UNDEF_INT, NO_EVENT,  0, 0, 0, ONE_HOUR_SEC},
 { EVE_ACTIVATED_SENS_PAGE , LOGFILE_INFO, MSG_ACTIVATED_SENS_PAGE , EMPTY_STRING  , UNDEF_INT, NO_EVENT,  0, 0, 0, 0  },
 { EVE_DB_RECORD_ON_CHANGE , LOG_UNDEFINED, EMPTY_STRING           , EMPTY_STRING  , UNDEF_INT, NO_EVENT,  0, 0, 0, 0  },
 { EVE_MINUTELY_DB_RECORD  , LOG_UNDEFINED, EMPTY_STRING           , EMPTY_STRING  , UNDEF_INT, NO_EVENT,  0, 0, 0, 0  },
 

 //! NEW MANUAL START OF THE DEVICE (SOL1 to SOL9)
 { EVE_SWITCH_ON_SOL1      , LOGFILE_INFO, MSG_DEV_STARTED_SOL1    , EMPTY_STRING  , 1, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_SWITCH_ON_SOL2      , LOGFILE_INFO, MSG_DEV_STARTED_SOL2    , EMPTY_STRING  , 1, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_SWITCH_ON_SOL3      , LOGFILE_INFO, MSG_DEV_STARTED_SOL3    , EMPTY_STRING  , 1, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_SWITCH_ON_SOL4      , LOGFILE_INFO, MSG_DEV_STARTED_SOL4    , EMPTY_STRING  , 1, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_SWITCH_ON_SOL5      , LOGFILE_INFO, MSG_DEV_STARTED_SOL5    , EMPTY_STRING  , 1, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_SWITCH_ON_SOL6      , LOGFILE_INFO, MSG_DEV_STARTED_SOL6    , EMPTY_STRING  , 1, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_SWITCH_ON_SOL7      , LOGFILE_INFO, MSG_DEV_STARTED_SOL7    , EMPTY_STRING  , 1, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_SWITCH_ON_SOL8      , LOGFILE_INFO, MSG_DEV_STARTED_SOL8    , EMPTY_STRING  , 1, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_SWITCH_ON_SOL9      , LOGFILE_INFO, MSG_DEV_STARTED_SOL9    , EMPTY_STRING  , 1, NO_EVENT,  0  , 0  ,  0  ,  0  },
 
 //! MANUAL STOP OF THE DEVICE
 { EVE_SWITCH_OFF_SOL1     , LOGFILE_INFO, MSG_DEV_STOPED_SOL1     , EMPTY_STRING  , 0, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_SWITCH_OFF_SOL2     , LOGFILE_INFO, MSG_DEV_STOPED_SOL2     , EMPTY_STRING  , 0, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_SWITCH_OFF_SOL3     , LOGFILE_INFO, MSG_DEV_STOPED_SOL3     , EMPTY_STRING  , 0, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_SWITCH_OFF_SOL4     , LOGFILE_INFO, MSG_DEV_STOPED_SOL4     , EMPTY_STRING  , 0, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_SWITCH_OFF_SOL5     , LOGFILE_INFO, MSG_DEV_STOPED_SOL5     , EMPTY_STRING  , 0, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_SWITCH_OFF_SOL6     , LOGFILE_INFO, MSG_DEV_STOPED_SOL6     , EMPTY_STRING  , 0, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_SWITCH_OFF_SOL7     , LOGFILE_INFO, MSG_DEV_STOPED_SOL7     , EMPTY_STRING  , 0, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_SWITCH_OFF_SOL8     , LOGFILE_INFO, MSG_DEV_STOPED_SOL8     , EMPTY_STRING  , 0, NO_EVENT,  0  , 0  ,  0  ,  0  },
 { EVE_SWITCH_OFF_SOL9     , LOGFILE_INFO, MSG_DEV_STOPED_SOL9     , EMPTY_STRING  , 0, NO_EVENT,  0  , 0  ,  0  ,  0  },
 
 //! add more events here, define new events ids in dispatcher.h
 { EVE_MAX_NUMBER          , LOG_UNDEFINED, EMPTY_STRING        , EMPTY_STRING  , UNDEF_INT, NO_EVENT, 0, 0, 0, 0 }
};

//! initialization table of emergencies
static bio_c_emerg_t emrgTable[MAX_NUM_EMERGENS] = {
   { NO_EMERGENCY  , EVE_NULL              , 0, 0 },
   { ACTUATOR_EMERG, EVE_ACTUATOR_EMERGENCY, 0, 0 },
   { MAGMETER_EMERG, EVE_MAGMETER_EMERGENCY, 0, 0 },
   { CHAMBER3_EMERG, EVE_CHAMBER3_EMERGENCY, 0, 0 },
   { PUMPS_EMERG   , EVE_PUMPS_EMERGENCY   , 0, 0 },
   { LIFT_ST_EMRG  , EVE_LIFT_ST_LVL_EMRGENCY  , 0, 0 },
   { EL_POWER_EMERG, EVE_POWER_FAILURE_EMERG, 0, 0 },
   { SYSTOPED_EMERG, EVE_SYSTOPED_EMERGENCY, 0, 0 },
};

#if DEBUG_DISPATCHER
//! PLC OPERATION MODES (enumeration from shamemchl.h)
static char *PLC_ModsList[NUM_PLC_MODES] = {
  (char *)"PLC_UNDEFINED",
  (char *)"INACTIVE",
  (char *)"EMERGENCY STOP"
};

//! EVENT STATUS TITLE TABLE (for debugging purpose only)
//! this table should match to events statuses enumeration in 'dispatcher.h'
static const char *EventStatusList[] = {
  "NO_EVENT",
  "INIT_EVENT",
  "QUIT_EVENT",
  
  //! REQUEST-ANSWER EVENT
  "RUN_EVENT",
  "STOP_EVENT",
  "SYS_ERR_INIT",
  "SYS_ERR_PROLONG",
  "SYS_ERR_RELEASE",
  "WAITING_EVENT",
  "PROLONGED_EVENT",
  "RESOLVED_EVENT",
  "TIME_OUT_EVENT",

  //! PLC EVENTS
  "PLC_EVENT",
  "PLC_EVENT_B2B",
  "PLC_EVENT_ON",
  "PLC_EVENT_OFF",
  
  //! OTHER EVENTS
  "DEFERRED_EVENT",
  "RECURRING_EVENT"
};
#endif

static uint plc_request_on = 0;

//!****************************************************************************
static void set_plc_request_off()
{
  plc_request_on = 0;
  #if DEBUG_DISPATCHER
  printf("set_plc_request_off(): plc_request_on = 0\n",
  #endif
}

//!****************************************************************************
static void set_plc_request_on()
{
  plc_request_on = 1;
  #if DEBUG_DISPATCHER
  printf("set_plc_request_off(): plc_request_on = 1\n",
  #endif
}

//!****************************************************************************
static int event_ind_resolved(int ind)
{
  int simple_eve_resolved    = 0;
  int prolonged_eve_resolved = 0;
  
  simple_eve_resolved = (eve_request[ind])->event_go  == NO_EVENT || 
                        ((eve_request[ind])->event_go == INIT_EVENT && 
                        (eve_proceed[ind])->event_run == QUIT_EVENT);

  prolonged_eve_resolved = //! requested event-table data
                           ((eve_request[ind])->event_go == RUN_EVENT &&
                           //! proceeding event-table data
                           ((eve_proceed[ind])->event_run == RESOLVED_EVENT  ||
                            (eve_proceed[ind])->event_run == TIME_OUT_EVENT ));
    
  return (simple_eve_resolved || prolonged_eve_resolved);
}

//!****************************************************************************
//!               INTERNAL and  EXTERNAL EVENT REQUESTS API
//!****************************************************************************
//! IMPORTATNT !!! USE EXTERNAL API FROM INTERPROCESS CALLS ONLY !!!!!!!!!!!!!!
//!                USE INTERNAL API FOR DISPATCHER NEEDS ONLY 
//!****************************************************************************
//!                    EXTERNAL EVENT REQUESTS API
//!----------------------------------------------------------------------------
//! event_request_value():  initiates the event by event id and set the value
//!                         for 'event_val'during interprocess communication
//!                         from SCADA pvs-server
//!----------------------------------------------------------------------------
//! args: 'id'        - event id, same for eve_request[] & eve_proceed[] arrays
//!       'status_val'- event status (EVENT STATUS ENUM in dispatcher.h)
//!       'value'     - some integer number
//!****************************************************************************
void event_request_value(int id, int status, int value)
{
  int  i = 0;
  do {
    if ((eve_request[i])->event_id == id){
       (eve_request[i])->event_go  = status;
       #if DEBUG_DISPATCHER
       printf(">>>>>\nevent_request_value(): id = %d; status = %d; value = %d\n>>>>>\n",
                                                       id, status, value);
       #endif
       (eve_request[i])->event_val = value;
       break;
    }
  } while ((eve_request[++i])->event_id != EVE_MAX_NUMBER);
}

//!****************************************************************************
//!                    EXTERNAL EVENT REQUESTS API
//!----------------------------------------------------------------------------
//! event_request_info(): initiates the event by event id and set an additional
//!                       msg for 'event_msg' during interprocess communication
//!                       from SCADA pvs-server
//!----------------------------------------------------------------------------
//! args: 'id'        - event id, same for eve_request[] & eve_proceed[] arrays
//!       'status_val'- event status (EVENT STATUS ENUM in dispatcher.h)
//!       '*eve_info' - additional changeable plane text information
//!****************************************************************************
void event_request_info(int id, int status, char *eve_info)
{
  int  i = 0;
  do {
    if ((eve_request[i])->event_id == id){
       (eve_request[i])->event_go  = status;
       //#if DEBUG_DISPATCHER
       printf(">>>>>\nevent_request_info(): id = %d; status = %d\n>>>>>\n",id,status);
       //#endif
       if (eve_info != NULL){
          strcpy((eve_request[i])->eve_info, eve_info);
       } else {
          strcpy((eve_request[i])->eve_info, EMPTY_STRING);
       }

       break;
    }
  } while ((eve_request[++i])->event_id != EVE_MAX_NUMBER);
}

//!****************************************************************************
//!                    EXTERNAL EVENT REQUESTS API
//!----------------------------------------------------------------------------
//! event_request():    initiates the simple event by event id during
//!                     interprocess communication from SCADA pvs-server
//!----------------------------------------------------------------------------
//! args: 'id'        - event id, same for eve_request[] & eve_proceed[] arrays
//!       'status_val'- event status (EVENT STATUS ENUM in dispatcher.h)
//!****************************************************************************
void event_request(int id, int status)
{
  event_request_info(id, status, NULL);
}

//!****************************************************************************
//!                    EXTERNAL EVENT REQUESTS API
//!----------------------------------------------------------------------------
//! reset_event_requests(): switches off statuses all events has been resolved 
//!----------------------------------------------------------------------------
//! no args
//!****************************************************************************
void reset_resolved_event_requests()
{
  int  i = 0;
  do {
    if (event_ind_resolved(i)){
       (eve_request[i])->event_go = NO_EVENT;
       strcpy((eve_request[i])->eve_info, EMPTY_STRING);
       (eve_request[i])->event_val = UNDEF_INT;
    }
  } while ((eve_request[++i])->event_id != EVE_MAX_NUMBER);
}

//!****************************************************************************
//!                    EXTERNAL EVENT REQUESTS API
//!----------------------------------------------------------------------------
//! reset_simple_eve_request(): switches off simple event status during
//!                             innterprocess communication between SCADA
//!                             pvs-server and PLC-server (can be forced)
//!----------------------------------------------------------------------------
//! args:'event_id'   - event id, same for eve_request[] & eve_proceed[] arrays
//!      'force_reset'- 1/0 bolean flag to force switching off the event
//!****************************************************************************
int reset_eve_request(int event_id, int force_reset)
{
  int  i = 0, eve_ind_resolved = 0, event_resolved = 0;
  do {
     if ((eve_request[i])->event_id == event_id){
        eve_ind_resolved = event_ind_resolved(i);

        if (eve_ind_resolved || force_reset){
          (eve_request[i])->event_go = NO_EVENT;
          strcpy((eve_request[i])->eve_info, EMPTY_STRING);
          (eve_request[i])->event_val = UNDEF_INT;
          event_resolved = 1;
        }
        break;
     }
  } while ((eve_request[++i])->event_id != EVE_MAX_NUMBER);
  
  #if DEBUG_DISPATCHER
  if (eve_request[++i])->event_id == EVE_MAX_NUMBER){
     printf("reset_simple_eve_request(): requested id event does not exist.\n");
  }
  #endif
  
  return event_resolved;
}

//!****************************************************************************
//!                    EXTERNAL EVENT REQUESTS API
//!----------------------------------------------------------------------------
//! (): returns status of the requested event
//!----------------------------------------------------------------------------
//! args:'event_id'             - event id, which status we need to check
//!****************************************************************************
int get_event_requested_status(int id)
{
  int  i = 0, status = UNDEF_INT;
  do {
    if ((eve_request[i])->event_id == id){
       status = (eve_request[i])->event_go;
       break;
    }
  } while ((eve_request[++i])->event_id != EVE_MAX_NUMBER);

  return status;
}

//!****************************************************************************
//!                    EXTERNAL EVENT REQUESTS API
//!----------------------------------------------------------------------------
//! get_event_proceeded_status() - returns event status for proceeded request 
//!                                during interprocess communication 
//!                                from SCADA pvs-server
//!----------------------------------------------------------------------------
//! args: 'id'        - event id, same for eve_request[] & eve_proceed[] arrays
//!----------------------------------------------------------------------------
//! returns: event status from eve_proceed[] array
//!****************************************************************************
int get_event_proceeded_status(int id)
{
  int  i = 0, status = UNDEF_INT;
  do {
    if ((eve_request[i])->event_id == id){
       status = (eve_proceed[i])->event_run;
       break;
    }
  } while ((eve_request[++i])->event_id != EVE_MAX_NUMBER);

  return status;
}

//!****************************************************************************
//!                    EXTERNAL EVENT REQUESTS API
//!----------------------------------------------------------------------------
//! get_event_proceeded_value(): returns assigned event-value for proceeded 
//!                              request during interprocess communication
//!                              from SCADA pvs-server
//!----------------------------------------------------------------------------
//! args: 'id'        - event id, same for eve_request[] & eve_proceed[] arrays
//!----------------------------------------------------------------------------
//! returns: event value from eve_proceed[] array
//!****************************************************************************
int get_event_proceeded_value(int id)
{
  int  i = 0, value = UNDEF_INT;
  do {
    if ((eve_request[i])->event_id == id){
       value = (eve_proceed[i])->event_val;
       break;
    }
  } while ((eve_request[++i])->event_id != EVE_MAX_NUMBER);

  return value;
}

//!****************************************************************************
//!         !!!!!!!!!!!! INTERNAL EVENT REQUESTS API !!!!!!!!!!!!!!!!
//!----------------------------------------------------------------------------
//! event_proceed() - initiates the event by event id and input status
//!                   for INTERNAL !!!!! dispatcher communication ONLY !!!!!!!!
//!----------------------------------------------------------------------------
//! args: 'id'        - event id, same for eve_request[] & eve_proceed[] arrays
//!       'status_val'- event status (EVENT STATUS ENUM in dispatcher.h)
//!****************************************************************************
static void event_proceed(int id, int status)
{
  int  i = 0;
  do {
    if ((eve_proceed[i])->event_id == id){
       (eve_proceed[i])->event_run = status;
       #if DEBUG_DISPATCHER
       printf(">>\nevent_proceed(): id = %d; status = %d\n>>\n", id, status);
       #endif
       break;
    }
  } while ((eve_proceed[++i])->event_id != EVE_MAX_NUMBER);
}
//!****************************************************************************
//!                       END OF EVENTS REQUESTs API
//!****************************************************************************

#if 0
// might be usefull in the future
//!****************************************************************************
static int get_run_status_by_id(int event_id)
{
  int  i, event_run_status = UNDEF_EVENT;
  
  for (i = 0; (eve_proceed[i])->event_id <= EVE_MAX_NUMBER; i++){
      if ((eve_proceed[i])->event_id == event_id){
         event_run_status = (eve_proceed[i])->event_run;
      }
  }
  return event_run_status;
}
#endif

//!****************************************************************************
static int sendmail(char *to, char *subj, char *msg)
{
  int retval = 0;
  FILE *mailpipe = NULL;
  char command[4096] = "";

  if (to != NULL && subj != NULL && msg != NULL){
     //! echo -e "body text" | mail -s "subject" email@example.com
     sprintf(command, "echo \"%s\" | mail -s \"%s\" %s\n", msg, subj, to);
     //! just for debugging
     printf("\n%s\n", command);

     //! Setup our pipe for reading and execute our command.
     mailpipe = popen(command,"w"); 

     //! Get the data from the process execution
     if (mailpipe != NULL) {
        if (pclose(mailpipe) != 0){
           printf(" Error: Failed to close command stream \n");
        } else {
           //! email was successfully sent
           retval = 1;
        }
     } else {
        printf("Failed to invoke sendmail().\n");
     }
  } else {
    //! just for debugging
    printf("sendmail(): Failed to send e-mail: No arguments were sent.\n");
    (to   == NULL)? printf("to   == NULL\n"): printf("     To:%s\n", to );
    (subj == NULL)? printf("subj == NULL\n"): printf("Subject:%s\n", subj);
    (msg  == NULL)? printf("msg  == NULL\n"): printf("Message:%s\n", msg );
  }
  return retval;
}

//!****************************************************************************
static int get_eve_ind_by_id(int event_id)
{
  int  i, ind = UNDEF_INT;
  
  for (i = 0; (eve_proceed[i])->event_id <= EVE_MAX_NUMBER; i++){
      if ((eve_proceed[i])->event_id == event_id){
         ind = i;
         break;
      }
  }
  return ind;
}

//!****************************************************************************
void log_print_waiting_resolved(int waiting_resolved, int ind)
{
  char buff[_SIZE_QK] = "";
 
  if (waiting_resolved == 1){
     sprintf(buff, "%s %s", (eve_proceed[ind])->event_msg, MSG_REQUEST_SOLVED);
     log_print((eve_proceed[ind])->event_type, buff);
              
  } else if (waiting_resolved == UNDEF_INT){
     sprintf(buff, "%s %s", (eve_proceed[ind])->event_msg, MSG_REQUEST_TIMEOUT);
     log_print((eve_proceed[ind])->event_type, buff);
  }
  #if DEBUG_DISPATCHER
  printf("proceed_waiting_event(): waiting_resolved = %d\n", waiting_resolved);
  #endif
}

//!****************************************************************************
static int proceed_waiting_event(int ind)
{
  int event_id, waiting_resolved = -2;
  
  if (ind >= 0 && ind < EVE_MAX_NUMBER){
    
    event_id   = (eve_proceed[ind])->event_id;

    switch (event_id){
#if 0   
        //! uncomment in case of the special proceeding        
        case EVE_SERVICE_FINISH: 
        case EVE_SERVICE_ALL_TO_AUTO:
        case EVE_INTO_AUTO_BL1A:
        case EVE_INTO_AUTO_BL1B:
        case EVE_INTO_AUTO_BL2:
        case EVE_INTO_AUTO_PUMPS:
        case EVE_INTO_AUTO_UV:
        case EVE_INTO_AUTO_SOL:
        case EVE_INTO_AUTO_ACT:
        case EVE_INTO_AUTO_LIFT:
        case EVE_INTO_DIS_BL1A:
        case EVE_INTO_DIS_BL1B:
        case EVE_INTO_DIS_BL2:
        case EVE_INTO_DIS_PUMP1:
        case EVE_INTO_DIS_PUMP2:
        case EVE_INTO_DIS_UV:
        case EVE_INTO_DIS_SOL:
        case EVE_INTO_DIS_LIFT:
        case EVE_SWITCH_OFF_BL1A:
        case EVE_SWITCH_OFF_BL1B:
        case EVE_SWITCH_OFF_BL2:
        case EVE_SWITCH_OFF_PUMP1:
        case EVE_SWITCH_OFF_PUMP2:
        case EVE_SWITCH_OFF_UV:
        case EVE_SWITCH_OFF_SOL:
        case EVE_SWITCH_OFF_LIFT:
        case EVE_INTO_MAN_BL1A:
        case EVE_INTO_MAN_BL1B:
        case EVE_INTO_MAN_BL2:
        case EVE_INTO_MAN_PUMPS:
        case EVE_INTO_MAN_UV:
        case EVE_INTO_MAN_SOL:
        case EVE_INTO_MAN_ACT:
        case EVE_INTO_MAN_LIFT:
        case EVE_INTO_ENBL_BL1A:
        case EVE_INTO_ENBL_BL1B:
        case EVE_INTO_ENBL_BL2:
        case EVE_INTO_ENBL_PUMP1:
        case EVE_INTO_ENBL_PUMP2:
        case EVE_INTO_ENBL_UV:
        case EVE_INTO_ENBL_SOL:
        case EVE_INTO_ENBL_LIFT:
        case EVE_SWITCH_ON_BL1A:
        case EVE_SWITCH_ON_BL1B:
        case EVE_SWITCH_ON_BL2:
        case EVE_SWITCH_ON_PUMP1:
        case EVE_SWITCH_ON_PUMP2:
        case EVE_SWITCH_ON_UV:
        case EVE_SWITCH_ON_SOL:
        case EVE_SWITCH_ON_LIFT:
        case EVE_ACTUATOR_STEP_UP:
        case EVE_ACTUATOR_STEP_DOWN:
        case EVE_SERVICE_START:
        case EVE_SERVICE_ERR_ACK:
        case EVE_SERVICE_STP_STOP: 
        case EVE_SERVICE_STP_START:
        case EVE_SERVICE_PC_REBOOT:
        case EVE_SERVICE_ALL_TO_MAN:
        case EVE_UPDATE_SYSTEM_DATA:
        case EVE_CONFIG_SCADA_TO_PLC:
        case EVE_CONFIG_UIMAN_TO_PLC:
#endif
        case EVE_SERVICE_START:
                 waiting_resolved = monitoring_scada_plc_request(event_id);
                 log_print_waiting_resolved(waiting_resolved, ind);
                 break;
      default:
           waiting_resolved = monitoring_scada_plc_request(event_id);
           log_print_waiting_resolved(waiting_resolved, ind);
           
    }
  }
  return waiting_resolved;
}

//!****************************************************************************
static void proceed_prolonged_event(int event_id, int event_status)
{
  int ind, request_value = UNDEF_INT, event_type = 0;
  char buf[_SIZE_QK] = "";

  ind = get_eve_ind_by_id(event_id);
  
  if (ind >= 0 && ind < EVE_MAX_NUMBER){  

     event_type = (eve_proceed[ind])->event_type;
     strcpy (buf, (eve_proceed[ind])->event_msg);
     request_value = (eve_proceed[ind])->event_val;
     #if DEBUG_DISPATCHER
     printf("proceed_prolonged_event(): event_type = %d, request_value = %d\n",
                                        event_type, request_value);
     #endif
     if (!plc_request_on){
        set_plc_request_on();
        //log_print(event_type, buf);
        #if DEBUG_DISPATCHER
        printf("id = %d, status = %d (%s)\n", event_id, event_status,
                                       EventStatusList[event_status]);
        #endif
     } else {
        #if DEBUG_DISPATCHER
        printf("attempt to proceed event id = %d, ", event_id);
        printf("status = %d (%s) failed: another request is processing\n",
                              event_status, EventStatusList[event_status]);
        #endif
     }
     switch (event_id){
#if 0
        //! uncomment in case of the special proceeding
        case EVE_SERVICE_FINISH: 
        case EVE_SERVICE_ALL_TO_AUTO:
        case EVE_INTO_AUTO_BL1A:
        case EVE_INTO_AUTO_BL1B:
        case EVE_INTO_AUTO_BL2:
        case EVE_INTO_AUTO_PUMPS:
        case EVE_INTO_AUTO_UV:
        case EVE_INTO_AUTO_SOL:
        case EVE_INTO_AUTO_ACT:
        case EVE_INTO_AUTO_LIFT:
        case EVE_INTO_DIS_BL1A:
        case EVE_INTO_DIS_BL1B:
        case EVE_INTO_DIS_BL2:
        case EVE_INTO_DIS_PUMP1:
        case EVE_INTO_DIS_PUMP2:
        case EVE_INTO_DIS_UV:
        case EVE_INTO_DIS_SOL:
        case EVE_INTO_DIS_LIFT:
        case EVE_SWITCH_OFF_BL1A:
        case EVE_SWITCH_OFF_BL1B:
        case EVE_SWITCH_OFF_BL2:
        case EVE_SWITCH_OFF_PUMP1:
        case EVE_SWITCH_OFF_PUMP2:
        case EVE_SWITCH_OFF_UV:
        case EVE_SWITCH_OFF_SOL:
        case EVE_SWITCH_OFF_LIFT:
        case EVE_INTO_MAN_BL1A:
        case EVE_INTO_MAN_BL1B:
        case EVE_INTO_MAN_BL2:
        case EVE_INTO_MAN_PUMPS:
        case EVE_INTO_MAN_UV:
        case EVE_INTO_MAN_SOL:
        case EVE_INTO_MAN_ACT:
        case EVE_INTO_MAN_LIFT:
        case EVE_INTO_ENBL_BL1A:
        case EVE_INTO_ENBL_BL1B:
        case EVE_INTO_ENBL_BL2:
        case EVE_INTO_ENBL_PUMP1:
        case EVE_INTO_ENBL_PUMP2:
        case EVE_INTO_ENBL_UV:
        case EVE_INTO_ENBL_SOL:
        case EVE_INTO_ENBL_LIFT:
        case EVE_SWITCH_ON_BL1A:
        case EVE_SWITCH_ON_BL1B:
        case EVE_SWITCH_ON_BL2:
        case EVE_SWITCH_ON_PUMP1:
        case EVE_SWITCH_ON_PUMP2:
        case EVE_SWITCH_ON_UV:
        case EVE_SWITCH_ON_SOL:
        case EVE_SWITCH_ON_LIFT:
        case EVE_ACTUATOR_STEP_UP:
        case EVE_ACTUATOR_STEP_DOWN:
        case EVE_SERVICE_START:
        case EVE_SERVICE_ERR_ACK:
        case EVE_SERVICE_STP_STOP: 
        case EVE_SERVICE_STP_START:
        case EVE_SERVICE_PC_REBOOT:
        case EVE_SERVICE_ALL_TO_MAN:
        case EVE_UPDATE_SYSTEM_DATA:
        case EVE_CONFIG_SCADA_TO_PLC:
        case EVE_CONFIG_UIMAN_TO_PLC:
#endif
     }
     if (request_value != UNDEF_INT){
        #if DEBUG_DISPATCHER
        printf("proceed_prolonged_event(): EVE_UPDATE_SYSTEM_DATA.....\n");
        #endif
        scada_plc_send_request(event_id, request_value);
        (eve_proceed[ind])->event_run = WAITING_EVENT;
     }
  }
}

//!****************************************************************************
static void proceed_deferred_event(int ind)
{
  int num_months = 0;
  int event_id, event_type;
  char buf[_SIZE_QK] = "";
  
  time_t curtime;
  long int l_cur_time = 0;
  
  if (ind >= 0 && ind < EVE_MAX_NUMBER){
    
    event_id   = (eve_proceed[ind])->event_id;
    event_type = (eve_proceed[ind])->event_type;
    strcpy (buf, (eve_proceed[ind])->event_msg);
    
    switch (event_id){
      case EVE_MAINTENANCE_REMINDER:

           curtime = time (NULL);
           l_cur_time  = (long int)(curtime);
           num_months = (l_cur_time - (eve_proceed[ind])->eve_init)/ONE_MONTH_SEC;
           log_print(event_type, buf, num_months);
           break;
    }
  }
}

//! ***************************************************************************
//! proceed_record_plc_event() is printing record message on condition value.
//! ---------------------------------------------------------------------------
//! In eim to avoid of messages multiplying printing :
//! 1) if condition is TRUE and 'event_run' flag is PLC_EVENT_OFF,
//!    'event_run' switches to PLC_EVENT_ON and activates log_print(), -
//!    this is one-time issue;
//! 2) if condition is FALSE and 'event_run' flag is PLC_EVENT_ON,
//!    'event_run' switches back to PLC_EVENT_OFF and if the event
//!    has PLC_EVENT_B2B type, it prints back message by log_print() call, -
//!    this is also one-time issue, 
//!    but if the event has PLC_EVENT type - it just resets the event status;
//! ---------------------------------------------------------------------------
//! FUNCTION MUST NOT BE CALLED UNDER THE CONDITION, SAME TO 'condition' VALUE
//! ***************************************************************************
static void proceed_record_plc_event(int ind, int condition)
{
  char buf[_SIZE_QK] = "";
  int type = LOGFILE_INFO;

  if (ind >= 0 && ind < EVE_MAX_NUMBER){
     #if DEBUG_DISPATCHER
     printf("dispatcher(): %s err = %d\n", eve_List[ind], condition);
     #endif

     if (condition == 1 && (eve_proceed[ind])->event_run == PLC_EVENT_OFF){
           
           (eve_proceed[ind])->event_run = PLC_EVENT_ON;

           strcpy(buf, (eve_proceed[ind])->event_msg);
           log_print((eve_proceed[ind])->event_type, buf);

     } else {
        if (condition == 0 && (eve_proceed[ind])->event_run != PLC_EVENT_OFF){

           (eve_proceed[ind])->event_run = PLC_EVENT_OFF;
   
           if ((eve_request[ind])->event_go == PLC_EVENT_B2B){
              if ((eve_proceed[ind])->event_type == LOG_MSG_CRIT ||
                  (eve_proceed[ind])->event_type == LOG_MSG_WARN){
                 type = LOG_MSG_INFO;
              } else if ((eve_proceed[ind])->event_type == LOG_MSG_INFO){
                 type = LOG_MSG_CRIT;
              } else if ((eve_proceed[ind])->event_type == LOGFILE_CRIT ||
                  (eve_proceed[ind])->event_type == LOGFILE_WARN){
                 type = LOGFILE_INFO;
              } else if ((eve_proceed[ind])->event_type == LOGFILE_INFO){
                 type = LOGFILE_CRIT;
              }
              
              strcpy(buf, (eve_proceed[ind])->back_msg);
              log_print(type, buf);
           }
        }
     }
  }
}

//!****************************************************************************
static void proceed_emergency_issue()
{
   int  service_on    = stp2pvs->service_mode;
   char hostname[128] = "";
   char email[256]    = "";
   char mesg[2048]    = "";
   char subj[256]     = "";
   int ind = 0;
   
   //strcpy (mesg, MSG_EMERGENCY_ISSUE);
   
   for (int i = 1; i < MAX_NUM_EMERGENS; i++){
       ind = get_eve_ind_by_id(emrgTable[i].eve_id);
       if (emrgTable[i].curr_stat == 1){
          strcat (mesg, (eve_proceed[ind])->event_msg);
       } else if (!service_on && emrgTable[i].curr_stat == 0 &&
                                 emrgTable[i].prev_stat == 1){
          strcat (mesg, (eve_proceed[ind])->back_msg);
       } else if (service_on){
          strcpy(mesg, MSG_EMRG_MAILING_STOPED);
          log_print(LOG_MSG_WARN, mesg);
          break;
       }
   }
   
   printf("proceed_emergency_issue(): %s\n",mesg);
   
   if (ldap_config->plant_name != NULL){
      sprintf (subj, "%s %s", MSG_EMERGENCY_ISSUE, ldap_config->plant_name);
   } else {
      gethostname(hostname, 1023);
      sprintf (subj, "%s %s", MSG_EMERGENCY_ISSUE, hostname);
   }
   //! check the e-mail configuration settings
   if (ldap_config->emrgemail1 != NULL && ldap_config->emrgemail2 != NULL){
      sprintf( email, "%s, %s", ldap_config->emrgemail1, ldap_config->emrgemail2);
   } else if (ldap_config->emrgemail1 != NULL){
      strcpy( email, ldap_config->emrgemail1);
   } else if (ldap_config->emrgemail2 != NULL){
      strcpy( email, ldap_config->emrgemail2);
   } else {
      return;
   }
   //! sending e-mail
   if(sendmail(email, subj, mesg)){
     #if DEBUG_DISPATCHER
     if (event_id == EVE_EMERGENCY_STOP){
        printf("%s = %d\n", eve_List[ind].eve_name, eve_id);
     }
     #endif
     event_proceed(EVE_EMRG_EMAIL_WAS_SENT, INIT_EVENT);
   }
}

//!****************************************************************************
static void proceed_recurring_event(int ind)
{
  int event_id;
  
  if (ind >= 0 && ind < EVE_MAX_NUMBER){
    
    event_id   = (eve_proceed[ind])->event_id;
    #if DEBUG_DISPATCHER
    printf("proceed_recurring_event(): ");
    #endif

    //! in common recurring and deferred events might have different procedures
    switch (event_id){

      case EVE_MAINTENANCE_REMINDER:
           #if DEBUG_DISPATCHER
           printf("%s = %d\n", eve_List[ind].eve_name, eve_id);
           #endif
           proceed_deferred_event(ind);
           break;

      case EVE_EMERGENCY_ISSUE:
           #if DEBUG_DISPATCHER
           printf("%s = %d\n", eve_List[ind].eve_name, eve_id);
           #endif
           proceed_emergency_issue();
           //+++++ why stp2pvs->service_mode == 1
           if (stp2pvs->service_mode == 1 || !is_an_emergency()){
              //! terminating recurring event (sending messages)
              (eve_proceed[ind])->event_run = RESOLVED_EVENT;
              printf("EVE_EMERGENCY_ISSUE: was terminated.\n");
           }
           break;
           
      case EVE_EMERGENCY_STOP:

           //! sys_emergency_stop() call proceed just once:
           //! at the first cycle, just before the start time was initialized
           if ((eve_proceed[ind])->eve_init  == 0 && 
               (eve_proceed[ind])->eve_start == 0 && is_production_mode()){
              #if DEBUG_DISPATCHER
              if (event_id == EVE_EMERGENCY_STOP){
                 printf("%s = %d\n", eve_List[ind].eve_name, eve_id);
              }
              #endif
              //sys_emergency_stop();
           }
           break;
    }
  }
}

//!****************************************************************************
/*
static void proceed_constant_event(int ind)
{
  //! initialization with unexisted values:
  static uint prev_day = 0, prev_hour = 25, prev_minute = 60;
  uint         cur_day = 0,  cur_hour = 25,  cur_minute = 60;

  static int prev_connected = 0;
  int connect_stat_changed  = 1;
  int connected             = !(stp2pvs->no_connection);
  int event_id;
  
  connect_stat_changed = (prev_connected == connected)? 0: 1;
  
  if (ind >= 0 && ind < EVE_MAX_NUMBER){
     event_id = (eve_proceed[ind])->event_id;
     switch (event_id){
        case EVE_MINUTELY_DB_RECORD:
           cur_day    = get_cur_day();
           cur_hour   = get_cur_hour();
           cur_minute = get_cur_minute();
           if (connected && prev_minute != cur_minute){
              if (connect_stat_changed){
                 if (!daily_record_exists()){
                    if (!hourly_record_exists()){
                       print_scada_db_record(DAILY_RECORD | HOURLY_RECORD | MINUTELY_RECORD);
                       prev_day    = cur_day;
                       prev_hour   = cur_hour;
                       prev_minute = cur_minute;
                    } else {
                       print_scada_db_record(DAILY_RECORD | MINUTELY_RECORD);
                       prev_day    = cur_day;
                       prev_minute = cur_minute;
                    }
                 } else if (!hourly_record_exists()){
                    print_scada_db_record(HOURLY_RECORD | MINUTELY_RECORD);
                    prev_hour   = cur_hour;
                    prev_minute = cur_minute;
                 } else {
                    print_scada_db_record(MINUTELY_RECORD);
                    prev_minute = cur_minute;
                 }
              } else {
                 if (prev_day != cur_day){
                    print_scada_db_record(DAILY_RECORD | HOURLY_RECORD | MINUTELY_RECORD);
                    prev_day    = cur_day;
                    prev_hour   = cur_hour;
                    prev_minute = cur_minute;
                 } else if (prev_hour != cur_hour){
                    print_scada_db_record(HOURLY_RECORD | MINUTELY_RECORD);
                    prev_hour   = cur_hour;
                    prev_minute = cur_minute;
                 } else {
                    print_scada_db_record(MINUTELY_RECORD);
                    prev_minute = cur_minute;
                 }
              }
           }
           break;
     }
  }
}
*/
//!****************************************************************************
static void proceed_simple_event(int ind)
{
  int event_id, event_type;
  char buf[_SIZE_QK] = "";
  
  if (ind >= 0 && ind < EVE_MAX_NUMBER){
    
     event_id   = (eve_proceed[ind])->event_id;
     event_type = (eve_proceed[ind])->event_type;
     strcpy (buf, (eve_proceed[ind])->event_msg);
  
     switch (event_id){
        case EVE_EXIT_SCADA_PROGRAM:
             //! this is a bomb! kills the application... 
             if (globs != NULL){
                 log_print(event_type, buf);
                 globs->stop_app = 1;
             }
             break;
        case EVE_CONFIG_PLC_TO_SCADA:
             if (check_plc_config_crit_errors() == 0){
             	//+++++++++ commented in pvapp.cpp
                //update_scada_config_from_plc();
                log_print(event_type, buf);
             } else {
                strcpy (buf, SCADA_PLC_CONFIG_ERRORS);
                log_print(LOG_MSG_CRIT, buf);
                event_proceed(EVE_EXIT_SCADA_PROGRAM, INIT_EVENT);
             }
             break;
        case EVE_ATTEMPT_CHANGE_FIXED:
             printf("EVE_ATTEMPT_CHANGE_FIXED simple event(): %s\n",(eve_request[ind])->eve_info);
             log_print(event_type, buf, (eve_request[ind])->eve_info);
             break;
        default:
              
              if ((eve_request[ind])->eve_info != NULL){
                 log_print(event_type, buf, (eve_request[ind])->eve_info);
              } else {
                 log_print(event_type, buf);
              }
     }
     #if DEBUG_DISPATCHER
     printf("dispatcher: proceed_simple_event(): id = %d: %s\n",event_id,buf);
     #endif
  }
}

#if 0
//****************************************************************************
static void proceed_plc_new_val_event(int ind, double *lastval,
                                      double newval, double cond)
{
  char buf[_SIZE_QK] = "";
  
  if (ind >= 0 && ind < EVE_MAX_NUMBER){
     if (lastval != NULL && abs(newval-(*lastval)) > cond){
        *lastval = newval;

        sprintf(buf, (eve_proceed[ind])->event_msg, newval);
        log_print((eve_proceed[ind])->event_type, buf);
     }
  }
}
#endif

//!****************************************************************************
static void proceed_plc_event(int ind)
{
  static int prev_connected = 0;

  int connect_stat_changed = 1;
  int config_stat_changed  = 0;
  int event_id, condition = 0;
  int conflict_configs = 0;
  int not_connected    = stp2pvs->no_connection;
  int service_on       = stp2pvs->service_mode;
  int connected        = !not_connected;
  int crucial_conflict = crucial_conflict_err();
  int config_force     = (bin_opts[CONFIG_FORCE])->cur_val;
  int config_error     = globs->conf_err;
  int cancel_recording = 0;
  int emrg_ind         = 0;
  int runstat          = 0;
  static int   prev_runstat = 0;
  static int   confirm_runstat_changed = 0;
  static int   unconfirm_runstat = 0;

  connect_stat_changed = (prev_connected == connected)? 0: 1;
  
  char buf[_SIZE_QK] = "";
  
  if (ind >= 0 && ind < EVE_MAX_NUMBER){
    
    event_id   = (eve_proceed[ind])->event_id;
    strcpy (buf, (eve_proceed[ind])->event_msg);
    
    switch (event_id){
    	//++++++++++++
      /*case EVE_DB_RECORD_ON_CHANGE:
           if (any_scada_db_digit_value_changed()){
              print_scada_db_record(RECORD_ON_CHANGE);
           }
           break;
      */
      case EVE_SCADA_CONFIG_STATUS:
           //proceed_record_plc_event(ind, !scada_configured);
           break;

      case EVE_SCADA_CONFIG_ERRORS:
           if (connected){
              //! if scada configuration failed but it was not crucial error,
              //! and force-flag for saving new configuration into plc memory
              //! was not raised up, then config should be taken from plc memory
              condition = (config_error && !config_force && !crucial_conflict);
              #if DEBUG_DISPATCHER
              printf("EVE_SCADA_CONFIG_ERRORS: condition = %d\n", condition );
              printf("dispatcher(): config_error = %d\n", config_error);
              #endif
              if (condition){
                 event_proceed(EVE_CONFIG_PLC_TO_SCADA, INIT_EVENT);
              }
           } else {
              cancel_recording = 1;
           }
           break;

      case EVE_CONFLICT_CONFIGS:
           //! very problematic part of PLC-SCADA intercommunication
           config_stat_changed = plc_scada_config_accordance();
           if (connect_stat_changed || config_stat_changed){
              if (connected){
                 conflict_configs = !config_stat_changed;
                 crucial_conflict = crucial_conflict_err();
                 
                 proceed_record_plc_event(ind, conflict_configs);
                 
                 if (conflict_configs && !crucial_conflict){
                    
                    //! config_force - the flag might be raised in configuration file,
                    //! if its true, it forces uploading configuration from SCADA to PLC
                    if (config_force){
                       #if DEBUG_DISPATCHER
                       printf("EVE_CONFLICT_CONFIGS: conflict_configs = %d\n", conflict_configs);
                       #endif
                       //! Forsing upload configuration from SCADA to PLC:
                       event_proceed(EVE_CONFIG_SCADA_TO_PLC, RUN_EVENT);
                    } else {
                       //! checking system configuration in PLC
                       if (check_plc_config_crit_errors() == 0){
                          //! if configuration on PLC doesn't have critical errors
                          //! start automatic upload configuration from PLC to SCADA:
                          event_proceed(EVE_CONFIG_PLC_TO_SCADA, INIT_EVENT);
                       } else {
                          //! config_error - static that defined in config_critical_err_status()
                          //! during SCADA configuration initialization on start or on UI changes 
                          if (!config_error){
                             //! start automatic upload configuration from SCADA to PLC:
                             // August 2016: after spontaneous configuration violations
                             // during downloading data from the touchscreen SCADA computer,
                             // was decided to exclude the possibility of automatic 
                             // configuration update from SCADA to PLC due unproper behavior
                             // event_proceed(EVE_CONFIG_SCADA_TO_PLC, RUN_EVENT); - obsolete
                             // only message about configuration conflict should appear:
                             strcpy (buf, MSG_CONFLICT_CONFIGS);
                             log_print(LOG_MSG_CRIT, buf);
                          } else {
                             //! Both configurations, - in PLC and in SCADA are wrong!!!
                             //! Turn off the Plant:
                             event_proceed(EVE_SERVICE_STP_STOP, RUN_EVENT);
                             //! Turn off SCADA program:
                             event_proceed(EVE_EXIT_SCADA_PROGRAM, INIT_EVENT);
                          }
                       }
                    }
                 } else if (crucial_conflict){
                    //! issue, when the SCADA & PLC software are incompatible
                    strcpy (buf, CRUCIAL_SCADA_CONFLICT);
                    log_print(LOG_MSG_CRIT, buf);
                    event_proceed(EVE_EXIT_SCADA_PROGRAM, INIT_EVENT);
                 } 
              }
              prev_connected = connected;
           }
           cancel_recording = 1;
           break;
           
      //! BioCompact errors
      case EVE_PLC_CONNECTION_ERR: condition = stp2pvs->no_connection;
                                   break;
      //+++++++++++delete useless error cases
      /*case EVE_SEN1_CONNECTION_ERR:condition = sens2pvs_1->no_connection;
                                   break;
      case EVE_SEN2_CONNECTION_ERR:condition = sens2pvs_2->no_connection;
                                   break;
      case EVE_SEN3_CONNECTION_ERR:condition = sens2pvs_3->no_connection;
                                   break;
      case EVE_ACTUATOR_ERR:       condition = stp2pvs->actuator_err;
                                   break;
      case EVE_ACT_NO_SIGNAL_ERR:  condition = stp2pvs->act_no_sign;
                                   break;
      case EVE_ACT_POSITION_ERR:   condition = stp2pvs->position_err;
                                   break;
      */
                                   //++++++ need to add magmOUT
      case EVE_MAGM_NO_SIGNAL_ERR: condition = stp2pvs->magmIN_sig_absent;
                                   break;
      /*case EVE_SOFT_START_1A_ERR:  condition = stp2pvs->softst1a_err;
                                   break;
      
      case EVE_PRESSURE_SW1A_ERR:  condition = stp2pvs->press_1a_err;
                                 break;
      case EVE_SOFT_START_1B_ERR:  condition = stp2pvs->softst1b_err;
                                   break;
      
      case EVE_PRESSURE_SW1B_ERR:  condition = stp2pvs->press_1b_err;
                                   break;
      case EVE_SOFT_START_2_ERR:   condition = stp2pvs->softst2_err;
                                   break;
      case EVE_PRESSURE_SW_2_ERR:  condition = stp2pvs->press_2_err;
                                   break;
      case EVE_T3_LVL_SENSOR_ERR:  condition = stp2pvs->lvl_sens_err;
                                   break;
      case EVE_LVL_SEN_NO_SIG_ERR: condition = stp2pvs->T3lvl_no_sig;
                                   break;
      case EVE_T3_SWITCHES_ERR:    condition = stp2pvs->switches_err;
                              break;
            */ 
      case EVE_PUMP_ONE_ERR:       condition = stp2pvs->pump1_err;
                                   break;
      case EVE_PUMP_TWO_ERR:       condition = stp2pvs->pump2_err;
                                   break;
         /* 
      case EVE_MAIN_LINE_ERR:      condition = stp2pvs->mainline_err;
                                   break;
      case EVE_LINE1_PHASE_ERR:    condition = stp2pvs->L1_phase_err;
                                   break;
      case EVE_LINE2_PHASE_ERR:    condition = stp2pvs->L2_phase_err;
                                   break;
      case EVE_LINE3_PHASE_ERR:    condition = stp2pvs->L3_phase_err;
                                   break;
      case EVE_UV_SEN_NO_SIG_ERR:  condition = stp2pvs->uv_no_signal;
                                   break;
      case EVE_LIFT_NO_SIGN_ERR:   condition = stp2pvs->lift_no_sign;
                               	   break;
      //+++++++++++++++++                        	   
      //need to add more error cases (tank!!!!)
      */
      //! BioCompact emergencies
      /*case EVE_ACTUATOR_EMERGENCY : emrg_ind  = ACTUATOR_EMERG;
                                    condition = stp2pvs->actuator_emr;
                                    break;
      case EVE_MAGMETER_EMERGENCY : emrg_ind = MAGMETER_EMERG;
                                    condition = stp2pvs->magmeter_emr;
                                    break;
      case EVE_CHAMBER3_EMERGENCY : emrg_ind = CHAMBER3_EMERG;
                                    condition = stp2pvs->chamber3_emr;
                                    break;
      case EVE_PUMPS_EMERGENCY    : emrg_ind = PUMPS_EMERG;
                                    condition = stp2pvs->pumps_emr;
                                    break;
      case EVE_LIFT_ST_LVL_EMRGENCY: emrg_ind = LIFT_ST_EMRG;
                                    condition = stp2pvs->lift_st_emr;
                                    break;
      case EVE_POWER_FAILURE_EMERG: emrg_ind = EL_POWER_EMERG;
                                    condition = stp2pvs->el_power_emr;
                                    break;
      case EVE_SYSTOPED_EMERGENCY : emrg_ind = SYSTOPED_EMERG;
                                    condition = stp2pvs->systoped_emr;
                                    break;
      */
      //! BioCompact routine events
      //! NOTE: very nasty patch !!!
      //! to eliminate the "phantom changes" of run_status value, these 
      //! changes will be accepted only if it happened three times in a row
      case EVE_PLANT_WAS_STARTED  : 
      case EVE_PLANT_WAS_STOPPED  : runstat = stp2pvs->sys_runstat;
                                    if (runstat != prev_runstat){
                                       confirm_runstat_changed += 1;
                                    } else {
                                       if (confirm_runstat_changed > 0){
                                          unconfirm_runstat += 1;
                                       }
                                    }
      //! 'confirm_runstat_changed' is bumped twice during each cycle, -
      //! once for EVE_PLANT_WAS_STARTED & once for EVE_PLANT_WAS_STOPPED;
      //! therefore we check it for > 4
                                    if (confirm_runstat_changed > 4){
                                       prev_runstat = runstat;
                                       confirm_runstat_changed = 0;
                                       unconfirm_runstat = 0;
                                    } else {
                                       runstat = prev_runstat;
                                       if (unconfirm_runstat){
                                          confirm_runstat_changed = 0;
                                          unconfirm_runstat = 0;
                                       }
                                    }
                                   
                                    if (event_id == EVE_PLANT_WAS_STARTED){
                                       condition = runstat;
                                    } 
                                    if (event_id == EVE_PLANT_WAS_STOPPED){
                                       condition = !runstat;
                                    }
                                    break;
      /*case EVE_T3_PUMPS_DUAL_FORCE: condition = stp2pvs->t3_dual_force;
                                    break;
      case EVE_LIFT_ST_LVL_HIGH   : condition = stp2pvs->lift_lvl_high;
                                    break;
      */
    }

    if (!cancel_recording){
       proceed_record_plc_event(ind, condition);
    }
    
    if (emrg_ind != 0){
       condition = condition && !service_on;
       emrgTable[emrg_ind].prev_stat = emrgTable[emrg_ind].curr_stat;
       emrgTable[emrg_ind].curr_stat = condition;
       if (emrgTable[emrg_ind].curr_stat != emrgTable[emrg_ind].prev_stat){
          event_proceed(EVE_EMERGENCY_ISSUE, INIT_EVENT);
       }
    }
  }
}

//!****************************************************************************
void init_eve_request()
{
  for (int i = 0; i < EVE_MAX_NUMBER; i++){

     (eve_request[i])->event_id = init_tbl_eve_request[i].event_id;
     (eve_request[i])->event_go = init_tbl_eve_request[i].event_go;
     (eve_request[i])->event_val = init_tbl_eve_request[i].event_val;
     strcpy((eve_request[i])->eve_info, EMPTY_STRING);
  }
}

//!****************************************************************************
void init_eve_proceed()
{
  for (int i = 0; i < EVE_MAX_NUMBER; i++){
    
     (eve_proceed[i])->event_id   = init_tbl_proceed[i].event_id;
     (eve_proceed[i])->event_type = init_tbl_proceed[i].event_type;
     if (init_tbl_eve_request[i].event_go == PLC_EVENT ||
         init_tbl_eve_request[i].event_go == PLC_EVENT_B2B){
        (eve_proceed[i])->event_run = PLC_EVENT_OFF;
     } else {
        (eve_proceed[i])->event_run = init_tbl_eve_request[i].event_go;
     }
     (eve_proceed[i])->timer      = init_tbl_proceed[i].timer;
     (eve_proceed[i])->eve_init   = init_tbl_proceed[i].eve_init;
     (eve_proceed[i])->eve_start  = init_tbl_proceed[i].eve_start;
     (eve_proceed[i])->eve_cycle  = init_tbl_proceed[i].eve_cycle;
     (eve_proceed[i])->event_msg  = init_tbl_proceed[i].event_msg;
     (eve_proceed[i])->back_msg   = init_tbl_proceed[i].back_msg;
  }
}

//!****************************************************************************
void scada_dispatcher()
{
  static uint plc_update = 0;
  int i, event_status, event_id;

  time_t curtime;
  long int l_cur_time = 0;
  long int l_evetimer = 0;
  long int l_ini_time = 0;
  long int l_evecycle = 0;
  long int l_exe_time = 0;
  
  int skip_plc_event   = 1;
  int waiting_resolved = 0;

  umask (0);
  
  //! DISPATCHER INFINITE MAIN LOOP
  //usleep(200000); //! delay for initialization of plc-server
  printf("%s\n", "scada_dispatcher() is called");
  while (1){
     i = 0;

     //! UI REQUESTS PROCESSING CYCLE: START
     do{

       //! --------------------- IMPORTANT !----------------------------------
       //! INTERPOCESS ANALISING: REQUESTS from SCADA UI always come into
       //! 'eve_request' table, which can be changed ONLY by pvs-server
       //! -------------------------------------------------------------------
       //! 'eve_proceed' is the table for processing by DISPATCHER program
       //! EVENTS REQUESTs API functions are described at the top of this file
       //! They should be used for interprocess communication between 
       //! events-dispatcher and pvs-server
       //! -------------------------------------------------------------------
       //! SIMPLE EVENT (do somthing and switch to NO_EVENT status)
       if ((eve_request[i])->event_go == INIT_EVENT){
          if ((eve_proceed[i])->event_run == NO_EVENT){
             (eve_proceed[i])->event_run = INIT_EVENT;
          } else if ((eve_proceed[i])->event_run == INIT_EVENT){
             (eve_proceed[i])->event_run = QUIT_EVENT;
          }
       //! NO EVENT case
       } else if ((eve_request[i])->event_go == NO_EVENT) {
          //! reseting event status in the 'eve_proceed' table in case
          //! when event request status has been resolved by pvs-server
          if ((eve_proceed[i])->event_run == INIT_EVENT ||
              (eve_proceed[i])->event_run == QUIT_EVENT){
             (eve_proceed[i])->event_run = NO_EVENT;
          }
       //! REQUEST-ANSWER EVENT: activating (start  call)
       } else if ((eve_request[i])->event_go == RUN_EVENT){
          #if DEBUG_DISPATCHER
          printf("dispatcher: RUN_EVENT REQUEST IS ON >>>>>>>>>>>>>>>>>\n");
          #endif
          if ((eve_proceed[i])->event_run != WAITING_EVENT &&
              (eve_proceed[i])->event_run != RESOLVED_EVENT &&
              (eve_proceed[i])->event_run != TIME_OUT_EVENT){
             #if DEBUG_DISPATCHER
             printf("dispatcher: RUN_EVENT REQUEST IS PROCEEDING\n");
             #endif
             (eve_proceed[i])->event_run = RUN_EVENT;
             #if DEBUG_DISPATCHER
             printf("dispatcher: PROCEEDING REQUEST-ANSWER EVENT = %d (%s)\n",
                                                  (eve_proceed[i])->event_run,
                                EventStatusList[(eve_proceed[i])->event_run]);
             #endif
          } else {
             #if DEBUG_DISPATCHER
             printf("dispatcher: RUN_EVENT REQUEST WAS ALREADY PROCEEDED\n");
             #endif
          }
      }
       //! new implementation of events status should be analized here

       #if DEBUG_DISPATCHER
       if ((eve_request[i])->event_id == EVE_SWITCH_SYSTEM_MODE &&
           (eve_request[i])->event_go != NO_EVENT){
          printf("EVE_SWITCH_SYSTEM_MODE: ");
          printf("REQUESTED EVENT = %d (%s), REQUESTED MODE = %d (%s)\n",
                                             (eve_request[i])->event_go,
                             EventStatusList[(eve_request[i])->event_go],
                                             (eve_request[i])->event_val,
                             PLC_ModsList[(eve_request[i])->event_val+1]);
       }
       #endif

     } while ((eve_request[++i])->event_id != EVE_MAX_NUMBER);
     //! END of UI REQUESTS PROCESSING CYCLE

     skip_plc_event = (stp2pvs->update == plc_update);
     i = 0;
     //! INTERNAL EVENT-DATA PROCESSING CYCLE: START
     do{

       #if DEBUG_DISPATCHER
       if ((eve_proceed[i])->event_id == EVE_SWITCH_SYSTEM_MODE){
          if ((eve_request[i])->event_go != NO_EVENT){
             printf("EVE_SWITCH_SYSTEM_MODE: PROCEEDING EVENT = %d (%s)\n",
                                               (eve_proceed[i])->event_run,
                               EventStatusList[(eve_proceed[i])->event_run]);
         }
       }
       #endif

       curtime = time (NULL);
       l_cur_time  = (long int)(curtime);
       if ((eve_request[i])->event_go != PLC_EVENT &&
           (eve_request[i])->event_go != PLC_EVENT_B2B &&
           (eve_request[i])->event_go != CONSTANT_EVENT){
          event_status = (eve_proceed[i])->event_run;
       } else {
          event_status = (eve_request[i])->event_go;
       }
       
       event_id = (eve_proceed[i])->event_id;
       
       switch (event_status){
              
         case RUN_EVENT:

              if ((eve_request[i])->event_val != UNDEF_INT){
                 (eve_proceed[i])->event_val = (eve_request[i])->event_val;
              } else {
                 (eve_proceed[i])->event_val = init_tbl_proceed[i].event_val;
              }
              //#if DEBUG_DISPATCHER
              printf ("RUN_EVENT: id = %d, plc_request_on = %d, event_val = %d\n",
                           event_id, plc_request_on, (eve_proceed[i])->event_val);
              //#endif
              proceed_prolonged_event(event_id, event_status);
              break;

         case WAITING_EVENT:

              #if DEBUG_DISPATCHER
              printf ("WAITING_EVENT: ....................................\n");
              #endif

              waiting_resolved = proceed_waiting_event(i);
              if (waiting_resolved == 1){
                 (eve_proceed[i])->event_run = RESOLVED_EVENT;
                 set_plc_request_off();

                 #if DEBUG_DISPATCHER
                 printf ("------------------------------------------------\n");
                 printf ("WAITING_EVENT: STATUS = %d (%s); event_val = %d\n",
                                              (eve_proceed[i])->event_run, 
                              EventStatusList[(eve_proceed[i])->event_run],
                                              (eve_proceed[i])->event_val);
                 printf ("------------------------------------------------\n");
                 #endif

              } else if (waiting_resolved == 0){
                 //! nothing to do, - waiting in progress...
                 #if DEBUG_DISPATCHER
                 printf ("WAITING_EVENT: waiting in progress..............\n");
                 #endif

              } else if (waiting_resolved == UNDEF_INT){
                 #if DEBUG_DISPATCHER
                 printf ("WAITING_EVENT: quit waiting by time out.........\n");
                 #endif
                 set_plc_request_off();
                 (eve_proceed[i])->event_run = TIME_OUT_EVENT;
              
              } else if (waiting_resolved == -2){
                 #if DEBUG_DISPATCHER
                 printf ("WAITING_EVENT: waiting error....................\n");
                 #endif
                 set_plc_request_off();
                 printf (WAITING_EVENT_ERROR_MSG, (eve_proceed[i])->event_id);
              }
              break;

         case PROLONGED_EVENT:

              if (event_id == EVE_UPDATE_SYSTEM_DATA){
                 (eve_proceed[i])->event_run = NO_EVENT;
              }
              #if DEBUG_DISPATCHER
              printf("PROLONGED_EVENT: id = %d\n", event_id, (eve_proceed[i])->event_val);
              #endif
              break;

         case RESOLVED_EVENT:

              #if DEBUG_DISPATCHER
              printf("RESOLVED_EVENT: id = %d\n", event_id);
              #endif
              if ((eve_request[i])->event_go == NO_EVENT){
                 //! --------------------------------------------
                 //! to avoid the transient oscillation effects,
                 //! switching processing mode can be done just 
                 //! after requesting mode was reset by pvs-server
                 //! --------------------------------------------
                 //(eve_proceed[i])->event_run = NO_EVENT;
                 //(eve_proceed[i])->event_val = UNDEF_INT;
                 (eve_proceed[i])->event_run = QUIT_EVENT;
              }
              break;

         case TIME_OUT_EVENT:
         case QUIT_EVENT:

              #if DEBUG_DISPATCHER
              printf("QUIT_EVENT: id = %d\n", event_id);
              #endif

              if ((eve_request[i])->event_go == NO_EVENT){
                 //! time-settings reset for defferred & recurring events
                 if ((eve_proceed[i])->timer != 0 || 
                     (eve_proceed[i])->eve_cycle != 0){
                    (eve_proceed[i])->eve_init  = 0;
                    (eve_proceed[i])->eve_start = 0;
                 }
                 //! --------------------------------------------
                 //! to avoid the transient oscillation effects,
                 //! switching processing mode can be done just 
                 //! after requesting mode was reset by pvs-server
                 //! --------------------------------------------
                 (eve_proceed[i])->event_run = NO_EVENT;
                 (eve_proceed[i])->event_val = UNDEF_INT;
              }
              break;

         case NO_EVENT:
              break;

         case INIT_EVENT:
              
              //! initialization of event value to the value from request array
              //! has to be proceeded just and only if the event was initiated
              //! from outside process (not from dispatcher)
              if ((eve_request[i])->event_go != NO_EVENT){
                 if ((eve_request[i])->event_val != UNDEF_INT){
                    (eve_proceed[i])->event_val = (eve_request[i])->event_val;
                 } else {
                    (eve_proceed[i])->event_val = init_tbl_proceed[i].event_val;
                 }
              }

              if ((eve_proceed[i])->timer){  //! if timer (delay start) defined
                 //! initialize the time-point of reference and switch status
                 (eve_proceed[i])->event_run = DEFERRED_EVENT;
                 //! no proceeding event immidiately
                 (eve_proceed[i])->eve_init  = l_cur_time;
                 (eve_proceed[i])->eve_start = 0;
              } else if ((eve_proceed[i])->eve_cycle){ //! if iteration defined
                 //! recurring event without delay start
                 (eve_proceed[i])->event_run = RECURRING_EVENT;
                 (eve_proceed[i])->eve_init  = 0;
                 (eve_proceed[i])->eve_start = 0;
                 proceed_recurring_event(i);
                 (eve_proceed[i])->eve_init  = l_cur_time;
                 (eve_proceed[i])->eve_start = l_cur_time;
              } else {
                 //! this is a simple case: proceed the event immediately
                 proceed_simple_event(i);
                 printf("INIT_EVENT: id = %d\n", event_id);
                 (eve_proceed[i])->event_run = QUIT_EVENT;
              }
              break;

         case DEFERRED_EVENT:
              l_evetimer = (eve_proceed[i])->timer;
              l_ini_time = (eve_proceed[++i])->eve_init;

              if (l_cur_time - l_ini_time >= l_evetimer){
                 //! switch to cycle status; proceed the event and setup start time
                 (eve_proceed[i])->event_run = RECURRING_EVENT;
                 proceed_deferred_event(i);
                 (eve_proceed[i])->eve_start = l_cur_time;
              }
              break;

         case RECURRING_EVENT:
              l_evecycle = (eve_proceed[i])->eve_cycle;
              l_exe_time = (eve_proceed[i])->eve_start;

              if (l_cur_time - l_exe_time >= l_evecycle){
                 //! proceed the event and reset the start time
                 proceed_recurring_event(i);
                 (eve_proceed[i])->eve_start = l_cur_time;
              }
              break;

         case PLC_EVENT:
         case PLC_EVENT_B2B:
              //! proceed the event in case of new OSAUT msg received
              if (!skip_plc_event){
                 proceed_plc_event(i);
              }
              break;
              //++++++++
        /*      
         case CONSTANT_EVENT:
              proceed_constant_event(i);
              break;
              */
       }

     } while ((eve_request[++i])->event_id != EVE_MAX_NUMBER);
     //! END of INTERNAL EVENT-DATA PROCESSING CYCLE
     if (globs->stop_app == 1)
        break;        

     if (!skip_plc_event){
        plc_update = stp2pvs->update;
     }
     usleep(5000);
  }
}
