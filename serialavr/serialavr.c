/*************************************************
 * 8-bit AVR Micro-controller UART Library v2
 * Soumil Heble
 * soumilheble@iith.ac.in
 *************************************************/

#include "serialavr.h"

void init_uart(void)
{
	uint8_t OldSREG = SREG;
	cli();
	UBRR0H = (UBRR_VALUE)>>8 & 0x0F;
	UBRR0L = (UBRR_VALUE) & 0xFF;
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	UCSR0B &= ~(1<<UCSZ02);
	UCSR0C &= ~((1<<UMSEL01)|(1<<UMSEL00)|(1<<USBS0));
	UCSR0C |= ((1<<UCSZ01)|(1<<UCSZ00));
	SREG = OldSREG;	
}

void uart_write(uint8_t data)
{
	while(!(UCSR0A & (1<<UDRE0)));
	UDR0 = data;
}

void uart_print(char* prnb)
{
  while(*prnb)
  {
    uart_write(*prnb);
    prnb++;
  }
}

void uart_println(char* prnb)
{
  uart_print(prnb);
  uart_write('\r');
  uart_write('\n');
}

void uart_print8(uint8_t prneb)
{
  uint8_t pbuf[3];
  uint8_t count = 0;
  while(prneb)
  {
    pbuf[count] = '0' + (prneb%10);
    prneb = prneb/10;
    count++;
  }
  while(count)
  {
    count--;
    uart_write(pbuf[count]);
  }
}

uint8_t uart_read(void)
{
	while(!(UCSR0A & (1<<RXC0)));
	return UDR0;
}