/*
 * header File: encoder.h
 *
 *  Description: IR_Encoder driver for ATMEGA128
 */

#ifndef ENCODER_H_
#define ENCODER_H_

#include <avr/io.h>
#include <avr/interrupt.h>



/*********************************************************************
 *                            GLOBAL VARIABLES
 /*********************************************************************/
float ticks_right;
float ticks_left;



/*********************************************************************
 *                              API functions
 /*********************************************************************/


 /*********************************************************************
 * Function    : encoder_init(void);
 *
 * DESCRIPTION : Initializes the Encoder.
 *
 * PARAMETERS  : Nothing.
 *
 * Return Value: Nothing
 ***********************************************************************/

void encoder_init(void);



/*********************************************************************
* Function    : ex_interrupt_init(void);
*
* DESCRIPTION : Initializes the Encoder.
*
* PARAMETERS  : Nothing.
*
* Return Value: Nothing
***********************************************************************/
void ex_interrupt_init(void);



/*********************************************************************
* Function    : reset_ticks(void);
*
* DESCRIPTION : Restes encoders' counters.
*
* PARAMETERS  : Nothing.
*
* Return Value: Nothing
***********************************************************************/
void reset_ticks(void);



#endif /* MOTOR_H_ */
