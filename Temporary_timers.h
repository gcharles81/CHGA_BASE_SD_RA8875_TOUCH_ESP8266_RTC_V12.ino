#pragma once

///this file is only a temporary basis one please remove later once timer handler is implimented with proper structures 



String RGBDELAY;
///////////////////////////////////////////////////////////////////////////////////

int SUNRISECYCLE = 0;
int COUNTFADEIN = 1;
int FADEVALUE = 0;
int COUNTFADEOUT = 1;
int FADEOUTVALUE = 0;
int SUNRISEOFFFLAG = false;
////////
float LEDOUTPUTSON = false;
float LEDOUTPUTSOFF = false;
//////////
int SUNSETCYCLE = 0;
int COUNTFADEIN2 = 1;
int FADEVALUE2 = 0;
int FADEVALUE3 = 0;
int FADEVALUE4 = 0;
int FADEVALUE5 = 0;
int FADEVALUE6 = 0;
int FADEVALUE7 = 0;
int COUNTFADEOUT2 = 1;
int FADEOUTVALUE2 = 0;
int SUNSETOFFFLAG = false;






int MINUTECOUNTER = 0;
int BASSAKOLLOK = 0;


int RED1 = 255; ///Read stored light Value
int GREEN1 = 25;  ///Read stored light Value
int BLUE1 = 50; ///Read stored light Value

int RED2 = 0; ///Read stored light Value
int GREEN2 = 0; ///Read stored light Value
int BLUE2 = 0; ///Read stored light Value

int RED3 = 0; ///Read stored light Value
int GREEN3 = 0; ///Read stored light Value
int BLUE3 = 0; ///Read stored light Value

int RED4 = 0; ///Read stored light Value
int GREEN4 = 0; ///Read stored light Value
int BLUE4 = 0; ///Read stored light Value
			   ///////////////////////////////////////DAY
int PREVIOUSMIN = 0;
int PREVIOUSMIN2 = 0;
int PREVIOUSHOUR = 0;

int CURRENTHOUR = 0;
int CURRENTMIN = 0;
int CURRENTSEC = 0;
int CURRENTDAY = 0;
int CURRENTMONTH = 0;
int CURRENTYEAR = 0;
int LASTMIN = 0;
int LASTSEC = 0;
boolean SEC_PASSED = false;

boolean MIN_PASSED = false;

boolean STARTRTC = false;
////
//////////////////////////////////////////////////////////////////////////////////////////////
//******************************************************************************///
float Current1 = 1.98;
float Current2 = 2.48;
float Current3 = 1.33;
float Current4 = 0.96;
boolean MANUAL_LED_Override = false;
boolean MANUAL_CH1_Override = false;
boolean MANUAL_CH2_Override = false;
boolean MANUAL_CH3_Override = false;
boolean MANUAL_CH4_Override = false;
///////////////////////////////////////////////////////////////////////////////////
