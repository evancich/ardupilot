
#ifndef __AP_HAL_IMX6S_UARTDRIVER_H__
#define __AP_HAL_IMX6S_UARTDRIVER_H__

#include <AP_HAL.h>
#include "AP_HAL_IMX6S_Namespace.h"
#if CONFIG_HAL_BOARD == HAL_BOARD_IMX6S
#include <AP_HAL_IMX6S.h>
//#include <systemlib/perf_counter.h>

class IMX6S::IMX6SUARTDriver : public AP_HAL::UARTDriver {
public:
    IMX6SUARTDriver(const char *devpath, const char *perf_name);
    IMX6SUARTDriver();
    /* IMX6S implementations of UARTDriver virtual methods */
    void begin(uint32_t b);
    void begin(uint32_t b, uint16_t rxS, uint16_t txS);
    void end();
    void flush();
    bool is_initialized();
    void set_blocking_writes(bool blocking);
    bool tx_pending();

    /* IMX6S implementations of Stream virtual methods */
    int16_t available();
    int16_t txspace();
    int16_t read();

    /* IMX6S implementations of Print virtual methods */
    size_t write(uint8_t c);
    size_t write(const uint8_t *buffer, size_t size);



private:
    const char *_devpath;
    int _fd;
    uint32_t _baudrate;
    volatile bool _initialised;
    volatile bool _in_timer;

    bool _nonblocking_writes;

    // we use in-task ring buffers to reduce the system call cost
    // of ::read() and ::write() in the main loop
    uint8_t *_readbuf;
    uint16_t _readbuf_size;

    // _head is where the next available data is. _tail is where new
    // data is put
    volatile uint16_t _readbuf_head;
    volatile uint16_t _readbuf_tail;

    uint8_t *_writebuf;
    uint16_t _writebuf_size;
    volatile uint16_t _writebuf_head;
    volatile uint16_t _writebuf_tail;
   // perf_counter_t  _perf_uart;

    int _write_fd(const uint8_t *buf, uint16_t n);
    int _read_fd(uint8_t *buf, uint16_t n);
    uint64_t _last_write_time;

    void try_initialise(void);
    uint32_t _last_initialise_attempt_ms;

    uint32_t _os_write_buffer_size;
    uint32_t _total_read;
    uint32_t _total_written;
    enum flow_control _flow_control;

//    pid_t _uart_owner_pid;

};
#endif //#if CONFIG_HAL_BOARD == HAL_BOARD_IMX6S
#endif // __AP_HAL_IMX6S_UARTDRIVER_H__
