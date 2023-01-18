#include <stdint.h>

#define GPIO_WAVEFORM 0

typedef uint32_t gpio_state_t;

gpio_state_t get_gpio_state(uint32_t pin);

enum
{
    GPIO_LOW_STATE = 0,
    GPIO_HIGH_STATE
};