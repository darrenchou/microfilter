//###############################################################
//# mask2_slots.h for ProcessViewServer created: Wed Mar 21 11:30:23 2018
//# please fill out these slots
//# here you find all possible events
//# Yours: Lehrig Software Engineering
//###############################################################

// todo: uncomment me if you want to use this data aquisiton
// also uncomment this classes in main.cpp and pvapp.h
// also remember to uncomment rllib in the project file
//extern rlModbusClient     modbus;  //Change if applicable
//extern rlSiemensTCPClient siemensTCP;
//extern rlPPIClient        ppi;



#include "shamemchl.h"
#include "dispatcher.h"
#include "logger.h"
#include "pvapp.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define MAN_OPER_DEV_NUM      9
#define INIT_SERV_DATA_ERROR  "init_serv_DATA() ERROR: unknown serv_ctrlList[] member\n"
#define INIT_DEV_DATA_ERROR   "init_serv_DATA() ERROR: unknown dev_stateList[] member\n"
#define SCADA_SERVICE_IS_BUSY "SCADA is busy. Request can not be processed now.\n"
#define ERROR_STP_RUN_STATUS  "slotButtonPressedEvent(): ERROR STP run-status flag value\n"
#define ERROR_ALL_TO_STATUS   "slotButtonPressedEvent(): ERROR ALL-TO flag state value\n"
#define PROCESSING_UNEXISTED  "showData(): attempt to process unexisted ui: serv_id = %d\n"


static int checkbox = 0;
//! general UI modes
enum {
   MODE_INACTIVE = 0,
   MODE_IN_REQUEST,
};

//! ALL TO... button states
enum {
   MODE_ALL_TO_AUTO = 0,
   MODE_ALL_TO_MAN
};

//! start/finish main service mode states
enum {
   MODE_START_SERV = 0,
   MODE_STOP_SERV
};

//! controls data structure
typedef struct serv_duo_ui {
   int serv_id;             //! service id
   int enbl;                //! enable/disable status
   uidstate_up2d_t btn_ui;  //! button id & status ('-1', if doesn't exist)
   uidstate_up2d_t img_ui;  //! image  id & status ('-1', if doesn't exist)
   
}serv_duo_ui_t;

//! SERVICE CONTROLS =========================================================

//! 'Plant Start/Stop' Statuses:
enum {
   STP_INACTIVE = 0, //! plant does not run
   STP_AUTOMATION,   //! plant works in automation mode
   STP_SERV_AUTO,    //! plant works in automation, but sevice was activated
   STP_SERV_MANUAL,  //! plant works, at least one device runs in manual mode
   STP_REQ_START,    //! SCADA requested PLC to start the plant
   STP_REQ_STOP,     //! SCADA requested PLC to stop the plant
   MAX_STP_STAT_NUM
};

//! Plant Start/Stop  button lables corresponding to state (see enum statuses above)
char* stp_btn_txt[MAX_STP_STAT_NUM] = {
   (char *)TXT_STP_START,
   (char *)TXT_STP_STOP,
   (char *)TXT_STP_STOP,
   (char *)TXT_STP_STOP,
   (char *)TXT_STP_START,
   (char *)TXT_STP_STOP
};

//! Plant Start/Stop image resources corresponding to state (see enum above)
char* stp_run_img_tbl[MAX_STP_STAT_NUM] = {
   (char *)LIGHT_GRAY_40,
   (char *)LIGHT_GREEN_40,
   (char *)LIGHT_GREEN_40,
   (char *)MANUAL_GREEN,
   (char *)LIGHT_BLUE_40,
   (char *)LIGHT_BLUE_40
};

//! 'PLC Error Ack' Statuses:
enum {
   STP_OFF_OR_DCN = 0,//! plant does not run or disconnected
   PLC_NO_ERROR,      //! no errors in the system
   PLC_WARNING,       //! there are some no-critical errors, - plant can run
   PLC_CRIT_ERR,      //! critial error in the system - plant can not run
   ERR_ACK_REQ,       //! error acknowledgement request was activated
   PLC_ERR_STAT_NUM
};

//! 'PLC Error Ack' image resources corresponding to state (see enum above)
char* plc_err_img_tbl[PLC_ERR_STAT_NUM] = {
   (char *)LIGHT_GRAY_40,
   (char *)LIGHT_GRAY_40,
   (char *)LIGHT_RED_40,
   (char *)LIGHT_RED_40,
   (char *)LIGHT_BLUE_40
};

//! SERVICE CONTROL UI ID: enumeration of manual operated devices
enum {
   SERV_ON_OFF = 0,   //! 'Start/Stop Service' Button
   SERV_ALL_TO,       //! 'All to AUTO/Manual' Button and Image
   SERV_REBOOT,       //! 'Reboot PC' Service Button
   SERV_STP_RUN,      //! 'STP Start/Stop' Button and Image
   SERV_ERR_ACK,      //! 'PLC Error Ack' Button and Image
   MAX_SERV_CTRL_NUM
};

//! SERVICE CONTROL Statuses:
enum {
   SERV_INACCESS = 0, //! service inaccessible
   SERVICE_OFF,       //! service is not activated
   SERV_IN_REQUEST,   //! service request to PLC is in process
   SERVICE_ALLOWED,   //! 'Start Service' was activated,
                      //! but all devices still in automation mode
   SERVICE_ACTIVE,    //! service is active, that means
                      //! at least one device is operated manualy
   MAX_SERV_BTN_STAT_NUM
};

//! STP Start/Stop  button lables corresponding to state (see enum above)
char* serv_btn_txt[MAX_SERV_BTN_STAT_NUM] = {
   (char *)TXT_SERV_START,
   (char *)TXT_SERV_START,
   (char *)TXT_PROCESSING,
   (char *)TXT_SERV_STOP,
   (char *)TXT_SERV_STOP
};

//! ALL TO... UI Statuses
enum {
   ALL_TO_DCN = 0,    //! service inaccessible
                      //! also is used as default on initializing
   ALL_TO_AUTO,       //! service propose to switch all devices into automation
   ALL_TO_MANUAL,     //! service propose to switch all devices into manual mode
   ALL_TO_AUTO_REQ,   //! request to switch all devices into automation
   ALL_TO_MAN_REQ,    //! request to switch all devices into manual mode
   MAX_ALL_TO_STAT_NUM
};

