void TFT_MAIN_PANEL () {

	tft.clearScreen();

  tft.fillWindow(RA8875_BLACK);//RA8875_LIGHT_GREY
  delay(150);

  tft.fillRoundRect(5, 2, 790, 55, 12, RA8875_DARK_ORANGE);//Top title bar
  tft.fillRoundRect(65, 426, 730, 48, 12, RA8875_DARK_ORANGE);//BOTTOM title bar

  

  tft.setFontScale(0);//reset font scale
  tft.fillRoundRect(5, 70, 150, 325, 12, RA8875_PURPLE); ///INFO_BOX_1 TEMP , PH , HUMIDITY
  tft.drawRoundRect(160, 70, 635, 300, 12, RA8875_PURPLE);///INFO_BOX_2 STATUS

 tft.setFontScale(0);//font x1
  tft.setTextColor(RA8875_BLUE, RA8875_PURPLE);

  tft.setCursor(15, 80);
  tft.print("Water  PH");

  tft.setFontScale(0);//font x1
  tft.setCursor(15, 160);
  tft.print("WATER");

  tft.setFontScale(0);//font x1
  tft.setCursor(15, 240);
  tft.print("ROOM");

  tft.setFontScale(0);//font x1
  tft.setCursor(15, 320);
  tft.print("HUMIDITY");
  WRITE_TITLE_DATE_TFT();
  Write_TEMP_HUMI_PH_TFT();


  

  //SPIFLASH-BMP-ICON SETTINGS Button////////////////////////////////
  Serial.println("let me show you settings button from flash ");
  tft.dispicown(1, 417, 66, 66, 455728); //Dispay pic039
  //tft.dispicown(1, 395, 130, 130, 464440); //Dispay pic039 
  delay(25);
  ///////////////////////////////////////////////////////////////////

  //SPIFLASH-BMP-ICON SETTINGS Button////////////////////////////////
  Serial.println("let me show you settings button from flash ");
  tft.dispicown(220, 200, 34, 34, 199296); //Dispay pic039
										 //tft.dispicown(1, 395, 130, 130, 464440); //Dispay pic039 
  delay(25);
  ///////////////////////////////////////////////////////////////////

  //SPIFLASH-BMP-ICON SETTINGS Button////////////////////////////////
  Serial.println("let me show you settings button from flash ");
  tft.dispicown(260, 200, 50, 50, 201608); //Dispay pic039
										 //tft.dispicown(1, 395, 130, 130, 464440); //Dispay pic039 
  delay(25);
  ///////////////////////////////////////////////////////////////////

  //SPIFLASH-BMP-ICON SETTINGS Button////////////////////////////////
  Serial.println("let me show you settings button from flash ");
  tft.dispicown(310, 200, 66, 66, 206608); //Dispay pic039
										 //tft.dispicown(1, 395, 130, 130, 464440); //Dispay pic039 
  delay(25);
  ///////////////////////////////////////////////////////////////////


  SCREEN_UPDATE = false;
}

void WRITE_TITLE_DATE_TFT() {
  /////////////WITE MAIN SCREEN NAME//////////////////

  tft.setFontScale(1);//font x1
  tft.setTextColor(RA8875_BLUE,RA8875_DARK_ORANGE);
  
  tft.setCursor((tft.width ()/ 2), 30,true);
  tft.print("SMART AQUARIUM CONTROL");
  /////////////WRITE DATE//////////////////
  tft.setTextColor(RA8875_BLACK, RA8875_DARK_ORANGE);
  tft.setCursor(550, 428);
  TFTrint2digits(CURRENTDAY);
  tft.print('/');
  TFTrint2digits(CURRENTMONTH);
  tft.print('/');
  tft.print(CURRENTYEAR);
}

