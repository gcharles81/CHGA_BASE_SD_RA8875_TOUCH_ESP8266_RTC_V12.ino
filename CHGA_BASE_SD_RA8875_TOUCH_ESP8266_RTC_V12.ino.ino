
// include the SD library:
#include "keypad.h"
#include <SPI.h>
#include <SD.h>

#include <RA8875.h>
//#include <Wire.h>

#include "Temporary_timers.h"

#include <FT5206.h>


////////////ONBOARD SD CARD//////CHGA
int Temporary_SD = 0;
const int chipSelect = BUILTIN_SDCARD;
//////////////////////////////////////////////////////////////////////////////////
#include <TimeLib.h>

////////////LEDS//////CHGA

#define LEDT 13   //Teensy-LED
#define LED1 45   //red
#define LED2 46   //orange
#define LED3 47   //green

//////////////////////////////////////////////////////////////////////////////////
////////////RA8875//////CHGA
#define BUFFPIXEL 30
#define RA8875_MISO 12
#define RA8875_MOSI 7
#define RA8875_SCK 14
#define RA8875_INT 22
#define RA8875_CS 15
#define RA8875_RESET 23//any pin or nothing!
#define MAXTOUCHLIMIT 1//1...5
#define CTP_INT           22    // touch data ready for read from FT5206 touch controller

uint8_t registers[FT5206_REGISTERS];
uint16_t new_coordinates[5][2];
uint16_t old_coordinates[5][2];
uint8_t current_touches = 0;
uint8_t old_touches = 0;

RA8875 tft = RA8875(RA8875_CS, RA8875_RESET, RA8875_MOSI, RA8875_SCK, RA8875_MISO);
FT5206 cts = FT5206(CTP_INT);
long Flash_image_Start_address  = 0;
short Flash_image_width = 0;
short Flash_image_height = 0;
File     bmpFile;
Sd2Card card;
SdVolume volume;
SdFile root;
File commandFile;
//File     bmpFile;



boolean btn_continous_press = false;

unsigned long currentMillis = 0;
long previousMillis = 0;        // will store last time LED was updated

// the follow variables is a long because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long interval = 2000;           // interval at which to blink (milliseconds)
///////////////////////////////////////////////////////////////////////////////////
//*********************MENUS RELATED********************************************///
int MENU_NR = 0;
int Menu_item = 0;

boolean Valid_button_menu_touch = false;////new chaga
boolean SCREEN_UPDATE = true;//////just for X_COL_2
boolean SUB_SCREEN_UPDATE = false;//////just for X_COL_2
int Settings_Menu_button_number = 0;
int i = 0;
///////////////////////////////////////////////////////////////////////////////////
//////////////////TOUCH CAPACITIVE////////////////////////////////////////////////////////////
boolean valid_touch = false;
boolean DO_I_NEED_TOUCH = false;
int Temp_TOUCH_X_VAL = 0;
int Temp_TOUCH_Y_VAL = 0;
int Temp_touch_FINGER = 0;
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////VIRTUAL KEYPAD RELATED///////////////////////////////////////
int KPD_Button_SIZE_X = 80; // 80x80 pixels
int KPD_Button_SIZE_Y = 50; // 80x80 pixels
int KPD_Button_PITCH_X = 90; // pitch between buttons 100 pixels
int KPD_Button_PITCH_Y = 60; // pitch between buttons 100 pixels
float KPD_Back_color = RA8875_RED;
float KPD_Button_color_touched = RA8875_WHITE;
float KPD_Button_color = RA8875_RED;
float KPD_TEXT_color = RA8875_BLACK;
boolean KEYPAD_UPDATE = false;//////just for X_COL_2
int KEYPAD_XPOS_VAL = 10;
int KEYPAD_YPOS_VAL = 10;
///////////////////////////////////////////////////////////////////////////////////


#include "All_75_Pic_65K.h"
#include "Buttons_handler_CHGA.h"

#include "RGB_settings_menu.h"
#include "CHGA_Keypad.h"
#include "Test_Menu.h"
#include "TESTING_EEPROM_HANDLER.h"

#include "Lable_handler_CHGA.h"

////////////ESP8266//////CHGA

#define WLAN_SERIAL     Serial1
#define WLAN_SERIAL_BAUD_INIT 74880
#define WLAN_SERIAL_BAUD 115200
#define WLAN_RESET      24
#define WLAN_ENABLE     16  //CH_PD
#define WLAN_CTS        20  //GPIO15
#define WLAN_RTS        2   //GPIO13
#define WLAN_GPIO0      51   //
#define WLAN_GPIO13     WLAN_RTS
#define WLAN_GPIO15     WLAN_CTS




#define HAVE_ESP12E   1 // 0= not available / 1=available


#define BUFFER_SIZE 1024

#define SSID  "Marsaxlokk"      // change this to match your WiFi SSID
#define PASS  "Liam@3004"  // change this to match your WiFi password
#define PORT  "123"
#define NTPSERVER  "192.168.1.4"
const int timeZone = -4;  // Eastern DST (USA)

