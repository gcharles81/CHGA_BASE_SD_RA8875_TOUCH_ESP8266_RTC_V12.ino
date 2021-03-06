
void GET_TOUCH_XY_VALUE () {
  int XXX = 0;
  int YYY = 0;

  uint8_t i;
  uint16_t x, y;
  cts.getTSregisters(registers);
  current_touches = cts.getTScoordinates(new_coordinates, registers);
  if (current_touches < 1) return;
  if (current_touches > 1) return;



  x = new_coordinates[0][0];
  y = new_coordinates[0][1];

  Serial.print("X coordinate - ");
  Serial.println(x);;
  Serial.print("Y coordinate - ");
  Serial.println(y);
  //  delay(100);


  tft.setCursor(0, 0); //set cursor work in pixel!!!
  switch (MENU) {
    case 0:    // your hand is on the sensor
      Serial.println("MENU 0 BUTTON pressed");
      BUTTON_TOUCH_MENU_0_1 (new_coordinates[0][0], new_coordinates[0][1]);
      break;
    case 1:    // your hand is close to the sensor

      Serial.println("HOME BUTTON pressed");
      BUTTON_TOUCH_SETTINGS_MENU(new_coordinates[0][0], new_coordinates[0][1]);
      break;
    case 2:    // your hand is a few inches from the sensor
      Serial.println("LED MENU BUTTON pressed");
      BUTTON_HOME(new_coordinates[0][0], new_coordinates[0][1]);
      break;

    case 3:    // your hand is nowhere near the sensor
      Serial.println("RGB 1 CONFIGURATION MENU BUTTON pressed");
      BUTTON_TOUCH_RGB_MENU(new_coordinates[0][0], new_coordinates[0][1]);
	  RGB_BUTTON_HOME(new_coordinates[0][0], new_coordinates[0][1]);
      break;
    case 4:    // your hand is close to the sensor
		Serial.println("RGB 2 CONFIGURATION MENU BUTTON pressed");
		BUTTON_TOUCH_RGB_MENU(new_coordinates[0][0], new_coordinates[0][1]);
		RGB_BUTTON_HOME(new_coordinates[0][0], new_coordinates[0][1]);
      break;
    case 5:    // your hand is a few inches from the sensor
		Serial.println("RGB 3 CONFIGURATION MENU BUTTON pressed");
		BUTTON_TOUCH_RGB_MENU(new_coordinates[0][0], new_coordinates[0][1]);
		RGB_BUTTON_HOME(new_coordinates[0][0], new_coordinates[0][1]);
      break;
    case 6:    // your hand is nowhere near the sensor
		Serial.println("RGB 4 CONFIGURATION MENU BUTTON pressed");
		BUTTON_TOUCH_RGB_MENU(new_coordinates[0][0], new_coordinates[0][1]);
		RGB_BUTTON_HOME(new_coordinates[0][0], new_coordinates[0][1]);
      break;
    case 7:    // your hand is close to the sensor

      Serial.println("HOME BUTTON pressed");
      BUTTON_HOME(new_coordinates[0][0], new_coordinates[0][1]);
      break;

  }

  if (SUB_SCREEN_UPDATE == true) {

	  
	  TRACK_BAR_POSITION(new_coordinates[0][0], new_coordinates[0][1]);
  }
}


void TRACK_BAR_POSITION(int Xtemp, int Ytemp) {

	if ((Xtemp > TRB_X && Xtemp < TRB_X + TRB_SIZE_X) && (Ytemp > TRB_Y && Ytemp < TRB_Y + TRB_SIZE_Y)) {

		int BVC = map(Xtemp, TRB_X, (TRB_X+TRB_SIZE_X), 0,255);
		TRACKBARVAL = BVC;
		delay(10);
		Track_bar_test();
	}

	else {

	}

}





void RESET_Temp_touch_values () {
  //Set all touch X,Y,Fingers temp values to 0
  Temp_TOUCH_X_VAL = 0;
  Temp_TOUCH_Y_VAL = 0;
  Temp_touch_FINGER = 0;
}

void CHGA_TOUCH () {

  GET_TOUCH_XY_VALUE ();

}
void BUTTON_HOME (int Xtemp , int Ytemp) {

  if ((Xtemp > 5 && Xtemp < 85 ) && (Ytemp > 395 && Ytemp < 475)) {
    Serial.println("HOME BUTTON PRESSED A");

    MENU = 0;            // MENU SET TO 0 MEANING HOME SCREEN;
    SCREEN_UPDATE = true; // UPDATE SCREEN SINCE HOME BUTTON WAS PRESSED;
  }
}

