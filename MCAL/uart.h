/***************************************************************
 *  header File: uart.h
 *
 *  Description: UART0 and UART1 driver for ATMEGA128
 *
 **************************************************************/


#ifndef UART_H_
#define UART_H_

#include <avr/io.h>
#include "uart_config.h"
#include <math.h>

#define BAUD_RATE ((FOSC)/(BAUD*16UL)-1) // Eqn to calculate BuadRate



/*********************************************************************
* Function    : uart_init(uint8_t UART));
*
* DESCRIPTION : Initializeing both UART0 and UART1
*
* PARAMETERS  : uint8_t UART number of the UART channel
*               UART0 or UART1
*
* Return Value: Nothing
***********************************************************************/
void uart_init(uint8_t UART);



/*********************************************************************
* Function    : uart_transmit(uint8_t data, uint8_t UART);
*
* DESCRIPTION : transmit data to the wanted channel
*
* PARAMETERS  :uint8_t data, uint8_t UART: Number of UART channel
*
* Return Value: Nothing
***********************************************************************/
void uart_transmit(uint8_t data, uint8_t UART);



/*********************************************************************
* Function    : uart_receive(uint8_t UART);
*
* DESCRIPTION : recieve data into UDRn register
*
* PARAMETERS  : uint8_t UART: Number of UART channel
*
* Return Value: UDR register value
***********************************************************************/
uint8_t uart_receive(uint8_t UART);



/*********************************************************************
* Function    : UART_Transmit_string (uint8_t* str, uint8_t UART);
*
* DESCRIPTION : transmit string
*
* PARAMETERS  : uint8_t* str, uint8_t UART: Number of UART channel
*
* Return Value: Nothing
***********************************************************************/
void UART_Transmit_string (char * str,uint8_t UART);



/*********************************************************************
* Function    : uart_receive_string (uint8_t UART);
*
* DESCRIPTION : receiving a string through UART0 or UART1 channels
*
* PARAMETERS  : uint8_t UART: Number of UART channel
*
* Return Value: uint8_t* str
***********************************************************************/
uint8_t * uart_receive_string(uint8_t UART)


#endif /* UART_H_ */
