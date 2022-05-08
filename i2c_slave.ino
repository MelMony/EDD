// Arduino slave to Raspberry Pi master using I2C
#include <Wire.h>

void setup() {
  Wire.begin(0x8); // Join I2C to pi with address 8
  Serial.begin(9600); // For serial monitoring
  Serial.println("I2C Communication"); 
  Wire.onReceive(printData); // When data is received trigger function
  Wire.onRequest(echoData); // Send data to master when requested
}

void loop() {


}

void printData(int data) 
{
  Serial.println("Receiving message...");
  int c;
  String message = "";
  
  for(int i = 0; i < data; i++)
  {
      c  = Wire.read();
      message += char(c);
  }
  Serial.println(message);
  Serial.println("Message complete");
}

void echoData()
{
  Wire.write(1); // Confirm communication 
  Serial.println("Confirmation sent");
}
