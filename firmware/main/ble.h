#pragma once

#include "packet.h"

#ifdef __cplusplus
extern "C"
{
#endif

void ble_init(void);

void ble_send(const SensorPacket *packet);

bool ble_connected(void);

#ifdef __cplusplus
}
#endif