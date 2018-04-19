void serialEvent() {
  while (Serial.available()) {
     int inByte = Serial.read();
     
     switch (inByte) {
      case 'a':
      SETTINGS_MENU(true, 0); //if recall with true means reset screen on entrance 
        break;
      case 'b':
    RTC_CHGA ();








      
          SCREEN_UPDATE = true;
        break;
      case 'c':
         Serial.println("cWWW");
tft.clearScreen();
         delay(500);
         tft.brightness(255);
         SCREEN_UPDATE = true;
        break;
      case 'd':
         Serial.println("dWWW");
         tft.brightness(25);
        break;
      case 'e':
         Serial.println("eWWW");
         tft.brightness(15);
        break;
        case 'f':
        Serial.println("fWWW");
         //tft.changeMode(GRAPHIC);
        ///INFO_BOX_4
        tft.fillRoundRect(590, 70, 190, 340, 12, RA8875_WHITE);
        delay(50);
         //tft.changeMode(GRAPHIC);
//       bmpDraw("sun.bmp", 610, 75);
        break;
         case 'g':
        Serial.println("gWWW");
         //tft.changeMode(GRAPHIC);
        ///INFO_BOX_4
        tft.fillRoundRect(590, 70, 190, 340, 12, RA8875_WHITE);
         //tft.changeMode(GRAPHIC);
 //     bmpDraw("moon.bmp", 610, 75);
        break;
         case 'h':
        Serial.println("gWWW");
         //tft.changeMode(GRAPHIC);
        ///INFO_BOX_4
        tft.fillRoundRect(590, 70, 190, 340, 12, RA8875_WHITE);
         //tft.changeMode(GRAPHIC);
   //   bmpDraw      ("moon.bmp", 610, 75);
        break;
         case 'k':
        Serial.println("kWWW");
         //tft.changeMode(GRAPHIC);
        ///INFO_BOX_4
        tft.fillRoundRect(590, 70, 190, 340, 12, RA8875_WHITE);

        break;
         case 'x':
        Serial.println("xWWW");
         //tft.changeMode(GRAPHIC);
        ///INFO_BOX_4
        tft.fillRoundRect(590, 70, 190, 340, 12, RA8875_WHITE);
//    bmpDraw("alert.bmp",  400, 75);//copy the enclosed image in a SD card (check the folder!!!)
        break;
        case '+':
        Serial.println("MENU +");
MENU_NR++;
SCREEN_UPDATE = true;
        break;
        
        case '-':
        Serial.println("Menu -");
        MENU_NR--;
        SCREEN_UPDATE = true;
        break;
        
        case '3':
        Serial.println("333");

        MENU_NR = 0;
    //    redrawTFT = true;
        break;
        
        case '4':
        Serial.println("444");
       
        break;
  }
}
 }
