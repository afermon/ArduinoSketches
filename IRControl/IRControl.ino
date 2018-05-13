#include <IRremote.h>

int RECV_PIN = 2;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600); // Initiallize serial port at 9600 rate
  irrecv.enableIRIn(); // Initiallize the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX); // send the result to the serial port.
    irrecv.resume(); // Receive the next value
  }
  delay(100); //Wait 100ms
}
