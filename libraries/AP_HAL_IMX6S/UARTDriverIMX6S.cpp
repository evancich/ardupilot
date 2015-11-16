/// -*- tab-width: 4; Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*-

#include <AP_HAL.h>

#if CONFIG_HAL_BOARD == HAL_BOARD_IMX6S
#include "UARTDriver.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
//#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
//#include <termios.h>
//#include <drivers/drv_hrt.h>
#include <assert.h>
#include "../AP_HAL/utility/RingBuffer.h"

using namespace IMX6S;

extern const AP_HAL::HAL& hal;

IMX6SUARTDriver::IMX6SUARTDriver(const char *devpath, const char *perf_name) :
	_devpath(devpath),
    _fd(-1),
    _baudrate(57600),
    _initialised(false),
    _in_timer(false),
    //_perf_uart(perf_alloc(PC_ELAPSED, perf_name)),
    _flow_control(FLOW_CONTROL_DISABLE)
{
}


 IMX6SUARTDriver::IMX6SUARTDriver()
{

}

/*
  this UART driver maps to a serial device in /dev
 */

void IMX6SUARTDriver::begin(uint32_t b, uint16_t rxS, uint16_t txS)
{


}



void IMX6SUARTDriver::begin(uint32_t b)
{

}


/*
  try to initialise the UART. This is used to cope with the way NuttX
  handles /dev/ttyACM0 (the USB port). The port appears in /dev on
  boot, but cannot be opened until a USB cable is connected and the
  host starts the CDCACM communication.
 */
void IMX6SUARTDriver::try_initialise(void)
{
    if (_initialised) {
        return;
    }

}


void IMX6SUARTDriver::end()
{

}

void IMX6SUARTDriver::flush() {}

bool IMX6SUARTDriver::is_initialized()
{ 

}

void IMX6SUARTDriver::set_blocking_writes(bool blocking)
{

}

bool IMX6SUARTDriver::tx_pending() { return false; }

/*
  return number of bytes available to be read from the buffer
 */
int16_t IMX6SUARTDriver::available()
{ 
return 0;
}

/*
  return number of bytes that can be added to the write buffer
 */
int16_t IMX6SUARTDriver::txspace()
{ 
return 0;
}

/*
  read one byte from the read buffer
 */
int16_t IMX6SUARTDriver::read()
{ 
return 0;
}

/* 
   write one byte to the buffer
 */
size_t IMX6SUARTDriver::write(uint8_t c)
{ 

    return 0;
}

/*
  write size bytes to the write buffer
 */
size_t IMX6SUARTDriver::write(const uint8_t *buffer, size_t size)
{

    size_t n = 0;
    while (size--) {
        n += write(*buffer++);
    }
    return n;
}



#endif // CONFIG_HAL_BOARD

