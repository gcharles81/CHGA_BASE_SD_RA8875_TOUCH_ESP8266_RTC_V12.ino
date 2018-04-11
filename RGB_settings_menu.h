//#pragma once

//-Menu 7 - Buttons // location X & Y & ICON numbers from - All_75_Pic_65K.h
int TRACKBARVAL = 50;
int TRB_X = 380;
int TRB_Y = 170;
int TRB_SIZE_X = 300;
int TRB_SIZE_Y = 35;

int Temp_red_1 = 0;
int Temp_blue_1 = 0;
int Temp_green_1 = 0;
uint16_t lbl_back_color = RA8875_LIGHT_GREY;
uint16_t lbl_TXT_color = RA8875_BLACK;

int16_t label_1[4] = { 172,153,113,40 };
int16_t ZHGF = label_1[2]/2;
int16_t vcx = label_1[0] + ZHGF;
int16_t ZHGFD = label_1[3] / 2;
int16_t vcy = label_1[1] + ZHGFD;

int16_t label_2[4] = { 172, 233,113,40};
int16_t label_3[4] = { 172, 313,113,40 };
/*
int RED1   = 255; ///Read stored light Value
int GREEN1 = 25;  ///Read stored light Value
int BLUE1   = 50; ///Read stored light Value
 */

int M7B_A[4] = { 3,6,0,5 };//[0] = location X , [1] = location Y ,[2] = pic number ,[3] = pic number "pressed":
int M7B_B[4] = { 740,6 ,84,66};//[0] = location X , [1] = location Y ,[2] = pic number ,[3] = pic number "pressed":
int M7B_C[4] = { 740,420 ,41,54};//[0] = location X , [1] = location Y ,[2] = pic number ,[3] = pic number "pressed":
int M7B_D[4] = { 3,420,126,90 };//[0] = location X , [1] = location Y ,[2] = pic number ,[3] = pic number "pressed":
int M7B_E[4] = { 530,320,109,91};//[0] = location X , [1] = location Y ,[2] = pic number ,[3] = pic number "pressed":
int M7B_F[4] = { 640,320,99,81};//[0] = location X , [1] = location Y ,[2] = pic number ,[3] = pic number "pressed":
int M7B_G[4] = { 300,145,1,6};//[0] = location X , [1] = location Y ,[2] = pic number ,[3] = pic number "pressed":
int M7B_H[4] = { 100,145,2,7 };//[0] = location X , [1] = location Y ,[2] = pic number ,[3] = pic number "pressed":
int M7B_I[4] = { 300,225,16,26 };//[0] = location X , [1] = location Y ,[2] = pic number ,[3] = pic number "pressed":
int M7B_J[4] = { 100,225,17,27 };//[0] = location X , [1] = location Y ,[2] = pic number ,[3] = pic number "pressed":
int M7B_K[4] = { 300,305,10,21 };//[0] = location X , [1] = location Y ,[2] = pic number ,[3] = pic number "pressed":
int M7B_L[4] = { 100,305, 11,22};//[0] = location X , [1] = location Y ,[2] = pic number ,[3] = pic number "pressed":


void Track_bar_test() {

	int posX = TRB_X;
	int posY = TRB_Y;
	int size_XX = TRB_SIZE_X;
	int size_YY = TRB_SIZE_Y;


	tft.drawRect((posX - 3), (posY - 3), (size_XX + 6), (size_YY + 6), RA8875_LIGHT_GREY);
	tft.drawRect((posX-2),( posY-2), (size_XX + 4),( size_YY + 4),RA8875_LIGHT_GREY);
	tft.drawRect((posX - 1), (posY - 1), (size_XX + 2), (size_YY + 2), RA8875_LIGHT_GREY);
	tft.fillRect(posX, posY, size_XX, size_YY, RA8875_BLACK);

	int GHT = TRACKBARVAL;
	int MARKER_WIDTH = 6;

	//tft.fillRect(GHT - (MARKER_WIDTH/2), posY, MARKER_WIDTH, size_YY, RA8875_RED);
	tft.fillRect(posX, posY, TRACKBARVAL, size_YY, RA8875_RED);
	int BVC = map(TRACKBARVAL, 0,TRB_SIZE_X, 10, 255);
	tft.brightness(BVC);
	SUB_SCREEN_UPDATE = true;

}




void create_label(int16_t TDF[4]) {

	tft.fillRect(TDF[0], TDF[1], TDF[2], TDF[3],lbl_back_color);
}

void update_label_val(int16_t TDF[4], int val) {

	tft.setFontScale(1);//font x1

	tft.setTextColor(lbl_TXT_color, lbl_back_color);

	tft.setCursor(((TDF[2] / 2) + TDF[0]), ((TDF[3] / 2) + TDF[1]),true);

	tft.print(val);
	
}


