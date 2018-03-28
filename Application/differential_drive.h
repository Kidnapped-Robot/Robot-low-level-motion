/*
 * header File: differential_drive.h
 *
 *  Description: IR_Encoder driver for ATMEGA128
 */



 #ifndef   DIFF_DRIVE_H_
 #define   DIFF_DRIVE_H_



 #include  <math.h>
 #include  <stdlib.h>
 #include  <avr/interrupt.h>
 #define   F_CPU 8000000UL
 #include  <util/delay.h>
 #include  "../MCAL/timer.h"
 #include  "../HAL/encoder.h"
 #include  "../HAL/motor.h"



 /*********************************************************************
  *                            CONSTANTS
  /*********************************************************************/

 #define		WHEEL_RADIUS		       ((float) ((3.2)/100.0))
 #define		N_TICKS				         ((float) 16)
 #define		PI					           ((float) 3.1415)
 #define		WHEEL_CIRCUMFERENCE	   ((float) (2*WHEEL_RADIUS*PI))
 #define		ROBOT_LENGTH		       ((float) (16.5)/100.0)
 #define    MAX_RPM	   	           ((float) 280)



 /*********************************************************************
  *                            GLOBAL VARIABLES
  /*********************************************************************/

  float x_pos;
  float y_pos;
  float angle;
  float distance_right_ms;
  float distance_left_ms;
  float distance_center_ms;
  float x_goal;
  float y_goal;



 /*********************************************************************
  *                              API functions
  /*********************************************************************/


 /*********************************************************************
 * Function    : calc_distance(void)
 *
 * DESCRIPTION : updates the current distance that the right, left wheels
                 and the center of the car has moved at a certine time
                 interval using the IR encoder as feedback.
 *
 * PARAMETERS  : Nothing.
 *
 * Return Value: Nothing.
 ***********************************************************************/
 void calc_distance(void);



 /*********************************************************************
 * Function    : calc_angle(void)
 *
 * DESCRIPTION : calculates the current angle of the car.
 *
 * PARAMETERS  : Nothing.
 *
 * Return Value: float angle: the angle between the car and the world.
 ***********************************************************************/
 float calc_angle(void);



 /*********************************************************************
 * Function    : calc_x_pos(void)
 *
 * DESCRIPTION : calculates the current X postion of the car in the world
 *               as feedback.
 *
 * PARAMETERS  : Nothing.
 *
 * Return Value: float x_pos: the x postion of the car.
 ***********************************************************************/
 float calc_x_pos(void);



 /*********************************************************************
 * Function    : calc_y_pos(void)
 *
 * DESCRIPTION : calculates the current Y postion of the car in the world
 *               as feedback.
 *
 * PARAMETERS  : Nothing.
 *
 * Return Value: float y_pos: the y postion of the car.
 ***********************************************************************/
 float clac_y_pos(void);



 /*********************************************************************
 * Function    : measure()
 *
 * DESCRIPTION : updates (x,y,angle) parameters of the robot as feedback
 *               and resets the distance moved by the car.
 *
 * PARAMETERS  : Nothing.
 *
 * Return Value: Nothing.
 ***********************************************************************/
 void measure();



 /*********************************************************************
 * Function    : uni_to_diff(float v_ms, float omega_rads)
 *
 * DESCRIPTION : uses the differential drive modul's equations to apply the
 *               control action of the P controller and map the given
 *               linear and angular velocities to Vl: left wheel velocity
 *               and Vr: right wheel velocity.
 *
 * PARAMETERS  : float v_ms: the given linear velocity in m/s.
 *               float omega_rads: the given angular velocity in rad/s
 *
 * Return Value: Nothing.
 ***********************************************************************/
 void uni_to_diff(float v_ms,float omega_rads);



 /*********************************************************************
 * Function    : go_to_goal(float x_goal, float y_goal)
 *
 * DESCRIPTION : takes (x,y) of the goal point and produces a control action
 *               using P controller in a form of Linear velocity in m/s
 *               and angular velocity in rad/s
 *
 * PARAMETERS  : Nothing.
 *
 * Return Value: (float x_goal, float ya- goal): postion of the goal in the world.
 ***********************************************************************/
 void go_to_goal(float x_goal,float y_goal);


#endif