//! ALL TO...  image resources corresponding to state (see enum above)
char* all_to_img_tbl[MAX_ALL_TO_STAT_NUM] = {
   (char *)ALL_TO_GRAY,
   (char *)ALL_TO_GREEN,
   (char *)ALL_TO_GREEN,
   (char *)LIGHT_BLUE_40,
   (char *)LIGHT_BLUE_40
};

//! ALL TO...  button lables corresponding to state (see enum above)
char* all_to_btn_txt[MAX_ALL_TO_STAT_NUM] = {
   (char *)TXT_ALL_TO_REQ,
   (char *)TXT_ALL_TO_AUTO,
   (char *)TXT_ALL_TO_MAN,
   (char *)TXT_ALL_TO_REQ,
   (char *)TXT_ALL_TO_REQ
};
//+++++++++++++++++++ check below change ui id+++++++++
//+++++++++++++++++++
/*
//! service controls table
static serv_duo_ui_t serv_ctrlList[MAX_SERV_CTRL_NUM] = {
 //! serv_id     enbl <----------- btn_ui ----------->  <------------ img_ui ------------>
 //!                  ui_id          state          up2d  ui_id          state          up2d 
   { SERV_ON_OFF , 1, {btnService   , SERV_INACCESS , 0}, {-1           , -1            , 1}},
   { SERV_ALL_TO , 0, {btnGroup_Mode, ALL_TO_DCN    , 0}, {imgGroup_Mode, ALL_TO_DCN    , 0}},
   { SERV_REBOOT , 1, {btnRestartPC , SERV_INACCESS , 0}, {-1           , -1            , 1}},
   { SERV_STP_RUN, 1, {btnSTP_OnOff , STP_INACTIVE  , 0}, {imgSTP_OnOff , STP_INACTIVE  , 0}},
   { SERV_ERR_ACK, 0, {btnErrorReset, STP_OFF_OR_DCN, 0}, {imgErrorReset, STP_OFF_OR_DCN, 0}}
};
*/

//! DEVICES ==================================================================

//! possible common devices ui states 
enum {
   AUTO_DCN = 0,          //! disconnected from PLC during auto modes,
                      //! also is used as default on initializing
   MAN_DCN,           //! disconnected from PLC during manual mode
   IN_AUTO,           //! device is in automation mode
   IN_MANUAL,         //! device is in manual mode
   REQ_AUTO,          //! device is in request for automation mode
   REQ_MAN,           //! device is in request for manual mode
   DIS_DCN,           //! disconnected when device was disabled,
   ENBL_DCN,          //! disconnected when device was enabled,
   DISABLED,          //! device has disabled state
   ENABLED,           //! device has enabled state
   IN_ERROR,          //! device has error state
   REQ_DIS,           //! device is in request for disabling
   REQ_ENBL,          //! device is in request for enabling
   INACT_DCN,         //! disconnected when device was stoped,
   ACTIV_DCN,         //! disconnected when device was started,
   INACTIVE,          //! device is off
   ACTIVE,            //! device is on
   REQ_ON,            //! device is in request to be turned on
   REQ_OFF,           //! device is in request to be turned off   19
   DEV_NUM_UI_STATES
};

//! Current Device's Service States
typedef struct serv_dev_stat {
   int dev_id;        //! DEVICE UI ID, - see enum of manual operated devices
   int exist;         //! device existing flag
   int man_stat;      //! current service status
   int cur_enbl;      //! current enable status
   int cur_run;       //! current run status
}serv_dev_stat_t;

//! devices Statuses Table
//! the order should fit to enum of the operated devices, - see pvapp.h

//++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++
//comented because no such device
/*
static serv_dev_stat_t dev_stateList[MAN_OPER_DEV_NUM] = {
 //! dev_id     exist  man_stat  cur_enbl  cur_run
   { DEV_LIFT  , 1   , AUTO_DCN, ENBL_DCN, INACT_DCN },
   { DEV_BLOW1A, 1   , AUTO_DCN, ENBL_DCN, INACT_DCN },
   { DEV_BLOW1B, 1   , AUTO_DCN, ENBL_DCN, INACT_DCN },
   { DEV_BLOW2 , 1   , AUTO_DCN, ENBL_DCN, INACT_DCN },
   { DEV_PUMP1 , 1   , AUTO_DCN, ENBL_DCN, INACT_DCN },
   { DEV_PUMP2 , 1   , AUTO_DCN, ENBL_DCN, INACT_DCN },
   { DEV_UV    , 1   , AUTO_DCN, ENBL_DCN, INACT_DCN },
   { DEV_SOL   , 1   , AUTO_DCN, ENBL_DCN, INACT_DCN },
   { DEV_ACT   , 1   , AUTO_DCN, ENBL_DCN, INACT_DCN }
};
*/
//new added

static serv_dev_stat_t dev_stateList[MAN_OPER_DEV_NUM] = {
 //! dev_id     exist  man_stat  cur_enbl  cur_run
   { DEV_SOL1  , 1   , AUTO_DCN, ENBL_DCN, INACT_DCN },
   { DEV_SOL2  , 1   , AUTO_DCN, ENBL_DCN, INACT_DCN },
   { DEV_SOL3  , 1   , AUTO_DCN, ENBL_DCN, INACT_DCN },
   { DEV_SOL4  , 1   , AUTO_DCN, ENBL_DCN, INACT_DCN },
   { DEV_SOL5  , 1   , AUTO_DCN, ENBL_DCN, INACT_DCN },
   { DEV_SOL6  , 1   , AUTO_DCN, ENBL_DCN, INACT_DCN },
   { DEV_SOL7  , 1   , AUTO_DCN, ENBL_DCN, INACT_DCN },
   { DEV_SOL8  , 1   , AUTO_DCN, ENBL_DCN, INACT_DCN },
   { DEV_SOL9  , 1   , AUTO_DCN, ENBL_DCN, INACT_DCN },   
};

