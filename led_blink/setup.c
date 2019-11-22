/*
 * setup.c
 *
 * Created: 11/17/2018 4:05:39 PM
 *  Author: conti
 */ 
#include <avr/io.h>
#include "button.h"
#include "leds.h"
#include <avr/interrupt.h>
#include "main_helper.h"

void setup() {
	SETUP_BUTTON();
	SETUP_LEDS();
	
	EICRA |= (1 << ISC00) ; // ANYLOGIC edge for INT0
	EIMSK  |= (1 << INT0 ) ;
	sei();
	
	prepare_leds_shift_format();
}

