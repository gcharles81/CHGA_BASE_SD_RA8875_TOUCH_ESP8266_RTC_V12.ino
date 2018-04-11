/*
void LOAD_TIMERS_CONFIG()

{
   commandFile.close();
  Serial.println("LOADING AQUA.txt FILE WITH ALL TIMERS ACTIVATION ON or OFF ");
  // Open the settings file for reading:
  commandFile = SD.open("AQUA.txt");
  
   if (SD.exists("AQUA.txt")) {
    Serial.println("AQUA.txt exists.");
  }
  else {
    Serial.println("AQUA.txt doesn't exist.");
  }
 // commandFile = SD.open("AQUA.txt");
  //delay(1000);
  char* demo ;
  char* demo2 ;
  int delayvalue = 100;
  demo = "Opening Config File";
 
  delay(delayvalue);
  char character;
  String description = "";
  String value = "";

  // read from the file until there's nothing else in it:
  while (commandFile.available()) {
    character = commandFile.read();
    if (character == '/')         {
      // Comment - ignore this line
      while (character != '\n') {
        character = commandFile.read();
      };
    }
    else if (isalnum(character))      { // Add a character to the description
      description.concat(character);
    }
    else if (character == '=')         { // start checking the value for possible results
      // First going to trim out all trailing white spaces
      do {
        character = commandFile.read();
      }
      while (character == ' ');

      if (description == "SUNRISE") {
        if (character == '1') {
          SUNRISE = true;
          demo =("");
          demo = "SUNRISE = ON";
//Print_to_TFT(demo);
  
  delay(delayvalue);
    Serial.println("gggggsdasdsad");

        }
        else {
          SUNRISE = false;
          demo = "SUNRISE = OFF";
//Print_to_TFT(demo);
  
  delay(delayvalue);
  Serial.println("33gggggsdasdsad");
        }
      }
      else if (description == "SUNSET") {
        if (character == '1') {
          SUNSET = true;
          demo = "SUNRSET = ON";
    //      Print_to_TFT(demo);
          delay(delayvalue);

        }
        else {
          SUNSET = false;
          demo = "SUNSET = OFF";
       //   Print_to_TFT(demo);
          delay(delayvalue);

        }
      }
      else if (description == "DAY1") {
        if (character == '1') {
          DAY1 = true;
          demo = "DAY1 = ON";
        //   Print_to_TFT(demo);
          delay(delayvalue);



        }
        else {
          DAY1 = false;
          demo = "DAY1 = OFF";
// Print_to_TFT(demo);
          delay(delayvalue);

        }
      }
      else if (description == "DAY2") {
        if (character == '1') {
          DAY2 = true;
          demo = "DAY2 = ON";
     //     Print_to_TFT(demo);
          delay(delayvalue);

        }
        else {
          DAY2 = false;
          demo = "DAY2 = OFF";
     //      Print_to_TFT(demo);
          delay(delayvalue);

        }
      }
      else if (description == "DAY3") {
        if (character == '1') {
          DAY3 = true;
          demo = "DAY3 = ON";
       //    Print_to_TFT(demo);
          delay(delayvalue);

        }
        else {
          DAY3 = false;
          demo = "DAY3 = OFF";
      //     Print_to_TFT(demo);
          delay(delayvalue);

        }
      }

      else if (description == "NEON1") {
        if (character == '1') {
          NEON1 = true;
          demo = "NEON1 = ON";
      //     Print_to_TFT(demo);
          delay(delayvalue);

        }
        else {
          NEON1 = false;
          demo = "NEON1 = OFF";
      //     Print_to_TFT(demo);
          delay(delayvalue);

        }
      }
      else if (description == "NEON2") {
        if (character == '1') {
          NEON2 = true;
          demo = "NEON2 = ON";
     //      Print_to_TFT(demo);
          delay(delayvalue);

        }
        else {
          NEON2 = false;
          demo = "NEON2 = OFF";
    //       Print_to_TFT(demo);
          delay(delayvalue);

        }
      }
      else if (description == "NEON3") {
        if (character == '1') {
          NEON3 = true;
          demo = "NEON3 = ON";
     //      Print_to_TFT(demo);
          delay(delayvalue);

        }
        else {
          NEON3 = false;
          demo = "NEON3 = OFF";
     //      Print_to_TFT(demo);
          delay(delayvalue);

        }
      }
      else if (description == "NIGHT1") {
        if (character == '1') {
          NIGHT1 = true;
          demo = "NIGHT1 = ON";
    //       Print_to_TFT(demo);
          delay(delayvalue);

        }
        else {
          NIGHT1 = false;
          demo = "NIGHT1 = OFF";
    //       Print_to_TFT(demo);
          delay(delayvalue);

        }
      }
      else if (description == "UV1") {
        if (character == '1') {
          UV1 = true;
          demo = "UV1 = ON";
   //        Print_to_TFT(demo);
          delay(delayvalue);

        }
        else {
          UV1 = false;
          demo = "UV1 = OFF";
     //      Print_to_TFT(demo);
          delay(delayvalue);

        }
      }
      else if (description == "UV2") {
        if (character == '1') {
          UV2 = true;
          demo = "UV2 = ON";
     //      Print_to_TFT(demo);
          delay(delayvalue);

        }
        else {
          UV2 = false;
          demo = "UV2 = OFF";
   //        Print_to_TFT(demo);
          delay(delayvalue);

        }
      }
      else if (description == "RGBDELAY") {
        value = "";
        do {
          value.concat(character);
          character = commandFile.read();
        }
        while (character != '\n');
        RGBDELAY = value;

      }
      else { // unknown parameter
        while (character != '\n')
          character = commandFile.read();
      }
      description = "";
    }
    else {
      // Ignore this character (could be space, tab, newline, carriage return or something else)
    }

  }
  // close the file:
  commandFile.close();
  
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Load_LED_DATA () {

  Serial.print("Loading Channel 1 to 4 RED PWM Values ....... ");
  commandFile = SD.open("LED1RED.TXT"); ////Loading LED1RED.TXT which is the desired RED color setting 0 - 255 of LED channel 1 RED
  if (commandFile)
  {
    while (commandFile.available())
    {
      Temporary_SD = commandFile.parseInt();
    }
    Serial.print("LED1RED.TXT, ");
    RED1 = Temporary_SD; // Store the value in the varieble
    commandFile.close(); // close the file when finished
  }
  else
  {
    Serial.println("Could not read LED1RED.TXT ");
    return;
  }
  commandFile = SD.open("LED2RED.TXT"); ////Loading LED2RED.TXT which is the desired RED color setting 0 - 255 of LED channel 1 RED
  if (commandFile)
  {
    while (commandFile.available())
    {
      Temporary_SD = commandFile.parseInt();
    }
    Serial.print("LED2RED.TXT, ");
    RED2 = Temporary_SD; // Store the value in the varieble
    commandFile.close(); // close the file when finished
  }
  else
  {
    Serial.println("Could not read LED2RED.TXT ");
    return;
  }

  commandFile = SD.open("LED3RED.TXT"); ////Loading LED3RED.TXT which is the desired RED color setting 0 - 255 of LED channel 1 RED
  if (commandFile)
  {
    while (commandFile.available())
    {
      Temporary_SD = commandFile.parseInt();
    }
    Serial.print("LED3RED.TXT, ");
    RED3 = Temporary_SD; // Store the value in the varieble
    commandFile.close(); // close the file when finished
  }
  else
  {
    Serial.println("Could not read LED3RED.TXT ");
    return;
  }

  commandFile = SD.open("LED4RED.TXT"); ////Loading LED4RED.TXT which is the desired RED color setting 0 - 255 of LED channel 1 RED
  if (commandFile)
  {
    while (commandFile.available())
    {
      Temporary_SD = commandFile.parseInt();
    }
    Serial.println("LED4RED.TXT, ");
    RED4 = Temporary_SD; // Store the value in the varieble
    commandFile.close(); // close the file when finished
  }
  else
  {
    Serial.println("Could not read LED4RED.TXT ");
    return;
  }

  Serial.print("Loading Channel 1 to 4 GREEN PWM Values ....... ");

  commandFile = SD.open("LED1GRE.TXT"); ////Loading LED1GRE.TXT which is the desired GREEN color setting 0 - 255 of LED channel 1 GRE
  if (commandFile)
  {
    while (commandFile.available())
    {
      Temporary_SD = commandFile.parseInt();
    }
    Serial.print("LED1GRE.TXT, ");
    GREEN1 = Temporary_SD; // Store the value in the varieble
    commandFile.close(); // close the file when finished
  }
  else
  {
    Serial.println("Could not read LED1GRE.TXT ");
    return;
  }
  commandFile = SD.open("LED2GRE.TXT"); ////Loading LED2GRE.TXT which is the desired GREEN color setting 0 - 255 of LED channel 1 GRE
  if (commandFile)
  {
    while (commandFile.available())
    {
      Temporary_SD = commandFile.parseInt();
    }
    Serial.print("LED2GRE.TXT, ");
    GREEN2 = Temporary_SD; // Store the value in the varieble
    commandFile.close(); // close the file when finished
  }
  else
  {
    Serial.println("Could not read LED2GRE.TXT ");
    return;
  }
  commandFile = SD.open("LED3GRE.TXT"); ////Loading LED3GRE.TXT which is the desired GREEN color setting 0 - 255 of LED channel 1 GRE
  if (commandFile)
  {
    while (commandFile.available())
    {
      Temporary_SD = commandFile.parseInt();
    }
    Serial.print("LED3GRE.TXT, ");
    GREEN3 = Temporary_SD; // Store the value in the varieble
    commandFile.close(); // close the file when finished
  }
  else
  {
    Serial.println("Could not read LED3GRE.TXT ");
    return;
  }
  commandFile = SD.open("LED4GRE.TXT"); ////Loading LED4GRE.TXT which is the desired GREEN color setting 0 - 255 of LED channel 1 GRE
  if (commandFile)
  {
    while (commandFile.available())
    {
      Temporary_SD = commandFile.parseInt();
    }
    Serial.println("LED4GRE.TXT, ");
    GREEN4 = Temporary_SD; // Store the value in the varieble
    commandFile.close(); // close the file when finished
  }
  else
  {
    Serial.println("Could not read LED4.TXT ");
    return;
  }

  Serial.print("Loading Channel 1 to 4 Blue PWM Values ....... ");

  commandFile = SD.open("LED1Blu.TXT"); ////Loading LED1Blu.TXT which is the desired Blue color setting 0 - 255 of LED channel 1 Blu
  if (commandFile)
  {
    while (commandFile.available())
    {
      Temporary_SD = commandFile.parseInt();
    }
    Serial.print("LED1Blu.TXT, ");
    BLUE1 = Temporary_SD; // Store the value in the varieble
    commandFile.close(); // close the file when finished
  }
  else
  {
    Serial.println("Could not read LED1Blu.TXT ");
    return;
  }
  commandFile = SD.open("LED2Blu.TXT"); ////Loading LED2Blu.TXT which is the desired Blue color setting 0 - 255 of LED channel 1 Blu
  if (commandFile)
  {
    while (commandFile.available())
    {
      Temporary_SD = commandFile.parseInt();
    }
    Serial.print("LED2Blu.TXT, ");
    BLUE2 = Temporary_SD; // Store the value in the varieble
    commandFile.close(); // close the file when finished
  }
  else
  {
    Serial.println("Could not read LED2Blu.TXT ");
    return;
  }
  commandFile = SD.open("LED3Blu.TXT"); ////Loading LED3Blu.TXT which is the desired Blue color setting 0 - 255 of LED channel 1 Blu
  if (commandFile)
  {
    while (commandFile.available())
    {
      Temporary_SD = commandFile.parseInt();
    }
    Serial.print("LED3Blu.TXT, ");
    BLUE3 = Temporary_SD; // Store the value in the varieble
    commandFile.close(); // close the file when finished
  }
  else
  {
    Serial.println("Could not read LED3Blu.TXT ");
    return;
  }
  commandFile = SD.open("LED4Blu.TXT"); ////Loading LED4Blu.TXT which is the desired Blue color setting 0 - 255 of LED channel 1 Blu
  if (commandFile)
  {
    while (commandFile.available())
    {
      Temporary_SD = commandFile.parseInt();
    }
    Serial.println("LED4Blu.TXT, ");
    BLUE4 = Temporary_SD; // Store the value in the varieble
    commandFile.close(); // close the file when finished
  }
  else
  {
    Serial.println("Could not read LED4.TXT ");
    return;
  }
  delay(200);

  // EEPROM.write(500, RED1);  // write eeprom address 50 with chga value
  // EEPROM.write(503, RED2);  // write eeprom address 50 with chga value
  // EEPROM.write(506, RED3);  // write eeprom address 50 with chga value
  // EEPROM.write(509, RED4);  // write eeprom address 50 with chga value

  // EEPROM.write(501, GREEN1);  // write eeprom address 50 with chga value
  //  EEPROM.write(504, GREEN2);  // write eeprom address 50 with chga value
  //  EEPROM.write(507, GREEN3);  // write eeprom address 50 with chga value
  //  EEPROM.write(510, GREEN4);  // write eeprom address 50 with chga value

  //  EEPROM.write(502, BLUE1);  // write eeprom address 50 with chga value
  //  EEPROM.write(505, BLUE2);  // write eeprom address 50 with chga value
  //  EEPROM.write(508, BLUE3);  // write eeprom address 50 with chga value
  //  EEPROM.write(511, BLUE4);  // write eeprom address 50 with chga value


  Serial.println(" PWN DATA STORED TO EEPROM is not active  ");

}

*/
