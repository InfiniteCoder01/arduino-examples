#include <hardware/spi.h>
#include <pico/binary_info.h>

void setup() {
  Serial1.begin(115200);
  spi_init(spi_default, 1000000);
  spi_set_slave(spi_default, true);
  spi_set_format(spi_default, 8, SPI_CPOL_1, SPI_CPHA_1, SPI_MSB_FIRST);
  gpio_set_function(PICO_DEFAULT_SPI_RX_PIN, GPIO_FUNC_SPI);
  gpio_set_function(PICO_DEFAULT_SPI_SCK_PIN, GPIO_FUNC_SPI);
  gpio_set_function(PICO_DEFAULT_SPI_TX_PIN, GPIO_FUNC_SPI);
  gpio_set_function(PICO_DEFAULT_SPI_CSN_PIN, GPIO_FUNC_SPI);
  bi_decl(bi_4pins_with_func(PICO_DEFAULT_SPI_RX_PIN, PICO_DEFAULT_SPI_TX_PIN, PICO_DEFAULT_SPI_SCK_PIN, PICO_DEFAULT_SPI_CSN_PIN, GPIO_FUNC_SPI));
}

void loop() {
  uint8_t buffer[1];
  if (spi_read_blocking(spi_default, 0, buffer, 1) >= 1) {
    Serial1.println(buffer[0]);
  }
}
