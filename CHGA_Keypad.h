#pragma once

int KPD_X_VAl = 0;
int KPD_Y_VAL = 0;

int X_M = 61;
int Y_M = 61;
String VALUE_Combined = "";

int16_t label_KEYPAD[4] = { 172, 233,113,40 };


int KPD_A[4] = { KPD_X_VAl,KPD_Y_VAL,143,154 };//[0] = location X , [1] = location Y ,[143] = pic number ,[154] = pic number "pressed": //1



int KPD_B[4] = { KPD_X_VAl,KPD_Y_VAL ,147,158 };//[0] = location X , [1] = location Y ,[147] = pic number ,[158] = pic number "pressed"://2



int KPD_C[4] = { KPD_X_VAl,KPD_Y_VAL ,146,157 };//[0] = location X , [1] = location Y ,[146] = pic number ,[157] = pic number "pressed"://3


int KPD_D[4] = { KPD_X_VAl,KPD_Y_VAL,140,151 };//[0] = location X , [1] = location Y ,[140] = pic number ,[151] = pic number "pressed"://4
int KPD_E[4] = { KPD_X_VAl,KPD_Y_VAL,139,150};//[0] = location X , [1] = location Y ,[139 = pic number ,[150] = pic number "pressed"://5
int KPD_F[4] = { KPD_X_VAl,KPD_Y_VAL,145,156};//[0] = location X , [1] = location Y ,[145] = pic number ,[156] = pic number "pressed"://6
int KPD_G[4] = { KPD_X_VAl,KPD_Y_VAL,144,155};//[0] = location X , [1] = location Y ,[144] = pic number ,[155] = pic number "pressed"://7
int KPD_H[4] = { KPD_X_VAl,KPD_Y_VAL,138,149};//[0] = location X , [1] = location Y ,[138] = pic number ,[149] = pic number "pressed"://8
int KPD_I[4] = { KPD_X_VAl,KPD_Y_VAL,142,153};//[0] = location X , [1] = location Y ,[142] = pic number ,[153] = pic number "pressed"://9
int KPD_J[4] = { KPD_X_VAl,KPD_Y_VAL,141,152};//[0] = location X , [1] = location Y ,[141] = pic number ,[152] = pic number "pressed"://c
int KPD_K[4] = { KPD_X_VAl,KPD_Y_VAL,117,21 };//[0] = location X , [1] = location Y ,[117] = pic number ,[3] = pic number "pressed":
int KPD_L[4] = { KPD_X_VAl,KPD_Y_VAL, 148,159 };//[0] = location X , [1] = location Y ,[148] = pic number ,[159] = pic number "pressed":



void Create_Keypad_01(int Xloc, int Yloc) {


	/// ***** later we have to update the Layer handling if possible the keypad will be shown on transparent layer 

	///create_label(label_KEYPAD);//Create label to show keypad value


	Update_KPDVAL(Xloc, Yloc); /// Re Calculate the Button positions and update button array to be used for button position also for touch detection 


	// ****** keypad border 

	// tft.drawRect(KPD_A[0] - 3, KPD_A[1] - 3, (KPD_L[0]  + 6), (KPD_L[1] + 57 + 6), RA8875_WHITE);
	// tft.drawRect(KPD_A[0] - 2, KPD_A[1] - 2, KPD_L[0] + 57 + 4, KPD_L[1] + 57 + 4, RA8875_WHITE);

	// **********************

	// Create the buttons ***

	create_btn(KPD_A); //Create button 1 
	DELAY_00D();
	create_btn(KPD_B);//Create button 2 
	DELAY_00D();
	create_btn(KPD_C);//Create button 3 
	DELAY_00D();
	create_btn(KPD_D);//Create button 4 
	DELAY_00D();
	create_btn(KPD_E);//Create button 5
	DELAY_00D();
	create_btn(KPD_F);//Create button 6 
	DELAY_00D();
	create_btn(KPD_G);//Create button 7 
	DELAY_00D();
	create_btn(KPD_H);//Create button 8 
	DELAY_00D();
	create_btn(KPD_I);//Create button 9 
	DELAY_00D();
	create_btn(KPD_J);//Create button Cancel 
	DELAY_00D();
	create_btn(KPD_K);//Create button Save 
	DELAY_00D();
	create_btn(KPD_L);//Create button 0 
	DELAY_00D();

	// *******************

	SCREEN_UPDATE = false; // False no continous refresh //


}

