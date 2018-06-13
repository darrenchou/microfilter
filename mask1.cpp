////////////////////////////////////////////////////////////////////////////
//
// show_mask1 for ProcessViewServer created: Mon Oct 29 14:34:27 2017
//
////////////////////////////////////////////////////////////////////////////
#include "pvapp.h"

// _begin_of_generated_area_ (do not edit -> use ui2pvc) -------------------

// our mask contains the following objects
enum {
  ID_MAIN_WIDGET = 0,
  frmBg,
  lblHeader,
  imgOsornoLogo,
  frmTopSeparator,
  btnLogout,
  btnMainMenu,
  btnStartStop,
  frmFooter,
  btnMessages,
  lblUserName,
  imgSchematic,
  imgPresSw_IN,
  imgPresSw_AIR,
  imgFilterSem,
  imgMagmeterINSem,
  imgSolenoid_1,
  imgSolenoid_1_man,
  imgSolenoid_2,
  imgSolenoid_2_man,
  imgSolenoid_2_man,
  imgSolenoid_3,
  imgSolenoid_3_man,
  imgSolenoid_4,
  imgSolenoid_A2_man,
  imgDosPump,
  imgDosPump_man,
  imgSolenoid_A2,
  imgSolenoid_A1,
  imgSolenoid_A1_man,
  imgSolenoid_10,
  imgSolenoid_10_man,
  imgTest,
  lblMagmeterName,
  lblMagmeterValue,
  lblTotalizerName,
  lblTotalizerValue,
  imgno_cip_lines,
  imgCIP_lines,
  imgSolenoid_9,
  imgSolenoid_9_man,
  imgSolenoid_7,
  imgSolenoid_7_man,
  lblSolenoid_9,
  btnGoCIP,
  lblMagINFlow,
  lblMagOUTFlow,
  lblMagINTotal,
  lblMagOUTTotal,
  imgExternal_bw,
  imgSolenoid_5,
  imgSolenoid_5_man,
  imgSolenoid_6,
  imgSolenoid_6_man,
  imgMagmeterOut,
  lblMagmeterOUT,
  lblSolenoid3,
  lblSolenoid_1,
  lblSolenoid_A1,
  lblSolenoid_10,
  lblSolenoid_A2,
  lblSolenoid_4,
  lblMagmeterIN,
  lblFilter,
  lblPresSw_IN,
  lblPressSw_AIR,
  lblDosingPump,
  lblSolenoid_2,
  imgext_lvlsw_low,
  imgext_lvlsw_high,
  imgext_lvlsw_emer,
  lblSolenoid_7,
  lblSolenoid_5,
  lblSolenoid_6,
  imgProdFlow,
  ID_END_OF_WIDGETS
};

