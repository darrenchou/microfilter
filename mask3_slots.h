//###############################################################
//# mask3_slots.h for ProcessViewServer created: Fri Dec 15 13:15:09 2017
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



#include <cstdlib>

#include <sys/time.h>

#include "osornoconf.h"

#include "shamemchl.h"
#include "dispatcher.h"
#include "pvapp.h"

#define NUM_COLS            4
#define MAX_ROWS_SET_TBL    10
#define MAX_BIN_CONFIGS     30
#define MAX_INT_CONFIGS     50

#define SURE_TO_SAVE        "ATTENTION !!!\nAfter SAVING changes, OLD SETTINGS will be LOST!\nAre you SURE TO SAVE new Configuration settings ?"
#define CONFIG_CORRUPTED    "ATTENTION !!!\nConfiguration Data files *.CSV are CORRUPTED !\nPlease ask for technical support."
#define CHANGES_ARE_ELIGIBLE "Some of New Config Settings are not applicable!\nPlease check Message Table for detailes."
#define NO_CHANGES_IN_CONFIG "No changes in Configuration Settings were done."
#define DOWN_LBL            "[ - ]"
#define UP_LBL              "[+]"

#define SEL_COLOR    143,169,211


typedef struct {

  int cur_enblstat_savebtn;
  int cur_enblstat_undobtn;
  
  int cur_increment;

  int request_activated;
  int config_was_saved;
}
DATA;

enum {
  NUM_COLUMN = -1,
  IMG_COLUMN = 0,
  MSG_COLUMN,
  TIME_COLUMN,
  CHK_COLUMN
};

//! boolean config options: table columns indexes
enum {
  BIN_CONFIG_NAME = 0,
  BIN_CONFIG_VALUE,
  BIN_CONFIG_ON_OFF,
  BIN_CONFIG_DESCR,
  
  NUM_BIN_CONFIG_COLUMNS
};

//! integer config options: table columns indexes
enum {
  INT_CONFIG_NAME = 0,
  INT_CONFIG_VALUE,
  INT_CONFIG_VAL_DOWN,
  INT_CONFIG_VAL_UP,
  INT_CONFIG_DESCR,
  
  NUM_INT_CONFIG_COLUMNS
};


//!****************************************************************************
static int init_mask_DATA(DATA *d)
{
  if(d == NULL) return 0;
  
  d->cur_enblstat_savebtn = 0;
  d->cur_enblstat_undobtn = 0;

  d->request_activated = 0;
  d->config_was_saved  = 0;

  return 1;
}

//!****************************************************************************
static int slotInit(PARAM *p, DATA *d)
{
  int val = 0, enbl = 0;

  if(p == NULL || d == NULL) return -1;
  memset(d,0,sizeof(DATA));
  map_cur_config_values_to_new();

  pvHide(p, lblSaving);
  
  pvSetGeometry(p, lblSaving, 300,612,200,40);
  
  pvHide(p,tblConfigBool);
  pvHide(p,tblConfigInt); 

  pvCSVdump(p,tblConfigBool,BIN_CONFIG_CSV,';');//get data from csv file
  pvCSVdump(p,tblConfigInt, INT_CONFIG_CSV,';');
  
  if (init_mask_DATA(d) == 0){
     pvMessageBox(p,-1,BoxCritical,CONFIG_CORRUPTED,MessageBoxOk,0,0);
     return MASK_SCHEMATIC;
  }
  
  pvSetEditable(p, tblConfigBool, 0);
  pvSetEditable(p, tblConfigInt, 0);

  //! the last option 'CONFIG_FORCE' should not be represented in the table
  for (int i = 0; i < NUM_CONFIG_BIN - 1; i++){
     
     val = bin_opts[i]->cur_val;
     printf("bin_opts[i]->cur_val: %s = %d\n", bin_opts[i]->name, val);
     if (!bin_opts[i]->fixed){
        pvSetTableCheckBox(p, tblConfigBool,BIN_CONFIG_ON_OFF,i,val,"");
     }
     pvSetTableText(p, tblConfigBool, BIN_CONFIG_ON_OFF,i,"");
     
     pvSetColumnWidth(p, tblConfigBool, BIN_CONFIG_NAME,  120);
     pvSetColumnWidth(p, tblConfigBool, BIN_CONFIG_VALUE, 80);
     pvSetColumnWidth(p, tblConfigBool, BIN_CONFIG_ON_OFF,40);
     pvSetColumnWidth(p, tblConfigBool, BIN_CONFIG_DESCR, 430);
     
     for (int j = 0; j < NUM_BIN_CONFIG_COLUMNS; j++){
         enbl = (j == BIN_CONFIG_ON_OFF && !bin_opts[i]->fixed)? 1: 0;
         if (enbl){
            pvTableSetEnabled(p, tblConfigBool, j, i, enbl);
         }
     }
  }
  
  for (int i = 0; i < NUM_CONFIG_INT; i++){
     pvSetTableText(p, tblConfigInt, INT_CONFIG_VAL_DOWN, i, "");
     pvSetTableText(p, tblConfigInt, INT_CONFIG_VAL_UP,   i, "");
     
     if (!int_opts[i]->fixed){
        pvSetTableButton(p, tblConfigInt, INT_CONFIG_VAL_DOWN, i, DOWN_LBL);  
        pvSetTableButton(p, tblConfigInt, INT_CONFIG_VAL_UP  , i, UP_LBL);  
     }
     pvSetColumnWidth(p, tblConfigInt, INT_CONFIG_NAME,    120);
     pvSetColumnWidth(p, tblConfigInt, INT_CONFIG_VALUE,   80);
     pvSetColumnWidth(p, tblConfigInt, INT_CONFIG_VAL_DOWN,40);
     pvSetColumnWidth(p, tblConfigInt, INT_CONFIG_VAL_UP,  40);
     pvSetColumnWidth(p, tblConfigInt, INT_CONFIG_DESCR,   390);

     for (int j = 0; j < NUM_INT_CONFIG_COLUMNS; j++){
         enbl = ((j == INT_CONFIG_VAL_DOWN || j == INT_CONFIG_VAL_UP)
                  && !int_opts[i]->fixed)? 1: 0;
         if (enbl){
            pvTableSetEnabled(p, tblConfigInt, j, i, enbl);
         }
     }
  }

  pvSetEnabled(p, btnSaveSettings, 0); 
  pvSetEnabled(p, btnOldSettings, 0);
  
  pvSetChecked(p, radioIncrement1, 1);
  d->cur_increment = 1;

  pvShow(p,tblConfigBool); 
  pvShow(p,tblConfigInt); 
  
  return 0;
}

