
#ifndef __AP_HAL_IMX6S_CLASS_H__
#define __AP_HAL_IMX6S_CLASS_H__

#include <AP_HAL.h>

#if CONFIG_HAL_BOARD == HAL_BOARD_IMX6S

#include <AP_HAL_IMX6S.h>
#include "AP_HAL_IMX6S_Namespace.h"
//#include <systemlib/visibility.h>
//#include <systemlib/perf_counter.h>

class HAL_IMX6S : public AP_HAL::HAL {
public:
    HAL_IMX6S();
    void init(int argc, char * const argv[]) const;
};

void hal_IMX6S_set_priority(uint8_t priority);

extern const HAL_IMX6S AP_HAL_IMX6S;

#endif // CONFIG_HAL_BOARD == HAL_BOARD_IMX6S
#endif // __AP_HAL_IMX6S_CLASS_H__