void BUTTON_TOUCH_MENU_0_1 (int Xtemp , int Ytemp) {

  //tft.fillRoundRect(610, 300, 80, 80, 12, RA8875_BLUE);//BUTTON SETUP for value referance only
  if ((Xtemp > 1 && Xtemp < 67 ) && (Ytemp > 414 && Ytemp < 479)) {
    Serial.println("BUTTON 0_1 PRESSED A");
    // tft.fillRoundRect(610, 300, 80, 80, 12, RA8875_GREEN);//ENTER SETTINGS BUTTON
    //1, 414, 66
    tft.dispicown(1, 417, 66, 66, 1574616); //Dispay pic172 // For pressed state.
    delay(25);//We have to wait 25 ms after we load pipc from Flash must

    MENU = 1;            // MENU SET TO 1 MEANING SETTINGS SCREEN;
    SCREEN_UPDATE = true; // UPDATE SCREEN SINCE SETTINGS BUTTON WAS PRESSED;

  }
}

void BUTTON_TOUCH_SETTINGS_MENU (int Xtemp , int Ytemp) {

  int icon_Size = 130;
  int Half_icon_offset = icon_Size / 2;
  int pitch_X_icon = (tft.width () / 2 / 2);

  int X_COL_1 = ((pitch_X_icon) - (Half_icon_offset));
  int X_COL_2 = ((pitch_X_icon) + (X_COL_1));
  int X_COL_3 = ((pitch_X_icon) + (X_COL_2));
  int Y_ROW_1 = 75;
  int Y_ROW_2 = 250;



  //tft.fillRoundRect(10, 70,385,80, 12, RA8875_BLUE);//BUTTON LED for value referance only
  if ((Xtemp > X_COL_1 && Xtemp < X_COL_1 + icon_Size ) && (Ytemp > Y_ROW_1 && Ytemp < Y_ROW_1 + icon_Size)) {
    Serial.println("BUTTON LED SETTINGS PRESSED A");
    //  tft.fillRoundRect(10, 70, 385, 80, 12, RA8875_GREEN); //ENTER SETTINGS BUTTON
    tft.dispicown(X_COL_1, Y_ROW_1, icon_Size, icon_Size, 5877200); //Dispay pic507 //507,     130,     130, 5877200, For pressed state.
    delay(200);//We have to wait 25 ms after we load pipc from Flash mus
    //

    MENU = 2;            // MENU SET TO 1 MEANING SETTINGS SCREEN;
    SCREEN_UPDATE = true; // UPDATE SCREEN SINCE SETTINGS BUTTON WAS PRESSED;
    //delay(200);
    return;
  }



  if ((Xtemp > X_COL_2 && Xtemp < X_COL_2 + icon_Size ) && (Ytemp > Y_ROW_1 && Ytemp < Y_ROW_1 + icon_Size)) {
    Serial.println("BUTTON LIGHTS SETTINGS PRESSED");

    tft.dispicown(X_COL_2, Y_ROW_1, icon_Size, icon_Size, 4253816); //Dispay pic384 384,     130,     130, 4253816, For pressed state.


    MENU = 3;            // MENU SET TO 1 MEANING SETTINGS SCREEN;
    SCREEN_UPDATE = true; // UPDATE SCREEN SINCE SETTINGS BUTTON WAS PRESSED;
    delay(200);//We have to wait 25 ms after we load pipc from Flash mus
    return;
  }


  if ((Xtemp > X_COL_3 && Xtemp < X_COL_3 + icon_Size ) && (Ytemp > Y_ROW_1 && Ytemp < Y_ROW_1 + icon_Size)) {
    Serial.println("BUTTON DEBUG SETTINGS PRESSED");

    tft.dispicown(X_COL_3, Y_ROW_1, icon_Size, icon_Size, 2259424); //Dispay pic237,     130,     130, 2259424, For pressed state.
    delay(200);//We have to wait 25 ms after we load pipc from Flash mus

    MENU = 4;            // MENU SET TO 1 MEANING SETTINGS SCREEN;
    SCREEN_UPDATE = true; // UPDATE SCREEN SINCE SETTINGS BUTTON WAS PRESSED;

    return;
  }
  if ((Xtemp > X_COL_1 && Xtemp < X_COL_1 + icon_Size ) && (Ytemp > Y_ROW_2 && Ytemp < Y_ROW_2 + icon_Size)) {
    Serial.println("BUTTON DATE/TIME SETTINGS PRESSED A");
    //  tft.fillRoundRect(10, 70, 385, 80, 12, RA8875_GREEN); //ENTER SETTINGS BUTTON
    tft.dispicown(X_COL_1, Y_ROW_2, icon_Size, icon_Size, 857616); //Dispay pic    83,     130,     130,  857616,, For pressed state.
    delay(200);//We have to wait 25 ms after we load pipc from Flash mus
    //

    MENU = 5;            // MENU SET TO 1 MEANING SETTINGS SCREEN;
    SCREEN_UPDATE = true; // UPDATE SCREEN SINCE SETTINGS BUTTON WAS PRESSED;
    //delay(200);
    return;
  }



  if ((Xtemp > X_COL_2 && Xtemp < X_COL_2 + icon_Size ) && (Ytemp > Y_ROW_2 && Ytemp < Y_ROW_2 + icon_Size)) {
    Serial.println("BUTTON WIFI SETTINGS PRESSED");

    tft.dispicown(X_COL_2, Y_ROW_2, icon_Size, icon_Size, 4652408); //Dispay pic 416,     130,     130, 4652408, For pressed state.
    delay(200);//We have to wait 25 ms after we load pipc from Flash mus

    MENU = 6;            // MENU SET TO 1 MEANING SETTINGS SCREEN;
    SCREEN_UPDATE = true; // UPDATE SCREEN SINCE SETTINGS BUTTON WAS PRESSED;

    return;
  }


  if ((Xtemp > X_COL_3 && Xtemp < X_COL_3 + icon_Size ) && (Ytemp > Y_ROW_2 && Ytemp < Y_ROW_2 + icon_Size)) {
    Serial.println("BUTTON ABOUT PRESSED");

    tft.dispicown(X_COL_3, Y_ROW_2, icon_Size, icon_Size, 7492608); //Dispay pic  609,     130,     130, 7492608,For pressed state.
    delay(200);//We have to wait 25 ms after we load pipc from Flash mus

    MENU = 7;            // MENU SET TO 1 MEANING SETTINGS SCREEN;
    SCREEN_UPDATE = true; // UPDATE SCREEN SINCE SETTINGS BUTTON WAS PRESSED;

    return;
  }
  BUTTON_HOME(Xtemp, Ytemp);
}


