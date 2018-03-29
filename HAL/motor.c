#include "motor.h"


 void motor_init()
 {

   RIGHT_MOTOR_DDR |= (1<<RIGHT_MOTOR_DIR0);
   RIGHT_MOTOR_DDR |= (1<<RIGHT_MOTOR_DIR1);
   LEFT_MOTOR_DDR  |= (1<<LEFT_MOTOR_DIR0);
   LEFT_MOTOR_DDR  |= (1<<LEFT_MOTOR_DIR0);

  pwm_init(TIMER_0);
  pwm_init(TIMER_2);

 }



 void move_right_forward(float v_right_rpm)
 {
	 float speed_perc=0;

   RIGHT_MOTOR_PORT |= (1<<RIGHT_MOTOR_DIR1);
	 RIGHT_MOTOR_PORT &= (~(1<<RIGHT_MOTOR_DIR0));

	 speed_perc=(v_right_rpm*100.0)/MAX_RPM;
	 speed_perc=((speed_perc*(40.0))/100.0)+60.0;

	 if(speed_perc>100)
		     speed_perc=100;

	 pwm_set_duty_cycle( (uint8_t)speed_perc, TIMER_2);
 }



void move_left_forward(float v_left_rpm)
{
	float speed_perc=0;

  LEFT_MOTOR_PORT |= (1<<LEFT_MOTOR_DIR0);
	LEFT_MOTOR_PORT &= (~(1<<LEFT_MOTOR_DIR1));

	speed_perc=(v_left_rpm*100.0)/MAX_RPM;
	speed_perc=((speed_perc*40.0)/100.0)+60.0;

	if(speed_perc>100)
		  speed_perc=100;

	pwm_set_duty_cycle((uint8_t) speed_perc, TIMER_0);
}



  void move_right_backward(float v_right_rpm)
  {
	   float speed_perc=0;

     RIGHT_MOTOR_PORT |= (1<<RIGHT_MOTOR_DIR0);
	   RIGHT_MOTOR_PORT &= (~(1<<RIGHT_MOTOR_DIR1));

	   speed_perc=(v_right_rpm*100.0)/MAX_RPM;
	   speed_perc=((speed_perc*40.0)/100)+60.0;

	   if(speed_perc>100)
			  speed_perc=100;

	   pwm_set_duty_cycle( (uint8_t)speed_perc, TIMER_2);
  }



void move_left_backward(float v_left_rpm)
{
	float speed_perc=0;

  LEFT_MOTOR_PORT |= (1<<LEFT_MOTOR_DIR1);
	LEFT_MOTOR_PORT &= (~(1<<LEFT_MOTOR_DIR0));

	speed_perc=(v_left_rpm*100.0)/MAX_RPM;
	speed_perc=((speed_perc*40.0)/100.0)+60.0;

	if(speed_perc>100)
		  speed_perc=100;

	pwm_set_duty_cycle((uint8_t) speed_perc, TIMER_0);

}



 void motor_stop_right()
 {
	 RIGHT_MOTOR_PORT |= (1<<RIGHT_MOTOR_DIR0);
   RIGHT_MOTOR_PORT |=(1<<RIGHT_MOTOR_DIR0);
 }



 void motor_stop_left()
 {
   LEFT_MOTOR_PORT |= (1<<LEFT_MOTOR_DIR0);
   LEFT_MOTOR_PORT |= (1<<LEFT_MOTOR_DIR1);
 }
