#include <ui.h>
#include <lvgl.h>

void ui_init(){
  lv_disp_t * dispp = lv_disp_get_default();
  lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                              true, LV_FONT_DEFAULT);
  lv_disp_set_theme(dispp, theme);
  DispText();
}

void DispText(){
  lv_obj_t *settings = lv_obj_create(lv_scr_act());
  lv_obj_set_size(settings, 320, 240);
  lv_obj_align(settings, LV_ALIGN_CENTER, 0, 0);

  lv_obj_t *settinglabel = lv_label_create(settings);
  lv_label_set_text(settinglabel, LV_SYMBOL_SETTINGS "Settings " );
  lv_obj_set_style_text_font(settinglabel, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_align(settinglabel, LV_ALIGN_TOP_LEFT, 6, 0);


  lv_obj_t *lb_text = lv_label_create(settings);
  lv_obj_set_align(lb_text, LV_ALIGN_CENTER);
  lv_label_set_text(lb_text, "Xin chao ban !!!");
  lv_obj_set_style_text_color(lb_text, lv_color_hex(0xFFFF00), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_align(lb_text, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_font(lb_text, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
}