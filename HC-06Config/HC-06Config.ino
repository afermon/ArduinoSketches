/*
CrArm Arduino Code
Created By Alex Fermon 2015
 
 The circuit: 
 * RX pin 10
 * TX pin 11
 
*/

#include <SoftwareSerial.h>

SoftwareSerial CrArm(12, 13); // RX, TX

void setup()  
{
  Serial.begin(9600);
  Serial.write("STARTED");
  CrArm.begin(9600);
  delay(1000);
  CrArm.print("AT");
  delay(1000);
  CrArm.print("AT+VERSION");
  delay(1000);
  CrArm.print("AT+PIN4018"); // Set pin to 4018
  delay(1000);
  CrArm.print("AT+NAMECrArm"); // Set name
  delay(1000);
  CrArm.print("AT+BAUD4"); //baudrate to 9600
  delay(1000);
  Serial.write("F");
}

void loop() // run over and over
{
  if (CrArm.available())
    Serial.write(CrArm.read());
  if (Serial.available())
    CrArm.write(Serial.read());
}

