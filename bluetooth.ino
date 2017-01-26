#include <DHT11.h>

//#include <SoftwareSerial.h>   //Serial library

int pin = 4;
DHT11 dht11(pin);   

// connect Arduino  TX pin to dongle RX pin 
// SoftwareSerial bt (5,6); // RX, TX

int btdata;   // sensordata bluetooth

void setup() {
  //bt.begin (9600);
  Serial.begin (9600);
}
  void loop() {
    int error;
    float temp, humi;
    if ((error = dht11.read(humi, temp)) == 0)
    {
    Serial.print("temperature:");
    Serial.print(temp);
    Serial.print(" humidity:");
    Serial.print(humi);
    Serial.println();
  }
  else
  {
    Serial.println();
    Serial.print("Error No");
    Serial.print(error);
    Serial.println();    
  }
  delay(DHT11_RETRY_DELAY); //delay for reread

    

  // Send data to serial bluetooth
  // bt.print(String(btdata) + "test");
  // bt.print("\n");
  
  //  delay(2000);
  }

