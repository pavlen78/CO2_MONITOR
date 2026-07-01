#pragma once

#include <stdint.h>

#pragma pack(push,1)

typedef struct
{
    uint32_t counter;
    uint16_t co2;
    int16_t temperature;     // x10
    uint8_t status;
    uint32_t uptime;

} SensorPacket;

#pragma pack(pop)

static_assert(sizeof(SensorPacket)==13);