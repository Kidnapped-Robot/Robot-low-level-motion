/***************************************************************
 *  Source File: PWM.h
 *
 *  Description: PWM driver for ATMEGA128
 *
 **************************************************************/

#ifndef PWM_H_
#define PWM_H_

#include "pwm_config.h"

/*************************************************
 *  API functions
 *************************************************/

void pwm_init(uint8_t);
void pwm_set_duty_value(uint8_t, uint8_t);
void pwm_set_duty_cycle(uint8_t, uint8_t);

#endif /* PWM_H_ */
