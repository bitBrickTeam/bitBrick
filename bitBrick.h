/*
        bitBrick to Arduino shield
        Created by hellogeeks, bitBrick Team
        2016.09.30.
        www.bitbrick.cc
        info@hellogeeks.kr
*/

#ifndef bitBrick_h
#define bitBrick_h

#include "Arduino.h"

//#include <avr/interrupt.h>



#define        BUZZER  12
#define        A        5
#define        B        6
#define        C        7
#define        D        8
#define        LED_R    9
#define        LED_G   10
#define        LED_B   11

#define        CW        1
#define        CCW       0

#define        ON        1
#define        OFF       0


#define        red      1
#define        green    2
#define        blue     3
#define        orange   4
#define        yellow   5
#define        pink     6
#define        skyblue  7
#define        navy     8
#define        purple   9
#define        white    0


class bitBrick
{


	//extern volatile unsigned long count;
	
  public:
  
    bitBrick();

	void set_led_off();
	void set_led_rgb(int r, int g, int b);
	void set_led_num(int value);
	void set_led_color(int value);
	void set_buzzer_num(int value);
	void get_module_check(int port);
	void set_dc_motor_velocity(int port_a ,  int velocity);
	void set_dc_motor_dir_speed(int port_a , int dir, int spdd);
	void set_servo_motor(int port_a , int angle);
	void set_motor_all_stop();
	void data_in();
	
	void data_parsing();
	unsigned int get_sensor_value(int port);
	void data_in_set();
	void data_out_set();
	void data_out();
	
	void run();
	
	
  //static:
  public:
//	static unsigned char clockSelectBits;

	int getData[20];
	int sendData[20];

	int port[13];


	long tempData[4];
	long sensor_port[5];

	long tempDataL[4];
	long tempDataH[4];


};

#endif