//! DEVICES UI REPRESENTATION ================================================

//! table of img-resources corresponded to images possible ui states
//! see enumeration above
char* img_dev_res_tbl[DEV_NUM_UI_STATES] = {
   (char *)AUTO_GRAY,
   (char *)MANUAL_GRAY,
   (char *)AUTO_GREEN,
   (char *)MANUAL_GREEN,
   (char *)LIGHT_BLUE_40,
   (char *)LIGHT_BLUE_40,
   (char *)LIGHT_GRAY_40,
   (char *)LIGHT_GRAY_40,
   (char *)LIGHT_GRAY_40,
   (char *)LIGHT_GREEN_40,
   (char *)LIGHT_RED_40,
   (char *)LIGHT_BLUE_40,
   (char *)LIGHT_BLUE_40,
   (char *)LIGHT_GRAY_40,
   (char *)LIGHT_GRAY_40,
   (char *)LIGHT_GRAY_40,
   (char *)LIGHT_GREEN_40,
   (char *)LIGHT_BLUE_40,
   (char *)LIGHT_BLUE_40     //19
};

//! AUTO-MANUAL buttons switch states
enum {
   SWITCH_MAN = 0,
   SWITCH_AUTO,
};

//! AUTO-MANUAL button lables corresponding to state (see enum above)
char* AM_btn_txt[2] = {
   (char *)TXT_SWITCH_MAN,
   (char *)TXT_SWITCH_AUTO
};

//! ENABLE-DISABLE buttons switch states
enum {
   SWITCH_ENBL = 0,
   SWITCH_DIS
};

//! ENABLE-DISABLE button lables corresponding to state (see enum above)
char* enbl_btn_txt[2] = {
   (char *)TXT_SWITCH_ENBL,
   (char *)TXT_SWITCH_DIS
};

//! ON-OFF buttons switch states
enum {
   SWITCH_ON = 0,
   SWITCH_OFF,
};

//! ON-OFF button lables corresponding to state (see enum above)
char* run_btn_txt[2] = {
   (char *)TXT_TURN_ON,
   (char *)TXT_TURN_OFF
};

//! LOCKED lables states
enum {
   LOCKED = 0,
   UNLOCKED
};

enum {
   DEV_AM = 0,
   DEV_DIS,
   DEV_RUN
};

//! device's manual control UI structure
typedef struct serv_dev_ui {
   //! auto-manual UI
   serv_duo_ui_t AM_ui;
   //! enable-disable UI
   //////serv_duo_ui_t enbl_ui;
   //! on-off UI
   serv_duo_ui_t run_ui;
   //! lock label
   //uidstate_up2d_t lock_ui;
}serv_dev_ui_t;

//! devices UI Table
static serv_dev_ui_t dev_uiList[MAN_OPER_DEV_NUM] = {
//! serv_id  enbl <---------- btn_ui ----------->   <---------- img_ui ----------->   <--------- lbl_ui ---------->
//!               ui_id            state       up2d  ui_id            state     up2d  ui_id              state  up2d
   {{DEV_AM , 0, {btnGroup_Mode , SWITCH_MAN , 0}, {imgSysMode , AUTO_DCN , 0}},//AM_ui
    //{DEV_DIS, 0, {btnLiftSt_EnDis, SWITCH_ENBL, 0}, {imgLiftSt_EnDis, ENBL_DCN , 0}},//enbl_ui
    {DEV_RUN, 0, {btnManSol1, SWITCH_ON  , 0}, {imgManSol1, INACT_DCN, 0}}},

    {{DEV_AM , 0, {btnGroup_Mode , SWITCH_MAN , 0}, {imgSysMode , AUTO_DCN , 0}},//AM_ui
    //{DEV_DIS, 0, {btnLiftSt_EnDis, SWITCH_ENBL, 0}, {imgLiftSt_EnDis, ENBL_DCN , 0}},//enbl_ui
    {DEV_RUN, 0, {btnManSol2, SWITCH_ON  , 0}, {imgManSol2, INACT_DCN, 0}}},

    {{DEV_AM , 0, {btnGroup_Mode , SWITCH_MAN , 0}, {imgSysMode , AUTO_DCN , 0}},//AM_ui
    //{DEV_DIS, 0, {btnLiftSt_EnDis, SWITCH_ENBL, 0}, {imgLiftSt_EnDis, ENBL_DCN , 0}},//enbl_ui
    {DEV_RUN, 0, {btnManSol3, SWITCH_ON  , 0}, {imgManSol3, INACT_DCN, 0}}},

    {{DEV_AM , 0, {btnGroup_Mode , SWITCH_MAN , 0}, {imgSysMode , AUTO_DCN , 0}},//AM_ui
    //{DEV_DIS, 0, {btnLiftSt_EnDis, SWITCH_ENBL, 0}, {imgLiftSt_EnDis, ENBL_DCN , 0}},//enbl_ui
    {DEV_RUN, 0, {btnManSol4, SWITCH_ON  , 0}, {imgManSol4, INACT_DCN, 0}}},

    {{DEV_AM , 0, {btnGroup_Mode , SWITCH_MAN , 0}, {imgSysMode , AUTO_DCN , 0}},//AM_ui
    //{DEV_DIS, 0, {btnLiftSt_EnDis, SWITCH_ENBL, 0}, {imgLiftSt_EnDis, ENBL_DCN , 0}},//enbl_ui
    {DEV_RUN, 0, {btnManSol5, SWITCH_ON  , 0}, {imgManSol5, INACT_DCN, 0}}},

    {{DEV_AM , 0, {btnGroup_Mode , SWITCH_MAN , 0}, {imgSysMode , AUTO_DCN , 0}},//AM_ui
    //{DEV_DIS, 0, {btnLiftSt_EnDis, SWITCH_ENBL, 0}, {imgLiftSt_EnDis, ENBL_DCN , 0}},//enbl_ui
    {DEV_RUN, 0, {btnManSol6, SWITCH_ON  , 0}, {imgManSol6, INACT_DCN, 0}}},

    {{DEV_AM , 0, {btnGroup_Mode , SWITCH_MAN , 0}, {imgSysMode , AUTO_DCN , 0}},//AM_ui
    //{DEV_DIS, 0, {btnLiftSt_EnDis, SWITCH_ENBL, 0}, {imgLiftSt_EnDis, ENBL_DCN , 0}},//enbl_ui
    {DEV_RUN, 0, {btnManSol7, SWITCH_ON  , 0}, {imgManSol7, INACT_DCN, 0}}},

    {{DEV_AM , 0, {btnGroup_Mode , SWITCH_MAN , 0}, {imgSysMode , AUTO_DCN , 0}},//AM_ui
    //{DEV_DIS, 0, {btnLiftSt_EnDis, SWITCH_ENBL, 0}, {imgLiftSt_EnDis, ENBL_DCN , 0}},//enbl_ui
    {DEV_RUN, 0, {btnManSol8, SWITCH_ON  , 0}, {imgManSol8, INACT_DCN, 0}}},

    {{DEV_AM , 0, {btnGroup_Mode , SWITCH_MAN , 0}, {imgSysMode , AUTO_DCN , 0}},//AM_ui
    //{DEV_DIS, 0, {btnLiftSt_EnDis, SWITCH_ENBL, 0}, {imgLiftSt_EnDis, ENBL_DCN , 0}},//enbl_ui
    {DEV_RUN, 0, {btnManSol9, SWITCH_ON  , 0}, {imgManSol9, INACT_DCN, 0}}},
  
};


