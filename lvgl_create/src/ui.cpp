#include <ui.h>
#include <lvgl.h>
#include <tft.h>
#include <WiFi.h>

extern TFT_eSPI tft;
lv_obj_t *wifi_label;
const char *ssid = "Chien";    
const char *password = "66666666";

void ui_init(){
  lv_disp_t * dispp = lv_disp_get_default();
  lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                              true, LV_FONT_DEFAULT);
  lv_disp_set_theme(dispp, theme);
  // DispText();
  connectToWiFi();
}

void DispText(){
  lv_obj_t *settings = lv_obj_create(lv_scr_act());
  lv_obj_set_size(settings, 320, 240);
  lv_obj_align(settings, LV_ALIGN_CENTER, 0, 0);

  // lv_obj_t *settinglabel = lv_label_create(settings);
  // lv_label_set_text(settinglabel, LV_SYMBOL_SETTINGS "Settings " );
  // lv_obj_set_style_text_font(settinglabel, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
  // lv_obj_align(settinglabel, LV_ALIGN_TOP_LEFT, 6, 0);

//   lv_obj_t *lb_text = lv_label_create(settings);
//   lv_obj_set_align(lb_text, LV_ALIGN_CENTER);
//   lv_label_set_text(lb_text, "Xin chao ban !!!");
//   lv_obj_set_style_text_color(lb_text, lv_color_hex(0xFFFF00), LV_PART_MAIN | LV_STATE_DEFAULT);
//   lv_obj_set_style_text_align(lb_text, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
//   lv_obj_set_style_text_font(lb_text, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

//   lv_obj_t *lb_text1 = lv_label_create(settings);
//   lv_obj_set_align(lb_text1, LV_ALIGN_TOP_RIGHT);
//   lv_label_set_text(lb_text1, LV_SYMBOL_BLUETOOTH "Bluetooth");
//   lv_obj_set_style_text_color(lb_text1, lv_color_hex(0xFFFF00), LV_PART_MAIN | LV_STATE_DEFAULT);
//   lv_obj_set_style_text_align(lb_text1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
//   lv_obj_set_style_text_font(lb_text1, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
}

void connectToWiFi() {
  lv_obj_t *settings = lv_obj_create(lv_scr_act());
  lv_obj_set_size(settings, 320, 240);
  lv_obj_align(settings, LV_ALIGN_CENTER, 0, 0);

  lv_obj_t *wifi_label = lv_label_create(settings);

  tft.fillScreen(TFT_BLACK); // Xóa màn hình

  // Hiển thị trạng thái kết nối
  lv_label_set_text(wifi_label, LV_SYMBOL_WIFI "Connecting to WiFi...");
  tft.drawString("Connecting to WIFI...", 10, 10);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    tft.fillScreen(TFT_BLACK); // Xóa màn hình
    tft.drawString("Connecting to WiFi...", 10, 10);
    tft.drawString("Please wait...", 10, 30);
  }

  // Khi kết nối thành công
  tft.fillScreen(TFT_BLACK); // Xóa màn hình
  lv_label_set_text(wifi_label,LV_SYMBOL_WIFI "Connected to WiFi");
  tft.drawString("Connected to WiFi", 10, 10);

  // In địa chỉ IP lên màn hình
  IPAddress localIP = WiFi.localIP();
  String ipString = "IP Address: " + localIP.toString();
  lv_label_set_text(wifi_label, ipString.c_str());
  tft.drawString(ipString, 10, 30);
}