/*****************************************************************************
 * bio_errors.h
 *
 * begin   : Thu Mar 11 14:18:12 2018
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
 * Copyright Osorno Enterprises Inc., 2018
 *
 * OSAUT and OSORNOD project
 * (c) Osorno Enterprises Inc., 2018: http://www.osorno.ca/
 * 
 ****************************************************************************/
#ifndef _BIO_ERRORS_H_
#define _BIO_ERRORS_H_

#include "logger.h"

#define MSG_PLC_NO_CONNECTION   "SYSTEM ERROR: NO CONNECTION with PLC! If a CONNECTION not be established within several minutes, contact MAINTENANCE.\t"
#define MSG_SEN1_NO_CONNECTION  "SYSTEM ERROR: No connection with Sensors #1.\t"
#define MSG_SEN2_NO_CONNECTION  "SYSTEM ERROR: No connection with Sensors #2.\t"
#define MSG_SEN3_NO_CONNECTION  "SYSTEM ERROR: No connection with Sensors #3.\t"
#define MSG_ACTUATOR_ERR        "SYSTEM ERROR: Actuator - not responded.\t"
#define MSG_ACT_NO_SIGNAL_ERR   "SYSTEM ERROR: No Signal from Actuator.\t"
#define MSG_ACT_POSITION_ERR    "SYSTEM ERROR: Actuator positioning error.\t"
#define MSG_MAGM_NO_SIGNAL_ERR  "SYSTEM ERROR: No Signal from Magmeter.\t" 
#define MSG_SOFT_START_1A_ERR   "SYSTEM ERROR: Blower_1A soft start error.\t"
#define MSG_PRESSURE_SW1A_ERR   "SYSTEM ERROR: Blower_1A pressure switch error.\t"
#define MSG_SOFT_START_1B_ERR   "SYSTEM ERROR: Blower_1B soft start error.\t"
#define MSG_PRESSURE_SW1B_ERR   "SYSTEM ERROR: Blower_1B pressure switch error.\t"
#define MSG_SOFT_START_2_ERR    "SYSTEM ERROR: Blower_2 soft start error.\t"
#define MSG_PRESSURE_SW_2_ERR   "SYSTEM ERROR: Blower_2 pressure switch error.\t"
#define MSG_T3_LVL_SENSOR_ERR   "SYSTEM ERROR: Tank-3, level sensor - inconsistency with switches.\t"
#define MSG_LVL_SEN_NO_SIG_ERR  "SYSTEM ERROR: Tank-3, no signal from level sensor.\t"
#define MSG_T3_SWITCHES_ERR     "SYSTEM ERROR: Tank-3, switches information conflict.\t"
#define MSG_PUMP_ONE_ERR        "SYSTEM ERROR: Pump #1 error.\t"
#define MSG_PUMP_TWO_ERR        "SYSTEM ERROR: Pump #2 error.\t"
#define MSG_MAIN_LINE_ERR       "SYSTEM ERROR: No power for single-phase supply (pre-UPS).\t"
#define MSG_LINE1_PHASE_ERR     "SYSTEM ERROR: Phase #1 failed.\t"
#define MSG_LINE2_PHASE_ERR     "SYSTEM ERROR: Phase #2 failed.\t"
#define MSG_LINE3_PHASE_ERR     "SYSTEM ERROR: Phase #3 failed.\t"
#define MSG_UV_SEN_NO_SIG_ERR   "SYSTEM ERROR: UV Sensor - no analogue signal.\t"
#define MSG_LIFT_NO_SIGN_ERR    "SYSTEM ERROR: Lift Station - no signal.\t"

#define MSG_PLC_CONNECTED       "SCADA successfully established CONNECTION with PLC.\t"
#define MSG_SEN1_CONNECTED      "Sensors #1 were successfully connected with SCADA.\t"
#define MSG_SEN2_CONNECTED      "Sensors #2 were successfully connected with SCADA.\t"
#define MSG_SEN3_CONNECTED      "Sensors #3 were successfully connected with SCADA.\t"
#define MSG_ACTUATOR_IS_OK      "Actuator is working properly, - ERROR RESOLVED.\t"
#define MSG_ACT_SYGN_IS_OK      "Signal from Actuator - ERROR RESOLVED.\t"
#define MSG_ACTU_POS_IS_OK      "Actuator Positioning - ERROR RESOLVED.\t"
#define MSG_MAGMETER_IS_OK      "Signal from Magmeter - ERROR RESOLVED.\t"
#define MSG_SSTART1A_IS_OK      "Blower_1A soft start - ERROR RESOLVED.\t"
#define MSG_PRESSW1A_IS_OK      "Blower_1A pressure switch - ERROR RESOLVED.\t"
#define MSG_SSTART1B_IS_OK      "Blower_1B soft start - ERROR RESOLVED.\t"
#define MSG_PRESSW1B_IS_OK      "Blower_1B pressure switch - ERROR RESOLVED.\t"
#define MSG_SSTART_2_IS_OK      "Blower_2 soft start - ERROR RESOLVED.\t"
#define MSG_PRESSW_2_IS_OK      "Blower_2 pressure switch - ERROR RESOLVED.\t"
#define MSG_T3LVLSEN_IS_OK      "Tank-3 Level Sensor - ERROR RESOLVED.\t"
#define MSG_T3SENSIG_IS_OK      "Signal from Tank-3 level sensor - ERROR RESOLVED.\t"
#define MSG_SWITCHES_IS_OK      "Tank-3 switches signals are correct - ERROR RESOLVED.\t"
#define MSG_PUMP_ONE_IS_OK      "Discharging Pump_#1 - ERROR RESOLVED.\t"
#define MSG_PUMP_TWO_IS_OK      "Discharging Pump_#2 - ERROR RESOLVED.\t"
#define MSG_MAINLINE_IS_OK      "Power in single-phase supply- ERROR RESOLVED.\t"
#define MSG_L1_PHASE_IS_OK      "Power in line-1 - ERROR RESOLVED.\t"
#define MSG_L2_PHASE_IS_OK      "Power in line-2 - ERROR RESOLVED.\t"
#define MSG_L3_PHASE_IS_OK      "Power in line-3 - ERROR RESOLVED.\t"
#define MSG_UV_SENOR_IS_OK      "Signal from UV Sensor - ERROR RESOLVED.\t"
#define MSG_LIFT_SEN_IS_OK      "Signal from Lift Station - ERROR RESOLVED.\t"

