// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.5.1
// LVGL version: 8.3.11
// Project name: UI_draft

#include "../ui.h"

void ui_Devmode_screen_init(void)
{
    ui_Devmode = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Devmode, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_LabelKp = lv_label_create(ui_Devmode);
    lv_obj_set_width(ui_LabelKp, 252);
    lv_obj_set_height(ui_LabelKp, 253);
    lv_obj_set_x(ui_LabelKp, -306);
    lv_obj_set_y(ui_LabelKp, -104);
    lv_obj_set_align(ui_LabelKp, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelKp, "Kp: 2.0");
    lv_obj_set_style_text_align(ui_LabelKp, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelKp, &lv_font_montserrat_40, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TextAreaKp = lv_textarea_create(ui_LabelKp);
    lv_obj_set_width(ui_TextAreaKp, 149);
    lv_obj_set_height(ui_TextAreaKp, 70);
    lv_obj_set_x(ui_TextAreaKp, -2);
    lv_obj_set_y(ui_TextAreaKp, 0);
    lv_obj_set_align(ui_TextAreaKp, LV_ALIGN_CENTER);
    lv_textarea_set_placeholder_text(ui_TextAreaKp, "Kp...");
    lv_obj_set_style_text_font(ui_TextAreaKp, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelKi = lv_label_create(ui_Devmode);
    lv_obj_set_width(ui_LabelKi, 252);
    lv_obj_set_height(ui_LabelKi, 253);
    lv_obj_set_x(ui_LabelKi, -40);
    lv_obj_set_y(ui_LabelKi, -108);
    lv_obj_set_align(ui_LabelKi, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelKi, "Ki: 2.0");
    lv_obj_set_style_text_align(ui_LabelKi, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelKi, &lv_font_montserrat_40, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TextAreaKi = lv_textarea_create(ui_LabelKi);
    lv_obj_set_width(ui_TextAreaKi, 149);
    lv_obj_set_height(ui_TextAreaKi, 70);
    lv_obj_set_x(ui_TextAreaKi, -2);
    lv_obj_set_y(ui_TextAreaKi, 0);
    lv_obj_set_align(ui_TextAreaKi, LV_ALIGN_CENTER);
    lv_textarea_set_placeholder_text(ui_TextAreaKi, "Ki...");
    lv_obj_set_style_text_font(ui_TextAreaKi, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelKd = lv_label_create(ui_Devmode);
    lv_obj_set_width(ui_LabelKd, 252);
    lv_obj_set_height(ui_LabelKd, 253);
    lv_obj_set_x(ui_LabelKd, 255);
    lv_obj_set_y(ui_LabelKd, -111);
    lv_obj_set_align(ui_LabelKd, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelKd, "Kd: 2.0");
    lv_obj_set_style_text_align(ui_LabelKd, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelKd, &lv_font_montserrat_40, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TextAreaKd = lv_textarea_create(ui_LabelKd);
    lv_obj_set_width(ui_TextAreaKd, 149);
    lv_obj_set_height(ui_TextAreaKd, 70);
    lv_obj_set_x(ui_TextAreaKd, -2);
    lv_obj_set_y(ui_TextAreaKd, 0);
    lv_obj_set_align(ui_TextAreaKd, LV_ALIGN_CENTER);
    lv_textarea_set_placeholder_text(ui_TextAreaKd, "Kd...");
    lv_obj_set_style_text_font(ui_TextAreaKd, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_KeyboardDev = lv_keyboard_create(ui_Devmode);
    lv_keyboard_set_mode(ui_KeyboardDev, LV_KEYBOARD_MODE_NUMBER);
    lv_obj_set_width(ui_KeyboardDev, 462);
    lv_obj_set_height(ui_KeyboardDev, 318);
    lv_obj_set_x(ui_KeyboardDev, -192);
    lv_obj_set_y(ui_KeyboardDev, 125);
    lv_obj_set_align(ui_KeyboardDev, LV_ALIGN_CENTER);

    ui_BtnCambiarK = lv_btn_create(ui_Devmode);
    lv_obj_set_width(ui_BtnCambiarK, 119);
    lv_obj_set_height(ui_BtnCambiarK, 70);
    lv_obj_set_x(ui_BtnCambiarK, 263);
    lv_obj_set_y(ui_BtnCambiarK, 37);
    lv_obj_set_align(ui_BtnCambiarK, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_BtnCambiarK, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_BtnCambiarK, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_BtnGoHome = lv_btn_create(ui_Devmode);
    lv_obj_set_width(ui_BtnGoHome, 119);
    lv_obj_set_height(ui_BtnGoHome, 70);
    lv_obj_set_x(ui_BtnGoHome, 264);
    lv_obj_set_y(ui_BtnGoHome, 156);
    lv_obj_set_align(ui_BtnGoHome, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_BtnGoHome, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_BtnGoHome, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_add_event_cb(ui_TextAreaKp, ui_event_TextAreaKp, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_TextAreaKi, ui_event_TextAreaKi, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_TextAreaKd, ui_event_TextAreaKd, LV_EVENT_ALL, NULL);
    lv_keyboard_set_textarea(ui_KeyboardDev, ui_TextAreaKp);
    lv_obj_add_event_cb(ui_BtnCambiarK, ui_event_BtnCambiarK, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_BtnGoHome, ui_event_BtnGoHome, LV_EVENT_ALL, NULL);

}
