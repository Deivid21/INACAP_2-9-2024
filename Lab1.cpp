void setup() {
  // Pines
  pinMode(2, INPUT); // LDR1
  pinMode(3, INPUT); // LDR2
  pinMode(4, INPUT); // Pulsador 1
  pinMode(5, INPUT); // Pulsador 2
  pinMode(13, OUTPUT); // LED 1
  pinMode(12, OUTPUT); // LED 2
  pinMode(11, OUTPUT); // LED 3
  pinMode(10, OUTPUT); // LED 4

}

void loop() {

  // Control LED inicio y final
  if (digitalRead(4) == LOW) {
    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);
  }
  if (digitalRead(5) == LOW) {
    digitalWrite(11, LOW);
    digitalWrite(10, HIGH);
  }

  // LDR
  if (digitalRead(2) == LOW) {
    digitalWrite(13, HIGH);
  }

  if (digitalRead(3) == LOW) {
    digitalWrite(12, HIGH);
  }
}