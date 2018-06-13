/*****************************************************************************
 * bio_config.cpp
 *
 * Started   : Apr 03 11:06:30 2018
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

#include <cstdlib>

#include "pvapp.h"
#include "shamemchl.h"
#include "osornoconf.h"

#define BIN_CONFIG_HEADER  "Flag Option;Value;;Description\n"
#define INT_CONFIG_HEADER  "Config Option;Value;;;Description\n"

const char *configList[] = {
  
};

bool_config_t init_bin_opts[NUM_CONFIG_BIN] = {
  //! config name cur new fixed   description
  //!-------------------------------------------------------------------------
  //! external modules configuration
  // +++++ no need
  /*{ "build_alarms", 0, 0, 0, "Building Alarms are connected to PLC panel.\n"},//1
  { "water_plant" , 0, 0, 0, "Water Treatment Plant control is supported.\n"},
  { "ch1a_sensors", 0, 0, 0, "T-pH-ORP Sensors are present in Chamber 1A.\n"},
  { "ch1b_sensors", 0, 0, 0, "T-pH-ORP Sensors are present in Chamber 1B.\n"},
  { "ch_3_sensors", 0, 0, 0, "T-pH Sensors are present in Chamber 3 .\n"    },//5
  
  //! internal devices configuration
  { "lift_station", 0, 0, 0, "BioCompact System has Lift Station control.\n"},//1
  { "lift_st_eth" , 0, 0, 0, "Lift Station communication type: ethernet.\n" },
  { "lift_sensor" , 0, 0, 0, "Lift Station level sensor exists.\n"          },
  { "actuator_opt", 0, 0, 0, "Actuator is present in the System.\n"         },
  { "actuator_eth", 0, 0, 0, "Actuator communication type: ethernet.\n"     },
  { "magmeter_opt", 0, 0, 0, "Sewage Treatment Plant Magmeter is present.\n"},
  { "magmeter_eth", 0, 0, 0, "STP Magmeter communication type: ethernet.\n" },
  { "blower1a_opt", 0, 0, 0, "Blower-1A in Chamber 1A is present.\n"        },
  { "bl1a_3_phase", 0, 0, 0, "Blower-1A is using three phases option.\n"    },
  { "bl1a_s_start", 0, 0, 0, "Blower-1A is using soft start option.\n"      },
  { "bl1a_pres_sw", 0, 0, 0, "Blower-1A is using pressure switch option.\n" },
  { "blower1b_opt", 0, 0, 0, "Blower-1B in Chamber 1B is present.\n"        },
  { "bl1b_3_phase", 0, 0, 0, "Blower-1B is using three phases option.\n"    },
  { "bl1b_s_start", 0, 0, 0, "Blower-1B is using soft start option.\n"      },
  { "bl1b_pres_sw", 0, 0, 0, "Blower-1B is using pressure switch option.\n" },
  { "blower2_opt" , 0, 0, 0, "Blower-2 in Chamber 2 is present.\n"          },
  { "bl2_3_phase" , 0, 0, 0, "Blower-2 is using three phases option.\n"     },
  { "bl2_s_start" , 0, 0, 0, "Blower-2 is using soft start option.\n"       },
  { "bl2_pres_sw" , 0, 0, 0, "Blower-2 is using pressure switch option.\n"  },
  { "solenoid_opt", 0, 0, 0, "Solenoid is present in the System.\n"         },
  { "t3_sens_opt" , 0, 0, 0, "Tank 3 level sensor is present.\n"            },
  { "t3_sens_eth" , 0, 0, 0, "Level sensor communication type: ethernet.\n" },
  { "t3_low_opt"  , 1, 0, 1, "Tank 3 low-level  switch, - always must be present.\n"},
  { "t3_high_opt" , 1, 0, 1, "Tank 3 high-level switch, - always must be present.\n"},
  { "t3_pump1_opt", 0, 0, 0, "Tank 3 discharging pump 1 is present.\n"      },
  { "t3_pump2_opt", 0, 0, 0, "Tank 3 discharging pump 2 is present.\n"      },
  { "uv_unit_opt" , 0, 0, 0, "UV Unit is present in the System.\n"          },
  { "uv_unit_eth" , 0, 0, 0, "UV Unit communication type: ethernet.\n"      },
  { "flow_sw_opt" , 0, 0, 0, "Out-Flow Switch is present in the System.\n"  },//29
   
  //! other configuration options
  { "alter_blow_2", 0, 0, 0, "Alternation mode for blower 2 is on.\n"       },
  { "alter_pumps" , 0, 0, 0, "Alternation mode for discharging pumps.\n"    },
  { "show_lvlsens", 0, 0, 0, "Show in UI Level Sensor and Switches.\n"      },
  { "show_ch3_lvl", 0, 0, 0, "Show in UI tank 3 water Level Value.\n"       },
 

   //+++++++new added
  //++++++++
  /*{ "auto_mode"   , 0, 0, 0, "System is running in auto mode.\n"            },  //1
  { "service_mode", 0, 0, 0, "System is running in service mode.\n"         },
  { "service_accept", 0, 0, 0, "Service mode is accepted.\n"                },
  { "service_request", 0, 0, 0, "Service mode is requested.\n"              },*/
  //! config name      cur new fixed   description
  { "PS1_present"      , 0, 0, 1, "PS1 is present in the system.\n"              },
  { "PS2_present"      , 0, 0, 0, "PS1 is present in the system.\n"              },
  { "PS_AIR_present"   , 0, 0, 1, "PS_AIR is present in the system.\n"        },
  { "MagmIN_present"   , 0, 0, 0, "MagmIN is present in the system.\n"        },
  { "MagmOUT_present"  , 0, 0, 0, "MagmOUT is present in the system.\n"      },
  { "CIP_present"      , 1, 0, 0, "CIP is present in the system.\n"              },
  { "reservoir_present", 0, 0, 0, "reservoir is present in the system.\n"  },
  { "sol_S1_present"   , 1, 0, 1, "Solenoid 1 is present in the system.- always must be present.\n"    },
  { "sol_S2_present"   , 1, 0, 1, "Solenoid 2 is present in the system.- always must be present.\n"    },
  { "sol_S3_present"   , 1, 0, 1, "Solenoid 3 is present in the system.- always must be present.\n"    },
  { "sol_S4_present"   , 1, 0, 1, "Solenoid 4 is present in the system.- always must be present.\n"    },
  { "sol_S5_present"   , 1, 0, 1, "Solenoid 5 is present in the system.- always must be present.\n"    },
  { "sol_S6_present"   , 1, 0, 1, "Solenoid 6 is present in the system.- always must be present.\n"    },
  { "uF1_present"      , 1, 0, 0, "Micro filter set 1 is present in the system.\n"},
  { "uF2_present"      , 0, 0, 0, "Micro filter set 2 is present in the system.\n"},
  { "dp_present"       , 0, 0, 0, "Dosing pump is present in the system.\n"       },
  /*{ "sol_S1_Man" , 0, 0, 0, "Manual mode Solenoid 1 is present.          \n"},
  { "sol_S2_Man" , 0, 0, 0, "Manual mode Solenoid 2 is present.          \n"},
  { "sol_S3_Man" , 0, 0, 0, "Manual mode Solenoid 3 is present.          \n"},
  { "sol_S4_Man" , 0, 0, 0, "Manual mode Solenoid 4 is present.          \n"},
  { "sol_S5_Man" , 0, 0, 0, "Manual mode Solenoid 5 is present.          \n"},
  { "sol_S6_Man" , 0, 0, 0, "Manual mode Solenoid 6 is present.          \n"},
  { "sol_S7_Man" , 0, 0, 0, "Manual mode Solenoid 7 is present.          \n"},
  { "sol_S8_Man" , 0, 0, 0, "Manual mode Solenoid 8 is present.          \n"},
  { "sol_S9_Man" , 0, 0, 0, "Manual mode Solenoid 9 is present.          \n"},
  { "sol_SA1_Man" , 0, 0, 0, "Manual mode Solenoid A1 is present.        \n"},
  { "sol_SA2_Man" , 0, 0, 0, "Manual mode Solenoid A2 is present.        \n"},
  { "dp_Man"     , 0, 0, 0, "Manual mode dosing pump is present.         \n"},  //31 */

  { "config_force", 0, 0, 0, "Forces configuration changes on start.\n"     },
  
};

