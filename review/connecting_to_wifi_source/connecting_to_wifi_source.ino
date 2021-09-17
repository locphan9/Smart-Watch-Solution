#include <ESP8266WiFi.h>
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

#define height 22
void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();
  Serial.begin(115200);
  display.setTextColor(1);
  display.setTextSize(0);
  /*
    Serial.println("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid,password);

    while(WiFi.status() != WL_CONNECTED)  {
      delay(500);
      Serial.print(".");
    }
    Serial.println("");
    Serial.println("Wifi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
  */

}

void loop() {
  // put your main code here, to run repeatedly:
   display.clearDisplay();
    scanWifi();
    delay(5000);
  /*
    Serial.println("Wifi scan started");

    // WiFi.scanNetworks will return the number of networks found
    int n = WiFi.scanNetworks();
    Serial.println("Wifi scan ended");
    if (n == 0) {
     Serial.println("no networks found");
    } else {
     Serial.print(n);
     Serial.println(" networks found");
     for (int i = 0; i < n; ++i) {
       // Print SSID and RSSI for each network found
       Serial.print(i + 1);
       Serial.print(") ");
       Serial.print(WiFi.SSID(i));// SSID
      Serial.print(" ");
      int sigStrength = 4 * (WiFi.RSSI(i) + 100)/50 + 1;
       Serial.print(WiFi.RSSI(i));//Signal strength in dBm
       Serial.print(" ");
       Serial.print(sigStrength);
       Serial.print("dBm (");
       
       if(WiFi.encryptionType(i) == ENC_TYPE_NONE)
       {
           Serial.println(" <<***OPEN***>>");
       }else{
           Serial.println();
       }

       delay(10);
     }
    }
    Serial.println("");

    // Wait a bit before scanning again
    delay(5000);
    WiFi.scanDelete();  */
}
//int numwifis=0;
//#define ypos 1
void scanWifi() {
  //int8_t f, ssids[numwifis][3];
  Serial.print("Scan start ... ");
  int n = WiFi.scanNetworks();
  Serial.print(n);
  Serial.println(" network(s) found");

  for (int f = 0; f < n; f++)
  {
    display.setCursor(0, 0);
    display.println("Networks");
    int quality = 3 * (WiFi.RSSI(f) + 100)/50 + 1;
    for (int k = 0; k < quality; k++) {
      display.drawLine(1 + k * 2, 18 + f * height + height, 1 + k * 2, 18 + f * height + height - k * 3, 1);
    }
    // ssids[f][ypos] = 14+ f * height;
    display.setCursor(18, 12 + f * height);
    display.print(WiFi.SSID(f));
    display.drawLine(3, 8 + f * height, SCREEN_WIDTH, 8 + f * height, 1);
  }
  display.display();

}

/*

display.setCursor(0, 0);
display.println("Networks");
int quality = 3 / 50 * (WiFi.RSSI(f) + 100) + 1;
for (int k = 0; k < quality; k++) {
  display.drawLine(1 + k * 2, 18 + f * height + height, 1 + k * 2, 18 + f * height + height - k * 3, 1);
}
// ssids[f][ypos] = 14+ f * height;
display.setCursor(18, 12 + f * height);
display.print(WiFi.SSID(f));
display.drawLine(3, 8 + f * height, SCREEN_WIDTH, 8 + f * height, 1);
}
display.display();
}
*/

/*
  #include "ESP8266WiFi.h"

  void setup()
  {
  Serial.begin(115200);
  Serial.println();

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  }

  void loop()
  {
  Serial.print("Scan start ... ");
  int n = WiFi.scanNetworks();
  Serial.print(n);
  Serial.println(" network(s) found");
  for (int i = 0; i < n; i++)
  {
    Serial.println(WiFi.SSID(i));
  }
  Serial.println();

  delay(5000);
  }
*/
