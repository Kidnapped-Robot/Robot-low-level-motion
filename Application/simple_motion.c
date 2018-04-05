/*
 * header File: simple-mostion.c
 *
 *  Description: simple motion of the robot: N,W,E,S
*/

#include "simple_motion.h"


void do_action(char action) {
  if(!done){
			done=1;
			switch (action) {
				case 'N':
				if(actions[previos_action]=='S')
				rotate_left_90(2.0);
				else if(actions[previos_action]=='E')
				rotate_left_90(1.0);
				else if(actions[previos_action]=='W')
				rotate_right_90(1.0);
				break;

				case 'E':
				if(actions[previos_action]=='B')
				rotate_right_90(1.0);
				else if(actions[previos_action]=='N')
				rotate_right_90(1.0);
				else if(actions[previos_action]=='S')
				rotate_left_90(1.0);
				else if(actions[previos_action]=='W')
				rotate_right_90(2.0);
				break;

				case 'W':
				if(actions[previos_action]=='B')
				rotate_left_90(1.0);
				else if(actions[previos_action]=='N')
				rotate_left_90(1.0);
				else if(actions[previos_action]=='S')
				rotate_right_90(1.0);
				else if(actions[previos_action]=='E')
				rotate_left_90(2.0);
				break;

				case 'S':
				if(actions[previos_action]=='B')
				rotate_right_90(2.0);
				else if(actions[previos_action]=='N')
				rotate_left_90(2.0);
				else if(actions[previos_action]=='W')
				rotate_left_90(1.0);
				else if(actions[previos_action]=='E')
				rotate_right_90(2.0);
				break;

				case 'G':
				motor_stop_left();
				motor_stop_right();
				current_action++;
				previos_action++;
				return;
				break;
			}

		}

		if(distance_center_ms <= 0.30){
			move_left_forward(240);
			move_right_forward(240);
		}
		else{
			motor_stop_right();
			motor_stop_left();
			reset_ticks();
			done=0;
			distance_center_ms=0;
			current_action++;
			previos_action++;
			_delay_ms(1500);
		}

}



void rotate_right_90(float n) {
  ticks_left=0;

  while(ticks_left< 18*n){
      motor_stop_right();
      move_left_forward(220);
  }

  motor_stop_right();
  motor_stop_left();
  reset_ticks();
  _delay_ms(1500);
}



void rotate_left_90(float n) {
  ticks_right=0;

  while(ticks_right< (18.0*n)){
    		motor_stop_left();
        move_right_forward(220);
		}

		motor_stop_right();
		motor_stop_left();
		reset_ticks();
		_delay_ms(1500);
}
