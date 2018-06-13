////////////////////////////////////////////////////////////////////////////
//
// show_mask3 for ProcessViewServer created: Fri Dec 15 13:15:09 2017
//
////////////////////////////////////////////////////////////////////////////
#include "pvapp.h"

// _begin_of_generated_area_ (do not edit -> use ui2pvc) -------------------

// our mask contains the following objects
enum {
  ID_MAIN_WIDGET = 0,
  frmBg,
  lblHeader,
  imgHeader,
  frmTopLine,
  frmBottomLine,
  tblConfigBool,
  btnGoBack,
  btnSaveSettings,
  btnOldSettings,
  tblConfigInt,
  lblSaving,
  frameIncrement,
  radioIncrement1,
  radioIncrement2,
  radioIncrement3,
  radioIncrement4,
  ID_END_OF_WIDGETS
};

// our mask contains the following widget names
  static const char *widgetName[] = {
  "ID_MAIN_WIDGET",
  "frmBg",
  "lblHeader",
  "imgHeader",
  "frmTopLine",
  "frmBottomLine",
  "tblConfigBool",
  "btnGoBack",
  "btnSaveSettings",
  "btnOldSettings",
  "tblConfigInt",
  "lblSaving",
  "frameIncrement",
  "radioIncrement1",
  "radioIncrement2",
  "radioIncrement3",
  "radioIncrement4",
  "ID_END_OF_WIDGETS",
  ""};

  static const char *toolTip[] = {
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  ""};

  static const char *whatsThis[] = {
  "",
  "",
  "",
  "images/osorno_logo.png",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "Increment",
  "",
  "",
  "",
  "",
  ""};

  static const int widgetType[ID_END_OF_WIDGETS+1] = {
  0,
  TQFrame,
  TQLabel,
  TQImage,
  TQFrame,
  TQFrame,
  TQTable,
  TQPushButton,
  TQPushButton,
  TQPushButton,
  TQTable,
  TQLabel,
  TQFrame,
  TQRadio,
  TQRadio,
  TQRadio,
  TQRadio,
  -1 };

