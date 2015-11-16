#ifndef __AP_HAL_IMX6S_MAIN_H__
#define __AP_HAL_IMX6S_MAIN_H__

#if CONFIG_HAL_BOARD == HAL_BOARD_IMX6S


#define AP_HAL_MAIN() extern "C" {\
    int main (void) {\
	hal.init(0, NULL);			\
        setup();\
        hal.scheduler->system_initialized(); \
        for(;;) loop();\
        return 0;\
    }\
    }

#endif
#endif // __AP_HAL_IMX6S_MAIN_H__