void TFT_MENU_RGB_01(boolean reset_screen, int STATUS, int menu_nr) {

	if (reset_screen == true) {
		tft.clearScreen();

		delay(50);
	}


	int PIC_NUM = 0;


	Track_bar_test();
	//tft.fillRect(530, 170, 130, 130, RA8875_WHITE);//RGB COLOR WINDOW
	tft.fillRect(0, 63, 800, 4, RA8875_WHITE);//TOP title bar
	tft.fillRect(0, 413, 800, 4, RA8875_WHITE);//BOTTOM title bar

	create_label(label_1);//Create label for RED show value
	create_label(label_2);//Create label for GREEN show value
	create_label(label_3);//Create label for BLUE show value

	if (menu_nr == 3) {
		Temp_red_1 = RED1;
		update_label_val(label_1, RED1);
		Temp_green_1 = GREEN1;
		update_label_val(label_2, GREEN1);
		Temp_blue_1 = BLUE1;
		update_label_val(label_3, BLUE1);
	}

	if (menu_nr == 4) {
		Temp_red_1 = RED2;
		update_label_val(label_1, RED2);
		Temp_green_1 = GREEN2;
		update_label_val(label_2, GREEN2);
		Temp_blue_1 = BLUE2;
		update_label_val(label_3, BLUE2);
	}

	if (menu_nr == 5) {
		Temp_red_1 = RED3;
		update_label_val(label_1, RED3);
		Temp_green_1 = GREEN3;
		update_label_val(label_2, GREEN3);
		Temp_blue_1 = BLUE3;
		update_label_val(label_3, BLUE3);
	}

	if (menu_nr == 6) {
		Temp_red_1 = RED4;
		update_label_val(label_1, RED4);
		Temp_green_1 = GREEN4;
		update_label_val(label_2, GREEN4);
		Temp_blue_1 = BLUE4;
		update_label_val(label_3, BLUE4);
	}

	/////////////WRITE SCREEN NAME//////////////////
	//	tft.setFont(&orbitron_16);//USE THIS FONT
	tft.setFontScale(2);//font x1
	tft.setTextColor(RA8875_BLUE, RA8875_BLACK);

	tft.setCursor((tft.width() / 2), 30, true);
	if (menu_nr == 3) { tft.print("RGB CHANNEL 1"); }

	if (menu_nr == 4) { tft.print("RGB CHANNEL 2"); }

	if (menu_nr == 5) { tft.print("RGB CHANNEL 3"); }

	if (menu_nr == 6) { tft.print("RGB CHANNEL 4"); }
	//////////////////////////////////////////////////

	//////////////////////////////////////////////////
	/// MENU TYPE ICON  M7B_A

	create_btn(M7B_A);

	//// HOME ICON M7B_B
	create_btn(M7B_B);


	///   NEXT PAGE 
	if (menu_nr == 3 || menu_nr == 4 || menu_nr == 5) {
		create_btn(M7B_C);

	}

	/// PREV PAGE 
	//if (menu_nr == 4 || menu_nr == 5 || menu_nr == 6) {
		create_btn(M7B_D);
	//}
	/// TEST - COLOR 

	create_btn(M7B_E);


	/// SAVE SETTINGS to EEPROM / SD 

	create_btn(M7B_F);

	/// RED +

	create_btn(M7B_G);

	/// RED -

	create_btn(M7B_H);


	/// GREEN +

	create_btn(M7B_I);

	/// GREEN -

	create_btn(M7B_J);

	/// BLUE +

	create_btn(M7B_K);

	/// BLUE -

	create_btn(M7B_L);


//	delay(100);


	SCREEN_UPDATE = false;
}


