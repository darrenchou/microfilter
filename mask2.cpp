////////////////////////////////////////////////////////////////////////////
//
// show_mask1 for ProcessViewServer created: Fri Feb 9 14:13:43 2018
//
////////////////////////////////////////////////////////////////////////////
#include "pvapp.h"

// _begin_of_generated_area_ (do not edit -> use ui2pvc) -------------------

// our mask contains the following objects
enum {
  ID_MAIN_WIDGET = 0,
  frmBg,
  frmTopSeparator,
  imgHeader,
  lblHeader,
  btnMenu,
  frmStatusMessage,
  imgInfoMsg,
  btnMessages,
  lblStatus,
  btnSettings,
  tabServices,
  pageManualOps,
  frmSolenoidsOps,
  frmManSol1,
  lblManSol1,
  imgManSol1,
  btnManSol1,
  frmManSol2,
  lblManSol2,
  imgManSol2,
  btnManSol2,
  frmManSol3,
  lblManSol3,
  imgManSol3,
  btnManSol3,
  frmManSol4,
  lblManSol4,
  imgManSol4,
  btnManSol4,
  frmManSol5,
  lblManSol5,
  imgManSol5,
  btnManSol5,
  frmManSol6,
  lblManSol6,
  imgManSol6,
  btnManSol6,
  frmManSol7,
  lblManSol7,
  imgManSol7,
  btnManSol7,
  frmManSol8,
  lblManSol8,
  imgManSol8,
  btnManSol8,
  frmManSol9,
  lblManSol9,
  imgManSol9,
  btnManSol9,
  frmManOtherOps,
  frmErrAck,
  lblErrAck,
  imgErrAck,
  btnErrorReset,
  frmSwitchManMode,
  lblSwitchManMode,
  btnGroup_Mode,
  imgSysMode,
  lblModes_Header,
  frmCIPOps,
  frmManStartCIP,
  lblStatusCIP,
  btnReduceClean,
  btnIncreaseClean,
  lineditCleanTime,
  frmChemClean,
  lblFlushLine2,
  lblCleanTimeLeft,
  imgFlushLine2,
  btnChemClean,
  frmTimerCIP,
  lblTimerCIP,
  chkTimerCIP,
  btnReduceMix,
  lineditMixTime,
  btnIncreaseMix,
  frmSetMixTime,
  lblCIPTimeLeft,
  lblMixTimeLeft,
  btnChemMix,
  imgManStartCIP,
  prgbarCIPTime,
  lblCIP_Header,
  frmDrain,
  lblDrain,
  btnDrain,
  pageMedia1,
  qitxtwebview_1,
  lblTimerOnOff,
  ID_END_OF_WIDGETS
};

