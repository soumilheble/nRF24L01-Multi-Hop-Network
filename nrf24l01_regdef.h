/*
 * nRF24L01 Register Map
 * Author: Soumil Heble
 * Register Address + Sub-Register Access Location
 * (Register Address), (Bit Mask), (Sub Register Position)
 * Last Edit: 5/4/2017 
 */

#ifndef _NRF24L01_REGDEF_H_
#define _NRF24L01_REGDEF_H_

/* Configuration Register */
#define CONFIG 			0x00
//Sub-Register: Mask Receive Interrupt
#define MASK_RX_DR 		0x00, 0x40, 6
//Sub-Register: Mask Transmit Interrupt
#define MASK_TX_DS 		0x00, 0x20, 5
//Sub-Register: Mask Maximum Retransmission Interrupt
#define MASK_MAX_RT 		0x00, 0x10, 4
//Sub-Register: Enable CRC
#define EN_CRC 			0x00, 0x08, 3
//Sub-Register: CRC Length
#define CRCO 			0x00, 0x04, 2
//Sub-Register: Power Control
#define PWR_UP 			0x00, 0x02, 1
//Sub-Register: TRX Mode Control
#define PRIM_RX 		0x00, 0x01, 0

/* Auto Acknowledgement Register */
#define EN_AA 			0x01
//Sub-Register: Enable Auto ACK Pipe 5
#define ENAA_P5 		0x01, 0x20, 5
//Sub-Register: Enable Auto ACK Pipe 4
#define ENAA_P4 		0x01, 0x10, 4
//Sub-Register: Enable Auto ACK Pipe 3
#define ENAA_P3 		0x01, 0x08, 3
//Sub-Register: Enable Auto ACK Pipe 2
#define ENAA_P2 		0x01, 0x04, 2
//Sub-Register: Enable Auto ACK Pipe 1
#define ENAA_P1 		0x01, 0x02, 1
//Sub-Register: Enable Auto ACK Pipe 0
#define ENAA_P0 		0x01, 0x01, 0

/* Enable RX Pipe Address Register */
#define EN_RXADDR 		0x02
//Sub-Register: Enable Data Pipe 5
#define ERX_P5 			0x02, 0x20, 5
//Sub-Register: Enable Data Pipe 4
#define ERX_P4 			0x02, 0x10, 4
//Sub-Register: Enable Data Pipe 3
#define ERX_P3 			0x02, 0x08, 3
//Sub-Register: Enable Data Pipe 2
#define ERX_P2 			0x02, 0x04, 2
//Sub-Register: Enable Data Pipe 1
#define ERX_P1 			0x02, 0x02, 1
//Sub-Register: Enable Data Pipe 0
#define ERX_P0 			0x02, 0x01, 0

/* Setup Address Width Register */
#define SETUP_AW 		0x03
//Sub-Register: Address Length
#define AW 			0x03, 0x03, 0

/* Setup Auto Retransmission Register */
#define SETUP_RETR 		0x04
//Sub-Register: Auto Retransmit Delay
#define ARD 			0x04, 0xF0, 4
//Sub-Register: Auto Retransmit Count
#define ARC 			0x04, 0x0F, 0

/* RF Channel Register */
#define RF_CH 			0x05
//Sub-Register: Frequency Offset (Channel Select)
#define RF_CH_MASK 		0x05, 0x7F, 0

/* RF Setup Register */
#define RF_SETUP 		0x06
//Sub-Register: Continuous Carrier Transmit
#define CONT_WAVE		0x06, 0x80, 7
//Sub-Register: RF Data Rate Low
#define RF_DR_LOW		0x06, 0x20, 5
//Sub-Register: Force PLL Lock
#define PLL_LOCK 		0x06, 0x10, 4
//Sub-Register: RF Data Rate High
#define RF_DR_HIGH 		0x06, 0x08, 3
//Sub-Register: RF Transmit Power
#define RF_PWR 			0x06, 0x06, 1
//Sub-Register: Setup LNA Gain
//#define LNA_HCURR 		0x06, 0x01, 0

/* Status Register */
#define STATUS 			0x07
//Sub-Register: RX Data Ready Interrupt Flag
#define RX_DR 			0x07, 0x40, 6
//Sub-Register: TX Data Sent Interrupt Flag
#define TX_DS 			0x07, 0x20, 5
//Sub-Register: Maximum Retransmission Interrupt Flag
#define MAX_RT 			0x07, 0x10, 4
//Sub-Register: Pipe Number with Data
#define RX_P_NO 		0x07, 0x0E, 1
//Sub-Register: TX FIFO Full Flag
#define TX_FULL 		0x07, 0x01, 0

