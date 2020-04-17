/*
   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#pragma once
#include <stdint.h>
#include <stdbool.h>

#define DEFAULT_POWER  true

void app_lcd_init();
esp_err_t app_lcd_write(char *string);
void app_wifi_init(void);
void app_wifi_start(void);