#if 0
static int slotInit(PARAM *p, DATA *d)
{
  ConnectedClient *client = NULL;

  if (p == NULL || d == NULL) return -1;

  memset(d,0,sizeof(DATA));
  
  gettimeofday(&(d->last_time_active), 0);

  client = (ConnectedClient *)(p->user);
  d->service_mode = client->service_mode;

  if (strcmp(client->ip_adr, LOCAL_IP_ADR) == 0){
     d->connection_type = LOCAL_HOST;
  } else {
     d->connection_type = REMOTE_HOST;
  }
  
  pvResize(p,0,800,600);
  //pvSetNumRows(p, tblConfigList, msg_tbl->rows[_num);
  pvSetNumCols(p, tblConfigList, NUM_COLS);
  
  pvSetColumnWidth(p, tblConfigList, IMG_COLUMN,  24);
  pvSetColumnWidth(p, tblConfigList, MSG_COLUMN,  486);
  pvSetColumnWidth(p, tblConfigList, TIME_COLUMN, 140);
  pvSetColumnWidth(p, tblConfigList, CHK_COLUMN,  24);
  pvHide(p,tblConfigList);
  //! avoid updates
  pvCSVdump(p, tblConfigList, MSGFILE, '\t');

  for (int i = 0; i < msg_tbl->rows_num; i++){
      pvSetRowHeight(p, tblConfigList, i, 40);
      show_row_by_index(p, d, i);
  }
  
  pvShow(p,tblConfigList);  

  return 0;
}
#endif
//!****************************************************************************
static void rollback_config_setings(PARAM *p, DATA *d)
{
  char buff[256] = "";
  long int old_val = 0;
  
  if(p == NULL || d == NULL) return;

  for (int i = 0; i < NUM_CONFIG_BIN; i++){
      bin_opts[i]->new_val = bin_opts[i]->cur_val;
      
      if (!bin_opts[i]->fixed){
         sprintf(buff, "%d", bin_opts[i]->cur_val);
         pvSetTableText    (p, tblConfigBool, BIN_CONFIG_VALUE , i, buff);
         pvSetTableCheckBox(p, tblConfigBool, BIN_CONFIG_ON_OFF, i,
                                              bin_opts[i]->cur_val,"");
      }
  }
  for (int i = 0; i < NUM_CONFIG_INT; i++){
      old_val = int_opts[i]->cur_val;
      int_opts[i]->new_val = old_val;
      
      sprintf(buff,"%ld",old_val);
      pvSetTableText(p,tblConfigInt,INT_CONFIG_VALUE,i,buff);
  }
}

//!****************************************************************************
static void update_ui_mode(PARAM *p, DATA *d)
{
   if (d->request_activated){
      pvShow(p,tblConfigBool); 
      pvShow(p,tblConfigInt); 

      pvSetEnabled(p, btnSaveSettings, 0); 
      pvSetEnabled(p, btnOldSettings, 0);
   }
}