static int generated_defineMask(PARAM *p)
{
  int w,h,depth;

  if(p == NULL) return 1;
  if(widgetName[0] == NULL) return 1; // suppress unused warning
  w = h = depth = strcmp(toolTip[0],whatsThis[0]);
  if(widgetType[0] == -1) return 1;
  if(w==h) depth=0; // fool the compiler
  pvStartDefinition(p,ID_END_OF_WIDGETS);

  pvQFrame(p,frmBg,0,NoFrame,Plain,0,1);
  pvSetGeometry(p,frmBg,1,1,800,600);
  pvSetPaletteBackgroundColor(p,frmBg,200,200,180);
  pvSetFont(p,frmBg,"Sans",10,0,0,0,0);

  pvQLabel(p,lblHeader,frmBg);
  pvSetGeometry(p,lblHeader,20,15,430,60);
  pvSetText(p,lblHeader,pvtr("System Configuration"));
  pvSetPaletteForegroundColor(p,lblHeader,120,120,70);
  pvSetFont(p,lblHeader,"Sans",28,0,0,0,0);

  pvDownloadFile(p,"images/osorno_logo.png");
  pvQImage(p,imgHeader,frmBg,"images/osorno_logo.png",&w,&h,&depth);
  pvSetGeometry(p,imgHeader,465,18,282,66);
  pvSetFont(p,imgHeader,"Sans",10,0,0,0,0);
  pvSetWhatsThis(p,imgHeader,pvtr("images/osorno_logo.png"));

  pvQFrame(p,frmTopLine,frmBg,HLine,Sunken,1,1);
  pvSetGeometry(p,frmTopLine,1,86,800,5);
  pvSetFont(p,frmTopLine,"Sans",10,0,0,0,0);

  pvQFrame(p,frmBottomLine,frmBg,HLine,Sunken,1,1);
  pvSetGeometry(p,frmBottomLine,1,541,800,5);
  pvSetFont(p,frmBottomLine,"Sans",10,0,0,0,0);

  pvQTable(p,tblConfigBool,frmBg,0,0);
  pvSetGeometry(p,tblConfigBool,39,99,720,210);
  pvSetFont(p,tblConfigBool,"Sans",10,0,0,0,0);

  pvQPushButton(p,btnGoBack,frmBg);
  pvSetGeometry(p,btnGoBack,620,552,140,35);
  pvSetText(p,btnGoBack,pvtr("Quit"));
  pvSetFont(p,btnGoBack,"Sans",12,0,0,0,0);

  pvQPushButton(p,btnSaveSettings,frmBg);
  pvSetGeometry(p,btnSaveSettings,40,552,140,35);
  pvSetText(p,btnSaveSettings,pvtr("Save Settings"));
  pvSetFont(p,btnSaveSettings,"Sans",11,0,0,0,0);

  pvQPushButton(p,btnOldSettings,frmBg);
  pvSetGeometry(p,btnOldSettings,195,552,140,35);
  pvSetText(p,btnOldSettings,pvtr("Undo Changes"));
  pvSetFont(p,btnOldSettings,"Sans",11,0,0,0,0);

  pvQTable(p,tblConfigInt,frmBg,0,0);
  pvSetGeometry(p,tblConfigInt,40,320,720,210);
  pvSetFont(p,tblConfigInt,"Sans",10,0,0,0,0);

  pvQLabel(p,lblSaving,frmBg);
  pvSetGeometry(p,lblSaving,300,312,200,40);
  pvSetText(p,lblSaving,pvtr(" saving new settings..."));
  pvSetPaletteBackgroundColor(p,lblSaving,200,200,180);
  pvSetFont(p,lblSaving,"Sans",13,0,0,0,0);
  pvSetStyle(p,lblSaving,Box,-1,-1,-1);

  pvQFrame(p,frameIncrement,frmBg,Panel,Sunken,1,1);
  pvSetGeometry(p,frameIncrement,352,552,250,35);
  pvSetFont(p,frameIncrement,"Sans",10,0,0,0,0);
  pvSetWhatsThis(p,frameIncrement,pvtr("Increment"));

  pvQRadioButton(p,radioIncrement1,frameIncrement);
  pvSetGeometry(p,radioIncrement1,6,6,40,25);
  pvSetText(p,radioIncrement1,pvtr("1"));
  pvSetFont(p,radioIncrement1,"Sans",11,0,0,0,0);

  pvQRadioButton(p,radioIncrement2,frameIncrement);
  pvSetGeometry(p,radioIncrement2,57,6,50,25);
  pvSetText(p,radioIncrement2,pvtr("10"));
  pvSetFont(p,radioIncrement2,"Sans",11,0,0,0,0);

  pvQRadioButton(p,radioIncrement3,frameIncrement);
  pvSetGeometry(p,radioIncrement3,112,6,60,25);
  pvSetText(p,radioIncrement3,pvtr("100"));
  pvSetFont(p,radioIncrement3,"Sans",11,0,0,0,0);

  pvQRadioButton(p,radioIncrement4,frameIncrement);
  pvSetGeometry(p,radioIncrement4,180,6,68,25);
  pvSetText(p,radioIncrement4,pvtr("1000"));
  pvSetFont(p,radioIncrement4,"Sans",11,0,0,0,0);


  pvEndDefinition(p);
  return 0;
}

// _end_of_generated_area_ (do not edit -> use ui2pvc) ---------------------

#include "mask3_slots.h"

#include <stdlib.h>
#include <unistd.h>

//!****************************************************************************
static int defineMask(PARAM *p)
{
  if(p == NULL) return 1;
  generated_defineMask(p);
  // (todo: add your code here)
  return 0;
}

