#include <FtduinoSimple.h>

bool coin;

void setup()
{
  while (!ftduino.input_get(Ftduino::I6)) // linke Rolle
  {
    ftduino.motor_set(Ftduino::M2, Ftduino::LEFT);
  }
  ftduino.motor_set(Ftduino::M2, Ftduino::OFF);

  while (!ftduino.input_get(Ftduino::I5)) // mittlere Rolle
  {
    ftduino.motor_set(Ftduino::M3, Ftduino::LEFT);
  }
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);

  while (!ftduino.input_get(Ftduino::I4)) // rechte Rolle
  {
    ftduino.motor_set(Ftduino::M4, Ftduino::LEFT);
  }
  ftduino.motor_set(Ftduino::M4, Ftduino::OFF);

  while (!ftduino.input_get(Ftduino::I2)) // Ausgabe
  {
    ftduino.motor_set(Ftduino::M1, Ftduino::LEFT);
  }
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);
}

void loop()
{
  coin = false;

  if (ftduino.input_get(Ftduino::I1))
  {
    coin = true;
  }
  else
  {
    coin = false;
  }

  if (ftduino.input_get(Ftduino::I7) && coin == true)
  {
    ftduino.motor_set(Ftduino::M2, Ftduino::LEFT);
    ftduino.motor_set(Ftduino::M3, Ftduino::LEFT);
    ftduino.motor_set(Ftduino::M4, Ftduino::LEFT);

  if (ftduino.input_get(Ftduino::I7)){
    switch (calcPos(1,3)){
      case 1:
    }
  }
   
}

int calcPos(int min, int max){

    double range = max - min + 1;
    return min + (int)(range * rand()/(RAND_MAX+1.0));

}


void stopRolling(int pos,  )