//!****************************************************************************
static int slotNullEvent(PARAM *p, DATA *d)
{
  int ret = 0;
  if(p == NULL || d == NULL) return -1;
  
  /*if (globs != NULL && globs->stop_app){
     ret = MASK_INFORMATION;
  }*/
  return ret;
}

//!****************************************************************************
static int slotButtonEvent(PARAM *p, int id, DATA *d)
{
  if(p == NULL || id == 0 || d == NULL) return -1;
  return 0;
}

//!****************************************************************************
static int slotButtonPressedEvent(PARAM *p, int id, DATA *d)
{
  if(p == NULL || id == 0 || d == NULL) return -1;
  
  if (id == btnGoBack){
     //map_cur_config_values_to_new();
     return MASK_MANUAL_OPER;
  }
  if (id == btnOldSettings){
     rollback_config_setings(p, d);
  }
     
  if (id == btnSaveSettings){
     //! In the following pvMessageBox(),"value of the clicked button
     //! is delivered in ’slotSliderEvent’." (pv-browser manual, p.95) 
     pvMessageBox(p,-1,BoxWarning,SURE_TO_SAVE,MessageBoxYes,MessageBoxNo,0);
     update_ui_mode(p, d);
  }
  return 0;
}

//!****************************************************************************
static int slotButtonReleasedEvent(PARAM *p, int id, DATA *d)
{
  if(p == NULL || id == 0 || d == NULL) return -1;
  return 0;
}

//!****************************************************************************
static int slotTextEvent(PARAM *p, int id, DATA *d, const char *text)
{
  if(p == NULL || id == 0 || d == NULL || text == NULL) return -1;
  return 0;
}

//!****************************************************************************
static int slotSliderEvent(PARAM *p, int id, DATA *d, int val)
{
  int save_status = 0;
  
  if(p == NULL || id == 0 || d == NULL || val < -1000) return -1;
  
  //! This event happened when the function pvMessageBox() with two buttons
  //! was called. In this case "value of the clicked button is delivered in 
  //! ’slotSliderEvent’."(from pv-browser manual,p.95)     

  if (val == 65536){ //! answer is 'No' 
     //! saving configuration changes was canceled by user
  } else if (val == 16384){ //! answer is 'Yes'
     //! check changes & eligibility and initiate EVE_CONFIG_UIMAN_TO_PLC event
//+++++++++++++++++++++++++
     save_status = ui_save_new_config_setings();  //++++previous comment
     if (save_status == -1){
        pvMessageBox(p,-1,BoxCritical,CHANGES_ARE_ELIGIBLE,MessageBoxOk,0,0);
        rollback_config_setings(p, d);
     } else if (save_status == 1){
        d->request_activated = 1;
     } else {
        pvMessageBox(p,-1,BoxWarning,NO_CHANGES_IN_CONFIG,MessageBoxOk,0,0);
     }
  }
  return 0;
}

//!****************************************************************************
static int slotCheckboxEvent(PARAM *p, int id, DATA *d, const char *text)
{
  if(p == NULL || id == 0 || d == NULL || text == NULL) return -1;
  return 0;
}

//!****************************************************************************
static int slotRadioButtonEvent(PARAM *p, int id, DATA *d, const char *text)
{
  if(p == NULL || id == 0 || d == NULL || text == NULL) return -1;
  
  switch (id){
     case radioIncrement1: d->cur_increment = 1;
          break;
     case radioIncrement2: d->cur_increment = 10;
          break;
     case radioIncrement3: d->cur_increment = 100;
          break;
     case radioIncrement4: d->cur_increment = 1000;
          break;
  }
  return 0;
}

//!****************************************************************************
static int slotGlInitializeEvent(PARAM *p, int id, DATA *d)
{
  if(p == NULL || id == 0 || d == NULL) return -1;
  return 0;
}

//!****************************************************************************
static int slotGlPaintEvent(PARAM *p, int id, DATA *d)
{
  if(p == NULL || id == 0 || d == NULL) return -1;
  return 0;
}

//!****************************************************************************
static int slotGlResizeEvent(PARAM *p, int id, DATA *d, int width, int height)
{
  if(p == NULL || id == 0 || d == NULL || width < 0 || height < 0) return -1;
  return 0;
}

//!****************************************************************************
static int slotGlIdleEvent(PARAM *p, int id, DATA *d)
{
  if(p == NULL || id == 0 || d == NULL) return -1;
  return 0;
}

//!****************************************************************************
static int slotTabEvent(PARAM *p, int id, DATA *d, int val)
{
  if(p == NULL || id == 0 || d == NULL || val < -1000) return -1;
  return 0;
}