int_config_t init_int_opts[NUM_CONFIG_INT] = {
  //! config name cur new min max fixed      description
  /*{ "plant_id"    , 3, 0, 1,  3, 1, "The unique plant Identification number, - read only.\n" },//1
  { "offtime_bl1a", 0, 0, 1, 60, 0, "Break time for Blower 1A (minutes: 0-60).\n"            },
  { "ontime_bl1a" , 0, 0, 1, 60, 0, "Work  time for Blower 1A (minutes: 0-60).\n"            },
  { "offtime_bl1b", 0, 0, 1, 60, 0, "Break time for Blower 1B (minutes: 0-60).\n"            },
  { "ontime_bl1b" , 0, 0, 1, 60, 0, "Work  time for Blower 1B (minutes: 0-60).\n"            },
  { "offtime_bl2" , 0, 0, 1, 60, 0, "Break time for Blower #2 (minutes: 0-60).\n"            },
  { "ontime_bl2"  , 0, 0, 1, 60, 0, "Work  time for Blower #2 (minutes: 0-60).\n"            },
  { "t3sen_slope" , 0, 0, 0,2000,0, "Tank 3: lvl-Sensor hardware slope parameter (x10000).\n"},
  { "t3sen_offset", 0, 0,0,10000,0, "Tank 3: lvl-Sensor hardware offset parameter (x100).\n" },
  { "magm_minflow",100,0,50,200, 0, "Min Magmeter Flow (liters per hour).\n"                 },
  { "magm_maxflow", 0, 0, 1, 20, 0, "Max Magmeter Flow (cubic meters per hour).\n"           },
  { "magm_pulse"  , 0, 0, 1,100, 0, "Magmeter pulse value (liters per pulse).\n"             },
  { "t3_min_dist" , 0, 0,30,100, 0, "Tank 3: min distance from lvl-Sensor to water (cm).\n"  },
  { "t3_max_dist" , 0, 0,180,226,0, "Tank 3: max distance from lvl-Sensor to water (cm).\n"  },
  { "lift_mindist", 0, 0, 0,  0, 0, "Lift St: min distance from lvl-Sensor to water (cm).\n" },
  { "lift_maxdist", 0, 0, 0,  0, 0, "Lift St: max distance from lvl-Sensor to water (cm).\n" },
  { "act_step_delay",0,0,20,1000,0, "Actuator position changes delay (miliseconds).\n"       },
  { "act_low_flow", 0, 0, 0,100, 0, "Actuator low flow boundary in (cu.m. per hour)x10.\n"   },
  { "act_high_flow",0, 0, 0,100, 0, "Actuator high flow boundary in (cu.m. per hour)x10.\n"  },//19*/
  //new added ++++++++++
  //+++++++++
   //! config name      cur new min max fixed      description
  { "max_magmIN_flow",    100,0,50,100, 0, "Max In Magmeter Flow (cubic meters per hour).\n"  },//1
  { "magmIN_pulse_value", 100,0,50,100, 0, "MagmeterIN pulse value (liters per hour).\n"      },
  { "max_magmOUT_flow",   100,0,50,100, 0, "Max Out Magmeter Flow (cubic meters per hour).\n" },
  { "magmOUT_pulse_value",100,0,50,100, 0, "MagmeterOUT pulse value(liters per hour).\n"       },
  /*{ "totalizerIN_low",    100,0,50,200, 0, "Low Level of In Totalizer (Liters).\n"            },
  { "totalizerIN_high",   100,0,50,200, 0, "High Level of In Totalizer (Liters).\n"           }, 
  { "totalizerOUT_low",   100,0,50,200, 0, "Low Level of Out Totalizer (Liters).\n"           },
  { "totalizerOUT_high",  100,0,50,200, 0, "High Level of Out Totalizer (Liters).\n"          },//8 */
};

