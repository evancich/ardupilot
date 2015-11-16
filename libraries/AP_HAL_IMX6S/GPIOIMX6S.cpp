
#include <AP_HAL.h>
#if CONFIG_HAL_BOARD == HAL_BOARD_IMX6S
#include "GPIO.h"





#define LOW     0
#define HIGH    1

extern const AP_HAL::HAL& hal;

using namespace IMX6S;

IMX6SGPIO::IMX6SGPIO()
{}

void IMX6SGPIO::init()
{

}

void IMX6SGPIO::pinMode(uint8_t pin, uint8_t output)
{

}

int8_t IMX6SGPIO::analogPinToDigitalPin(uint8_t pin)
{

    return -1;
}


uint8_t IMX6SGPIO::read(uint8_t pin) {
    return 0;
}

void IMX6SGPIO::write(uint8_t pin, uint8_t value)
{

}

void IMX6SGPIO::toggle(uint8_t pin)
{

}

/* Alternative interface: */
AP_HAL::DigitalSource* IMX6SGPIO::channel(uint16_t n) {
    return new IMX6SDigitalSource(0);
}

/* Interrupt interface: */
bool IMX6SGPIO::attach_interrupt(uint8_t interrupt_num, AP_HAL::Proc p, uint8_t mode)
{
    return true;
}

/*
  return true when USB connected
 */
bool IMX6SGPIO::usb_connected(void)
{
    return false;
}


IMX6SDigitalSource::IMX6SDigitalSource(uint8_t v) :
    _v(v)
{}

void IMX6SDigitalSource::mode(uint8_t output)
{}

uint8_t IMX6SDigitalSource::read() {
    return _v;
}

void IMX6SDigitalSource::write(uint8_t value) {
    _v = value;
}

void IMX6SDigitalSource::toggle() {
    _v = !_v;
}

#endif // CONFIG_HAL_BOARD
