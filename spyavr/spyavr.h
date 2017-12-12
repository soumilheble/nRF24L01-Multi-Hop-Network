/*************************************************
 * 8-bit AVR Micro-controller SPI Master Library
 * Soumil Heble
 * soumilheble@iith.ac.in
 *************************************************/ 

#ifndef _SPYAVR_H_
#define _SPYAVR_H_

/*******************************************
 *	AVR IO Library required for MCU macros	
 *******************************************/
#include <avr/io.h>

/********************************************************************
 *	AVR DDR, PORT letter for SPI and pin number for MOSI, SS and SCK	
 ********************************************************************/
#define SPIDDR		DDRB
#define SPIPORT		PORTB
#define MOSI_SPY	3
#define MISO_SPY	4
#define SCK_SPY		5
#define SS_SPY		2

/******************************************************************
 *	SPI Initialization
 *	Sets pin direction for MOSI (out), SCK (out) and SS (out,high) 
 *	Enables SPI peripheral in master mode
 ******************************************************************/
void spi_init();

/******************************************************
 *	Set SPI Mode, i.e., Clock Polarity and Clock Phase
 *	Arguments: SPI Mode
 *	SPI Mode	Clock Polarity	Clock Phase	
 *	   0			0				0
 *	   1			0				1
 *	   2			1				0
 *	   3			1				1
 ******************************************************/
void spi_mode(uint8_t spymode);

/****************************************************
 *	Set SPI Clock Speed (SCK Speed)
 *	Arguments: Clock Division (F_CPU Pre-scaler)
 *	Available pre-scaler values: 2,4,8,16,32,64,128
 ****************************************************/
void spi_speed(uint8_t clkdiv);

/*********************************************
 *	SPI Data Mode
 *	Arguments: 0 (MSB first) or 1 (LSB first)
 *********************************************/
void spi_dmode(uint8_t dato);

/**********************************************
 *	SPI Shift Data
 *	Loads data to SPI data register and waits 
 *	 until data transfer is complete
 *	Arguments: 8-bit data to be transferred
 *	Returns: 8-bit data received
 **********************************************/
uint8_t spi_shift(uint8_t spidata);

/********************************************
 *	SPI De-initialize
 *	Disables SPI by clearing SPI enable bit
 * and restoring HW pins to default state
 ********************************************/
void spi_deinit();

#endif
