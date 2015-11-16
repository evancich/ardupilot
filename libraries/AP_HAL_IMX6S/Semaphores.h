
#ifndef __AP_HAL_IMX6S_SEMAPHORE_H__
#define __AP_HAL_IMX6S_SEMAPHORE_H__

#include <AP_HAL_IMX6S.h>
#include "AP_HAL_IMX6S_Namespace.h"

class IMX6S::IMX6SSemaphore : public AP_HAL::Semaphore {
public:
	IMX6SSemaphore() : _taken(false) {}
    bool give();
    bool take(uint32_t timeout_ms);
    bool take_nonblocking();
private:
    bool _taken;
};

#endif // __AP_HAL_IMX6S_SEMAPHORE_H__