void Write_TEMP_HUMI_PH_TFT() {

  tft.setFontScale(1);//LARGE FONT
  tft.setTextColor(RA8875_WHITE, RA8875_PURPLE);

  tft.setCursor(15, 340); ///HUMIDITY
  tft.print("45 %");

//tft.gPrint(15,250,"24.45",RA8875_WHITE,1,&squarefont_14);
 tft.setCursor(15, 260);///ROOM TEMP
 tft.print("24.48");
  //tft.setFontScale(6);//LARGE FONT
// tft.setTextColor(RA8875_WHITE);
 
  tft.setCursor(15, 180);///WATER AVG TEMP
  tft.print("26.49");

  tft.setCursor(15, 100);///WATER PH
  tft.print("7.79");
}

void TFTrint2digits(int number) {
  if (number >= 0 && number < 10) {
    tft.print("0");
  }
  tft.print(number);
}




void TFT_MENU_SETTINGS () {

int icon_Size =130;
int Half_icon_offset = icon_Size/2;
int pitch_X_icon = (tft.width ()/ 2 /2);

  int X_COL_1 = ((pitch_X_icon)-(Half_icon_offset));
  int X_COL_2 = ((pitch_X_icon)+(X_COL_1));
  int X_COL_3 = ((pitch_X_icon)+(X_COL_2));
  int Y_ROW_1 = 75;
  int Y_ROW_2 = 250;


	//int Button_1_loc[2] =  {10,70 };
//	int Button_2_loc[2] = { 10,170 };

  tft.clearScreen();
  delay(80);
  tft.fillRect(0, 5, 790, 55, RA8875_LIGHT_ORANGE);//Top title bar
  tft.fillRoundRect(0, 426, 730, 48, 12, RA8875_DARK_ORANGE);//BOTTOM title bar
															/////////////WITE MAIN SCREEN NAME//////////////////
//  tft.setFont(&orbitron_16);//USE THIS FONT
  tft.setFontScale(1);//font x1

  tft.setTextColor(RA8875_WHITE, RA8875_LIGHT_ORANGE);
  tft.setCursor((tft.width ()/ 2), 30 ,true);
  tft.print("SETTINGS");


  
  //SPIFLASH-BMP-ICON Settings////////////////////////////////
  Serial.println("let me show you settings icon from flash ");
  tft.dispicown(0, 0, 66, 66, 455728); //Dispay pic39 //  39,      66,      66,  455728,
 // delay(45);
  //////////////////////////////////////////////////////////////
  //SPIFLASH-BMP-ICON Settings////////////////////////////////
  Serial.println("let me show you settings icon from flash ");
  tft.dispicown(X_COL_1, Y_ROW_1, icon_Size, icon_Size, 414616); //Dispay pic36 //  36,     130,     130,  414616,
 // delay(45);
  //////////////////////////////////////////////////////////////
  //SPIFLASH-BMP-ICON Settings////////////////////////////////
  Serial.println("let me show you settings icon from flash ");
  tft.dispicown(X_COL_2, Y_ROW_1, icon_Size, icon_Size, 6542368); //Dispay pic549 //   549,     130,     130, 6542368,
 // delay(45);
  //////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////
  //SPIFLASH-BMP-ICON Settings////////////////////////////////
  Serial.println("let me show you settings icon from flash ");
 // tft.dispic(1);
  tft.dispicown(X_COL_3, Y_ROW_1, icon_Size, icon_Size, 4602584); //Dispay pic696 //   696,     130,     130, 8870456,
 // delay(45);
  //////////////////////////////////////////////////////////////
  //********************
  //SPIFLASH-BMP-ICON Settings////////////////////////////////
  Serial.println("let me show you settings icon from flash ");
  tft.dispicown(X_COL_1, Y_ROW_2, icon_Size, icon_Size, 6637392); //Dispay pic555 // 555,     130,     130, 6637392,
 // delay(45);
  //////////////////////////////////////////////////////////////
  //SPIFLASH-BMP-ICON Settings////////////////////////////////
  Serial.println("let me show you settings icon from flash ");
  tft.dispicown(X_COL_2,Y_ROW_2, icon_Size, icon_Size, 2309248); //Dispay pic241 //    241,     130,     130, 2309248,,
 // delay(45);
  //////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////
  //SPIFLASH-BMP-ICON Settings////////////////////////////////
  Serial.println("let me show you settings icon from flash ");
  tft.dispicown(X_COL_3,Y_ROW_2, icon_Size, icon_Size, 5250296); //Dispay pic464 //    464,     130,     130, 5250296,
 // delay(45);
  //////////////////////////////////////////////////////////////


///947,     199,     199,10955456 -- RGB Color Wheel 



  //********************

  //SPIFLASH-BMP-ICON HOME Button////////////////////////////////
  Serial.println("let me show you home button from flash ");
  tft.dispicown(1, 414, 66, 66, 3502368); //Dispay pic325
 // delay(45);
  delay(100);
  tft.setActiveWindow();
  
  //////////////////////////////////////////////////////////////
//  tft.setFont(&orbitron_16);//USE THIS FONT
  tft.setFontScale(0);//font x1

  tft.setTextColor(RA8875_WHITE, RA8875_BLACK);
  tft.setCursor(X_COL_1+Half_icon_offset,Y_ROW_1 +icon_Size+15,true);
  tft.print("OPTIONS");
  tft.setCursor(X_COL_2 + Half_icon_offset,Y_ROW_1 +icon_Size+15,true);
  tft.print("LIGHTS");
  tft.setCursor(X_COL_3 + Half_icon_offset,Y_ROW_1 +icon_Size+15,true);
  tft.print("DEBUG");
  
  tft.setTextColor(RA8875_WHITE, RA8875_BLACK);
  tft.setCursor(X_COL_1 + Half_icon_offset, Y_ROW_2 +icon_Size+15, true);
  tft.print("DATE/TIME");
  tft.setCursor(X_COL_2 + Half_icon_offset, Y_ROW_2 +icon_Size+15, true);
  tft.print("WIFI");
  tft.setCursor(X_COL_3 + Half_icon_offset,Y_ROW_2 +icon_Size+15, true);
  tft.print("ABOUT");
  tft.setActiveWindow();
  SCREEN_UPDATE = false;
}