const char *IntConfigList[NUM_CONFIG_INT] = {
  /*"Plant ID",
  "Blower 1A offtime",
  "Blower 1A ontime",
  "Blower 1B offtime",
  "Blower 1B ontime",
  "Blower 2 offtime",
  "Blower 2 ontime",
  "Tank 3 lvl-Sensor slope parameter",
  "Tank 3 lvl-Sensor offset parameter",
  "Magmeter minimum flow",
  "Magmeter maximum flow",
  "Magmeter pulse",
  "Tank 3 min water distance",
  "Tank 3 max water distance",
  "Lift Station min water distance",
  "Lift Station max water distance",
  "Actuator step delay",
  "Actuator low flow boundary",
  "Actuator high flow boundary",*/
  //++++++new added
  "Magmeter in flow",
  "Magmeter in pulse",
  "Magmeter out flow",
  "Magmeter out pulse",
};

ip_config_t init_ip_opts[NUM_CONFIG_IP] = {
  { "scada_ip"  , NULL },
  { "stp_plc_ip", NULL },
  { "wtp_plc_ip", NULL },
  { "stp_mgm_ip", NULL },
  { "wtp_mgm_ip", NULL },
  { "sens_1_ip" , NULL },
  { "sens_2_ip" , NULL },
  { "sens_3_ip" , NULL },
  { "lift_st_ip", NULL } 
};

