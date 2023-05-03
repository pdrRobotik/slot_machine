#include <FtduinoSimple.h>

bool debug = false;
bool coin;

int motor=2;
int input=4;


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

void loop(){
  if ((ftduino.input_get(Ftduino::I3)) && (ftduino.input_get(Ftduino::I7))) {
    if (debug == true) {
      debug = false;
    } else {
      debug = true;
    }
  }


  coin = false;

  if (ftduino.input_get(Ftduino::I1)) //münzschlitz 
  {
    coin = true;
  }
  else
  {
    coin = false;
  }

  if (ftduino.input_get(Ftduino::I7) && coin == true) //wenn coin registriert und startknopf
  {
    ftduino.motor_set(Ftduino::M2, Ftduino::LEFT); // rollen drehen
    ftduino.motor_set(Ftduino::M3, Ftduino::LEFT);
    ftduino.motor_set(Ftduino::M4, Ftduino::LEFT);

    if (ftduino.input_get(Ftduino::I3)){
      for (int t=0; t <= 2; t++) {
      stopRolling(t);
      }
    } 

  }
   
}

int calcPos(int min, int max){

  double range = max - min + 1;
  return min + (int)(range * rand()/(RAND_MAX+1.0));



}


void stopRolling(int t){ //rollen stoppen
  int time;
  input = t+4;
  motor = t+2;

  switch(t) { //alle Zeitwerte anpassen!
    case 1:
      time = 100;
    case 2:
      time = 200;
    case 3:
      time = 300;
  }

  while (ftduino.input_get(input)) // Ausgabe
  {
    delay(time);
    ftduino.motor_set(motor, Ftduino::OFF);
  }
}