void GGDELAY(){
  delay(100);
}
void TFT_MENU_CONFIGURATION () {

  
int icon_Size_X =60;
int icon_Size_Y =51;
int pitch_X_icon = ((tft.width ()/ 2)- (icon_Size_X/2));
int pitch_Y_icon = ((tft.height ()/ 2)- (icon_Size_Y/2));
 // tft.setActiveWindow();

  tft.clearScreen();
  delay(80);
  tft.fillRect(0, 5, 790, 55, RA8875_LIGHT_ORANGE);//Top title bar
  tft.fillRoundRect(60, 426, 730, 48, 12, RA8875_DARK_ORANGE);//BOTTOM title bar
                              /////////////WITE MAIN SCREEN NAME//////////////////
//  tft.setFont(&orbitron_16);//USE THIS FONT
  tft.setFontScale(1);//font x1

  tft.setTextColor(RA8875_WHITE, RA8875_LIGHT_ORANGE);
  tft.setCursor((tft.width ()/ 2), 30 ,true);
  tft.print("LED LIGHTS");
  delay(80);
  
 //tft.setActiveWindow();
 tft.dispicown(130, 80,48,      63,10302502);// 840,      48,      63,10302502,
  //SPIFLASH-BMP-ICON LIGHTS////////////////////////////////
  Serial.println("let me show you lights icon from flash ");
    delay(80);
tft.dispicown(0, 0, 66, 66,4245104);//pic 383

GGDELAY();

tft.dispicown(0, 132,  66,     66,10914992);// p941.bmp  66  66  16bpp mode (RGB 5:6:5)  8712  10914992
GGDELAY();
tft.dispicown(0, 66,  66,     66,10923704);// p942.bmp  66  66  16bpp mode (RGB 5:6:5)  8712  10923704
GGDELAY();
tft.dispicown(0, 264,  66,     66,10932416);// p943.bmp  66  66  16bpp mode (RGB 5:6:5)  8712  10932416
GGDELAY();
tft.dispicown(0, 198,  66,     66,10827872);// p931.bmp  66  66  16bpp mode (RGB 5:6:5)  8712  10827872
GGDELAY();
tft.dispicown(0, 330,  66,     66,10941128);// p944.bmp  66  66  16bpp mode (RGB 5:6:5)  8712  10941128
GGDELAY();
tft.dispicown(66, 132,  66,     66,10949840);// p945.bmp  66  66  16bpp mode (RGB 5:6:5)  8712  10949840
GGDELAY();
tft.dispicown(66, 66,  66,     66,10958552);// p946.bmp 66  66  16bpp mode (RGB 5:6:5)  8712  10958552
GGDELAY();
tft.dispicown(66, 264,  66,     66,10836584);//p932.bmp 66  66  16bpp mode (RGB 5:6:5)  8712  10836584
GGDELAY();
tft.dispicown(66, 198,  66,     66,10845296);//p933.bmp 66  66  16bpp mode (RGB 5:6:5)  8712  10845296
GGDELAY();
tft.dispicown(66, 330,  66,     66,10854008);// p934.bmp  66  66  16bpp mode (RGB 5:6:5)  8712  10854008
GGDELAY();
tft.dispicown(132, 132,  66,     66,10862720);//p935.bmp  66  66  16bpp mode (RGB 5:6:5)  8712  10862720
GGDELAY();
tft.dispicown(132, 66,  66,     66,10958552);// p936.bmp  66  66  16bpp mode (RGB 5:6:5)  8712  10871432
GGDELAY();
tft.dispicown(132, 264,  66,     66,10836584);//p937.bmp  66  66  16bpp mode (RGB 5:6:5)  8712  10880144
GGDELAY();
tft.dispicown(132, 198,  66,     66,10845296);//p938.bmp  66  66  16bpp mode (RGB 5:6:5)  8712  10888856
GGDELAY();
tft.dispicown(132, 330,  66,     66,10854008);//p939.bmp  66  66  16bpp mode (RGB 5:6:5)  8712  10897568
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
GGDELAY();
tft.dispicown(198, 132,  66,     66,10906280);//p940.bmp  66  66  16bpp mode (RGB 5:6:5)  8712  10906280
GGDELAY();
tft.dispicown(198, 66,  66,     66,10636208);// p909.bmp  66  66  16bpp mode (RGB 5:6:5)  8712  10636208
GGDELAY();
tft.dispicown(198, 264,  66,     66,10644920);//p910.bmp  66  66  16bpp mode (RGB 5:6:5)  8712  10644920
GGDELAY();
tft.dispicown(198, 198,  66,     66,10653632);//p911.bmp  66  66  16bpp mode (RGB 5:6:5)  8712  10653632
GGDELAY();
tft.dispicown(198, 330,  66,     66,10662344);//p912.bmp  66  66  16bpp mode (RGB 5:6:5)  8712  10662344
GGDELAY();

tft.dispicown(264, 65,  75,     66,11095426);//p952.bmp  60  75  16bpp mode (RGB 5:6:5)  9000  11095426
GGDELAY();
tft.dispicown(334, 65,  75,     66,11104426);//p953.bmp  60  75  16bpp mode (RGB 5:6:5)  9000  11104426
GGDELAY();
tft.dispicown(404, 65,  75,     66,11113426);//p954.bmp  60  75  16bpp mode (RGB 5:6:5)  9000  11113426
GGDELAY();
tft.dispicown(700,66,84,75,11056306);// p948.bmp  84  75  16bpp mode (RGB 5:6:5)  12600 11056306
GGDELAY();
tft.dispicown(700,162,84,75,11082826);//p951.bmp  84  75  16bpp mode (RGB 5:6:5)  12600 11082826
GGDELAY();
tft.dispicown(630,66,58,60,11068906);// p949.bmp  58  60  16bpp mode (RGB 5:6:5)  6960  11068906
GGDELAY();
tft.dispicown(630,132,58,60,11075866);//p950.bmp  58  60  16bpp mode (RGB 5:6:5)  6960  11075866
GGDELAY();
//tft.dispicown(130, 80,48,      63,10302502);// 840,      48,      63,10302502,
//tft.dispicown(178, 80,48,      63,10314598);// 842,      48,      63,10314598,
 // tft.dispicown(0, 0, 66, 66,4245104); //  383,      66,      66, 4245104,

  //////////////////////////////////////////////////////////////

////Lets show RGB 
  Serial.println("let me show you settings RGB PALETTE icon from flash ");
  tft.dispicown(pitch_X_icon, pitch_Y_icon,icon_Size_X,icon_Size_Y, 10120606); // 798,      60,      51,10120606,

//tft.drawFlashImage(480, 200,   130,     130, 8395336); //Dispay pic696 //   696,     130,     130, 8870456,
// tft.dispicown(480, 200,   130,     130, 8395336); //Dispay pic696 //   696,     130,     130, 8870456,
tft.dispicown(480,200,128,128,11302426); //p956.bmp 128 128 16bpp mode (RGB 5:6:5)  32768 11302426
// 801,      92,      92,10134646,
// 768,     130,     130, 9848440,
// 902,     240,      66,10580008,
  //SPIFLASH-BMP-ICON HOME Button////////////////////////////////
  Serial.println("let me show you home button from flash ");
  tft.dispicown(1, 414, 66, 66, 3502368); //Dispay pic325
 // delay(45);
  
 // tft.setActiveWindow();

  
  SCREEN_UPDATE = false;
}

