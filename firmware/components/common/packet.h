#pragma once

#include <stdint.h>

#define PACKET_VERSION 1

typedef struct __attribute__((packed))
{
    uint8_t version;

    uint32_t counter;

    uint16_t co2;

    int16_t temperature;

    uint8_t status;

    uint32_t uptime;

    uint8_t crc;

} sensor_packet_t;

_Static_assert(sizeof(sensor_packet_t) == 15, "Invalid packet size");