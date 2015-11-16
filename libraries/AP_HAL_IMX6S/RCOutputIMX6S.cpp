/// -*- tab-width: 4; Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*-

#include <AP_HAL.h>

#if CONFIG_HAL_BOARD == HAL_BOARD_IMX6S
#include "RCOutput.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

//#include <drivers/drv_pwm_output.h>
//#include <uORB/topics/actuator_direct.h>
//#include <drivers/drv_hrt.h>

extern const AP_HAL::HAL& hal;

using namespace IMX6S;

void IMX6SRCOutput::init(void* unused)
{

}


void IMX6SRCOutput::_init_alt_channels(void)
{

}

void IMX6SRCOutput::set_freq(uint32_t chmask, uint16_t freq_hz)
{

}

uint16_t IMX6SRCOutput::get_freq(uint8_t ch)
{

    return 50;
}

void IMX6SRCOutput::enable_ch(uint8_t ch)
{

}

void IMX6SRCOutput::disable_ch(uint8_t ch)
{

}

void IMX6SRCOutput::set_safety_pwm(uint32_t chmask, uint16_t period_us)
{

}

void IMX6SRCOutput::set_failsafe_pwm(uint32_t chmask, uint16_t period_us)
{

}

bool IMX6SRCOutput::force_safety_on(void)
{

}

void IMX6SRCOutput::force_safety_off(void)
{

}

void IMX6SRCOutput::write(uint8_t ch, uint16_t period_us)
{

}

void IMX6SRCOutput::write(uint8_t ch, uint16_t* period_us, uint8_t len)
{
    for (uint8_t i=0; i<len; i++) {
        write(i, period_us[i]);
    }
}

uint16_t IMX6SRCOutput::read(uint8_t ch)
{

    return 900;
}

void IMX6SRCOutput::read(uint16_t* period_us, uint8_t len)
{

}

/*
  update actuator armed state
 */
void IMX6SRCOutput::_arm_actuators(bool arm)
{

}

/*
  publish new outputs to the actuator_direct topic
 */
void IMX6SRCOutput::_publish_actuators(void)
{

}

void IMX6SRCOutput::_timer_tick(void)
{


}

#endif // CONFIG_HAL_BOARD
