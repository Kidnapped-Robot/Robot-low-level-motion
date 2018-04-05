/*
 * header File: simple_motion.h
 *
 *  Description: simple_motion.c header file
 */

 #ifndef   SIMPLE_MOTION_H_
 #define   SIMPLE_MOTION_H_

 #include "../HAL/motor.h"
 #include "../HAL/encoder.h"
 #define   F_CPU 8000000UL
 #include  <util/delay.h>



 /*********************************************************************
 *                            GLOBAL VARIABLES
/*********************************************************************/

 char actions[100]; 
 int no_of_actions;
 int current_action;
 int previos_action;
 int  done;


/*********************************************************************
  *                              API functions
/*********************************************************************/


 /*********************************************************************
 * Function    : do_action(char action)
 *
 * DESCRIPTION : applies the action given to it.
                actions could be to move north,south, east,west
 *
 * PARAMETERS  : Nothing.
 *
 * Return Value: Nothing.
 ***********************************************************************/

void do_action(char action);



/*********************************************************************
* Function    : rotate_right_90(float n)
*
* DESCRIPTION : rotates the robot (n*90) degrees to the right
*
* PARAMETERS  : float n: rotation scaler 90*n.
*
* Return Value: Nothing.
***********************************************************************/

void rotate_right_90(float n);



/*********************************************************************
* Function    : rotate_left_90(float n)
*
* DESCRIPTION : rotates the robot (n*90) degrees to the left
*
* PARAMETERS  :float n: rotation scaler 90*n.
*
* Return Value: Nothing.
***********************************************************************/

void rotate_left_90(float n);

 #endif
