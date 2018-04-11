void LOOPING_ALL_PICS_IN_FLASH(){


Serial.println("V");

 for (int i = 0; i < 54; i++) {

Flash_image_Start_address = B_INFO[i].start_addr;
Flash_image_width = B_INFO[i].img_width;  
Flash_image_height = B_INFO[i].img_height;  

tft.dispicown(50,200,Flash_image_width,Flash_image_height,Flash_image_Start_address);/////ZZB1.bmp  55  55  16bpp mode (RGB 5:6:5)  6050  134480




Serial.println(Flash_image_Start_address);
Serial.println(Flash_image_width);
Serial.println(Flash_image_height);
 
 Delay_KL();
 
 
 }
 tft.setActiveWindow();
 delay(200);
  tft.fillWindow(RA8875_BLACK);//RA8875_LIGHT_GREY// tft.fillScreen(RA8875_BLACK);
delay(1000);

}

void Delay_KL(){
  
  delay(200);
}

/*
void Show_Pic_In_Flash_Name(int XX , int YY ,char* Name   ){


int i = B_INFO[Name].number;

tft.dispicown(XX,YY,B_INFO[i].img_width,B_INFO[i].img_height,B_INFO[i].start_addr);
 
Delay_KL();
 
 }
*/
void Show_Pic_In_Flash_Number(int XX , int YY , int number ){


tft.dispicown(XX,YY,B_INFO[number].img_width,B_INFO[number].img_height,B_INFO[number].start_addr);
 
Delay_KL();
 
 }

 void PROGRESS_BAR_CHGA(int mxs){
//tft.setActiveWindow();

int testX = 11;
int start_G = 9;
int BVC = mxs;

Flash_image_width = B_INFO[16].img_width;  
Flash_image_height = B_INFO[16].img_height;
//tft.fillRect(0,100,800,80,RA8875_BLACK); 
//tft.fillRect(2,101,796,78,RA8875_LIGHT_GREY);



for (int i = 0; i < 71; i++) {

 

Flash_image_Start_address = B_INFO[16].start_addr;
tft.dispicown(start_G,100,Flash_image_width,Flash_image_height,Flash_image_Start_address);/////ZZB1.bmp  55  55  16bpp mode (RGB 5:6:5)  6050  134480

Flash_image_Start_address = B_INFO[17].start_addr;
tft.dispicown(start_G,200,Flash_image_width,Flash_image_height,Flash_image_Start_address);/////ZZB1.bmp  55  55  16bpp mode (RGB 5:6:5)  6050  134480

Flash_image_Start_address = B_INFO[18].start_addr;
tft.dispicown(start_G,300,Flash_image_width,Flash_image_height,Flash_image_Start_address);/////ZZB1.bmp  55  55  16bpp mode (RGB 5:6:5)  6050  134480
Flash_image_Start_address = B_INFO[19].start_addr;
tft.dispicown(start_G,380,Flash_image_width,Flash_image_height,Flash_image_Start_address);/////ZZB1.bmp  55  55  16bpp mode (RGB 5:6:5)  6050  134480
start_G = start_G + testX;

Delay_PROGRESS(BVC);
 
 
 }

  tft.setActiveWindow();
 delay(200);
  tft.fillWindow(RA8875_BLACK);//RA8875_LIGHT_GREY// tft.fillScreen(RA8875_BLACK);
delay(1000);
 }
 
 void Delay_PROGRESS(int valueh){
 delay(valueh);
 }

 

void PROGRESS_BAR_CHGAB( int STARTY, int rec_value ){

//  tft.textMode();

//    tft.textSetCursor(STARTY - 10 , 10);
  
  /* Render some text! */
//  tft.textEnlarge(1);

 // tft.textColor(RA8875_WHITE, RA8875_BLACK);

  
//tft.print ("LOADING........");

//tft.graphicsMode();

Flash_image_width = B_INFO[16].img_width;  
Flash_image_height = B_INFO[16].img_height;

int Index_X_pitch = 22;
int X_start_position = 10; /// indexed during fill 
int delay_value = rec_value; // not inuse
int Number_of_seq = 30;//((tft.width() - 20) / (Flash_image_width -1) );
int X_SIZE_BAR = Number_of_seq * Index_X_pitch + 4;

Flash_image_width = B_INFO[16].img_width;  
Flash_image_height = B_INFO[16].img_height;


tft.fillRect(X_start_position - 2,STARTY -3,X_SIZE_BAR,Flash_image_height + 5,RA8875_LIGHT_GREY); 
X_SIZE_BAR = X_SIZE_BAR -2;

tft.fillRect(X_start_position - 1,STARTY -2,X_SIZE_BAR,Flash_image_height + 3,RA8875_BLACK); 

for (int i = 0; i < Number_of_seq; i++) {

 

Flash_image_Start_address = B_INFO[16].start_addr;
tft.dispicown(X_start_position,STARTY,Flash_image_width,Flash_image_height,Flash_image_Start_address);/////ZZB1.bmp  55  55  16bpp mode (RGB 5:6:5)  6050  134480


X_start_position = X_start_position + Index_X_pitch;

Delay_PROGRESS(delay_value);
 
} 
  tft.setActiveWindow();
 delay(200);
tft.fillWindow(RA8875_BLACK);//RA8875_LIGHT_GREY// tft.fillScreen(RA8875_BLACK);
delay(1000);
 }
