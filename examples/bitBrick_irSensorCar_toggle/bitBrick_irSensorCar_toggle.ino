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

int MaxSpeed = 15;

boolean toggle, flag;

void setup()
{
  Timer1.initialize(20000);//20000->20ms bitBrick need a data every 20ms
  Timer1.attachInterrupt(bitBrickRun);
  Serial.begin(38400);
}

void loop()
{
  ////////////////////your Code START//////////////////////////////
  //Serial.println(myBrick.get_sensor_value(1));

  if (myBrick.get_sensor_value(1) < 500 && flag==false) //button
  {

    flag = true;
    if (toggle == 0)   toggle = 1;
    else            toggle = 0;
  }
  else
  {
    flag = false;
  }

  if (toggle == 0)
  {
    myBrick.set_dc_motor_dir_speed(B, CCW, 0);
    myBrick.set_dc_motor_dir_speed(C, CW, 0);
  }
  else
  {
    if (myBrick.get_sensor_value(2) < 200)
    {
      myBrick.set_dc_motor_dir_speed(B, CCW, 0);
      myBrick.set_dc_motor_dir_speed(C, CW, 0);
    }
    else
    {
      myBrick.set_dc_motor_dir_speed(B, CCW, MaxSpeed);
      myBrick.set_dc_motor_dir_speed(C, CW, MaxSpeed - 5);//-5 is CW,CCW zero set val
    }
  }


  /////////////////////your Code END//////////////////////////////
}

void bitBrickRun(void)
{
  myBrick.run();
}