// our mask contains the following widget names
  static const char *widgetName[] = {
  "ID_MAIN_WIDGET",
  "frmBg",
  "lblHeader",
  "imgOsornoLogo",
  "frmTopSeparator",
  "btnLogout",
  "btnMainMenu",
  "btnStartStop",
  "frmFooter",
  "btnMessages",
  "lblUserName",
  "imgSchematic",
  "imgPresSw_IN",
  "imgPresSw_AIR",
  "imgFilterSem",
  "imgMagmeterINSem",
  "imgSolenoid_1",
  "imgSolenoid_1_man",
  "imgSolenoid_2",
  "imgSolenoid_2_man",
  "imgSolenoid_2_man",
  "imgSolenoid_3",
  "imgSolenoid_3_man",
  "imgSolenoid_4",
  "imgSolenoid_A2_man",
  "imgDosPump",
  "imgDosPump_man",
  "imgSolenoid_A2",
  "imgSolenoid_A1",
  "imgSolenoid_A1_man",
  "imgSolenoid_10",
  "imgSolenoid_10_man",
  "imgTest",
  "lblMagmeterName",
  "lblMagmeterValue",
  "lblTotalizerName",
  "lblTotalizerValue",
  "imgno_cip_lines",
  "imgCIP_lines",
  "imgSolenoid_9",
  "imgSolenoid_9_man",
  "imgSolenoid_7",
  "imgSolenoid_7_man",
  "lblSolenoid_9",
  "btnGoCIP",
  "lblMagINFlow",
  "lblMagOUTFlow",
  "lblMagINTotal",
  "lblMagOUTTotal",
  "imgExternal_bw",
  "imgSolenoid_5",
  "imgSolenoid_5_man",
  "imgSolenoid_6",
  "imgSolenoid_6_man",
  "imgMagmeterOut",
  "lblMagmeterOUT",
  "lblSolenoid3",
  "lblSolenoid_1",
  "lblSolenoid_A1",
  "lblSolenoid_10",
  "lblSolenoid_A2",
  "lblSolenoid_4",
  "lblMagmeterIN",
  "lblFilter",
  "lblPresSw_IN",
  "lblPressSw_AIR",
  "lblDosingPump",
  "lblSolenoid_2",
  "imgext_lvlsw_low",
  "imgext_lvlsw_high",
  "imgext_lvlsw_emer",
  "lblSolenoid_7",
  "lblSolenoid_5",
  "lblSolenoid_6",
  "imgProdFlow",
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
  ""};

  static const char *whatsThis[] = {
  "",
  "",
  "",
  "images/misc/osorno_logo.png",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "images/misc/microfiltr_four.png",
  "",
  "",
  "images/icons25x25/gray25x25.png",
  "images/icons25x25/gray25x25.png",
  "images/icons25x25/gray25x25.png",
  "",
  "images/icons25x25/gray25x25.png",
  "",
  "",
  "images/icons25x25/gray25x25.png",
  "",
  "images/icons25x25/gray25x25.png",
  "",
  "images/icons25x25/gray25x25.png",
  "",
  "images/icons25x25/gray25x25.png",
  "images/icons25x25/gray25x25.png",
  "",
  "images/icons25x25/gray25x25.png",
  "",
  "/home/bzhou_local/project/micro_image/giphy.gif",
  "",
  "",
  "",
  "",
  "images/misc/no_cip_lines.png",
  "images/misc/cip_lines.png",
  "images/icons25x25/gray25x25.png",
  "",
  "images/icons25x25/gray25x25.png",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "images/misc/external_bw.png",
  "images/icons25x25/gray25x25.png",
  "",
  "images/icons25x25/gray25x25.png",
  "",
  "images/icons25x25/gray25x25.png",
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
  "images/icons30x20/lvlsw_inactive.png",
  "",
  "",
  "",
  "",
  "",
  "images/misc/prod_flow.gif",
  ""};

  static const int widgetType[ID_END_OF_WIDGETS+1] = {
  0,
  TQFrame,
  TQLabel,
  TQImage,
  TQFrame,
  TQPushButton,
  TQPushButton,
  TQPushButton,
  TQFrame,
  TQPushButton,
  TQLabel,
  TQImage,
  TQImage,
  TQImage,
  TQImage,
  TQImage,
  TQImage,
  TQImage,
  TQImage,
  TQImage,
  TQImage,
  TQImage,
  TQImage,
  TQImage,
  TQImage,
  TQImage,
  TQImage,
  TQImage,
  TQImage,
  TQImage,
  TQImage,
  TQImage,
  TQImage,
  TQLabel,
  TQLabel,
  TQLabel,
  TQLabel,
  TQImage,
  TQImage,
  TQImage,
  TQImage,
  TQImage,
  TQImage,
  TQLabel,
  TQPushButton,
  TQLabel,
  TQLabel,
  TQLabel,
  TQLabel,
  TQImage,
  TQImage,
  TQImage,
  TQImage,
  TQImage,
  TQImage,
  TQLabel,
  TQLabel,
  TQLabel,
  TQLabel,
  TQLabel,
  TQLabel,
  TQLabel,
  TQLabel,
  TQLabel,
  TQLabel,
  TQLabel,
  TQLabel,
  TQLabel,
  TQImage,
  TQImage,
  TQImage,
  TQLabel,
  TQLabel,
  TQLabel,
  TQImage,
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

  pvQLabel(p,lblHeader,frmBg);
  pvSetGeometry(p,lblHeader,20,20,501,54);
  pvSetText(p,lblHeader,pvtr("Microfiltration Water Treatment"));
  pvSetPaletteForegroundColor(p,lblHeader,120,120,70);
  pvSetFont(p,lblHeader,"Arial",26,0,0,0,0);

  pvDownloadFile(p,"images/misc/osorno_logo.png");
  pvQImage(p,imgOsornoLogo,frmBg,"images/misc/osorno_logo.png",&w,&h,&depth);
  pvSetGeometry(p,imgOsornoLogo,570,22,192,49);
  pvSetFont(p,imgOsornoLogo,"Cantarell",11,0,0,0,0);
  pvSetWhatsThis(p,imgOsornoLogo,pvtr("images/misc/osorno_logo.png"));

  pvQFrame(p,frmTopSeparator,frmBg,HLine,Sunken,1,1);
  pvSetGeometry(p,frmTopSeparator,1,79,800,3);
  pvSetFont(p,frmTopSeparator,"Cantarell",11,0,0,0,0);

  pvQPushButton(p,btnLogout,frmBg);
  pvSetGeometry(p,btnLogout,651,78,130,35);
  pvSetText(p,btnLogout,pvtr("Logout"));
  pvSetFont(p,btnLogout,"Sans Serif",12,0,0,0,0);

  pvQPushButton(p,btnMainMenu,frmBg);
  pvSetGeometry(p,btnMainMenu,20,552,130,35);
  pvSetText(p,btnMainMenu,pvtr("Main Menu"));
  pvSetFont(p,btnMainMenu,"Sans Serif",12,0,0,0,0);

  pvQPushButton(p,btnStartStop,frmBg);
  pvSetGeometry(p,btnStartStop,660,552,130,35);
  pvSetText(p,btnStartStop,pvtr("Start"));
  pvSetFont(p,btnStartStop,"Sans Serif",12,0,0,0,0);

  pvQFrame(p,frmFooter,frmBg,Panel,Raised,1,1);
  pvSetGeometry(p,frmFooter,160,550,479,50);
  pvSetPaletteBackgroundColor(p,frmFooter,120,120,70);
  pvSetFont(p,frmFooter,"Cantarell",11,0,0,0,0);

  pvQPushButton(p,btnMessages,frmFooter);
  pvSetGeometry(p,btnMessages,370,7,99,35);
  pvSetText(p,btnMessages,pvtr("Messages"));
  pvSetFont(p,btnMessages,"Sans Serif",12,0,0,0,0);

  pvQLabel(p,lblUserName,frmBg);
  pvSetGeometry(p,lblUserName,507,78,99,30);
  pvSetText(p,lblUserName,pvtr("  User"));
  pvSetPaletteBackgroundColor(p,lblUserName,120,120,70);
  pvSetFont(p,lblUserName,"Cantarell",11,0,0,0,0);

  pvDownloadFile(p,"images/misc/microfiltr_four.png");
  pvQImage(p,imgSchematic,frmBg,"images/misc/microfiltr_four.png",&w,&h,&depth);
  pvSetGeometry(p,imgSchematic,1,129,800,408);
  pvSetFont(p,imgSchematic,"Cantarell",11,0,0,0,0);
  pvSetWhatsThis(p,imgSchematic,pvtr("images/misc/microfiltr_four.png"));

  pvDownloadFile(p,"images/icons30x20/pressw_inactive.png");
  pvQImage(p,imgPresSw_IN,imgSchematic,"images/icons30x20/pressw_inactive.png",&w,&h,&depth);
  pvSetGeometry(p,imgPresSw_IN,147,156,30,20);
  pvSetFont(p,imgPresSw_IN,"Cantarell",11,0,0,0,0);
  pvSetWhatsThis(p,imgPresSw_IN,pvtr(""));

  pvDownloadFile(p,"images/icons30x20/pressw_inactive.png");
  pvQImage(p,imgPresSw_AIR,imgSchematic,"images/icons30x20/pressw_inactive.png",&w,&h,&depth);
  pvSetGeometry(p,imgPresSw_AIR,498,333,30,20);
  pvSetFont(p,imgPresSw_AIR,"Cantarell",11,0,0,0,0);
  pvSetWhatsThis(p,imgPresSw_AIR,pvtr(""));

  pvDownloadFile(p,"images/icons25x25/gray25x25.png");
  pvQImage(p,imgFilterSem,imgSchematic,"images/icons25x25/gray25x25.png",&w,&h,&depth);
  pvSetGeometry(p,imgFilterSem,113,184,25,25);
  pvSetFont(p,imgFilterSem,"Cantarell",11,0,0,0,0);
  pvSetWhatsThis(p,imgFilterSem,pvtr("images/icons25x25/gray25x25.png"));

  pvDownloadFile(p,"images/icons25x25/gray25x25.png");
  pvQImage(p,imgMagmeterINSem,imgSchematic,"images/icons25x25/gray25x25.png",&w,&h,&depth);
  pvSetGeometry(p,imgMagmeterINSem,192,177,25,25);
  pvSetFont(p,imgMagmeterINSem,"Cantarell",11,0,0,0,0);
  pvSetWhatsThis(p,imgMagmeterINSem,pvtr("images/icons25x25/gray25x25.png"));

  pvDownloadFile(p,"images/icons25x25/gray25x25.png");
  pvQImage(p,imgSolenoid_1,imgSchematic,"images/icons25x25/gray25x25.png",&w,&h,&depth);
  pvSetGeometry(p,imgSolenoid_1,285,300,25,25);
  pvSetFont(p,imgSolenoid_1,"Cantarell",11,0,0,0,0);
  pvSetWhatsThis(p,imgSolenoid_1,pvtr("images/icons25x25/gray25x25.png"));

  pvDownloadFile(p,"images/icons/manual/blackoper.png");
  pvQImage(p,imgSolenoid_1_man,imgSolenoid_1,"images/icons/manual/blackoper.png",&w,&h,&depth);
  pvSetGeometry(p,imgSolenoid_1_man,1,1,24,24);
  pvSetFont(p,imgSolenoid_1_man,"Cantarell",11,0,0,0,0);
  pvSetWhatsThis(p,imgSolenoid_1_man,pvtr(""));

  pvDownloadFile(p,"images/icons25x25/gray25x25.png");
  pvQImage(p,imgSolenoid_2,imgSchematic,"images/icons25x25/gray25x25.png",&w,&h,&depth);
  pvSetGeometry(p,imgSolenoid_2,285,9,25,25);
  pvSetFont(p,imgSolenoid_2,"Cantarell",11,0,0,0,0);
  pvSetWhatsThis(p,imgSolenoid_2,pvtr("images/icons25x25/gray25x25.png"));

  pvDownloadFile(p,"images/icons/manual/blackoper.png");
  pvQImage(p,imgSolenoid_2_man,imgSolenoid_2,"images/icons/manual/blackoper.png",&w,&h,&depth);
  pvSetGeometry(p,imgSolenoid_2_man,1,1,24,24);
  pvSetFont(p,imgSolenoid_2_man,"Cantarell",11,0,0,0,0);
  pvSetWhatsThis(p,imgSolenoid_2_man,pvtr(""));

  pvDownloadFile(p,"images/icons/manual/blackoper.png");
  pvQImage(p,imgSolenoid_2_man,imgSolenoid_2,"images/icons/manual/blackoper.png",&w,&h,&depth);
  pvSetGeometry(p,imgSolenoid_2_man,1,1,24,24);
  pvSetFont(p,imgSolenoid_2_man,"Cantarell",11,0,0,0,0);
  pvSetWhatsThis(p,imgSolenoid_2_man,pvtr(""));

  pvDownloadFile(p,"images/icons25x25/gray25x25.png");
  pvQImage(p,imgSolenoid_3,imgSchematic,"images/icons25x25/gray25x25.png",&w,&h,&depth);
  pvSetGeometry(p,imgSolenoid_3,211,318,25,25);
  pvSetFont(p,imgSolenoid_3,"Cantarell",11,0,0,0,0);
  pvSetWhatsThis(p,imgSolenoid_3,pvtr("images/icons25x25/gray25x25.png"));

  pvDownloadFile(p,"images/icons/manual/blackoper.png");
  pvQImage(p,imgSolenoid_3_man,imgSolenoid_3,"images/icons/manual/blackoper.png",&w,&h,&depth);
  pvSetGeometry(p,imgSolenoid_3_man,1,1,24,24);
  pvSetFont(p,imgSolenoid_3_man,"Cantarell",11,0,0,0,0);
  pvSetWhatsThis(p,imgSolenoid_3_man,pvtr(""));

  pvDownloadFile(p,"images/icons25x25/gray25x25.png");
  pvQImage(p,imgSolenoid_4,imgSchematic,"images/icons25x25/gray25x25.png",&w,&h,&depth);
  pvSetGeometry(p,imgSolenoid_4,554,182,25,25);
  pvSetFont(p,imgSolenoid_4,"Cantarell",11,0,0,0,0);
  pvSetWhatsThis(p,imgSolenoid_4,pvtr("images/icons25x25/gray25x25.png"));

  pvDownloadFile(p,"images/icons/manual/blackoper.png");
  pvQImage(p,imgSolenoid_A2_man,imgSolenoid_4,"images/icons/manual/blackoper.png",&w,&h,&depth);
  pvSetGeometry(p,imgSolenoid_A2_man,1,1,24,24);
  pvSetFont(p,imgSolenoid_A2_man,"Cantarell",11,0,0,0,0);
  pvSetWhatsThis(p,imgSolenoid_A2_man,pvtr(""));

  pvDownloadFile(p,"images/icons25x25/gray25x25.png");
  pvQImage(p,imgDosPump,imgSchematic,"images/icons25x25/gray25x25.png",&w,&h,&depth);
  pvSetGeometry(p,imgDosPump,44,245,25,25);
  pvSetFont(p,imgDosPump,"Cantarell",11,0,0,0,0);
  pvSetWhatsThis(p,imgDosPump,pvtr("images/icons25x25/gray25x25.png"));

  pvDownloadFile(p,"images/icons/manual/blackoper.png");
  pvQImage(p,imgDosPump_man,imgDosPump,"images/icons/manual/blackoper.png",&w,&h,&depth);
  pvSetGeometry(p,imgDosPump_man,1,1,24,24);
  pvSetFont(p,imgDosPump_man,"Cantarell",11,0,0,0,0);
  pvSetWhatsThis(p,imgDosPump_man,pvtr(""));

  pvDownloadFile(p,"images/icons25x25/gray25x25.png");
  pvQImage(p,imgSolenoid_A2,imgSchematic,"images/icons25x25/gray25x25.png",&w,&h,&depth);
  pvSetGeometry(p,imgSolenoid_A2,504,276,25,25);
  pvSetFont(p,imgSolenoid_A2,"Cantarell",11,0,0,0,0);
  pvSetWhatsThis(p,imgSolenoid_A2,pvtr("images/icons25x25/gray25x25.png"));

  pvDownloadFile(p,"images/icons25x25/gray25x25.png");
  pvQImage(p,imgSolenoid_A1,imgSchematic,"images/icons25x25/gray25x25.png",&w,&h,&depth);
  pvSetGeometry(p,imgSolenoid_A1,372,333,25,25);
  pvSetFont(p,imgSolenoid_A1,"Cantarell",11,0,0,0,0);
  pvSetWhatsThis(p,imgSolenoid_A1,pvtr("images/icons25x25/gray25x25.png"));

  pvDownloadFile(p,"images/icons/manual/blackoper.png");
  pvQImage(p,imgSolenoid_A1_man,imgSolenoid_A1,"images/icons/manual/blackoper.png",&w,&h,&depth);
  pvSetGeometry(p,imgSolenoid_A1_man,1,1,24,24);
  pvSetFont(p,imgSolenoid_A1_man,"Cantarell",11,0,0,0,0);
  pvSetWhatsThis(p,imgSolenoid_A1_man,pvtr(""));

  pvDownloadFile(p,"images/icons25x25/gray25x25.png");
  pvQImage(p,imgSolenoid_10,imgSchematic,"images/icons25x25/gray25x25.png",&w,&h,&depth);
  pvSetGeometry(p,imgSolenoid_10,423,276,25,25);
  pvSetFont(p,imgSolenoid_10,"Cantarell",11,0,0,0,0);
  pvSetWhatsThis(p,imgSolenoid_10,pvtr("images/icons25x25/gray25x25.png"));

  pvDownloadFile(p,"images/icons/manual/blackoper.png");
  pvQImage(p,imgSolenoid_10_man,imgSolenoid_10,"images/icons/manual/blackoper.png",&w,&h,&depth);
  pvSetGeometry(p,imgSolenoid_10_man,1,1,24,24);
  pvSetFont(p,imgSolenoid_10_man,"Cantarell",11,0,0,0,0);
  pvSetWhatsThis(p,imgSolenoid_10_man,pvtr(""));

  pvDownloadFile(p,"/home/bzhou_local/project/micro_image/giphy.gif");
  pvQImage(p,imgTest,imgSchematic,"/home/bzhou_local/project/micro_image/giphy.gif",&w,&h,&depth);
  pvSetGeometry(p,imgTest,90,333,59,40);
  pvSetFont(p,imgTest,"Cantarell",11,0,0,0,0);
  pvSetWhatsThis(p,imgTest,pvtr("/home/bzhou_local/project/micro_image/giphy.gif"));

  pvQLabel(p,lblMagmeterName,imgSchematic);
  pvSetGeometry(p,lblMagmeterName,51,384,129,27);
  pvSetText(p,lblMagmeterName,pvtr("Magmeter Flow"));
  pvSetPaletteForegroundColor(p,lblMagmeterName,255,255,255);
  pvSetPaletteBackgroundColor(p,lblMagmeterName,120,120,70);
  pvSetFont(p,lblMagmeterName,"Cantarell",11,1,0,0,0);

  pvQLabel(p,lblMagmeterValue,imgSchematic);
  pvSetGeometry(p,lblMagmeterValue,171,384,139,27);
  pvSetText(p,lblMagmeterValue,pvtr("Magmeter Value"));
  pvSetFont(p,lblMagmeterValue,"Cantarell",11,0,0,0,0);

  pvQLabel(p,lblTotalizerName,imgSchematic);
  pvSetGeometry(p,lblTotalizerName,324,384,109,27);
  pvSetText(p,lblTotalizerName,pvtr("   Totalizer"));
  pvSetPaletteForegroundColor(p,lblTotalizerName,255,255,255);
  pvSetPaletteBackgroundColor(p,lblTotalizerName,0,0,0);
  pvSetFont(p,lblTotalizerName,"Cantarell",11,1,0,0,0);

  pvQLabel(p,lblTotalizerValue,imgSchematic);
  pvSetGeometry(p,lblTotalizerValue,462,384,129,27);
  pvSetText(p,lblTotalizerValue,pvtr("Totalizer Value"));
  pvSetFont(p,lblTotalizerValue,"Cantarell",11,0,0,0,0);

  pvDownloadFile(p,"images/misc/no_cip_lines.png");
  pvQImage(p,imgno_cip_lines,imgSchematic,"images/misc/no_cip_lines.png",&w,&h,&depth);
  pvSetGeometry(p,imgno_cip_lines,23,33,240,120);
  pvSetFont(p,imgno_cip_lines,"Cantarell",11,0,0,0,0);
  pvSetWhatsThis(p,imgno_cip_lines,pvtr("images/misc/no_cip_lines.png"));

  pvDownloadFile(p,"images/misc/cip_lines.png");
  pvQImage(p,imgCIP_lines,imgno_cip_lines,"images/misc/cip_lines.png",&w,&h,&depth);
  pvSetGeometry(p,imgCIP_lines,0,0,240,120);
  pvSetFont(p,imgCIP_lines,"Cantarell",11,0,0,0,0);
  pvSetWhatsThis(p,imgCIP_lines,pvtr("images/misc/cip_lines.png"));

  pvDownloadFile(p,"images/icons25x25/gray25x25.png");
  pvQImage(p,imgSolenoid_9,imgCIP_lines,"images/icons25x25/gray25x25.png",&w,&h,&depth);
  pvSetGeometry(p,imgSolenoid_9,189,48,25,25);
  pvSetFont(p,imgSolenoid_9,"Cantarell",11,0,0,0,0);
  pvSetWhatsThis(p,imgSolenoid_9,pvtr("images/icons25x25/gray25x25.png"));

  pvDownloadFile(p,"images/icons/manual/blackoper.png");
  pvQImage(p,imgSolenoid_9_man,imgSolenoid_9,"images/icons/manual/blackoper.png",&w,&h,&depth);
  pvSetGeometry(p,imgSolenoid_9_man,1,1,24,24);
  pvSetFont(p,imgSolenoid_9_man,"Cantarell",11,0,0,0,0);
  pvSetWhatsThis(p,imgSolenoid_9_man,pvtr(""));

  pvDownloadFile(p,"images/icons25x25/gray25x25.png");
  pvQImage(p,imgSolenoid_7,imgCIP_lines,"images/icons25x25/gray25x25.png",&w,&h,&depth);
  pvSetGeometry(p,imgSolenoid_7,90,24,25,25);
  pvSetFont(p,imgSolenoid_7,"Cantarell",11,0,0,0,0);
  pvSetWhatsThis(p,imgSolenoid_7,pvtr("images/icons25x25/gray25x25.png"));

  pvDownloadFile(p,"images/icons/manual/blackoper.png");
  pvQImage(p,imgSolenoid_7_man,imgSolenoid_7,"images/icons/manual/blackoper.png",&w,&h,&depth);
  pvSetGeometry(p,imgSolenoid_7_man,1,1,24,24);
  pvSetFont(p,imgSolenoid_7_man,"Cantarell",11,0,0,0,0);
  pvSetWhatsThis(p,imgSolenoid_7_man,pvtr(""));

  pvQLabel(p,lblSolenoid_9,imgCIP_lines);
  pvSetGeometry(p,lblSolenoid_9,138,78,59,25);
  pvSetText(p,lblSolenoid_9,pvtr("Solenoid9"));
  pvSetPaletteForegroundColor(p,lblSolenoid_9,255,255,255);
  pvSetPaletteBackgroundColor(p,lblSolenoid_9,150,150,100);
  pvSetFont(p,lblSolenoid_9,"Cantarell",7,0,0,0,0);

  pvQPushButton(p,btnGoCIP,imgCIP_lines);
  pvSetGeometry(p,btnGoCIP,9,60,99,30);
  pvSetText(p,btnGoCIP,pvtr("<- show CIP"));
  pvSetFont(p,btnGoCIP,"Cantarell",11,0,0,0,0);

  pvQLabel(p,lblMagINFlow,imgSchematic);
  pvSetGeometry(p,lblMagINFlow,681,275,79,20);
  pvSetText(p,lblMagINFlow,pvtr("n/a"));
  pvSetPaletteBackgroundColor(p,lblMagINFlow,255,255,255);
  pvSetFont(p,lblMagINFlow,"Cantarell",11,0,0,0,0);

  pvQLabel(p,lblMagOUTFlow,imgSchematic);
  pvSetGeometry(p,lblMagOUTFlow,681,297,79,20);
  pvSetText(p,lblMagOUTFlow,pvtr("n/a"));
  pvSetPaletteBackgroundColor(p,lblMagOUTFlow,255,255,255);
  pvSetFont(p,lblMagOUTFlow,"Cantarell",11,0,0,0,0);

  pvQLabel(p,lblMagINTotal,imgSchematic);
  pvSetGeometry(p,lblMagINTotal,672,351,99,20);
  pvSetText(p,lblMagINTotal,pvtr(" n/a"));
  pvSetPaletteBackgroundColor(p,lblMagINTotal,255,255,255);
  pvSetFont(p,lblMagINTotal,"Cantarell",11,0,0,0,0);

  pvQLabel(p,lblMagOUTTotal,imgSchematic);
  pvSetGeometry(p,lblMagOUTTotal,672,372,99,20);
  pvSetText(p,lblMagOUTTotal,pvtr(" n/a"));
  pvSetPaletteBackgroundColor(p,lblMagOUTTotal,255,255,255);
  pvSetFont(p,lblMagOUTTotal,"Cantarell",11,0,0,0,0);

  pvDownloadFile(p,"images/misc/external_bw.png");
  pvQImage(p,imgExternal_bw,imgSchematic,"images/misc/external_bw.png",&w,&h,&depth);
  pvSetGeometry(p,imgExternal_bw,518,1,269,96);
  pvSetFont(p,imgExternal_bw,"Cantarell",11,0,0,0,0);
  pvSetWhatsThis(p,imgExternal_bw,pvtr("images/misc/external_bw.png"));

  pvDownloadFile(p,"images/icons25x25/gray25x25.png");
  pvQImage(p,imgSolenoid_5,imgExternal_bw,"images/icons25x25/gray25x25.png",&w,&h,&depth);
  pvSetGeometry(p,imgSolenoid_5,190,36,25,25);
  pvSetFont(p,imgSolenoid_5,"Cantarell",11,0,0,0,0);
  pvSetWhatsThis(p,imgSolenoid_5,pvtr("images/icons25x25/gray25x25.png"));

  pvDownloadFile(p,"images/icons/manual/blackoper.png");
  pvQImage(p,imgSolenoid_5_man,imgSolenoid_5,"images/icons/manual/blackoper.png",&w,&h,&depth);
  pvSetGeometry(p,imgSolenoid_5_man,1,1,24,24);
  pvSetFont(p,imgSolenoid_5_man,"Cantarell",11,0,0,0,0);
  pvSetWhatsThis(p,imgSolenoid_5_man,pvtr(""));

  pvDownloadFile(p,"images/icons25x25/gray25x25.png");
  pvQImage(p,imgSolenoid_6,imgExternal_bw,"images/icons25x25/gray25x25.png",&w,&h,&depth);
  pvSetGeometry(p,imgSolenoid_6,47,26,25,25);
  pvSetFont(p,imgSolenoid_6,"Cantarell",11,0,0,0,0);
  pvSetWhatsThis(p,imgSolenoid_6,pvtr("images/icons25x25/gray25x25.png"));

  pvDownloadFile(p,"images/icons/manual/blackoper.png");
  pvQImage(p,imgSolenoid_6_man,imgSolenoid_6,"images/icons/manual/blackoper.png",&w,&h,&depth);
  pvSetGeometry(p,imgSolenoid_6_man,1,1,24,24);
  pvSetFont(p,imgSolenoid_6_man,"Cantarell",11,0,0,0,0);
  pvSetWhatsThis(p,imgSolenoid_6_man,pvtr(""));

  pvDownloadFile(p,"images/icons25x25/gray25x25.png");
  pvQImage(p,imgMagmeterOut,imgExternal_bw,"images/icons25x25/gray25x25.png",&w,&h,&depth);
  pvSetGeometry(p,imgMagmeterOut,120,60,25,25);
  pvSetFont(p,imgMagmeterOut,"Cantarell",11,0,0,0,0);
  pvSetWhatsThis(p,imgMagmeterOut,pvtr("images/icons25x25/gray25x25.png"));

  pvQLabel(p,lblMagmeterOUT,imgExternal_bw);
  pvSetGeometry(p,lblMagmeterOUT,108,18,59,20);
  pvSetText(p,lblMagmeterOUT,pvtr("   MG2"));
  pvSetPaletteForegroundColor(p,lblMagmeterOUT,255,255,255);
  pvSetPaletteBackgroundColor(p,lblMagmeterOUT,150,150,100);
  pvSetFont(p,lblMagmeterOUT,"Cantarell",8,0,0,0,0);

  pvQLabel(p,lblSolenoid3,imgSchematic);
  pvSetGeometry(p,lblSolenoid3,177,282,65,25);
  pvSetText(p,lblSolenoid3,pvtr("Solenoid3"));
  pvSetPaletteForegroundColor(p,lblSolenoid3,255,255,255);
  pvSetPaletteBackgroundColor(p,lblSolenoid3,150,150,100);
  pvSetFont(p,lblSolenoid3,"Cantarell",8,0,0,0,0);

  pvQLabel(p,lblSolenoid_1,imgSchematic);
  pvSetGeometry(p,lblSolenoid_1,276,336,65,25);
  pvSetText(p,lblSolenoid_1,pvtr("Solenoid1"));
  pvSetPaletteForegroundColor(p,lblSolenoid_1,255,255,255);
  pvSetPaletteBackgroundColor(p,lblSolenoid_1,150,150,100);
  pvSetFont(p,lblSolenoid_1,"Cantarell",8,0,0,0,0);

  pvQLabel(p,lblSolenoid_A1,imgSchematic);
  pvSetGeometry(p,lblSolenoid_A1,401,339,65,25);
  pvSetText(p,lblSolenoid_A1,pvtr("SolenoidA1"));
  pvSetPaletteForegroundColor(p,lblSolenoid_A1,255,255,255);
  pvSetPaletteBackgroundColor(p,lblSolenoid_A1,150,150,100);
  pvSetFont(p,lblSolenoid_A1,"Cantarell",8,0,0,0,0);

  pvQLabel(p,lblSolenoid_10,imgSchematic);
  pvSetGeometry(p,lblSolenoid_10,349,276,65,25);
  pvSetText(p,lblSolenoid_10,pvtr("Solenoid10"));
  pvSetPaletteForegroundColor(p,lblSolenoid_10,255,255,255);
  pvSetPaletteBackgroundColor(p,lblSolenoid_10,150,150,100);
  pvSetFont(p,lblSolenoid_10,"Cantarell",8,0,0,0,0);

  pvQLabel(p,lblSolenoid_A2,imgSchematic);
  pvSetGeometry(p,lblSolenoid_A2,533,228,63,25);
  pvSetText(p,lblSolenoid_A2,pvtr("SolenoidA2"));
  pvSetPaletteForegroundColor(p,lblSolenoid_A2,255,255,255);
  pvSetPaletteBackgroundColor(p,lblSolenoid_A2,150,150,100);
  pvSetFont(p,lblSolenoid_A2,"Cantarell",8,0,0,0,0);

  pvQLabel(p,lblSolenoid_4,imgSchematic);
  pvSetGeometry(p,lblSolenoid_4,535,121,55,25);
  pvSetText(p,lblSolenoid_4,pvtr("Solenoid4"));
  pvSetPaletteForegroundColor(p,lblSolenoid_4,255,255,255);
  pvSetPaletteBackgroundColor(p,lblSolenoid_4,150,150,100);
  pvSetFont(p,lblSolenoid_4,"Cantarell",8,0,0,0,0);

  pvQLabel(p,lblMagmeterIN,imgSchematic);
  pvSetGeometry(p,lblMagmeterIN,180,213,60,25);
  pvSetText(p,lblMagmeterIN,pvtr("    MG1"));
  pvSetPaletteForegroundColor(p,lblMagmeterIN,255,255,255);
  pvSetPaletteBackgroundColor(p,lblMagmeterIN,150,150,100);
  pvSetFont(p,lblMagmeterIN,"Cantarell",8,0,0,0,0);

  pvQLabel(p,lblFilter,imgSchematic);
  pvSetGeometry(p,lblFilter,69,150,65,25);
  pvSetText(p,lblFilter,pvtr("    Filter"));
  pvSetPaletteForegroundColor(p,lblFilter,255,255,255);
  pvSetPaletteBackgroundColor(p,lblFilter,150,150,100);
  pvSetFont(p,lblFilter,"Cantarell",8,0,0,0,0);

  pvQLabel(p,lblPresSw_IN,imgSchematic);
  pvSetGeometry(p,lblPresSw_IN,180,151,60,20);
  pvSetText(p,lblPresSw_IN,pvtr("PressSW_IN"));
  pvSetPaletteForegroundColor(p,lblPresSw_IN,255,255,255);
  pvSetPaletteBackgroundColor(p,lblPresSw_IN,150,150,100);
  pvSetFont(p,lblPresSw_IN,"Cantarell",7,0,0,0,0);

  pvQLabel(p,lblPressSw_AIR,imgSchematic);
  pvSetGeometry(p,lblPressSw_AIR,526,339,60,20);
  pvSetText(p,lblPressSw_AIR,pvtr("PressSw_AIR"));
  pvSetPaletteForegroundColor(p,lblPressSw_AIR,255,255,255);
  pvSetPaletteBackgroundColor(p,lblPressSw_AIR,150,150,100);
  pvSetFont(p,lblPressSw_AIR,"Cantarell",7,0,0,0,0);

  pvQLabel(p,lblDosingPump,imgSchematic);
  pvSetGeometry(p,lblDosingPump,54,216,50,20);
  pvSetText(p,lblDosingPump,pvtr("DosPump"));
  pvSetPaletteForegroundColor(p,lblDosingPump,255,255,255);
  pvSetPaletteBackgroundColor(p,lblDosingPump,150,150,100);
  pvSetFont(p,lblDosingPump,"Cantarell",7,0,0,0,0);

  pvQLabel(p,lblSolenoid_2,imgSchematic);
  pvSetGeometry(p,lblSolenoid_2,333,6,65,25);
  pvSetText(p,lblSolenoid_2,pvtr("Solenoid2"));
  pvSetPaletteForegroundColor(p,lblSolenoid_2,255,255,255);
  pvSetPaletteBackgroundColor(p,lblSolenoid_2,150,150,100);
  pvSetFont(p,lblSolenoid_2,"Cantarell",8,0,0,0,0);

  pvDownloadFile(p,"images/icons30x20/lvlsw_inactive.png");
  pvQImage(p,imgext_lvlsw_low,imgSchematic,"images/icons30x20/lvlsw_inactive.png",&w,&h,&depth);
  pvSetGeometry(p,imgext_lvlsw_low,651,201,59,30);
  pvSetFont(p,imgext_lvlsw_low,"Cantarell",11,0,0,0,0);
  pvSetWhatsThis(p,imgext_lvlsw_low,pvtr(""));

  pvDownloadFile(p,"images/icons30x20/lvlsw_inactive.png");
  pvQImage(p,imgext_lvlsw_high,imgSchematic,"images/icons30x20/lvlsw_inactive.png",&w,&h,&depth);
  pvSetGeometry(p,imgext_lvlsw_high,651,165,59,30);
  pvSetFont(p,imgext_lvlsw_high,"Cantarell",11,0,0,0,0);
  pvSetWhatsThis(p,imgext_lvlsw_high,pvtr(""));

  pvDownloadFile(p,"images/icons30x20/lvlsw_inactive.png");
  pvQImage(p,imgext_lvlsw_emer,imgSchematic,"images/icons30x20/lvlsw_inactive.png",&w,&h,&depth);
  pvSetGeometry(p,imgext_lvlsw_emer,651,123,59,30);
  pvSetFont(p,imgext_lvlsw_emer,"Cantarell",11,0,0,0,0);
  pvSetWhatsThis(p,imgext_lvlsw_emer,pvtr(""));

  pvQLabel(p,lblSolenoid_7,imgSchematic);
  pvSetGeometry(p,lblSolenoid_7,144,3,59,25);
  pvSetText(p,lblSolenoid_7,pvtr("Solenoid7"));
  pvSetPaletteForegroundColor(p,lblSolenoid_7,255,255,255);
  pvSetPaletteBackgroundColor(p,lblSolenoid_7,150,150,100);
  pvSetFont(p,lblSolenoid_7,"Cantarell",7,0,0,0,0);

  pvQLabel(p,lblSolenoid_5,imgSchematic);
  pvSetGeometry(p,lblSolenoid_5,684,89,59,25);
  pvSetText(p,lblSolenoid_5,pvtr("Solenoid5"));
  pvSetPaletteForegroundColor(p,lblSolenoid_5,255,255,255);
  pvSetPaletteBackgroundColor(p,lblSolenoid_5,150,150,100);
  pvSetFont(p,lblSolenoid_5,"Cantarell",8,0,0,0,0);

  pvQLabel(p,lblSolenoid_6,imgSchematic);
  pvSetGeometry(p,lblSolenoid_6,462,1,59,25);
  pvSetText(p,lblSolenoid_6,pvtr("Solenoid6"));
  pvSetPaletteForegroundColor(p,lblSolenoid_6,255,255,255);
  pvSetPaletteBackgroundColor(p,lblSolenoid_6,150,150,100);
  pvSetFont(p,lblSolenoid_6,"Cantarell",8,0,0,0,0);

  pvDownloadFile(p,"images/misc/prod_flow.gif");
  pvQImage(p,imgProdFlow,0,"images/misc/prod_flow.gif",&w,&h,&depth);
  pvSetGeometry(p,imgProdFlow,327,636,750,188);
  pvSetFont(p,imgProdFlow,"Cantarell",11,0,0,0,0);
  pvSetWhatsThis(p,imgProdFlow,pvtr("images/misc/prod_flow.gif"));


  pvEndDefinition(p);
  return 0;
}

