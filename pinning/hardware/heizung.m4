/* port the enc28j60 is attached to */
pin(SPI_CS_NET, SPI_CS_HARDWARE)

/* port the dataflash CS is attached to */
dnl pin(SPI_CS_DF, PB1, OUTPUT)

ifdef(`conf_ONEWIRE', `dnl
  /* onewire support */
  pin(ONEWIRE, PD6)
')dnl

ifdef(`conf_SD_READER', `dnl
  /* port the sd-reader CS is attached to */
  pin(SPI_CS_SD_READER, PB2, OUTPUT)
')dnl

ifdef(`conf_STATUSLED_TX', `dnl
pin(STATUSLED_TX, PB3, OUTPUT)
')dnl

ifdef(`conf_STATUSLED_RX', `dnl
pin(STATUSLED_RX, PB1, OUTPUT)
')dnl


ifdef(`conf_RFM12', `dnl
  /* port the rfm12 module CS is attached to */
  pin(SPI_CS_RFM12, PB0, OUTPUT)

dnl   /* port the LEDS for rfm12 txrx attached to */
  pin(RFM12_TX_PIN, STATUSLED_TX)
  pin(RFM12_RX_PIN, STATUSLED_RX)

  RFM12_USE_INT(2)
  RFM12_ASK_SENSE_USE_INT(1)
')

ifdef(`conf_ZBUS', `dnl
  /* port config for zbus */
  pin(ZBUS_RXTX_PIN, PD2)
  pin(ZBUS_TX_PIN, STATUSLED_TX)
  pin(ZBUS_RX_PIN, STATUSLED_RX)
')

ifdef(`conf_ECMD_SERIAL_USART_RS485', `dnl
  pin(ECMD_SERIAL_USART_TX, PC2)
')

ifdef(`conf_RC5', `
  pin(RC5_SEND, PD4)
')

