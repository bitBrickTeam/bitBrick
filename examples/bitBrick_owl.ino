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

int xVal, yVal, zVal;
int moveVal;

unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change :
const long interval = 50;           // interval at which to blink (milliseconds)


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

  xVal = myBrick.get_sensor_value(2);
  xVal = map(xVal, 20, 980, 45, 135);

  yVal = myBrick.get_sensor_value(4);
  yVal = map(yVal, 20, 980, 50, 130);

  zVal = myBrick.get_sensor_value(3);
  zVal = map(zVal, 0, 1023, 0, 180);


  if (myBrick.get_sensor_value(1) < 200)
  {
    if (mode == 0) {
      moveVal = 10;
      myBrick.set_buzzer_num(60);

    }
    else
    {
      moveVal = -10;
      myBrick.set_buzzer_num(0);
    }
  }
  else
  {
    myBrick.set_buzzer_num(0);
    moveVal = 0;
  }
  myBrick.set_servo_motor(A, xVal);
  myBrick.set_servo_motor(B, yVal);
  myBrick.set_servo_motor(C, zVal + moveVal);
  delay(20);

  /////////////////////your Code END//////////////////////////////
}

void TIME()
{
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
    if (mode < 1)  mode++;
    else        mode = 0;


  }


}


void bitBrickRun(void)
{
  myBrick.run();
}




