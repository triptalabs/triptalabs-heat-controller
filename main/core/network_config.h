#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @file network_config.h
 * @brief Configuración global de red y WebSocket.
 */

/** Número máximo de clientes WebSocket simultáneos permitidos */
#define MAX_WS_CLIENTS 1

/** Puerto TCP en el que escucha el servidor WebSocket */
#define WS_SERVER_PORT 8080

#ifdef __cplusplus
}
#endif 