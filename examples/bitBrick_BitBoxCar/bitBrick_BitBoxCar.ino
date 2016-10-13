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

int MaxSpeed = 100;

int loopTimer;

int servoTimer;

void setup()
{
        Timer1.initialize(20000);//20000->20ms bitBrick need a data every 20ms
        Timer1.attachInterrupt(bitBrickRun);
        Serial.begin(38400);
}

void loop()
{
        ////////////////////your Code START//////////////////////////////
        Serial.println(myBrick.get_sensor_value(1));

        if(loopTimer<95*2)      loopTimer++;
        else                    loopTimer = 0;

        if(loopTimer<95)        servoTimer = loopTimer;
        else                    servoTimer = 190 - loopTimer;
        
        if(servoTimer%4==map(myBrick.get_sensor_value(1),0,1023,0,5))
        {
        //myBrick.set_buzzer_num(servoTimer);
        }
        else
        myBrick.set_buzzer_num(0);
        
//        if (myBrick.get_sensor_value(1) < 150)
//        {
//                //leftTurn
//                myBrick.set_led_color(yellow);
//                myBrick.set_dc_motor_dir_speed(B, CW, MaxSpeed);
//                myBrick.set_dc_motor_dir_speed(C, CW, MaxSpeed);
//
//        }
//        else
//        {
//                //foward
//                myBrick.set_led_color(red);
//                myBrick.set_dc_motor_dir_speed(B, CCW, MaxSpeed);
//                myBrick.set_dc_motor_dir_speed(C, CW, MaxSpeed);
//        }
        /////////////////////your Code END//////////////////////////////
}

void bitBrickRun(void)
{
        myBrick.run();
}




