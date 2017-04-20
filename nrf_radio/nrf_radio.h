 /*************************************************
 * nRF24L01 Radio Driver Header
 * Soumil Heble
 * soumilheble@iith.ac.in
 *************************************************/
//Radio Delay enum
 
//PIB
void len_crc();
void mask_int();
void tx_pow();
void com_speed();
void rf_chan();
void pay_len();
void pipe_addr();
void addr_len();

//Management Functions
void flushrx_fifo();
void flushtx_fifo();
uint8_t get_status();
void clr_int();
radio_mode

//Channel Scan
get_rpd

//Test Functions
carrier_on
carrier_off

//Data Functions
rx_conf
tx_conf
tx_payl
rx_payl

//Radio States
Radio States
RX_ON
TX_ON
STDBY_2
STDBY_1
TRX_OFF