#define BUFFER_SIZE 1024
///////////////////////////////////////////////////////////////////////////////////
char buffer[BUFFER_SIZE], query[48];

byte binfind(char *str) {
  unsigned long t = millis();
  bool found = false;
  int i = 0, j = 0, len = strlen(str);
  char c;
  while (millis() < t + 5000) {
    if (Serial1.available()) {
      c = Serial1.read();
      if (c == str[i]) {
        i++;
        if (i == len) return true;
      } else i = 0;
    }
  }
  return found;
}


// By default we are looking for OK\r\n
char OKrn[] = "OK\r\n";

byte wait_for_esp_response(int timeout, char* term = OKrn) {
  unsigned long t = millis();
  bool found = false;
  int i = 0;
  int len = strlen(term);
  // wait for at most timeout milliseconds
  // or if OK\r\n is found
  while (millis() < t + timeout) {
    if (Serial1.available()) {
      buffer[i++] = Serial1.read();
      if (i >= len) {
        if (strncmp(buffer + i - len, term, len) == 0) {
          found = true;
          break;
        }
      }
    }
  }
  buffer[i] = 0;
  Serial.print(buffer);
  return found;
}
bool resetWLAN() {
#if HAVE_ESP12E

  Serial.println("INIT ESP12E");

  WLAN_SERIAL.begin(WLAN_SERIAL_BAUD);

  pinMode(WLAN_RESET, OUTPUT);
  pinMode(WLAN_ENABLE, OUTPUT);
  pinMode(WLAN_CTS, OUTPUT);
  pinMode(WLAN_GPIO0, OUTPUT);

  digitalWrite(WLAN_CTS, LOW);
  digitalWrite(WLAN_ENABLE, LOW);

  //Reset ESP
  digitalWrite(WLAN_RESET, LOW);
  delay(15);
  digitalWrite(WLAN_ENABLE, HIGH);
  digitalWrite(WLAN_RESET, HIGH);

  //The ESP - Bootloader waits for  HIGH on WLAN_GPIO0
  digitalWrite(WLAN_GPIO0, HIGH);

  bool ret = WLAN_SERIAL.findUntil("ready", "");

  //GPIO0 ist not needed anymore:
  pinMode(WLAN_GPIO0, INPUT);

  //Disable all used pins if no response from ESP
  if (!ret) {
    pinMode(WLAN_RESET, INPUT);
    pinMode(WLAN_ENABLE, INPUT);
    pinMode(WLAN_CTS, INPUT);
  }

  return ret;
#endif


}

