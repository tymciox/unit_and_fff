#include "vbat.h"
#include "gpio_control.h"

static int cnt = 0;

// typedef enum
// {
//     IDLE,
//     FIRST_SIGNAL
// }detection_state_t;

// detection_state_t detection_state;

void detection_init(void)
{
    cnt = 0;
}

signal_detected_t detection(void)
{
    gpio_state_t current_state = get_gpio_state(GPIO_WAVEFORM);

    if (GPIO_HIGH_STATE == current_state)
    {
        cnt++;
    }
    else
    {
        if (cnt >= 200/TICK_MS)
        {
            return 1;
        }
    }
    return 0;
}