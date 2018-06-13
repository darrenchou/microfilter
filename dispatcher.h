/*****************************************************************************
 * dispatcher.h
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
 * (c) Osorno Enterprises Inc., 2014: http://www.osorno.ca/
 * 
 ****************************************************************************/

#ifndef _DISPATCHER_H_
#define _DISPATCHER_H_

#include "logger.h"
#include "pvapp.h"

#define DEBUG_DISPATCHER    0

#define NUM_PLC_MODES       14
#define NUM_FB_PULSES_CHECK 100

#define WAITING_EVENT_ERROR_MSG "WAITING_EVENT event id = %d returned error from proceed_waiting_event().\n"

//! EVENT STATUS ENUMERATION
enum {
  UNDEF_EVENT =-2, //! undefined event
  EMERG_EVENT =-1, //! emergency event
  NO_EVENT = 0,    //! no-event 
  
  //! SIMPLE EVENT (do somthing once and switch to NO_EVENT status)
  INIT_EVENT,      //! 01 // activating status for initiating simple event  (start call)
  QUIT_EVENT,      //! 02 // resolving  status of finished simple event     (end)
  
  //! REQUEST-ANSWER EVENT (send request > wait for responce > get the answer)
  RUN_EVENT,       //! 03 // activating status for REQUEST-ANSWER event     (start  call)
  STOP_EVENT,      //! 04 // terminating status for REQUEST-ANSWER event    (stop   call)
  SYS_ERR_INIT,    //! 05 // system error initializing REQUEST-ANSWER event (start sys error)
  SYS_ERR_PROLONG, //! 06 // system error hold on REQUEST-ANSWER event      (hold sys error)
  SYS_ERR_RELEASE, //! 07 // system error releasing REQUEST-ANSWER event    (release sys error)
  WAITING_EVENT,   //! 08 // waiting status of the REQUEST-ANSWER event     (in communicating)
  PROLONGED_EVENT, //! 09 // continuous status of the REQUEST-ANSWER event  (active production)
  RESOLVED_EVENT,  //! 10 // resolving status of the REQUEST-ANSWER event   (end)
  TIME_OUT_EVENT,  //! 11 // status for REQUEST-ANSWER event was timed out  (no responce)

  //! PLC EVENTS
  PLC_EVENT,       //! 12 // simple event has only one state responce
  PLC_EVENT_B2B,   //! 13 // back-to-back event, - has responces for both states
  PLC_EVENT_ON,    //! 14 // flag to activate event
  PLC_EVENT_OFF,   //! 15 // flag to terminate event
  
  //! OTHER EVENTS
  DEFERRED_EVENT,  //! 16 // already active, but deferred event (delay start)
  RECURRING_EVENT, //! 17 // iterative active event (repeating)
  CONSTANT_EVENT,  //! 18 // constantly repeating event that cannot be stopped
  
  //! ADD NEW EVENTS HERE
};  


