
//#pragma once

//-Button_handler 
int Button_hold_delay = 50;

bool Touch_inRange(int X_val,int Y_val,int Button_name[4])
  
  {

int X_min = Button_name[0];
int Y_min = Button_name[1];
int X_max = (Button_name[0] + B_INFO[Button_name[2]].img_width);
int Y_max = (Button_name[1] + B_INFO[Button_name[2]].img_height);


  return ((X_min <= X_val) && (X_val <= X_max)&& (Y_val <= Y_max)&& (Y_val <= Y_max));

  }


void create_btn(int tff[4]){
	int PIC_NUM = 0;
	PIC_NUM =tff[2];

	/*

	int16_t x7, y7;
	tft.getCursor0(x7, y7);
	delay(10);
	
	int16_t x1, y1, x2, y2;
	tft.getActiveWindow(x1, x2, y1, y2);
	delay(10);

	

		Serial.print("Cursor position X - 7  ");
		Serial.println(x7);

		Serial.print("Cursor position Y - 7 ");
		Serial.println(y7);
*/
	



	tft.dispicown(tff[0], tff[1], B_INFO[PIC_NUM].img_width, B_INFO[PIC_NUM].img_height, B_INFO[PIC_NUM].start_addr);
	/*

	delay(10);
	tft.setCursor(x7, y7);
	delay(10);
	tft.setActiveWindow(x1, x2, y1, y2);
	*/
}

void Update_btn_press(int tff[4]) {
	int PIC_NUM = 0;

	PIC_NUM = tff[3]; /// address 3 contains the pressed image stared in flash 
/*
	tft.drawRect(tff[0] - 3, tff[1] - 3, B_INFO[PIC_NUM].img_width + 6, B_INFO[PIC_NUM].img_height + 6, RA8875_LIGHT_GREY);
	tft.drawRect(tff[0] - 2, tff[1] - 2, B_INFO[PIC_NUM].img_width + 4, B_INFO[PIC_NUM].img_height + 4, RA8875_LIGHT_GREY);
	tft.drawRect(tff[0] - 1, tff[1] - 1, B_INFO[PIC_NUM].img_width + 2, B_INFO[PIC_NUM].img_height + 2, RA8875_LIGHT_GREY);
*/
	tft.drawRoundRect(tff[0] - 3, tff[1] - 3, B_INFO[PIC_NUM].img_width + 6, B_INFO[PIC_NUM].img_height + 6,6, RA8875_YELLOW);
	tft.drawRoundRect(tff[0] - 2, tff[1] - 2, B_INFO[PIC_NUM].img_width + 4, B_INFO[PIC_NUM].img_height + 4,6, RA8875_LIGHT_GREY);
	tft.drawRoundRect(tff[0] - 1, tff[1] - 1, B_INFO[PIC_NUM].img_width + 2, B_INFO[PIC_NUM].img_height + 2,6, RA8875_LIGHT_GREY);
	delay(Button_hold_delay);

	tft.drawRoundRect(tff[0] - 3, tff[1] - 3, B_INFO[PIC_NUM].img_width + 6, B_INFO[PIC_NUM].img_height + 6, 6, RA8875_BLACK);
	tft.drawRoundRect(tff[0] - 2, tff[1] - 2, B_INFO[PIC_NUM].img_width + 4, B_INFO[PIC_NUM].img_height + 4, 6, RA8875_BLACK);
	tft.drawRoundRect(tff[0] - 1, tff[1] - 1, B_INFO[PIC_NUM].img_width + 2, B_INFO[PIC_NUM].img_height + 2, 6, RA8875_BLACK);
	

	
}