//!****************************************************************************
static int showData(PARAM *p, DATA *d)
{
  int data_changed = 0, eve_id = 0;
  int connected    = !stp2pvs->no_connection;
  static int prev_activated = 0;
  
  if(p == NULL || d == NULL) return 1;
  
  if (d->request_activated && !prev_activated){
     pvSetGeometry(p, lblSaving, 300,312,200,40);
     pvShow(p, lblSaving);    
     pvSetEnabled(p,tblConfigBool, 0); 
     pvSetEnabled(p,tblConfigInt, 0); 
     pvSetEnabled(p, btnSaveSettings, 0); 
     pvSetEnabled(p, btnOldSettings, 0);
     prev_activated = 1;
      
  } else if (!d->request_activated && prev_activated){
     pvHide(p, lblSaving);
     pvSetGeometry(p, lblSaving, 300,612,200,40);
     pvSetEnabled(p,tblConfigBool, 1); 
     pvSetEnabled(p,tblConfigInt, 1); 
     prev_activated = 0;
     
  } else {
     data_changed = config_has_new_settings();
     //!-----------------------------------------------------------------  
     //! Save Settings button
     //!-----------------------------------------------------------------
     if (data_changed && d->cur_enblstat_savebtn == 0){
        d->cur_enblstat_savebtn = 1;
        pvSetEnabled(p, btnSaveSettings, 1); 
     } else if(!data_changed && d->cur_enblstat_savebtn == 1) {
        d->cur_enblstat_savebtn = 0;
        pvSetEnabled(p, btnSaveSettings, 0); 
     }
     //!-----------------------------------------------------------------  
     //! Undo Changes button
     //!-----------------------------------------------------------------
     if (d->config_was_saved == 1){
        pvHide(p, btnOldSettings);
     } else if (data_changed && d->cur_enblstat_undobtn == 0){
        d->cur_enblstat_undobtn = 1;
        pvSetEnabled(p, btnOldSettings, 1);
     } else if(!data_changed && d->cur_enblstat_undobtn == 1) {
        d->cur_enblstat_undobtn = 0;
        pvSetEnabled(p, btnSaveSettings, 0); 
        pvSetEnabled(p, btnOldSettings, 0);
     }
  }
  if (d->request_activated){
     eve_id = (connected)? EVE_CONFIG_UIMAN_TO_PLC: EVE_NEW_CONFIG_SAVED;
     //+++++++++  comment
     if (get_event_proceeded_status(eve_id) == NO_EVENT){
        // update ui according new changes !!!!
        d->request_activated = 0;
        d->config_was_saved  = 1;
     }
     
  }
  
  return 0;
}

//!****************************************************************************
static int readData(DATA *d) // from shared memory, database or something else
{
  if(d == NULL) return 1;
  // (todo: add your code here)
  return 0;
}