//bld_alrm_config_t bld_alrm_opts[NUM_EXTERN_INPUTS];

//!****************************************************************************
void init_ip_opts_tbl()
{
  for (int i = 0; i < NUM_CONFIG_IP; i++){
     strcpy((ip_opts[i])->name, init_ip_opts[i].name);
     ip_opts[i]->ip   = init_ip_opts[i].ip;
  }
}

//!****************************************************************************
void init_bin_opts_tbl()
{
  for (int i = 0; i < NUM_CONFIG_BIN; i++){
     strcpy((bin_opts[i])->name, init_bin_opts[i].name);
     bin_opts[i]->cur_val     = init_bin_opts[i].cur_val;
     bin_opts[i]->new_val     = init_bin_opts[i].new_val;
     bin_opts[i]->fixed       = init_bin_opts[i].fixed;
     strcpy((bin_opts[i])->description, init_bin_opts[i].description);
  }
}

//!****************************************************************************
void init_int_opts_tbl()
{
  for (int i = 0; i < NUM_CONFIG_INT; i++){
     strcpy((int_opts[i])->name, init_int_opts[i].name);
     int_opts[i]->cur_val     = init_int_opts[i].cur_val;
     int_opts[i]->new_val     = init_int_opts[i].new_val;
     int_opts[i]->lo_bound    = init_int_opts[i].lo_bound;
     int_opts[i]->hi_bound    = init_int_opts[i].hi_bound;
     int_opts[i]->fixed       = init_int_opts[i].fixed;
     strcpy((int_opts[i])->description, init_int_opts[i].description);
  }
}

//! saving boolean config options into the 'bin_config_tbl.csv' file
//!****************************************************************************
int save_bin_config_csv()
{
  char buff[256] = "";
  FILE *b_fp = NULL;

  b_fp = fopen(BIN_CONFIG_CSV,"w");
  if (b_fp == NULL)
     return 0;

  fprintf(b_fp,"%s",BIN_CONFIG_HEADER);
  
  //! the last option 'CONFIG_FORCE' should not be represented in config table
  for (int i = 0; i < NUM_CONFIG_BIN - 1; i++){
      sprintf(buff,"%ld",bin_opts[i]->cur_val);
      fprintf(b_fp,"%s;",bin_opts[i]->name);
      fprintf(b_fp,"%s; ;",buff);
      fprintf(b_fp,"%s",bin_opts[i]->description);
  }
  fclose(b_fp);

  return 1;
}

//! saving boolean config options into the 'bio_c.conf' - system config file
//!****************************************************************************
int save_bio_c_conf_bin()
{
  FILE *fp = NULL;
  char buf[64] = "";
  
  printf ("NUM_CONFIG_BIN = %d\n", NUM_CONFIG_BIN);
  for (int i = 0; i < NUM_CONFIG_BIN; i++){
     strcpy(buf, bin_opts[i]->name);
     if (!bin_opts[i]->fixed){
        printf("%d: %s = %ld\n", i, buf, bin_opts[i]->cur_val);
        cfg_setint(cfg, buf, bin_opts[i]->cur_val);
     } else {
        printf ("%d: %s = %d unchangeable\n", i, buf, bin_opts[i]->cur_val);
     }
  }

  fp = fopen(CONFIG_FILE, "w");
  if (fp == NULL){
     return 0;
  }
  cfg_print(cfg, fp);
  fclose(fp);
  
  return 1;
}

//! saving integer config options into the 'int_config_tbl.csv' file
//!****************************************************************************
int save_int_config_csv()
{
  char buff[256] = "";
  FILE *i_fp = NULL;

  i_fp = fopen(INT_CONFIG_CSV,"w");
  if (i_fp == NULL) return 0;

     fprintf(i_fp,"%s",INT_CONFIG_HEADER);
  
     for (int i = 0; i < NUM_CONFIG_INT; i++){
         sprintf(buff,"%ld",int_opts[i]->cur_val);
         fprintf(i_fp,"%s;",int_opts[i]->name);
         fprintf(i_fp,"%s;",buff);
         sprintf(buff,"%ld",int_opts[i]->lo_bound);
         fprintf(i_fp,"%s;",buff);
         sprintf(buff,"%ld",int_opts[i]->hi_bound);
         fprintf(i_fp,"%s;",buff);
         fprintf(i_fp,"%s" ,int_opts[i]->description);
    }
    fclose(i_fp);

  return 1;
}

