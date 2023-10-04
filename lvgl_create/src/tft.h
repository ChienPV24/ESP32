#ifndef _TFT_H_
#define _TFT_H_

#include <lvgl.h>
#include <TFT_eSPI.h>

void tft_init();

void my_touchpad_read( lv_indev_drv_t * indev_driver, lv_indev_data_t * data );
void my_disp_flush( lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p );

#endif