/////////////////////
void setupWiFi() {

  // turn on echo
  Serial1.println("ATE1");
  wait_for_esp_response(1000);

  // set mode 1 (client)
  Serial1.println("AT+CWMODE=3");
  wait_for_esp_response(1000);

  // reset WiFi module
  Serial1.print("AT+RST\r\n");
  wait_for_esp_response(1500);

  //join AP
  Serial1.print("AT+CWJAP=\"");
  Serial1.print(SSID);
  Serial1.print("\",\"");
  Serial1.print(PASS);
  Serial1.println("\"");
  wait_for_esp_response(5000);

  //Create UDP ports
  Serial1.println("AT+CIPMUX=1");
  wait_for_esp_response(1000);

  String cmd = "AT+CIPSTART=4,\"UDP\",\"";
  cmd += NTPSERVER;
  cmd += "\",";
  cmd += PORT;
  cmd += ",4321,0";
  Serial1.println(cmd);
  wait_for_esp_response(1000);

  query[0] = 0x1B;    // NTP request
  Serial.println("UDP ready");
}
void setup()
{


  pinMode(LEDT, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  // Wire1.begin();
  digitalWrite(LED3, HIGH);   // turn the LED on (HIGH is the voltage level)



  Serial.begin(9600);

  // set the Time library to use Teensy 3.0's RTC to keep time
  setSyncProvider(getTeensy3Time);
  if (timeStatus() != timeSet) {
    Serial.println("Unable to sync with the RTC");
  } else {
    Serial.println("RTC has set the system time");
  }
  delay(200); // Give RTC some time

  Serial.print("\nInitializing SD card...");


  // we'll use the initialization code from the utility libraries
  // since we're just X_COL_2ing if the card is working!
  if (!card.init(SPI_HALF_SPEED, chipSelect)) {
    Serial.println("initialization failed. Things to check:");
    Serial.println("* is a card inserted?");
    Serial.println("* is your wiring correct?");
    Serial.println("* did you change the chipSelect pin to match your shield or module?");
    return;
  } else {
    Serial.println("Wiring is correct and a card is present.");
  }

  // print the type of card
  Serial.print("\nCard type: ");
  switch (card.type()) {
    case SD_CARD_TYPE_SD1:
      Serial.println("SD1");
      break;
    case SD_CARD_TYPE_SD2:
      Serial.println("SD2");
      break;
    case SD_CARD_TYPE_SDHC:
      Serial.println("SDHC");
      break;
    default:
      Serial.println("Unknown");
  }

  // Now we will try to open the 'volume'/'partition' - it should be FAT16 or FAT32
  if (!volume.init(card)) {
    Serial.println("Could not find FAT16/FAT32 partition.\nMake sure you've formatted the card");
    return;
  }


  // print the type and size of the first FAT-type volume
  uint32_t volumesize;
  Serial.print("\nVolume type is FAT");
  Serial.println(volume.fatType(), DEC);
  Serial.println();

  volumesize = volume.blocksPerCluster();    // clusters are collections of blocks
  volumesize *= volume.clusterCount();       // we'll have a lot of clusters
  if (volumesize < 8388608ul) {
    Serial.print("Volume size (bytes): ");
    Serial.println(volumesize * 512);        // SD card blocks are always 512 bytes
  }
  Serial.print("Volume size (Kbytes): ");
  volumesize /= 2;
  Serial.println(volumesize);
  Serial.print("Volume size (Mbytes): ");
  volumesize /= 1024;
  Serial.println(volumesize);


  Serial.println("\nFiles found on the card (name, date and size in bytes): ");
  root.openRoot(volume);

  // list all files in the card with date and size
  root.ls(LS_R | LS_DATE | LS_SIZE);


  /*
    if ( !resetWLAN() ) {
      Serial.println("ESP-12e not found!!!!");
      while (1);
    }

  */

  digitalWrite(LEDT, HIGH);

  delay(1500);
  Serial.println("TFT begin");
  tft.begin(RA8875_800x480);
  delay(1000);

  tft.fillWindow(RA8875_BLACK);//RA8875_LIGHT_GREY// tft.fillScreen(RA8875_BLACK);
  delay(100);
  // PROGRESS_BAR_CHGAB(400,50);
  // TFT_MENU_RGB_01(true,0);

  cts.begin();



  //tft.setRotation(2);//this works in any rotation mode! 0,1,2,3
  delay(100);

  /// CHGA_BCD(); FONT X_COL_2
  //  tft.setFont(&orbitron_16);//USE THIS FONT
  //tft.DMA_enable();
  Serial.println("Displaying Logo");
  // bmpDraw("alert.bmp", 0, 0);//copy the enclosed image in a SD card (check the folder!!!)
  //  tft.drawFlashImage(10,10,132,132,896724);
  delay(500);
  Serial1.println("AT+CIFSR");
  wait_for_esp_response(1000);


}


void loop(void) {
  unsigned long currentMillis = millis();

  if (cts.touched()) { //if touched(true) detach isr
    digitalWrite(LED2, HIGH);   // turn the LED on (HIGH is the voltage level)
    GET_TOUCH_XY_VALUE ();
    delay(150);
    RESET_Temp_touch_values ();
   // delay(100);
    //cts.touched(false);
  }

  // wait for a second

  digitalWrite(LED2, LOW);    // turn the LED off by making the voltage LOW

  if (SCREEN_UPDATE == true) {


    switch (MENU_NR) {
      case 0:    // your hand is on the sensor
        Serial.println("TFT MENU 0 Needs update");
        TFT_MAIN_PANEL();
        break;
      case 1:    // your hand is close to the sensor
        Serial.println("ENTER TFT MENU SETTINGS");
        TFT_MENU_SETTINGS();
        break;
      case 2:    // your hand is a few inches from the sensor
        Serial.println("ENTER TFT LED SETTINGS");
       // TFT_MENU_LED();
        break;
      case 3:    // your hand is nowhere near the sensor
        Serial.println("ENTER TFT RGB CONFCH 1 ");
        TFT_MENU_RGB_01(true, 0,MENU_NR);
        break;
      case 4:    // your hand is a few inches from the sensor
		  Serial.println("ENTER TFT RGB CONFCH 2 ");
		  TFT_MENU_RGB_01(true, 0, MENU_NR);
        break;
      case 5:    // your hand is nowhere near the sensor
		  Serial.println("ENTER TFT RGB CONFCH 3 ");
		  TFT_MENU_RGB_01(true, 0, MENU_NR);
        break;
      case 6:    // your hand is nowhere near the sensor
		  Serial.println("ENTER TFT RGB CONFCH 4 ");
		  TFT_MENU_RGB_01(true, 0, MENU_NR);
        break;
      case 7:    // your hand is nowhere near the sensor

        Serial.println("ENTER TFT MENU ABOUT");
		update_label_values_from_int();

     TFT_MENU_ABOUT(true, 0, MENU_NR);
        //  Numeric_Keypad_TFT(100, 10);


        break;

	  case 8:    // your hand is nowhere near the sensor

		  Serial.println("ENTER TFT MENU ABOUT");
		  TFT_MENU_ABOUT(true, 0, MENU_NR);
		  //  Numeric_Keypad_TFT(100, 10);
		  break;
    }

	
  }

 
}



