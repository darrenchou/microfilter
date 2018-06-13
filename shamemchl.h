#include <sys/types.h>

#define _SIZE_EK        128
#define _SIZE_QK        256
#define _SIZE_HK        512
#define _SIZE_1K        1024
enum { //! PLC operation modes
  PLC_UNDEFINED = -1, //! virtual mode, used only for programming purposes
  PLC_INACTIVE = 0,
  PLC_PROD_AUTO,
  //PLC_PROD_AUTO_MAN,
  PLC_PROD_MANUAL,
  PLC_SYS_ERR
};


typedef struct plc_to_pvs {

  bool	update;		 //! receiving new package from plc flag

  bool	no_connection;	 //! connection status with PLC flag

  bool magm_no_sign;
  uint location_id;     //! unique SCADA program location number (plant ID)
  bool crit_error;      //! critical error flag, - the Systems should be stopped
  bool warn_error;      //! none-critical error flag, - System continue working
  bool emrg_error;      //! emergency flag, - forces SCADA to send an emergency e-mail
  bool sys_runstat;     //! stp system run-status (PLC on or not):1/0
  int	main_flow;       //! main flow average value
                         //! calibration and dosage values
  char test1[7];
  
  const char *info;
  
  bool run_service;     //! flag required to start service mode if true
  
  int plc_dosing_rate;
  
  int plc_magmeter_flow;

  int plc_totalizer_low;

  int plc_totalizer_high;

  int plc_flow_dependant;

  int plc_pH_dependant;

  int plc_save_config;
  ///////////////////////////////////////////////////////
  //new added below

  uint magmeterIN;// magmeter in flow in cubic meter per hour
  uint magmeterOUT;// magmeter out flow in cubic meter per hour

  bool auto_mode;
  bool service_mode;
  bool err_ack;
  bool AC_state;

  bool PS1;
  bool PS2;
  bool PS_AIR;
  bool MagmIN_pulse;
  bool MagmOUT_pulse;
  bool CIP_Hlvl;
  bool CIP_Llvl;
  bool Ext_Hlvl;
  bool Ext_Llvl;

  //paragraph 2
  // word 0    on/off
  bool LED_run;
  bool LED_err;
  bool sol_S1;//solenoid 1
  bool sol_S2;//solenoid 2
  bool sol_S3;//solenoid 3
  bool sol_S4;//solenoid 4
  bool sol_S5;//solenoid 5
  bool sol_S6;//solenoid 6
  bool sol_S7;//solenoid 7
  bool sol_S8;//solenoid 8
  bool sol_S9;//solenoid 9
  bool sol_SA1;//solenoid A1, first two solenoids for the first two membranes
  bool sol_SA2;//solenoid A2, second two solenoids for the second two membranes
  bool dosing_pump;//dosing pump is running
  //word 1
  bool pump_CIP;//CIP pump is running

  
  uint operation_submode;
  
  //p3 word 3
  bool PS1_present;
  bool PS2_present;
  bool PS_AIR_present;
  bool MagmIN_present;
  bool MagmOUT_present;
  bool CIP_present;
  bool reservoir_present;
  bool sol_S1_present;
  bool sol_S2_present;
  bool sol_S3_present;
  bool sol_S4_present;
  bool sol_S5_present;
  bool sol_S6_present;
  bool uF1_present;
  bool uF2_present;
  bool dp_present;//dosing pump present

  //p4 word 1   same in pvs2plc
  bool sol_S1_Man;// solenoid 1 on in manual mode
  bool sol_S2_Man;
  bool sol_S3_Man;
  bool sol_S4_Man;
  bool sol_S5_Man;
  bool sol_S6_Man;
  bool sol_S7_Man;
  bool sol_S8_Man;
  bool sol_S9_Man;
  bool sol_SA1_Man;// solenoid A1(first set including two solenoids) in manual mode
  bool sol_SA2_Man;// solenoid A2(second set including two solenoids) in manual mode
  bool dp_Man;// dosing pump in manual mode

  //p4 word 9
  bool pump1_err;
  bool pump2_err;
  bool tank_empty_err;
  bool ext_tank_contr_err;
  bool ext_tank_alarm;
  bool magmIN_sig_absent;
  bool magmOUT_sig_absent;
  
  //p4 word 12 - 15
  uint totalizerIN_low;
  uint totalizerIN_high;
  uint totalizerOUT_low;
  uint totalizerOUT_high;


  //! ------------------------------------------------------------------------
  //! system control statuses: previous! !!! 
  //! ------------------------------------------------------------------------
  bool start_plant_stat;//! system start signal confirmation from PLC
  bool stop_plant_stat; //! system stop signal confirmation from PLC
  bool error_ack_stat;  //! PLC error acknowledgment confirmation from PLC
  bool pc_reboot_stat;  //! confirmation signal from PLC: touchscreen was rebooted
  bool save_data_stat;  //! confirmation signal from PLC: data was saved into PLC memory
  
  //TEST
  bool bl1a_started;
  bool lift_station;
  bool lift_eth;

} plc_to_pvs_t;


