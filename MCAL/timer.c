  /***************************************************************
 *  Source File: timer.c
 *
 *  Description: Timer1 driver for ATMEGA128
 *
 **************************************************************/
#include "timer.h"


/*********************************************************************
* Function    : timer1_init(void);
*
* DESCRIPTION : Initializes Timer1 with 1024 prescaler.
*
* PARAMETERS  : Nothing.
*
* Return Value: Nothing.
***********************************************************************/
void timer1_init(void)
{
	    	/* Disable Timer 1 */
	    	TCCR1B = DISABLE_MODULE_VALUE;
	    	/* Setting pre scaler */
	    	TCCR1B = (PRESCLR1024_VALUE);
	    	/* Initializing the timer with zero */
	    	TCNT1 = ZER0_INITIALIZER;
			  /* Enabling Timer1 overflow interrupt*/
			  TIMSK |=(1<<TOIE1);

	return;
}