//!****************************************************************************
//modify this !
int udjustable_min_max_int_option(int int_opt_id)
{
    /*(int_opt_id == T3_MIN_DIST  || int_opt_id == T3_MAX_DIST    ||
           int_opt_id == LIFT_MINDIST || int_opt_id == LIFT_MAXDIST   ||
           int_opt_id == MAGM_MAXFLOW || int_opt_id == MAGM_PULSE     ||
           int_opt_id == MAGM_MINFLOW || int_opt_id == ACT_STEP_DELAY ||
           int_opt_id == ACT_LOW_FLOW || int_opt_id == ACT_HIGH_FLOW  ||*/
           //new added
    return (int_opt_id == MAX_MAGMIN_FLOW   || int_opt_id == MAGMIN_PULSE_VALUE  ||
           int_opt_id == MAX_MAGMOUT_FLOW  || int_opt_id == MAGMOUT_PULSE_VALUE
           /*int_opt_id == TOTALIZERIN_LOW   || int_opt_id == TOTALIZERIN_HIGH    ||
           int_opt_id == TOTALIZEROUT_LOW  || int_opt_id == TOTALIZEROUT_HIGH  */   );

}

//! saving integer config options into the 'osorno.conf' - system config file
//!****************************************************************************
int save_bio_c_conf_int()
{
  FILE *fp = NULL;
  char buf[64] = "";

  printf ("NUM_CONFIG_INT = %d\n", NUM_CONFIG_INT);
  for (int i = 0; i < NUM_CONFIG_INT; i++){
     strcpy(buf, int_opts[i]->name);
     if (udjustable_min_max_int_option(i)){
        //! only current integer config option value might be changed in UI
        //! setup of other options (low,high bound) should be done manualy, -
        //! by editing the configuration file during the program instalation.
        if (!int_opts[i]->fixed){
           printf("%d: %s = {%ld, %ld, %ld}\n", i, buf, int_opts[i]->cur_val,
                                 int_opts[i]->lo_bound, int_opts[i]->hi_bound);
           cfg_setnint(cfg, int_opts[i]->name, int_opts[i]->cur_val, 0);
        } else {
           printf("%d: %s = {%ld, %ld, %ld} unchangeable\n", i, buf, 
           int_opts[i]->cur_val, int_opts[i]->lo_bound, int_opts[i]->hi_bound);
        }
     } else {
        if (!int_opts[i]->fixed){
           printf("%d: %s\t= %ld\n", i, buf ,int_opts[i]->cur_val);
           cfg_setint(cfg, int_opts[i]->name, int_opts[i]->cur_val);
        } else {
           printf("%d: %s\t= %ld unchangeable\n", i, buf ,int_opts[i]->cur_val);
        }
     }
  }
  
  fp = fopen(CONFIG_FILE, "w");
  if (fp == NULL)
     return 0;
  
  cfg_print(cfg, fp);
  fclose(fp);
  
  return 1;
}
/*
//! Building alarms:
//!****************************************************************************
void read_bld_alrm_stats()
{
  int alarm = 0;
printf("read_bld_alrm_stats(): step 01\n");
  
  if (stp2pvs->no_connection){
printf("read_bld_alrm_stats(): step 02\n");
     for (int i = 0; i < bld_alarms_num; i++){
         bld_alrm_opts[i].alarm_stat = BLD_STAT_UNDEF;
     }
  } else {
printf("read_bld_alrm_stats(): step 03\n");
     //! first just copy signals from OSAUT message
     bld_alrm_opts[INPUT_00].alarm_stat = stp2pvs->input_00;
     bld_alrm_opts[INPUT_01].alarm_stat = stp2pvs->input_01;
     bld_alrm_opts[INPUT_02].alarm_stat = stp2pvs->input_02;
     bld_alrm_opts[INPUT_03].alarm_stat = stp2pvs->input_03;
     bld_alrm_opts[INPUT_04].alarm_stat = stp2pvs->input_04;
     bld_alrm_opts[INPUT_05].alarm_stat = stp2pvs->input_05;
     bld_alrm_opts[INPUT_06].alarm_stat = stp2pvs->input_06;
     bld_alrm_opts[INPUT_07].alarm_stat = stp2pvs->input_07;
     bld_alrm_opts[INPUT_08].alarm_stat = stp2pvs->input_08;
     bld_alrm_opts[INPUT_09].alarm_stat = stp2pvs->input_09;
     bld_alrm_opts[INPUT_10].alarm_stat = stp2pvs->input_10;
     bld_alrm_opts[INPUT_11].alarm_stat = stp2pvs->input_11;
     bld_alrm_opts[INPUT_12].alarm_stat = stp2pvs->input_12;
     bld_alrm_opts[INPUT_13].alarm_stat = stp2pvs->input_13;
     bld_alrm_opts[INPUT_14].alarm_stat = stp2pvs->input_14;
     bld_alrm_opts[INPUT_15].alarm_stat = stp2pvs->input_15;
     bld_alrm_opts[INPUT_16].alarm_stat = stp2pvs->input_16;
     bld_alrm_opts[INPUT_17].alarm_stat = stp2pvs->input_17;
     bld_alrm_opts[INPUT_18].alarm_stat = stp2pvs->input_18;
     bld_alrm_opts[INPUT_19].alarm_stat = stp2pvs->input_19;
     bld_alrm_opts[INPUT_20].alarm_stat = stp2pvs->input_20;
     bld_alrm_opts[INPUT_21].alarm_stat = stp2pvs->input_21;
     bld_alrm_opts[INPUT_22].alarm_stat = stp2pvs->input_22;
     bld_alrm_opts[INPUT_23].alarm_stat = stp2pvs->input_23;
  
     for (int i = 0; i < bld_alarms_num; i++){
        alarm = bld_alrm_opts[i].alarm_stat;
        //! adjustment for streight/reverse logic of the alarm signal
        alarm = (bld_alrm_opts[i].reverse_logic)? !alarm: alarm;
        if (alarm){
           bld_alrm_opts[i].alarm_stat = BLD_STAT_ALRM;
        } else {
           //! if no alarm, - adjustment for normal activity of the signal:
           //! active signals will be shown in green, inactive in grey colors
           if (bld_alrm_opts[i].normal_inactive){
              bld_alrm_opts[i].alarm_stat = BLD_STAT_INAC;
           } else {
              bld_alrm_opts[i].alarm_stat = BLD_STAT_NORM;
           }
        }
     }
  }
}
*/
//! init_bld_alrm_conf() function should be processed just once, - during
//! SCADA configuration initializing the external inputs (building alarms)
//!****************************************************************************
/*
int init_bld_alrm_conf()
{
  char line[256]  = "";
  const char s[2] = ";";
  char *token     = NULL;
  int count       = 0;
  
  FILE *fp = fopen(BLD_ALARMS_CSV,"r");
  if (fp != NULL) {

     fgets(line, sizeof(line), fp); //! first line has column headers names
     for (int i = 0; i < NUM_EXTERN_INPUTS; i++){

        if (fgets(line, sizeof(line), fp)){
           
           //! get the first token - description of the alarm
           token = strtok(line, s);
           if (token != NULL){
              sprintf(bld_alrm_opts[i].alarm_name,"%s",token);
           } else {
              return 0;
           }
           //! get the second token - normal/reverse logic option of the alarm
           token = strtok(NULL, s);
           if (token != NULL){
                   bld_alrm_opts[i].reverse_logic = (bool)atoi(token);
           } else {
              return 0;
           }
           //! get the third token - normal inactive logic option of the alarm
           //! (the normal alarm state will be shown in grey rather in green)
           token = strtok(NULL, s);
           if (token != NULL){
                   bld_alrm_opts[i].normal_inactive = (bool)atoi(token);
           } else {
              return 0;
           }
           //! get the fourth token - acknowledgment needed option
           token = strtok(NULL, s);
           if (token != NULL){
                   bld_alrm_opts[i].alarm_ack = (bool)atoi(token);
           } else {
              return 0;
           }
           count++;
           
        } else {
           //! zero initialization members are out-of-use
           strcpy(bld_alrm_opts[i].alarm_name,"");
                bld_alrm_opts[i].reverse_logic   = 0;
                bld_alrm_opts[i].normal_inactive = 0;
                bld_alrm_opts[i].alarm_ack       = 0;
        }
        //! alarm status is a run-time data and will be processed
        //! every time the new OSAUT message is received
             bld_alrm_opts[i].alarm_stat = 0;
     }
     fclose(fp);
  } else {
     return 0;
  }
  
  return count;
}
*/