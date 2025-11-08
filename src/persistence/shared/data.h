#pragma once;
#include <Arduino.h>

struct VoltData
{
  float volt[2][4];
};

struct ControlData
{
  bool ENTER_A = LOW;
  bool ENTER_B = LOW;
  bool BACK_A = LOW;
  bool BACK_B = LOW;
  bool UP_A = LOW;
  bool UP_B = LOW;
  bool DOWN_A = LOW;
  bool DOWN_B = LOW;
  bool LEFT_A = LOW;
  bool LEFT_B = LOW;
  bool RIGH_A = LOW;
  bool RIGH_B = LOW;
};