//!****************************************************************************
int show_mask3(PARAM *p)
{
  DATA d;
  char event[MAX_EVENT_LENGTH];
  char text[MAX_EVENT_LENGTH];
  char str1[MAX_EVENT_LENGTH];
  int  i,w,h,val,x,y,button,ret;
  float xval, yval;

  defineMask(p);
  //rlSetDebugPrintf(1);
  if((ret=slotInit(p,&d)) != 0) return ret;
  readData(&d); // from shared memory, database or something else
  //+++++
  showData(p,&d);
  pvClearMessageQueue(p);
  while(1)
  {
    pvPollEvent(p,event);
    switch(pvParseEvent(event, &i, text))
    {
      case NULL_EVENT:
        readData(&d); // from shared memory, database or something else
        //++++++++++ comment
        //reset_resolved_event_requests();
        //+++++++++
        showData(p,&d);
        if((ret=slotNullEvent(p,&d)) != 0) return ret;
        break;
      case BUTTON_EVENT:
        if(trace) printf("BUTTON_EVENT id=%d\n",i);
        if((ret=slotButtonEvent(p,i,&d)) != 0) return ret;
        break;
      case BUTTON_PRESSED_EVENT:
        if(trace) printf("BUTTON_PRESSED_EVENT id=%d\n",i);
        if((ret=slotButtonPressedEvent(p,i,&d)) != 0) return ret;
        break;
      case BUTTON_RELEASED_EVENT:
        if(trace) printf("BUTTON_RELEASED_EVENT id=%d\n",i);
        if((ret=slotButtonReleasedEvent(p,i,&d)) != 0) return ret;
        break;
      case TEXT_EVENT:
        if(trace) printf("TEXT_EVENT id=%d %s\n",i,text);
        if((ret=slotTextEvent(p,i,&d,text)) != 0) return ret;
        break;
      case SLIDER_EVENT:
        sscanf(text,"(%d)",&val);
        if(trace) printf("SLIDER_EVENT val=%d\n",val);
        if((ret=slotSliderEvent(p,i,&d,val)) != 0) return ret;
        break;
      case CHECKBOX_EVENT:
        if(trace) printf("CHECKBOX_EVENT id=%d %s\n",i,text);
        if((ret=slotCheckboxEvent(p,i,&d,text)) != 0) return ret;
        break;
      case RADIOBUTTON_EVENT:
        if(trace) printf("RADIOBUTTON_EVENT id=%d %s\n",i,text);
        if((ret=slotRadioButtonEvent(p,i,&d,text)) != 0) return ret;
        break;
      case GL_INITIALIZE_EVENT:
        if(trace) printf("you have to call initializeGL()\n");
        if((ret=slotGlInitializeEvent(p,i,&d)) != 0) return ret;
        break;
      case GL_PAINT_EVENT:
        if(trace) printf("you have to call paintGL()\n");
        if((ret=slotGlPaintEvent(p,i,&d)) != 0) return ret;
        break;
      case GL_RESIZE_EVENT:
        sscanf(text,"(%d,%d)",&w,&h);
        if(trace) printf("you have to call resizeGL(w,h)\n");
        if((ret=slotGlResizeEvent(p,i,&d,w,h)) != 0) return ret;
        break;
      case GL_IDLE_EVENT:
        if((ret=slotGlIdleEvent(p,i,&d)) != 0) return ret;
        break;
      case TAB_EVENT:
        sscanf(text,"(%d)",&val);
        if(trace) printf("TAB_EVENT(%d,page=%d)\n",i,val);
        if((ret=slotTabEvent(p,i,&d,val)) != 0) return ret;
        break;
      case TABLE_TEXT_EVENT:
        sscanf(text,"(%d,%d,",&x,&y);
        pvGetText(text,str1);
        if(trace) printf("TABLE_TEXT_EVENT(%d,%d,\"%s\")\n",x,y,str1);
        if((ret=slotTableTextEvent(p,i,&d,x,y,str1)) != 0) return ret;
        break;
      case TABLE_CLICKED_EVENT:
        sscanf(text,"(%d,%d,%d)",&x,&y,&button);
        if(trace) printf("TABLE_CLICKED_EVENT(%d,%d,button=%d)\n",x,y,button);
        if((ret=slotTableClickedEvent(p,i,&d,x,y,button)) != 0) return ret;
        break;
      case SELECTION_EVENT:
        sscanf(text,"(%d,",&val);
        pvGetText(text,str1);
        if(trace) printf("SELECTION_EVENT(column=%d,\"%s\")\n",val,str1);
        if((ret=slotSelectionEvent(p,i,&d,val,str1)) != 0) return ret;
        break;
      case CLIPBOARD_EVENT:
        sscanf(text,"(%d",&val);
        if(trace) printf("CLIPBOARD_EVENT(id=%d)\n",val);
        if(trace) printf("clipboard = \n%s\n",p->clipboard);
        if((ret=slotClipboardEvent(p,i,&d,val)) != 0) return ret;
        break;
      case RIGHT_MOUSE_EVENT:
        if(trace) printf("RIGHT_MOUSE_EVENT id=%d text=%s\n",i,text);
        if((ret=slotRightMouseEvent(p,i,&d,text)) != 0) return ret;
        break;
      case KEYBOARD_EVENT:
        sscanf(text,"(%d",&val);
        if(trace) printf("KEYBOARD_EVENT modifier=%d key=%d\n",i,val);
        if((ret=slotKeyboardEvent(p,i,&d,val,i)) != 0) return ret;
        break;
      case PLOT_MOUSE_MOVED_EVENT:
        sscanf(text,"(%f,%f)",&xval,&yval);
        if(trace) printf("PLOT_MOUSE_MOVE %f %f\n",xval,yval);
        if((ret=slotMouseMovedEvent(p,i,&d,xval,yval)) != 0) return ret;
        break;
      case PLOT_MOUSE_PRESSED_EVENT:
        sscanf(text,"(%f,%f)",&xval,&yval);
        if(trace) printf("PLOT_MOUSE_PRESSED %f %f\n",xval,yval);
        if((ret=slotMousePressedEvent(p,i,&d,xval,yval)) != 0) return ret;
        break;
      case PLOT_MOUSE_RELEASED_EVENT:
        sscanf(text,"(%f,%f)",&xval,&yval);
        if(trace) printf("PLOT_MOUSE_RELEASED %f %f\n",xval,yval);
        if((ret=slotMouseReleasedEvent(p,i,&d,xval,yval)) != 0) return ret;
        break;
      case MOUSE_OVER_EVENT:
        sscanf(text,"%d",&val);
        if(trace) printf("MOUSE_OVER_EVENT %d\n",val);
        if((ret=slotMouseOverEvent(p,i,&d,val)) != 0) return ret;
        break;
      case USER_EVENT:
        if(trace) printf("USER_EVENT id=%d %s\n",i,text);
        if((ret=slotUserEvent(p,i,&d,text)) != 0) return ret;
        break;
      default:
        if(trace) printf("UNKNOWN_EVENT id=%d %s\n",i,text);
        break;
    }
  }
}

