// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.5.1
// LVGL version: 8.3.11
// Project name: UI_draft

#include "../ui.h"

void ui_ScreenEstadisticas_screen_init(void)
{
    ui_ScreenEstadisticas = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScreenEstadisticas, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_flex_flow(ui_ScreenEstadisticas, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_ScreenEstadisticas, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_pad_row(ui_ScreenEstadisticas, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_ScreenEstadisticas, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label26 = lv_label_create(ui_ScreenEstadisticas);
    lv_obj_set_width(ui_Label26, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label26, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label26, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label26, "Estadísticas de uso:");
    lv_obj_set_style_text_font(ui_Label26, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Label26, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Label26, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Label26, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Label26, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_Label26, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_Label26, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label3 = lv_label_create(ui_ScreenEstadisticas);
    lv_obj_set_width(ui_Label3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label3, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label3,
                      "Tiempo total de operación: 1h 3min\nTiempo neto de calentamiento: 30min\nNúmero de ciclos del SSR: 40\nNúmero total de sesiones: 2\n");
    lv_obj_set_style_text_font(ui_Label3, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_BtnStatsGoHome = lv_btn_create(ui_ScreenEstadisticas);
    lv_obj_set_height(ui_BtnStatsGoHome, 50);
    lv_obj_set_width(ui_BtnStatsGoHome, LV_SIZE_CONTENT);   /// 100
    lv_obj_set_x(ui_BtnStatsGoHome, 58);
    lv_obj_set_y(ui_BtnStatsGoHome, 199);
    lv_obj_set_align(ui_BtnStatsGoHome, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_BtnStatsGoHome, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_BtnStatsGoHome, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label1 = lv_label_create(ui_BtnStatsGoHome);
    lv_obj_set_width(ui_Label1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label1, "Volver a la pantalla principal");

    lv_obj_add_event_cb(ui_BtnStatsGoHome, ui_event_BtnStatsGoHome, LV_EVENT_ALL, NULL);

}
