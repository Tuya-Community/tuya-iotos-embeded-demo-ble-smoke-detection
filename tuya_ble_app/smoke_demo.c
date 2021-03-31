#include "tuya_ble_log.h"

#include "smoke_demo.h"

/* update DP array len */
#define ARRAY_LEN		4
#define UPDATE_DP_LEN	1


#define ALARM_LEVEL 1500 //1.6V

#define NORMAL	0
#define ALARM	1



unsigned char sensor_state;

void smoke_sensor_task(unsigned int adc_value)
{
	if (adc_value < ALARM_LEVEL) {
		sensor_state = NORMAL;
	} else {
		sensor_state = ALARM;
	}
	dp_update(DP_ID_SENSOR_STATE, DT_ENUM, sensor_state);
}

/*
 * data_type: bool:1 ,value:2, string:3, enum:4, bitmap:5
 * */
void dp_update(unsigned char dp_id, unsigned char data_type, unsigned char data)
{
	unsigned char sensor_state_array[ARRAY_LEN];
	sensor_state_array[0] = dp_id;
	sensor_state_array[1] = data_type;
	sensor_state_array[2] = UPDATE_DP_LEN;
	sensor_state_array[3] = data;

	tuya_ble_dp_data_report(sensor_state_array, ARRAY_LEN);
}









