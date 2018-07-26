/*
        bitBrick to Arduino shield
        Created by hellogeeks, bitBrick Team
        2016.09.30.
        www.bitbrick.cc
        info@hellogeeks.kr
*/

#include "Arduino.h"
#include "bitBrick.h"


bitBrick::bitBrick()
{
	/*
	TCCR1A = 0x00;
	TCCR1B = 0x0C;
	TCCR1C = 0x00;
	OCR1AH = ( 2249 & 0xFF00 ) >> 8 ;//(16Mhz /250/want )- 1 = 1250 -1 
	OCR1AL =  2249 & 0xFF ;

//        OCR1AH =  31249  >> 8 ;
//        OCR1AL =  31249 & 0xFF ;
	TIMSK1 = 0x02;
	TIFR1 = 0x00;
	sei();
*/
	
	Serial1.begin(38400);


}


void bitBrick::set_led_off()
{
	port[LED_R] = 0; port[LED_G] = 0; port[LED_B] = 0;
}


void bitBrick::set_led_rgb(int r, int g, int b)
{
	port[LED_R] = r;
	port[LED_G] = g;
	port[LED_B] = b;
}


void bitBrick::set_led_num(int value)
{
	int tempColorR, tempColorG, tempColorB;
	if (value <= 66)
	{
		tempColorR = map(value, 0, 66, 255, 0);
		tempColorR = constrain(tempColorR, 0, 255);
		tempColorG = map(value, 0, 66, 0, 255);
		tempColorG = constrain(tempColorG, 0, 255);

	}
	else if (value <= 133)
	{
		tempColorG = map(value, 67, 133, 255, 0);
		tempColorG = constrain(tempColorG, 0, 255);
		tempColorB = map(value, 67, 133, 0, 255);
		tempColorB = constrain(tempColorB, 0, 255);

	}
	else
	{
		tempColorB = map(value, 134, 200, 255, 0);
		tempColorB = constrain(tempColorB, 0, 255);
		tempColorR = map(value, 134, 255, 0, 255);
		tempColorR = constrain(tempColorR, 0, 255);
	}
	
	port[LED_R] = tempColorR;
	port[LED_G] = tempColorG;
	port[LED_B] = tempColorB;
}

void bitBrick::set_led_color(int value)
{       //red, green, blue, orage, yellow, pink, skyblue, navy, purple, white
	if (value == 1)
	{
		port[LED_R] = 255;      port[LED_G] = 0;     port[LED_B] = 0;
	}
	else if (value == 2)
	{
		port[LED_R] = 0;      port[LED_G] = 255;     port[LED_B] = 0;
	}
	else if (value == 3)
	{
		port[LED_R] = 0;      port[LED_G] = 0;     port[LED_B] = 255;
	}
	else if (value == 4)
	{
		port[LED_R] = 255;      port[LED_G] = 100;     port[LED_B] = 0;
	}
	else if (value == 5)
	{
		port[LED_R] = 255;      port[LED_G] = 150;     port[LED_B] = 0;
	}
	else if (value == 6)
	{
		port[LED_R] = 255;      port[LED_G] = 0;     port[LED_B] = 255;
	}
	else if (value == 7)
	{
		port[LED_R] = 0;      port[LED_G] = 255;     port[LED_B] = 100;
	}
	else if (value == 8)
	{
		port[LED_R] = 0;      port[LED_G] = 0;     port[LED_B] = 50;
	}
	else if (value == 9)
	{
		port[LED_R] = 100;      port[LED_G] = 0;     port[LED_B] = 255;
	}
	else if (value == 0)
	{
		port[LED_R] = 255;      port[LED_G] = 255;     port[LED_B] = 255;
	}
        
}


void bitBrick::set_buzzer_num(int value)
{
	if (value > 96)    value = 96;
	port[BUZZER] = value;
}

void bitBrick::get_module_check(int port)
{

}

void bitBrick::set_dc_motor_velocity(int port_a ,  int velocity)
{
	//if((velocity>-5)&&(velocity<5))port[port_a]=0;
	//else
	port[port_a] = 128 + velocity;
}
void bitBrick::set_dc_motor_dir_speed(int port_a , int dir, int spdd)
{
	if (dir == 0)
		port[port_a] = 128 - spdd;
	else
		port[port_a] = 128 + spdd;
}

void bitBrick::set_servo_motor(int port_a , int angle)
{
	port[port_a] = angle;
}

void bitBrick::set_motor_all_stop()
{
	for(int i = 0;i<4;i++)
	{//19 servo
		if (getData[10+i] == 19)  port[i+5] = 181;
		else                    port[i+5] = 0;
	}
}

void bitBrick::data_in()
{
	if (Serial1.available() > 17)
	{
		for (int i = 0 ; i < 17; i++)
		{
			getData[i] = Serial1.read();
		}
	}
}

void bitBrick::data_parsing()
{
	for (int i = 0; i < 4; i++)
	{
		tempDataL[i] = getData[i * 2 + 3];
		tempDataH[i] = ((getData[i * 2 + 2 ] & 0x0003) << 8) & 0xFF00;
		tempData[i] = tempDataL[i] + tempDataH[i];
		sensor_port[i + 1] = tempData[i];
	}
}


unsigned int bitBrick::get_sensor_value(int port)
{
	return sensor_port[port];
}


void bitBrick::data_in_set()
{

}

void bitBrick::data_out_set()
{

}

void bitBrick::data_out()
{
	Serial1.write(255);
	Serial1.write(255);
	Serial1.write(0);
	Serial1.write(port[BUZZER]);//random(0,5));//buzzer
	Serial1.write(0);
	//        Serial1.write(port[A]);
	if (getData[10] == 19)        Serial1.write(181 - port[A]); //if the servo connected data will convert
	else                       Serial1.write(port[A]);//port 1 Data
	Serial1.write(0);
	//        Serial1.write(port[B]);
	if (getData[11] == 19)        Serial1.write(181 - port[B]); //if the servo connected data will convert
	else                       Serial1.write(port[B]);//port 2 Data
	Serial1.write(0);
	//        Serial1.write(port[C]);
	if (getData[12] == 19)        Serial1.write(181 - port[C]); //if the servo connected data will convert
	else                       Serial1.write(port[C]);//port 3 Data
	Serial1.write(0);
	//        Serial1.write(port[D]);
	if (getData[13] == 19)        Serial1.write(181 - port[D]); //if the servo connected data will convert
	else                       Serial1.write(port[D]);//port 3 Data
	Serial1.write(0);
	Serial1.write(port[LED_R]);//red
	Serial1.write(0);
	Serial1.write(port[LED_G]);//green
	Serial1.write(0);
	Serial1.write(port[LED_B]);//blue
	Serial1.write(254);
	Serial1.write(254);
}

void bitBrick::run()
{
	bitBrick::data_out();
	//delay(20);
	bitBrick::data_in();
	bitBrick::data_parsing();
}

