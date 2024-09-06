//
// Copyright (C) 1996 - 2024 INACAP
// Copyright (C) 2017 - 2024 Deivid Ignacio Parra (Deivid21)
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Estado del Sistema = Partida
bool SystemOff = false;

void setup() {
  // Configuarcion de Pines
  pinMode(13, OUTPUT); // LED 1 - Rojo
  pinMode(12, OUTPUT); // LED 2 - Verde
  pinMode(11, OUTPUT); // LED 3 - V/V 1
  pinMode(10, OUTPUT); // LED 4 - V/V 2
  pinMode(5, INPUT); // LDR2 - Maximo
  pinMode(4, INPUT); // LDR1 - Minimo
  pinMode(3, INPUT); // Pulsador 2 - Partida
  pinMode(2, INPUT); // Pulsador 1 - Parada
  
  // LED 1 - Rojo = Encendido al Inicio
  digitalWrite(13, HIGH);
}

void loop() {
  if (digitalRead(2) == HIGH) {
    digitalWrite(10, LOW); // Apaga LED 4 - V/V 2
    digitalWrite(11, LOW); // Apaga LED 3 - V/V 1
    digitalWrite(12, LOW); // Apaga LED 2 - Verde
    digitalWrite(13, HIGH); // Enciende LED 1 - Rojo
    SystemOff = true; // Estado del Sistema = Parado
  } else if (digitalRead(3) == HIGH) {
    digitalWrite(10, LOW); // Apaga LED 4 - V/V 2
    digitalWrite(11, LOW); // Apaga LED 3 - V/V 1
    digitalWrite(12, HIGH); // Enciende LED 2 - Verde
    digitalWrite(13, LOW); // Apaga LED 1 - Rojo
    SystemOff = false; // Estado del Sistema = Partida
  } else {
    if (SystemOff) {
      digitalWrite(10, LOW); // Apaga LED 4 - V/V 2
      digitalWrite(11, LOW); // Apaga LED 3 - V/V 1
    } else {
      if (digitalRead(5) == LOW) {
        digitalWrite(11, LOW); // Apaga LED 3 - V/V 1
        digitalWrite(10, HIGH); // Enciende LED 4 - V/V 2
      } else if (digitalRead(4) == LOW) {
        digitalWrite(10, LOW); // Apaga LED 4 - V/V 2
        digitalWrite(11, HIGH); // Enciende LED 3 - V/V 1
      } else {
        digitalWrite(10, LOW); // Apaga LED 4 - V/V 2
        digitalWrite(11, LOW); // Apaga LED 3 - V/V 1
      }
    }
  }
}