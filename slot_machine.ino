#include <FtduinoSimple.h>

void setup()
{

}

void loop()
{

  while (ftduino.input_get(Ftduino::I1))
  {
    ftduino.motor_set(Ftduino::M1, Ftduino::LEFT);
    
  }
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);
}