//!****************************************************************************
static int slotTableTextEvent(PARAM *p, int id, DATA *d, int x, int y,
                                                         const char *text)
{
  char buff[256] = "";
  int  value = 0;
  
  if(p == NULL || id == 0 || d == NULL || x<-1000 || y<-1000 || text == NULL){
     return -1;
  }

  printf("mask3: slotTableTextEvent(): id = %d\n",id);
  if (id == tblConfigBool && x == BIN_CONFIG_ON_OFF){
     if (strcmp(text, "1,") == 0){
        if (bin_opts[y]->new_val == 0){
           pvSetTableText(p, id, BIN_CONFIG_VALUE, y, "1");
           bin_opts[y]->new_val = 1;
        } else {
           printf ("mask3: slotTableTextEvent() - new_value=0 DATA Error\n");
        }
     } else if(strcmp(text, "0,") == 0) {
        if (bin_opts[y]->new_val == 1){
           pvSetTableText(p, id, BIN_CONFIG_VALUE, y, "0");
           bin_opts[y]->new_val = 0;
        } else {
           printf ("mask3: slotTableTextEvent() - new_value=1 DATA Error\n");
        }
     }
  }
  if (id == tblConfigInt){
     if (x == INT_CONFIG_VAL_DOWN && strcmp(text, DOWN_LBL) == 0){
        if (int_opts[y]->new_val > int_opts[y]->lo_bound){
           value = int_opts[y]->new_val - (d->cur_increment);
           if (value >= int_opts[y]->lo_bound){
              printf ("mask3: slotTableTextEvent() - DOWN\n");
              int_opts[y]->new_val = value;

              sprintf(buff,"%ld",int_opts[y]->new_val);
              pvSetTableText(p, id, INT_CONFIG_VALUE, y, buff);
           }
        }
     }
     if (x == INT_CONFIG_VAL_UP && strcmp(text, UP_LBL) == 0){
        if (int_opts[y]->new_val < int_opts[y]->hi_bound){
           value = int_opts[y]->new_val + (d->cur_increment);
           if (value <= int_opts[y]->hi_bound){
              printf ("mask3: slotTableTextEvent() - UP\n");
              int_opts[y]->new_val = value;
           
              sprintf(buff,"%ld",int_opts[y]->new_val);
              pvSetTableText(p, id, INT_CONFIG_VALUE, y, buff);
           }
        }
     }
     printf("value = %ld\n",int_opts[y]->new_val);
  }
  return 0;
}

//!****************************************************************************
static int slotTableClickedEvent(PARAM *p, int id, DATA *d, int x, int y,
                                                                   int button)
{
  int ret = 0;
  if(p == NULL || id == 0 || d == NULL || x<-1000 || y<-1000 || button < 0){
     ret -1;
  }
  return ret;
}

//!****************************************************************************
static int slotSelectionEvent(PARAM *p, int id, DATA *d, int val, const char *text)
{
  if(p == NULL || id == 0 || d == NULL || val<-1000 || text == NULL) return -1;
  return 0;
}

//!****************************************************************************
static int slotClipboardEvent(PARAM *p, int id, DATA *d, int val)
{
  if(p == NULL || id == 0 || d == NULL || val < -1000) return -1;
  return 0;
}

//!****************************************************************************
static int slotRightMouseEvent(PARAM *p, int id, DATA *d, const char *text)
{
  if(p == NULL || id == 0 || d == NULL || text == NULL) return -1;
  //pvPopupMenu(p,-1,"Menu1,Menu2,,Menu3");
  return 0;
}

//!****************************************************************************
static int slotKeyboardEvent(PARAM *p, int id, DATA *d, int val, int modifier)
{
  int ret = 0;
  if(p == NULL || id == 0 || d == NULL || val < -1000 || modifier < -1000){
     ret = -1;
  }
  return ret;
}

//!****************************************************************************
static int slotMouseMovedEvent(PARAM *p, int id, DATA *d, float x, float y)
{
  if(p == NULL || id == 0 || d == NULL || x < -1000 || y < -1000) return -1;
  return 0;
}

//!****************************************************************************
static int slotMousePressedEvent(PARAM *p, int id, DATA *d, float x, float y)
{
  if(p == NULL || id == 0 || d == NULL || x < -1000 || y < -1000) return -1;
  return 0;
}

//!****************************************************************************
static int slotMouseReleasedEvent(PARAM *p, int id, DATA *d, float x, float y)
{
  if(p == NULL || id == 0 || d == NULL || x < -1000 || y < -1000) return -1;
  return 0;
}

//!****************************************************************************
static int slotMouseOverEvent(PARAM *p, int id, DATA *d, int enter)
{
  if(p == NULL || id == 0 || d == NULL || enter < -1000) return -1;
  return 0;
}

//!****************************************************************************
static int slotUserEvent(PARAM *p, int id, DATA *d, const char *text)
{
  if(p == NULL || id == 0 || d == NULL || text == NULL) return -1;
  return 0;
}
