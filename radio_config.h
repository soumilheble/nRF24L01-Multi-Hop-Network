/* Radio Configuration Header File
 * Soumil Heble
 * soumilheble@iith.ac.in
 */

#ifndef _RADIO_CONFIG_H_
#define _RADIO_CONFIG_H_

// Define if TX Setup (Does not attach RX ISR)
#define TXON 
// Define if RX Setup
#define RXON 
//Communication Channel Frequency in MHz
#define RF_CHANNEL_FREQ 	2484
//Payload Length in bytes
#define PAY_LEN			3//bytes
//CRC length in bytes
#define CRC_LEN			2//bytes
//HAL Layer RX Buffer
#define HAL_BUFFER_LEN		10
//Radio Interrupt Vector - External Interrupt 0
#define RADIO_VECT INT0_vect

//Internal: Channel Frequency to Offset Conversion
#define RF_CHANNEL_OFFSET 	(RF_CHANNEL_FREQ - 2400)
//Internal: CRC byte to Command Conversion
#define CRC_FINAL		CRC_LEN-1

#endif