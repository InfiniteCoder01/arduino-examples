#define ONBOARD_LED LED_BUILTIN

void setup() {
  pinMode(ONBOARD_LED,OUTPUT);
}

void loop() {
  delay(100);
  digitalWrite(ONBOARD_LED, HIGH);
  delay(100);
  digitalWrite(ONBOARD_LED, LOW);
}