// our mask contains the following widget names
  static const char *widgetName[] = {
  "ID_MAIN_WIDGET",
  "frmBg",
  "frmTopSeparator",
  "imgHeader",
  "lblHeader",
  "btnMenu",
  "frmStatusMessage",
  "imgInfoMsg",
  "btnMessages",
  "lblStatus",
  "btnSettings",
  "tabServices",
  "pageManualOps",
  "frmSolenoidsOps",
  "frmManSol1",
  "lblManSol1",
  "imgManSol1",
  "btnManSol1",
  "frmManSol2",
  "lblManSol2",
  "imgManSol2",
  "btnManSol2",
  "frmManSol3",
  "lblManSol3",
  "imgManSol3",
  "btnManSol3",
  "frmManSol4",
  "lblManSol4",
  "imgManSol4",
  "btnManSol4",
  "frmManSol5",
  "lblManSol5",
  "imgManSol5",
  "btnManSol5",
  "frmManSol6",
  "lblManSol6",
  "imgManSol6",
  "btnManSol6",
  "frmManSol7",
  "lblManSol7",
  "imgManSol7",
  "btnManSol7",
  "frmManSol8",
  "lblManSol8",
  "imgManSol8",
  "btnManSol8",
  "frmManSol9",
  "lblManSol9",
  "imgManSol9",
  "btnManSol9",
  "frmManOtherOps",
  "frmErrAck",
  "lblErrAck",
  "imgErrAck",
  "btnErrorReset",
  "frmSwitchManMode",
  "lblSwitchManMode",
  "btnGroup_Mode",
  "imgSysMode",
  "lblModes_Header",
  "frmCIPOps",
  "frmManStartCIP",
  "lblStatusCIP",
  "btnReduceClean",
  "btnIncreaseClean",
  "lineditCleanTime",
  "frmChemClean",
  "lblFlushLine2",
  "lblCleanTimeLeft",
  "imgFlushLine2",
  "btnChemClean",
  "frmTimerCIP",
  "lblTimerCIP",
  "chkTimerCIP",
  "btnReduceMix",
  "lineditMixTime",
  "btnIncreaseMix",
  "frmSetMixTime",
  "lblCIPTimeLeft",
  "lblMixTimeLeft",
  "btnChemMix",
  "imgManStartCIP",
  "prgbarCIPTime",
  "lblCIP_Header",
  "frmDrain",
  "lblDrain",
  "btnDrain",
  "pageMedia1",
  "qitxtwebview_1",
  "lblTimerOnOff",
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
  "images/misc/osorno_logo.png",
  "",
  "",
  "",
  "images/empty32.png",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "images/icons25x25/graygreen25x25.png",
  "",
  "",
  "",
  "images/icons25x25/graygreen25x25.png",
  "",
  "",
  "",
  "images/icons25x25/graygreen25x25.png",
  "",
  "",
  "",
  "images/icons25x25/graygreen25x25.png",
  "",
  "",
  "",
  "images/icons25x25/graygreen25x25.png",
  "",
  "",
  "",
  "images/icons25x25/graygreen25x25.png",
  "",
  "",
  "",
  "images/icons25x25/graygreen25x25.png",
  "",
  "",
  "",
  "images/icons25x25/graygreen25x25.png",
  "",
  "",
  "",
  "images/icons25x25/graygreen25x25.png",
  "",
  "",
  "",
  "",
  "images/icons25x25/graygreen25x25.png",
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
  "",
  "",
  ""};

  static const int widgetType[ID_END_OF_WIDGETS+1] = {
  0,
  TQFrame,
  TQFrame,
  TQImage,
  TQLabel,
  TQPushButton,
  TQFrame,
  TQImage,
  TQPushButton,
  TQLabel,
  TQPushButton,
  TQTabWidget,
  TQWidget,
  TQFrame,
  TQFrame,
  TQLabel,
  TQImage,
  TQPushButton,
  TQFrame,
  TQLabel,
  TQImage,
  TQPushButton,
  TQFrame,
  TQLabel,
  TQImage,
  TQPushButton,
  TQFrame,
  TQLabel,
  TQImage,
  TQPushButton,
  TQFrame,
  TQLabel,
  TQImage,
  TQPushButton,
  TQFrame,
  TQLabel,
  TQImage,
  TQPushButton,
  TQFrame,
  TQLabel,
  TQImage,
  TQPushButton,
  TQFrame,
  TQLabel,
  TQImage,
  TQPushButton,
  TQFrame,
  TQLabel,
  TQImage,
  TQPushButton,
  TQFrame,
  TQFrame,
  TQLabel,
  TQImage,
  TQPushButton,
  TQFrame,
  TQLabel,
  TQPushButton,
  TQImage,
  TQLabel,
  TQFrame,
  TQFrame,
  TQLabel,
  TQPushButton,
  TQPushButton,
  TQLineEdit,
  TQFrame,
  TQLabel,
  TQLabel,
  TQImage,
  TQPushButton,
  TQFrame,
  TQLabel,
  TQCheck,
  TQPushButton,
  TQLineEdit,
  TQPushButton,
  TQFrame,
  TQLabel,
  TQLabel,
  TQPushButton,
  TQImage,
  TQProgressBar,
  TQLabel,
  TQFrame,
  TQLabel,
  TQPushButton,
  TQWidget,
  TQTextBrowser,
  TQLabel,
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

  pvQFrame(p,frmBg,0,Box,Plain,0,1);
  pvSetGeometry(p,frmBg,1,1,800,600);
  pvSetPaletteBackgroundColor(p,frmBg,200,200,180);
  pvSetFont(p,frmBg,"Cantarell",11,0,0,0,0);

  pvQFrame(p,frmTopSeparator,frmBg,HLine,Sunken,1,1);
  pvSetGeometry(p,frmTopSeparator,1,80,800,2);
  pvSetFont(p,frmTopSeparator,"Cantarell",11,0,0,0,0);

  pvDownloadFile(p,"images/misc/osorno_logo.png");
  pvQImage(p,imgHeader,frmBg,"images/misc/osorno_logo.png",&w,&h,&depth);
  pvSetGeometry(p,imgHeader,570,22,192,49);
  pvSetFont(p,imgHeader,"Cantarell",11,0,0,0,0);
  pvSetWhatsThis(p,imgHeader,pvtr("images/misc/osorno_logo.png"));

  pvQLabel(p,lblHeader,frmBg);
  pvSetGeometry(p,lblHeader,20,15,470,60);
  pvSetText(p,lblHeader,pvtr("Manual Operations"));
  pvSetPaletteForegroundColor(p,lblHeader,120,120,70);
  pvSetFont(p,lblHeader,"Cantarell",28,0,0,0,0);

  pvQPushButton(p,btnMenu,frmBg);
  pvSetGeometry(p,btnMenu,625,553,140,35);
  pvSetText(p,btnMenu,pvtr("Main Menu"));
  pvSetFont(p,btnMenu,"Sans Serif",12,0,0,0,0);

  pvQFrame(p,frmStatusMessage,frmBg,Panel,Raised,1,1);
  pvSetGeometry(p,frmStatusMessage,165,545,450,50);
  pvSetPaletteBackgroundColor(p,frmStatusMessage,150,150,100);
  pvSetFont(p,frmStatusMessage,"Cantarell",10,0,0,0,0);

  pvDownloadFile(p,"images/empty32.png");
  pvQImage(p,imgInfoMsg,frmStatusMessage,"images/empty32.png",&w,&h,&depth);
  pvSetGeometry(p,imgInfoMsg,10,13,22,22);
  pvSetFont(p,imgInfoMsg,"Sans Serif",10,0,0,0,0);
  pvSetWhatsThis(p,imgInfoMsg,pvtr("images/empty32.png"));

  pvQPushButton(p,btnMessages,frmStatusMessage);
  pvSetGeometry(p,btnMessages,330,9,100,30);
  pvSetText(p,btnMessages,pvtr("Messages"));
  pvSetFont(p,btnMessages,"Sans Serif",12,0,0,0,0);

  pvQLabel(p,lblStatus,frmStatusMessage);
  pvSetGeometry(p,lblStatus,9,9,315,30);
  pvSetPaletteBackgroundColor(p,lblStatus,200,200,180);
  pvSetFont(p,lblStatus,"Sans Serif",11,0,0,0,0);

  pvQPushButton(p,btnSettings,frmBg);
  pvSetGeometry(p,btnSettings,18,553,135,35);
  pvSetText(p,btnSettings,pvtr("SYS Config"));
  pvSetFont(p,btnSettings,"Sans Serif",12,0,0,0,0);

  pvQTabWidget(p,tabServices,frmBg);
  pvSetGeometry(p,tabServices,14,90,770,450);
  pvSetPaletteForegroundColor(p,tabServices,0,0,0);
  pvSetPaletteBackgroundColor(p,tabServices,200,200,180);
  pvSetFont(p,tabServices,"Sans Serif",10,1,0,0,0);

  pvQWidget(p,pageManualOps,tabServices);
  pvAddTab(p,tabServices,pageManualOps,pvtr("Manual Ops"));
  pvSetFont(p,pageManualOps,"Sans",10,0,0,0,0);

  pvQFrame(p,frmSolenoidsOps,pageManualOps,Panel,Raised,1,1);
  pvSetGeometry(p,frmSolenoidsOps,1,1,378,416);
  pvSetPaletteBackgroundColor(p,frmSolenoidsOps,200,200,180);
  pvSetFont(p,frmSolenoidsOps,"Sans",10,0,0,0,0);

  pvQFrame(p,frmManSol1,frmSolenoidsOps,Panel,Raised,1,1);
  pvSetGeometry(p,frmManSol1,10,10,359,40);
  pvSetPaletteBackgroundColor(p,frmManSol1,150,150,100);
  pvSetFont(p,frmManSol1,"Sans",10,0,0,0,0);

  pvQLabel(p,lblManSol1,frmManSol1);
  pvSetGeometry(p,lblManSol1,10,5,110,30);
  pvSetText(p,lblManSol1,pvtr("Solenoid #1:"));
  pvSetPaletteForegroundColor(p,lblManSol1,255,255,255);
  pvSetFont(p,lblManSol1,"Sans",13,0,0,0,0);

  pvDownloadFile(p,"images/icons25x25/graygreen25x25.png");
  pvQImage(p,imgManSol1,frmManSol1,"images/icons25x25/graygreen25x25.png",&w,&h,&depth);
  pvSetGeometry(p,imgManSol1,155,7,25,25);
  pvSetFont(p,imgManSol1,"Sans",10,0,0,0,0);
  pvSetWhatsThis(p,imgManSol1,pvtr(""));

  pvQPushButton(p,btnManSol1,frmManSol1);
  pvSetGeometry(p,btnManSol1,213,3,140,30);
  pvSetText(p,btnManSol1,pvtr("Open"));
  pvSetFont(p,btnManSol1,"Sans",12,0,0,0,0);

  pvQFrame(p,frmManSol2,frmSolenoidsOps,Panel,Raised,1,1);
  pvSetGeometry(p,frmManSol2,10,55,359,40);
  pvSetPaletteBackgroundColor(p,frmManSol2,150,150,100);
  pvSetFont(p,frmManSol2,"Sans",10,0,0,0,0);

  pvQLabel(p,lblManSol2,frmManSol2);
  pvSetGeometry(p,lblManSol2,10,5,110,30);
  pvSetText(p,lblManSol2,pvtr("Solenoid #2:"));
  pvSetPaletteForegroundColor(p,lblManSol2,255,255,255);
  pvSetFont(p,lblManSol2,"Sans",13,0,0,0,0);

  pvDownloadFile(p,"images/icons25x25/graygreen25x25.png");
  pvQImage(p,imgManSol2,frmManSol2,"images/icons25x25/graygreen25x25.png",&w,&h,&depth);
  pvSetGeometry(p,imgManSol2,155,7,25,25);
  pvSetFont(p,imgManSol2,"Sans",10,0,0,0,0);
  pvSetWhatsThis(p,imgManSol2,pvtr(""));

  pvQPushButton(p,btnManSol2,frmManSol2);
  pvSetGeometry(p,btnManSol2,213,5,140,30);
  pvSetText(p,btnManSol2,pvtr("Open"));
  pvSetFont(p,btnManSol2,"Sans",12,0,0,0,0);

  pvQFrame(p,frmManSol3,frmSolenoidsOps,Panel,Raised,1,1);
  pvSetGeometry(p,frmManSol3,10,100,359,40);
  pvSetPaletteBackgroundColor(p,frmManSol3,150,150,100);
  pvSetFont(p,frmManSol3,"Sans",10,0,0,0,0);

  pvQLabel(p,lblManSol3,frmManSol3);
  pvSetGeometry(p,lblManSol3,10,5,110,30);
  pvSetText(p,lblManSol3,pvtr("Solenoid #3:"));
  pvSetPaletteForegroundColor(p,lblManSol3,255,255,255);
  pvSetFont(p,lblManSol3,"Sans",13,0,0,0,0);

  pvDownloadFile(p,"images/icons25x25/graygreen25x25.png");
  pvQImage(p,imgManSol3,frmManSol3,"images/icons25x25/graygreen25x25.png",&w,&h,&depth);
  pvSetGeometry(p,imgManSol3,155,7,25,25);
  pvSetFont(p,imgManSol3,"Sans",10,0,0,0,0);
  pvSetWhatsThis(p,imgManSol3,pvtr(""));

  pvQPushButton(p,btnManSol3,frmManSol3);
  pvSetGeometry(p,btnManSol3,213,5,140,30);
  pvSetText(p,btnManSol3,pvtr("Open"));
  pvSetFont(p,btnManSol3,"Sans",12,0,0,0,0);

  pvQFrame(p,frmManSol4,frmSolenoidsOps,Panel,Raised,1,1);
  pvSetGeometry(p,frmManSol4,10,145,359,40);
  pvSetPaletteBackgroundColor(p,frmManSol4,150,150,100);
  pvSetFont(p,frmManSol4,"Sans",10,0,0,0,0);

  pvQLabel(p,lblManSol4,frmManSol4);
  pvSetGeometry(p,lblManSol4,10,5,110,30);
  pvSetText(p,lblManSol4,pvtr("Solenoid #4:"));
  pvSetPaletteForegroundColor(p,lblManSol4,255,255,255);
  pvSetFont(p,lblManSol4,"Sans",13,0,0,0,0);

  pvDownloadFile(p,"images/icons25x25/graygreen25x25.png");
  pvQImage(p,imgManSol4,frmManSol4,"images/icons25x25/graygreen25x25.png",&w,&h,&depth);
  pvSetGeometry(p,imgManSol4,155,7,25,25);
  pvSetFont(p,imgManSol4,"Sans",10,0,0,0,0);
  pvSetWhatsThis(p,imgManSol4,pvtr(""));

  pvQPushButton(p,btnManSol4,frmManSol4);
  pvSetGeometry(p,btnManSol4,213,5,140,30);
  pvSetText(p,btnManSol4,pvtr("Open"));
  pvSetFont(p,btnManSol4,"Sans",12,0,0,0,0);

  pvQFrame(p,frmManSol5,frmSolenoidsOps,Panel,Raised,1,1);
  pvSetGeometry(p,frmManSol5,10,190,359,40);
  pvSetPaletteBackgroundColor(p,frmManSol5,150,150,100);
  pvSetFont(p,frmManSol5,"Sans",10,0,0,0,0);

  pvQLabel(p,lblManSol5,frmManSol5);
  pvSetGeometry(p,lblManSol5,10,5,110,30);
  pvSetText(p,lblManSol5,pvtr("Solenoid #5:"));
  pvSetPaletteForegroundColor(p,lblManSol5,255,255,255);
  pvSetFont(p,lblManSol5,"Sans",13,0,0,0,0);

  pvDownloadFile(p,"images/icons25x25/graygreen25x25.png");
  pvQImage(p,imgManSol5,frmManSol5,"images/icons25x25/graygreen25x25.png",&w,&h,&depth);
  pvSetGeometry(p,imgManSol5,155,7,25,25);
  pvSetFont(p,imgManSol5,"Sans",10,0,0,0,0);
  pvSetWhatsThis(p,imgManSol5,pvtr(""));

  pvQPushButton(p,btnManSol5,frmManSol5);
  pvSetGeometry(p,btnManSol5,213,5,140,30);
  pvSetText(p,btnManSol5,pvtr("Open"));
  pvSetFont(p,btnManSol5,"Sans",12,0,0,0,0);

  pvQFrame(p,frmManSol6,frmSolenoidsOps,Panel,Raised,1,1);
  pvSetGeometry(p,frmManSol6,10,235,359,40);
  pvSetPaletteBackgroundColor(p,frmManSol6,150,150,100);
  pvSetFont(p,frmManSol6,"Sans",10,0,0,0,0);

  pvQLabel(p,lblManSol6,frmManSol6);
  pvSetGeometry(p,lblManSol6,10,5,110,30);
  pvSetText(p,lblManSol6,pvtr("Solenoid #6:"));
  pvSetPaletteForegroundColor(p,lblManSol6,255,255,255);
  pvSetFont(p,lblManSol6,"Sans",13,0,0,0,0);

  pvDownloadFile(p,"images/icons25x25/graygreen25x25.png");
  pvQImage(p,imgManSol6,frmManSol6,"images/icons25x25/graygreen25x25.png",&w,&h,&depth);
  pvSetGeometry(p,imgManSol6,155,7,25,25);
  pvSetFont(p,imgManSol6,"Sans",10,0,0,0,0);
  pvSetWhatsThis(p,imgManSol6,pvtr(""));

  pvQPushButton(p,btnManSol6,frmManSol6);
  pvSetGeometry(p,btnManSol6,213,5,140,30);
  pvSetText(p,btnManSol6,pvtr("Open"));
  pvSetFont(p,btnManSol6,"Sans",12,0,0,0,0);

  pvQFrame(p,frmManSol7,frmSolenoidsOps,Panel,Raised,1,1);
  pvSetGeometry(p,frmManSol7,10,280,359,40);
  pvSetPaletteBackgroundColor(p,frmManSol7,150,150,100);
  pvSetFont(p,frmManSol7,"Sans",10,0,0,0,0);

  pvQLabel(p,lblManSol7,frmManSol7);
  pvSetGeometry(p,lblManSol7,10,5,110,30);
  pvSetText(p,lblManSol7,pvtr("Solenoid #7:"));
  pvSetPaletteForegroundColor(p,lblManSol7,255,255,255);
  pvSetFont(p,lblManSol7,"Sans",13,0,0,0,0);

  pvDownloadFile(p,"images/icons25x25/graygreen25x25.png");
  pvQImage(p,imgManSol7,frmManSol7,"images/icons25x25/graygreen25x25.png",&w,&h,&depth);
  pvSetGeometry(p,imgManSol7,155,7,25,25);
  pvSetFont(p,imgManSol7,"Sans",10,0,0,0,0);
  pvSetWhatsThis(p,imgManSol7,pvtr(""));

  pvQPushButton(p,btnManSol7,frmManSol7);
  pvSetGeometry(p,btnManSol7,213,5,140,30);
  pvSetText(p,btnManSol7,pvtr("Open"));
  pvSetFont(p,btnManSol7,"Sans",12,0,0,0,0);

  pvQFrame(p,frmManSol8,frmSolenoidsOps,Panel,Raised,1,1);
  pvSetGeometry(p,frmManSol8,10,325,359,40);
  pvSetPaletteBackgroundColor(p,frmManSol8,150,150,100);
  pvSetFont(p,frmManSol8,"Sans",10,0,0,0,0);

  pvQLabel(p,lblManSol8,frmManSol8);
  pvSetGeometry(p,lblManSol8,10,5,110,30);
  pvSetText(p,lblManSol8,pvtr("Solenoid #8:"));
  pvSetPaletteForegroundColor(p,lblManSol8,255,255,255);
  pvSetFont(p,lblManSol8,"Sans",13,0,0,0,0);

  pvDownloadFile(p,"images/icons25x25/graygreen25x25.png");
  pvQImage(p,imgManSol8,frmManSol8,"images/icons25x25/graygreen25x25.png",&w,&h,&depth);
  pvSetGeometry(p,imgManSol8,155,7,25,25);
  pvSetFont(p,imgManSol8,"Sans",10,0,0,0,0);
  pvSetWhatsThis(p,imgManSol8,pvtr("images/icons25x25/graygreen25x25.png"));

  pvQPushButton(p,btnManSol8,frmManSol8);
  pvSetGeometry(p,btnManSol8,213,5,140,30);
  pvSetText(p,btnManSol8,pvtr("Open"));
  pvSetFont(p,btnManSol8,"Sans",12,0,0,0,0);

  pvQFrame(p,frmManSol9,frmSolenoidsOps,Panel,Raised,1,1);
  pvSetGeometry(p,frmManSol9,10,370,359,40);
  pvSetPaletteBackgroundColor(p,frmManSol9,150,150,100);
  pvSetFont(p,frmManSol9,"Sans",10,0,0,0,0);

  pvQLabel(p,lblManSol9,frmManSol9);
  pvSetGeometry(p,lblManSol9,10,5,110,30);
  pvSetText(p,lblManSol9,pvtr("Solenoid #9:"));
  pvSetPaletteForegroundColor(p,lblManSol9,255,255,255);
  pvSetFont(p,lblManSol9,"Sans",13,0,0,0,0);

  pvDownloadFile(p,"images/icons25x25/graygreen25x25.png");
  pvQImage(p,imgManSol9,frmManSol9,"images/icons25x25/graygreen25x25.png",&w,&h,&depth);
  pvSetGeometry(p,imgManSol9,155,7,25,25);
  pvSetFont(p,imgManSol9,"Sans",10,0,0,0,0);
  pvSetWhatsThis(p,imgManSol9,pvtr("images/icons25x25/graygreen25x25.png"));

  pvQPushButton(p,btnManSol9,frmManSol9);
  pvSetGeometry(p,btnManSol9,213,5,140,30);
  pvSetText(p,btnManSol9,pvtr("Open"));
  pvSetFont(p,btnManSol9,"Sans",12,0,0,0,0);

  pvQFrame(p,frmManOtherOps,pageManualOps,Panel,Raised,0,1);
  pvSetGeometry(p,frmManOtherOps,381,0,380,225);
  pvSetPaletteBackgroundColor(p,frmManOtherOps,200,200,180);
  pvSetFont(p,frmManOtherOps,"Sans",10,0,0,0,0);

  pvQFrame(p,frmErrAck,frmManOtherOps,Panel,Raised,1,1);
  pvSetGeometry(p,frmErrAck,11,94,359,40);
  pvSetPaletteBackgroundColor(p,frmErrAck,150,150,100);
  pvSetFont(p,frmErrAck,"Sans",10,0,0,0,0);

  pvQLabel(p,lblErrAck,frmErrAck);
  pvSetGeometry(p,lblErrAck,10,5,120,30);
  pvSetText(p,lblErrAck,pvtr("Alarm   Reset :"));
  pvSetPaletteForegroundColor(p,lblErrAck,255,255,255);
  pvSetFont(p,lblErrAck,"Sans",13,0,0,0,0);

  pvDownloadFile(p,"images/icons25x25/graygreen25x25.png");
  pvQImage(p,imgErrAck,frmErrAck,"images/icons25x25/graygreen25x25.png",&w,&h,&depth);
  pvSetGeometry(p,imgErrAck,158,7,25,25);
  pvSetFont(p,imgErrAck,"Sans",10,0,0,0,0);
  pvSetWhatsThis(p,imgErrAck,pvtr(""));

  pvQPushButton(p,btnErrorReset,frmErrAck);
  pvSetGeometry(p,btnErrorReset,213,5,140,30);
  pvSetText(p,btnErrorReset,pvtr("Alarm Reset"));
  pvSetFont(p,btnErrorReset,"Sans",12,0,0,0,0);

  pvQFrame(p,frmSwitchManMode,frmManOtherOps,Panel,Raised,1,1);
  pvSetGeometry(p,frmSwitchManMode,11,51,359,40);
  pvSetPaletteBackgroundColor(p,frmSwitchManMode,150,150,100);
  pvSetFont(p,frmSwitchManMode,"Sans",10,0,0,0,0);

  pvQLabel(p,lblSwitchManMode,frmSwitchManMode);
  pvSetGeometry(p,lblSwitchManMode,10,6,130,30);
  pvSetText(p,lblSwitchManMode,pvtr("System Mode :"));
  pvSetPaletteForegroundColor(p,lblSwitchManMode,255,255,255);
  pvSetFont(p,lblSwitchManMode,"Sans",13,0,0,0,0);

  pvQPushButton(p,btnGroup_Mode,frmSwitchManMode);
  pvSetGeometry(p,btnGroup_Mode,213,5,140,30);
  pvSetText(p,btnGroup_Mode,pvtr("Switch To Manual"));
  pvSetFont(p,btnGroup_Mode,"Sans",11,0,0,0,0);

  pvDownloadFile(p,"images/icons25x25/greenauto25x25.png");
  pvQImage(p,imgSysMode,frmSwitchManMode,"images/icons25x25/greenauto25x25.png",&w,&h,&depth);
  pvSetGeometry(p,imgSysMode,158,8,25,25);
  pvSetFont(p,imgSysMode,"Sans",10,0,0,0,0);
  pvSetWhatsThis(p,imgSysMode,pvtr(""));

  pvQLabel(p,lblModes_Header,frmManOtherOps);
  pvSetGeometry(p,lblModes_Header,12,9,359,35);
  pvSetText(p,lblModes_Header,pvtr("             Operation Modes"));
  pvSetPaletteForegroundColor(p,lblModes_Header,120,120,80);
  pvSetFont(p,lblModes_Header,"Sans",13,1,0,0,0);
  pvSetStyle(p,lblModes_Header,Box,-1,-1,-1);
  pvSetStyle(p,lblModes_Header,-1,-1,2,-1);

  pvQFrame(p,frmCIPOps,pageManualOps,Panel,Raised,1,1);
  pvSetGeometry(p,frmCIPOps,384,140,375,270);
  pvSetFont(p,frmCIPOps,"Sans",10,0,0,0,0);

  pvQFrame(p,frmManStartCIP,frmCIPOps,Panel,Raised,1,1);
  pvSetGeometry(p,frmManStartCIP,9,138,359,80);
  pvSetPaletteBackgroundColor(p,frmManStartCIP,150,150,100);
  pvSetFont(p,frmManStartCIP,"Sans",10,0,0,0,0);

  pvQLabel(p,lblStatusCIP,frmManStartCIP);
  pvSetGeometry(p,lblStatusCIP,9,3,195,30);
  pvSetText(p,lblStatusCIP,pvtr("Chemical Clean Timer:"));
  pvSetPaletteForegroundColor(p,lblStatusCIP,255,255,255);
  pvSetFont(p,lblStatusCIP,"Sans",12,1,0,0,0);

  pvQPushButton(p,btnReduceClean,frmManStartCIP);
  pvSetGeometry(p,btnReduceClean,207,3,29,30);
  pvSetText(p,btnReduceClean,pvtr("<"));
  pvSetFont(p,btnReduceClean,"Sans",12,0,0,0,0);

  pvQPushButton(p,btnIncreaseClean,frmManStartCIP);
  pvSetGeometry(p,btnIncreaseClean,324,3,29,30);
  pvSetText(p,btnIncreaseClean,pvtr(">"));
  pvSetFont(p,btnIncreaseClean,"Sans Serif",12,0,0,0,0);

  pvQLineEdit(p,lineditCleanTime,frmManStartCIP);
  pvSetGeometry(p,lineditCleanTime,240,3,79,30);
  pvSetText(p,lineditCleanTime,pvtr("10 min"));
  pvSetFont(p,lineditCleanTime,"Courier",12,1,0,0,0);

  pvQFrame(p,frmChemClean,frmManStartCIP,Panel,Sunken,1,1);
  pvSetGeometry(p,frmChemClean,3,36,359,40);
  pvSetFont(p,frmChemClean,"Sans",10,0,0,0,0);

  pvQLabel(p,lblFlushLine2,frmChemClean);
  pvSetGeometry(p,lblFlushLine2,9,6,170,30);
  pvSetText(p,lblFlushLine2,pvtr("Time left:"));
  pvSetPaletteForegroundColor(p,lblFlushLine2,255,255,255);
  pvSetFont(p,lblFlushLine2,"Sans",13,0,0,0,0);

  pvQLabel(p,lblCleanTimeLeft,lblFlushLine2);
  pvSetGeometry(p,lblCleanTimeLeft,84,0,99,30);
  pvSetText(p,lblCleanTimeLeft,pvtr("10 min"));
  pvSetFont(p,lblCleanTimeLeft,"Sans",13,0,0,0,0);

  pvDownloadFile(p,"images/icons25x25/graygreen25x25.png");
  pvQImage(p,imgFlushLine2,frmChemClean,"images/icons25x25/graygreen25x25.png",&w,&h,&depth);
  pvSetGeometry(p,imgFlushLine2,210,9,25,25);
  pvSetFont(p,imgFlushLine2,"Sans",10,0,0,0,0);
  pvSetWhatsThis(p,imgFlushLine2,pvtr(""));

  pvQPushButton(p,btnChemClean,frmChemClean);
  pvSetGeometry(p,btnChemClean,246,5,100,30);
  pvSetText(p,btnChemClean,pvtr("Start"));
  pvSetFont(p,btnChemClean,"Sans",12,0,0,0,0);

  pvQFrame(p,frmTimerCIP,frmCIPOps,Panel,Raised,1,1);
  pvSetGeometry(p,frmTimerCIP,11,50,359,80);
  pvSetPaletteBackgroundColor(p,frmTimerCIP,150,150,100);
  pvSetFont(p,frmTimerCIP,"Sans",10,0,0,0,0);

  pvQLabel(p,lblTimerCIP,frmTimerCIP);
  pvSetGeometry(p,lblTimerCIP,9,6,175,30);
  pvSetText(p,lblTimerCIP,pvtr("Chemical Mix Timer:"));
  pvSetPaletteForegroundColor(p,lblTimerCIP,255,255,255);
  pvSetFont(p,lblTimerCIP,"Sans",12,1,0,0,0);

  pvQCheckBox(p,chkTimerCIP,frmTimerCIP);
  pvSetGeometry(p,chkTimerCIP,187,6,20,30);
  pvSetPaletteBackgroundColor(p,chkTimerCIP,150,150,100);
  pvSetFont(p,chkTimerCIP,"Sans",12,0,0,0,0);

  pvQPushButton(p,btnReduceMix,frmTimerCIP);
  pvSetGeometry(p,btnReduceMix,213,3,30,30);
  pvSetText(p,btnReduceMix,pvtr("<"));
  pvSetFont(p,btnReduceMix,"Cantarell",12,0,0,0,0);

  pvQLineEdit(p,lineditMixTime,frmTimerCIP);
  pvSetGeometry(p,lineditMixTime,242,5,82,30);
  pvSetText(p,lineditMixTime,pvtr("  10 min"));
  pvSetPaletteBackgroundColor(p,lineditMixTime,255,255,255);
  pvSetFont(p,lineditMixTime,"Courier",12,1,0,0,0);

  pvQPushButton(p,btnIncreaseMix,frmTimerCIP);
  pvSetGeometry(p,btnIncreaseMix,323,5,30,30);
  pvSetText(p,btnIncreaseMix,pvtr(">"));
  pvSetFont(p,btnIncreaseMix,"Cantarell",12,0,0,0,0);

  pvQFrame(p,frmSetMixTime,frmTimerCIP,Panel,Sunken,1,1);
  pvSetGeometry(p,frmSetMixTime,5,35,345,40);
  pvSetFont(p,frmSetMixTime,"Sans",10,0,0,0,0);

  pvQLabel(p,lblCIPTimeLeft,frmSetMixTime);
  pvSetGeometry(p,lblCIPTimeLeft,3,6,100,30);
  pvSetText(p,lblCIPTimeLeft,pvtr("Time Left :"));
  pvSetPaletteForegroundColor(p,lblCIPTimeLeft,255,255,255);
  pvSetFont(p,lblCIPTimeLeft,"Sans",13,0,0,0,0);

  pvQLabel(p,lblMixTimeLeft,frmSetMixTime);
  pvSetGeometry(p,lblMixTimeLeft,99,6,60,30);
  pvSetText(p,lblMixTimeLeft,pvtr("10 min"));
  pvSetPaletteForegroundColor(p,lblMixTimeLeft,255,255,255);
  pvSetFont(p,lblMixTimeLeft,"Sans",12,1,0,0,0);

  pvQPushButton(p,btnChemMix,frmSetMixTime);
  pvSetGeometry(p,btnChemMix,249,5,90,30);
  pvSetText(p,btnChemMix,pvtr("Start"));
  pvSetFont(p,btnChemMix,"Sans",12,0,0,0,0);

  pvDownloadFile(p,"images/icons25x25/graygreen25x25.png");
  pvQImage(p,imgManStartCIP,frmSetMixTime,"images/icons25x25/graygreen25x25.png",&w,&h,&depth);
  pvSetGeometry(p,imgManStartCIP,219,6,25,25);
  pvSetFont(p,imgManStartCIP,"Sans",10,0,0,0,0);
  pvSetWhatsThis(p,imgManStartCIP,pvtr(""));

  pvQProgressBar(p,prgbarCIPTime,frmSetMixTime,100,Horizontal);
  pvSetGeometry(p,prgbarCIPTime,159,3,60,30);
  pvSetFont(p,prgbarCIPTime,"Sans",10,0,0,0,0);

  pvQLabel(p,lblCIP_Header,frmCIPOps);
  pvSetGeometry(p,lblCIP_Header,12,9,350,36);
  pvSetText(p,lblCIP_Header,pvtr("        Chemecal Cleaning (CIP)"));
  pvSetPaletteForegroundColor(p,lblCIP_Header,120,120,80);
  pvSetFont(p,lblCIP_Header,"Sans",13,1,0,0,0);
  pvSetStyle(p,lblCIP_Header,Box,-1,-1,-1);
  pvSetStyle(p,lblCIP_Header,-1,-1,2,-1);

  pvQFrame(p,frmDrain,frmCIPOps,Box,Plain,0,1);
  pvSetGeometry(p,frmDrain,9,225,359,40);
  pvSetPaletteBackgroundColor(p,frmDrain,150,150,100);
  pvSetFont(p,frmDrain,"Sans",10,0,0,0,0);

  pvQLabel(p,lblDrain,frmDrain);
  pvSetGeometry(p,lblDrain,9,3,170,30);
  pvSetText(p,lblDrain,pvtr("Drain:"));
  pvSetPaletteForegroundColor(p,lblDrain,255,255,255);
  pvSetFont(p,lblDrain,"Sans",12,1,0,0,0);

  pvQPushButton(p,btnDrain,frmDrain);
  pvSetGeometry(p,btnDrain,246,6,99,30);
  pvSetText(p,btnDrain,pvtr("Start"));
  pvSetFont(p,btnDrain,"Sans",12,0,0,0,0);

  pvQWidget(p,pageMedia1,tabServices);
  pvAddTab(p,tabServices,pageMedia1,pvtr("Media 1"));
  pvSetFont(p,pageMedia1,"Cantarell",11,0,0,0,0);

  pvQTextBrowser(p,qitxtwebview_1,pageMedia1);
  pvSetGeometry(p,qitxtwebview_1,3,3,759,413);
  pvSetFont(p,qitxtwebview_1,"Cantarell",11,0,0,0,0);

  pvQLabel(p,lblTimerOnOff,0);
  pvSetGeometry(p,lblTimerOnOff,630,663,120,30);
  pvSetText(p,lblTimerOnOff,pvtr("CIP Timer Off"));
  pvSetPaletteForegroundColor(p,lblTimerOnOff,255,255,255);
  pvSetFont(p,lblTimerOnOff,"Sans",12,0,0,0,0);


  pvEndDefinition(p);
  return 0;
}

