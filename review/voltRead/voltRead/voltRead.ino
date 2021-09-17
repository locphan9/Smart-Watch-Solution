#include <math.h>
const int analogInPin = A0;  // ESP8266 Analog Pin ADC0 = A0
int  sensorValue;
int element;
void setup() {
  // initialize serial communication at 115200
  Serial.begin(115200);
}

void loop( ) {
  // read the analog in value
  voltRead(25);
}

void voltRead(int numberElement) {
 sensorValue = analogRead(analogInPin);
 element = (sensorValue-17)*numberElement/1006;
Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("   ");
  Serial.print("element");
  Serial.println(element);
  delay(300);
}
