// Arduino Uno 101 sending sensordata over serial bluetooth to Raspberry Pi 3

#include <DHT11.h> // Sensor library
#include <SoftwareSerial.h>   // Serial library

int bluetoothTx = 2;  // TX-O pin of bluetooth mate, Arduino D2
int bluetoothRx = 3;  // RX-I pin of bluetooth mate, Arduino D3
int pin = 4;    // DHT11 data pin

DHT11 dht11(pin);   

SoftwareSerial bt (bluetoothTx, bluetoothRx); 

void setup() 
{
  Serial.begin (9600);
  
  bt.begin(115200);  // The Bluetooth Mate defaults to 115200bps
  bt.print("$");  // Print three times individually
  bt.print("$");
  bt.print("$");  // Enter command mode
  delay(100);  // Short delay, wait for the Mate to send back CMD
  bt.println("U,9600,N");  // Temporarily Change the baudrate to 9600, no parity
  
  bt.begin (9600);
}
void loop() 
{
  int error;
  float temp, humi;
  
  if ((error = dht11.read(humi, temp)) == 0)
  {
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print(" Humidity: ");
  Serial.print(humi);
  Serial.print("%");
  Serial.println();

    // Printing data to serial bluetooth (bt)
  bt.print(String(temp) + "," + String(humi));
  bt.print("\n");

  delay(DHT11_RETRY_DELAY); //delay for reread
  }
  else
  {
  Serial.println();
  Serial.print("Error No. ");
  Serial.print(error);
  Serial.println();    
  }
}

/*
if(bt.available())  // If the bluetooth sent any characters
  {
    // Send any characters the bluetooth prints to the serial monitor
    Serial.print((char)bt.read());  
  }
  if(Serial.available())  // If stuff was typed in the serial monitor
  {
    // Send any characters the Serial monitor prints to the bluetooth
    bt.print((char)Serial.read());
  }
  // and loop forever and ever!
}
*/



