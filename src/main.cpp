#include <Arduino.h>
// #include "Joystick.h"

const int btnsTL = 12;
const int btns[12] = {
    2, 3, 4,
    5, 6, 7,
    8, 9, 10,
    11, 12, 13}; //A0, A1, A2, A3, A4, A5}; 18

void setup()
{
  for (int i = 0; i < btnsTL; i++)
  {
    pinMode(btns[i], INPUT);
    digitalWrite(btns[i], HIGH);
  }
  Serial.begin(9600);
}
void pressButton()
{
  for (int i = 0; i < btnsTL; i++)
  {
    if (digitalRead(btns[i]) == LOW)
    {
      Serial.println(i);
    }
  }
}

void loop()
{
  pressButton();
}