/* Transmit Observe Register */
#define OBSERVE_TX 		0x08
//Sub-Register: Count Lost Packets
#define PLOS_CNT 		0x08, 0xF0, 4
//Sub-Register: Count Retransmitted Packets
#define ARC_CNT 		0x08, 0x0F, 0

/* Receive Power Detect Register */
#define RPD 			0x09
//Sub-Register: Receive Power Detect Bit
#define RPD_MASK 		0x09, 0x01, 0

/* RX Pipe 0 Address Register */
#define RX_ADDR_P0 		0x0A

/* RX Pipe 1 Address Register */
#define RX_ADDR_P1 		0x0B

/* RX Pipe 2 Address Register */
#define RX_ADDR_P2 		0x0C

/* RX Pipe 3 Address Register */
#define RX_ADDR_P3 		0x0D

/* RX Pipe 4 Address Register */
#define RX_ADDR_P4 		0x0E

/* RX Pipe 5 Address Register */
#define RX_ADDR_P5 		0x0F

/* Transmit Address Register */
#define TX_ADDR 		0x10

/* Number of Bytes in RX Payload Pipe 0 Register */
#define RX_PW_P0 		0x11
//Sub-Register: 5 Byte Address
#define RX_PW_P0_MASK 		0x11, 0x3F, 0

/* Number of Bytes in RX Payload Pipe 1 Register */
#define RX_PW_P1 		0x12
//Sub-Register: 5 Byte Address
#define RX_PW_P1_MASK 		0x12, 0x3F, 0

/* Number of Bytes in RX Payload Pipe 2 Register */
#define RX_PW_P2 		0x13
//Sub-Register: 5 Byte Address
#define RX_PW_P2_MASK 		0x13, 0x3F, 0

/* Number of Bytes in RX Payload Pipe 3 Register */
#define RX_PW_P3 		0x14
//Sub-Register: 5 Byte Address
#define RX_PW_P3_MASK 		0x14, 0x3F, 0

/* Number of Bytes in RX Payload Pipe 4 Register */
#define RX_PW_P4 		0x15
//Sub-Register: 5 Byte Address
#define RX_PW_P4_MASK 		0x15, 0x3F, 0

/* Number of Bytes in RX Payload Pipe 5 Register */
#define RX_PW_P5 		0x16
//Sub-Register: 5 Byte Address
#define RX_PW_P5_MASK 		0x16, 0x3F, 0

/* FIFO Status Register */
#define FIFO_STATUS 		0x17
//Sub-Register: Reuse Last Transmit Payload
#define TX_REUSE 		0x17, 0x40, 6
//Sub-Register: TX FIFO Full Flag
#define TX_FIFO_FULL 		0x17, 0x20, 5
//Sub-Register: TX FIFO Empty Flag
#define TX_FIFO_EMPTY 		0x17, 0x10, 4
//Sub-Register: RX FIFO Full Flag
#define RX_FIFO_FULL 		0x17, 0x02, 1
//Sub-Register: RX FIFO Empty Flag
#define RX_FIFO_EMPTY 		0x17, 0x01, 0

/* Dynamic Payload Register */
#define DYNPD 			0x1C
//Sub-Register: Enable Dynamic Payload on Pipe 5
#define DPL_P5 			0x1C, 0x20, 5
//Sub-Register: Enable Dynamic Payload on Pipe 4
#define DPL_P4 			0x1C, 0x10, 4
//Sub-Register: Enable Dynamic Payload on Pipe 3
#define DPL_P3 			0x1C, 0x08, 3
//Sub-Register: Enable Dynamic Payload on Pipe 2
#define DPL_P2 			0x1C, 0x04, 2
//Sub-Register: Enable Dynamic Payload on Pipe 1
#define DPL_P1 			0x1C, 0x02, 1
//Sub-Register: Enable Dynamic Payload on Pipe 0
#define DPL_P0 			0x1C, 0x01, 0

/* Feature Register */
#define FEATURE 		0x1D
//Sub-Register: Enable Dynamic Payload
#define EN_DPL 			0x1D, 0x04, 2
//Sub-Register: Enable Payload ACK
#define EN_ACK_PAY 		0x1D, 0x02, 1
//Sub-Register: Enable Dynamic with ACK
#define EN_DYN_ACK 		0x1D, 0x01, 0

/****************************************
 * SPI Commands
 * 	Command Name		Command Word
 ****************************************/
#define R_REGISTER		0x00
#define R_REGISTER_MASK		0x1F
#define	W_REGISTER		0x20
#define W_REGISTER_MASK		0x1F
#define	W_TX_PAYLOAD		0xA0
#define	R_RX_PAYLOAD		0x61
#define FLUSH_TX		0xE1
#define FLUSH_RX		0xE2
#define SPI_DUMMY		0xFF

#endif