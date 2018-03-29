/*
 * Source File: differential_drive.c
 *
 *  Description: contains functions implementation of the differential drive module
 */

#include "differential_drive.h"


void calc_distance(void) {
  distance_right_ms = WHEEL_CIRCUMFERENCE*(ticks_right/N_TICKS);
  distance_left_ms  = WHEEL_CIRCUMFERENCE*(ticks_left/N_TICKS);
  distance_center_ms = (distance_left_ms+distance_right_ms)/2;
}



float calc_x_pos(void) {

  return (x_pos+(distance_center_ms*cos(angle)));
}



float clac_y_pos(void) {

  return (y_pos+(distance_center_ms*sin(angle)));
}



float calc_angle(void) {

  return(angle+(distance_right_ms-distance_left_ms)/ROBOT_LENGTH);
}



void measure(void) {
  calc_distance();
  x_pos=calc_x_pos();
  y_pos=clac_y_pos();
  angle=calc_angle();

  // mapping thr angle to [-PI,PI]
  if(angle>PI)
    angle-=2*PI;
  if(angle<(-PI))
    angle+=2*PI;
  //Rintialize the variables
  ticks_left=0;
  ticks_right=0;
  distance_left_ms=0;
  distance_right_ms=0;
  distance_center_ms=0;
}



void go_to_goal(float x_goal,float y_goal) {
  float goal_angle_rad, error_angle_rad,distance_to_goal;
  float v_ms,omega_rads,k_gain_v=.7,k_gain_omega=.4;
  float epsilon=0.01;

  move_left_forward(0);
  move_right_forward(0);

  goal_angle_rad=atan2((y_goal-y_pos),(x_goal-x_pos) );
  error_angle_rad=goal_angle_rad-angle;
  //error_angle_rad=atan(sin(error_angle_rad)/cos(error_angle_rad));
  if(error_angle_rad>PI)
    error_angle_rad-=(2*PI);
  if(error_angle_rad<-PI)
    error_angle_rad+=(2*PI);


  if((abs(error_angle_rad) <= epsilon)) //Linear motion
  {
    distance_to_goal=sqrt( ( (x_goal-x_pos) * (x_goal-x_pos) ) + ( (y_goal-y_pos) * (y_goal-y_pos) ) );
    v_ms=k_gain_v*distance_to_goal;
    uni_to_diff(v_ms,0);
  }
  else //Rotational motion
  {
    omega_rads=k_gain_omega*error_angle_rad;
    uni_to_diff(0,omega_rads);
  }

}



void uni_to_diff(float v_ms,float omega_rads){
  float v_right_rf_ms=0;
  float v_left_rf_ms=0;

  v_right_rf_ms=(v_ms+((ROBOT_LENGTH/2.0)*omega_rads));
  v_left_rf_ms =(v_ms-((ROBOT_LENGTH/2.0)*omega_rads));
  //v_right_rf_ms=((2*v_ms+omega*ROBOT_LENGTH)/(2*WHEEL_RADIUS));
  //v_right_rf_ms=((2*v_ms-omega*ROBOT_LENGTH)/(2*WHEEL_RADIUS));

  if(v_right_rf_ms <= 0.0)
  {
    move_right_backward(abs((v_right_rf_ms/WHEEL_CIRCUMFERENCE)*60));
  }
  else{
    move_right_forward(abs((v_right_rf_ms/WHEEL_CIRCUMFERENCE)*60));
  }

  if(v_left_rf_ms <= 0.0){
    move_left_backward(abs((v_left_rf_ms/WHEEL_CIRCUMFERENCE)*60));
  }
  else{
    move_left_forward(abs((v_left_rf_ms/WHEEL_CIRCUMFERENCE)*60));
  }

}



ISR(TIMER1_OVF_vect) {
  TCNT1=64364;
  //measure();
  //go_to_goal(x_goal,y_goal);
  //temp_ticks_right=ticks_right-temp_ticks_right;
  //temp_ticks_left=ticks_left-temp_ticks_left;
  //v_right_feedback_rpm = (ticks_right/16)*60;//*(2*WHEEL_RADIUS*PI));
  //v_left_feedback_rpm  = (ticks_left/16)*60;//(2*WHEEL_RADIUS*PI));
  //ticks_left=0;
  //ticks_right=0;
}
