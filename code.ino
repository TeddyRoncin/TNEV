#include <Arduino.h>
#include "constants.cpp"

#include "Movement.hpp"
#include "LightResistance.hpp"

/*
 * This is the main file of the sketch.
 * "void setup()" function is called once when the sketch is started, and "void loop()" is then called indefinitely
*/

Movement mvmt = Movement();
LightResistance lr = LightResistance(mvmt);

void setup() {
  Serial.begin(9600);
  lr.Calibrate();
}

void loop() {
  while (!Serial.available()) {
    delay(1000);
  }
  lr.Update();
}
