/*************************************************
 * nRF24L01 Hardware Abstraction Layer Source
 * Soumil Heble
 * soumilheble@iith.ac.in
 *************************************************/
#include <nrf24_hal.h>

/************************************************
 * Variables
 ************************************************/
extern nrf24_hal_frame rx_buf[HAL_BUFFER_LEN];
extern uint8_t rxbuf_head, rxbuf_tail;

//nRF24L01 Interrupt Handler
#define HAL_RF24_ISR()		ISR(RADIO_VECT)

/*****************************************
 *	SPI Activate
 *	Pull down SS to enable SPI peripheral
 *****************************************/
#define HAL_SPI_ACT() SPIPORT &= ~(1<<SS_SPY)

/****************************************
 *	SPI Deactivate
 *	Pull up SS to disable SPI peripheral
 ****************************************/
#define HAL_SPI_DEACT() SPIPORT |= (1<<SS_SPY)

/****************************************
 *	Mode Control Low
 *	Pull down CE on nRF
 ****************************************/
#define HAL_MCON_LOW() CEPORT &= ~(1<<MCPIN)

/****************************************
 *	Mode Control High
 *	Pull up CE on nRF
 ****************************************/
#define HAL_MCON_HIGH() CEPORT |= (1<<MCPIN)

/****************************************
 *	Disable Global Interrupts
 ****************************************/
#define HAL_ATOMIC_REGION_BEGIN()	volatile uint8_t OldSREG = SREG; \
					cli()

/****************************************
 *	Enable Global Interrupts
 ****************************************/
#define HAL_ATOMIC_REGION_END()		SREG = OldSREG

/****************************************
 *	Start SPI Transaction
 ****************************************/
#define HAL_OPEN_SPI()			HAL_ATOMIC_REGION_BEGIN(); \
					HAL_SPI_ACT()

/****************************************
 *	Shift SPI Data
 ****************************************/
#define HAL_SPI_TRANSFER(data_write)	spi_shift(data_write)

/****************************************
 *	Close SPI Transaction
 ****************************************/
#define HAL_CLOSE_SPI()			HAL_SPI_DEACT(); \
					HAL_ATOMIC_REGION_END()

void nrf_init()
{
	HAL_ATOMIC_REGION_BEGIN();
	#if RXON
	  sei();	//Enable Global Interrupts
	#endif
	//Setup SPI
	CEDDR |= (1<<MCPIN);
	HAL_MCON_LOW();
	HAL_SPI_DEACT();
	spi_mode(0);
	spi_dmode(0);
	spi_speed(2);
	spi_init();
	HAL_ATOMIC_REGION_END();
}

uint8_t read_reg(uint8_t addr)
{
	uint8_t data_in;
	HAL_OPEN_SPI();
	HAL_SPI_TRANSFER(addr);
	data_in = HAL_SPI_TRANSFER(SPI_DUMMY);
	HAL_CLOSE_SPI();
	return data_in;
}

uint8_t read_subreg(uint8_t addr, uint8_t mask, uint8_t position)
{
	uint8_t data_in = read_addr(addr);
	data_in &= mask;
	data_in >>= position;
	return data_in;
}

void exec_command(uint8_t comm)
{
	HAL_OPEN_SPI();
	HAL_SPI_TRANSFER(comm);
	HAL_CLOSE_SPI();
}

void write_reg(uint8_t addr, uint8_t val)
{
	HAL_OPEN_SPI();
	HAL_SPI_TRANSFER(W_REGISTER|addr);
	HAL_SPI_TRANSFER(val);
	HAL_CLOSE_SPI();
}

void write_subreg(uint8_t addr, uint8_t mask, uint8_t position, uint8_t value)
{
	uint8_t data_in = read_addr(addr);
	data_in &= ~(mask);
	data_in |= (value<<position);
	write_addr(addr,data_in);
}

void read_regm(uint8_t addr, uint8_t len, uint8_t* buf)
{
	HAL_OPEN_SPI();
	HAL_SPI_TRANSFER(addr);
	while(len)
	{
		*buf = HAL_SPI_TRANSFER(SPI_DUMMY);
		len--;
		buf++;
	}
	HAL_CLOSE_SPI();
}

void write_regm(uint8_t addr, uint8_t len, uint8_t* buf)
{
	HAL_OPEN_SPI();
	HAL_SPI_TRANSFER(W_REGISTER|addr);
	while(len)
	{
		HAL_SPI_TRANSFER(*buf);
		len--;
		buf++;
	}
	HAL_CLOSE_SPI();
}

void write_frame(uint8_t* buf, uint8_t len)
{
	HAL_OPEN_SPI();
	HAL_SPI_TRANSFER(W_TX_PAYLOAD);
	while(len)
	{
		HAL_SPI_TRANSFER(*buf);
		len--;
		buf++;
	}
	HAL_CLOSE_SPI();
}

void read_frame(nrf24_hal_frame *rx_frame)
{
	uint8_t len = PAY_LEN;
	HAL_SPI_ACT();
	
	/* Test Snippet
	rx_frame->pipeno = HAL_SPI_TRANSFER(SPI_DUMMY) & 0x0E;
	HAL_SPI_DEACT();
	
	HAL_SPI_ACT();
	HAL_SPI_TRANSFER(R_RX_PAYLOAD);
	*/
	
	rx_frame->pipeno = HAL_SPI_TRANSFER(R_RX_PAYLOAD) & 0x0E;
	while(len)
	{
		rx_frame->data[PAY_LEN-len] = HAL_SPI_TRANSFER(SPI_DUMMY);
		len--;
	}
	HAL_SPI_DEACT();
}

HAL_RF24_ISR()	//Buffer Incoming Frame and Clear RF Interrupt
{
  read_frame(&rx_buf[rxbuf_tail]);
  HAL_SPI_ACT();
  uint8_t stat_reg = HAL_SPI_TRANSFER(W_REGISTER|STATUS);
  stat_reg |= (1<<7); //Clear RX_DR
  HAL_SPI_TRANSFER(stat_reg);
  HAL_SPI_DEACT();
}