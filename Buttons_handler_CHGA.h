
//#pragma once
//-Button_handler - V 0.5 - pre release still lots of test ongoing **** 

// Copyright Charles Galea  - email charles.galea@gmail.com

// address 2 contains the button image stared in flash 
// address 3 contains the button pressed image stared in flash 



int Button_hold_delay = 50;





void create_btn(int tff[4]){       // creates a button with icon picture the button would be the size of the pic 

	int PIC_NUM = 0;
	
	PIC_NUM =tff[2];
	
	tft.dispicown(tff[0], tff[1], B_INFO[PIC_NUM].img_width, B_INFO[PIC_NUM].img_height, B_INFO[PIC_NUM].start_addr);

}

void Update_btn_press(int tff[4]) {

	int PIC_NUM = 0;

	PIC_NUM = tff[3]; /// address 3 contains the pressed image stared in flash 

	tft.drawRoundRect(tff[0] - 3, tff[1] - 3, B_INFO[PIC_NUM].img_width + 6, B_INFO[PIC_NUM].img_height + 6,6, RA8875_YELLOW);
	tft.drawRoundRect(tff[0] - 2, tff[1] - 2, B_INFO[PIC_NUM].img_width + 4, B_INFO[PIC_NUM].img_height + 4,6, RA8875_LIGHT_GREY);
	tft.drawRoundRect(tff[0] - 1, tff[1] - 1, B_INFO[PIC_NUM].img_width + 2, B_INFO[PIC_NUM].img_height + 2,6, RA8875_LIGHT_GREY);
	delay(Button_hold_delay);

	tft.drawRoundRect(tff[0] - 3, tff[1] - 3, B_INFO[PIC_NUM].img_width + 6, B_INFO[PIC_NUM].img_height + 6, 6, RA8875_BLACK);
	tft.drawRoundRect(tff[0] - 2, tff[1] - 2, B_INFO[PIC_NUM].img_width + 4, B_INFO[PIC_NUM].img_height + 4, 6, RA8875_BLACK);
	tft.drawRoundRect(tff[0] - 1, tff[1] - 1, B_INFO[PIC_NUM].img_width + 2, B_INFO[PIC_NUM].img_height + 2, 6, RA8875_BLACK);
		
}
bool Touch_inRange(int X_val, int Y_val, int Button_name[4])

{

	int X_min = Button_name[0];
	int Y_min = Button_name[1];
	int X_max = (Button_name[0] + B_INFO[Button_name[2]].img_width);
	int Y_max = (Button_name[1] + B_INFO[Button_name[2]].img_height);

	return ((X_val > X_min) && (X_val < X_max) && (Y_val > Y_min) && (Y_val < Y_max));

}