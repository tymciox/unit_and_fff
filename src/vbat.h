#include <stdbool.h>

#define TICK_MS 10

typedef bool signal_detected_t;

signal_detected_t detection(void);
void detection_init(void);