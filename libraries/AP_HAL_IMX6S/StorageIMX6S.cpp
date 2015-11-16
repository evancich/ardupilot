#include <AP_HAL.h>
#if CONFIG_HAL_BOARD == HAL_BOARD_IMX6S

#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <ctype.h>

#include "Storage.h"
using namespace IMX6S;

/*
  This stores eeprom data in the IMX6S MTD interface with a 4k size, and
  a in-memory buffer. This keeps the latency and devices IOs down.
 */



extern const AP_HAL::HAL& hal;

IMX6SStorage::IMX6SStorage(void) 
{
}

/*
  get signature from bytes at offset MTD_SIGNATURE_OFFSET
 */
uint32_t IMX6SStorage::_mtd_signature(void)
{

}

/*
  put signature bytes at offset MTD_SIGNATURE_OFFSET
 */
void IMX6SStorage::_mtd_write_signature(void)
{

}

/*
  upgrade from microSD to MTD (FRAM)
 */
void IMX6SStorage::_upgrade_to_mtd(void)
{

}
            

void IMX6SStorage::_storage_open(void)
{

}

/*
  mark some lines as dirty. Note that there is no attempt to avoid
  the race condition between this code and the _timer_tick() code
  below, which both update _dirty_mask. If we lose the race then the
  result is that a line is written more than once, but it won't result
  in a line not being written.
 */
void IMX6SStorage::_mark_dirty(uint16_t loc, uint16_t length)
{

}

void IMX6SStorage::read_block(void *dst, uint16_t loc, size_t n)
{

}

void IMX6SStorage::write_block(uint16_t loc, const void *src, size_t n)
{

}

void IMX6SStorage::_timer_tick(void)
{

}

#endif // CONFIG_HAL_BOARD
