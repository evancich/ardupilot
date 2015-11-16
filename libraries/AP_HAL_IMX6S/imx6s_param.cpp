/// -*- tab-width: 4; Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*-
/*
  This replaces the IMX6SFirmware parameter system with dummy
  functions. The ArduPilot parameter system uses different formatting
  for FRAM and we need to ensure that the IMX6S parameter system doesn't
  try to access FRAM in an invalid manner
 */

#include <AP_HAL.h>

#if CONFIG_HAL_BOARD == HAL_BOARD_IMX6S
//#include <IMX6S_defines.h>
//#include <IMX6S_posix.h>
#include <stdio.h>

//#include "systemlib/param/param.h"

//#include "uORB/uORB.h"
//#include "uORB/topics/parameter_update.h"

/** parameter update topic */
//ORB_DEFINE(parameter_update, struct parameter_update_s);

#if 0 //hou
param_t param_find(const char *name)
{
    ::printf("IMX6S: param_find(%s)\n", name);
    return PARAM_INVALID;
}

int param_get(param_t param, void *val)
{
    return -1;
}

int param_set(param_t param, const void *val)
{
    return -1;
}
#endif //hou
#endif // CONFIG_HAL_BOARD
