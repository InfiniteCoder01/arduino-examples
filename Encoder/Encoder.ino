void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
}

void loop() {
  static int count = 0;
  count += !digitalRead(4) * (digitalRead(3) * 2 - 1);
  Serial.print(digitalRead(2));
  Serial.print(' ');
  Serial.println(count);
}
