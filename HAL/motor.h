/*
 * Source File: motor.h
 *
 *  Description: Motor driver for ATMEGA128
 */

#ifndef MOTOR_H_
#define MOTOR_H_


#include <avr/io.h>
#include "pwm.h"



/*************************************************
 *  CONSTANTS
 *************************************************/
#define   RIGHT_MOTOR_DDR        DDRD
#define   RIGHT_MOTOR_PORT       PORTD
#define   RIGHT_MOTOR_DIR0       4
#define   RIGHT_MOTOR_DIR1       5
#define   LEFT_MOTOR_DDR        DDRD
#define   LEFT_MOTOR_PORT       PORTD
#define   LEFT_MOTOR_DIR0        6
#define   LEFT_MOTOR_DIR1        7



/*********************************************************************
 *  API functions
 /*********************************************************************



 /*********************************************************************
 * Function    : motor_init()
 *
 * DESCRIPTION : Initializes the motor direction pins.
 *
 * PARAMETERS  : Nothing.
 *
 * Return Value: Nothing.
 ***********************************************************************/
void motor_init();



/*********************************************************************
* Function    : move_right_forward(float);
*
* DESCRIPTION : moves the right motor forward with a given speed (RPM)
*               using PWM on TIMER2 mapping it from 60 to 100 % duty cycle.
*
* PARAMETERS  : float v_right_rpm: the speed in RPM.
*
* Return Value: Nothing
***********************************************************************/
void move_right_forward(float);




/*********************************************************************
* Function    : move_left_forward(float);
*
* DESCRIPTION : moves the left motor forward with a given speed (RPM)
*               using PWM on TIMER0 mapping it from 60 to 100 % duty cycle.
*
* PARAMETERS  : float v_left_rpm: the speed in RPM.
*
* Return Value: Nothing
***********************************************************************/
void move_left_forward(float);



/*********************************************************************
* Function    : move_right_backward(float);
*
* DESCRIPTION : moves the left motor backward with a given speed (RPM)
*               using PWM on TIMER2 mapping it from 60 to 100 % duty cycle.
*
* PARAMETERS  : float v_right_rpm: the speed in RPM.
*
* Return Value: Nothing
***********************************************************************/
void move_right_backward(float);



/*********************************************************************
* Function    : move_left_backward(float);
*
* DESCRIPTION : moves the left motor backward with a given speed (RPM)
*               using PWM on TIMER0 mapping it from 60 to 100 % duty cycle.
*
* PARAMETERS  : float v_left_rpm: the speed in RPM.
*
* Return Value: Nothing
***********************************************************************/
void move_left_backward(float);



/*********************************************************************
* Function    : motor_stop_left(void);
*
* DESCRIPTION : Stopping the left motor.
*
* PARAMETERS  : Nothing.
*
* Return Value: Nothing
***********************************************************************/
void motor_stop_left();



/*********************************************************************
* Function    : motor_stop_right(void);
*
* DESCRIPTION : Stopping the right motor.
*
* PARAMETERS  : Nothing.
*
* Return Value: Nothing
***********************************************************************/
void motor_stop_right();



#endif /* MOTOR_H_ */
