/*
 * button.h
 *
 * Created: 11/15/2018 2:04:48 AM
 *  Author: conti
 */ 

#include <avr/io.h>
#include "avrlibtypes.h"

#ifndef BUTTON_H_
#define BUTTON_H_

/*************************************************************************/

#define BUTTON_DDR				DDRD    
#define BUTTON_PORT				PORTD	
#define BUTTON_PIN				PIND  
#define BUTTON_BIT              PD2
/*************************************************************************/

#define SETUP_BUTTON()	BUTTON_DDR &= ~(1 << BUTTON_BIT); BUTTON_PORT |= (1 << BUTTON_BIT);

#define BUTTON_IS_PRESSED()      ((BUTTON_PIN & (1 << BUTTON_BIT)) == 0)

BOOL is_button_pressed ( void );

#endif /* BUTTON_H_ */