# main/CMakeLists.txt
idf_component_register(
    SRCS 
        "core/main.c"
        "core/update.c"
        "core/pid_controller.c"
        "core/autotuning/autotuning.c"
        "core/autotuning/ziegler_nichols.c"
        "core/autotuning/astrom_hagglund.c"
        "core/wifi_manager.c"
        "core/statistics.c"
        "core/system_test.c"
        "core/system_time.c"
        "core/bt.c"
        "bootloader/bootloader_main.c"
        "bootloader/integrity_checker.c"
        "bootloader/sd_recovery.c"
        "bootloader/recovery_mode.c"
        "drivers/io/CH422G.c"
        "drivers/display/waveshare_rgb_lcd_port.c"
        "drivers/sensor/sensor.c"
        "drivers/config/DEV_Config.c"
        "ui_chart_data.c"
        "lvgl_port.c"
        "ui/ui.c"
        "ui/ui_events.c"
        "ui/ui_helpers.c"
        "ui/screens/ui_ScreenWifi.c"
        "ui/screens/ui_ScreenAjustes.c"
        "ui/screens/ui_ScreenBootlogo.c"
        "ui/screens/ui_ScreenBT.c"
        "ui/screens/ui_ScreenEstadisticas.c"
        "ui/screens/ui_ScreenHome.c"
        "ui/screens/ui_Devmode.c"
        "ui/images/ui_img_logoblanco_png.c"
        "ui/images/ui_img_qrcode_png.c"
        "ui/images/ui_img_logo_blanco_png_png.c"
        "ui/images/ui_img_imgsettings_png.c"
        "ui/images/ui_img_img_wifi_png.c"
        "ui/images/ui_img_img_heating2_png.c"
        "ui/images/ui_img_img_cooling_png.c"
        "ui/images/ui_img_img_bt_png.c"
        "ui/images/ui_img_iconwarn_png.c"
        "ui/images/ui_img_iconwifi_png.c"
        "ui/images/ui_img_iconupdate_png.c"
        "ui/images/ui_img_iconheating_png.c"
        "ui/images/ui_img_iconsettings_png.c"
        "ui/images/ui_img_iconstatistic_png.c"
        "ui/images/ui_img_buttonminuspressed_png.c"
        "ui/images/ui_img_buttonpluspressed_png.c"
        "ui/images/ui_img_buttonplus_1_png.c"
        "ui/images/ui_img_iconbt_png.c"
        "ui/images/ui_img_arrowicon_1_png.c"
        "ui/images/ui_img_buttonminus_png.c"
        "ui/components/ui_comp_statusbar.c"
        "ui/components/statusbar_manager.c"
        "ui/components/ui_comp.c"
        "ui/components/ui_comp_hook.c"
        "core/wifi_prov.c"
        "core/ws_server/ws_server.c"
    INCLUDE_DIRS 
        "."
        "core"
        "core/autotuning"
        "bootloader"
        "drivers/io"
        "drivers/display"
        "drivers/sensor"
        "drivers/config"
        "ui"
        "ui/screens"
        "ui/images"
        "ui/components"
        "core/ws_server"
    REQUIRES
        esp_wifi
        nvs_flash
        bt
        app_update
        esp_https_ota
        spiffs
        fatfs
        console
        espressif__esp-modbus
        lvgl__lvgl
        esp_netif
        esp_event
        lwip
        esp_partition
        driver
        mbedtls
        freertos
        vfs
        mdns
        esp_http_server
        json
)

# Añadir rutas privadas adicionales
target_include_directories(${COMPONENT_TARGET} PRIVATE
    "${CMAKE_CURRENT_LIST_DIR}/../managed_components/espressif__esp-modbus/freemodbus/modbus/include"
    "${CMAKE_CURRENT_LIST_DIR}/../managed_components/espressif__esp-modbus/freemodbus/port"
    "${IDF_PATH}/components/bt/host/bluedroid/api/include/api"
    "${IDF_PATH}/components/bt/include"
)