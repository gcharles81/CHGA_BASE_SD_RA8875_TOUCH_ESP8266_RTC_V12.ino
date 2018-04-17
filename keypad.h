// keypad.h

#ifndef _KEYPAD_h
#define _KEYPAD_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class KeypadClass
{
 protected:


 public:
	void init();
};

extern KeypadClass Keypad;

#endif