typedef struct pvs_to_plc {
  
  bool	update;		 //! sending new package to plc flag
  
  const char *value;
  
  int dosing_rate;
  
  int pvs_flow_dependant;
  
  int pvs_pH_dependant;

  int pvs_save_config;

  // new added below!!!!!!!
  bool system_auto_mode;
  bool system_service_mode; 

  //p3 word 4 - 9
  int max_magmIN_flow;//in cubic meters per hour
  int magmIN_pulse_value;// in L
  int max_magmOUT_flow;//in cubic meters per hour
  int magmOUT_pulse_value;// in L
  int short_flush_time;//in seconds
  int long_flush_time;//in seconds

  //p4 word 1
  bool sol_S1_Man;// solenoid 1 on in manual mode
  bool sol_S2_Man;
  bool sol_S3_Man;
  bool sol_S4_Man;
  bool sol_S5_Man;
  bool sol_S6_Man;
  bool sol_S7_Man;
  bool sol_S8_Man;
  bool sol_S9_Man;
  bool sol_SA1_Man;// solenoid A1(first set including two solenoids) in manual mode
  bool sol_SA2_Man;// solenoid A2(second set including two solenoids) in manual mode
  bool dp_Man;// dosing pump in manual mode

  
} pvs_to_plc_t;

//! interprocess-visible global variables
typedef struct global_flags {
   int block_ui;
   int run_serv;
   int conf_err;
   int stpIPerr;
   int stop_app;
   int cur_mask;
   int pre_mask;
   long int debug_on;
   
} global_flags_t;

extern global_flags_t *globs;

extern plc_to_pvs_t *stp2pvs; 
extern pvs_to_plc_t *pvs2stp;


//!****************************************************************************
//! EVENTS shared memory structures used for Biocompact Systems: start
//!****************************************************************************
//! event-stucture, processing by pv-server
typedef struct event_request {
  int   event_id;           //! event identificator (see dispatcher.h)
  int   event_go;           //! flag for activation event

  char  eve_info[_SIZE_HK]; //! event-specific additional info
  int   event_val;
} event_request_t;

//! event-stucture, processing by dispatcher
typedef struct event_dsptch {
  int           event_id;
  int           event_type;//! for table & log - messages ui-type defines:
                           //!  a) ui-type of message (info/warning/alert);
                           //!  b) print location (table/logfile/both).
  const char   *event_msg; //! the message used for event activation
  const char   *back_msg;  //! the message used for de-activativation
                           //! event (if needed)

  int           event_val; //! integer value, might be used by event API
  int           event_run; //! activation status of the event

  unsigned long timer;     //! time in sec should pass for event activation 
  unsigned long eve_init;  //! time in sec of initializing event request 
  unsigned long eve_start; //! time record in sec of the first activation
  unsigned long eve_cycle; //! activation period in sec if event_go is true
   
} event_dsptch_t;


extern event_request_t *eve_request[]; //!'ro' for dispatcher; 'wr' for pvs
extern event_dsptch_t  *eve_proceed[]; //!'ro' for pvs; 'wr' for dispatcher


extern int save_bio_c_conf_bin();
extern int save_bio_c_conf_int();

extern int save_bin_config_csv();
extern int save_int_config_csv();