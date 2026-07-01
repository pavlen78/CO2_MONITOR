#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

static const char *TAG = "CO2_MONITOR";

extern "C" void app_main(void)
{
    ESP_LOGI(TAG, "CO2 monitor start OK");

    while (1)
    {
        ESP_LOGI(TAG, "system running...");
        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}