
avr-gcc -Os -DF_CPU=8000000UL -mmcu=atmega128 -c Application/main.c Application/differential_drive.c HAL/encoder.c HAL/motor.c  MCAL/pwm.c  MCAL/timer.c  MCAL/uart.c Application/simple_motion.c
avr-gcc -mmcu=atmega128 *.o -o run
avr-objcopy -O ihex -R .eeprom run run.hex
avrdude -F -V -c usbasp -p ATMEGA128 -P /dev/ttyACM0 -b 115200 -U flash:w:run.hex
