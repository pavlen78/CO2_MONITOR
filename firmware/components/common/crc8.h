#pragma once

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

uint8_t crc8(const void *data, uint32_t len);

#ifdef __cplusplus
}
#endif