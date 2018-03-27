/***************************************************************
 *  Source File: timer_config.h
 *
 *  Description: Timer driver configuration for ATMEGA128
 *
 **************************************************************/
#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_
#include <avr/io.h>


#define FAST_PWM						        (1<<3)|(1<<6)
#define NON_INVERT						      (1<<5)
#define PRESCLR1_VALUE 		            0x01
#define PRESCLR8_VALUE 		            0x02
#define PRESCLR64_VALUE 	            0x03
#define PRESCLR256_VALUE 	            0x04
#define PRESCLR1024_VALUE 	          0x05
#define DISABLE_MODULE_VALUE 		      0x00
/* Timer DDR */
#define TIMER0_DDR						        DDRB
#define TIMER2_DDR					         	DDRB

#define TIMER_0                         0
#define TIMER_2                         2
/* Out compare pin */
#define OC0_OUTPUT_SETTER               4
#define OC2_OUTPUT_SETTER               7

#define ZER0_INITIALIZER                0x00
/* Max counts of timer0 and timer2 is 2^8=255 */
#define TIMER_MAX_VALUE_8BIT            255
/* Max counts of timer1 is 2^16=65536 */
#define TIMER_MAX_VALUE_16BIT
/* max Percentage Value (100%) */
#define DUTY_CYCLE_MAX_VALUE            100


#endif /* TIMER_CONFIG_H_  */
