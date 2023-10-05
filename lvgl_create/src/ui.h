#ifndef _UI_H_
#define _UI_H_

// extern TFT_eSPI tft;
// extern lv_obj_t *wifi_label;
extern const char *ssid;    
extern const char *password;

void ui_init();
void DispText();
void connectToWiFi();

#endif