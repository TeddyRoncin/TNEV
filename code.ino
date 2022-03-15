//#include "constants.cpp"

#include "Movement.hpp"
#include "LightResistance.hpp"

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
