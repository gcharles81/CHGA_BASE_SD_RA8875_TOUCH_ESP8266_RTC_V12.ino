#pragma once
/*
boolean label_test_1_Locked = false;
boolean label_test_2_Locked = false;
boolean label_test_3_Locked = false;
*/

//String VALUE_Combined = "";
int16_t label_test_1[4] = { 172,153,113,40 };
int16_t label_test_2[4] = { 172, 233,113,40 };
int16_t label_test_3[4] = { 172, 313,113,40 };




int M8B_A[4] = {450,200,168,171 };//[0] = location X , [1] = location Y ,[2] = pic number ,[3] = pic number "pressed":
/*
int M8B_B[4] = { 740,6 ,84,66 };//[0] = location X , [1] = location Y ,[2] = pic number ,[3] = pic number "pressed":
int M8B_C[4] = { 740,420 ,41,54 };//[0] = location X , [1] = location Y ,[2] = pic number ,[3] = pic number "pressed":
int M8B_D[4] = { 3,420,126,90 };//[0] = location X , [1] = location Y ,[2] = pic number ,[3] = pic number "pressed":
int M8B_E[4] = { 530,320,109,91 };//[0] = location X , [1] = location Y ,[2] = pic number ,[3] = pic number "pressed":
int M8B_F[4] = { 640,320,99,81 };//[0] = location X , [1] = location Y ,[2] = pic number ,[3] = pic number "pressed":
int M8B_G[4] = { 300,145,1,6 };//[0] = location X , [1] = location Y ,[2] = pic number ,[3] = pic number "pressed":
int M8B_H[4] = { 100,145,2,7 };//[0] = location X , [1] = location Y ,[2] = pic number ,[3] = pic number "pressed":
int M8B_I[4] = { 300,225,16,26 };//[0] = location X , [1] = location Y ,[2] = pic number ,[3] = pic number "pressed":
int M8B_J[4] = { 100,225,17,27 };//[0] = location X , [1] = location Y ,[2] = pic number ,[3] = pic number "pressed":
int M8B_K[4] = { 300,305,10,21 };//[0] = location X , [1] = location Y ,[2] = pic number ,[3] = pic number "pressed":
int M8B_L[4] = { 100,305, 11,22 };//[0] = location X , [1] = location Y ,[2] = pic number ,[3] = pic number "pressed":
*/

void Test_menu_update_label_val_String(int val) {

	//int16_t  TDF[4] = {0,0,0,0};

//	create_label(label_KEYPAD);
	if ((val == 99) && (label_test_1_Locked == true)) {
		
		create_label(label_test_1);//Create lable to reset

		tft.setFontScale(1);//font x1

		tft.setTextColor(lbl_TXT_color, lbl_back_color);

		tft.setCursor(((label_test_1[2] / 2) + label_test_1[0]), ((label_test_1[3] / 2) + label_test_1[1]), true);

		tft.print(VALUE_Combined);
	}

	else if ((val < 99) && (label_test_1_Locked == true) && (VALUE_Combined.length()<3))
	{
		create_label(label_test_1);//Create lable to reset

		VALUE_Combined.concat(val);

		tft.setFontScale(1);//font x1

		tft.setTextColor(lbl_TXT_color, lbl_back_color);

		tft.setCursor(((label_test_1[2] / 2) + label_test_1[0]), ((label_test_1[3] / 2) + label_test_1[1]), true);

		tft.print(VALUE_Combined);
	}

	if ((val == 99) && (label_test_2_Locked == true)) {

		create_label(label_test_2);//Create lable to reset

		tft.setFontScale(1);//font x1

		tft.setTextColor(lbl_TXT_color, lbl_back_color);

		tft.setCursor(((label_test_2[2] / 2) + label_test_2[0]), ((label_test_2[3] / 2) + label_test_2[1]), true);

		tft.print(VALUE_Combined);
	}

	else if ((val < 99) && (label_test_2_Locked == true) && (VALUE_Combined.length()<3))
	{
		create_label(label_test_2);//Create lable to reset

		VALUE_Combined.concat(val);

		tft.setFontScale(1);//font x1

		tft.setTextColor(lbl_TXT_color, lbl_back_color);

		tft.setCursor(((label_test_2[2] / 2) + label_test_2[0]), ((label_test_2[3] / 2) + label_test_2[1]), true);

		tft.print(VALUE_Combined);
	}


	if ((val == 99) && (label_test_3_Locked == true)) {

		create_label(label_test_3);//Create lable to reset

		tft.setFontScale(1);//font x1

		tft.setTextColor(lbl_TXT_color, lbl_back_color);

		tft.setCursor(((label_test_3[2] / 2) + label_test_3[0]), ((label_test_3[3] / 2) + label_test_3[1]), true);

		tft.print(VALUE_Combined);
	}

	else if ((val < 99) && (label_test_3_Locked == true) && (VALUE_Combined.length()<3))
	{
		create_label(label_test_3);//Create lable to reset

		VALUE_Combined.concat(val);

		tft.setFontScale(1);//font x1

		tft.setTextColor(lbl_TXT_color, lbl_back_color);

		tft.setCursor(((label_test_3[2] / 2) + label_test_3[0]), ((label_test_3[3] / 2) + label_test_3[1]), true);

		tft.print(VALUE_Combined);
	}
}



void TEST_Lable_Menu(int Xval, int Yval) {

	//////////////////////////////////////////////////




	/// label_test_1
	if (Lable_Touch_inRange(Xval, Yval, label_test_1) && label_test_1_Locked == false)
	{

		Serial.println("Lable 1 in not locked so I have to diplay input Keypad");
		
		Create_Keypad_01(350, 120);

		label_test_1_Locked = true;
		return;	
	}

	else { // do nothing *
	}
	////label_test_2
	if (Lable_Touch_inRange(Xval, Yval, label_test_2))
	{

		Serial.println("Lable 2");
		return;
	}
	else { // do nothing *
	}
	///   label_test_3
	if (Lable_Touch_inRange(Xval, Yval, label_test_3))
	{

		Serial.println("Lable 3");
		return;
	}
	else { // do nothing *
	}
}


