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


int val = 2;

void setup()
{
  Timer1.initialize(20000);//20000->20ms bitBrick need a data every 20ms
  Timer1.attachInterrupt(bitBrickRun);
  Serial.begin(38400);
}

void loop()
{
  ////////////////////your Code START//////////////////////////////
  if ((myBrick.get_sensor_value(2) < 500) || (myBrick.get_sensor_value(4) < 400))
  {
    if (val < 250)     val++;

  }
  else
  {
    if (val >= 2)     val -= 2;
    else             val = 0;
  }

  myBrick.set_led_rgb(val, val, val);
  delay(5);

  /////////////////////your Code END//////////////////////////////
}

void bitBrickRun(void)
{
  myBrick.run();
}




