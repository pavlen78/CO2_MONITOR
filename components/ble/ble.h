#pragma once

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
    uint32_t counter;
    uint16_t co2;
    int16_t temperature;
    uint8_t status;
    uint32_t uptime;

} __attribute__((packed)) SensorPacket;

void ble_init(void);

void ble_send(const SensorPacket *packet);

bool ble_is_connected(void);

#ifdef __cplusplus
}
#endif