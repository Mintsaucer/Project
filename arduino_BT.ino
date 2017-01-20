#include <SoftwareSerial.h> //Serial library

// connect Arduino  TX pin to dongle RX pin 
SoftwareSerial bt (5,6); // RX, TX
// int ledPin = 13;
int btdata;   // sensordata

void setup() {
  // Serial.begin(9600);
  bt.begin (9600);
  
}

void loop() {
  // Send data to serial bluetooth
  bt.print(String(btdata) + "test");
  bt.print("\n");
  
  delay(1500);
}
