#include <Arduino.h>
#include <Joystick.h>

Joystick_ Joystick;

const int btnsTL = 18;
const int btns[18] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, A0, A1, A2, A3, A4, A5};

int state[18] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void setup()
{
  for (int i = 0; i < btnsTL; i++)
  {
    pinMode(btns[i], INPUT);
    digitalWrite(btns[i], HIGH);
  }
  Joystick.begin();
  Joystick.setXAxis(512);
  Joystick.setYAxis(512);
}
void pressButton()
{
  for (int i = 0; i < btnsTL; i++)
  {
    int st = digitalRead(btns[i]) == LOW;
    if (st != state[i])
    {
      Joystick.setButton(i, st);
      state[i] = st;
    }
  }
}

void loop()
{
  pressButton();
}