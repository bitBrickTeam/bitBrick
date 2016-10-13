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

int loopTimer,moveTimer;

void setup()
{
        Timer1.initialize(20000);//20000->20ms bitBrick need a data every 20ms
        Timer1.attachInterrupt(bitBrickRun);
        Serial.begin(38400);
}

void loop()
{
         ////////////////////your Code START//////////////////////////////
        myBrick.set_led_rgb(255,255,255);
        delay(1000);
        myBrick.set_led_rgb(0,0,0);
        delay(1000);
        

        /////////////////////your Code END//////////////////////////////
}

void bitBrickRun(void)
{
        myBrick.run();
}






