#ifndef _PANEL_OPS_MIPI_H_
#define _PANEL_OPS_MIPI_H_

uint32_t Panel_I2C_Init(unsigned int bus_no, int speed, int slaveaddr);
int Panel_I2C_Write(uint32_t addr,  uint32_t reg, uint32_t val);
int Panel_I2C_Read(uint32_t addr, uint32_t reg);

#endif
