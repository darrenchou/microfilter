//###############################################################
//# mask1_slots.h for ProcessViewServer created: Mon Oct 23 14:34:27 2017
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

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#include <signal.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "shamemchl.h"
#include "oscadaserv.h"
#include "osornoconf.h"

#define MAX_MAN_UI_DEV_NUM 9 //! number of manualy operated devices shown in UI
//! possible device's states:
enum {
   DEVICE_NOSIGN = 0, //! no signal available 
   DEVICE_ACTIVE,     //! device is active
   
   //! if device has more than one active state:
   DEVICE_STATE_1,    //! device is in an active state #1
   DEVICE_STATE_2,    //! device is in an active state #2
   
   DEVICE_STANDBY,    //! device is inactive
   DEVICE_REQUEST,    //! device is in a waiting state
   DEVICE_ERROR,      //! device is in an error state
   MAX_DEVICE_STAT_NUM
};

enum {
   GR_NOGROUP = 0,
};
///state images for mask1 and mask7 
char* imgPressSw_List[MAX_STATS_NUM] = {
   (char *)IMG_PRESSW_INACTIVE,
   (char *)IMG_PRESSW_GREY,
   (char *)IMG_PRESSW_GREY,
   (char *)IMG_PRESSW_GREEN,
   (char *)IMG_PRESSW_GREY,
   (char *)IMG_PRESSW_RED,
   (char *)IMG_PRESSW_RED
};

char* imgLvlSw_List[MAX_STATS_NUM] = {
   (char *)IMG_LVL_SW_INACTIVE,
   (char *)IMG_LVL_SW_GREY_OP,
   (char *)IMG_LVL_SW_GREY_CL,
   (char *)IMG_LVL_SW_GREEN_OP,
   (char *)IMG_LVL_SW_GREEN_CL,
   (char *)IMG_LVL_SW_RED_CL,
   (char *)IMG_LVL_SW_RED_OP
};
/*
char* imgSens30_List[MAX_STATS_NUM] = {
   (char *)IMG_32_SENS_INACT,
   (char *)IMG_32_SENS_GRAY,
   (char *)IMG_32_SENS_GRAY,
   (char *)IMG_32_SENS_GREEN,
   (char *)IMG_32_SENS_GRAY,
   (char *)IMG_32_SENS_RED,
   (char *)IMG_32_SENS_RED
};
*/
char* imgSema24_List[MAX_STATS_NUM] = {
   (char *)IMG_24_SEM_INACT,
   (char *)IMG_24_SEM_GREY,
   (char *)IMG_24_SEM_BLGR,
   (char *)IMG_24_SEM_GREEN,
   (char *)IMG_24_SEM_GRGR,
   (char *)IMG_24_SEM_RED,
   (char *)IMG_24_SEM_RED
};
static dev_uistate_t manualUI_List[]= {
   //! dev_type      ui_id     state
   { DEV_SOL1   , { imgSolenoid_1_man  , 0 }},
   { DEV_SOL2   , { imgSolenoid_2_man  , 0 }},
   { DEV_SOL3   , { imgSolenoid_3_man  , 0 }},
   { DEV_SOL4   , { imgSolenoid_4_man  , 0 }},
   { DEV_SOL5   , { imgSolenoid_5_man  , 0 }},
   { DEV_SOL6   , { imgSolenoid_6_man  , 0 }},
   { DEV_SOL7   , { imgSolenoid_7_man  , 0 }},
   //{ DEV_SOL8   , { imgSolenoid_8_man  , 0 }},
   { DEV_SOL9   , { imgSolenoid_9_man  , 0 }},
   
   { DEV_DS_PUMP, { imgDosPump_man     , 0 }},
   { DUMMY_ID  , { DUMMY_ID   , 0 }}
};

typedef struct // (todo: define your data structure here)
{
}
DATA;

static int slotInit(PARAM *p, DATA *d)
{
  if(p == NULL || d == NULL) return -1;
  //memset(d,0,sizeof(DATA));
  return 0;
}

static int slotNullEvent(PARAM *p, DATA *d)
{
  if(p == NULL || d == NULL) return -1;

  char str_val[4] = "";
  if(stp2pvs->plc_magmeter_flow == 0)
    pvSetText(p, lblMagmeterValue, NOT_AVAILABLE); 
  else
  {
    if((stp2pvs->plc_magmeter_flow & 0xf000) == 0x0000)
    {
      unsigned int x = (stp2pvs->plc_magmeter_flow ) & 0x0fff;//get value from 0th to 12th bit
      sprintf(str_val,"%u", x);
      pvSetText(p, lblMagmeterValue, str_val); 
    }
    else pvSetText(p, lblMagmeterValue, "useless value"); 
  }

  unsigned long y = stp2pvs->plc_totalizer_high << 16 |  stp2pvs->plc_totalizer_low;
  if(y == 0)
    pvSetText(p, lblTotalizerValue, NOT_AVAILABLE); 
  else
  {
    sprintf(str_val,"%lu", y);
    pvSetText(p, lblTotalizerValue, str_val);   
  }

  return 0;
}

static int slotButtonEvent(PARAM *p, int id, DATA *d)
{
  int ret = 0;
  if(p == NULL || id == 0 || d == NULL) return -1;
  
  return ret;
}

static int slotButtonPressedEvent(PARAM *p, int id, DATA *d)
{
  if(p == NULL || id == 0 || d == NULL) return -1;
  int ret = 0;
  if(id == btnStartStop)
  {
     pvDownloadFile(p, "images/g.gif");
     pvSetImage(p, imgTest, "images/g.gif");
     
  }
  if (id == btnMessages)
  {
     ret = MASK_MESSAGES ;
  }
  if (id == btnLogout)
  {
     ret = MASK_SCADA_LOGIN ;
  }
  if(id == btnMainMenu)
  {
    ret = MASK_MAIN_MENU ;
  }
  if(id == btnGoCIP)
  {
    return MASK_CIP;
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
