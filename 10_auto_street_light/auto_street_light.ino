/*
 * Automatic Street Light Using Arduino & Photoresistor
 * --------------------------------------------------
 * Reads an LDR through analog pin A0 (10k ohm pull-down to GND)
 * and switches an LED on digital pin 10 ON when the ambient
 * light falls below the threshold value.
 *
 * Hardware:
 *   - Arduino UNO (ATmega328P)
 *   - LDR (photoresistor)
 *   - 10k ohm pull-down resistor (R2)
 *   - 330 ohm LED current-limiting resistor (R1)
 *   - LED on digital pin 10
 *
 * Wiring:
 *   5V -> LDR -> A0 -> 10k -> GND   (voltage divider)
 *   D10 -> 330 ohm -> LED -> GND
 *
 * Author: Ulker Aliyeva
 */

int LDR_VAL = 0;

void setup() {
  pinMode(10, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  LDR_VAL = analogRead(A0);
  Serial.println(LDR_VAL);

  if (LDR_VAL > 500) {
    digitalWrite(10, HIGH);   // LED ON  (dark environment)
  } else {
    digitalWrite(10, LOW);    // LED OFF (bright environment)
  }
}
