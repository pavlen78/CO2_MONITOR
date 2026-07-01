#include "crc8.h"

uint8_t crc8(const void *data, uint32_t len)
{
    const uint8_t *p = (const uint8_t *)data;

    uint8_t crc = 0;

    while (len--)
    {
        crc ^= *p++;

        for (uint8_t i = 0; i < 8; i++)
        {
            if (crc & 0x80)
                crc = (crc << 1) ^ 0x07;
            else
                crc <<= 1;
        }
    }

    return crc;
}