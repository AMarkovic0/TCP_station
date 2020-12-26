#ifndef _GPIO_DRIVER_H_
#define _GPIO_DRIVER_H_

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

#include"tcp_server.h"
#include"device.h"

#define NUM_OF_PINS 9

typedef enum gpio_states{ GPIO_NONE , GPIO_OUT , GPIO_IN };
typedef enum gpio_values{ GPIO_ON , GPIO_OFF };

typedef struct gpio
{
	uint8_t gpio_state[ NUM_OF_PINS ];
	uint8_t gpio_value[ NUM_OF_PINS ];
	_client_dev* device;
}_gpio;

int gpio_handshake( _gpio* gpio_device );
int gpio_heartbeat( _gpio gpio_device , int min_beats );

int gpio_pin16_out( _gpio* gpio_dev );
int gpio_pin16_in( _gpio* gpio_dev );
int gpio_pin16_on( _gpio* gpio_dev );
int gpio_pin16_off( _gpio* gpio_dev );
int gpio_pin16_toggle( _gpio* gpio_dev );

/////////////////////////////////////////////////

int gpio_pin0_out( _gpio* gpio_dev );
int gpio_pin0_in( _gpio* gpio_dev );
int gpio_pin0_on( _gpio* gpio_dev );
int gpio_pin0_off( _gpio* gpio_dev );
int gpio_pin0_toggle( _gpio* gpio_dev );

/////////////////////////////////////////////////

int gpio_pin2_out( _gpio* gpio_dev );
int gpio_pin2_in( _gpio* gpio_dev );
int gpio_pin2_on( _gpio* gpio_dev );
int gpio_pin2_off( _gpio* gpio_dev );
int gpio_pin2_toggle( _gpio* gpio_dev );

/////////////////////////////////////////////////

int gpio_pin4_out( _gpio* gpio_dev );
int gpio_pin4_in( _gpio* gpio_dev );
int gpio_pin4_on( _gpio* gpio_dev );
int gpio_pin4_off( _gpio* gpio_dev );
int gpio_pin4_toggle( _gpio* gpio_dev );

/////////////////////////////////////////////////

int gpio_pin5_out( _gpio* gpio_dev );
int gpio_pin5_in( _gpio* gpio_dev );
int gpio_pin5_on( _gpio* gpio_dev );
int gpio_pin5_off( _gpio* gpio_dev );
int gpio_pin5_toggle( _gpio* gpio_dev );

/////////////////////////////////////////////////

int gpio_pin12_out( _gpio* gpio_dev );
int gpio_pin12_in( _gpio* gpio_dev );
int gpio_pin12_on( _gpio* gpio_dev );
int gpio_pin12_off( _gpio* gpio_dev );
int gpio_pin12_toggle( _gpio* gpio_dev );

/////////////////////////////////////////////////

int gpio_pin13_out( _gpio* gpio_dev );
int gpio_pin13_in( _gpio* gpio_dev );
int gpio_pin13_on( _gpio* gpio_dev );
int gpio_pin13_off( _gpio* gpio_dev );
int gpio_pin13_toggle( _gpio* gpio_dev );

/////////////////////////////////////////////////

int gpio_pin14_out( _gpio* gpio_dev );
int gpio_pin14_in( _gpio* gpio_dev );
int gpio_pin14_on( _gpio* gpio_dev );
int gpio_pin14_off( _gpio* gpio_dev );
int gpio_pin14_toggle( _gpio* gpio_dev );

/////////////////////////////////////////////////

int gpio_pin15_out( _gpio* gpio_dev );
int gpio_pin15_in( _gpio* gpio_dev );
int gpio_pin15_on( _gpio* gpio_dev );
int gpio_pin15_off( _gpio* gpio_dev );
int gpio_pin15_toggle( _gpio* gpio_dev );

/////////////////////////////////////////////////

#endif //_GPIO_DRIVER_H_
