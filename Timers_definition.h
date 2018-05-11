#pragma once
#include <TimerHandler.h>


TimerHandler mytimer_check = TimerHandler();

// Timers name definition  

Timer Sunrise = { 0, 0, 0 ,0 ,0 ,false };//use the TimerHandler library structure
Timer Sunset  = { 0, 0, 0 ,0 ,0 ,false };//use the TimerHandler library structure
Timer Day1    = { 0, 0, 0 ,0 ,0 ,false };//use the TimerHandler library structure
Timer Day2    = { 0, 0, 0 ,0 ,0 ,false };//use the TimerHandler library structure
Timer Day3    = { 0, 0, 0 ,0 ,0 ,false };//use the TimerHandler library structure
Timer Neon1   = { 0, 0, 0 ,0 ,0 ,false };//use the TimerHandler library structure
Timer Neon2   = { 0, 0, 0 ,0 ,0 ,false };//use the TimerHandler library structure
Timer Neon3   = { 0, 0, 0 ,0 ,0 ,false };//use the TimerHandler library structure
Timer Night1  = { 0, 0, 0 ,0 ,0 ,false };//use the TimerHandler library structure
Timer Night2  = { 0, 0, 0 ,0 ,0 ,false };//use the TimerHandler library structure
Timer Uv1     = { 0, 0, 0 ,0 ,0 ,false };//use the TimerHandler library structure
Timer Uv2     = { 0, 0, 0 ,0 ,0 ,false };//use the TimerHandler library structure

//


int g = Sunrise.Hour_On;
int H = Sunrise.Hour_Off;

void Test_bncd() {
	
	
	if (mytimer_check.Timer_ON(1, Sunrise)) {

		Serial.println("ON");

	}

	else {

		Serial.println("OFF");
	}
}