void KEYPAD_BUTTONS (int Xtemp , int Ytemp) {

  boolean goodtouch = false;////for delay X_COL_2 if touch is not valid
  int tempx = 0;
  int tempy = 0;
  int tempxsize = 0;
  int tempysize = 0;


  int KEYPAD_XPOS = KEYPAD_XPOS_VAL;
  int KEYPAD_YPOS = KEYPAD_YPOS_VAL;
  //int KPD_Button_SIZE = 80; // 80x80 pixels
  //int KPD_Button_PITCH = 100; // pitch between buttons 100 pixels
  Serial.println(Xtemp);
  Serial.println(Ytemp);
  //tft.fillRoundRect(10, 70,385,80, 12, RA8875_BLUE);//BUTTON LED for value referance only
  //(p.y > 3 && p.y < 160 && p.x > 210 && p.x < 266)

  if ((Xtemp > KEYPAD_XPOS && Xtemp < KEYPAD_XPOS + KPD_Button_SIZE_X ) && (Ytemp > KEYPAD_YPOS && Ytemp < KEYPAD_YPOS +  KPD_Button_SIZE_Y)) {
    //tft.fillRect(KEYPAD_XPOS,KEYPAD_YPOS,KPD_Button_SIZE_X,KPD_Button_SIZE_Y,KPD_Button_color_touched);//DRAW  button NO1 touched color

    tempx = KEYPAD_XPOS;
    tempy = KEYPAD_YPOS;
    tempxsize = KPD_Button_SIZE_X;
    tempysize = KPD_Button_SIZE_Y;

    Update_keypad_pressed_button(tempx, tempy, tempxsize, tempysize, KPD_Button_color_touched);
    Write_selected_value ("1");
    Update_keypad_pressed_button(tempx, tempy, tempxsize, tempysize, KPD_Button_color);

    goodtouch = true;
  }

  if ((Xtemp > KEYPAD_XPOS + KPD_Button_PITCH_X  && Xtemp < KEYPAD_XPOS + KPD_Button_SIZE_X + KPD_Button_PITCH_X  ) && (Ytemp > KEYPAD_YPOS && Ytemp < KEYPAD_YPOS +  KPD_Button_SIZE_Y)) {
    Serial.println("BUTTON 2 PRESSED");
    // tft.fillRect(KEYPAD_XPOS + KPD_Button_PITCH_X,KEYPAD_YPOS, KPD_Button_SIZE_X,KPD_Button_SIZE_Y,KPD_Button_color_touched);//DRAW button NO2 touched color

    tempx = (KEYPAD_XPOS + KPD_Button_PITCH_X);
    tempy = KEYPAD_YPOS;
    tempxsize = KPD_Button_SIZE_X;
    tempysize = KPD_Button_SIZE_Y;

    Update_keypad_pressed_button(tempx, tempy, tempxsize, tempysize, KPD_Button_color_touched);
    Write_selected_value ("2");
    Update_keypad_pressed_button(tempx, tempy, tempxsize, tempysize, KPD_Button_color);

    goodtouch = true;
  }

  if ((Xtemp > KEYPAD_XPOS + KPD_Button_PITCH_X + KPD_Button_PITCH_X && Xtemp < KEYPAD_XPOS + KPD_Button_SIZE_X + KPD_Button_PITCH_X + KPD_Button_PITCH_X ) && (Ytemp > KEYPAD_YPOS && Ytemp < KEYPAD_YPOS +  KPD_Button_SIZE_Y)) {
    Serial.println("BUTTON 3 PRESSED");
    //  tft.fillRect(KEYPAD_XPOS + KPD_Button_PITCH_X + KPD_Button_PITCH_X , KEYPAD_YPOS , KPD_Button_SIZE_X,KPD_Button_SIZE_Y, KPD_Button_color_touched);//DRAW  button NO1 touched color


    tempx = (KEYPAD_XPOS + KPD_Button_PITCH_X + KPD_Button_PITCH_X);
    tempy = KEYPAD_YPOS;
    tempxsize = KPD_Button_SIZE_X;
    tempysize = KPD_Button_SIZE_Y;

    Update_keypad_pressed_button(tempx, tempy, tempxsize, tempysize, KPD_Button_color_touched);
    Write_selected_value ("3");
    Update_keypad_pressed_button(tempx, tempy, tempxsize, tempysize, KPD_Button_color);

    goodtouch = true;
  }

  if ((Xtemp > KEYPAD_XPOS && Xtemp < KEYPAD_XPOS + KPD_Button_SIZE_X ) && (Ytemp > KEYPAD_YPOS +  KPD_Button_PITCH_Y  && Ytemp < KEYPAD_YPOS +  KPD_Button_PITCH_Y +  KPD_Button_SIZE_Y)) {
    Serial.println("BUTTON 4 PRESSED");
    //  tft.fillRect(KEYPAD_XPOS + KPD_Button_PITCH_X, KEYPAD_YPOS , KPD_Button_SIZE_X, KPD_Button_SIZE_Y, KPD_Button_color_touched);//DRAW button NO2 touched color

    tempx = KEYPAD_XPOS;
    tempy = (KEYPAD_YPOS + KPD_Button_PITCH_Y);
    tempxsize = KPD_Button_SIZE_X;
    tempysize = KPD_Button_SIZE_Y;

    Update_keypad_pressed_button(tempx, tempy, tempxsize, tempysize, KPD_Button_color_touched);
    Write_selected_value ("4");
    Update_keypad_pressed_button(tempx, tempy, tempxsize, tempysize, KPD_Button_color);

    goodtouch = true;
  }

  if ((Xtemp > KEYPAD_XPOS + KPD_Button_PITCH_X && Xtemp < KEYPAD_XPOS +  KPD_Button_PITCH_X + KPD_Button_SIZE_X ) && (Ytemp > KEYPAD_YPOS +  KPD_Button_PITCH_Y  && Ytemp < KEYPAD_YPOS +  KPD_Button_PITCH_Y +  KPD_Button_SIZE_Y)) {
    Serial.println("BUTTON 5 PRESSED");
    //tft.fillRect(KEYPAD_XPOS, KEYPAD_YPOS, KPD_Button_SIZE_X, KPD_Button_SIZE_Y, KPD_Button_color_touched);//DRAW  button NO1 touched color

    tempx = (KEYPAD_XPOS + KPD_Button_PITCH_X );
    tempy = (KEYPAD_YPOS + KPD_Button_PITCH_Y );
    tempxsize = KPD_Button_SIZE_X;
    tempysize = KPD_Button_SIZE_Y;

    Update_keypad_pressed_button(tempx, tempy, tempxsize, tempysize, KPD_Button_color_touched);
    Write_selected_value ("5");
    Update_keypad_pressed_button(tempx, tempy, tempxsize, tempysize, KPD_Button_color);

    goodtouch = true;
  }

  if ((Xtemp > KEYPAD_XPOS + KPD_Button_PITCH_X * 2 && Xtemp < KEYPAD_XPOS +  KPD_Button_PITCH_X  * 2 + KPD_Button_SIZE_X ) && (Ytemp > KEYPAD_YPOS +  KPD_Button_PITCH_Y  && Ytemp < KEYPAD_YPOS +  KPD_Button_PITCH_Y +  KPD_Button_SIZE_Y)) {
    Serial.println("BUTTON 6 PRESSED");
    //tft.fillRect(KEYPAD_XPOS + KPD_Button_PITCH_X, KEYPAD_YPOS , KPD_Button_SIZE_X, KPD_Button_SIZE_Y, KPD_Button_color_touched);//DRAW button NO2 touched color

    tempx = (KEYPAD_XPOS + KPD_Button_PITCH_X + KPD_Button_PITCH_X);
    tempy = (KEYPAD_YPOS + KPD_Button_PITCH_Y );
    tempxsize = KPD_Button_SIZE_X;
    tempysize = KPD_Button_SIZE_Y;

    Update_keypad_pressed_button(tempx, tempy, tempxsize, tempysize, KPD_Button_color_touched);
    Write_selected_value ("6");
    Update_keypad_pressed_button(tempx, tempy, tempxsize, tempysize, KPD_Button_color);

    goodtouch = true;
  }

  if ((Xtemp > KEYPAD_XPOS && Xtemp < KEYPAD_XPOS + KPD_Button_SIZE_X ) && (Ytemp > KEYPAD_YPOS +  KPD_Button_PITCH_Y * 2 && Ytemp < KEYPAD_YPOS +  KPD_Button_PITCH_Y * 2 +  KPD_Button_SIZE_Y)) {
    Serial.println("BUTTON 7 PRESSED");
    //tft.fillRect(KEYPAD_XPOS, KEYPAD_YPOS, KPD_Button_SIZE_X, KPD_Button_SIZE_Y, KPD_Button_color_touched);//DRAW  button NO1 touched color

    tempx = (KEYPAD_XPOS);
    tempy = (KEYPAD_YPOS + KPD_Button_PITCH_Y + KPD_Button_PITCH_Y );
    tempxsize = KPD_Button_SIZE_X;
    tempysize = KPD_Button_SIZE_Y;

    Update_keypad_pressed_button(tempx, tempy, tempxsize, tempysize, KPD_Button_color_touched);
    Write_selected_value ("7");
    Update_keypad_pressed_button(tempx, tempy, tempxsize, tempysize, KPD_Button_color);

    goodtouch = true;
  }

  if ((Xtemp > KEYPAD_XPOS + KPD_Button_PITCH_X && Xtemp < KEYPAD_XPOS +  KPD_Button_PITCH_X + KPD_Button_SIZE_X ) && (Ytemp > KEYPAD_YPOS +  KPD_Button_PITCH_Y * 2  && Ytemp < KEYPAD_YPOS +  KPD_Button_PITCH_Y * 2 +  KPD_Button_SIZE_Y)) {
    Serial.println("BUTTON 8 PRESSED");
    //tft.fillRect(KEYPAD_XPOS + KPD_Button_PITCH_X, KEYPAD_YPOS , KPD_Button_SIZE_X, KPD_Button_SIZE_Y, KPD_Button_color_touched);//DRAW button NO2 touched color

    tempx = (KEYPAD_XPOS + KPD_Button_PITCH_X );
    tempy = (KEYPAD_YPOS + KPD_Button_PITCH_Y + KPD_Button_PITCH_Y);
    tempxsize = KPD_Button_SIZE_X;
    tempysize = KPD_Button_SIZE_Y;

    Update_keypad_pressed_button(tempx, tempy, tempxsize, tempysize, KPD_Button_color_touched);
    Write_selected_value ("8");
    Update_keypad_pressed_button(tempx, tempy, tempxsize, tempysize, KPD_Button_color);

    goodtouch = true;
  }
  if ((Xtemp > KEYPAD_XPOS + KPD_Button_PITCH_X * 2 && Xtemp < KEYPAD_XPOS +  KPD_Button_PITCH_X  * 2 + KPD_Button_SIZE_X ) && (Ytemp > KEYPAD_YPOS +  KPD_Button_PITCH_Y * 2  && Ytemp < KEYPAD_YPOS +  KPD_Button_PITCH_Y * 2 +  KPD_Button_SIZE_Y)) {
    Serial.println("BUTTON 9 PRESSED");
    //tft.fillRect (KEYPAD_XPOS + (KPD_Button_PITCH_X * 2), KEYPAD_YPOS + (KPD_Button_PITCH_Y * 3), KPD_Button_SIZE_X, KPD_Button_SIZE_Y, KPD_Button_color_touched);//DRAW button NO9 touched color

    tempx = (KEYPAD_XPOS + KPD_Button_PITCH_X + KPD_Button_PITCH_X);
    tempy = (KEYPAD_YPOS + KPD_Button_PITCH_Y + KPD_Button_PITCH_Y);
    tempxsize = KPD_Button_SIZE_X;
    tempysize = KPD_Button_SIZE_Y;

    Update_keypad_pressed_button(tempx, tempy, tempxsize, tempysize, KPD_Button_color_touched);
    Write_selected_value ("9");
    Update_keypad_pressed_button(tempx, tempy, tempxsize, tempysize, KPD_Button_color);

    goodtouch = true;
  }

  if ((Xtemp > KEYPAD_XPOS && Xtemp < KEYPAD_XPOS + KPD_Button_SIZE_X ) && (Ytemp > KEYPAD_YPOS +  KPD_Button_PITCH_Y * 3 && Ytemp < KEYPAD_YPOS +  KPD_Button_PITCH_Y * 3 +  KPD_Button_SIZE_Y)) {
    Serial.println("BUTTON SAVE PRESSED");
    // tft.fillRect(KEYPAD_XPOS, KEYPAD_YPOS + (KPD_Button_PITCH_Y * 3), KPD_Button_SIZE_X, KPD_Button_SIZE_Y, KPD_Button_color_touched);//DRAW  button SAVE touched color

    tempx = (KEYPAD_XPOS);
    tempy = (KEYPAD_YPOS + KPD_Button_PITCH_Y + KPD_Button_PITCH_Y + KPD_Button_PITCH_Y);
    tempxsize = KPD_Button_SIZE_X;
    tempysize = KPD_Button_SIZE_Y;

    Update_keypad_pressed_button(tempx, tempy, tempxsize, tempysize, KPD_Button_color_touched);
    Write_selected_value ("SAVE");
    Update_keypad_pressed_button(tempx, tempy, tempxsize, tempysize, KPD_Button_color);
    //    LOAD_TIMERS_CONFIG();
    goodtouch = true;
  }  if  ((Xtemp > KEYPAD_XPOS + KPD_Button_PITCH_X && Xtemp < KEYPAD_XPOS +  KPD_Button_PITCH_X + KPD_Button_SIZE_X ) && (Ytemp > KEYPAD_YPOS +  KPD_Button_PITCH_Y * 3  && Ytemp < KEYPAD_YPOS +  KPD_Button_PITCH_Y * 3 +  KPD_Button_SIZE_Y)) {
    Serial.println("BUTTON CANCEL PRESSED");
    //tft.fillRect(KEYPAD_XPOS + KPD_Button_PITCH_X, KEYPAD_YPOS + (KPD_Button_PITCH_Y * 3), KPD_Button_SIZE_X, KPD_Button_SIZE_Y, KPD_Button_color_touched);//DRAW button CANCEL touched color

    tempx = (KEYPAD_XPOS + KPD_Button_PITCH_X);
    tempy = (KEYPAD_YPOS + KPD_Button_PITCH_Y + KPD_Button_PITCH_Y + KPD_Button_PITCH_Y);
    tempxsize = KPD_Button_SIZE_X;
    tempysize = KPD_Button_SIZE_Y;

    Update_keypad_pressed_button(tempx, tempy, tempxsize, tempysize, KPD_Button_color_touched);
    Write_selected_value ("CANCEL");
    Update_keypad_pressed_button(tempx, tempy, tempxsize, tempysize, KPD_Button_color);

    goodtouch = true;
  }

  if ((Xtemp > KEYPAD_XPOS + KPD_Button_PITCH_X * 2 && Xtemp < KEYPAD_XPOS +  KPD_Button_PITCH_X  * 2 + KPD_Button_SIZE_X ) && (Ytemp > KEYPAD_YPOS +  KPD_Button_PITCH_Y * 3  && Ytemp < KEYPAD_YPOS +  KPD_Button_PITCH_Y * 3 +  KPD_Button_SIZE_Y)) {
    Serial.println("BUTTON . PRESSED");
    // tft.fillRect (KEYPAD_XPOS + (KPD_Button_PITCH_X * 2), KEYPAD_YPOS + (KPD_Button_PITCH_Y * 3), KPD_Button_SIZE_X, KPD_Button_SIZE_Y, KPD_Button_color_touched);//DRAW button . touched color

    tempx = (KEYPAD_XPOS + KPD_Button_PITCH_X + KPD_Button_PITCH_X);
    tempy = (KEYPAD_YPOS + KPD_Button_PITCH_Y * 3);
    tempxsize = KPD_Button_SIZE_X;
    tempysize = KPD_Button_SIZE_Y;

    Update_keypad_pressed_button(tempx, tempy, tempxsize, tempysize, KPD_Button_color_touched);
    Write_selected_value (".");
    Update_keypad_pressed_button(tempx, tempy, tempxsize, tempysize, KPD_Button_color);

    goodtouch = true;
  }

  if (goodtouch == false) {
    delay(5);
    Serial.println("TOUCH COORDINATES NOT VALID SO I WILL WAIT 500ms");


  }

}