void TFT_MENU_OUTPUTS () {
  tft.clearScreen();
  delay(200);
  tft.fillRoundRect(5, 395, 80, 80, 12, RA8875_BLUE);//BUTTON HOME VALUE 0
  tft.fillRoundRect(5, 2, 790, 55, 12, RA8875_WHITE);//Top title bar
  tft.setFontScale(2);//font x1
  tft.setTextColor(RA8875_BLACK);
  tft.setCursor(135, 4);
  tft.print("OUTPUTS");
  SCREEN_UPDATE = false;
}

void TFT_MENU_PH () {
  tft.clearScreen();
  delay(200);
  tft.fillRoundRect(5, 395, 80, 80, 12, RA8875_BLUE);//BUTTON HOME VALUE 0
  tft.fillRoundRect(5, 2, 790, 55, 12, RA8875_WHITE);//Top title bar
  tft.setFontScale(2);//font x1
  tft.setTextColor(RA8875_BLACK);
  tft.setCursor(135, 4);
  tft.print("PH CALIBRATION");
  Serial.println("OK!");
 // bmpDraw("alert.bmp", 70, 70);//copy the enclosed image in a SD card (check the folder!!!)
  SCREEN_UPDATE = false;
}

void TFT_MENU_ABOUT (boolean reset_screen, int STATUS, int menu_nr) {

	if (reset_screen == true) {
		tft.clearScreen();

		delay(50);
	}


  tft.fillRect(0, 5, 790, 55, RA8875_LIGHT_ORANGE);//Top title bar
  tft.fillRoundRect(60, 426, 730, 48, 12, RA8875_DARK_ORANGE);//BOTTOM title bar
                              /////////////WITE MAIN SCREEN NAME//////////////////
//  tft.setFont(&orbitron_16);//USE THIS FONT
  tft.setFontScale(1);//font x1

  tft.setTextColor(RA8875_WHITE, RA8875_LIGHT_ORANGE);
  tft.setCursor((tft.width ()/ 2), 30 ,true);
  tft.print("ABOUT");
  delay(80);


  create_label(label_test_1);//Create label for RED show value
  create_label(label_test_2);//Create label for GREEN show value
  create_label(label_test_3);//Create label for BLUE show value

  update_label_val(label_test_1, label_test_1_Value);
  update_label_val(label_test_2, label_test_2_Value);
  update_label_val(label_test_3, label_test_3_Value);


  create_btn(M8B_A);






  /*
//create_label(label_KEYPAD);//Create label to show keypad value


  Update_KPDVAL(350, 120);


  // keypad border 
 // tft.drawRect(KPD_A[0] - 3, KPD_A[1] - 3, (KPD_L[0]  + 6), (KPD_L[1] + 57 + 6), RA8875_WHITE);
 // tft.drawRect(KPD_A[0] - 2, KPD_A[1] - 2, KPD_L[0] + 57 + 4, KPD_L[1] + 57 + 4, RA8875_WHITE);

  create_btn(KPD_A);
  DELAY_00D();
  create_btn(KPD_B);
  DELAY_00D();
  create_btn(KPD_C);
  DELAY_00D();
  create_btn(KPD_D);
  DELAY_00D();
  create_btn(KPD_E);
  DELAY_00D();
  create_btn(KPD_F);
  DELAY_00D();
  create_btn(KPD_G);
  DELAY_00D();
  create_btn(KPD_H);
  DELAY_00D();
  create_btn(KPD_I);
  DELAY_00D();
  create_btn(KPD_J);
  DELAY_00D();
  create_btn(KPD_K);
  DELAY_00D();
  create_btn(KPD_L);
  DELAY_00D();

  */
  SCREEN_UPDATE = false;
   

}



