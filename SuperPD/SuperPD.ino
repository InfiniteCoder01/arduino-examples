const int AIN1 = 19, AIN2 = 18, APWM = 20;
const int ENCODER = A2;

void setup() {
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(APWM, OUTPUT);
}

void loop() {
  static float last;
  int speed = 10;
  digitalWrite(AIN1, speed > 0);
  digitalWrite(AIN2, speed <= 0);
  analogWrite(APWM, abs(speed));
  last += (analogRead(ENCODER) - last);// * 0.4;
  Serial.println(last);
}