////////////////////////////////////////////
void BUTTON_TOUCH_TEST_MENU(int Xval, int Yval) {

	//////////////////////////////////////////////////
	/// MENU TYPE ICON  M7B_A
	if (Touch_inRange(Xval, Yval, M8B_A)  && label_test_1_Locked == false)
	{
		Serial.println("MENU TYPE ICON  M8B_A");

		return;
	}

	else { // do nothing *
	}


	SCREEN_UPDATE = false;
}

void Test_Menu_Subitems_Check(int Xtemp, int Ytemp) {

	if (label_test_1_Locked == false) {
		TEST_Lable_Menu(Xtemp, Ytemp);
		Test_Menu_BTN_Home(Xtemp, Ytemp);
	}
	else if (label_test_1_Locked == true) {
		BUTTON_KPD_MENU(Xtemp, Xtemp, label_test_1);
	} //Do nothing
}

void Test_Menu_BTN_Home(int Xtemp, int Ytemp) {

	if (Touch_inRange(Xtemp, Ytemp, M7B_B))
	{
		Serial.println("MENU SET TO 0 MEANING HOME SCREEN");
		MENU = 0;            // MENU SET TO 0 MEANING HOME SCREEN;
		SCREEN_UPDATE = true; // UPDATE SCREEN SINCE HOME BUTTON WAS PRESSED;
		

		return;
	}
	else { // do nothing *
	}


}
void BUTTON_KPD_MENU(int Xval, int Yval, int16_t LABLE[4]) {

	//////////////////////////////////////////////////
	/// Number 1  KPD_A
	if (Touch_inRange(Xval, Yval, KPD_A))
	{

		delay(20);
		Update_btn_press(KPD_A);
		if (label_test_1_Locked == true) {
			Test_menu_update_label_val_String(1);
		}


		Serial.println("Number 1");
		return;
	}

	else { // do nothing *
	}
	////Number 2 KPD_B
	if (Touch_inRange(Xval, Yval, KPD_B))
	{
		Update_btn_press(KPD_B);
		delay(20);
		Test_menu_update_label_val_String(2);
		Serial.println("Number 2");
		return;
	}
	else { // do nothing *
	}
	///   Number 3
	if (Touch_inRange(Xval, Yval, KPD_C))
	{
		Update_btn_press(KPD_C);
		delay(20);
		Test_menu_update_label_val_String(3);
		Serial.println("Number 3");
		return;
	}
	else { // do nothing *
	}
	/// Number 4
	if (Touch_inRange(Xval, Yval, KPD_D))
	{
		Update_btn_press(KPD_D);
		delay(20);
		Test_menu_update_label_val_String(4);
		Serial.println("Number 4");
		return;


	}
	else { // do nothing *
	}
	/// Number 5
	if (Touch_inRange(Xval, Yval, KPD_E))
	{
		Update_btn_press(KPD_E);
		delay(20);
		Test_menu_update_label_val_String(5);


		Serial.println("Number 5");
		return;
	}
	else { // do nothing *
	}
	/// Number 6
	if (Touch_inRange(Xval, Yval, KPD_F))
	{
		Update_btn_press(KPD_F);
		delay(20);
		Test_menu_update_label_val_String(6);
		Serial.println("Number 6");

		return;
	}

	else { // do nothing *
	}
	/// Number 7
	if (Touch_inRange(Xval, Yval, KPD_G))
	{
		Update_btn_press(KPD_G);
		delay(20);
		Test_menu_update_label_val_String(7);
		Serial.println("Number 7");

		return;
	}

	else { // do nothing *
	}
	/// Number 8
	if (Touch_inRange(Xval, Yval, KPD_H))
	{
		Update_btn_press(KPD_H);
		delay(20);
		Test_menu_update_label_val_String(8);
		Serial.println("Number 8");
		return;
	}

	else { // do nothing *
	}

	/// Number 9
	if (Touch_inRange(Xval, Yval, KPD_I))
	{
		Update_btn_press(KPD_I);
		delay(20);
		Test_menu_update_label_val_String(9);
		Serial.print("Number 8");
		return;
	}


	else { // do nothing *
	}

	/// Cancel

	if (Touch_inRange(Xval, Yval, KPD_J))
	{
		Update_btn_press(KPD_J);
		delay(20);
		Serial.println("Cancel");

		int length = (VALUE_Combined.length());

		VALUE_Combined.remove(length - 1, 1); // Remove six characters starting at index=2
		Test_menu_update_label_val_String(99);
		//VALUE_Combined[length - 1] = '\0';

		return;
	}

	else { // do nothing *
	}
	/// SAVE Number
	if (Touch_inRange(Xval, Yval, KPD_K))
	{
		Update_btn_press(KPD_K);
		delay(20);
		Serial.println("SAVE Number");
		///Just to be used during debug to clear valuestring 
		VALUE_Combined = "";
		create_label(label_KEYPAD);//Create label to show keypad value
								   //////
		return;
	}
	else { // do nothing *
	}

	///  Number 0
	if (Touch_inRange(Xval, Yval, KPD_L))
	{
		Update_btn_press(KPD_L);
		delay(20);
		Test_menu_update_label_val_String(0);
		Serial.println("Number 0");
		return;
	}
	else { // do nothing *
	}

	///////////////

	SCREEN_UPDATE = false;
}
