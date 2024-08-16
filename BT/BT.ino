//#include <SoftwareSerial.h>

//SoftwareSerial BTSerial(A5, A4);

/*
  AT+RMAAD (To clear any paired devices)
  AT+ROLE=1 (To set it as master)
  AT+CMODE=0 (To connect the module to the specified Bluetooth address and this Bluetooth address can be specified by the binding command)
  AT+BIND=xxxx,xx,xxxxxx (Now, type AT+BIND=98d3,34,906554 obviously with your respective address to the slave. Note the commas instead of colons given by the slave module.
*/

void setup() {
  Serial.begin(9600);
  //  BTSerial.begin(38400);
  pinMode(13, OUTPUT);
  Serial.write("AT+NAMETermit2Max");
  //  Serial.write("AT+NAMEPin10Ten");
}

void loop() {
  //  if (BTSerial.available()) {
  //    Serial.write(BTSerial.read());
  //  }
  //  if (Serial.available()) {
  //    BTSerial.write(Serial.read());
  //  }
}
