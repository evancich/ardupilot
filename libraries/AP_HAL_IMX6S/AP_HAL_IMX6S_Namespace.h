
#ifndef __AP_HAL_IMX6S_NAMESPACE_H__
#define __AP_HAL_IMX6S_NAMESPACE_H__

#if CONFIG_HAL_BOARD == HAL_BOARD_IMX6S
namespace IMX6S {
	class IMX6SScheduler;
	class IMX6SUARTDriver;
	class IMX6SI2CDriver;
	class IMX6SStorage;
	class IMX6SRCInput;
	class IMX6SRCOutput;
	class IMX6SAnalogIn;
	class IMX6SAnalogSource;
	class IMX6SUtil;
    class IMX6SGPIO;
    class IMX6SDigitalSource;
    class NSHShellStream;
    class IMX6SSemaphore;
}
#endif //#if CONFIG_HAL_BOARD == HAL_BOARD_IMX6S
#endif //__AP_HAL_IMX6S_NAMESPACE_H__

