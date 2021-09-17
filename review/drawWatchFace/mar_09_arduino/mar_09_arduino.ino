
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

const float pi = 3.141593;
const char* ssid = "FiOS-HRDOQ";
const char* password = "box42neon8559knees";
int timezone = 8 * 3600;
int dst = 0;

const unsigned char deer18[] PROGMEM = {
  0x00,0x00,0x00,
  0x00,0x00,0x00,
  0x08,0x00,0x00,
  0x08,0x0C,0x00,
  0x0C,0x04,0x00,
  0x02,0x08,0x00,
  0x01,0x10,0x00,
  0x03,0xF0,0x00,
  0x01,0xF0,0x00,
  0x00,0xE0,0x00,
  0x00,0xE0,0x00,
  0x00,0xE0,0x00,
  0x01,0xE0,0x00,
  0x01,0xE0,0x00,
  0x00,0xE0,0x00,
  0x00,0x40,0x00
};

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();
  Serial.begin(115200);
  display.setTextColor(1);
  display.setTextSize(0);
  display.setCursor(0, 0);
  display.print("Connecting");
  WiFi.begin(ssid, password);
  display.display();
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    display.print(".");
    display.display();
  }
  Serial.println("Wifi Connected");
  Serial.println(WiFi.localIP() );
  display.clearDisplay();

  configTime(timezone, dst, "pool.ntp.org", "time.window.com");
  while (!time(nullptr))  {
    delay(1000);
    display.print(".");
    display.display();
  }
}

void loop() {
  drawWatchFace();
}

void drawWatchFace()  {
  //Draw the Watch's face
  display.clearDisplay();
  clockFace(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
  arm(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 18, 15, 12);
//  appCircle(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 11);
  numerical();
  drawLogo();
  display.display();
}

void clockFace(int xC, int yC)  {
  display.fillRoundRect(xC - yC, 0, 2 * yC, 2 * yC, delta, 1);
  for (int k = 0; k < 61; k++)  {
    display.drawLine(xC - cos(k * pi / 30), yC + sin(k * pi / 30), xC + HYPOTNUSE * cos(k * pi / 30), yC + HYPOTNUSE * sin(k * pi / 30), 0);
  }
  display.fillRoundRect(xC - yC + delta, delta, 2 * yC - 2 * delta, 2 * yC - 2 * delta, delta, 1);
  for (int k = 0; k < 15; k++)  {
    display.drawLine(xC - cos(k * pi / 6), yC + sin(k * pi / 6), xC + HYPOTNUSE * cos(k * pi / 6), yC + HYPOTNUSE * sin(k * pi / 6), 0);
  }
  display.fillRoundRect(xC - yC + 10, 10, 2 * yC - 2 * 10, 2 * yC - 2 * 10, 10, 1);
  display.setTextSize(2);
  display.setCursor(xC - 3, delta);
  display.print("A");
 // display.fillTriangle(xC - 2, delta + 1, xC + 2, delta + 1, xC, delta + 4, 0);
  display.drawRoundRect(xC - yC, 0, 2 * yC, 2 * yC, 5, 1);
  display.drawRoundRect(xC - yC + delta, delta, 2 * yC - 2 * delta, 2 * yC - 2 * delta, delta, 1);
  display.fillRect(0, 0, xC - yC, 2 * yC, 0);
  display.fillRect(xC + yC, 0, 2 * xC, 2 * yC, 0);
}
//xC-11, 2 * yC - 2 * delta -9
void arm(int xC, int yC, int secarm, int minarm, int hourarm) {
  time_t now = time(nullptr);
  struct tm* p_tm = localtime(&now);
  display.drawLine(xC, yC, xC + secarm * cos(p_tm->tm_sec * pi / 30 - pi / 2), yC + secarm * sin(p_tm->tm_sec * pi / 30 - pi / 2), 0);
  display.drawLine(xC, yC, xC + minarm * cos(p_tm->tm_min * pi / 30 - pi / 2), yC + minarm * sin(p_tm->tm_min * pi / 30 - pi / 2), 0);
  display.drawLine(xC, yC, xC + hourarm * cos(p_tm->tm_hour * pi / 6 + p_tm->tm_min * pi / 360 - pi / 2), yC + hourarm * sin(p_tm->tm_hour * pi / 6 + p_tm->tm_min * pi / 360 - pi / 2), 0);
}
/*
void appCircle(int xc, int yc, int radius)  {
  int k = 0;
  for ( int i = -1; k < 2; i *= -1) {
    display.drawCircle(xc - i * (xc - radius), yc + i * (yc - radius), radius, 1);
    display.drawCircle(xc - i * (xc - radius), yc - i * (yc - radius), radius, 1);
    k++;
  }
}
*/
void numerical()  {
  display.setTextColor(0);
  display.setTextSize(1);
  display.setCursor(SCREEN_WIDTH / 2 + SCREEN_HEIGHT / 2 - 5 * delta + 4, 2 * delta + 1);
  display.print("I");
  display.setCursor(SCREEN_WIDTH / 2 - SCREEN_HEIGHT / 2 + 3 * delta , 2 * delta + 1);
  display.print("11");
  display.setCursor(SCREEN_WIDTH / 2 + SCREEN_HEIGHT / 2 - 3 * delta, SCREEN_HEIGHT / 2 - 3);
  display.print("3");
  display.setCursor(SCREEN_WIDTH / 2 - SCREEN_HEIGHT / 2 + 2 * delta, SCREEN_HEIGHT / 2 - 3);
  display.print("9");
  display.setCursor(SCREEN_WIDTH / 2 + SCREEN_HEIGHT / 2 - 5 * delta +3, SCREEN_HEIGHT - 3 * delta -3);
  display.print("V");
  display.setCursor(SCREEN_WIDTH / 2 - SCREEN_HEIGHT / 2 + 4*delta -3, SCREEN_HEIGHT - 3 *delta -3);
  display.print("7");
}

void drawLogo() {
  display.drawBitmap(SCREEN_WIDTH/2-9,SCREEN_HEIGHT/2+10, deer18,18,16,0);
}
