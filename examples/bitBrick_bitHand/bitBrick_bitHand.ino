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

void setup()
{
        Timer1.initialize(20000);//20000->20ms bitBrick need a data every 20ms
        Timer1.attachInterrupt(bitBrickRun);
        Serial.begin(38400);
}


void loop()
{
        ////////////////////your Code START//////////////////////////////
        if(myBrick.get_sensor_value(1)<150)
        {
                myBrick.set_servo_motor(A,160);
                myBrick.set_led_num(0);
        }
        else
        {
                myBrick.set_servo_motor(A,70);
                myBrick.set_led_off();
        }
        /////////////////////your Code END//////////////////////////////
}

void bitBrickRun(void)
{
        myBrick.run();
}