//! EVENT IDENTIFICATORS ENUMERATOR
enum {
 EVE_NULL = 0,
 EVE_USER_LOGIN_SUCCEED  ,
 EVE_OPER_LOGIN_SUCCEED  ,
 EVE_SERV_LOGIN_SUCCEED  ,
 EVE_CLIENT_LOGGED_OUT   ,
 EVE_CLIENT_QUIT_SESSION ,
 EVE_SESSION_TIMED_OUT   ,
 EVE_CLIENT_LOGIN_FAILED ,
 EVE_USER_LOGIN_FAILED   ,
 EVE_REMOTE_OPER_LOGIN   ,
 EVE_NO_SERV_SYSTEM_BUSY ,
 EVE_USER_LOGIN_IS_BUSY  ,
 EVE_SERV_LOGIN_IS_BUSY  ,
 EVE_CLIENT_IP_CONNECTED ,
 EVE_CLIENT_DISCONNECTED ,
 EVE_PVS_WAS_TERMINATED  ,
 EVE_PLC_CONNECTION_ERR  ,
 EVE_SEN1_CONNECTION_ERR ,
 EVE_SEN2_CONNECTION_ERR ,
 EVE_SEN3_CONNECTION_ERR ,
 EVE_ACTUATOR_ERR        ,
 EVE_ACT_NO_SIGNAL_ERR   ,
 EVE_ACT_POSITION_ERR    ,
 EVE_MAGM_NO_SIGNAL_ERR  ,
 EVE_SOFT_START_1A_ERR   ,
 EVE_PRESSURE_SW1A_ERR   ,
 EVE_SOFT_START_1B_ERR   ,
 EVE_PRESSURE_SW1B_ERR   ,
 EVE_SOFT_START_2_ERR    ,
 EVE_PRESSURE_SW_2_ERR   ,
 EVE_T3_LVL_SENSOR_ERR   ,
 EVE_LVL_SEN_NO_SIG_ERR  ,
 EVE_T3_SWITCHES_ERR     ,
 EVE_PUMP_ONE_ERR        ,
 EVE_PUMP_TWO_ERR        ,
 EVE_MAIN_LINE_ERR       ,
 EVE_LINE1_PHASE_ERR     ,
 EVE_LINE2_PHASE_ERR     ,
 EVE_LINE3_PHASE_ERR     ,
 EVE_UV_SEN_NO_SIG_ERR   ,
 EVE_LIFT_NO_SIGN_ERR    ,
 EVE_ACTUATOR_EMERGENCY  ,
 EVE_MAGMETER_EMERGENCY  ,
 EVE_CHAMBER3_EMERGENCY  ,
 EVE_PUMPS_EMERGENCY     ,
 EVE_LIFT_ST_LVL_EMRGENCY,
 EVE_POWER_FAILURE_EMERG ,
 EVE_SYSTOPED_EMERGENCY  ,
 EVE_EMERGENCY_ISSUE     ,
 EVE_SCADA_CONFIG_STATUS , //! ???
 EVE_SCADA_CONFIG_ERRORS ,
 EVE_CRITICAL_CONFIG     ,
 EVE_NEW_CONFIG_ERROR    ,
 EVE_CONFLICT_CONFIGS    ,
 EVE_EXIT_SCADA_PROGRAM  ,
 EVE_CONFIG_PLC_TO_SCADA ,
 EVE_CONFIG_SCADA_TO_PLC ,
 EVE_CONFIG_UIMAN_TO_PLC ,
 EVE_NEW_CONFIG_SAVED    ,
 EVE_ATTEMPT_CHANGE_FIXED,
 EVE_REQUEST_TIMEOUT     ,
 EVE_PLANT_WAS_STARTED   ,
 EVE_PLANT_WAS_STOPPED   ,
 EVE_T3_PUMPS_DUAL_FORCE ,
 EVE_LIFT_ST_LVL_HIGH    ,
 EVE_SERVICE_START       , //! MANUAL OPERATING EVENTS
 EVE_SERVICE_FINISH      ,
 EVE_SERVICE_PC_REBOOT   ,
 EVE_SERVICE_STP_START   ,
 EVE_SERVICE_STP_STOP    ,
 EVE_SERVICE_ERR_ACK     ,
 EVE_SERVICE_ALL_TO_MAN  ,
 EVE_SERVICE_ALL_TO_AUTO ,
 EVE_INTO_MAN_BL1A       , //! SWITCHING MODE BETWEEN MANUAL & AUTO
 EVE_INTO_MAN_BL1B       ,
 EVE_INTO_MAN_BL2        ,
 EVE_INTO_MAN_PUMPS      ,
 EVE_INTO_MAN_UV         ,
 EVE_INTO_MAN_SOL        ,
 EVE_INTO_MAN_ACT        ,
 EVE_INTO_MAN_LIFT       ,
 EVE_INTO_AUTO_BL1A      ,
 EVE_INTO_AUTO_BL1B      ,
 EVE_INTO_AUTO_BL2       ,
 EVE_INTO_AUTO_PUMPS     ,
 EVE_INTO_AUTO_UV        ,
 EVE_INTO_AUTO_SOL       ,
 EVE_INTO_AUTO_ACT       ,
 EVE_INTO_AUTO_LIFT      ,
 EVE_INTO_ENBL_BL1A      , //! SWITCHING BETWEEN ENABLE & DISABLE
 EVE_INTO_ENBL_BL1B      ,
 EVE_INTO_ENBL_BL2       ,
 EVE_INTO_ENBL_PUMP1     ,
 EVE_INTO_ENBL_PUMP2     ,
 EVE_INTO_ENBL_UV        ,
 EVE_INTO_ENBL_SOL       ,
 EVE_INTO_ENBL_LIFT      ,
 EVE_INTO_DIS_BL1A       ,
 EVE_INTO_DIS_BL1B       ,
 EVE_INTO_DIS_BL2        ,
 EVE_INTO_DIS_PUMP1      ,
 EVE_INTO_DIS_PUMP2      ,
 EVE_INTO_DIS_UV         ,
 EVE_INTO_DIS_SOL        ,
 EVE_INTO_DIS_LIFT       ,
 EVE_SWITCH_ON_BL1A      , //! SWITCHING BETWEEN START & STOP
 EVE_SWITCH_ON_BL1B      ,
 EVE_SWITCH_ON_BL2       ,
 EVE_SWITCH_ON_PUMP1     ,
 EVE_SWITCH_ON_PUMP2     ,
 EVE_SWITCH_ON_UV        ,
 EVE_SWITCH_ON_SOL       ,
 EVE_SWITCH_ON_LIFT      ,
 EVE_SWITCH_OFF_BL1A     ,
 EVE_SWITCH_OFF_BL1B     ,
 EVE_SWITCH_OFF_BL2      ,
 EVE_SWITCH_OFF_PUMP1    ,
 EVE_SWITCH_OFF_PUMP2    ,
 EVE_SWITCH_OFF_UV       ,
 EVE_SWITCH_OFF_SOL      ,
 EVE_SWITCH_OFF_LIFT     ,
 EVE_ACTUATOR_STEP_UP    ,
 EVE_ACTUATOR_STEP_DOWN  ,
 EVE_UPDATE_SYSTEM_DATA  ,
 EVE_AUTHENTICATION_OK   ,
 EVE_MAINTENANCE_REMINDER, 
 EVE_EMRG_EMAIL_WAS_SENT , 
 EVE_EMERGENCY_STOP      , 
 EVE_ACTIVATED_SENS_PAGE ,
 EVE_DB_RECORD_ON_CHANGE ,
 EVE_MINUTELY_DB_RECORD  ,
 //! add new events here
 EVE_SWITCH_ON_SOL1      , //! SWITCHING BETWEEN START & STOP
 EVE_SWITCH_ON_SOL2      ,
 EVE_SWITCH_ON_SOL3      ,
 EVE_SWITCH_ON_SOL4      ,
 EVE_SWITCH_ON_SOL5      ,
 EVE_SWITCH_ON_SOL6      ,
 EVE_SWITCH_ON_SOL7      ,
 EVE_SWITCH_ON_SOL8      ,
 EVE_SWITCH_ON_SOL9      ,
 EVE_SWITCH_OFF_SOL1     ,
 EVE_SWITCH_OFF_SOL2     ,
 EVE_SWITCH_OFF_SOL3     ,
 EVE_SWITCH_OFF_SOL4     ,
 EVE_SWITCH_OFF_SOL5     ,
 EVE_SWITCH_OFF_SOL6     ,
 EVE_SWITCH_OFF_SOL7     ,
 EVE_SWITCH_OFF_SOL8     ,
 EVE_SWITCH_OFF_SOL9     ,
 EVE_MAX_NUMBER  
};