void DELAY_001 (){
  delay(1);
  }
//////////////////////////NUMERIC KEYPAD///////////////////////////////////////////////
void Numeric_Keypad_TFT (int XPOS , int YPOS){
  
int Center_buttun_X = (KPD_Button_SIZE_X / 2);
int Center_buttun_Y = (KPD_Button_SIZE_Y / 2);
  
tft.clearScreen();
delay(200);
tft.fillRect(XPOS -5 , YPOS -5, 5+ (KPD_Button_PITCH_X * 2)+ KPD_Button_SIZE_X +5 , 5+ (KPD_Button_PITCH_Y * 3)+ KPD_Button_SIZE_Y +5, KPD_Back_color);//DRAW  button NO1
DELAY_001 ();
tft.fillRect(XPOS, YPOS, KPD_Button_SIZE_X, KPD_Button_SIZE_Y, KPD_Button_color);//DRAW  button NO1
DELAY_001 ();
tft.fillRect(XPOS + KPD_Button_PITCH_X, YPOS , KPD_Button_SIZE_X, KPD_Button_SIZE_Y, KPD_Button_color);//DRAW button NO2
DELAY_001 ();
tft.fillRect (XPOS + (KPD_Button_PITCH_X * 2), YPOS , KPD_Button_SIZE_X, KPD_Button_SIZE_Y, KPD_Button_color);//DRAW button NO3
DELAY_001 ();
tft.fillRect(XPOS, YPOS + KPD_Button_PITCH_Y , KPD_Button_SIZE_X, KPD_Button_SIZE_Y, KPD_Button_color);//DRAW  button NO4
DELAY_001 ();
tft.fillRect(XPOS + KPD_Button_PITCH_X, YPOS + KPD_Button_PITCH_Y , KPD_Button_SIZE_X, KPD_Button_SIZE_Y, KPD_Button_color);//DRAW button NO5
DELAY_001 ();
tft.fillRect (XPOS + (KPD_Button_PITCH_X * 2), YPOS + KPD_Button_PITCH_Y , KPD_Button_SIZE_X, KPD_Button_SIZE_Y, KPD_Button_color);//DRAW button NO6
DELAY_001 ();
tft.fillRect(XPOS, YPOS + (KPD_Button_PITCH_Y * 2), KPD_Button_SIZE_X, KPD_Button_SIZE_Y, KPD_Button_color);//DRAW  button NO7
DELAY_001 ();
tft.fillRect(XPOS + KPD_Button_PITCH_X, YPOS + (KPD_Button_PITCH_Y * 2), KPD_Button_SIZE_X, KPD_Button_SIZE_Y, KPD_Button_color);//DRAW button NO8
DELAY_001 ();
tft.fillRect (XPOS + (KPD_Button_PITCH_X * 2), YPOS + (KPD_Button_PITCH_Y * 2), KPD_Button_SIZE_X, KPD_Button_SIZE_Y, KPD_Button_color);//DRAW button NO9
DELAY_001 ();
tft.fillRect(XPOS, YPOS + (KPD_Button_PITCH_Y * 3), KPD_Button_SIZE_X, KPD_Button_SIZE_Y, KPD_Button_color);//DRAW  button SAVE
DELAY_001 ();
tft.fillRect(XPOS + KPD_Button_PITCH_X, YPOS + (KPD_Button_PITCH_Y * 3), KPD_Button_SIZE_X, KPD_Button_SIZE_Y, KPD_Button_color);//DRAW button CANCEL
DELAY_001 ();
tft.fillRect (XPOS + (KPD_Button_PITCH_X * 2), YPOS + (KPD_Button_PITCH_Y * 3), KPD_Button_SIZE_X, KPD_Button_SIZE_Y, KPD_Button_color);//DRAW button .
DELAY_001 ();


tft.setFontScale(5);//font x1
tft.setTextColor(KPD_TEXT_color , KPD_Button_color);


tft.setCursor(XPOS + Center_buttun_X , YPOS + Center_buttun_Y,true);//DRAW  button NO1
tft.print("1");
DELAY_001 (); 
tft.setCursor(XPOS +  KPD_Button_PITCH_X + Center_buttun_X , YPOS + Center_buttun_Y,true);//DRAW  button NO1
tft.print("2");
DELAY_001 (); 
tft.setCursor(XPOS +  KPD_Button_PITCH_X *2 + Center_buttun_X , YPOS + Center_buttun_Y,true);//DRAW  button NO1
tft.print("3");








KEYPAD_XPOS_VAL = XPOS;///PLEASE REMEMBER TO SAVE XPOS AND YPOS BEFORE EXIT for detecting touch
KEYPAD_YPOS_VAL = YPOS;///PLEASE REMEMBER TO SAVE XPOS AND YPOS BEFORE EXIT for detecting touch
Serial.print("XPOS  ");
Serial.println(KEYPAD_XPOS_VAL);
Serial.print("YPOS  ");
Serial.println(KEYPAD_YPOS_VAL);
//KEYPAD_UPDATE = false; ///KEYPAD HAS BEEN DRAWN
SCREEN_UPDATE = false;

}