// _end_of_generated_area_ (do not edit -> use ui2pvc) ---------------------
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "mask1_slots.h"
#include "osornoconf.h"

#define FILE_MAP_A "images/misc/microfiltr_four.png"
#define FILE_MAP   "images/misc/microfiltr_two.png"
#define EXT_BW     "images/misc/external_bw.png"
#define NO_EXT_BW  "images/misc/no_ext_bw.png"




static adjustable_ui_t four_ext_cip[] = {
    //!     id             group    x    y    w    h   v   txt
    { imgSchematic   , GR_NOGROUP,   1,   1, 800, 600, 1, FILE_MAP     },
    { imgSolenoid_5  , GR_NOGROUP, 190,  36,  25,  25, 1, MSG_BLANK    },
    { imgSolenoid_6  , GR_NOGROUP,  47,  26,  25,  25, 1, MSG_BLANK    },
    { imgSolenoid_7  , GR_NOGROUP,  90,  24,  25,  25, 1, MSG_BLANK    },
    { imgSolenoid_9  , GR_NOGROUP,  189, 48,  25,  25, 1, MSG_BLANK    },
    

    /*{ frmBlower2     , GR_BLOWER2, 395,  92, 116,  31, 1, MSG_BLANK    },
    { frmLogInOut    , GR_NOGROUP, 514,  92, 255,  31, 1, MSG_BLANK    },
    { frmFacilities  , GR_FACILIT,   5,  92, 150,  31, 1, MSG_BLANK    },
    { lblFacilities  , GR_FACILIT,  22,   3, 100,  25, 1, MSG_BLANK    },
    { frmFacilStatus , GR_FACILIT,   5, 123, 150,  95, 1, MSG_BLANK    },
    { frmActFlow     , GR_NOGROUP,   5, 224, 150,  30, 1, MSG_BLANK    },
    { lblActFlow     , GR_NOGROUP,  35,   3,  90,  25, 1, MSG_INFLOW   },
    { frmActFlowVal  , GR_NOGROUP,   5, 254, 150,  40, 1, MSG_BLANK    },
    { lblActFlowVal  , GR_NOGROUP,  15,   7, 100,  25, 1, MSG_VAL_QMPH },
    { frmMagmeter    , GR_NOGROUP,   5, 352, 150,  30, 1, MSG_BLANK    },
    { lblMagmeter    , GR_NOGROUP,  22,   3,  90,  25, 1, MSG_TOTALISER},
    { frmMagmeterVal , GR_NOGROUP,   5, 382, 150,  58, 1, MSG_BLANK    },
    { lblMagmTotVal  , GR_NOGROUP,   5,  15, 120,  25, 1, MSG_TOTAL_VAL},
    { lblMagmFlowVal , GR_NOGROUP, 205,   3, 145,  25, 0, MSG_BLANK    },
    { frmPowerHeader , GR_NOGROUP,   5, 447, 150,  30, 1, MSG_BLANK    },
    { frmPower       , GR_NOGROUP,   5, 477, 150,  60, 1, MSG_BLANK    },
    { frmBlower1A    , GR_NOGROUP, 160,  92, 115,  31, 1, MSG_BLANK    },
    { frmBlower1B    , GR_NOGROUP, 278,  92, 114,  31, 1, MSG_BLANK    },
    { frmLvlControls , GR_NOGROUP, 515, 269, 113,  49, 1, MSG_BLANK    },
    { frmOutflow     , GR_NOGROUP, 674, 244,  96,  31, 1, MSG_BLANK    },
    { frmUVunit      , GR_NOGROUP, 601, 128,  78,  31, 1, MSG_BLANK    },
    { frmUVunitVal   , GR_NOGROUP, 601, 159,  78,  30, 1, MSG_BLANK    },
    { frmChamber1A   , GR_NOGROUP, 160, 447, 115,  30, 1, MSG_BLANK    },
    { frmChamb1A_Val , GR_NOGROUP, 160, 477, 115,  60, 1, MSG_BLANK    },
    { frmChamber1B   , GR_NOGROUP, 278, 447, 115,  30, 1, MSG_BLANK    },
    { frmChamb1B_Val , GR_NOGROUP, 278, 477, 115,  60, 1, MSG_BLANK    },
    { frmChamber2    , GR_NOGROUP, 396, 447, 115,  30, 1, MSG_BLANK    },
    { frmChamber3    , GR_NOGROUP, 514, 447, 115,  30, 1, MSG_BLANK    },
    { lblChamber3    , GR_NOGROUP,   9,   3, 105,  25, 1, MSG_BLANK    },
    { frmChamb3_Val  , GR_CH3_FRM, 514, 477, 114,  60, 1, MSG_BLANK    },
    { lblTank3Level  , GR_CH3_LVL,   7,   1, 100,  20, 1, MSG_BLANK    },
    { lblCH3_1       , GR_CH3_SEN,   8,  19, 100,  20, 1, MSG_BLANK    },
    { lblCH3_2       , GR_CH3_SEN,   8,  37, 100,  20, 1, MSG_BLANK    },
    { frmPump1       , GR_NOGROUP, 631, 447,  68,  30, 1, MSG_BLANK    },
    { frmPump2       , GR_NOGROUP, 702, 447,  70,  30, 1, MSG_BLANK    },
    { imgBlower2     , GR_BLOWER2, 425, 128,  55,  73, 1, MSG_BLANK    },
    { frmTank3_Lvl   , GR_NOGROUP, 512, 323, 117, 118, 1, MSG_BLANK    },
    { imgLvlSwitch   , GR_T3_LVLS, 519, 318,  30, 120, 1, MSG_BLANK    },
    { imgLvlSensor   , GR_T3_LVLS, 592, 318,  30,  35, 1, MSG_BLANK    },
    { imgCh1A_bbl1   , GR_NOGROUP, 191, 333,  60,  90, 1, MSG_BLANK    },
    { imgCh1A_bbl2   , GR_NOGROUP, 191, 333,  60,  90, 1, MSG_BLANK    },
    { imgCh1A_bbl3   , GR_NOGROUP, 191, 325,  60,  90, 1, MSG_BLANK    },
    { imgCh1A_bbl4   , GR_NOGROUP, 191, 308,  60,  90, 1, MSG_BLANK    },
    { imgCh1A_bbl5   , GR_NOGROUP, 191, 308,  60,  90, 1, MSG_BLANK    },
    { imgCh1B_bbl1   , GR_NOGROUP, 307, 333,  60,  90, 1, MSG_BLANK    },
    { imgCh1B_bbl2   , GR_NOGROUP, 307, 333,  60,  90, 1, MSG_BLANK    },
    { imgCh1B_bbl3   , GR_NOGROUP, 307, 325,  60,  90, 1, MSG_BLANK    },
    { imgCh1B_bbl4   , GR_NOGROUP, 307, 308,  60,  90, 1, MSG_BLANK    },
    { imgCh1B_bbl5   , GR_NOGROUP, 307, 308,  60,  90, 1, MSG_BLANK    },
    { imgTank3Number , GR_NOGROUP, 548, 318,  48,  80, 1, MSG_BLANK    },
    { imgValve       , GR_NOGROUP, 934, 305,  33,  33, 0, MSG_BLANK    },
    { imgActuatorStat, GR_NOGROUP, 933, 253,  34,  34, 0, MSG_BLANK    },
    { imgMagmeterStat, GR_NOGROUP,  76, 304,  40,  40, 1, MSG_BLANK    },
    { imgBlower1AStat, GR_NOGROUP, 199, 136,  40,  40, 1, MSG_BLANK    },
    { imgBlower1BStat, GR_NOGROUP, 316, 136,  40,  40, 1, MSG_BLANK    },
    { imgUV_Status   , GR_NOGROUP, 625, 201,  34,  40, 1, MSG_BLANK    },
    { imgPump1Status , GR_NOGROUP, 649, 353,  40,  40, 1, MSG_BLANK    },
    { imgPump2Status , GR_NOGROUP, 713, 353,  40,  40, 1, MSG_BLANK    },
    { frmChamb2_Val  , GR_BLOWER2, 396, 477, 115,  60, 1, MSG_BLANK    },
    { frmLiftStation , GR_LIFT_ST, 631, 479, 155,  28, 1, MSG_BLANK    },
    { frmLiftVal     , GR_LIFT_ST, 631, 507, 155,  30, 1, MSG_BLANK    },
    { frmOutFlow     , GR_FLOW_SW, 680, 128,  88,  31, 1, MSG_BLANK    },
    { imgOutFlowSw   , GR_FLOW_SW, 711, 163,  27,  27, 1, MSG_BLANK    },*/
    //! add new members here (before the last row)
    { ID_END_OF_WIDGETS,GR_NOGROUP,  0,   0,   0,   0, 0, MSG_BLANK    }
};

