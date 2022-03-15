#pragma once

#include "constants.cpp"
#include <Arduino.h>

#include "Movement.hpp"

/*
 * This class reprensents the light resistance.
 * It is placed under the robot, quite near the ground.
 * Half of what it sees should be the ground and half should be the scotch on the ground.
 * When the sensor measures the ambiant luminosity to be too close to the one of the ground, (we "see" too much ground), so we go back on the scotch.
 * When the sensor measures the ambiant luminosity to be too close the the one of the scotch (we "see" too much scotch), so we go back on the ground.
 * That should make the robot be able to follow the track (as long as it is not too fast)
 */

class LightResistance
{
public:
  LightResistance(Movement& movement);
  void Calibrate();
  int Update();

  void test() {
    while (true) {
      Serial.println(Measure());
    }
  }

private:
  Movement m_Movement;
  int m_GroundColor;
  int m_TapeColor;
  int m_GoalColor;
  int Measure();

};

LightResistance::LightResistance(Movement& movement)
{
  m_Movement = movement;
}

void LightResistance::Calibrate()
{
  m_Movement.Turn(90);
  m_Movement.StartMoving();
  m_GroundColor = Measure();
  Serial.println(m_GroundColor);
  m_TapeColor = m_GroundColor;
  int color;
  while (abs(m_TapeColor - m_GroundColor) < 100 || abs(m_GroundColor - color) > abs(m_TapeColor - color)) {
    m_Movement.Update();
    color = Measure();
    if (abs(m_GroundColor - m_TapeColor) < abs(m_GroundColor - color)) {
      m_TapeColor = color;
      Serial.println(m_TapeColor);
    }
  }
  Serial.println("Fini");
  Serial.print("Couleur du sol : ");
  Serial.println(m_GroundColor);
  Serial.print("Couleur du scotch : ");
  Serial.println(m_TapeColor);
  m_GoalColor = (m_GroundColor + m_TapeColor) / 2;
}

int LightResistance::Update()
{
  int color = Measure();
  if (abs(m_TapeColor - color) < abs(m_GoalColor - color)) {
    Serial.println("Dirigez vous vers le sol");
  } else {
    Serial.println("Dirigez vous vers le scotch");
  }
  return 0;
}

int LightResistance::Measure()
{
  return analogRead(LIGHT_RESISTANCE_PIN);
}
