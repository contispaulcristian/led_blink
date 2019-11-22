/*
* leds.h
*
* Created: 11/15/2018 6:46:40 PM
*  Author: conti
*/


#ifndef LEDS_H_
#define LEDS_H_

#include <avr/io.h>
/******************************************************************************/
#define LED_PORT		    PORTB
/******************************************************************************/
#define LED_GREEN_PORT			    PORTB
#define	LED_GREEN_DDR				DDRB
#define LED_GREEN_PIN				PINB
#define LED_GREEN_BIT				PB5
/******************************************************************************/
#define LED_RED_PORT			    PORTB
#define LED_RED_DDR				    DDRB
#define LED_RED_PIN				    PINB
#define LED_RED_BIT				    PB4
/******************************************************************************/
#define LED_YELLOW_PORT			    PORTB
#define LED_YELLOW_DDR				DDRB
#define LED_YELLOW_PIN				PINB
#define LED_YELLOW_BIT				PB3
/******************************************************************************/
#define LED_BLUE_PORT			    PORTB
#define LED_BLUE_DDR				DDRB
#define LED_BLUE_PIN				PINB
#define LED_BLUE_BIT				PB2

/******************************************************************************/

#define LED_GREEN_OUTPUT()          LED_GREEN_DDR  |=  ( 1 << LED_GREEN_BIT )     //Set I/O as output
#define LED_GREEN_ON()		        LED_GREEN_PORT |=  ( 1 << LED_GREEN_BIT )     //Turn the LED on
#define LED_GREEN_OFF()             LED_GREEN_PORT &= ~( 1 << LED_GREEN_BIT )     //Turn the LED off
#define LED_GREEN_TOGGLE()	        LED_GREEN_PORT ^=  ( 1 << LED_GREEN_BIT )     //Toggle(Blink) LED state

/*******************************************************************************/

#define LED_RED_OUTPUT()            LED_RED_DDR  |=  ( 1 << LED_RED_BIT )
#define LED_RED_ON()	            LED_RED_PORT |=  ( 1 << LED_RED_BIT )
#define LED_RED_OFF()               LED_RED_PORT &= ~( 1 << LED_RED_BIT )
#define LED_RED_TOGGLE()	        LED_RED_PORT ^=  ( 1 << LED_RED_BIT )

/*******************************************************************************/

#define LED_YELLOW_OUTPUT()         LED_YELLOW_DDR  |=  ( 1 << LED_YELLOW_BIT )
#define LED_YELLOW_ON()		        LED_YELLOW_PORT |=  ( 1 << LED_YELLOW_BIT )
#define LED_YELLOW_OFF()            LED_YELLOW_PORT &= ~( 1 << LED_YELLOW_BIT )
#define LED_YELLOW_TOGGLE()	        LED_YELLOW_PORT ^=  ( 1 << LED_YELLOW_BIT )

/*******************************************************************************/

#define LED_BLUE_OUTPUT()           LED_BLUE_DDR  |=  ( 1 << LED_BLUE_BIT )
#define LED_BLUE_ON()		        LED_BLUE_PORT |=  ( 1 << LED_BLUE_BIT )
#define LED_BLUE_OFF()              LED_BLUE_PORT &= ~( 1 << LED_BLUE_BIT )
#define LED_BLUE_TOGGLE()	        LED_BLUE_PORT ^=  ( 1 << LED_BLUE_BIT )

/*******************************************************************************/

#define LED_ALL_TURN_OFF()	        LED_GREEN_OFF(); LED_RED_OFF(); LED_YELLOW_OFF(); LED_BLUE_OFF();
#define LED_ALL_TURN_ON()           LED_GREEN_ON(); LED_RED_ON(); LED_YELLOW_ON(); LED_BLUE_ON();

#define SETUP_LEDS()		        LED_GREEN_OUTPUT(); LED_GREEN_OFF(); \
                                    LED_RED_OUTPUT(); LED_RED_OFF(); \
                                    LED_YELLOW_OUTPUT(); LED_YELLOW_OFF(); \
                                    LED_BLUE_OUTPUT(); LED_BLUE_OFF(); \
									
/*******************************************************************************/

void all_leds_blink( void );
void blink_left_to_right( void );
void blink_right_to_left( void );
void blink_odd_vs_notOdd( void );

#endif /* LEDS_H_ */