// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.5.1
// LVGL version: 8.3.11
// Project name: UI_draft

#include "lvgl.h"
#include <stdint.h>

#ifndef _UI_EVENTS_H
#define _UI_EVENTS_H

#ifdef __cplusplus
extern "C" {
#endif

void EncenderWifi(lv_event_t * e);
void ApagarWifi(lv_event_t * e);
void EncenderBt(lv_event_t * e);
void ApagarBt(lv_event_t * e);
void EncenderPID(lv_event_t * e);
void ApagarPID(lv_event_t * e);
void EncenderTimer(lv_event_t * e);
void ApagarTimer(lv_event_t * e);
void CambiarNombreBT(lv_event_t * e);
void CambiarFechaHora(lv_event_t * e);
void UpdateFirmware(lv_event_t * e);
void TryWifiConn(lv_event_t * e);
void ActualizarK(lv_event_t * e);
void actualizar_hora_cb(lv_timer_t *timer);
// ui_events.h
void ui_actualizar_estado_pid(float temperatura, bool heating_on);
#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
