
void setup()
{
  // Pines
  pinMode(13, OUTPUT); // LED 1 - Rojo
  pinMode(12, OUTPUT); // LED 2 - Verde
  pinMode(11, OUTPUT); // LED 3 - V/V 1
  pinMode(10, OUTPUT); // LED 4 - V/V 2
  pinMode(5, INPUT); // LDR2 - Maximo
  pinMode(4, INPUT); // LDR1 - Minimo
  pinMode(3, INPUT); // Pulsador 2 - Partida
  pinMode(2, INPUT); // Pulsador 1 - Parada
  digitalWrite(13, HIGH); // LED 1 - Rojo Encendido Inicio
}

void loop()
{
// Pulsador 1 - Parada
  if (digitalRead(2) == HIGH) {
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
  }
// Pulsador 2 - Partida
  if (digitalRead(3) == HIGH) {
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
  }
// LDR1 - Minimo
  if (digitalRead(4) == LOW) {
    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);
  } else if (digitalRead(4) == HIGH) {
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
  }
// LDR2 - Maximo
  if (digitalRead(5) == LOW) {
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
  } else if (digitalRead(5) == HIGH) {
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  }
}
