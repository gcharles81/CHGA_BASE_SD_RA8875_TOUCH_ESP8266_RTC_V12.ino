void Deduct_1_character() {
	
	int length = (Val_Combined_lbl1.length());

	if (label_test_1_Locked == true) { Val_Combined_lbl1.remove(length - 1, 1); }
	
	
	length = (Val_Combined_lbl2.length());
	if (label_test_2_Locked == true) { Val_Combined_lbl2.remove(length - 1, 1); }
	
	
	
	length = (Val_Combined_lbl3.length());
	if (label_test_3_Locked == true) { Val_Combined_lbl3.remove(length - 1, 1); }

}


	







		void Deduct_1_character_New() {

			int length = 0;


			switch (Menu_item) {

			case 1:    // Lable 1 pressed 
				length = (Val_Combined_lbl1.length());
				Val_Combined_lbl1.remove(length - 1, 1);
				break;

			case 2:    // Lable 2 pressed 
				length = (Val_Combined_lbl2.length());
				Val_Combined_lbl2.remove(length - 1, 1);
				break;

			case 3:    // Lable 3 pressed 
				length = (Val_Combined_lbl3.length());
				Val_Combined_lbl3.remove(length - 1, 1);
				break;
			}
		}


		void update_label_values_from_int() {

			Val_Combined_lbl1 = String(label_test_1_Value);
			Val_Combined_lbl2 = String(label_test_2_Value);
			Val_Combined_lbl3 = String(label_test_2_Value);
		}






			void Test_menu_update_label_val_String(int val) {

				//int16_t  TDF[4] = {0,0,0,0};

				//	create_label(label_KEYPAD);
				if ((val == 99) && (label_test_1_Locked == true)) {

					create_label(label_test_1);//Create lable to reset

					tft.setFontScale(1);//font x1

					tft.setTextColor(lbl_TXT_color, lbl_back_color);

					tft.setCursor(((label_test_1[2] / 2) + label_test_1[0]), ((label_test_1[3] / 2) + label_test_1[1]), true);

					tft.print(Val_Combined_lbl1);
				}

				else if ((val < 99) && (label_test_1_Locked == true) && (Val_Combined_lbl1.length() < 3))
				{
					create_label(label_test_1);//Create lable to reset

					Val_Combined_lbl1.concat(val);

					tft.setFontScale(1);//font x1

					tft.setTextColor(lbl_TXT_color, lbl_back_color);

					tft.setCursor(((label_test_1[2] / 2) + label_test_1[0]), ((label_test_1[3] / 2) + label_test_1[1]), true);

					tft.print(Val_Combined_lbl1);
				}

				if ((val == 99) && (label_test_2_Locked == true)) {

					create_label(label_test_2);//Create lable to reset

					tft.setFontScale(1);//font x1

					tft.setTextColor(lbl_TXT_color, lbl_back_color);

					tft.setCursor(((label_test_2[2] / 2) + label_test_2[0]), ((label_test_2[3] / 2) + label_test_2[1]), true);

					tft.print(Val_Combined_lbl2);
				}

				else if ((val < 99) && (label_test_2_Locked == true) && (Val_Combined_lbl1.length() < 3))
				{
					create_label(label_test_2);//Create lable to reset

					Val_Combined_lbl2.concat(val);

					tft.setFontScale(1);//font x1

					tft.setTextColor(lbl_TXT_color, lbl_back_color);

					tft.setCursor(((label_test_2[2] / 2) + label_test_2[0]), ((label_test_2[3] / 2) + label_test_2[1]), true);

					tft.print(Val_Combined_lbl2);
				}


				if ((val == 99) && (label_test_3_Locked == true)) {

					create_label(label_test_3);//Create lable to reset

					tft.setFontScale(1);//font x1

					tft.setTextColor(lbl_TXT_color, lbl_back_color);

					tft.setCursor(((label_test_3[2] / 2) + label_test_3[0]), ((label_test_3[3] / 2) + label_test_3[1]), true);

					tft.print(Val_Combined_lbl3);
				}

				else if ((val < 99) && (label_test_3_Locked == true) && (Val_Combined_lbl3.length() < 3))
				{
					create_label(label_test_3);//Create lable to reset

					Val_Combined_lbl3.concat(val);

					tft.setFontScale(1);//font x1

					tft.setTextColor(lbl_TXT_color, lbl_back_color);

					tft.setCursor(((label_test_3[2] / 2) + label_test_3[0]), ((label_test_3[3] / 2) + label_test_3[1]), true);

					tft.print(Val_Combined_lbl3);
				}
			}






			void TEST_Lable_Menu(int Xval, int Yval) {

				//////////////////////////////////////////////////

				Serial.println("Muuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuu");


				/// label_test_1
				if (Lable_Touch_inRange(Xval, Yval, label_test_1) && label_test_1_Locked == false)
				{

					Serial.println("Lable 1 in not locked so I have to diplay input Keypad");

					Create_Keypad_01(350, 120);
					label_test_1_Locked = true;
					label_test_2_Locked = false;
					label_test_3_Locked = false;

					return;
				}

				else { // do nothing *
				}
				////label_test_2
				if (Lable_Touch_inRange(Xval, Yval, label_test_2) && label_test_2_Locked == false)
				{

					Serial.println("Lable2 in not locked so I have to diplay input Keypad");

					Create_Keypad_01(350, 120);
					label_test_1_Locked = false;
					label_test_2_Locked = true;
					label_test_3_Locked = false;
					return;
				}
				else { // do nothing *
				}
				///   label_test_3
				if (Lable_Touch_inRange(Xval, Yval, label_test_3) && label_test_3_Locked == false)
				{

					Serial.println("Lable 3 in not locked so I have to diplay input Keypad");

					Create_Keypad_01(350, 120);
					label_test_1_Locked = false;
					label_test_2_Locked = false;
					label_test_3_Locked = true;
					return;
				}
				else { // do nothing *
				}
			}


			////////////////////////////////////////////
			void BUTTON_TOUCH_TEST_MENU(int Xval, int Yval) {

				//////////////////////////////////////////////////
				/// MENU TYPE ICON  M7B_A
				if (Touch_inRange(Xval, Yval, M8B_A) && label_test_1_Locked == false)
				{
					Serial.println("MENU TYPE ICON  M8B_A");

					return;
				}

				else { // do nothing *
				}


				SCREEN_UPDATE = false;
			}

	

void BUTTON_KPD_MENU(int Xval, int Yval, int16_t LABLE[4]) {
				Serial.println("WDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD");
				//////////////////////////////////////////////////
				/// Number 1  KPD_A
				if (Touch_inRange(Xval, Yval, KPD_A))
				{

					delay(20);
					Update_btn_press(KPD_A);
					//	if (label_test_1_Locked == true) {
					Test_menu_update_label_val_String(1);
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

					Deduct_1_character();

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
					/*
					Serial.println("SAVE Number");
					///Just to be used during debug to clear valuestring
					VALUE_Combined = "";
					create_label(label_KEYPAD);//Create label to show keypad value
					*/

					Val_Combined_lbl1 = "";

					if (label_test_1_Locked == true) { Val_Combined_lbl1 = ""; label_test_1_Locked = false; }
					if (label_test_2_Locked == true) { Val_Combined_lbl2 = ""; label_test_2_Locked = false; }
					if (label_test_3_Locked == true) { Val_Combined_lbl3 = ""; label_test_3_Locked = false; }
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
					Test_menu_update_label_val_String(0);
					Serial.println("Number 0");
					return;
				}
				else { // do nothing *
				}

				///////////////

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
