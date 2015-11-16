/// -*- tab-width: 4; Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*-

//#include <AP_HAL.h>
//#if CONFIG_HAL_BOARD == HAL_BOARD_IMX6S

//#include "AP_HAL_IMX6S.h"
#include <SchedulerIMX6S.h>

//#include <unistd.h>
//#include <stdlib.h>
//#include <sched.h>
//#include <errno.h>
//#include <stdio.h>
//#include <drivers/drv_hrt.h>
//#include <nuttx/arch.h>
//#include <systemlib/systemlib.h>
//#include <pthread.h>
//#include <poll.h>

//#include "UARTDriver.h"
//#include "AnalogIn.h"
//#include "Storage.h"
//#include "RCOutput.h"
//#include "RCInput.h"
//#include <AP_Scheduler.h>

using namespace IMX6S;

extern const AP_HAL::HAL& hal;


//IMX6SScheduler::IMX6SScheduler()
//{
//
//}

IMX6SScheduler::IMX6SScheduler()
{

}
void IMX6SScheduler::init(void *unused)
{

}

uint64_t IMX6SScheduler::micros64()
{
  return 0;
}

uint64_t IMX6SScheduler::millis64()
{
	  return 0;
}

uint32_t IMX6SScheduler::micros()
{
	  return 0;
}

uint32_t IMX6SScheduler::millis()
{
	  return 0;
}

/**
   delay for a specified number of microseconds using a semaphore wait
 */
void IMX6SScheduler::delay_microseconds_semaphore(uint16_t usec)
{

}

void IMX6SScheduler::delay_microseconds(uint16_t usec)
{

}




/*
  a varient of delay_microseconds that boosts priority to
  APM_MAIN_PRIORITY_BOOST for APM_MAIN_PRIORITY_BOOST_USEC
  microseconds when the time completes. This significantly improves
  the regularity of timing of the main loop as it takes 
 */
void IMX6SScheduler::delay_microseconds_boost(uint16_t usec)
{

}

void IMX6SScheduler::delay(uint16_t ms)
{

}

void IMX6SScheduler::register_delay_callback(AP_HAL::Proc proc,
                                            uint16_t min_time_ms) 
{

}

void IMX6SScheduler::register_timer_process(AP_HAL::MemberProc proc)
{

}

void IMX6SScheduler::register_io_process(AP_HAL::MemberProc proc)
{

}

void IMX6SScheduler::register_timer_failsafe(AP_HAL::Proc failsafe, uint32_t period_us)
{
   
}

void IMX6SScheduler::suspend_timer_procs()
{
   
}

void IMX6SScheduler::resume_timer_procs()
{

}

void IMX6SScheduler::reboot(bool hold_in_bootloader)
{

}

void IMX6SScheduler::_run_timers(bool called_from_timer_thread)
{

}

extern bool IMX6S_ran_overtime;

void *IMX6SScheduler::_timer_thread(void)
{

}

void IMX6SScheduler::_run_io(void)
{

}

void *IMX6SScheduler::_uart_thread(void)
{

}

void *IMX6SScheduler::_io_thread(void)
{

}

void *IMX6SScheduler::_storage_thread(void)
{

}

void IMX6SScheduler::panic(const prog_char_t *errormsg)
{
    hal.console->println_P(errormsg);
    for(;;);
}

bool IMX6SScheduler::in_timerprocess()
{
  
}

bool IMX6SScheduler::system_initializing() {
    return !_initialized;
}

void IMX6SScheduler::system_initialized() {
    if (_initialized) {
        panic(PSTR("PANIC: scheduler::system_initialized called"
                   "more than once"));
    }
    _initialized = true;
}

//#endif