//! OUTPUT UI REPRESENTATION =================================================

//! output ui data structure
typedef struct serv_output {
   int dev_id;   //! DEVICE ID, - see enumeration of manual operated devices
   int exist;    //! device existing flag from system configuration (true/false)
   int ui_id;    //! editbox UI widget id
   char txt[64]; //! editbox text
}serv_output_t;


//!****************************************************************************
//!                     MASK UI DATA STRUCTURE
//!****************************************************************************
typedef struct {
   int ui_cur_mode;                //! UI mode MODE_... see top of this file
   int all_to_state;               //! 'ALL_TO_... button state
   //int service_state;               //! 'Start/Stop Service button state

   int req_eve_id;                 //! requested event id, if MODE_IN_REQUEST
   uint update;
   
   serv_duo_ui_t   *servs_tbl;     //! services controls table (runtime data)
   serv_dev_stat_t *states_tbl;    //! devices states table (runtime data)
   serv_dev_ui_t   *dev_ui_tbl;    //! devices ui table (static & runtime)
   serv_output_t   *serv_out_tbl;  //! output ui table  (editboxes)
}
DATA;

//!****************************************************************************
/*static int update_serv_ctrl_DATA(DATA *d, int force_update)
{
  return 0;
}
*/
/*
static void startCIP()
{

  set cip start control value to true
  do I need to set the control of all solenoids 
  
  printf("CIP is starting\n");
}
*/


