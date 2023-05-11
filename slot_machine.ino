#include <FtduinoSimple.h>

bool debug = false;
bool coin;

int motor=2;
int input=4;

void setup() //Rollen fahren auf Ausgangsposition / Ausgabe schließt sich
{
  coin = false;

  while (!ftduino.input_get(Ftduino::I4)) // linke Rolle
  {
    ftduino.motor_set(Ftduino::M2, Ftduino::LEFT);
  }
  ftduino.motor_set(Ftduino::M2, Ftduino::OFF);

  while (!ftduino.input_get(Ftduino::I5)) // mittlere Rolle
  {
    ftduino.motor_set(Ftduino::M3, Ftduino::LEFT);
  }
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);

  while (!ftduino.input_get(Ftduino::I6)) // rechte Rolle
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
  if ((ftduino.input_get(Ftduino::I3) && (ftduino.input_get(Ftduino::I7)))) {
    if (debug == true) {
      debug = false;
    } else {
      debug = true;
    }
  }

  if (ftduino.input_get(Ftduino::I1))
  {
    coin = true;
  }


  if (ftduino.input_get(Ftduino::I7) && coin == true)
  {
    ftduino.motor_set(Ftduino::M2, Ftduino::LEFT);
    ftduino.motor_set(Ftduino::M3, Ftduino::LEFT);
    ftduino.motor_set(Ftduino::M4, Ftduino::LEFT);

    while (ftduino.input_get(Ftduino::I3)){}
/*     ftduino.motor_set(Ftduino::M2, Ftduino::OFF);
    ftduino.motor_set(Ftduino::M3, Ftduino::OFF);
    ftduino.motor_set(Ftduino::M4, Ftduino::OFF); */
    for (int t=0; t <= 3; t++) {
      stopRolling(t);
    }
  }   
}


int calcPos(int min, int max){

  double range = max - min + 1;
  return min + (int)(range * rand()/(RAND_MAX+1.0));
}

void stopRolling(int t){
  input = t+3;
  motor = t+1;
  int duration;

  switch(calcPos(1, 3)) { //alle Zeitwerte anpassen!
    case 1:
      duration=100;
      break;
    case 2:
      duration=200;
      break;
    case 3:
      duration=1000;
      break;
  }

  while (!ftduino.input_get(input)) // Ausgabe
  {
  
  }
  delay(duration);
  ftduino.motor_set(motor, Ftduino::OFF);
  
  
}
