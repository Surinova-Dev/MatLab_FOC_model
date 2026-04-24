#include <stdint.h>

extern void SPI_WriteReg(uint16_t data);
extern uint16_t SPI_ReadReg(uint16_t addr);
extern void SPI_Init(void);