void BUTTON_TOUCH_RGB_MENU(int Xval, int Yval) {

	//////////////////////////////////////////////////
	/// MENU TYPE ICON  M7B_A
	if (Touch_inRange(Xval, Yval, M7B_A))
	{
		Serial.println("MENU TYPE ICON  M7B_A");
		return;
	}

	else { // do nothing *
	}
	//// HOME ICON M7B_B
	if (Touch_inRange(Xval, Yval, M7B_B))
	{
		Update_btn_press(M7B_B);
		delay(1);
		Serial.println("HOME ICON ICON  M7B_B");
		return;
	}
	else { // do nothing *
	}
	///   NEXT PAGE
	if ((Touch_inRange(Xval, Yval, M7B_C)) && (MENU == 3 || MENU == 4 || MENU == 5))
	{
		Update_btn_press(M7B_C);
		delay(1);
		MENU++;
		SCREEN_UPDATE = true;
		Serial.println("NEXT PAGE  ICON  M7B_C");
		return;
	}
	else { // do nothing *
	}
	/// PREV PAGE
	if (Touch_inRange(Xval, Yval, M7B_D))
	{
		Update_btn_press(M7B_D);
		delay(1);
		Serial.println("PREV PAGE  ICON  M7B_D");

		MENU--;
		SCREEN_UPDATE = true;
		return;


	}
	else { // do nothing *
	}
	/// TEST - COLOR
	if (Touch_inRange(Xval, Yval, M7B_E))
	{
		Update_btn_press(M7B_E);
		delay(1);
		Serial.println("TEST - COLOR  ICON  M7B_E");
		return;
	}
	else { // do nothing *
	}
	/// SAVE SETTINGS to EEPROM / SD
	if (Touch_inRange(Xval, Yval, M7B_F))
	{
		Update_btn_press(M7B_F);
		delay(1);

		if (MENU == 3) {
			RED1 = Temp_red_1; ///Read stored light Value
			GREEN1 = Temp_green_1;  ///Read stored light Value
			BLUE1 = Temp_blue_1; ///Read stored light Value
		}
		if (MENU == 4) {
			RED2 = Temp_red_1; ///Read stored light Value
			GREEN2 = Temp_green_1;  ///Read stored light Value
			BLUE2 = Temp_blue_1; ///Read stored light Value
		}
		if (MENU == 3) {
			RED3 = Temp_red_1; ///Read stored light Value
			GREEN3 = Temp_green_1;  ///Read stored light Value
			BLUE3 = Temp_blue_1; ///Read stored light Value
		}
		if (MENU == 3) {
			RED4 = Temp_red_1; ///Read stored light Value
			GREEN4 = Temp_green_1;  ///Read stored light Value
			BLUE4 = Temp_blue_1; ///Read stored light Value
		}


		//to store EEprom later 

		Serial.println("SAVE SETTINGS to EEPROM / SD  ICON  M7B_F");
		return;
	}

	else { // do nothing *
	}
	/// RED +
	if (Touch_inRange(Xval, Yval, M7B_G))
	{
		Update_btn_press(M7B_G);
		delay(1);

		if (Temp_red_1 < 255) {
			Temp_red_1++;
		}

		Serial.println("RED +  ICON  M7B_G");
		Serial.print("RED + ");
		Serial.println(Temp_red_1);
		delay(20);
		update_label_val(label_1, Temp_red_1);
		return;
	}

	else { // do nothing *
	}
	/// RED -
	if (Touch_inRange(Xval, Yval, M7B_H))
	{
		Update_btn_press(M7B_H);
		delay(1);
		if (Temp_red_1 > 0) {
			Temp_red_1--;

			//Update_btn_press(M7B_H);

		}

		Serial.println("RED -  ICON  M7B_H");
		Serial.print("RED - ");
		Serial.println(Temp_red_1);
		//delay(200);
		update_label_val(label_1, Temp_red_1);

		return;
	}

	else { // do nothing *
	}

	/// GREEN +
	if (Touch_inRange(Xval, Yval, M7B_I))
	{
		Update_btn_press(M7B_I);
		delay(1);
		if (Temp_green_1 < 255) {
			Temp_green_1++;
		}

		Serial.println("GREEN +  ICON  M7B_I");
		Serial.print("GREEN + ");
		Serial.println(Temp_green_1);
		delay(20);
		Serial.println("GREEN +  ICON  M7B_I");
		update_label_val(label_2, Temp_green_1);
		return;
	}
		
	
	else { // do nothing *
	}

	/// GREEN -

	if (Touch_inRange(Xval, Yval, M7B_J))
	{
		Update_btn_press(M7B_J);
		delay(1);


		Serial.println("GREEN -  ICON  M7B_J");
		return;
	}

	else { // do nothing *
	}
	/// BLUE +
	if (Touch_inRange(Xval, Yval, M7B_K))
	{
		Update_btn_press(M7B_K);
		//delay(1);
		if (Temp_blue_1 < 255) {
			Temp_blue_1++;
		}

		Serial.println("BLUE +  ICON  M7B_K");
		Serial.print("BLUE + ");
		Serial.println(Temp_blue_1);
	//	delay(20);
		Serial.println("GREEN +  ICON  M7B_K");
		update_label_val(label_3, Temp_blue_1);
		return;
	}
	else { // do nothing *
	}

	/// BLUE -


	if (Touch_inRange(Xval, Yval, M7B_L))
	{


		Update_btn_press(M7B_L);
		///delay(1);

		Serial.println("BLUE -  ICON  M7B_L");
		return;
	}

	else { // do nothing *
	}

	///////////////

	SCREEN_UPDATE = false;
}


void RGB_BUTTON_HOME(int Xtemp, int Ytemp) {

	if (Touch_inRange(Xtemp, Ytemp, M7B_B))
	{
		Serial.println("MENU SET TO 0 MEANING HOME SCREEN");
		MENU = 0;            // MENU SET TO 0 MEANING HOME SCREEN;
		SCREEN_UPDATE = true; // UPDATE SCREEN SINCE HOME BUTTON WAS PRESSED;
		SUB_SCREEN_UPDATE = false;

		return;
	}
	else { // do nothing *
	}


	}

