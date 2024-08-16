const int AIN1 = 19, AIN2 = 18, APWM = 20;

void setup() {
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(APWM, OUTPUT);
}

void loop() {
  int speed = 100;
  digitalWrite(AIN1, speed > 0);
  digitalWrite(AIN2, speed <= 0);
  analogWrite(APWM, abs(speed));
}
