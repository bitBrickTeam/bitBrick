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

int mode;

unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change :
const long interval = 5000;           // interval at which to blink (milliseconds)

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
  {

    myBrick.set_buzzer_num(60);
    delay(100);
    myBrick.set_buzzer_num(0);
    delay(400);
    myBrick.set_buzzer_num(55);
    delay(100);
    myBrick.set_buzzer_num(0);
    myBrick.set_led_color(red);
    myBrick.set_servo_motor(A, 20);

    for (int i = 0; i < 20; i++)
    {
      myBrick.set_servo_motor(C, 1);
      delay(100);
      myBrick.set_servo_motor(C, 40);
      delay(100);
    }

    myBrick.set_servo_motor(A, 90);

  }
  else
  {
    myBrick.set_buzzer_num(0);
    if (myBrick.get_sensor_value(4) < 100)
    {
      if (val < 255)     val++;
      delay(10);

    }
    else
    {
      if (val)     val--;
      delay(10);
    }


    if (myBrick.get_sensor_value(2) < 500)
    {
      myBrick.set_dc_motor_dir_speed(B, CW, 10);
      myBrick.set_led_num(map(myBrick.get_sensor_value(3), 0, 1023, 0, 200));
    }
    else
    {
      myBrick.set_dc_motor_dir_speed(B, CW, 0);
      myBrick.set_led_rgb(val, val, val);
    }



  }



  /////////////////////your Code END//////////////////////////////
}



void bitBrickRun(void)
{
  myBrick.run();
}




