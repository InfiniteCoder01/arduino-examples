void setup() {
  Serial.begin(9600);
}

void loop() {
  float millivolts = (analogRead(A0) / 1024.0) * 3300;
  float celsius = millivolts / 10;
  Serial.print("In DegreeC = ");
  Serial.println(celsius);
  delay(1000);
}