// _end_of_generated_area_ (do not edit -> use ui2pvc) ---------------------

#include "mask2_slots.h"
#include "osornoconf.h"
#include "osaut.h"

static adjustable_ui_t yesCIPUI[] = {
    //!     id         group  x    y    w    h   v    txt
    { frmCIPOps        , 0,  382,   140, 380, 270,  1, MSG_BLANK }, 
    { frmManSol1       , 0,   10,    10, 359,  40,  1, MSG_BLANK },
    { frmManSol2       , 0,   10,    55, 359,  40,  1, MSG_BLANK },
    { frmManSol3       , 0,   10,   100, 359,  40,  1, MSG_BLANK },
    { frmManSol4       , 0,   10,   145, 359,  40,  1, MSG_BLANK },
    { frmManSol5       , 0,   10,   190, 359,  40,  1, MSG_BLANK },
    { frmManSol6       , 0,   10,   235, 359,  40,  1, MSG_BLANK },
    { frmManSol7       , 0,   10,   280, 359,  40,  1, MSG_BLANK },
    { frmManSol8       , 0,   10,   325, 359,  40,  1, MSG_BLANK },
    { frmManSol9       , 0,   10,   370, 359,  40,  1, MSG_BLANK },
    { ID_END_OF_WIDGETS, 0,   0,   0,   0,   0,  0, MSG_BLANK }
};
static adjustable_ui_t noCIPUI[] = {
    //!     id         group  x    y    w    h   v    txt
    { frmCIPOps        , 0,  382,   140, 380, 270,  0, MSG_BLANK }, 
    { frmManSol1       , 0,   10,    10, 359,  40,  1, MSG_BLANK },
    { frmManSol2       , 0,   10,    55, 359,  40,  1, MSG_BLANK },
    { frmManSol3       , 0,   10,   100, 359,  40,  1, MSG_BLANK },
    { frmManSol4       , 0,   10,   145, 359,  40,  1, MSG_BLANK },
    { frmManSol5       , 0,   10,   190, 359,  40,  1, MSG_BLANK },
    { frmManSol6       , 0,   10,   235, 359,  40,  1, MSG_BLANK },
    { frmManSol7       , 0,   10,   280, 359,  40,  1, MSG_BLANK },
    { frmManSol8       , 0,   10,   325, 359,  40,  1, MSG_BLANK },
    { frmManSol9       , 0,   10,   370, 359,  40,  1, MSG_BLANK },
    { ID_END_OF_WIDGETS, 0,   0,   0,   0,   0,  0, MSG_BLANK }
};
static int defineMask(PARAM *p)
{
  int  id = 0, visible = 0, width = 0;
  if(p == NULL) return 1;
  int show_cip   = (int)bin_opts[CIP_PRESENT]->cur_val;
  generated_defineMask(p);
  pvHide(p, frmBg);
  pvDownloadFile(p, EMPTY_IMAGE);
  pvDownloadFile(p, ALERT_GREY);
  pvDownloadFile(p, WARNING_GREY);
  pvDownloadFile(p, INFORM_GREY);
  pvDownloadFile(p,"images/semRedL.png");
  pvDownloadFile(p,"images/semGreenL.png");
  pvDownloadFile(p,"images/semBlueL.png");
  pvDownloadFile(p,"images/manual_on.png");
  pvDownloadFile(p,"images/auto_on.png");
  pvDownloadFile(p,"images/all.png");

  pvSetEnabled(p,btnReduceMix,0);
  pvSetEnabled(p,btnIncreaseMix,0);
  pvSetEnabled(p,lineditMixTime,0);

  adjustable_ui_t *adjust_UI = NULL;
  // (todo: add your code here)
  if (show_cip == 0){
     adjust_UI = noCIPUI;
  }
  else adjust_UI = yesCIPUI;
  printf("id is %d\n",adjust_UI->id);
  while ((adjust_UI->id) < ID_END_OF_WIDGETS ){
     
     id      = adjust_UI->id;
     visible = adjust_UI->v;
     width   = adjust_UI->w;
     
     switch (id){
       /*if(id == frmCIPOps){
               if (show_cip){
                  ///width = 734;
                  pvSetGeometry(p,lblManSol7,10,5,290,35);
                  pvSetText(p,lblManSol7,pvtr(TXT_DEV_NA_LONG));
                  printf("%s\n", "cip_present is on");
                  visible = 0;
               }  
       //}
       }
       if(id == frmManSol1){
               if (!show_cip){
                  ///width = 734;
                  pvSetGeometry(p,lblManSol8,10,5,290,35);
                  pvSetText(p,lblManSol8,pvtr(TXT_DEV_NA_LONG));
                  printf("%s\n", "cip_present is off");
                  visible = 0;
               }  
       //}
       }*/
       case frmCIPOps:
               if (!show_cip){
                  pvHide(p,btnManSol7);
                  pvHide(p,btnManSol8);
                  pvHide(p,btnManSol9);
                  pvHide(p,imgManSol7);
                  pvHide(p,imgManSol8);
                  pvHide(p,imgManSol9);
                  //width = 734;
                  pvSetGeometry(p,lblManSol7,10,1,320,40);
                  pvSetText(p,lblManSol7,pvtr("Solenoid #7:"TXT_DEV_NA_SHORT));
                  //pvSetGeometry(p,lblManSol8,10,325,320,40);
                  pvSetGeometry(p,lblManSol8,10,1,320,40);
                  pvSetText(p,lblManSol8,pvtr("Solenoid #8:"TXT_DEV_NA_SHORT));
                  pvSetGeometry(p,lblManSol9,10,1,320,40);
                  pvSetText(p,lblManSol9,pvtr("Solenoid #9:"TXT_DEV_NA_SHORT));
                  pvSetGeometry(p,lblCIP_Header,10,1,320,40);
                  pvSetText(p,lblCIP_Header,pvtr("CIP is not available"));            

                  visible = 0;
               }
               break;
     }

     pvSetGeometry(p, id, adjust_UI->x, adjust_UI->y, width, adjust_UI->h);
     if (!visible){
        pvHide(p, id);
     }
     adjust_UI++;
  }
  printf("after while in mask2\n");
  pvShow(p, frmBg);
  
  return 0;
}


