void SETTINGS_MENU(boolean reset_screen, int STATUS) {

  if (reset_screen == true) {
    tft.clearScreen();
    delay(200);
  }
  boolean Panel_background = true;
  String  Button_shape = "Round_Rect";//"Round_Rect";// CHGA 27 MAy 16 - either set  Rectangle or Round_Rect:
  boolean Write_button_number = false;
  tft.setFontScale(1);//font x1
  tft.setTextColor(RA8875_WHITE);
  boolean PRINT_NAME = true;
  int menu_size_X = 800;
  int menu_size_Y = 380;
  int tempnumber = 1;
  int MENU_COLUMNS = 3;
  int MENU_ROWS = 3;
  int X_COOR_Butt = 0;
  int Y_COOR_Butt = 0;
  int TEMP_X_COOR_Butt = 0;
  int TEMP_Y_COOR_Butt = 0;
  int number_of_buttons = 9;
  int value_count = 1;
  String NAME_1("LED");
  String NAME_2("CONFIGURATION");
  String NAME_3("OUTPUTS");
  String NAME_4("PH CALIB");
  String NAME_5("WIFI");
  String NAME_6("UDP DEBUG");
  String NAME_7("SPARE 3");
  String NAME_8("SPARE 4");
  String NAME_9("SPARE 5");

  uint16_t buttonX_size = (menu_size_X - ((MENU_COLUMNS + 1) * 5)) / MENU_COLUMNS;
  uint16_t buttonY_size = (menu_size_Y - ((MENU_ROWS + 1) * 5)) / MENU_ROWS;
  uint16_t X_OFFSET_START = (menu_size_X - (((MENU_COLUMNS - 1) * 5) + (buttonX_size * MENU_COLUMNS))) / 2;
  uint16_t Y_OFFSET_START = (menu_size_Y - (((MENU_ROWS - 1) * 5) + (buttonY_size * MENU_ROWS))) / 2;

  if (Panel_background == true) { //if true draw background behind buttons 
    //tft.fillRect(X_COOR_Butt, Y_COOR_Butt, menu_size_X, menu_size_Y, RA8875_LIGHT_GREY);//FILL the menu background
    tft.fillRect(X_COOR_Butt, Y_COOR_Butt, menu_size_X, 480, RA8875_LIGHT_GREY);//FILL the menu background
  }
  TEMP_X_COOR_Butt = (X_COOR_Butt + X_OFFSET_START);
  TEMP_Y_COOR_Butt = (Y_COOR_Butt + Y_OFFSET_START);

  for (int i = 1; i <= MENU_COLUMNS; i++) {

    if (tempnumber <= MENU_ROWS) {


    switch (STATUS) {

        case 0:    // your hand is on the sensor

          if (Button_shape == "Round_Rect") { // Determines the button Shape we want in the menu 
            
            tft.fillRoundRect(TEMP_X_COOR_Butt, TEMP_Y_COOR_Butt, buttonX_size, buttonY_size, 8, RA8875_DARK_ORANGE);
          }
          else if (Button_shape == "Rectangle") { // Determines the button Shape we want in the menu 
            
            tft.fillRect(TEMP_X_COOR_Butt, TEMP_Y_COOR_Butt, buttonX_size, buttonY_size, RA8875_GREEN);//BUTTON HOME VALUE 0
          }
        
          if (Write_button_number == true) {
            tft.setCursor(TEMP_X_COOR_Butt + (buttonX_size / 2), TEMP_Y_COOR_Butt + (buttonY_size / 2), true); //Set cursor in center to write button number
            tft.print(value_count);// Wtite button Number 
          }
        break;

        case 1:

              //  if ((Xtemp > TEMP_X_COOR_Butt && Xtemp < TEMP_X_COOR_Butt + buttonX_size) && (Ytemp > TEMP_Y_COOR_Butt && Ytemp < TEMP_Y_COOR_Butt + buttonY_size)) {
              //  Update_keypad_pressed_button(TEMP_X_COOR_Butt, TEMP_Y_COOR_Butt, buttonX_size, buttonY_size, RA8875_WHITE);
              //  }
        break;
        //
    }


      if (PRINT_NAME == true) {

        tft.setCursor(TEMP_X_COOR_Butt + (buttonX_size / 2), TEMP_Y_COOR_Butt + (buttonY_size / 2), true); //Set cursor in center to write button name
        
        switch (value_count) {
        case 1:    // your hand is on the sensor
          
          tft.print(NAME_1);
          break;
        case 2:    // your hand is close to the sensor

          tft.print(NAME_2);
          break;
        case 3:    // your hand is close to the sensor

          tft.print(NAME_3);
          break;
        case 4:    // your hand is close to the sensor

          tft.print(NAME_4);
          break;
        case 5:    // your hand is close to the sensor

          tft.print(NAME_5);
          break;
        case 6:    // your hand is close to the sensor

          tft.print(NAME_6);
          break;
        case 7:    // your hand is close to the sensor

          tft.print(NAME_7);
          break;
        case 8:    // your hand is close to the sensor

          tft.print(NAME_8);
          break;
        case 9:    // your hand is close to the sensor

          tft.print(NAME_9);
          break;

        }
      }

        TEMP_X_COOR_Butt = (TEMP_X_COOR_Butt + buttonX_size + 5);
        Serial.println(TEMP_X_COOR_Butt);

        /////////////////////////////////////////////////////////////////////////////////////
        if (i == MENU_COLUMNS && tempnumber <= MENU_ROWS) {
          i = 0;
          TEMP_Y_COOR_Butt = (TEMP_Y_COOR_Butt + buttonY_size + 5);
          TEMP_X_COOR_Butt = (X_COOR_Butt + X_OFFSET_START);
          tempnumber++;
        }
        /////////////////////////////////////////////////////////////////////////////////////
        value_count++;
        ///////////////////////////////////////////////////////////////////////////
        if (value_count == number_of_buttons + 1) {
          tempnumber = MENU_ROWS;
          i = MENU_COLUMNS;
        }
        ////////////////////////////////////////////////////////////////////////////
      }


    }
    tft.fillTriangle(5, 405, 65, 405, 35, 380, RA8875_BLUE);
    tft.fillRect(10, 405, 50, 35, RA8875_BLUE);//BUTTON HOME VALUE 0
  SCREEN_UPDATE = false;

  }
  

