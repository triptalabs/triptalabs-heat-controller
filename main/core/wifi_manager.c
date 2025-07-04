/**
 * @file wifi_manager.c
 * @brief Implementación del gestor de WiFi
 */

#include "wifi_manager.h"
#include "esp_log.h"
#include "esp_wifi.h"
#include "nvs_flash.h"
#include "esp_netif.h"
#include "esp_event.h"
#include "lwip/apps/sntp.h"
#include "lvgl.h"
#include "system_time.h"
#include <string.h>
#include <time.h>
#include "wifi_prov.h"
#include "network_config.h"
#include "mdns.h"
#include "ws_server.h"

static const char *TAG = "wifi_manager";

static EventGroupHandle_t s_wifi_event_group;
#define WIFI_CONNECTED_BIT BIT0
#define WIFI_FAIL_BIT BIT1
static int s_retry_num = 0;

static void wifi_event_handler(void* arg, esp_event_base_t event_base, int32_t event_id, void* event_data)
{
    if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_DISCONNECTED) {
        if (s_retry_num < 5) {
            esp_wifi_connect();
            s_retry_num++;
            ESP_LOGI(TAG, "Reintentando conexión WiFi (%d)", s_retry_num);
        } else {
            xEventGroupSetBits(s_wifi_event_group, WIFI_FAIL_BIT);
        }
    } else if (event_base == IP_EVENT && event_id == IP_EVENT_STA_GOT_IP) {
        s_retry_num = 0;
        xEventGroupSetBits(s_wifi_event_group, WIFI_CONNECTED_BIT);
        // Inicializar mDNS una sola vez
        static bool mdns_started = false;
        if (!mdns_started) {
            mdns_init();
            mdns_hostname_set("horno");
            mdns_service_add(NULL, "_ws", "_tcp", WS_SERVER_PORT, NULL, 0);
            ws_server_start();
            mdns_started = true;
            ESP_LOGI(TAG, "mDNS hostname 'horno.local' registrado");
        }
    }
}

esp_err_t wifi_manager_init(lv_obj_t *dropdown, lv_obj_t *datetime_label) {
    ESP_LOGI(TAG, "Inicializando WiFi...");

    // Inicializa el almacenamiento no volátil
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ESP_ERROR_CHECK(nvs_flash_init());
    }

    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());
    esp_netif_create_default_wifi_sta();

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));
    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));

    // Reemplazar bloque de configuración hard-coded
    wifi_credentials_t creds;
    if (wifi_prov_get_credentials(&creds) != ESP_OK) {
        ESP_LOGW(TAG, "Sin credenciales en NVS; iniciando provisioning BLE");
        wifi_prov_start_ble_provisioning();
        // Fallback temporal mientras se prueba
        strcpy(creds.ssid, "DemoSSID");
        strcpy(creds.password, "password");
    }

    wifi_config_t wifi_config = { 0 };
    strncpy((char *)wifi_config.sta.ssid, creds.ssid, sizeof(wifi_config.sta.ssid));
    strncpy((char *)wifi_config.sta.password, creds.password, sizeof(wifi_config.sta.password));

    ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_STA, &wifi_config));
    ESP_ERROR_CHECK(esp_wifi_start());
    ESP_ERROR_CHECK(esp_wifi_connect());

    ESP_LOGI(TAG, "Conectado a Yahel2023");

    // Espera para permitir escaneo de redes
    vTaskDelay(pdMS_TO_TICKS(3000));

    // Escaneo de redes y construcción de lista para el dropdown
    uint16_t ap_num = 0;
    wifi_ap_record_t ap_records[20];

    ESP_ERROR_CHECK(esp_wifi_scan_start(NULL, true));
    ESP_ERROR_CHECK(esp_wifi_scan_get_ap_num(&ap_num));
    ESP_ERROR_CHECK(esp_wifi_scan_get_ap_records(&ap_num, ap_records));

    static char options[512] = "";
    options[0] = '\0';

    for (int i = 0; i < ap_num && i < 20; i++) {
        strcat(options, (const char *)ap_records[i].ssid);
        if (i < ap_num - 1) strcat(options, "\n");
    }

    if (dropdown != NULL) {
        lv_dropdown_set_options(dropdown, options);
        ESP_LOGI(TAG, "Redes actualizadas en el dropdown.");
    }

    // Usar el nuevo sistema de tiempo para sincronización automática
    ESP_LOGI(TAG, "Sincronizando tiempo con la red usando el nuevo sistema...");
    system_time_update_from_network();
    
    // Iniciar timer de actualización automática
    system_time_start_auto_update();
    
    ESP_LOGI(TAG, "Sistema de tiempo integrado con WiFi completado");

    ESP_LOGI(TAG, "WiFi y hora configurados correctamente.");

    s_wifi_event_group = xEventGroupCreate();
    ESP_ERROR_CHECK(esp_event_handler_instance_register(WIFI_EVENT, ESP_EVENT_ANY_ID, &wifi_event_handler, NULL, NULL));
    ESP_ERROR_CHECK(esp_event_handler_instance_register(IP_EVENT, IP_EVENT_STA_GOT_IP, &wifi_event_handler, NULL, NULL));

    return ESP_OK;
} 