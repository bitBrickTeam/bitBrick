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


void setup()
{
  Timer1.initialize(20000);//20000->20ms bitBrick need a data every 20ms
  Timer1.attachInterrupt(bitBrickRun);
  Serial.begin(38400);
}

void loop()
{
  ////////////////////your Code START//////////////////////////////

  TIME();

  if (mode == 0)
  {
    myBrick.set_led_color(red);
    myBrick.set_servo_motor(A, 0);

    if (myBrick.get_sensor_value(2) < 500)
    {
      myBrick.set_buzzer_num(60);
      delay(50);
    }
    else
      myBrick.set_buzzer_num(0);
  }
  else if (mode == 1)
  {
    myBrick.set_buzzer_num(0);
    myBrick.set_led_color(green);
    myBrick.set_servo_motor(A, 90);
  }
  else if (mode == 2)
  {
    myBrick.set_buzzer_num(0);
    myBrick.set_led_color(green);
    delay(500);
    myBrick.set_led_rgb(0, 0, 0);
    delay(500);

    myBrick.set_servo_motor(A, 90);

  }

  /////////////////////your Code END//////////////////////////////
}

void TIME()
{
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
    if (mode < 2)  mode++;
    else        mode = 0;


  }


}

void bitBrickRun(void)
{
  myBrick.run();
}




