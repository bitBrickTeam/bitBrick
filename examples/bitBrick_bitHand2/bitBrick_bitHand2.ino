/*
        bitBrick to Arduino shield
        Created by hellogeeks, bitBrick Team
        2016.09.30.
        www.bitbrick.cc
        info@hellogeeks.kr
*/


#include <bitBrick.h>
bitBrick myBrick;

#include <TimerOne.h>

int val;


void setup()
{
  Timer1.initialize(20000);//20000->20ms bitBrick need a data every 20ms
  Timer1.attachInterrupt(bitBrickRun);
  Serial.begin(38400);
}

void loop()
{
  ////////////////////your Code START//////////////////////////////


  if (myBrick.get_sensor_value(1) < 500)
    myBrick.set_servo_motor(A, 160);
  else
    myBrick.set_servo_motor(A, 40);


  if (myBrick.get_sensor_value(2) < 200)
    myBrick.set_servo_motor(B, 160);
  else
    myBrick.set_servo_motor(B, 40);

  if (myBrick.get_sensor_value(3) < 100)
    myBrick.set_servo_motor(C, 175);
  else
    myBrick.set_servo_motor(C, 50);

  if (myBrick.get_sensor_value(4) < 100)
    myBrick.set_servo_motor(D, 175);
  else
    myBrick.set_servo_motor(D, 50);


  if (val < 200)     val++;
  else            val = 0;

  myBrick.set_led_num(val);

  delay(20);


  /////////////////////your Code END//////////////////////////////
}


void bitBrickRun(void)
{
  myBrick.run();
}




