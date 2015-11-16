
#include <AP_HAL.h>
#if CONFIG_HAL_BOARD == HAL_BOARD_IMX6S
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
//#include <apps/nsh.h>
#include <fcntl.h>
#include "UARTDriver.h"
//#include <uORB/uORB.h>
//#include <uORB/topics/safety.h>
//#include <systemlib/board_serial.h>

extern const AP_HAL::HAL& hal;

#include "Util.h"
using namespace IMX6S;

extern bool _IMX6S_thread_should_exit;

/*
  constructor
 */
IMX6SUtil::IMX6SUtil(void) : Util()
{

}


/*
  start an instance of nsh
 */
bool IMX6SUtil::run_debug_shell(AP_HAL::BetterStream *stream)
{

    return true;
}

/*
  return state of safety switch
 */
enum IMX6SUtil::safety_state IMX6SUtil::safety_switch_state(void)
{

    return AP_HAL::Util::SAFETY_DISARMED;
}

void IMX6SUtil::set_system_clock(uint64_t time_utc_usec)
{
;
}

/*
  display IMX6S system identifer - board type and serial number
 */
bool IMX6SUtil::get_system_id(char buf[40])
{

    return true;
}

/**
   how much free memory do we have in bytes.
*/
uint16_t IMX6SUtil::available_memory(void)
{

}

#endif // CONFIG_HAL_BOARD == HAL_BOARD_IMX6S
