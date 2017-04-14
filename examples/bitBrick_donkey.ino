/*
        bitBrick to Arduino module
        Created by hellogeeks, bitBrick Team
        2017.04.10.
        www.bitbrick.cc
        info@hellogeeks.kr
*/


#include <bitBrick.h>
bitBrick myBrick;

#include <TimerOne.h>

void setup()
{
  Timer1.initialize(20000);//20000->20ms bitBrick need a data every 20ms
  Timer1.attachInterrupt(bitBrickRun);
  Serial.begin(38400);
}

void loop()
{
  ////////////////////your Code START//////////////////////////////


  int sensorVal = myBrick.get_sensor_value(2);
  sensorVal = map(sensorVal, 20, 980, 0, 30);

  int zero = myBrick.get_sensor_value(3);
  zero = map(zero, 0, 1023, 0, 80);
  myBrick.set_servo_motor(A, zero + sensorVal);


  /////////////////////your Code END//////////////////////////////
}



void bitBrickRun(void)
{
  myBrick.run();
}




