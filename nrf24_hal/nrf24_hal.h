/*************************************************
 * nRF24L01 Hardware Abstraction Layer Header
 * Soumil Heble
 * soumilheble@iith.ac.in
 *************************************************/ 

#ifndef	_NRF24__HAL_H_
#define _NRF24__HAL_H_

/**********************************************************
 *	AVR IO Library required for MCU macros and SPI Library	
 **********************************************************/
#include <avr/io.h>
#include <avr/interrupt.h>
#include <radio_config.h>
#include <spyavr.h>
#include <nrf24l01_regdef.h>

/*******************************************************************
 *	AVR DDR and pin number for nRF Interrupt (External Int. on AVR)
 *	DDR, PORT and pin number for RX and TX Control Pin nRF 
 *******************************************************************/
#define	IRQDDR		DDRD
#define IRQPIN		2
#define	CEDDR		DDRD
#define	CEPORT		PORTD
#define	MCPIN		4	//Mode Control Pin (CE Pin nRF24L01)

/********************************************
 *	HAL Frame Structure
 *	Members: Pipe Number and Data Array
 ********************************************/
typedef struct
{
  uint8_t pipeno;
  uint8_t payload[PAY_LEN];
} nrf24_hal_frame;

/***************************************
 *	Activate NRF Interface
 *	Setup SPI and Mode Select (CE) Pin
 ***************************************/
void nrf_init();

/*********************************************
 *	Read Register
 *	Reads value from nRF register
 *	Arguments: 8-bit register address
 *	Returns: Register contents of the address
 *********************************************/
uint8_t read_reg(uint8_t addr);

/**************************************************************
 *	Read Register Bit
 *	Reads value of #bit from nRF register
 *	Arguments: 8-bit register address and Bit number (0-7)
 *	Returns: Register contents of the address at specified bit
 **************************************************************/
uint8_t read_subreg(uint8_t addr, uint8_t mask, uint8_t position);

/********************************
 *	Execute Command
 *	SPI Commands to nRF
 *	Arguments: 8-bit SPI Command
 ********************************/
void exec_command(uint8_t comm);

/*****************************************************
 *	Write Register
 *	Writes value to nRF register
 *	Arguments: 8-bit register address and 8-bit Value
 *****************************************************/
void write_reg(uint8_t addr, uint8_t val);

/*********************************************************************
 *	Write Register Bit
 *	Set/Reset bit in nRF register at specified address
 *	Arguments: 8-bit register address, Bit number (0-7) and Bit Value
 *********************************************************************/
void write_subreg(uint8_t addr, uint8_t mask, uint8_t position, uint8_t value);

/******************************************************************************
 *	Read Register Multi-byte
 *	Writes multi-byte value to nRF register
 *	Arguments: 8-bit register address, no. of bytes and pointer to data array
 ******************************************************************************/
void read_mreg(uint8_t addr, uint8_t len, uint8_t* buf);

/******************************************************************************
 *	Write Register Multi-byte
 *	Writes multi-byte value to nRF register
 *	Arguments: 8-bit register address, no. of bytes and pointer to data array
 ******************************************************************************/
void write_mreg(uint8_t addr, uint8_t len, uint8_t* buf);

/******************************************************************************
 *	Write Payload Multi-byte
 *	Reads multi-byte payload from nRF
 *	Arguments: payload Length and pointer to data array
 ******************************************************************************/
void write_frame(uint8_t* buf, uint8_t len);

/******************************************************************************
 *	Read Payload Multi-byte
 *	Reads multi-byte payload from nRF
 *	Arguments: no. of bytes and pointer to data array
 *	Returns: Pipe Number	
 ******************************************************************************/
void read_frame(nrf24_hal_frame *rx_frame);

#endif