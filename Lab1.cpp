//
// Copyright (C) 1996 - 2024 INACAP
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

// Variable para recordar el estado del sistema
bool sistemaParado = false;

void setup()
{
  // Pines
  pinMode(13, OUTPUT); // LED 1 - Rojo
  pinMode(12, OUTPUT); // LED 2 - Verde
  pinMode(11, OUTPUT); // LED 3 - V/V 1
  pinMode(10, OUTPUT); // LED 4 - V/V 2
  pinMode(5, INPUT);  // LDR2 - Maximo
  pinMode(4, INPUT);  // LDR1 - Minimo
  pinMode(3, INPUT);  // Pulsador 2 - Partida
  pinMode(2, INPUT);  // Pulsador 1 - Parada

  // Inicializa LEDs
  digitalWrite(13, HIGH); // LED rojo encendido al inicio
}

void loop()
{
  // Lee el estado de los botones y sensores
  bool parada = digitalRead(2) == HIGH;
  bool partida = digitalRead(3) == HIGH;
  bool ldr1 = digitalRead(4) == LOW;
  bool ldr2 = digitalRead(5) == LOW;

  if (parada) {
    // Cuando el Pulsador 1 (Parada) está presionado
    digitalWrite(10, LOW);  // Apaga LED 4
    digitalWrite(11, LOW);  // Apaga LED 3
    digitalWrite(12, LOW);  // Apaga LED verde
    digitalWrite(13, HIGH); // Enciende LED rojo

    sistemaParado = true; // Establece el estado como "parado"
  } 
  else if (partida) {
    // Cuando el Pulsador 2 (Partida) está presionado
    digitalWrite(10, LOW);  // Apaga LED 4
    digitalWrite(11, LOW);  // Apaga LED 3
    digitalWrite(12, HIGH); // Enciende LED verde
    digitalWrite(13, LOW);  // Apaga LED rojo

    sistemaParado = false; // Establece el estado como "en marcha"
  } 
  else {
    // Cuando no se presionan los botones
    if (sistemaParado) {
      // Si el sistema está en estado "parado", apaga los LEDs 3 y 4
      digitalWrite(10, LOW);  // Apaga LED 4
      digitalWrite(11, LOW);  // Apaga LED 3
    } 
    else {
      // Controla los LEDs con las LDRs y asegura que no estén activas al mismo tiempo
      if (ldr2) {
        // LDR2 está activo, apaga LDR1
        digitalWrite(11, LOW);  // Apaga LED 3
        digitalWrite(10, HIGH); // Enciende LED 4
      } 
      else if (ldr1) {
        // LDR1 está activo, apaga LDR2
        digitalWrite(10, LOW);  // Apaga LED 4
        digitalWrite(11, HIGH); // Enciende LED 3
      } 
      else {
        // Ambos LDRs están inactivos
        digitalWrite(10, LOW);  // Apaga LED 4
        digitalWrite(11, LOW);  // Apaga LED 3
      }
    }
  }
}