static int update_dev_DATA(DATA *d, int force_update)
{
  int dev_exists=0, dev_manual=0, dev_powered=0, dev_started=0, dev_in_err=0;
  
  int plc_connected   = !(stp2pvs->no_connection);
  int sys_runstat     = stp2pvs->sys_runstat;      //! 'STP is working' flag
  /*
  int blower2_exists  = (int)bin_opts[BLOWER2_OPT ]->cur_val;
  int lift_st_exists  = (int)bin_opts[LIFT_STATION]->cur_val;
  */
  /*int bl1a_manual     = stp2pvs->bl1a_mode;
  int bl1b_manual     = stp2pvs->bl1b_mode;
  int bl2_manual      = stp2pvs->bl2_mode;
  int pumps_manual    = stp2pvs->pumps_mode;
  int uv_manual       = stp2pvs->uv_mode;
  int sol_manual      = stp2pvs->sol_mode;
  int act_manual      = stp2pvs->act_mode;
  int lift_manual     = stp2pvs->lift_mode;
  */
  //new added+++++
  int sol1_manual = stp2pvs->sol_S1;
  int sol2_manual = stp2pvs->sol_S2;
  int sol3_manual = stp2pvs->sol_S3;
  int sol4_manual = stp2pvs->sol_S4;
  int sol5_manual = stp2pvs->sol_S5;
  int sol6_manual = stp2pvs->sol_S6;
  int sol7_manual = stp2pvs->sol_S7;
  int sol8_manual = stp2pvs->sol_S8;
  int sol9_manual = stp2pvs->sol_S9;

  int dev_status;
  //int old_man_stat, old_enbl_stat, old_run_stat, old_lock_stat;
  //int cur_man_stat, cur_enbl_stat, cur_run_stat, cur_lock_stat;

  int old_man_stat,  old_run_stat;
  int cur_man_stat,  cur_run_stat;
  int up2d_AM = 1,  up2d_run = 1; //initialized value is 1???

  //! first we receive the picture of the actual device's statuses
  //! based on the very last OSAUT message, remaped into 'stp2pvs'
  //! shared memmory structure
  for (int i = 0; i < MAN_OPER_DEV_NUM; i++){
     
     dev_exists  = devstatList[i]->exists; //in shared memory, each time can get new info from plc message
     dev_manual  = devstatList[i]->manual;
     dev_powered = devstatList[i]->enbled;
     dev_started = devstatList[i]->active;
     dev_in_err  = devstatList[i]->in_err;

     d->states_tbl[i].exist = dev_exists;
     if (dev_exists){
        old_man_stat  = d->states_tbl[i].man_stat;
        //old_enbl_stat = d->states_tbl[i].cur_enbl;
        old_run_stat  = d->states_tbl[i].cur_run;
        //olcxd_lock_stat = d->dev_ui_tbl[i].lock_ui.state;
        
        ///if (plc_connected){
           cur_man_stat  = (dev_manual)? IN_MANUAL: IN_AUTO;
           //cur_enbl_stat = (dev_in_err)? IN_ERROR: (dev_powered)? ENABLED: DISABLED;
           cur_run_stat  = (dev_started)? ACTIVE: INACTIVE; //active option is 0 when initialized!
           //cur_lock_stat = (dev_manual && dev_powered && !dev_in_err)? UNLOCKED: LOCKED;
           
           //! if requested status was resolved or got any value after disconnection,
           //! then update status for a new current value in the table
           
           //! Manual/Auto widget
           if ((old_man_stat == REQ_AUTO && cur_man_stat == IN_AUTO) ||     //! request resolved
               (old_man_stat == REQ_MAN  && cur_man_stat == IN_MANUAL) ||   //! request resolved
                old_man_stat == AUTO_DCN || old_man_stat == MAN_DCN ||
                 cur_man_stat != old_man_stat || force_update){             //! status after disc
              d->states_tbl[i].man_stat = cur_man_stat;
              up2d_AM = 0;
           }
           //! Enable/Disable widget
           /*if (d->states_tbl[i].dev_id != DEV_ACT){
              if ((old_enbl_stat == REQ_ENBL && cur_enbl_stat == ENABLED) ||   //! request resolved
                  (old_enbl_stat == REQ_DIS  && cur_enbl_stat == DISABLED) ||  //! request resolved
                   old_enbl_stat == ENBL_DCN || old_enbl_stat == DIS_DCN ||
                   cur_enbl_stat != old_enbl_stat || force_update){            //! status after disc
                 d->states_tbl[i].cur_enbl = cur_enbl_stat;
                 //printf("update_dev_DATA(): cur_enbl_stat = %d\n", cur_enbl_stat);
                 up2d_enbl = 0;
              } 
           } else if (d->states_tbl[i].dev_id == DEV_ACT){
              //! The system does not have power control of the actuator, its always powered.
              //! Therefore 'switching' actuator to the manual mode means also to 'enable' it.
              if (cur_enbl_stat != old_enbl_stat || force_update){
                 d->states_tbl[i].cur_enbl = cur_enbl_stat;
                 up2d_enbl = 0;
              }
           }
           */
           //! Start/Stop widget
           /*if ((old_run_stat == REQ_ON  && cur_run_stat == ACTIVE) ||       //! request resolved
               (old_run_stat == REQ_OFF && cur_run_stat == IN_MANUAL) ||    //! request resolved
                old_run_stat == ACTIV_DCN || old_run_stat == INACT_DCN ||
                cur_run_stat != old_run_stat || force_update){              //! status after disc
           */
              d->states_tbl[i].cur_run  = cur_run_stat;
              up2d_run = 0;
           ///}
           //! LOCKED label
           /*
           if (old_lock_stat != cur_lock_stat || force_update){
              d->dev_ui_tbl[i].lock_ui.state = cur_lock_stat;
              up2d_lock = 0;
           }*/
           //! updating button's statuses accordance to the actual value
           d->dev_ui_tbl[i].AM_ui.btn_ui.state = (dev_manual)? SWITCH_AUTO: SWITCH_MAN; //MAN is 0, AUTO is 1 in definition
           ///if (d->states_tbl[i].dev_id != DEV_ACT){
              ///d->dev_ui_tbl[i].enbl_ui.btn_ui.state = (dev_powered)? SWITCH_DIS: SWITCH_ENBL;
              d->dev_ui_tbl[i].run_ui.btn_ui.state  = (dev_started)? SWITCH_OFF: SWITCH_ON;
           ///} 
        /*} else {
           //! if PLC was disconnected during manual mode, we try to keep
           //! the latest opcode snapshot, but all green lights switch to gray
           //! also we have to close access into 'start/stop' button with 'LOCKED' label
           cur_man_stat  = (old_man_stat == IN_MANUAL || old_man_stat == MAN_DCN)? MAN_DCN: AUTO_DCN;
           ///cur_enbl_stat = (old_enbl_stat == ENABLED || old_enbl_stat == ENBL_DCN)? ENBL_DCN: DIS_DCN;
           cur_run_stat  = (old_run_stat  == ACTIVE || old_run_stat == ACTIV_DCN)? ACTIV_DCN: INACT_DCN;
           ///cur_lock_stat = LOCKED;

           //! Manual/Auto widget
           if ((old_man_stat != AUTO_DCN && old_man_stat != MAN_DCN) || force_update){
              d->states_tbl[i].man_stat = cur_man_stat;
              up2d_AM = 0;
           }
           //! Enable/Disable widget
           if ((cur_enbl_stat != AUTO_DCN && cur_enbl_stat != DIS_DCN) || force_update){
              d->states_tbl[i].cur_enbl = cur_enbl_stat;
              up2d_enbl = 0;
           }
           //! Start/Stop widget
           if ((old_man_stat != ENBL_DCN && old_man_stat != MAN_DCN) || force_update){
              d->states_tbl[i].cur_run  = cur_run_stat;
              up2d_run = 0;
           }
           //! LOCKED label
           /*if ((old_lock_stat != cur_lock_stat) || force_update){
              d->dev_ui_tbl[i].lock_ui.state = cur_lock_stat;
              up2d_lock = 0;
           }
        }
        */
        //! repmaping images statuses from states_tbl[] into the dev_ui_tbl[]
        d->dev_ui_tbl[i].AM_ui.img_ui.state = d->states_tbl[i].man_stat;
        ////d->dev_ui_tbl[i].enbl_ui.img_ui.state = d->states_tbl[i].cur_enbl;
        ///if (d->states_tbl[i].dev_id != DEV_ACT){
           d->dev_ui_tbl[i].run_ui.img_ui.state  = d->states_tbl[i].cur_run;
        ///}
        
        //if (!up2d_AM || !up2d_enbl || !up2d_run || !up2d_lock){
        if (!up2d_AM || !up2d_run ){
           //! true 'force_update' resets all 'up2d' statuses on the every new entry into the mask
           if (!up2d_AM){
              d->dev_ui_tbl[i].AM_ui.btn_ui.up2d = (d->dev_ui_tbl[i].AM_ui.btn_ui.ui_id != -1)? 0: 1;
              d->dev_ui_tbl[i].AM_ui.img_ui.up2d = (d->dev_ui_tbl[i].AM_ui.img_ui.ui_id != -1)? 0: 1;
           }
           /*if (!up2d_enbl){
              d->dev_ui_tbl[i].enbl_ui.btn_ui.up2d = (d->dev_ui_tbl[i].enbl_ui.btn_ui.ui_id != -1)? 0: 1;
              d->dev_ui_tbl[i].enbl_ui.img_ui.up2d = (d->dev_ui_tbl[i].enbl_ui.img_ui.ui_id != -1)? 0: 1;
              //printf("update_dev_DATA(): d->dev_ui_tbl[i].enbl_ui.img_ui.up2d = %d\n",d->dev_ui_tbl[i].enbl_ui.img_ui.up2d);
           }*/
           if (!up2d_run){
              d->dev_ui_tbl[i].run_ui.btn_ui.up2d = (d->dev_ui_tbl[i].run_ui.btn_ui.ui_id != -1)? 0: 1;
              d->dev_ui_tbl[i].run_ui.img_ui.up2d = (d->dev_ui_tbl[i].run_ui.img_ui.ui_id != -1)? 0: 1;
           }
           /*if (!up2d_lock){
              d->dev_ui_tbl[i].lock_ui.up2d = (d->dev_ui_tbl[i].lock_ui.ui_id != -1)? 0: 1;
           }*/
        }
     } 
  }
  return 0;
}

