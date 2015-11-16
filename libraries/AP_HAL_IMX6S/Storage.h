

#ifndef __AP_HAL_IMX6S_STORAGE_H__
#define __AP_HAL_IMX6S_STORAGE_H__

#include <AP_HAL.h>
#if CONFIG_HAL_BOARD == HAL_BOARD_IMX6S
#include "AP_HAL_IMX6S_Namespace.h"
//#include <systemlib/perf_counter.h>

#define IMX6S_STORAGE_SIZE HAL_STORAGE_SIZE
#define IMX6S_STORAGE_MAX_WRITE 512
#define IMX6S_STORAGE_LINE_SHIFT 9
#define IMX6S_STORAGE_LINE_SIZE (1<<IMX6S_STORAGE_LINE_SHIFT)
#define IMX6S_STORAGE_NUM_LINES (IMX6S_STORAGE_SIZE/IMX6S_STORAGE_LINE_SIZE)

class IMX6S::IMX6SStorage : public AP_HAL::Storage {
public:
    IMX6SStorage();

    void init(void* machtnichts) {}
    void read_block(void *dst, uint16_t src, size_t n);
    void write_block(uint16_t dst, const void* src, size_t n);

    void _timer_tick(void);

private:
    int _fd;
    volatile bool _initialised;
    void _storage_create(void);
    void _storage_open(void);
    void _mark_dirty(uint16_t loc, uint16_t length);
    uint8_t _buffer[IMX6S_STORAGE_SIZE] __attribute__((aligned(4)));
    volatile uint32_t _dirty_mask;
  //  perf_counter_t  _perf_storage;
  //  perf_counter_t  _perf_errors;
    bool _have_mtd;
    void _upgrade_to_mtd(void);
    uint32_t _mtd_signature(void);
    void _mtd_write_signature(void);
};
#endif //#if CONFIG_HAL_BOARD == HAL_BOARD_IMX6S
#endif // __AP_HAL_IMX6S_STORAGE_H__
