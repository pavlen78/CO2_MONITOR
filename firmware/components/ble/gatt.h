#pragma once

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void ble_gatt_init(void);

void ble_gatt_notify(const void *data, uint16_t len);

#ifdef __cplusplus
}
#endif