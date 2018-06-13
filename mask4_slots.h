//###############################################################
//# mask4_slots.h for ProcessViewServer created: Tue Mar 24 09:21:00 2018
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
#include <time.h>
#include <sys/time.h>
#include <sys/wait.h>  
#include "shamemchl.h"
#include "logger.h"
#include "dispatcher.h"

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_COLS       4
#define MAX_ROWS_INFO_TBL  100

#define SEL_COLOR    193,169,211
#define MSGFILE                  "./CSV/msg_table.csv"

enum {
  NUM_COLUMN = -1,
  IMG_COLUMN = 0,
  MSG_COLUMN,
  TIME_COLUMN,
  CHK_COLUMN
};


typedef struct // (todo: define your data structure here)
{
  ClientSession session;
}
DATA;

//!****************************************************************************
static void show_row_by_index(PARAM *p, DATA *d, int i)
{
  const char *buf    = "color(%d,%d,%d)";
  char msg_buf[256]  = "color(%d,%d,%d)";
  char time_buf[256] = "color(%d,%d,%d)";
  int selected = -1, msg_type = -1, active_service = 0;
  
  if (p == NULL) return;
  
  /*active_service = (d->session.client->service_mode == OPERATING ||
                    d->session.client->service_mode == SERVICE);
  */
  //????
  //have issue when use (msg_tbl->rows[i]).msg_type, it shows constructing widget tree
  printf("active_service is %d\n", active_service);
  if ((msg_tbl->rows[i]).msg_type != LOG_UNDEFINED){

     strcat (msg_buf,  (msg_tbl->rows[i]).msg);
     strcat (time_buf, (msg_tbl->rows[i]).time_txt);

     msg_type = (msg_tbl->rows[i]).msg_type;
     selected = (msg_tbl->rows[i]).selected;
     
     //+++++
     //pvSetTablePixmap  (p,tblMsgList, IMG_COLUMN, i, msg_imgs[msg_type]);
     if (active_service){
        pvSetTableCheckBox(p,tblMsgList, CHK_COLUMN, i, selected, "");
     }
     
     if (selected == 1 && active_service){
        pvTablePrintf(p, tblMsgList, IMG_COLUMN,  i, buf,      SEL_COLOR);
        pvTablePrintf(p, tblMsgList, MSG_COLUMN,  i, msg_buf,  SEL_COLOR);
        pvTablePrintf(p, tblMsgList, TIME_COLUMN, i, time_buf, SEL_COLOR);
     } else {
        pvTablePrintf(p, tblMsgList, IMG_COLUMN,  i, buf,      WHITE);
        pvTablePrintf(p, tblMsgList, MSG_COLUMN,  i, msg_buf,  WHITE);
        pvTablePrintf(p, tblMsgList, TIME_COLUMN, i, time_buf, WHITE);
     }
  } else {
        pvSetRowHeight  (p, tblMsgList,             i, -1);
        pvSetTablePixmap(p, tblMsgList, IMG_COLUMN, i, msg_imgs[0]);
        pvTablePrintf   (p, tblMsgList, IMG_COLUMN, i, buf,      WHITE);
        pvTablePrintf   (p, tblMsgList, MSG_COLUMN, i, msg_buf,  WHITE);
        pvTablePrintf   (p, tblMsgList, TIME_COLUMN,i, time_buf, WHITE);
        pvSetTableLabel (p, tblMsgList, CHK_COLUMN, i, "");
  }
  
}

//!****************************************************************************
static int slotInit(PARAM *p, DATA *d)
{
  if (p == NULL || d == NULL) return -1;

  memset(d,0,sizeof(DATA));
  //++++++
  //init_user_session(p, &(d->session));
  
  pvResize(p,0,800,600);
  pvSetNumCols(p, tblMsgList, NUM_COLS);
  
  pvSetColumnWidth(p, tblMsgList, IMG_COLUMN,  24);
  pvSetColumnWidth(p, tblMsgList, MSG_COLUMN,  486);
  pvSetColumnWidth(p, tblMsgList, TIME_COLUMN, 140);
  pvSetColumnWidth(p, tblMsgList, CHK_COLUMN,  24);
  pvHide(p,tblMsgList);
  //! avoid updates
  pvCSVdump(p, tblMsgList, MSGFILE, '\t');
  
  
  //+++++  problem always build the widget trees!!
  //for (int i = 0; i < msg_tbl->rows_num; i++){
  //for (int i = 0; i < 3; i++){
     //printf ("msg_tbl->rows_num = %d\n",msg_tbl->rows_num);
      //pvSetRowHeight(p, tblMsgList, 1, 30);
      //++++ temperary commented, i -> 1   ???
      show_row_by_index(p, d, 2);
  //}
  printf("show_row_by_index is called\n");
  //+++++++
  pvShow(p,tblMsgList);
  //testing code
  ///++++++this code cause the problem, always build the widget trees
  //! for the case when we have critical configuration errors
  /*if (scada_cannot_be_started()){
     pvMessageBox(p,-1,BoxCritical,MSG_SCADA_NOT_CONFIGURED,MessageBoxOk,0,0);
  } else if (globs->stop_app){
     pvMessageBox(p,-1,BoxCritical,MSG_SCADA_WAS_STOPPED,MessageBoxOk,0,0);
  }
  */
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
  return 0;
}

static int slotButtonPressedEvent(PARAM *p, int id, DATA *d)
{
  if(p == NULL || id == 0 || d == NULL) return -1;
  int ret = 0;
  if (id == btnGoBack){
    //event_request(EVE_EXIT_MESSAGES_TABLE, INIT_EVENT);
    ret = 1;
  }
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
  if (x == CHK_COLUMN){
     if (text[0] == '0'){
        (msg_tbl->rows[y]).selected = 0;
     } else if (text[0] == '1'){
        (msg_tbl->rows[y]).selected = 1;
     }
     show_row_by_index(p, d, y);
  }
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