void Update_keypad_pressed_button (int X , int Y , int sizex , int sizey , float color ) {

  tft.drawRect(X, Y, sizex, sizey, color);
  tft.drawRect(X + 1, Y + 1, sizex - 2, sizey - 2, color);
  tft.drawRect(X + 2, Y  + 2, sizex - 4, sizey - 4, color);
  tft.drawRect(X + 3, Y  + 3, sizex - 6, sizey - 6, color);
  tft.drawRect(X + 4, Y  + 4, sizex - 8, sizey - 8, color);

  //delay(200);
  tft.drawRect(X, Y, sizex, sizey, KPD_Button_color);
  tft.drawRect(X + 1, Y  + 1, sizex - 2, sizey - 2, KPD_Button_color);
  tft.drawRect(X + 2, Y + 2, sizex - 4, sizey - 4, KPD_Button_color);
  tft.drawRect(X + 3, Y + 3, sizex - 6, sizey - 6, KPD_Button_color);
  tft.drawRect(X + 4, Y  + 4, sizex - 8, sizey - 8, KPD_Button_color);
}

void Write_selected_value (char* val) {

  tft.setFontScale(5);//font Xval
  tft.setTextColor(RA8875_BLUE, RA8875_BLACK);
  tft.setCursor(5, 350);
  tft.print(val);
  delay(50);
}

