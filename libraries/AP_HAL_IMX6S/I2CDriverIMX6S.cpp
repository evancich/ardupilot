
#include <AP_HAL.h>
#include "I2CDriver.h"
#include "imx_i2c.h"

using namespace IMX6S;


void IMX6SI2CDriver::begin() {}
void IMX6SI2CDriver::end() {}
void IMX6SI2CDriver::setTimeout(uint16_t ms) {}
void IMX6SI2CDriver::setHighSpeed(bool active) {}

//Todo - Figure out who is responsible for setting up the I2C Device

uint8_t IMX6SI2CDriver::write(uint8_t addr, uint8_t len, uint8_t* data)
{

	static struct imx_i2c_request myI2CRequest;

    //Setup the I2C Request in the format expected by the IMX6 SDK Driver
    myI2CRequest.dev_addr = addr;
    myI2CRequest.buffer = data;

    // Call the IMX6 SDK function to do the read
    i2c_write(&myI2CRequest);


    return 0;
}
uint8_t IMX6SI2CDriver::writeRegister(uint8_t addr, uint8_t reg, uint8_t val)
{
	return 1;
}
uint8_t IMX6SI2CDriver::writeRegisters(uint8_t addr, uint8_t reg,
                               uint8_t len, uint8_t* data)
{
	return 1;
}

uint8_t IMX6SI2CDriver::read(uint8_t addr, uint8_t len, uint8_t* data)
{
    memset(data, 0, len);

    static struct imx_i2c_request myI2CRequest;

    //Setup the I2C Request in the format expected by the IMX6 SDK Driver
    myI2CRequest.dev_addr = addr;
    myI2CRequest.buffer = data;

    // Call the IMX6 SDK function to do the read
    i2c_read(&myI2CRequest);


    return 0;
}
uint8_t IMX6SI2CDriver::readRegister(uint8_t addr, uint8_t reg, uint8_t* data)
{
    *data = 0;
    return 1;
}

uint8_t IMX6SI2CDriver::readRegisters(uint8_t addr, uint8_t reg,
                                      uint8_t len, uint8_t* data)
{
    memset(data, 0, len);    
    return 1;
}

uint8_t IMX6SI2CDriver::lockup_count() {return 0;}
