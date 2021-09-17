#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <time.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define height 6
#define width 6
#define delta 4
#define OLED_RESET      LED_BUILTIN
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  // put your setup code here, to run once:
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();
}

void loop() {
  drawButton();
}

void drawButton() {
  
 // display.drawRoundRect(SCREEN_WIDTH/2+SCREEN_HEIGHT/2,SCREEN_HEIGHT/2-height,width,2*height);
  
  //k is the voltage reading
  for(int k=0;k<15;k++) {
    display.clearDisplay();
  for(int i=0;i<50;i++) {
    display.drawLine(SCREEN_WIDTH/2+SCREEN_HEIGHT/2,i*delta+k,SCREEN_WIDTH/2+SCREEN_HEIGHT/2+width,i*delta+k,1);
  }
  display.display();
  }
  
  delay(900);
}
