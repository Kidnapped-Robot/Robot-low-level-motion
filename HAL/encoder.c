#include "motor.h"



  void encoder_init(void){

    ex_interrupt_init();
    
  }



 	void ex_interrupt_init(void){
		//The rising edge of INTn generates asynchronously an interrupt request on INT6
		EICRB |= (1<<ISC61)|(1<<ISC60);;
    //The rising edge of INTn generates asynchronously an interrupt request on INT7
    EICRB |= (1<<ISC71)|(1<<ISC70);
    //Enable INT6 and INT7
		EIMSK |= (1<<INT6)|(1<<INT7);
	}



	ISR(INT6_vect){

  	ticks_left++;
	}

	ISR(INT7_vect){

  	ticks_right++;

  	}