void Check_Settings_MENU_BUTTONS(int Xtemp , int Ytemp) {
  tft.setFontScale(1);//font x1
  tft.setTextColor(RA8875_BLACK);
  boolean PRINT_NAME = false;
  // tft.setFontScale(1);//font x1
  // tft.setTextColor(RA8875_WHITE);
  int menu_size_X = 800;
  int menu_size_Y = 380;
  int tempnumber = 1;
  int MENU_COLUMNS = 3;
  int MENU_ROWS = 3;
  int X_COOR_Butt = 0;
  int Y_COOR_Butt = 0;
  int TEMP_X_COOR_Butt = 0 ;
  int TEMP_Y_COOR_Butt = 0;
  int number_of_buttons = 9;
  int value_count = 0;

  uint16_t buttonX_size = ( menu_size_X - ((MENU_COLUMNS + 1 ) * 5) ) / MENU_COLUMNS;
  uint16_t buttonY_size = ( menu_size_Y - ((MENU_ROWS + 1 ) * 5) ) / MENU_ROWS;
  uint16_t X_OFFSET_START = (menu_size_X - (((MENU_COLUMNS - 1) * 5) + (buttonX_size * MENU_COLUMNS))) / 2;
  uint16_t Y_OFFSET_START = (menu_size_Y - (((MENU_ROWS - 1) * 5) + (buttonY_size * MENU_ROWS))) / 2;

  TEMP_X_COOR_Butt = (X_COOR_Butt + X_OFFSET_START);
  TEMP_Y_COOR_Butt = (Y_COOR_Butt + Y_OFFSET_START);

  for (int i = 1; i <= MENU_COLUMNS; i++) {
    if (tempnumber <= MENU_ROWS) {
      if ((Xtemp > TEMP_X_COOR_Butt && Xtemp < TEMP_X_COOR_Butt + buttonX_size ) && (Ytemp > TEMP_Y_COOR_Butt && Ytemp < TEMP_Y_COOR_Butt +  buttonY_size)){
        Update_keypad_pressed_button (TEMP_X_COOR_Butt, TEMP_Y_COOR_Butt, buttonX_size, buttonY_size, RA8875_WHITE);
    Serial.println("Got valid touch new chga");
    Settings_Menu_button_number = (value_count + 1);
    Valid_button_menu_touch = true;
    Serial.println(value_count);
    return;

      }
         TEMP_X_COOR_Butt = (TEMP_X_COOR_Butt + buttonX_size + 5);
     Serial.println(value_count);
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
  if (valid_touch = true) {
    Serial.println("or else I am here mate after you return");

  }
  
  }
}

void charles_1() {
  tft.clearScreen();
    //autocenter method
  tft.drawRect(100, 100, 100, 100, RA8875_RED);
  tft.setCursor(150, 150, true);//activate autocenter
  tft.setFontScale(2);
  tft.print("AB");
  tft.setFontScale(0);
  tft.setCursor(CENTER, CENTER);
  tft.print("centered");
}