#define MSG_ACTUATOR_EMERGENCY  "Actuator emergency (no signal, no response).\t"
#define MSG_MAGMETER_EMERGENCY  "Magmeter emergency (no signal, out of reasonable range).\t"
#define MSG_CHAMBER3_EMERGENCY  "Tank #3 emergency (level sensor, internal inconsistency).\t"
#define MSG_PUMPS_EMERGENCY     "Pump_#1 and Pump_#2 emergency: do not operate\t"

#define MSG_LIFT_ST_LVL_EMRGENCY "Lift Station level emergency.\t"
#define MSG_POWER_EMERGENCY     "Emergency: power failure in single-phase or in the phases lines.\t"
#define MSG_SYSTOPED_EMERGENCY  "Emergency: Plant has been stopped and does not operate more than 5 minutes.\t"

#define MSG_ACTUATOR_EMRG_ENDS  "Actuator emergency issue WAS RESOLVED.\t"
#define MSG_MAGMETER_EMRG_ENDS  "Magmeter emergency issue WAS RESOLVED.\t"
#define MSG_CHAMBER3_EMRG_ENDS  "Tank-3 emergency issue WAS RESOLVED.\t"
#define MSG_PUMPS_EMRG_ENDS     "Tank #3 Discharge emergency issue WAS RESOLVED.\t"
#define MSG_LIFT_ST_LVL_EMRG_ENDS "Lift Station level emergency issue WAS RESOLVED.\t"
#define MSG_POWER_EMRG_ENDS     "Elecrical Power emergency issue WAS RESOLVED.\t"
#define MSG_SYSTOPED_EMRG_ENDS  "Plant has been started. Emergency issue WAS RESOLVED.\t"

#define MSG_EMERGENCY_ISSUE     "SCADA Emergency issue: \t"
#define MSG_EMRG_MAILING_STOPED "SCADA Emergency messaging was terminated by Service.\t"

//!----------------------------------------------------------------------------
//! There are two types of errors: 1) errors from devices (incoming errors)
//!                                2) SCADA emergencies   (outcoming errors)
//!----------------------------------------------------------------------------
//! IDS OF INCOMMING ERRORS 
enum {
   NO_ERROR = 0,          //! normal status of the system
   PLC_CNCT_ERROR,        //! no connection with PLC error
   /*SEN1CNCT_ERROR,        //! no connection with sensor-1
   SEN2CNCT_ERROR,        //! no connection with sensor-2 
   SEN3CNCT_ERROR,        //! no connection with sensor-3

   ACTUATOR_ERROR,        //! actuator error
   ACT_SIGN_ERROR,        //! actuator 'no signal' error
   POSITION_ERROR,        //! actuator positional error
   */
   MAGM_SIG_ERROR,        //! magmeter 'no signal' error
   SSTART1A_ERROR,        //! blower-1A soft start error
   PRESSW1A_ERROR,        //! blower-1A pressure switch error
   SSTART1B_ERROR,        //! blower-1B soft start error
   PRESSW1B_ERROR,        //! blower-1B pressure switch error
   SSTART_2_ERROR,        //! blower-2 soft start error
   PRESSW_2_ERROR,        //! blower-2 pressure switch error
   T3LVLSEN_ERROR,        //! tank-3 lvl sensor error
   T3SENSIG_ERROR,        //! tank-3 lvl sensor 'no signal' error
   SWITCHES_ERROR,        //! tank-3 switches error
   PUMP_ONE_ERROR,        //! pump-1 error
   PUMP_TWO_ERROR,        //! pump-2 error
   MAINLINE_ERROR,        //! main line power error
   L1_PHASE_ERROR,        //! power on phase line-1 error
   L2_PHASE_ERROR,        //! power on phase line-2 error
   L3_PHASE_ERROR,        //! power on phase line-3 error
   UVSENSIG_ERROR,        //! uv sensor 'no signal' error
   LIFTSIGN_ERROR,        //! lift station 'no signal' error
   //! add new error here   
   MAX_NUM_ERRORS
};

//! TYPES OF EMERGENCIES FOR OUTPUT TEXTING
enum {
   NO_EMERGENCY = 0,
   ACTUATOR_EMERG,        //! actuator emergency
   MAGMETER_EMERG,        //! magmeter emergency
   CHAMBER3_EMERG,        //! tank-3 emergency (switches or lvl-sensor)
   PUMPS_EMERG   ,        //! pumps emergency
   LIFT_ST_EMRG  ,        //! lift station emergency
   EL_POWER_EMERG,        //! electrical power emergencies
   SYSTOPED_EMERG,        //! plant was stopped emergency
   //! add new emergency here   
   MAX_NUM_EMERGENS
};

//! emergency processing structure
typedef struct bio_c_emerg{
   int emrg_id;
   int eve_id;
   int prev_stat;
   int curr_stat;
}bio_c_emerg_t;

#endif