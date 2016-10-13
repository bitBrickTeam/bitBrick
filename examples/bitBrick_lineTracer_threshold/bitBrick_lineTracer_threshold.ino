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

int MaxSpeed=100;

void setup()
{
        Timer1.initialize(20000);//20000->20ms bitBrick need a data every 20ms
        Timer1.attachInterrupt(bitBrickRun);
        Serial.begin(38400);
}

void loop()
{
        ////////////////////your Code START//////////////////////////////
        
        Serial.println(myBrick.get_sensor_value(3));

        int tempValue = myBrick.get_sensor_value(3);
        
        if (myBrick.get_sensor_value(1)> tempValue)
        {
                if (myBrick.get_sensor_value(2) > tempValue)
                {//foward
                        myBrick.set_led_color(red);
                        myBrick.set_dc_motor_dir_speed(B,CCW,MaxSpeed);
                        myBrick.set_dc_motor_dir_speed(C,CW,MaxSpeed);
                }
                else
                {//leftTurn
                        myBrick.set_led_color(yellow);
                        myBrick.set_dc_motor_dir_speed(B,CW,MaxSpeed);
                        myBrick.set_dc_motor_dir_speed(C,CW,MaxSpeed);
                }
        }
        else
        {
                if (myBrick.get_sensor_value(2) > tempValue)
                {//rightTurn
                        myBrick.set_led_color(pink);
                        myBrick.set_dc_motor_dir_speed(B,CCW,MaxSpeed);
                        myBrick.set_dc_motor_dir_speed(C,CCW,MaxSpeed);
                }
                else
                {//foward
                        myBrick.set_led_color(blue);
                        myBrick.set_dc_motor_dir_speed(B,CCW,MaxSpeed);
                        myBrick.set_dc_motor_dir_speed(C,CW,MaxSpeed);
                }
        }
        
        /////////////////////your Code END//////////////////////////////
}

void bitBrickRun(void)
{
        myBrick.run();
}






