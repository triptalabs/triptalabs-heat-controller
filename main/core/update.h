/**
 * @file update.h
 * @brief Módulo para manejo de actualizaciones OTA desde repositorio GitHub usando microSD.
 *
 * Este módulo permite:
 * - Verificar si hay una versión más reciente del firmware.
 * - Descargar el firmware desde GitHub a la microSD.
 * - Flashear el ESP32 desde ese archivo sin usar particiones OTA.
 * - Restaurar una copia de respaldo si la actualización falla.
 *
 * La microSD se monta automáticamente si no está montada al llamar las funciones.
 * El archivo version.json en GitHub debe tener el formato:
 * @code
 * { "version": "1.0.1" }
 * @endcode
 *
 * @note Este módulo requiere:
 * - Una tarjeta microSD formateada con sistema de archivos FAT.
 * - Conexión WiFi activa antes de iniciar la descarga.
 *
 * @author Tripta
 * @date 2025
 */

#ifndef UPDATE_H
#define UPDATE_H

#include "esp_err.h"
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// Incluir configuración secreta si existe
#ifdef UPDATE_CONFIG_H
#include "update_config.h"
#endif

/**
 * @def FIRMWARE_URL_DEFAULT
 * @brief URL por defecto del firmware más reciente (.bin) alojado en GitHub.
 */
#ifdef SECRET_FIRMWARE_URL
#define FIRMWARE_URL_DEFAULT SECRET_FIRMWARE_URL
#else
#define FIRMWARE_URL_DEFAULT "https://github.com/triptalabs/firmware-vacuum-oven/releases/latest/download/lvgl_porting.bin"
#endif

/**
 * @def VERSION_URL_DEFAULT
 * @brief URL por defecto del archivo JSON que contiene la versión más reciente disponible del firmware.
 */
#ifdef SECRET_VERSION_URL
#define VERSION_URL_DEFAULT SECRET_VERSION_URL
#else
#define VERSION_URL_DEFAULT "https://github.com/triptalabs/firmware-vacuum-oven/releases/latest/download/version.json"
#endif

/**
 * @def VERSION_CHECK_TIMEOUT_DEFAULT
 * @brief Timeout por defecto para verificación de versión (ms)
 */
#define VERSION_CHECK_TIMEOUT_DEFAULT 15000

/**
 * @def DOWNLOAD_TIMEOUT_DEFAULT
 * @brief Timeout por defecto para descarga de firmware (ms)
 */
#define DOWNLOAD_TIMEOUT_DEFAULT 300000

/**
 * @struct update_config_t
 * @brief Estructura de configuración para el módulo de actualización
 */
typedef struct {
    const char *firmware_url;    ///< URL del firmware más reciente
    const char *version_url;     ///< URL del archivo de versión
    int version_check_timeout;   ///< Timeout para verificación de versión (ms)
    int download_timeout;        ///< Timeout para descarga de firmware (ms)
} update_config_t;

/**
 * @brief Configura las URLs y timeouts del módulo de actualización
 * 
 * @param config Estructura con la configuración deseada
 * @return
 * - ESP_OK: Configuración exitosa
 * - ESP_ERR_INVALID_ARG: Configuración inválida
 */
esp_err_t update_set_config(const update_config_t *config);

/**
 * @brief Inicializa el módulo de actualización OTA.
 *
 * Establece el estado inicial del sistema de actualización. Debe ser llamado una sola vez
 * al iniciar el sistema, generalmente desde `app_main()`.
 *
 * @return
 * - ESP_OK: Inicialización exitosa.
 * - ESP_FAIL: Fallo interno.
 */
esp_err_t update_init(void);

/**
 * @brief Verifica si hay una actualización de firmware disponible.
 *
 * Compara la versión local con la remota contenida en el archivo `version.json` en GitHub.
 *
 * @param[out] update_available Puntero que será true si hay nueva versión.
 * @return
 * - ESP_OK: Verificación exitosa.
 * - ESP_FAIL: Error de red, formato inválido o no se pudo acceder.
 * - ESP_ERR_INVALID_ARG: Puntero nulo.
 */
esp_err_t update_check(bool *update_available);

/**
 * @brief Descarga el firmware más reciente desde GitHub a la microSD.
 *
 * La descarga se realiza desde una URL fija (definida en `FIRMWARE_URL`) y se guarda
 * en la ruta especificada en `local_path`. La SD se monta automáticamente si no lo está.
 *
 * @param[in] local_path Ruta completa en la microSD donde se guardará el firmware (.bin).
 * @return
 * - ESP_OK: Descarga exitosa.
 * - ESP_FAIL: Error de red, montaje o escritura.
 * - ESP_ERR_INVALID_ARG: Ruta nula.
 */
esp_err_t update_download_firmware(const char *local_path);

/**
 * @brief Flashea el firmware desde un archivo en la microSD.
 *
 * Intenta flashear el firmware desde `firmware_path`. Si falla, intenta restaurar
 * automáticamente el firmware original desde `fallback_path`. En caso de éxito,
 * reinicia el dispositivo para aplicar los cambios.
 *
 * Flujo de ejecución:
 * 1. Intenta flashear `firmware_path`.
 * 2. Si falla, intenta flashear `fallback_path`.
 * 3. Si ambos fallan, devuelve ESP_FAIL.
 * 4. Si el flasheo es exitoso, reinicia el dispositivo.
 *
 * @param[in] firmware_path Ruta del nuevo firmware descargado.
 * @param[in] fallback_path Ruta de la copia de respaldo del firmware original.
 * @return
 * - ESP_OK: Flasheo exitoso y reinicio iniciado.
 * - ESP_FAIL: Fallo al flashear tanto el firmware nuevo como el respaldo.
 * - ESP_ERR_INVALID_ARG: Rutas inválidas o nulas.
 */
esp_err_t update_perform(const char *firmware_path, const char *fallback_path);

/**
 * @brief Consulta si hay una actualización pendiente detectada.
 *
 * Este valor se establece por la última llamada a update_check().
 * Debe llamarse después de update_check() para obtener resultados válidos.
 *
 * @return true si hay una actualización disponible, false si no.
 */
bool update_there_is_update(void);

/**
 * @brief Limpia la bandera de actualización pendiente.
 *
 * Se puede usar si el usuario cancela el proceso o tras una actualización manual.
 */
void update_clear_flag(void);

#ifdef __cplusplus
}
#endif

#endif // UPDATE_H