///originally from mask1
dev_uistate_t DeltaDevices[MAX_DEV_NUM]= {
   //! dev_type         ui_id                   state
   { DEV_SOL1,       { imgSolenoid_1,         STAT_DSCN }},
   { DEV_SOL2,       { imgSolenoid_2,         STAT_DSCN }},
   { DEV_SOL3,       { imgSolenoid_3,         STAT_DSCN }},
   { DEV_SOL4,       { imgSolenoid_4,         STAT_DSCN }},
   { DEV_SOL5,       { imgSolenoid_5,         STAT_DSCN }},
   { DEV_SOL6,       { imgSolenoid_6,         STAT_DSCN }},
   { DEV_SOL7,       { imgSolenoid_7,         STAT_DSCN }},
   //{ DEV_SOL8,       { imgSolenoid_8,         STAT_DSCN }},
   { DEV_SOL9,       { imgSolenoid_9,         STAT_DSCN }},

   { DEV_DS_PUMP,    { imgDosPump,            STAT_DSCN }},
   { DEV_FT,         { imgFilterSem,          STAT_DSCN }},
   { DEV_MG_IN,      { imgMagmeterINSem,      STAT_DSCN }},
   { DEV_MG_OUT,     { imgMagmeterINSem,      STAT_DSCN }},
   { DEV_SOL10,      { imgSolenoid_10,        STAT_DSCN }},
   { DEV_SOLA1,      { imgSolenoid_A1,        STAT_DSCN }},
   { DEV_SOLA2,      { imgSolenoid_A2,        STAT_DSCN }},
   { DEV_PSW_IN,     { imgPresSw_IN,          STAT_DSCN }},
   { DEV_PSW_AIR,    { imgPresSw_AIR,         STAT_DSCN }},
   
   { DEV_LVLSW_L,    { imgext_lvlsw_low,      STAT_DSCN }},
   { DEV_LVLSW_H,    { imgext_lvlsw_high,     STAT_DSCN }},
   { DEV_LVLSW_E,    { imgext_lvlsw_emer,     STAT_DSCN }},
   
      
   { DEV_SYS,        { DUMMY_ID,              STAT_DSCN }},

};