void CHGA_BCD() {


  tft.setTextColor(RA8875_GREEN, RA8875_BLACK);
//  tft.setFont(&squarefont_14);

  tft.setFontScale(1);
  tft.setCursor(0, 80);
  tft.println("Xval - ABCDEFGH1234");
  tft.setTextColor(RA8875_RED, RA8875_BLACK);

  tft.setFontScale(2);
  tft.setCursor(0, 120);
  tft.println("X2 - ABCDEFGH1234");
  tft.setTextColor(RA8875_BLUE, RA8875_BLACK);

  tft.setFontScale(3);
  tft.setCursor(0, 200);
  tft.println("X3 - ABCDEFGH1234");

  tft.setFontScale(4);
  tft.setCursor(0, 280);
  tft.println("X4 - AB");

  tft.setFontScale(5);
  tft.setCursor(0, 360);
  tft.println("X5 - A");
  delay(1000);
  ////////////////////////////////////////////////////////////////////////////
  tft.clearScreen();
  tft.fillWindow(RA8875_BLACK);//RA8875_LIGHT_GREY
  delay(150);

  tft.setTextColor(RA8875_GREEN, RA8875_BLACK);
//  tft.setFont(&SquareOne_14);

  tft.setFontScale(1);
  tft.setCursor(0, 80);
  tft.println("Xval - ABCDEFGH1234");
  tft.setTextColor(RA8875_RED, RA8875_BLACK);

  tft.setFontScale(2);
  tft.setCursor(0, 120);
  tft.println("X2 - ABCDEF");
  tft.setTextColor(RA8875_BLUE, RA8875_BLACK);

  tft.setFontScale(3);
  tft.setCursor(0, 200);
  tft.println("X3 - AB");

  tft.setFontScale(4);
  tft.setCursor(0, 280);
  tft.println("X4 - AB");

  tft.setFontScale(0);
  tft.setCursor(0, 360);
  tft.println("X5 - A");
  delay(1000);
  ///////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////
  tft.clearScreen();
  tft.fillWindow(RA8875_BLACK);//RA8875_LIGHT_GREY
  delay(150);

  tft.setTextColor(RA8875_GREEN, RA8875_BLACK);
//  tft.setFont(&aerial_22);

  tft.setFontScale(1);
  tft.setCursor(0, 80);
  tft.println("Xval - ABCDEFGH1234");
  tft.setTextColor(RA8875_RED, RA8875_BLACK);

  tft.setFontScale(2);
  tft.setCursor(0, 120);
  tft.println("X2 - A");
  tft.setTextColor(RA8875_BLUE, RA8875_BLACK);

  tft.setFontScale(3);
  tft.setCursor(0, 200);
  tft.println("X3 - AB");

  tft.setFontScale(4);
  tft.setCursor(0, 280);
  tft.println("X4 - AB");

  tft.setFontScale(0);
  tft.setCursor(0, 360);
  tft.println("X5 - ABCD");
  delay(1000);
  ///////////////////////////////////////////////////////////////////

  ////////////////////////////////////////////////////////////////////////////
  tft.clearScreen();
  tft.fillWindow(RA8875_BLACK);//RA8875_LIGHT_GREY
  delay(150);

  tft.setTextColor(RA8875_GREEN, RA8875_BLACK);
//  tft.setFont(&dubstreptix_14);

  tft.setFontScale(1);
  tft.setCursor(0, 80);
  tft.println("Xval - ABCDEFGH1234");
  tft.setTextColor(RA8875_RED, RA8875_BLACK);

  tft.setFontScale(2);
  tft.setCursor(0, 120);
  tft.println("X2 - ABCDEFGH1234");
  tft.setTextColor(RA8875_BLUE, RA8875_BLACK);

  tft.setFontScale(3);
  tft.setCursor(0, 200);
  tft.println("X3 - AB");

  tft.setFontScale(4);
  tft.setCursor(0, 280);
  tft.println("X4 - A");

  tft.setFontScale(0);
  tft.setCursor(0, 360);
  tft.println("X5 - A");
  delay(1000);
  ///////////////////////////////////////////////////////////////////

  ////////////////////////////////////////////////////////////////////////////
  tft.clearScreen();
  tft.fillWindow(RA8875_BLACK);//RA8875_LIGHT_GREY
  delay(150);

  tft.setTextColor(RA8875_GREEN, RA8875_BLACK);
//  tft.setFont(&orbitron_16);

  tft.setFontScale(1);
  tft.setCursor(0, 80);
  tft.println("Xval - ABCDEFGH1234");
  tft.setTextColor(RA8875_RED, RA8875_BLACK);

  tft.setFontScale(2);
  tft.setCursor(0, 120);
  tft.println("X2 - ABCDEFGH1234");
  tft.setTextColor(RA8875_BLUE, RA8875_BLACK);

  tft.setFontScale(3);
  tft.setCursor(0, 200);
  tft.println("X3 - AB");

  tft.setFontScale(4);
  tft.setCursor(0, 280);
  tft.println("X4 - A");

  tft.setFontScale(0);
  tft.setCursor(0, 360);
  tft.println("X5 - A");
  delay(1000);
  ///////////////////////////////////////////////////////////////////

  //tft.setFont(INTFONT);




}
