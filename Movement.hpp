#pragma once

#include <Arduino.h>
#include "constants.cpp"

class Movement
{
public:
  Movement();
  void Update();
  void Turn(int degree);
  void StartMoving();
  void StopMoving();
private:
  int m_AmountToTurn;
};


Movement::Movement() {}
void Movement::Update() {}
void Movement::Turn(int degree) {}
void Movement::StartMoving() {}
void Movement::StopMoving() {}

