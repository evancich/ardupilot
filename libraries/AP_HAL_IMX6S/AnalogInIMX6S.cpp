/// -*- tab-width: 4; Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*-

#include <AP_HAL.h>

#if CONFIG_HAL_BOARD == HAL_BOARD_IMX6S
#include "AnalogIn.h"
//#include <drivers/drv_adc.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
//#include <nuttx/analog/adc.h>
//#include <nuttx/config.h>
//#include <arch/board/board.h>
//#include <uORB/topics/battery_status.h>
//#include <uORB/topics/servorail_status.h>
//#include <uORB/topics/system_power.h>
#include <GCS_MAVLink.h>
#include <errno.h>
#include "GPIO.h"
#include <AP_HAL_IMX6S.h>
#include "AP_HAL_IMX6S_Namespace.h"
#define ANLOGIN_DEBUGGING 0

// base voltage scaling for 12 bit 3.3V ADC
#define IMX6S_VOLTAGE_SCALING (3.3f/4096.0f)

#if ANLOGIN_DEBUGGING
 # define Debug(fmt, args ...)  do {printf("%s:%d: " fmt "\n", __FUNCTION__, __LINE__, ## args); } while(0)
#else
 # define Debug(fmt, args ...)
#endif

extern const AP_HAL::HAL& hal;

/*
  scaling table between ADC count and actual input voltage, to account
  for voltage dividers on the board. 
 */
static const struct {
    uint8_t pin;
    float scaling;
} pin_scaling[] = {
#ifdef CONFIG_ARCH_BOARD_PX4FMU_V1
    // PX4 has 4 FMU analog input pins
    { 10, (5.7f*3.3f)/4096 }, // FMU battery on multi-connector pin 5,
                            // 5.7:1 scaling
    { 11,  6.6f/4096  }, // analog airspeed input, 2:1 scaling
    { 12,  3.3f/4096  }, // analog2, on SPI port pin 3
    { 13, 16.8f/4096  }, // analog3, on SPI port pin 4
#elif defined(CONFIG_ARCH_BOARD_PX4FMU_V2)
    { 2,   3.3f/4096  },    // 3DR Brick voltage, usually 10.1:1
                            // scaled from battery voltage
    { 3,   3.3f/4096  },    // 3DR Brick current, usually 17:1 scaled
                            // for APM_PER_VOLT
    { 4,   6.6f/4096  },    // VCC 5V rail sense
    { 10,  3.3f/4096  },    // spare ADC
    { 11,  3.3f/4096  },    // spare ADC
    { 12,  3.3f/4096  },    // spare ADC
    { 13,  3.3f/4096  },    // AUX ADC pin 4
    { 14,  3.3f/4096  },    // AUX ADC pin 3
    { 15,  6.6f/4096  },    // analog airspeed sensor, 2:1 scaling
#elif defined(HAL_BOARD_IMX6S)
	 { 2,   3.3f/4096  },    // 3DR Brick voltage, usually 10.1:1
	                            // scaled from battery voltage
	    { 3,   3.3f/4096  },    // 3DR Brick current, usually 17:1 scaled
	                            // for APM_PER_VOLT
	    { 4,   6.6f/4096  },    // VCC 5V rail sense
	    { 10,  3.3f/4096  },    // spare ADC
	    { 11,  3.3f/4096  },    // spare ADC
	    { 12,  3.3f/4096  },    // spare ADC
	    { 13,  3.3f/4096  },    // AUX ADC pin 4
	    { 14,  3.3f/4096  },    // AUX ADC pin 3
	    { 15,  6.6f/4096  },    // analog airspeed sensor, 2:1 scaling
#else
#error "Unknown board type for AnalogIn scaling"
#endif
};

using namespace IMX6S;

IMX6SAnalogSource::IMX6SAnalogSource(int16_t pin, float initial_value) :
	_pin(pin),
    _stop_pin(-1),
    _settle_time_ms(0),
    _value(initial_value),
    _value_ratiometric(initial_value),
    _latest_value(initial_value),
    _sum_count(0),
    _sum_value(0),
    _sum_ratiometric(0)
{
#ifdef PX4_ANALOG_VCC_5V_PIN
    if (_pin == ANALOG_INPUT_BOARD_VCC) {
        _pin = PX4_ANALOG_VCC_5V_PIN;
    }
#endif
}

void IMX6SAnalogSource::set_stop_pin(uint8_t p)
{ 
    _stop_pin = p; 
}

float IMX6SAnalogSource::read_average()
{

    return _value;
}

float IMX6SAnalogSource::read_latest()
{
    return _latest_value;
}

/*
  return scaling from ADC count to Volts
 */
float IMX6SAnalogSource::_pin_scaler(void)
{
    float scaling = IMX6S_VOLTAGE_SCALING;
    uint8_t num_scalings = sizeof(pin_scaling)/sizeof(pin_scaling[0]);
    for (uint8_t i=0; i<num_scalings; i++) {
        if (pin_scaling[i].pin == _pin) {
            scaling = pin_scaling[i].scaling;
            break;
        }
    }
    return scaling;
}

/*
  return voltage in Volts
 */
float IMX6SAnalogSource::voltage_average()
{
    return _pin_scaler() * read_average();
}

/*
  return voltage in Volts, assuming a ratiometric sensor powered by
  the 5V rail
 */
float IMX6SAnalogSource::voltage_average_ratiometric()
{
    voltage_average();
    return _pin_scaler() * _value_ratiometric;
}

/*
  return voltage in Volts
 */
float IMX6SAnalogSource::voltage_latest()
{
    return _pin_scaler() * read_latest();
}

void IMX6SAnalogSource::set_pin(uint8_t pin)
{
    if (_pin == pin) {
        return;
    }
    hal.scheduler->suspend_timer_procs();
    _pin = pin;
    _sum_value = 0;
    _sum_ratiometric = 0;
    _sum_count = 0;
    _latest_value = 0;
    _value = 0;
    _value_ratiometric = 0;
    hal.scheduler->resume_timer_procs();
}

/*
  apply a reading in ADC counts
 */
void IMX6SAnalogSource::_add_value(float v, float vcc5V)
{
    _latest_value = v;
    _sum_value += v;
    if (vcc5V < 3.0f) {
        _sum_ratiometric += v;
    } else {
        // this compensates for changes in the 5V rail relative to the
        // 3.3V reference used by the ADC.
        _sum_ratiometric += v * 5.0f / vcc5V;
    }
    _sum_count++;
    if (_sum_count == 254) {
        _sum_value /= 2;
        _sum_ratiometric /= 2;
        _sum_count /= 2;
    }
}


IMX6SAnalogIn::IMX6SAnalogIn() :
    _current_stop_pin_i(0),
	_board_voltage(0),
    _servorail_voltage(0),
    _power_flags(0)
{}

void IMX6SAnalogIn::init(void* machtnichts)
{

}


/*
  move to the next stop pin
 */
void IMX6SAnalogIn::next_stop_pin(void)
{

}

/*
  called at 1kHz
 */
void IMX6SAnalogIn::_timer_tick(void)
{


}

AP_HAL::AnalogSource* IMX6SAnalogIn::channel(int16_t pin)
{
    for (uint8_t j=0; j<IMX6S_ANALOG_MAX_CHANNELS; j++) {
        if (_channels[j] == NULL) {
            _channels[j] = new IMX6SAnalogSource(pin, 0.0f);
            return _channels[j];
        }
    }
    hal.console->println("Out of analog channels");
    return NULL;
}

#endif // CONFIG_HAL_BOARD
