#pragma once

#ifdef __cplusplus
extern "C" {
#endif

void ble_gap_start_advertising(void);

void ble_gap_init(void);

bool ble_gap_is_connected(void);

#ifdef __cplusplus
}
#endif