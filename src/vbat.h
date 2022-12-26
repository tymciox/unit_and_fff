#include "adc_driver.h"

#define ADC_LEVEL_BELOW_THRESHOLD 2850

void vbat_init(void);
void vbat_check(adc_raw_t adc_val);
int vbat_check_alarm_state(void);