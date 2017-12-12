/*************************************************
 * 8-bit AVR Micro-controller SPI Master Library
 * Soumil Heble
 * soumilheble@iith.ac.in
 *************************************************/

#include <spyavr.h>

/**************************
 *	SPI speed 2X bit mask	
 **************************/
#define CLK_2XMASK	0x01

void spi_init()
{
	SPIDDR |= (1<<SCK_SPY)|(1<<MOSI_SPY)|(1<<SS_SPY);	//SCK,MOSI and SS as Output
	SPIDDR &= ~(1<<MISO_SPY);	//MISO as Input
	SPIPORT |= (1<<SS_SPY);	//SS is Set High
	SPCR |= (1<<SPE)|(1<<MSTR);	//SPI Enable and Master Mode
}

void spi_mode(uint8_t spymode)
{
  spymode = (spymode<<2);
  SPCR = (SPCR & 0xF3)|spymode;	//Set SPI Mode
}

/* SPR1 SPR0 ~SPI2X Freq
    0    0     0   fosc/2
    0    0     1   fosc/4
    0    1     0   fosc/8
    0    1     1   fosc/16
    1    0     0   fosc/32
    1    0     1   fosc/64
    1    1     0   fosc/64
    1    1     1   fosc/128
*/
void spi_speed(uint8_t clkdiv)
{
	uint8_t dival=0;
	while(clkdiv!=0x00)	//Count what multiple of 2
	{
		dival++;
		clkdiv = (clkdiv>>1);
	}
	dival -= 2;	//Subtract by 2 to bring it to correct value
	SPCR = (SPCR & 0b11111100)|(dival>>1);	//Set First 2 val in the control register
	SPSR = (SPSR & 0b11111110)|(~(dival & CLK_2XMASK));	//Set SPI2X val in the status register
}

void spi_dmode(uint8_t dato)
{
	if(dato)
		SPCR |= (1<<DORD);
	else
		SPCR &= ~(1<<DORD);
}

uint8_t spi_shift(uint8_t spidata)
{
	SPDR = spidata;
	asm volatile("nop");			//From Arduino SPI Library - If fast SPI, MCU does not have to wait much - Verify This ??
	while (!(SPSR & (1<<SPIF)));	//Wait for SPI to complete data transfer
	return SPDR;
}

void spi_deinit()
{
	SPCR &= ~(1<<SPE);
	SPIPORT &= ~(1<<SS_SPY);	//SS is Set High
	SPIDDR &= ~((1<<SCK_SPY)|(1<<MOSI_SPY)|(1<<SS_SPY));	//SCK,MOSI and SS as Output
}
