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
  
  // LED
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
}

void loop() {

  // Control LED inicio y final
  if (digitalRead(4) == LOW) {
    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);
  } else if (digitalRead(5) == LOW) {
    digitalWrite(11, LOW);
    digitalWrite(10, HIGH);
  }

  // Lectura LDR
  int valorLDR1 = analogRead(2);
  int valorLDR2 = analogRead(3);

  // LDR
  if (valorLDR1 < 1000) { // Umbral LDR1
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }

  if (valorLDR2 < 1000) { // Umbral LDR2
    digitalWrite(12, HIGH);
  } else {
    digitalWrite(12, LOW);
  }
}