//!****************************************************************************
static int init_serv_DATA(DATA *d)
{
  int dev_exists = 0;
  
  ///int actuator_exists = (int)bin_opts[ACTUATOR_OPT]->cur_val;
  ///int lift_lvl_sensor = (int)bin_opts[LIFT_SENSOR ]->cur_val;
  
  if(d == NULL) return -1;
  
  d->ui_cur_mode = MODE_INACTIVE;
  d->req_eve_id  = EVE_NULL;
  
  //! SERVICE CONTROLS INITIALIZATION
  //d->servs_tbl = serv_ctrlList;
  ///update_serv_ctrl_DATA(d, 1);

  //! DEVICES INITIALIZATION
  d->states_tbl = dev_stateList;
  d->dev_ui_tbl = dev_uiList;
  update_dev_DATA(d, 1);

  //! OUTPUTS INITIALIZATION
  /*d->serv_out_tbl = dev_outList;
  for (int i = 0; i < 4; i++){
     dev_exists = 1;
     switch (d->serv_out_tbl[i].dev_id){
        case DEV_LIFT : dev_exists = lift_lvl_sensor;
                        break;
        case DEV_PUMP1: break;
        case DEV_ACT  : dev_exists = actuator_exists;
                        break;
     }
     d->serv_out_tbl[i].exist = dev_exists;
  }
  */
  ///update_output_DATA(d);

  return 0;
}

static int slotInit(PARAM *p, DATA *d)
{
  if(p == NULL || d == NULL) return -1;
  //memset(d,0,sizeof(DATA));
  memset(d,0,sizeof(DATA));
  
  init_serv_DATA(d);
  printf("%s\n","slot2 is initializing" );
  return 0;
}

static int slotNullEvent(PARAM *p, DATA *d)
{
  if(p == NULL || d == NULL) return -1;
  return 0;
}

static int slotButtonEvent(PARAM *p, int id, DATA *d)
{
  if(p == NULL || id == 0 || d == NULL) return -1;
  int ret = 0;
  //int btn_state, eve_id;
  /*if (id == btnMenu){
     //globs->pre_mask = globs->cur_mask;
     return MASK_SCHEMATIC; // go back to the main production mask
  }
  */
  if (id == btnSettings)
  {
     ret = MASK_SYS_SETTINGS;
  }
  if (id == btnMenu)
  {
     ret = MASK_SCHEMATIC;
  }
  if (id == btnMessages)
  {
     ret = MASK_MESSAGES ;
  }
  return ret;
}

//!****************************************************************************
static void update_ui_modes(PARAM *p, DATA *d)
{
  ///if (d->ui_cur_mode == MODE_IN_REQUEST){
    /// if (get_event_requested_status(d->req_eve_id) == NO_EVENT){
        ///printf ("update_ui_modes(): released current ui mode into MODE_INACTIVE.\n");
        ///update_serv_ctrl_DATA(d, 1);
        update_dev_DATA(d, 1);
        //update_output_DATA(d);
        
        //mask_uiSetEnabled(p, d, 1);
        
        //d->ui_cur_mode = MODE_INACTIVE;
        //d->req_eve_id  = EVE_NULL;
     //}
  //}
}

