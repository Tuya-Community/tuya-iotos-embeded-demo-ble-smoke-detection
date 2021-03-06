#ifndef __SMOKE_DEMO_H__
#define __SMOKE_DEMO_H__

#include "tuya_ble_common.h"

/* DP define */
#define DP_ID_SENSOR_STATE	101

void smoke_sensor_task(unsigned int adc_value);
void dp_update(unsigned char dp_id, unsigned char data_type, unsigned char data);

#endif /* __SMOKE_DEMO_H__ */