typedef struct eve_id_name {
   int eve_id;
   char eve_name[64];
}eve_id_name_t;

//! for debuging needs:
const static eve_id_name_t eve_List[EVE_MAX_NUMBER] = {
   { EVE_NULL                , "EVE_NULL"                },
   { EVE_USER_LOGIN_SUCCEED  , "EVE_USER_LOGIN_SUCCEED"  },
   { EVE_OPER_LOGIN_SUCCEED  , "EVE_OPER_LOGIN_SUCCEED"  },
   { EVE_SERV_LOGIN_SUCCEED  , "EVE_SERV_LOGIN_SUCCEED"  },
   { EVE_CLIENT_LOGGED_OUT   , "EVE_CLIENT_LOGED_OUT"    },
   { EVE_CLIENT_QUIT_SESSION , "EVE_CLIENT_QUIT_SESSION" },
   { EVE_SESSION_TIMED_OUT   , "EVE_SESSION_TIMED_OUT"   },
   { EVE_CLIENT_LOGIN_FAILED , "EVE_CLIENT_LOGIN_FAILED" },
   { EVE_USER_LOGIN_FAILED   , "EVE_USER_LOGIN_FAILED"   },
   { EVE_REMOTE_OPER_LOGIN   , "EVE_REMOTE_OPER_LOGIN"   },
   { EVE_NO_SERV_SYSTEM_BUSY , "EVE_NO_SERV_SYSTEM_BUSY" },
   { EVE_USER_LOGIN_IS_BUSY  , "EVE_USER_LOGIN_IS_BUSY"  },
   { EVE_SERV_LOGIN_IS_BUSY  , "EVE_SERV_LOGIN_IS_BUSY"  },
   { EVE_CLIENT_IP_CONNECTED , "EVE_CLIENT_IP_CONNECTED" },
   { EVE_CLIENT_DISCONNECTED , "EVE_CLIENT_DISCONNECTED" },
   { EVE_PVS_WAS_TERMINATED  , "EVE_PVS_WAS_TERMINATED"  },
   { EVE_PLC_CONNECTION_ERR  , "EVE_PLC_CONNECTION_ERR"  },
   { EVE_SEN1_CONNECTION_ERR , "EVE_SEN1_CONNECTION_ERR" },
   { EVE_SEN2_CONNECTION_ERR , "EVE_SEN2_CONNECTION_ERR" },
   { EVE_SEN3_CONNECTION_ERR , "EVE_SEN3_CONNECTION_ERR" },
   { EVE_ACTUATOR_ERR        , "EVE_ACTUATOR_ERR"        },
   { EVE_ACT_NO_SIGNAL_ERR   , "EVE_ACT_NO_SIGNAL_ERR"   },
   { EVE_ACT_POSITION_ERR    , "EVE_ACT_POSITION_ERR"    },
   { EVE_MAGM_NO_SIGNAL_ERR  , "EVE_MAGM_NO_SIGNAL_ERR"  },
   { EVE_SOFT_START_1A_ERR   , "EVE_SOFT_START_1A_ERR"   },
   { EVE_PRESSURE_SW1A_ERR   , "EVE_PRESSURE_SW1A_ERR"   },
   { EVE_SOFT_START_1B_ERR   , "EVE_SOFT_START_1B_ERR"   },
   { EVE_PRESSURE_SW1B_ERR   , "EVE_PRESSURE_SW1B_ERR"   },
   { EVE_SOFT_START_2_ERR    , "EVE_SOFT_START_2_ERR"    },
   { EVE_PRESSURE_SW_2_ERR   , "EVE_PRESSURE_SW_2_ERR"   },
   { EVE_T3_LVL_SENSOR_ERR   , "EVE_T3_LVL_SENSOR_ERR"   },
   { EVE_LVL_SEN_NO_SIG_ERR  , "EVE_LVL_SEN_NO_SIG_ERR"  },
   { EVE_T3_SWITCHES_ERR     , "EVE_T3_SWITCHES_ERR"     },
   { EVE_PUMP_ONE_ERR        , "EVE_PUMP_ONE_ERR"        },
   { EVE_PUMP_TWO_ERR        , "EVE_PUMP_TWO_ERR"        },
   { EVE_MAIN_LINE_ERR       , "EVE_MAIN_LINE_ERR"       },
   { EVE_LINE1_PHASE_ERR     , "EVE_LINE1_PHASE_ERR"     },
   { EVE_LINE2_PHASE_ERR     , "EVE_LINE2_PHASE_ERR"     },
   { EVE_LINE3_PHASE_ERR     , "EVE_LINE3_PHASE_ERR"     },
   { EVE_UV_SEN_NO_SIG_ERR   , "EVE_UV_SEN_NO_SIG_ERR"   },
   { EVE_LIFT_NO_SIGN_ERR    , "EVE_LIFT_NO_SIGN_ERR"    },
   { EVE_ACTUATOR_EMERGENCY  , "EVE_ACTUATOR_EMERGENCY"  },
   { EVE_MAGMETER_EMERGENCY  , "EVE_MAGMETER_EMERGENCY"  },
   { EVE_CHAMBER3_EMERGENCY  , "EVE_CHAMBER3_EMERGENCY"  },
   { EVE_PUMPS_EMERGENCY     , "EVE_PUMPS_EMERGENCY"     },
   { EVE_LIFT_ST_LVL_EMRGENCY, "EVE_LIFT_ST_LVL_EMRGENCY"},
   { EVE_POWER_FAILURE_EMERG , "EVE_EL_POWER_EMERGENCY"  },
   { EVE_SYSTOPED_EMERGENCY  , "EVE_SYSTOPED_EMERGENCY"  },
   { EVE_EMERGENCY_ISSUE     , "EVE_EMERGENCY_ISSUE"     },
   { EVE_SCADA_CONFIG_STATUS , "EVE_SCADA_CONFIG_STATUS" },
   { EVE_SCADA_CONFIG_ERRORS , "EVE_SCADA_CONFIG_ERRORS" },
   { EVE_CRITICAL_CONFIG     , "EVE_CRITICAL_CONFIG"     },
   { EVE_NEW_CONFIG_ERROR    , "EVE_NEW_CONFIG_ERROR"    },
   { EVE_CONFLICT_CONFIGS    , "EVE_CONFLICT_CONFIGS"    },
   { EVE_EXIT_SCADA_PROGRAM  , "EVE_EXIT_SCADA_PROGRAM"  },
   { EVE_CONFIG_PLC_TO_SCADA , "EVE_CONFIG_PLC_TO_SCADA" },
   { EVE_CONFIG_SCADA_TO_PLC , "EVE_CONFIG_SCADA_TO_PLC" },
   { EVE_CONFIG_UIMAN_TO_PLC , "EVE_CONFIG_UIMAN_TO_PLC" },
   { EVE_NEW_CONFIG_SAVED    , "EVE_NEW_CONFIG_SAVED"    },
   { EVE_ATTEMPT_CHANGE_FIXED, "EVE_ATTEMPT_CHANGE_FIXED"},
   { EVE_REQUEST_TIMEOUT     , "EVE_REQUEST_TIMEOUT"     },
   { EVE_PLANT_WAS_STARTED   , "EVE_PLANT_WAS_STARTED"   },
   { EVE_PLANT_WAS_STOPPED   , "EVE_PLANT_WAS_STOPPED"   },
   { EVE_T3_PUMPS_DUAL_FORCE , "EVE_T3_PUMPS_DUAL_FORCE" },
   { EVE_LIFT_ST_LVL_HIGH    , "EVE_LIFT_ST_LVL_HIGH"    },
   { EVE_SERVICE_START       , "EVE_SERVICE_START"       },
   { EVE_SERVICE_FINISH      , "EVE_SERVICE_FINISH"      },
   { EVE_SERVICE_PC_REBOOT   , "EVE_SERVICE_PC_REBOOT"   },
   { EVE_SERVICE_STP_START   , "EVE_SERVICE_STP_START"   },
   { EVE_SERVICE_STP_STOP    , "EVE_SERVICE_STP_STOP"    },
   { EVE_SERVICE_ERR_ACK     , "EVE_SERVICE_ERR_ACK"     },
   { EVE_SERVICE_ALL_TO_MAN  , "EVE_SERVICE_ALL_TO_MAN"  },
   { EVE_SERVICE_ALL_TO_AUTO , "EVE_SERVICE_ALL_TO_AUTO" },
   { EVE_INTO_MAN_BL1A       , "EVE_INTO_MAN_BL1A"       },
   { EVE_INTO_MAN_BL1B       , "EVE_INTO_MAN_BL1B"       },
   { EVE_INTO_MAN_BL2        , "EVE_INTO_MAN_BL2"        },
   { EVE_INTO_MAN_PUMPS      , "EVE_INTO_MAN_PUMPS"      },
   { EVE_INTO_MAN_UV         , "EVE_INTO_MAN_UV"         },
   { EVE_INTO_MAN_SOL        , "EVE_INTO_MAN_SOL"        },
   { EVE_INTO_MAN_ACT        , "EVE_INTO_MAN_ACT"        },
   { EVE_INTO_MAN_LIFT       , "EVE_INTO_MAN_LIFT"       },
   { EVE_INTO_AUTO_BL1A      , "EVE_INTO_AUTO_BL1A"      },
   { EVE_INTO_AUTO_BL1B      , "EVE_INTO_AUTO_BL1B"      },
   { EVE_INTO_AUTO_BL2       , "EVE_INTO_AUTO_BL2"       },
   { EVE_INTO_AUTO_PUMPS     , "EVE_INTO_AUTO_PUMPS"     },
   { EVE_INTO_AUTO_UV        , "EVE_INTO_AUTO_UV"        },
   { EVE_INTO_AUTO_SOL       , "EVE_INTO_AUTO_SOL"       },
   { EVE_INTO_AUTO_ACT       , "EVE_INTO_AUTO_ACT"       },
   { EVE_INTO_AUTO_LIFT      , "EVE_INTO_AUTO_LIFT"      },
   { EVE_INTO_ENBL_BL1A      , "EVE_INTO_ENBL_BL1A"      },
   { EVE_INTO_ENBL_BL1B      , "EVE_INTO_ENBL_BL1B"      },
   { EVE_INTO_ENBL_BL2       , "EVE_INTO_ENBL_BL2"       },
   { EVE_INTO_ENBL_PUMP1     , "EVE_INTO_ENBL_PUMP1"     },
   { EVE_INTO_ENBL_PUMP2     , "EVE_INTO_ENBL_PUMP2"     },
   { EVE_INTO_ENBL_UV        , "EVE_INTO_ENBL_UV"        },
   { EVE_INTO_ENBL_SOL       , "EVE_INTO_ENBL_SOL"       },
   { EVE_INTO_ENBL_LIFT      , "EVE_INTO_ENBL_LIFT"      },
   { EVE_INTO_DIS_BL1A       , "EVE_INTO_DIS_BL1A"       },
   { EVE_INTO_DIS_BL1B       , "EVE_INTO_DIS_BL1B"       },
   { EVE_INTO_DIS_BL2        , "EVE_INTO_DIS_BL2"        },
   { EVE_INTO_DIS_PUMP1      , "EVE_INTO_DIS_PUMP1"      },
   { EVE_INTO_DIS_PUMP2      , "EVE_INTO_DIS_PUMP2"      },
   { EVE_INTO_DIS_UV         , "EVE_INTO_DIS_UV"         },
   { EVE_INTO_DIS_SOL        , "EVE_INTO_DIS_SOL"        },
   { EVE_INTO_DIS_LIFT       , "EVE_INTO_DIS_LIFT"       },
   { EVE_SWITCH_ON_BL1A      , "EVE_SWITCH_ON_BL1A"      },
   { EVE_SWITCH_ON_BL1B      , "EVE_SWITCH_ON_BL1B"      },
   { EVE_SWITCH_ON_BL2       , "EVE_SWITCH_ON_BL2"       },
   { EVE_SWITCH_ON_PUMP1     , "EVE_SWITCH_ON_PUMP1"     },
   { EVE_SWITCH_ON_PUMP2     , "EVE_SWITCH_ON_PUMP2"     },
   { EVE_SWITCH_ON_UV        , "EVE_SWITCH_ON_UV"        },
   { EVE_SWITCH_ON_SOL       , "EVE_SWITCH_ON_SOL"       },
   { EVE_SWITCH_ON_LIFT      , "EVE_SWITCH_ON_LIFT"      },
   { EVE_SWITCH_OFF_BL1A     , "EVE_SWITCH_OFF_BL1A"     },
   { EVE_SWITCH_OFF_BL1B     , "EVE_SWITCH_OFF_BL1B"     },
   { EVE_SWITCH_OFF_BL2      , "EVE_SWITCH_OFF_BL2"      },
   { EVE_SWITCH_OFF_PUMP1    , "EVE_SWITCH_OFF_PUMP1"    },
   { EVE_SWITCH_OFF_PUMP2    , "EVE_SWITCH_OFF_PUMP2"    },
   { EVE_SWITCH_OFF_UV       , "EVE_SWITCH_OFF_UV"       },
   { EVE_SWITCH_OFF_SOL      , "EVE_SWITCH_OFF_SOL"      },
   { EVE_SWITCH_OFF_LIFT     , "EVE_SWITCH_OFF_LIFT"     },
   { EVE_ACTUATOR_STEP_UP    , "EVE_ACTUATOR_STEP_UP"    },
   { EVE_ACTUATOR_STEP_DOWN  , "EVE_ACTUATOR_STEP_DOWN"  },
   { EVE_UPDATE_SYSTEM_DATA  , "EVE_UPDATE_SYSTEM_DATA"  },
   { EVE_AUTHENTICATION_OK   , "EVE_AUTHENTICATION_OK"   },
   { EVE_MAINTENANCE_REMINDER, "EVE_MAINTENANCE_REMINDER"},
   { EVE_EMRG_EMAIL_WAS_SENT , "EVE_EMRG_EMAIL_WAS_SENT" },
   { EVE_EMERGENCY_STOP      , "EVE_EMERGENCY_STOP"      },
   { EVE_ACTIVATED_SENS_PAGE , "EVE_ACTIVATED_SENS_PAGE" },
   { EVE_DB_RECORD_ON_CHANGE , "EVE_DB_RECORD_ON_CHANGE" },
   { EVE_MINUTELY_DB_RECORD  , "EVE_MINUTELY_DB_RECORD"  },
};

extern void init_eve_request();
extern void init_eve_proceed();

extern void event_request_info(int id, int status_val, char *eve_info);
extern int  get_event_requested_status(int id);
extern int  get_event_proceeded_status(int id);
extern int  get_event_proceeded_value(int id);
extern void event_request(int id, int status_val);
extern void event_request_value(int id, int status, int value);
//extern void reset_resolved_event_requests();
extern int  reset_eve_request(int event_id, int force_reset);
extern void read_config();
extern void init_config();
extern int    plc_scada_config_accordance();
extern int    check_plc_config_crit_errors();

#endif