//!****************************************************************************
//! updates the status and state of ui, corresponding to device
//! was activated by pressing one of the device controls buttons:
//! 'manual/auto',  'start/stop'
//!****************************************************************************
static int update_devices_ui(PARAM *p, DATA *d, int pressed_btn_id)
{
  int cur_man_stat  = -1, cur_enbl_stat = -1, cur_run_stat = -1;
  int new_stat = -1, updated = 0;
  //printf("%s\n","test" );
  //usleep(10000000);

  for (int i = 0; i < MAN_OPER_DEV_NUM; i++){

     //cur_man_stat  = d->states_tbl[i].man_stat;
     //cur_enbl_stat = d->states_tbl[i].cur_enbl;
     cur_run_stat  = d->states_tbl[i].cur_run;
      
     /*if (d->dev_ui_tbl[i].AM_ui.btn_ui.ui_id == pressed_btn_id){
        new_stat = (cur_man_stat == IN_MANUAL)? REQ_AUTO: REQ_MAN;
        d->states_tbl[i].man_stat = new_stat;

        d->dev_ui_tbl[i].AM_ui.btn_ui.state = new_stat;
        d->dev_ui_tbl[i].AM_ui.img_ui.state = new_stat;
        //! changing image to the new status immidiatly:
        pvSetImage(p, d->dev_ui_tbl[i].AM_ui.img_ui.ui_id,
                      pvtr(img_dev_res_tbl[new_stat]));
        d->dev_ui_tbl[i].AM_ui.btn_ui.up2d  = 0;
        updated = 1;
        break;
     } 
     if (d->dev_ui_tbl[i].enbl_ui.btn_ui.ui_id == pressed_btn_id){
        new_stat = (cur_enbl_stat == ENABLED)? REQ_DIS: REQ_ENBL;
        d->states_tbl[i].cur_enbl = new_stat;

        d->dev_ui_tbl[i].enbl_ui.btn_ui.state = new_stat;
        d->dev_ui_tbl[i].enbl_ui.img_ui.state = new_stat;
        //! changing image to the new status immidiatly:
        pvSetImage(p, d->dev_ui_tbl[i].enbl_ui.img_ui.ui_id,
                      pvtr(img_dev_res_tbl[new_stat]));
        d->dev_ui_tbl[i].enbl_ui.btn_ui.up2d  = 0;
        updated = 1;
        break;
     }*/

     if (d->dev_ui_tbl[i].run_ui.btn_ui.ui_id == pressed_btn_id){
        new_stat = (cur_run_stat == ACTIVE)? REQ_OFF: REQ_ON;
        d->states_tbl[i].cur_run = new_stat;

        d->dev_ui_tbl[i].run_ui.btn_ui.state = new_stat;
        d->dev_ui_tbl[i].run_ui.img_ui.state = new_stat;
        //! changing image to the new status immidiatly:

        pvSetImage(p, d->dev_ui_tbl[i].run_ui.img_ui.ui_id,
                      pvtr(img_dev_res_tbl[new_stat]));
        d->dev_ui_tbl[i].run_ui.btn_ui.up2d  = 0;
        printf("%s\n","update_devices_ui is called" );
        printf("new_stat is %d\n", new_stat);
        printf("the device num is %d\n", i);
        updated = 1;
        usleep(10000000);
        break;
     }
  }
  return updated;
}


//!****************************************************************************
//! updates the status and state of ui, corresponding service
//! was activated by pressing one of the service control buttons
//! ('service start/stop','reboot','stp start/stop','error ack','all to...')
//!****************************************************************************
static int update_service_ctrl_ui(PARAM *p, DATA *d, int pressed_btn_id)
{
  int cur_stat = -1, new_stat = -1, updated = 0;

  for (int i = 0; i < MAX_SERV_CTRL_NUM; i++){
     if (d->servs_tbl[i].btn_ui.ui_id == pressed_btn_id){

         cur_stat = d->servs_tbl[i].btn_ui.state;
         switch (i){
            case SERV_ON_OFF : new_stat = SERV_IN_REQUEST;
                               break;
            case SERV_ALL_TO : if (cur_stat == ALL_TO_AUTO){
                                  new_stat = ALL_TO_AUTO_REQ;
                               } else if (cur_stat == ALL_TO_MANUAL){
                                  new_stat = ALL_TO_MAN_REQ;
                               }
                               pvSetImage(p, d->servs_tbl[i].img_ui.ui_id,
                                             pvtr(all_to_img_tbl[new_stat]));
                               break;
            case SERV_REBOOT : new_stat = SERV_IN_REQUEST;
                               break;
            case SERV_STP_RUN: if (cur_stat == STP_AUTOMATION || cur_stat == STP_SERV_AUTO ){
                                  new_stat = STP_REQ_STOP;
                               } else if (cur_stat == STP_INACTIVE){
                                  new_stat = STP_REQ_START;
                               }
                               break;
            case SERV_ERR_ACK: new_stat = ERR_ACK_REQ;
                               break;
                      default: return 0;
         }
         d->servs_tbl[i].btn_ui.state = new_stat;
         d->servs_tbl[i].btn_ui.up2d  = 0;
         d->servs_tbl[i].enbl         = 0;

         if (d->servs_tbl[i].img_ui.ui_id != -1){
            d->servs_tbl[i].img_ui.state = new_stat;
            d->servs_tbl[i].img_ui.up2d  = 0;
         }
         updated = 1;
         break;
     }         
  }
  return updated;
}



static int slotButtonPressedEvent(PARAM *p, int id, DATA *d)
{
  if(p == NULL || id == 0 || d == NULL) return -1;
  int ret = 0; 
  int btn_state, eve_id;
  char err_msg [256] = "";
  switch (id){  
    //service controls
    case btnChemMix     : eve_id = (stp2pvs->service_mode)? EVE_SERVICE_FINISH: EVE_SERVICE_START; break;
    case btnErrorReset  : eve_id = EVE_SERVICE_ERR_ACK;    break;
    
    //switch on/off of solenoids 1 to 9
    case btnManSol1: eve_id=(stp2pvs->sol_S1)?  EVE_SWITCH_OFF_SOL1 : EVE_SWITCH_ON_SOL1 ; printf("man sol1 is called\n");  break;
    //case btnBlow1A_OnOff: eve_id=(stp2pvs->bl1a_started)?  EVE_SWITCH_OFF_BL1A : EVE_SWITCH_ON_BL1A ; break;
    case btnManSol2: eve_id=(stp2pvs->sol_S2)?  EVE_SWITCH_OFF_SOL2 : EVE_SWITCH_ON_SOL1 ; printf("man sol2 is called\n");  break;
    case btnManSol3: eve_id=(stp2pvs->sol_S3)?  EVE_SWITCH_OFF_SOL3 : EVE_SWITCH_ON_SOL1 ; printf("man sol3 is called\n");  break;
    case btnManSol4: eve_id=(stp2pvs->sol_S4)?  EVE_SWITCH_OFF_SOL4 : EVE_SWITCH_ON_SOL1 ; printf("man sol4 is called\n");  break;
    case btnManSol5: eve_id=(stp2pvs->sol_S5)?  EVE_SWITCH_OFF_SOL5 : EVE_SWITCH_ON_SOL1 ; printf("man sol5 is called\n");  break;
    case btnManSol6: eve_id=(stp2pvs->sol_S6)?  EVE_SWITCH_OFF_SOL6 : EVE_SWITCH_ON_SOL1 ; printf("man sol6 is called\n");  break;
    case btnManSol7: eve_id=(stp2pvs->sol_S7)?  EVE_SWITCH_OFF_SOL7 : EVE_SWITCH_ON_SOL1 ; printf("man sol7 is called\n");  break;
    case btnManSol8: eve_id=(stp2pvs->sol_S8)?  EVE_SWITCH_OFF_SOL8 : EVE_SWITCH_ON_SOL1 ; printf("man sol8 is called\n");  break;
    case btnManSol9: eve_id=(stp2pvs->sol_S9)?  EVE_SWITCH_OFF_SOL9 : EVE_SWITCH_ON_SOL1 ; printf("man sol9 is called\n");  break;
  default: return 0; //! if this is not a button, just exit 
  }

  /*if (d->ui_cur_mode == MODE_INACTIVE){
     d->ui_cur_mode = MODE_IN_REQUEST;
     */if (eve_id != -1){
        //update_service_ctrl_ui(p, d, id);
        update_devices_ui(p, d, id);
        //p->force_null_event = 1;
        event_request(eve_id, RUN_EVENT);
        d->req_eve_id  = eve_id;
        //mask_uiSetEnabled(p, d, 0);
       
     } else {
        printf(err_msg);
     }
  /*} else {
     printf(SCADA_SERVICE_IS_BUSY); 
  }
  */
  //printf("button state is %d after press sol1!!!!\n", d->dev_ui_tbl[i].run_ui.btn_ui.state);
  return ret;
}



