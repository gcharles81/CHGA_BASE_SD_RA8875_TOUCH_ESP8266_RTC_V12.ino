void Test_menu_update_label_val_String_NEW_A(int val) {

	//int16_t  TDF[4] = {0,0,0,0};

	//	create_label(label_KEYPAD);
	
		switch (Menu_item) {

		case 1:    // Lable 1 pressed 

			create_label(label_test_1);//Create lable to reset

			tft.setFontScale(1);//font x1

			tft.setTextColor(lbl_TXT_color, lbl_back_color);

			tft.setCursor(((label_test_1[2] / 2) + label_test_1[0]), ((label_test_1[3] / 2) + label_test_1[1]), true);

			tft.print(Val_Combined_lbl1);

			break;

		case 2:    // Lable 2 pressed 

			create_label(label_test_2);//Create lable to reset

			tft.setFontScale(1);//font x1

			tft.setTextColor(lbl_TXT_color, lbl_back_color);

			tft.setCursor(((label_test_2[2] / 2) + label_test_2[0]), ((label_test_2[3] / 2) + label_test_2[1]), true);

			tft.print(Val_Combined_lbl2);

			break;

		case 3:    // Lable 3 pressed 

			create_label(label_test_3);//Create lable to reset

			tft.setFontScale(1);//font x1

			tft.setTextColor(lbl_TXT_color, lbl_back_color);

			tft.setCursor(((label_test_3[2] / 2) + label_test_3[0]), ((label_test_3[3] / 2) + label_test_3[1]), true);

			tft.print(Val_Combined_lbl3);

			break;


			default:
			break;

		}

	}


void Test_menu_update_label_val_String_NEW_B(int val) {



		switch (Menu_item) {

		case 1:    // Write to lable 1
			if (Val_Combined_lbl1.length() < label_test_1_size) {
				create_label(label_test_1);//Create lable to reset

				Val_Combined_lbl1.concat(val);

				tft.setFontScale(1);//font x1

				tft.setTextColor(lbl_TXT_color, lbl_back_color);

				tft.setCursor(((label_test_1[2] / 2) + label_test_1[0]), ((label_test_1[3] / 2) + label_test_1[1]), true);

				tft.print(Val_Combined_lbl1);

				break;
			}

			else {
				break;
			}

		case 2:    // Write to lable 2
			if (Val_Combined_lbl2.length() < label_test_2_size) {
			create_label(label_test_2);//Create lable to reset

			Val_Combined_lbl2.concat(val);

			tft.setFontScale(1);//font x1

			tft.setTextColor(lbl_TXT_color, lbl_back_color);

			tft.setCursor(((label_test_2[2] / 2) + label_test_2[0]), ((label_test_2[3] / 2) + label_test_2[1]), true);

			tft.print(Val_Combined_lbl2);

			break;
			}

			else {
				break;
			}

		case 3:     // Write to lable 3 
			
			if (Val_Combined_lbl3.length() < label_test_3_size) {
			
			create_label(label_test_3);//Create lable to reset

			Val_Combined_lbl3.concat(val);

			tft.setFontScale(1);//font x1

			tft.setTextColor(lbl_TXT_color, lbl_back_color);

			tft.setCursor(((label_test_3[2] / 2) + label_test_3[0]), ((label_test_3[3] / 2) + label_test_3[1]), true);

			tft.print(Val_Combined_lbl3);


			break;
			}

			else {
				break;
			}

	

		}

	}



void Uboat(int Test) {


	if (Test == 99) {
		Test_menu_update_label_val_String_NEW_A(Test);

	}

	if (Test == 1){
		Test_menu_update_label_val_String_NEW_B(Test);
	}

	if (Test == 2) {
		Test_menu_update_label_val_String_NEW_B(Test);
	}

	if (Test == 3) {
		Test_menu_update_label_val_String_NEW_B(Test);
	}

	if (Test == 4) {
		Test_menu_update_label_val_String_NEW_B(Test);
	}
}

void BUTTON_KPD_MENU_New(int Xval, int Yval, int16_t LABLE[4]) {
	Serial.println("WDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD");
	//////////////////////////////////////////////////
	/// Number 1  KPD_A
	if (Touch_inRange(Xval, Yval, KPD_A))
	{

		delay(20);
		Update_btn_press(KPD_A);
		//	if (label_test_1_Locked == true) {
		Uboat(1);
		//	}


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
		Uboat(2);
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
		Uboat(3);
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
		Uboat(4);
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
		Uboat(5);


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
		Uboat(6);
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
		Uboat(7);
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
		Uboat(8);
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
		Uboat(9);
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

		Deduct_1_character_New();

		Uboat(99);
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

		if (Menu_item == 1){
			Val_Combined_lbl1 = "";
			Menu_item = 0;
		}

		if (Menu_item == 2) {
			Val_Combined_lbl2 = "";
			Menu_item = 0;
		}

		if (Menu_item == 3) {
			Val_Combined_lbl3 = "";
			Menu_item = 0;
		}

	
/*
		switch (Menu_item) {

		case 1:    // Lable 1 pressed

		VALUE_Combined_1 = "";
		Menu_item = 0;

		break;

		case 2:    // Lable 2 pressed

		VALUE_Combined_2 = "";
		Menu_item = 0;

		break;

		case 3:    // Lable 3 pressed

		VALUE_Combined_3 = "";
		Menu_item = 0;

		break;


	*/	




		SCREEN_UPDATE = true;
		return;

	}


	else { // do nothing *

	}

	///  Number 0
	if (Touch_inRange(Xval, Yval, KPD_L))
	{
		Update_btn_press(KPD_L);
		delay(20);
		Uboat(0);
		Serial.println("Number 0");
		return;
	}
	else { // do nothing *
	}

	///////////////

	SCREEN_UPDATE = false;

	return;


}




void TEST_Lable_Menu_NEW(int Xval, int Yval) {

	//////////////////////////////////////////////////

	Serial.println("Muuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuu");


	/// label_test_1
	if (Lable_Touch_inRange(Xval, Yval, label_test_1))
	{

		Menu_item = 1;
		Create_Keypad_01(350, 120);
		return;
	}

	else { // do nothing *

		
	}


	////label_test_2
	if (Lable_Touch_inRange(Xval, Yval, label_test_2))
	{

		Serial.println("Lable2 in not locked so I have to diplay input Keypad");

		Menu_item = 2;
		Create_Keypad_01(350, 120);
		return;
	}
	else { // do nothing *
		
	}


	///   label_test_3
	if (Lable_Touch_inRange(Xval, Yval, label_test_3))
	{

		Serial.println("Lable 3 in not locked so I have to diplay input Keypad");

		Menu_item = 3;
		Create_Keypad_01(350, 120);
		return;
	}
	else { // do nothing *
		

	}




}


void Test_Menu_BTN_Home(int Xtemp, int Ytemp) {

	if (Touch_inRange(Xtemp, Ytemp, M7B_B))
	{
		Serial.println("MENU SET TO 0 MEANING HOME SCREEN");
		MENU_NR = 0;            // MENU SET TO 0 MEANING HOME SCREEN;
		SCREEN_UPDATE = true; // UPDATE SCREEN SINCE HOME BUTTON WAS PRESSED;


		return;
	}
	else { // do nothing *
	}


}