#if 0
//!****************************************************************************
//! just sample of function which is parsing files into configuration data
//!****************************************************************************
static int init_mask_DATA(PARAM *p, DATA *d)
{
  char line[256]    = "";
  const char s[2]   = ";";
  char *token       = NULL;
  int bool_counter  = 0;
  int int_counter   = 0;

  if(p == NULL || d == NULL) return 0;
  
  d->b_config_List = bin_opts;
  d->i_config_List = int_opts;
  
  d->b_config_List[i].new_value = d->b_config_List[i].cur_value;
  d->i_config_List[i].new_value = d->i_config_List[i].cur_value;

  //! boolean configuration data initialization:
  FILE *fp = fopen(BIN_CONFIG_CSV,"r");
  if (fp != NULL) {

     fgets(line, sizeof(line), fp); //! first line has column headers names
     for (int i = 0; i < MAX_BOOL_CONFIGS; i++){

        if (fgets(line, sizeof(line), fp)){
           
           //! get the first token - name of the config option
           token = strtok(line, s);
           if (token != NULL){
              sprintf(d->b_config_List[i].name,"%s",token);
           } else {
              return 0;
           }
           //! get the second token - the config option value
           token = strtok(NULL, s);
           if (token != NULL){
              d->b_config_List[i].old_value = (bool)atoi(token);
              d->b_config_List[i].new_value = d->b_config_List[i].old_value;
           } else {
              return 0;
           }
           /*
           printf("init_mask_data(): %s = %d\n", d->b_config_List[i].name,
                                                 d->b_config_List[i].old_value);
           */
           //! get the third token - empty
           token = strtok(NULL, s);
           //! get the fourth token - description
           token = strtok(NULL, s);
           if (token != NULL){
              sprintf(d->b_config_List[i].description,"%s",token);
           } else {
              return 0;
           }
           bool_counter++;
           
        } else {
           //! zero initialization of unnecessary members
           strcpy(d->b_config_List[i].name,"");
           strcpy(d->b_config_List[i].description,"");
           d->b_config_List[i].old_value = 0;
           d->b_config_List[i].new_value = 0;
        }
     }
     fclose(fp);
  } else {
     return 0;
  }
  
  //! integer configuration data initialization:
  fp = fopen(INT_CONFIG_CSV,"r");
  if (fp != NULL) {
     fgets(line, sizeof(line), fp); //! first line has column headers names
     for (int i = 0; i < MAX_INT_CONFIGS; i++){
        
        if (fgets(line, sizeof(line), fp)){
           //! get the first token (name of the config option)
           token = strtok(line, s);
           if (token != NULL){
              sprintf(d->i_config_List[i].name,"%s",token);
           } else {
              return 0;
           }
           //! get the second token (the config option value)
           token = strtok(NULL, s);
           if (token != NULL){
              d->i_config_List[i].old_value = atoi(token);
              d->i_config_List[i].new_value = d->i_config_List[i].old_value;
           } else {
              return 0;
           }
           /*
           printf("init_mask_data(): %s = %d\n", d->i_config_List[i].name,
                                                 d->i_config_List[i].old_value);
           */
           //! get the third token (minimum config option value)
           token = strtok(NULL, s);
           if (token != NULL){
              d->i_config_List[i].min_min = atoi(token);
           } else {
              return 0;
           }
           //! get the fourth token (maximum config option value)
           token = strtok(NULL, s);
           if (token != NULL){
              d->i_config_List[i].max_max = atoi(token);
           } else {
              return 0;
           }
           /*
           printf("init_mask_data(): %s: %d - %d\n", d->i_config_List[i].name,
                   d->i_config_List[i].min_min,d->i_config_List[i].max_max);
           */
           //! get the fifth token - description
           token = strtok(NULL, s);
           if (token != NULL){
              sprintf(d->i_config_List[i].description,"%s",token);
           } else {
              return 0;
           }
           int_counter++;
           
        } else {
           //! zero initialization of redundant array members
           strcpy(d->i_config_List[i].name,"");
           strcpy(d->i_config_List[i].description,"");
           d->i_config_List[i].old_value = 0;
           d->i_config_List[i].new_value = 0;
           d->i_config_List[i].min_min = 0;
           d->i_config_List[i].max_max = 0;
        }
     }
     fclose(fp);
  } else {
     return 0;
  }
  d->bool_rows_num    = bool_counter;
  d->int_rows_num     = int_counter;
  d->config_was_saved = 0;

  return 1;
}
#endif