/**********************
 *  Source File: PWM.c
 *
 *  Description: PWM driver for ATMEGA128
 *
 *  -------------------------------------------------------*/

#include "pwm.h"

/*********************************************************************
* Function    : pwm_init(uint8_t timer_number);
*
* DESCRIPTION : Initializes the PWM in fast mode.
*
* PARAMETERS  : The number of 8 bit timer to set for fast mode pwm.
*               Either Timer 0 or Timer 2.
*
* Return Value: Nothing
***********************************************************************/
void pwm_init(uint8_t timer_number)
{
	switch(timer_number)
	{
	    case TIMER_2:
	    	 /* OC2 PIN TO BE OUTPUT */
	    	TIMER2_DDR |= (1<<OC2_OUTPUT_SETTER);
	    	 /*Disable Timer 2*/
	    	 TCCR2 = DISABLE_MODULE_VALUE;
	    	 /* Setting pre scaler */
	    	 TCCR2 = PRESCLR1_VALUE|(FAST_PWM)|(NON_INVERT);
	    	 /* Initializing the timer with zero */
	    	 TCNT2 = ZER0_INITIALIZER;
	         break;

	    case TIMER_0:
	    	/* OC0 PIN TO BE OUTPUT */
	    	TIMER0_DDR |= (1<<OC0_OUTPUT_SETTER);
	    	/* Disable Timer 0 */
	    	TCCR0 = DISABLE_MODULE_VALUE;
	    	/* Setting pre scaler */
	    	TCCR0 = (PRESCLR1_VALUE)|(FAST_PWM)|(NON_INVERT);
	    	/* Initializing the timer with zero */
	    	TCNT0 = ZER0_INITIALIZER;
	    	break;

	    default:
	    	 break;
	}
	return;
}

/****************************************************************************
* Function    : pwm_set_duty_value(uint8_t duty_value, uint8_t timer_number)
*
* DESCRIPTION : Sets duty cycle for the  PWM
*
* PARAMETER 1 : The duty cycle value. A value between 0 (0 %) and 255 (100 %).
*
* PARAMETER 2 : The number of 8 bit timer. Either Timer 0 or Timer 2.
*
* Return Value: Nothing
******************************************************************************/
void pwm_set_duty_value(uint8_t duty_value, uint8_t timer_number)
{

	  switch(timer_number)
	  {

	  case TIMER_2:
		  /*Output Compare Register  OCR2
		   * contains an 8-bit value that is continuously compared
		   * with the counter value (TCNT2). A match can be used to
		   * generate an output compare interrupt
		   * */
		  OCR2 = duty_value;
		  break;

	  case TIMER_0:
		  /*Output Compare Register  OCR0
		   * contains an 8-bit value that is continuously compared
		   * with the counter value (TCNT0). A match can be used to
		   * generate an output compare interrupt
		   * */
		  OCR0 = duty_value;
		  break;

	  default:
		   break;
	  }
	  return;
}

/****************************************************************************
* Function    : pwm_set_duty_cycle(uint8_t duty_cycle, uint8_t timer_number)
*
* DESCRIPTION : Sets duty cycle for the  PWM
*
* PARAMETER 1 : The duty cycle value. A value between (0 %) and (100 %).
*
* PARAMETER 2 : The number of 8 bit timer. Either Timer 0 or Timer 2.
*
* Return Value: Nothing
******************************************************************************/
void pwm_set_duty_cycle(uint8_t duty_cycle, uint8_t timer_number)
{
	  uint8_t pwm_actual_duty ;           //duty cycle is represented by a number from 0->255


	  pwm_actual_duty = (duty_cycle * TIMER_MAX_VALUE_8BIT) / DUTY_CYCLE_MAX_VALUE;
	  /*Output Compare Register OCRx
	   * contains an 8-bit value that is continuously compared
	   * with the counter value (TCNTx). A match can be used to
	   * generate an output compare interrupt
	   **/
	  switch(timer_number)
	  {

	  case TIMER_2:
		  OCR2 = pwm_actual_duty;
		  break;

	  case TIMER_0:
		  OCR0 = pwm_actual_duty;
		  break;

	  default:
		  break;
	  }
}