static int defineMask(PARAM *p)
{
  int i = 0;
  if(p == NULL) return 1;
  int show_cip   = (int)bin_opts[CIP_PRESENT]->cur_val;
  int show_four_membrane = (int)bin_opts[UF2_PRESENT]->cur_val;
  int show_ext_bw = (int)bin_opts[PS2_PRESENT]->cur_val; ///need to use new variable
  pvDownloadFile(p,FILE_MAP_A);
  pvDownloadFile(p,FILE_MAP);
  pvDownloadFile(p,EXT_BW);
  pvDownloadFile(p,NO_EXT_BW);
  generated_defineMask(p);
  // (todo: add your code here)
  for (int i = 0; i < MAX_MAN_UI_DEV_NUM; i++){
     pvHide(p, manualUI_List[i].ui.ui_id);
  }
  pvHide(p, frmBg);
  //show CIP part or not
  if (show_cip){
     pvSetGeometry(p,imgCIP_lines,0,0,240,120);
     ///pvSetGeometry(p,frmLegend,24,620,150,170);    
     pvShow(p, imgCIP_lines);
     ///pvShow(p, imgDosFlow);
     /*
     pvHide(p, frmLegend);
     pvShow(p, lblBackwashLine);
     pvShow(p, lblDistribLine);
     pvShow(p, lblDrainLine);
     */
  } else {
     pvSetGeometry(p,imgCIP_lines,830,70,165,245);
     pvSetGeometry(p,imgno_cip_lines,23,33,240,120);
     
     ///pvSetGeometry(p,frmLegend,24,120,150,170);

     pvHide(p, imgCIP_lines);
     pvShow(p, imgno_cip_lines);
     ///pvHide(p, imgDosFlow);
     
     /*pvShow(p, frmLegend);
     pvHide(p, lblBackwashLine);
     pvHide(p, lblDistribLine);
     pvHide(p, lblDrainLine);
     */
  }
  
  //show external backwash line
  if (show_ext_bw){   
     /*pvSetGeometry(p,imgno_ext_bw,830,2,259,96);
     pvHide(p, imgno_ext_bw); 
     pvSetGeometry(p,imgExternal_bw,518,3,268,95);
     pvShow(p, imgExternal_bw);
     ///pvSetImage(p,imgSchematic,FILE_MAP_A);
     
     pvShow(p, imgSolenoid_6);
     */
     pvSetGeometry(p,imgExternal_bw,518,2,269,96);
     pvSetImage(p,imgExternal_bw,EXT_BW);
     printf("%s\n", "show extermal backwash");
  } else {
     /*pvSetGeometry(p,imgno_ext_bw,518,2,259,96);
     pvSetGeometry(p,imgExternal_bw,830,2,259,96);
     pvHide(p, imgExternal_bw);
     pvShow(p, imgno_ext_bw);
     pvSetGeometry(p,imgSolenoid_5,190,66,25,25);//adjust solenoid 5
     pvShow(p, imgSolenoid_5);
     pvHide(p, imgSolenoid_6);
     pvSetGeometry(p,imgMagmeterOut,70,35,25,25);//adjust magmeterOut
     pvShow(p, imgMagmeterOut);
     */
     pvSetGeometry(p,imgExternal_bw,518,2,269,96);
     pvSetImage(p,imgExternal_bw,NO_EXT_BW);
     //hide solenoid6
     pvHide(p, imgSolenoid_6);
     pvHide(p, imgSolenoid_6);
     
     pvSetGeometry(p,imgSolenoid_5,190,5,25,25);//adjust solenoid 5
     pvSetGeometry(p,imgMagmeterOut,65,30,25,25);//adjust magmeterOut
     printf("%s\n", "do not show extermal backwash");
  }

  //show one or two set of uF
  if (show_four_membrane){    
     pvSetGeometry(p,imgSchematic,1,129,800,408);
     pvSetImage(p,imgSchematic,FILE_MAP_A);
     pvShow(p, imgSolenoid_10);
     pvShow(p, imgSolenoid_A2);
     printf("%s\n", "show two set of membranes");
  } else {
     pvSetGeometry(p,imgSchematic,1,129,800,408);
     pvSetImage(p,imgSchematic,FILE_MAP);

     pvSetGeometry(p,imgSolenoid_1,340,296,25,25);
     pvSetGeometry(p,imgSolenoid_A1,473,296,25,25);
     pvSetGeometry(p,imgSolenoid_4,535,193,25,25);
     pvSetGeometry(p,imgSolenoid_2,289,9,25,25);

     //hide A2 & 10 
     pvHide(p, imgSolenoid_10);
     pvHide(p, imgSolenoid_A2);
     pvHide(p, lblSolenoid_10);
     pvHide(p, lblSolenoid_A2);

     printf("%s\n", "show one set of membranes");
  }
  for (i = 0; i < ID_END_OF_WIDGETS; i++){
      if (widgetType[i] == TQPushButton){
         pvSetPaletteBackgroundColor(p,i,225,225,225);
      }
  }
  pvShow(p, frmBg); 

  return 0;
}

