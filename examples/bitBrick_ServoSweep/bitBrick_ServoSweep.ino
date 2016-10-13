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
        if(loopTimer<360)       loopTimer++;
        else                    loopTimer = 0;

        if(loopTimer<180)       moveTimer = loopTimer;
        else                    moveTimer = 360 - loopTimer;

        Serial.println(moveTimer);
        
        myBrick.set_servo_motor(A,moveTimer);

        /////////////////////your Code END//////////////////////////////
}

void bitBrickRun(void)
{
        myBrick.run();
}