static int slotButtonReleasedEvent(PARAM *p, int id, DATA *d)
{
  if(p == NULL || id == 0 || d == NULL) return -1;
  return 0;
}

static int slotTextEvent(PARAM *p, int id, DATA *d, const char *text)
{
  if(p == NULL || id == 0 || d == NULL || text == NULL) return -1;
  return 0;
}

static int slotSliderEvent(PARAM *p, int id, DATA *d, int val)
{
  if(p == NULL || id == 0 || d == NULL || val < -1000) return -1;
  return 0;
}

static int slotCheckboxEvent(PARAM *p, int id, DATA *d, const char *text)
{
  if(p == NULL || id == 0 || d == NULL || text == NULL) return -1;
  
  if(id == chkTimerCIP)
  {
    if(checkbox%2 != 0)
    {
      pvSetEnabled(p,btnReduceMix,1);
      pvSetEnabled(p,btnIncreaseMix,1);
      pvSetEnabled(p,lineditMixTime,1);
      printf("enable %d\n", checkbox);
      
    }
    else
    {
      pvSetEnabled(p,btnReduceMix,0);
      pvSetEnabled(p,btnIncreaseMix,0);
      pvSetEnabled(p,lineditMixTime,0);
      printf("unenable %d\n", checkbox);
    }
    checkbox++;
  }

  return 0;
}

static int slotRadioButtonEvent(PARAM *p, int id, DATA *d, const char *text)
{
  if(p == NULL || id == 0 || d == NULL || text == NULL) return -1;
  return 0;
}

static int slotGlInitializeEvent(PARAM *p, int id, DATA *d)
{
  if(p == NULL || id == 0 || d == NULL) return -1;
  return 0;
}

static int slotGlPaintEvent(PARAM *p, int id, DATA *d)
{
  if(p == NULL || id == 0 || d == NULL) return -1;
  return 0;
}

static int slotGlResizeEvent(PARAM *p, int id, DATA *d, int width, int height)
{
  if(p == NULL || id == 0 || d == NULL || width < 0 || height < 0) return -1;
  return 0;
}

static int slotGlIdleEvent(PARAM *p, int id, DATA *d)
{
  if(p == NULL || id == 0 || d == NULL) return -1;
  return 0;
}

static int slotTabEvent(PARAM *p, int id, DATA *d, int val)
{
  if(p == NULL || id == 0 || d == NULL || val < -1000) return -1;
  return 0;
}

static int slotTableTextEvent(PARAM *p, int id, DATA *d, int x, int y, const char *text)
{
  if(p == NULL || id == 0 || d == NULL || x < -1000 || y < -1000 || text == NULL) return -1;
  return 0;
}

static int slotTableClickedEvent(PARAM *p, int id, DATA *d, int x, int y, int button)
{
  if(p == NULL || id == 0 || d == NULL || x < -1000 || y < -1000 || button < 0) return -1;
  return 0;
}

static int slotSelectionEvent(PARAM *p, int id, DATA *d, int val, const char *text)
{
  if(p == NULL || id == 0 || d == NULL || val < -1000 || text == NULL) return -1;
  return 0;
}

static int slotClipboardEvent(PARAM *p, int id, DATA *d, int val)
{
  if(p == NULL || id == -1 || d == NULL || val < -1000) return -1;
  return 0;
}

static int slotRightMouseEvent(PARAM *p, int id, DATA *d, const char *text)
{
  if(p == NULL || id == 0 || d == NULL || text == NULL) return -1;
  //pvPopupMenu(p,-1,"Menu1,Menu2,,Menu3");
  return 0;
}

static int slotKeyboardEvent(PARAM *p, int id, DATA *d, int val, int modifier)
{
  if(p == NULL || id == 0 || d == NULL || val < -1000 || modifier < -1000) return -1;
  return 0;
}

static int slotMouseMovedEvent(PARAM *p, int id, DATA *d, float x, float y)
{
  if(p == NULL || id == 0 || d == NULL || x < -1000 || y < -1000) return -1;
  return 0;
}

static int slotMousePressedEvent(PARAM *p, int id, DATA *d, float x, float y)
{
  if(p == NULL || id == 0 || d == NULL || x < -1000 || y < -1000) return -1;
  return 0;
}

static int slotMouseReleasedEvent(PARAM *p, int id, DATA *d, float x, float y)
{
  if(p == NULL || id == 0 || d == NULL || x < -1000 || y < -1000) return -1;
  return 0;
}

static int slotMouseOverEvent(PARAM *p, int id, DATA *d, int enter)
{
  if(p == NULL || id == 0 || d == NULL || enter < -1000) return -1;
  return 0;
}

static int slotUserEvent(PARAM *p, int id, DATA *d, const char *text)
{
  if(p == NULL || id == 0 || d == NULL || text == NULL) return -1;
  return 0;
}
