/*
* button.c
*
* Created: 11/15/2018 2:04:27 AM
*  Author: conti
*/


#include <avr/io.h>
#include "global.h"
#include <util/delay.h>
#include "button.h"
#include <avr/interrupt.h>
#include "main.h"

BOOL button_was_pressed = FALSE;

ISR(INT0_vect) 
{
	if((BUTTON_IS_PRESSED()) && (!button_was_pressed)) button_was_pressed = TRUE;
	if(!(BUTTON_IS_PRESSED()) && (button_was_pressed)) {
		if(state == STATE_1) state = STATE_2;
		else if(state == STATE_2) state = STATE_3;
		else if(state == STATE_3) state = STATE_4;
		else if(state == STATE_4) state = STATE_1;	
		button_was_pressed = FALSE;
	}
}




// int number = 0;





