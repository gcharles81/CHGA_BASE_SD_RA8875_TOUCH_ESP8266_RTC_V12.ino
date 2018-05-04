#pragma once
////
boolean label_test_1_Locked = false;
boolean label_test_2_Locked = false;
boolean label_test_3_Locked = false;
//
int label_test_1_size = 3;
int label_test_2_size = 3;
int label_test_3_size = 3;


int label_test_1_Value = 100;

int label_test_2_Value = 200;
int label_test_3_Value = 3;


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
/*

void Test_menu_check_sub(int Xval, int Yval) {

	// Serial.println("HOME BUTTON pressed");
	if (label_test_1_Locked == false) {
		TEST_Lable_Menu(Xval,Yval);
		BUTTON_HOME(Xval,Yval);
	}
	else if (label_test_1_Locked == true) {
		BUTTON_KPD_MENU(Xval,Yval, label_test_1);
	} //Do nothing


}
*/



