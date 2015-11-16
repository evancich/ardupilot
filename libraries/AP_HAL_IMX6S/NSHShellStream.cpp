/// -*- tab-width: 4; Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*-
/*
  implementation of NSH shell as a stream, for use in nsh over MAVLink

  See GCS_serial_control.cpp for usage
 */

#include <AP_HAL.h>
#if CONFIG_HAL_BOARD == HAL_BOARD_IMX6S
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
//#include <apps/nsh.h>
#include <fcntl.h>
//#include <sys/ioctl.h>
#include <SchedulerIMX6S.h>

extern const AP_HAL::HAL& hal;

#include "Util.h"
using namespace IMX6S;

void NSHShellStream::shell_thread(void)
{




    shell_stdin  = -1;
    shell_stdout = -1;
    child.in  = -1;
    child.out = -1;
}

void NSHShellStream::start_shell(void)
{

}

size_t NSHShellStream::write(uint8_t b)
{

}

size_t NSHShellStream::write(const uint8_t *buffer, size_t size)
{
    size_t ret = 0;
    while (size > 0) {
        if (write(*buffer++) != 1) {
            break;
        }
        ret++;
        size--;
    }
    return ret;
}

int16_t NSHShellStream::read()
{

    return -1;
}

int16_t NSHShellStream::available()
{

    return 0;
}

int16_t NSHShellStream::txspace()
{

    return 0;
}

#endif // CONFIG_HAL_BOARD
