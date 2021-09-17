#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <time.h>
#include <math.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define HYPOTNUSE 143
#define delta 5
#define OLED_RESET      LED_BUILTIN
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();
  Serial.begin(115200);
  display.setTextColor(1);
  display.setTextSize(0);
  display.setCursor(0, 0);
}

void loop() {
  app();
  
}

void app() {  
  for (int k = 0; k<15;k+=0.5) {
    display.clearDisplay();
    float ycover = pow(2,-(k-3));
    display.drawLine(0, ycover, SCREEN_WIDTH, ycover, 1);   
    display.display();
  }
}