static int showData(PARAM *p, DATA *d)
{
  if(p == NULL) return 1;
  if(d == NULL) return 1;
  int ui_mode, dev_type, dev_stat, id, i;

  for(i = 0; i < MAX_DEV_NUM; i++){
     dev_type = DeltaDevices[i].dev_type;
     dev_stat = DeltaDevices[i].ui.state;
     id = DeltaDevices[i].ui.ui_id;
     
     switch (dev_type){
        case DEV_SYS:
                      break;

        case DEV_SOL1 :
        case DEV_SOL2 :
        case DEV_SOL3 :
        case DEV_SOL4 :
        case DEV_SOL5 :
        case DEV_SOL6 :
        case DEV_SOL7 :
        //case DEV_SOL8 :
        case DEV_SOL9 :

        case DEV_DS_PUMP :
        case DEV_FT :
        case DEV_MG_IN :
        case DEV_MG_OUT:       //! MAGMETER_OUT
        case DEV_SOL10:        //! SOLENOID 10
        case DEV_SOLA1:        //! SOLENOID A1
        case DEV_SOLA2:        //! SOLENOID A2 

                      pvSetImage(p, id, pvtr(imgSema24_List[dev_stat]));
                      break;
        /*
        case DEV_DOS_TANK:
                      if (dev_stat == STAT_DSCN){
                         pvShow(p, id);
                         pvSetText(p,lblTankEmpty,pvtr(" ?"));
                         pvSetPaletteForegroundColor(p,lblTankEmpty,255,255,255);
                         pvSetPaletteBackgroundColor(p,lblTankEmpty,78,123,255);
                      } else if (dev_stat == STAT_IN_ERR_1){
                         pvShow(p, id);
                         pvSetText(p,lblTankEmpty,pvtr(" !!"));
                         pvSetPaletteForegroundColor(p,lblTankEmpty,255,255,255);
                         pvSetPaletteBackgroundColor(p,lblTankEmpty,255,0,0);
                      } else if (dev_stat == STAT_ACTIVE_OFF){
                         pvShow(p, id);
                         pvSetText(p,lblTankEmpty,pvtr(" !!"));
                         pvSetPaletteForegroundColor(p,lblTankEmpty,255,0,0);
                         pvSetPaletteBackgroundColor(p,lblTankEmpty,255,255,0);
                      } else if (dev_stat == STAT_ACTIVE_ON){
                         pvHide(p, id);
                      }
                      break;
                      */
        /*
        case DEV_PSW_IN: if (dev_stat == STAT_DSCN){
                         pvSetText(p,lblPsw,pvtr(UNKNOWN_PRESSURE));
                         pvSetPaletteForegroundColor(p,lblPsw,0,0,0);
                      } else if (dev_stat == STAT_IN_ERR_1){
                         pvSetText(p,lblPsw,pvtr(INFLOW_ERROR));
                         pvSetPaletteForegroundColor(p,lblPsw,255,0,0);
                      } else if (dev_stat == STAT_ACTIVE_OFF){
                         pvSetText(p,lblPsw,pvtr(LOW_PRESSURE));
                         pvSetPaletteForegroundColor(p,lblPsw,0,0,0);
                      } else {
                         pvSetText(p,lblPsw,pvtr(NORMAL_PRESSURE));
                         pvSetPaletteForegroundColor(p,lblPsw,0,0,0);
                      }
                      pvSetImage(p, id, pvtr(imgPressSw_List[dev_stat]));
                      break;
                       DEV_PSW_IN,       //! PRESSURE SWITCH IN
           DEV_PSW_AIR,      //! PRESSURE SWITCH AIR
        */
        case DEV_LVLSW_L:
        case DEV_LVLSW_H:
        case DEV_LVLSW_E:
        /*case DEV_CIP_LVLSW_L:
        case DEV_CIP_LVLSW_H:
        case DEV_CIP_LVLSW_E:
        */
                      pvSetImage(p, id, pvtr(imgLvlSw_List[dev_stat]));
                      break;

        default: pvSetImage(p, id, pvtr(imgSema24_List[dev_stat]));
     }
  }
  return 0;
}

