/*
* main_helper.c
*
* Created: 11/15/2018 6:44:26 PM
*  Author: conti
*/

#include <avr/io.h>
#include "global.h"
#include <util/delay.h>
#include "leds.h"
#include "main.h"

uint8_t shift_format_for_leds = 0x00;

/**************************************************************************/
void prepare_leds_shift_format() {
	shift_format_for_leds = 0x00;
	shift_format_for_leds |= (1 << LED_BLUE_BIT);
}

void shift_next_led() {
	shift_format_for_leds <<=1;
	LED_PORT |= shift_format_for_leds;
}

void shift_prev_led()  {
	shift_format_for_leds >>=1;
	LED_PORT |= shift_format_for_leds;
}

void go_to_the_end_shift_format() {
	prepare_leds_shift_format();
	shift_format_for_leds <<= 4;
}

void go_to_the_start_shift_format() {
	prepare_leds_shift_format();
	shift_format_for_leds >>=1;
}
/**************************************************************************/
void all_leds_blink()
{
	LED_ALL_TURN_ON();
	_delay_ms(200);
	LED_ALL_TURN_OFF();
	_delay_ms(200);
}
/**************************************************************************/
void blink_left_to_right()
{
	go_to_the_end_shift_format();
	for(uint8_t i = 0; i < 4;i++) {
		shift_prev_led(); _delay_ms(200);
	}
	LED_ALL_TURN_OFF();
	_delay_ms(200);
}
/**************************************************************************/
void blink_right_to_left()
{
	go_to_the_start_shift_format();
	for(uint8_t i = 0; i < 4;i++) {
		shift_next_led(); _delay_ms(200);
	}
	LED_ALL_TURN_OFF();
	_delay_ms(200);
}
/**************************************************************************/
void blink_odd_vs_notOdd()
{
	LED_ALL_TURN_OFF();
	shift_format_for_leds = 0x00;
	shift_format_for_leds |= (1 << LED_GREEN_BIT) | (1 << LED_YELLOW_BIT);
	LED_PORT |= shift_format_for_leds; _delay_ms(200);
	LED_ALL_TURN_OFF(); _delay_ms(200);
	
	shift_format_for_leds = 0x00;
	shift_format_for_leds |= (1 << LED_RED_BIT) | (1 << LED_BLUE_BIT);
	LED_PORT |= shift_format_for_leds; _delay_ms(200);
	LED_ALL_TURN_OFF(); _delay_ms(200);
	prepare_leds_shift_format();
}

