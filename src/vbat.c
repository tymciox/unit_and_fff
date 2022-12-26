#include "vbat.h"
#include "adc_driver.h"
#include "led_driver.h"

static int alarm = 0;
static int alarm_cnt = 0;

void vbat_check(void)
{
    if (read_adc() < ALARM_THRESHOLD_LEVEL)
    {
        alarm_cnt++;
    }
    else
    {
        alarm_cnt = 0;
    }
    
    if (alarm_cnt >= 5)
    {
        alarm = 1;
    }
}

int vbat_check_alarm_state(void)
{
    return alarm;
}

void vbat_init(void)
{
    alarm = 0;
    alarm_cnt = 0;
}