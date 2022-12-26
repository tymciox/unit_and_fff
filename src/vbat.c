#include "vbat.h"
#include "adc_driver.h"
#include "led_driver.h"

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
        led_on();
    }
}

void vbat_init(void)
{
    led_off();
    alarm_cnt = 0;
}