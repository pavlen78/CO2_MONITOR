#include "ble.h"

#include "esp_log.h"
#include "esp_err.h"
#include "nvs_flash.h"

#include "nimble/nimble_port.h"
#include "nimble/nimble_port_freertos.h"

#include "host/ble_hs.h"

static const char *TAG = "BLE";

/*------------------------------------------------------------------*/
/* BLE Host Task                                                    */
/*------------------------------------------------------------------*/

static void ble_host_task(void *param)
{
    ESP_LOGI(TAG, "BLE Host Task started");

    nimble_port_run();

    nimble_port_freertos_deinit();
}

/*------------------------------------------------------------------*/
/* Sync callback                                                    */
/*------------------------------------------------------------------*/

static void ble_on_sync(void)
{
    ESP_LOGI(TAG, "BLE Host synchronized");
}

/*------------------------------------------------------------------*/
/* Public                                                           */
/*------------------------------------------------------------------*/

void ble_init(void)
{
    esp_err_t err = nvs_flash_init();

    if (err == ESP_ERR_NVS_NO_FREE_PAGES ||
        err == ESP_ERR_NVS_NEW_VERSION_FOUND)
    {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ESP_ERROR_CHECK(nvs_flash_init());
    }

    ESP_ERROR_CHECK(nimble_port_init());

    ble_hs_cfg.sync_cb = ble_on_sync;

    nimble_port_freertos_init(ble_host_task);

    ESP_LOGI(TAG, "BLE initialized");
}