void DELAY_00D() {
	delay(1);
}


void update_label_val_String(int16_t TDF[4], int val) {
	create_label(label_KEYPAD);

	if (val == 99) {

	//	VALUE_Combined.concat(val);

		tft.setFontScale(1);//font x1

		tft.setTextColor(lbl_TXT_color, lbl_back_color);

		tft.setCursor(((TDF[2] / 2) + TDF[0]), ((TDF[3] / 2) + TDF[1]), true);

		tft.print(VALUE_Combined);
	}

	else {
		VALUE_Combined.concat(val);

		tft.setFontScale(1);//font x1

		tft.setTextColor(lbl_TXT_color, lbl_back_color);

		tft.setCursor(((TDF[2] / 2) + TDF[0]), ((TDF[3] / 2) + TDF[1]), true);

		tft.print(VALUE_Combined);
	}


}

void Update_KPDVAL(int XXX , int YYY) {

	int temp_X = XXX;
	int temp_Y = YYY;

	KPD_A[0] = XXX;
	KPD_A[1] = YYY;

	XXX = (XXX + X_M);

	KPD_B[0] = XXX;
	KPD_B[1] = YYY;

	XXX = (XXX + X_M);

	KPD_C[0] = XXX;
	KPD_C[1] = YYY;

	XXX = temp_X;
	YYY = (YYY + Y_M);

	KPD_D[0] = XXX;
	KPD_D[1] = YYY;

	XXX = (XXX + X_M);

	KPD_E[0] = XXX;
	KPD_E[1] = YYY;

	XXX = (XXX + X_M);

	KPD_F[0] = XXX;
	KPD_F[1] = YYY;

	XXX = temp_X;
	YYY = (YYY + Y_M);

	KPD_G[0] = XXX;
	KPD_G[1] = YYY;

	XXX = (XXX + X_M);

	KPD_H[0] = XXX;
	KPD_H[1] = YYY;

	XXX = (XXX + X_M);

	KPD_I[0] = XXX;
	KPD_I[1] = YYY;


	XXX = temp_X;
	YYY = (YYY + Y_M);

	KPD_J[0] = XXX;
	KPD_J[1] = YYY;

	XXX = (XXX + X_M);
	KPD_K[0] = XXX;
	KPD_K[1] = YYY;

	XXX = (XXX + X_M);
	KPD_L[0] = XXX;
	KPD_L[1] = YYY;
}

///
void BUTTON_KPD_MENU(int Xval, int Yval) {
	
	//////////////////////////////////////////////////
	/// Number 1  KPD_A
	if (Touch_inRange(Xval, Yval, KPD_A))
	{
		delay(20);
		Update_btn_press(KPD_A);
		update_label_val_String(label_KEYPAD, 1);
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
		update_label_val_String(label_KEYPAD, 2);
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
		update_label_val_String(label_KEYPAD, 3);
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
		update_label_val_String(label_KEYPAD, 4);
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
		update_label_val_String(label_KEYPAD, 5);


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
		update_label_val_String(label_KEYPAD, 6);
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
		update_label_val_String(label_KEYPAD, 7);
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
		update_label_val_String(label_KEYPAD, 8);
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
		update_label_val_String(label_KEYPAD, 9);
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

		VALUE_Combined.remove(length - 1,1); // Remove six characters starting at index=2
		update_label_val_String(label_KEYPAD, 99);
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
		update_label_val_String(label_KEYPAD, 0);
		Serial.println("Number 0");
		return;
	}
	else { // do nothing *
	}

	///////////////

	SCREEN_UPDATE = false;
}