///////////////////////////////////////////////////////////////////////////////////////
/*
void ON_OFF_BUTTON (int XPOS , int YPOS , char* button_name){
  int BUTT_SIZE = 50;



    
tft.drawRect(XPOS, YPOS,BUTT_SIZE, BUTT_SIZE, RA8875_WHITE);//DRAW  button NO1

 for (int i=0; i <= 3; i++){
      tft.drawRect(XPOS, YPOS,BUTT_SIZE, BUTT_SIZE, RA8875_WHITE);//DRAW  button NO1
        XPOS++;
        YPOS++;
        BUTT_SIZE--;
        BUTT_SIZE--;
        Serial.print("BUTT_SIZE  " );
        Serial.println(BUTT_SIZE);
   } 
   
   tft.fillRect(XPOS, YPOS,BUTT_SIZE, BUTT_SIZE, RA8875_GREEN);//DRAW  button NO1

    int Center_buttun = (BUTT_SIZE / 2);

    tft.setFontScale(2);//LARGE FONT
    tft.setTextColor(RA8875_BLACK,RA8875_GREEN);
    tft.setCursor(XPOS + Center_buttun, YPOS + Center_buttun,true);//DRAW  button NO1
    tft.print("ON");
    
  SCREEN_UPDATE = false;
}


void DRAW_SETTINGS_MENU_BUTTONS_CHGA(boolean reset_screen, int STATUS) {

  if (reset_screen == true) {
    tft.clearScreen();
    delay(200);
  }
  tft.setFontScale(1);//font x1
  tft.setTextColor(RA8875_BLACK);
  boolean PRINT_NAME = false;
  // tft.setFontScale(1);//font x1
  // tft.setTextColor(RA8875_WHITE);
  int menu_size_X = 770;
  int menu_size_Y = 400;
  int tempnumber = 1;
  int MENU_COLUMNS = 2;
  int MENU_ROWS = 3;
  int X_COOR_Butt = 20;
  int Y_COOR_Butt = 50;
  int TEMP_X_COOR_Butt = 5;
  int TEMP_Y_COOR_Butt = 5;
  int number_of_buttons = 6;
  int value_count = 0;
  String NAME_1("LED");
  String NAME_2("CONFIGURATION");
  String NAME_3("OUTPUTS");
  String NAME_4("PH CALIB");
  String NAME_5("SPARE 1");
  String NAME_6("SPARE 2");
  String NAME_7("SPARE 3");
  String NAME_8("SPARE 4");
  String NAME_9("SPARE 5");

  uint16_t buttonX_size = (menu_size_X - ((MENU_COLUMNS + 1) * 5)) / MENU_COLUMNS;
  uint16_t buttonY_size = (menu_size_Y - ((MENU_ROWS + 1) * 5)) / MENU_ROWS;
  uint16_t X_OFFSET_START = (menu_size_X - (((MENU_COLUMNS - 1) * 5) + (buttonX_size * MENU_COLUMNS))) / 2;
  uint16_t Y_OFFSET_START = (menu_size_Y - (((MENU_ROWS - 1) * 5) + (buttonY_size * MENU_ROWS))) / 2;

  tft.fillRect(X_COOR_Butt, Y_COOR_Butt, menu_size_X, menu_size_Y, RA8875_LIGHT_GREY);//FILL the menu background

  TEMP_X_COOR_Butt = (X_COOR_Butt + X_OFFSET_START);
  TEMP_Y_COOR_Butt = (Y_COOR_Butt + Y_OFFSET_START);

  for (int i = 1; i <= MENU_COLUMNS; i++) {

    if (tempnumber <= MENU_ROWS) {

      switch (STATUS) {

      case 0:    // your hand is on the sensor

        tft.fillRect(TEMP_X_COOR_Butt, TEMP_Y_COOR_Butt, buttonX_size, buttonY_size, RA8875_RED);//BUTTON HOME VALUE 0
        tft.setCursor(TEMP_X_COOR_Butt + (buttonX_size / 2), TEMP_Y_COOR_Butt + (buttonY_size / 2), true); //DRAW  button NO1
        tft.print(value_count);
        break;

      case 1:

        //if ((Xtemp > TEMP_X_COOR_Butt && Xtemp < TEMP_X_COOR_Butt + buttonX_size) && (Ytemp > TEMP_Y_COOR_Butt && Ytemp < TEMP_Y_COOR_Butt + buttonY_size)) {
          //Update_keypad_pressed_button(TEMP_X_COOR_Butt, TEMP_Y_COOR_Butt, buttonX_size, buttonY_size, RA8875_WHITE);
        //}
        break;
        if (PRINT_NAME == true) {
          switch (value_count) {
          case 1:    // your hand is on the sensor
            tft.print(NAME_1);
            break;
          case 2:    // your hand is close to the sensor

            tft.print(NAME_2);

            break;

          }
        }

        TEMP_X_COOR_Butt = (TEMP_X_COOR_Butt + buttonX_size + 5);

      }

      if (i == MENU_COLUMNS && tempnumber <= MENU_ROWS) {
        i = 0;
        TEMP_Y_COOR_Butt = (TEMP_Y_COOR_Butt + buttonY_size + 5);
        TEMP_X_COOR_Butt = (X_COOR_Butt + X_OFFSET_START);


        tempnumber++;
      }

      value_count++;

      if (value_count == number_of_buttons) {
        tempnumber = MENU_ROWS;
        i = MENU_COLUMNS;
      }
    }
    SCREEN_UPDATE = false;
  }
}
*/