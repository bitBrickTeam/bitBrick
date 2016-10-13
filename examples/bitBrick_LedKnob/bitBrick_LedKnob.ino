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

        int sensorValue = myBrick.get_sensor_value(1);
        int outValue = map(sensorValue,0,1023,0,255);
        
        Serial.print(sensorValue);
        Serial.print("\t");
        Serial.println(outValue);
        
        
        //myBrick.set_led_rgb(outValue,0,255-outValue);
        
        //myBrick.set_led_num(outValue);
        
        if(sensorValue<100)             myBrick.set_led_color(white);
        else                            myBrick.set_led_color(yellow);
        

        /////////////////////your Code END//////////////////////////////
}

void bitBrickRun(void)
{
        myBrick.run();
}




