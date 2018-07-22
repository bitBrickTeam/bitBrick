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

#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"

Adafruit_BicolorMatrix matrix = Adafruit_BicolorMatrix();


void setup()
{
        Timer1.initialize(20000);//20000->20ms bitBrick need a data every 20ms
        Timer1.attachInterrupt(bitBrickRun);
        Serial.begin(38400);

        matrix.begin(0x70);  // pass in the address
        matrix.setTextWrap(false);  // we dont want text to wrap so it scrolls nicely
        matrix.setTextSize(1);
        matrix.setTextColor(LED_GREEN);

}

void loop()
{
        ////////////////////your Code START//////////////////////////////
        int sensorValue = myBrick.get_sensor_value(1);
        int outValue = map(sensorValue, 0, 1023, 0, 8);

        matrix.clear();
        matrix.drawRect(0, 0, outValue, outValue, LED_RED);
        matrix.drawRect(outValue, outValue, 8, 8, LED_GREEN);
        
        matrix.writeDisplay();
        delay(10);
        /////////////////////your Code END//////////////////////////////
}

void bitBrickRun(void)
{
        myBrick.run();
}