static int readData(DATA *d) // from shared memory, database or something else
{
  int operation_mode, dev_type, dev_stat, id, i;
  double min_flow, flow_val;
  int ext_tank_contr_err = plc2pvs->ext_tank_contr_err;
  int manual_mode = 
  if(d == NULL) return 1;
  // (todo: add your code here)
  if (plc2pvs->no_connection){
     operation_mode = STAT_DSCNC_PLC;
  } else {
     operation_mode = plc2pvs->operation_submode;
  }
  for(i = 0; i < MAX_DEV_NUM; i++){
     dev_type = DeltaDevices[i].dev_type;
     if (dev_type == DEV_SYS){
        continue;
     }

     if (delta_plc2pvs->no_connection){
        dev_stat = STAT_DSCN;
     } else {
        switch (dev_type){
           /*case DEV_MM : if(flow_val > min_flow){
                            dev_stat = (delta_plc2pvs->in_flow == NO_A_SIGNAL)? STAT_IN_ERR_1: STAT_ACTIVE_ON;
                         } else {
                            dev_stat = STAT_ACTIVE_OFF;
                         }
                         break;
           */
           case DEV_SOL1 : 
                            dev_stat = (plc2pvs->sol_S1)? STAT_ACTIVE_ON: STAT_STANDBY_2;                      
                         break;
           case DEV_SOL2 : 
                            dev_stat = (plc2pvs->sol_S2)? STAT_ACTIVE_ON: STAT_STANDBY_2;                      
                         break;
           case DEV_SOL3 : 
                            dev_stat = (plc2pvs->sol_S3)? STAT_ACTIVE_ON: STAT_STANDBY_2;                      
                         break;
           case DEV_SOL4 : 
                            dev_stat = (plc2pvs->sol_S4)? STAT_ACTIVE_ON: STAT_STANDBY_2;                      
                         break;
           case DEV_SOL5 : 
                            dev_stat = (plc2pvs->sol_S5)? STAT_ACTIVE_ON: STAT_STANDBY_2;                      
                         break;
           case DEV_SOL6 : 
                            dev_stat = (plc2pvs->sol_S6)? STAT_ACTIVE_ON: STAT_STANDBY_2;                      
                         break;
           case DEV_SOL7 : 
                            dev_stat = (plc2pvs->sol_S7)? STAT_ACTIVE_ON: STAT_STANDBY_2;                      
                         break;
           case DEV_SOL9 : 
                            dev_stat = (plc2pvs->sol_S9)? STAT_ACTIVE_ON: STAT_STANDBY_2;                      
                         break;


           /*check delta
           case DEV_S2 : if (!delta_plc2pvs->sol_S2_err){
                           dev_stat = (delta_plc2pvs->solenoid_2)? STAT_ACTIVE_ON: STAT_STANDBY_2;
                         } else {
                            dev_stat = STAT_IN_ERR_1;
                         }
                         break;
         
           case DEV_S3 : if (!delta_plc2pvs->sol_S3_err){
                            dev_stat = (delta_plc2pvs->solenoid_3)? STAT_ACTIVE_ON: STAT_STANDBY_2;
                         } else {
                            dev_stat = STAT_IN_ERR_1;
                         }
                         break;

           case DEV_S4 : if (!delta_plc2pvs->sol_S4_err){
                            dev_stat = (delta_plc2pvs->solenoid_4)? STAT_ACTIVE_ON: STAT_STANDBY_2;
                         } else {
                            dev_stat = STAT_IN_ERR_1;
                         }
                         break;

           case DEV_S5 : if (!delta_plc2pvs->sol_S5_err){
                            dev_stat = (delta_plc2pvs->solenoid_5)? STAT_ACTIVE_ON: STAT_STANDBY_2;
                         } else {
                            dev_stat = STAT_IN_ERR_1;
                         }
                         break;
           */
           case DEV_PSW_IN:
                             dev_stat = (plc2pvs->PS1)? STAT_ACTIVE_ON: STAT_ACTIVE_OFF;
                         break;
           case DEV_PSW_AIR:
                             dev_stat = (plc2pvs->PS_AIR)? STAT_ACTIVE_ON: STAT_ACTIVE_OFF;
                         break;
    
           case DEV_FT :/* if (delta_plc2pvs->bw_media_err || delta_plc2pvs->mediaf_dscn){
                            dev_stat = STAT_IN_ERR_1;*/
                         if (operation_mode == STAT_BACKWASH_MF){
                            dev_stat = STAT_ACTIVE_ON;
                         } else {
                            dev_stat = STAT_ACTIVE_OFF;
                         }
                         break;


           /*case DEV_FD1: dev_stat = (delta_plc2pvs->flowdetect_1)? STAT_ACTIVE_ON: STAT_STANDBY_1;
                         break;

           case DEV_FD2: dev_stat = (delta_plc2pvs->flowdetect_2)? STAT_ACTIVE_ON: STAT_STANDBY_1;
                         break;*/

           /*case DEV_BWP: if (delta_plc2pvs->bw_pump_err){
                            dev_stat = STAT_IN_ERR_1;
                         } else {
                            dev_stat = (delta_plc2pvs->press_pump)? STAT_ACTIVE_ON: STAT_STANDBY_1;
                         }
                         break;
                         */

           /*case DEV_DS_PUMP : if (!delta_plc2pvs->pump1_err){
                            dev_stat = (delta_plc2pvs->dospumpflow > 0)? STAT_ACTIVE_ON: STAT_STANDBY_1;
                         } else {
                            dev_stat = STAT_IN_ERR_1;
                         }
                         break;
          */
           case DEV_DS_PUMP :
                         if (!delta_plc2pvs->pump1_err){
                          //different!!! 
                            dev_stat = (plc2pvs->dosing_pump)? STAT_ACTIVE_ON: STAT_STANDBY_1;
                         } else {
                            dev_stat = STAT_IN_ERR_1;
                         }
                         break;
           /*              
           case DEV_DOS_TANK:
                         if (delta_plc2pvs->dosing_empty){
                            dev_stat = STAT_IN_ERR_1;
                         } else if (delta_plc2pvs->dosing_prempty){
                            dev_stat = STAT_ACTIVE_OFF;
                         } else {
                            dev_stat = STAT_ACTIVE_ON;
                         }
                         break;
            */

           case DEV_LVLSW_L:
                         ///if (irr_tank_lvlsw_contr){
                        if (ext_tank_contr_err){                        
                            dev_stat = STAT_IN_ERR_2;
                         } else if (plc2pvs->Ext_Llvl){
                            dev_stat = STAT_ACTIVE_ON;
                         } else {
                            dev_stat = STAT_STANDBY_2;
                         }
                         break;

           case DEV_LVLSW_H:
                         if (ext_tank_contr_err){
                            dev_stat = STAT_IN_ERR_2;
                         } else if (plc2pvs->Ext_Hlvl){
                            dev_stat = STAT_ACTIVE_OFF;
                         } else {
                            dev_stat = STAT_STANDBY_1;
                         }
                         break;

           case DEV_LVLSW_E: ////need to check this
                         if (ext_tank_contr_err){
                            dev_stat = STAT_IN_ERR_2;
                         } else if (delta_plc2pvs->ir_lvlsw_e){
                            dev_stat = STAT_IN_ERR_1;
                         } else {
                            dev_stat = STAT_STANDBY_1;
                         }
                         break;

           /*case DEV_BW_LVLSW_L: 
                         if (bw_tank_lvlsw_contr){
                            dev_stat = STAT_IN_ERR_2;
                         } else if (delta_plc2pvs->bw_lvlsw_l){
                            dev_stat = STAT_ACTIVE_ON;
                         } else {
                            dev_stat = STAT_STANDBY_2;
                         }
                         break;

           case DEV_BW_LVLSW_H:
                         if (bw_tank_lvlsw_contr){
                            dev_stat = STAT_IN_ERR_2;
                         } else if (delta_plc2pvs->bw_lvlsw_h){
                            dev_stat = STAT_ACTIVE_OFF;
                         } else {
                            dev_stat = STAT_STANDBY_1;
                         }
                         break;

           case DEV_BW_LVLSW_E: 
                         if (bw_tank_lvlsw_contr){
                            dev_stat = STAT_IN_ERR_2;
                         } else if (delta_plc2pvs->bw_lvlsw_e){
                            dev_stat = STAT_IN_ERR_1;
                         } else {
                            dev_stat = STAT_STANDBY_1;
                         }
                         break;

           case DEV_EC_SENS:
                         if (sensors_set){
                            if (!sens2pvs->no_connection){
                               dev_stat = (sens2pvs->error)? STAT_IN_ERR_1: STAT_ACTIVE_ON;
                            } else {
                               dev_stat = STAT_DSCN;
                            }
                         }
                         break;
          */
        }
     }
     DeltaDevices[i].ui.state = dev_stat;
  }
  return 0;
}


int show_mask1(PARAM *p)
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
