/*
 * global.h
 *
 * Created: 12/22/2024 7:46:12 PM
 *  Author: paul.contis
 */ 


#ifndef GLOBAL_H_
#define GLOBAL_H_

// global AVRLIB defines
#include "avrlibdefs.h"
// global AVRLIB types definitions
#include "avrlibtypes.h"

// project/system dependent defines

// CPU clock speed
#define F_CPU        16000000               		// 16MHz processor
//#define F_CPU        14745000               		// 14.745MHz processor
//#define F_CPU        8000000               		// 8MHz processor
//#define F_CPU        7372800               		// 7.37MHz processor
//#define F_CPU        4000000               		// 4MHz processor
//#define F_CPU        3686400               		// 3.69MHz processor
//#define F_CPU        8000000               		// 1MHz processor
#define CYCLES_PER_US ((F_CPU+500000)/1000000) 	// cpu cycles per microsecond

#define USART_BAUD 9600


#endif /* GLOBAL_H_ */