#include "vbat.h"
#include "adc_driver.h"
#include "led_driver.h"

static int alarm = 0;

void vbat_check(adc_raw_t adc_val)
{
    
}

int vbat_check_alarm_state(void)
{
    return alarm;
}