/*************************************************
 * 8-bit AVR Micro-controller UART Library v2
 * Soumil Heble
 * soumilheble@iith.ac.in
 *************************************************/
 
#ifndef _SERIALAVR_H_
#define _SERIALAVR_H_

#include <avr/io.h>
#include <avr/interrupt.h>

/*
#ifndef F_CPU
#define F_CPU 16000000
#endif
*/

//#define BAUD		9600
#define UBRR_VALUE	F_CPU/16/BAUD-1

void init_uart(void);
void uart_write(uint8_t data);
void uart_print(char* prnb);
void uart_println(char* prnb);
void uart_print8(uint8_t prneb);
uint8_t uart_read(void);

#endif