
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <time.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define HYPOTNUSE 143
#define delta 5
#define OLED_RESET      LED_BUILTIN
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  // put your setup code here, to run once:
  // put your setup code here, to run once:
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();
  Serial.begin(115200);
  display.setCursor(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
  display.setTextColor(1);
  display.setTextSize(0);

}
unsigned long myTime;
int sec1;
int start = 0;
unsigned long tim = 0;
unsigned long msec = 0;
unsigned long mili = 0;
void loop() {
  // put your main code here, to run repeatedly:
  stopWatch();
}

void stopWatch()  {
  display.clearDisplay();
  if (start == 0) {
    tim = millis();
    start =1;
  }
  int msec = millis() - tim;
  int min1 = msec / 60000;

  if ((msec / 1000) > 59)
  {
    sec1 = (msec / 1000) - (min1 * 60);
  } else {
    sec1 = msec / 1000;
  }

  mili = (msec % 1000) / 10;

  display.setCursor(SCREEN_WIDTH/2-5,SCREEN_HEIGHT/2);
  if (min1 <= 9)
  {
    display.print("0");
    display.print(min1);
  } else {
    display.print(min1);
  }

  display.print(":");

  if (sec1 <= 9)
  {
    display.print("0");
    display.print(sec1);
  } else {
    display.print(sec1);
  }
  display.display();
}
