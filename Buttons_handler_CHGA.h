
//#pragma once

//-Button_handler 
int Button_hold_delay = 50;




void create_btn(int tff[4]){
	int PIC_NUM = 0;
	PIC_NUM =tff[2];


	tft.dispicown(tff[0], tff[1], B_INFO[PIC_NUM].img_width, B_INFO[PIC_NUM].img_height, B_INFO[PIC_NUM].start_addr);

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
