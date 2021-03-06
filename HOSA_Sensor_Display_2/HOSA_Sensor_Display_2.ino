#include <Adafruit_GFX.h>    
#include <Adafruit_TFTLCD.h>

#define LCD_CS A3 
#define LCD_CD A2 
#define LCD_WR A1 
#define LCD_RD A0 
#define LCD_RESET A4 

#define BLACK   0x0000
#define BLUE    0x001F
#define BLUE2   0x051F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

int loopNumber = 0; 


void setup() {

  //Serial.begin(9600);
  tft.reset();
  tft.begin(0x9481);
  tft.setRotation(1);
  tft.fillScreen(GREEN);
  tft.fillScreen(BLUE);
  tft.fillScreen(BLUE2);
  delay(100);

  //first number is for horizontal adjustmemt, while second is vertical adjustment
  tft.setCursor(75,65);
  tft.setTextColor(BLUE);
  tft.setTextSize(5);
  tft.print("FLASH HEART");

  tft.setCursor(110,125);
  tft.setTextColor(BLACK);
  tft.setTextSize(4);
  tft.print("Risk Level: ");

}
void reset() {
  loopNumber = 0; 
}

void loop() 
{
  unsigned int analogValue;
  String displayVal = String(200);
  String S_Rest = String(16); 
  String S_Danger = String(16);
  String S_Precaution = String(16);
  String S_Normal = String(16);
  String S_EmergencyCare = String(16);
  String S_PrecautionCare = String(16);
  String S_Initial = String(16); 
  String S_PostInitial = String(16);
  String S_Final = String(16);
  S_Rest = "Insert Blood Sample "; 
  S_Normal = "Normal: "; 
  S_Precaution = "Precaution: ";
  S_Danger = "Danger: ";
  S_EmergencyCare = "Dialing 911...";
  S_PrecautionCare = "Consult Doctor";  
   S_Initial = "Detected Sample "; 
  S_PostInitial = "Analyzing Blood... "; 
  S_Final = "Results are: "; 
  analogValue = analogRead(0);
  tft.fillRect(80,200,321,60,BLACK);
  tft.fillRect(80,200,321,60,BLUE);
  tft.setCursor(135,215);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  
  if (analogValue < 710) {
          tft.setCursor(120,220);
          tft.setTextColor(WHITE);
          tft.setTextSize(2.5);
          displayVal = S_Rest;
          loopNumber = 0; 
          
  }else if ((analogValue < 850)){
    if(loopNumber == 0) {
      tft.setCursor(115,220);
      tft.setTextColor(WHITE);
      tft.setTextSize(2);
      displayVal = S_Initial;
      delay(500);
      loopNumber = 1;  
      
    }else if(loopNumber == 1) {
      tft.setCursor(115,220);
      tft.setTextColor(WHITE);
      tft.setTextSize(2);
      displayVal = S_PostInitial;
        delay(500);
      loopNumber = 2;  
      
    }
    else if(loopNumber == 2) {
      tft.setCursor(115,220);
      tft.setTextColor(WHITE);
      tft.setTextSize(2);
      displayVal = S_Final;
        delay(500);
      loopNumber = 3; 
    }
    else if(loopNumber == 3) {
          displayVal = S_Normal +analogValue ;//+ " " + "Normal";
    }
          
  }else if (analogValue < 920 ){
    
    if(loopNumber == 0) {
      tft.setCursor(115,220);
      tft.setTextColor(WHITE);
      tft.setTextSize(2);
      displayVal = S_Initial;
      delay(500);
      loopNumber = 1;  
      
    }else if(loopNumber == 1) {
      tft.setCursor(115,220);
      tft.setTextColor(WHITE);
      tft.setTextSize(2);
      displayVal = S_PostInitial;
        delay(500);
      loopNumber = 2;  
      
    }else if(loopNumber == 2) {
      tft.setCursor(115,220);
      tft.setTextColor(WHITE);
      tft.setTextSize(2);
      displayVal = S_Final;
        delay(500);
      loopNumber = 3; 
    }else if(loopNumber == 3) {
      tft.setCursor(110,220);
      tft.setTextColor(WHITE);
      tft.setTextSize(3);
      displayVal = S_Precaution + analogValue;// + " " + "Precaution";
    }
    }else {
   if(loopNumber == 0) {
      tft.setCursor(115,220);
      tft.setTextColor(WHITE);
      tft.setTextSize(2);
      displayVal = S_Initial;
      delay(500);
      loopNumber = 1;  
      
    }else if(loopNumber == 1) {
      tft.setCursor(115,220);
      tft.setTextColor(WHITE);
      tft.setTextSize(2);
      displayVal = S_PostInitial;
        delay(500);
      loopNumber = 2;  
      
    }else if(loopNumber == 2) {
      tft.setCursor(115,220);
      tft.setTextColor(WHITE);
      tft.setTextSize(2);
      displayVal = S_Final;
        delay(500);
      loopNumber = 3; 
    }else if(loopNumber == 3) {
      displayVal = S_Danger +analogValue ;// + " " + "Danger";

    }

  }
  //Serial.println(displayVal);  

  tft.print(displayVal);
  delay(1000);
  if(loopNumber == 2) {
    delay(2000);
  }
}
  
