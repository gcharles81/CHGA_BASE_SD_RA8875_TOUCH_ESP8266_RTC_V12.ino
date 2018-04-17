#pragma once

int KPD_X_VAl = 0;
int KPD_Y_VAL = 0;

int X_M = 61;
int Y_M = 61;





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
int KPD_L[4] = { KPD_X_VAl,KPD_Y_VAL, 11,22 };//[0] = location X , [1] = location Y ,[2] = pic number ,[3] = pic number "pressed":



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

}

///
void BUTTON_KPD_MENU(int Xval, int Yval) {

	//////////////////////////////////////////////////
	/// Number 1  KPD_A
	if (Touch_inRange(Xval, Yval, KPD_A))
	{
		Serial.println("Number 1");
		return;
	}

	else { // do nothing *
	}
	////Number 2 KPD_B
	if (Touch_inRange(Xval, Yval, KPD_B))
	{
		Update_btn_press(KPD_B);
		delay(1);
		Serial.println("Number 2");
		return;
	}
	else { // do nothing *
	}
	///   Number 3
	if (Touch_inRange(Xval, Yval, KPD_C))
	{
		Update_btn_press(KPD_C);
		delay(1);
		MENU++;
		SCREEN_UPDATE = true;
		Serial.println("Number 3");
		return;
	}
	else { // do nothing *
	}
	/// PREV PAGE
	if (Touch_inRange(Xval, Yval, KPD_D))
	{
		Update_btn_press(KPD_D);
		delay(1);
		Serial.println("PREV PAGE  ICON  KPD_D");

		MENU--;
		SCREEN_UPDATE = true;
		return;


	}
	else { // do nothing *
	}
	/// TEST - COLOR
	if (Touch_inRange(Xval, Yval, KPD_E))
	{
		Update_btn_press(KPD_E);
		delay(1);
		Serial.println("TEST - COLOR  ICON  KPD_E");
		return;
	}
	else { // do nothing *
	}
	/// SAVE SETTINGS to EEPROM / SD
	if (Touch_inRange(Xval, Yval, KPD_F))
	{
		Update_btn_press(KPD_F);
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

		Serial.println("SAVE SETTINGS to EEPROM / SD  ICON  KPD_F");
		return;
	}

	else { // do nothing *
	}
	/// RED +
	if (Touch_inRange(Xval, Yval, KPD_G))
	{
		Update_btn_press(KPD_G);
		delay(1);

		if (Temp_red_1 < 255) {
			Temp_red_1++;
		}

		Serial.println("RED +  ICON  KPD_G");
		Serial.print("RED + ");
		Serial.println(Temp_red_1);
		delay(20);
		update_label_val(label_1, Temp_red_1);
		return;
	}

	else { // do nothing *
	}
	/// RED -
	if (Touch_inRange(Xval, Yval, KPD_H))
	{
		Update_btn_press(KPD_H);
		delay(1);
		if (Temp_red_1 > 0) {
			Temp_red_1--;

			//Update_btn_press(KPD_H);

		}

		Serial.println("RED -  ICON  KPD_H");
		Serial.print("RED - ");
		Serial.println(Temp_red_1);
		//delay(200);
		update_label_val(label_1, Temp_red_1);

		return;
	}

	else { // do nothing *
	}

	/// GREEN +
	if (Touch_inRange(Xval, Yval, KPD_I))
	{
		Update_btn_press(KPD_I);
		delay(1);
		if (Temp_green_1 < 255) {
			Temp_green_1++;
		}

		Serial.println("GREEN +  ICON  KPD_I");
		Serial.print("GREEN + ");
		Serial.println(Temp_green_1);
		delay(20);
		Serial.println("GREEN +  ICON  KPD_I");
		update_label_val(label_2, Temp_green_1);
		return;
	}


	else { // do nothing *
	}

	/// GREEN -

	if (Touch_inRange(Xval, Yval, KPD_J))
	{
		Update_btn_press(KPD_J);
		delay(1);

		if (Temp_green_1 >= 1) {
			Temp_green_1--;
		}

		Serial.println("GREEN -  ICON  KPD_J");
		update_label_val(label_2, Temp_green_1);
		return;
	}

	else { // do nothing *
	}
	/// BLUE +
	if (Touch_inRange(Xval, Yval, KPD_K))
	{
		Update_btn_press(KPD_K);
		//delay(1);
		if (Temp_blue_1 < 255) {
			Temp_blue_1++;
		}

		Serial.println("BLUE +  ICON  KPD_K");
		Serial.print("BLUE + ");
		Serial.println(Temp_blue_1);
		//	delay(20);
		Serial.println("GREEN +  ICON  KPD_K");
		update_label_val(label_3, Temp_blue_1);
		return;
	}
	else { // do nothing *
	}

	/// BLUE -


	if (Touch_inRange(Xval, Yval, KPD_L))
	{


		Update_btn_press(KPD_L);

		if (Temp_blue_1 >= 1) {
			Temp_blue_1--;
		}

		///delay(1);
		update_label_val(label_3, Temp_blue_1);
		Serial.println("BLUE -  ICON  KPD_L");
		return;
	}

	else { // do nothing *
	}

	///////////////

	SCREEN_UPDATE = false;
}