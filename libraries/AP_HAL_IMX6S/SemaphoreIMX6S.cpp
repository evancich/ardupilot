#include <AP_HAL.h>
#include "Semaphores.h"

using namespace IMX6S;

bool IMX6SSemaphore::give() {
    if (_taken) {
        _taken = false;
        return true;
    } else {
        return false;
    }
}

bool IMX6SSemaphore::take(uint32_t timeout_ms) {
    return take_nonblocking();
}

bool IMX6SSemaphore::take_nonblocking() {
    /* No syncronisation primitives to garuntee this is correct */
    if (!_taken) {
        _taken = true;
        return true;
    } else {
        return false;
    }
}
