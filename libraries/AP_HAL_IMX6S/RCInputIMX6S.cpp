#include <AP_HAL.h>

#if CONFIG_HAL_BOARD == HAL_BOARD_IMX6S
#include "RCInput.h"
#include <fcntl.h>
#include <unistd.h>
//#include <drivers/drv_pwm_output.h>
//#include <drivers/drv_hrt.h>
//#include <uORB/uORB.h>

using namespace IMX6S;

extern const AP_HAL::HAL& hal;

void IMX6SRCInput::init(void* unused)
{

}

bool IMX6SRCInput::new_input()
{

}

uint8_t IMX6SRCInput::num_channels()
{

}

uint16_t IMX6SRCInput::read(uint8_t ch)
{

}

uint8_t IMX6SRCInput::read(uint16_t* periods, uint8_t len)
{

}

bool IMX6SRCInput::set_overrides(int16_t *overrides, uint8_t len)
{

}

bool IMX6SRCInput::set_override(uint8_t channel, int16_t override) {

}

void IMX6SRCInput::clear_overrides()
{

}

void IMX6SRCInput::_timer_tick(void)
{

}

bool IMX6SRCInput::rc_bind(int dsmMode)
{

    return true;
}

#endif //#if CONFIG_HAL_BOARD == HAL_BOARD_IMX6S
