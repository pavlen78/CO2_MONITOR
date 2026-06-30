#pragma once

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct __attribute__((packed))
{
    uint32_t counter;

    uint16_t co2;

    int16_t temperature;

    uint8_t status;

    uint32_t uptime;

} sensor_packet_t;

#ifdef __cplusplus
}
#endif