//!****************************************************************************
static int showData(PARAM *p, DATA *d)
{
  int in_request = 0;
  int serv_id = -1, id = -1, state = -1, disable = 1;
  
  static int old_act_position = 2048; // just some value in a middle position
  ///int new_act_position        = stp2pvs->act_position;
  
  char buff[24] = "";
  
  if (p == NULL || d == NULL)
     return 1;

  ///in_request = (d->ui_cur_mode == MODE_IN_REQUEST)? 1: 0;
  //!-----------------------------------------------------------------  
  //! Service Control UI: Start/Stop Service, All to Auto/Manual, PC Reboot,
  //!                     STP Start/Stop, PLC Error Ack
  //!-----------------------------------------------------------------  
  /*for (int i = 0; i < MAX_SERV_CTRL_NUM; i++){
     serv_id = d->servs_tbl[i].serv_id;
     //! Service Control button ui
     if (!d->servs_tbl[i].btn_ui.up2d){
        id      = d->servs_tbl[i].btn_ui.ui_id;
        state   = d->servs_tbl[i].btn_ui.state;
        
        switch (serv_id){
           case SERV_ON_OFF : pvSetText(p, id, pvtr(serv_btn_txt[state]));
                              break;
           case SERV_ALL_TO : pvSetText(p, id, pvtr(all_to_btn_txt[state]));
                              break;
           case SERV_STP_RUN: pvSetText(p, id, pvtr(stp_btn_txt[state]));
                              break;
           case SERV_REBOOT : break; //! no changes of the button's label
           case SERV_ERR_ACK:
              //printf ("showData() : d->servs_tbl[i].enbl = %d\n",d->servs_tbl[i].enbl);

              break; //! no changes of the button's label
        }
        disable = (in_request)? 1: !(d->servs_tbl[i].enbl);
        pvSetEnabled(p, id, !disable);
        d->servs_tbl[i].btn_ui.up2d = 1;
     }

     //!-----------------------------------------------------------------  
     //! Service Control image ui 
     //!-----------------------------------------------------------------  
     //! if image doesn't exist, then uptodate flag 'up2d' is always true
     if (!d->servs_tbl[i].img_ui.up2d){
        id      = d->servs_tbl[i].img_ui.ui_id;
        state   = d->servs_tbl[i].img_ui.state;
        switch (serv_id){
           case SERV_ALL_TO : pvSetImage(p, id, pvtr(all_to_img_tbl[state]));
                              break;
           case SERV_ERR_ACK: pvSetImage(p, id, pvtr(plc_err_img_tbl[state]));
                              break;
           case SERV_STP_RUN: pvSetImage(p, id, pvtr(stp_run_img_tbl[state]));
                              break;
           case SERV_ON_OFF : printf(PROCESSING_UNEXISTED, serv_id); break;
           case SERV_REBOOT : printf(PROCESSING_UNEXISTED, serv_id); break;
        }
     }
  }
  */
  //!-----------------------------------------------------------------  
  //! devices Auto/Manual, Enable/Disable and Start/Stop ui
  //!-----------------------------------------------------------------  
  for (int i = 0; i < MAN_OPER_DEV_NUM; i++){
     ///if (dev_stateList[i].exist){
        //! Auto/Manual button ui
        /*if (!d->dev_ui_tbl[i].AM_ui.btn_ui.up2d){
           id      = d->dev_ui_tbl[i].AM_ui.btn_ui.ui_id;
           state   = d->dev_ui_tbl[i].AM_ui.btn_ui.state;
           pvSetText(p, id, pvtr(AM_btn_txt[state]));
           d->dev_ui_tbl[i].AM_ui.btn_ui.up2d = 1;
        }
        state   = dev_stateList[i].man_stat;
        disable = (d->ui_cur_mode == MODE_IN_REQUEST || 
                   d->servs_tbl[SERV_ALL_TO].enbl == 0 ||
                   state == AUTO_DCN || state == MAN_DCN);
        pvSetEnabled(p, id, !disable);
        //! Auto/Manual image ui
        if (!d->dev_ui_tbl[i].AM_ui.img_ui.up2d){
           id      = d->dev_ui_tbl[i].AM_ui.img_ui.ui_id;
           state   = d->dev_ui_tbl[i].AM_ui.img_ui.state;

           pvSetImage(p, id, pvtr(img_dev_res_tbl[state]));
           d->dev_ui_tbl[i].AM_ui.img_ui.up2d = 1;
        }
        */
        /* 
        //! Enable/Disable button ui
        if (!d->dev_ui_tbl[i].enbl_ui.btn_ui.up2d){
           id      = d->dev_ui_tbl[i].enbl_ui.btn_ui.ui_id;
           state   = d->dev_ui_tbl[i].enbl_ui.btn_ui.state;
           pvSetText(p, id, pvtr(enbl_btn_txt[state]));
           d->dev_ui_tbl[i].enbl_ui.btn_ui.up2d = 1;
        }
        state   = dev_stateList[i].cur_enbl;
        disable = (d->ui_cur_mode == MODE_IN_REQUEST ||
                   state == ENBL_DCN || state == DIS_DCN ||
                   d->dev_ui_tbl[i].AM_ui.btn_ui.state == SWITCH_MAN);
        pvSetEnabled(p, id, !disable);

        //! Enable/Disable image ui
        if (!d->dev_ui_tbl[i].enbl_ui.img_ui.up2d){
           id      = d->dev_ui_tbl[i].enbl_ui.img_ui.ui_id;
           state   = d->dev_ui_tbl[i].enbl_ui.img_ui.state;
           //printf("showData(): img file name is '%s'\n", img_dev_res_tbl[state]);
           pvSetImage(p, id, pvtr(img_dev_res_tbl[state]));
           d->dev_ui_tbl[i].enbl_ui.img_ui.up2d = 1;
        }
        */
        //! Locked label ui
        /*if (!d->dev_ui_tbl[i].lock_ui.up2d){
           id      = d->dev_ui_tbl[i].lock_ui.ui_id;
           state   = d->dev_ui_tbl[i].lock_ui.state;
           if (state == LOCKED){
              if (i == DEV_ACT){
                 pvHide(p, btnAct_Up);
                 pvHide(p, btnAct_Down);
              } else {
                pvHide(p, d->dev_ui_tbl[i].run_ui.btn_ui.ui_id);
              }
              pvShow(p, id);
           } else {
              pvHide(p, id);
              if (i == DEV_ACT){
                 pvShow(p, btnAct_Up);
                 pvShow(p, btnAct_Down);
              } else {
                pvShow(p, d->dev_ui_tbl[i].run_ui.btn_ui.ui_id);
              }
           }
           d->dev_ui_tbl[i].lock_ui.up2d = 1;
        }
        */
        //! Start/Stop button ui
        if (!d->dev_ui_tbl[i].run_ui.btn_ui.up2d){
           id      = d->dev_ui_tbl[i].run_ui.btn_ui.ui_id;
           state   = d->dev_ui_tbl[i].run_ui.btn_ui.state;
           //printf("%s\n", run_btn_txt[16]);
           //printf("button state is %d\n", state);
           pvSetText(p, id, pvtr(run_btn_txt[state]));
           //pvSetText(p, id, pvtr(TXT_SERV_STOP));
           
           d->dev_ui_tbl[i].run_ui.btn_ui.up2d = 1;
        }
        state   = dev_stateList[i].cur_run;
        /*disable = (d->ui_cur_mode == MODE_IN_REQUEST ||
                   state == ACTIV_DCN || state == INACT_DCN ||
                   d->dev_ui_tbl[i].AM_ui.btn_ui.state == SWITCH_MAN ||
                   d->dev_ui_tbl[i].enbl_ui.img_ui.state == SWITCH_DIS);
        pvSetEnabled(p, id, !disable);
        */
        //! Start/Stop image ui
        if (!d->dev_ui_tbl[i].run_ui.img_ui.up2d){
           id      = d->dev_ui_tbl[i].run_ui.img_ui.ui_id;
           state   = d->dev_ui_tbl[i].run_ui.img_ui.state;
           //printf("image state is %d\n", state);
           pvSetImage(p, id, pvtr(img_dev_res_tbl[state]));
           d->dev_ui_tbl[i].run_ui.img_ui.up2d = 1;
        }
     ///}
  }
  /*
  //!-----------------------------------------------------------------  
  //! gray/ungray 'Step Up' & 'Step Down' actuator buttons
  //!-----------------------------------------------------------------  
  if (new_act_position != old_act_position){
     if (new_act_position == MIN_ANALOG_DEVICE_VAL){
        pvSetEnabled(p, btnAct_Down, 0);
        pvSetEnabled(p, btnAct_Up, 1);
     } else if (new_act_position == MAX_ANALOG_DEVICE_VAL){
        pvSetEnabled(p, btnAct_Down, 1);
        pvSetEnabled(p, btnAct_Up, 0);
     } else {
        pvSetEnabled(p, btnAct_Down, 1);
        pvSetEnabled(p, btnAct_Up, 1);
     }
     old_act_position = new_act_position;
  } else {
     if (new_act_position == MIN_ANALOG_DEVICE_VAL){
        pvSetEnabled(p, btnAct_Down, 0);
     }
     if (new_act_position == MAX_ANALOG_DEVICE_VAL){
        pvSetEnabled(p, btnAct_Up, 0);
     }
  }


  //!-----------------------------------------------------------------  
  //! showing output values ui for some devices
  //!-----------------------------------------------------------------  
  for (int i = 0; i < 3; i++){
     if (d->serv_out_tbl[i].exist){
        id = d->serv_out_tbl[i].ui_id;
        pvSetText(p, id, pvtr(d->serv_out_tbl[i].txt));
     }
  }
  //!-----------------------------------------------------------------  
  //! Info panel 
  //!-----------------------------------------------------------------
  show_status_message(p, lblStatus, imgInfoMsg);
  */
  return 0;
}
static int readData(DATA *d) // from shared memory, database or something else
{
  if(d == NULL) return 1;
  // (todo: add your code here)
  return 0;
}


int show_mask2(PARAM *p)
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
  showData(p,&d);
  pvClearMessageQueue(p);
  while(1)
  {
    pvPollEvent(p,event);
    switch(pvParseEvent(event, &i, text))
    {
      case NULL_EVENT:
        readData(&d); // from shared memory, database or something else
        update_ui_modes(p,&d);
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
