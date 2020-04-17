/*
   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include "esp_log.h"

/*SPI & LCD Driver Includes*/
#include "iot_lcd.h"
#include "FreeSerifItalic24pt7b.h"
#include "FreeSerifItalic9pt7b.h"
#include "image.h"

CEspLcd* tft = NULL;
extern "C" {
void app_lcd_init()
{
    /*ESP Wrover kit config*/
    lcd_conf_t lcd_pins = {
        .lcd_model = LCD_MOD_ST7789,
        .pin_num_miso = GPIO_NUM_25,
        .pin_num_mosi = GPIO_NUM_23,
        .pin_num_clk = GPIO_NUM_19,
        .pin_num_cs = GPIO_NUM_22,
        .pin_num_dc = GPIO_NUM_21,
        .pin_num_rst = GPIO_NUM_18,
        .pin_num_bckl = GPIO_NUM_5,
        .clk_freq = 20 * 1000 * 1000,
        .rst_active_level = 0,
        .bckl_active_level = 0,
        .spi_host = HSPI_HOST,
        .init_spi_bus = true,
    };

    /*Initialize SPI Handler*/
    if (tft == NULL) {
        tft = new CEspLcd(&lcd_pins);
    }

    /*screen initialize*/
    tft->invertDisplay(false);
    tft->setRotation(1);             //Landscape mode
    tft->fillScreen(COLOR_ESP_BKGD);
    tft->drawBitmap(0, 0, esp_logo, 137, 26);
    //    tft->drawBitmap(243, 0, aws_logo, 77, 31);
    tft->setFont(&FreeSerifItalic24pt7b);
    tft->fillRect(0, 30, 230, 10, COLOR_ESP_BKGD);
    tft->drawString("Out for Lunch", 5, 90);
    tft->setFont(&FreeSerifItalic9pt7b);
    tft->drawString("Powered by ESP RainMaker", 110, 230);
}

esp_err_t app_lcd_write(char *string)
{
    if (!tft) {
        return ESP_FAIL;
    }
    tft->fillScreen(COLOR_ESP_BKGD);
    tft->drawBitmap(0, 0, esp_logo, 137, 26);
    //    tft->drawBitmap(243, 0, aws_logo, 77, 31);
    tft->setFont(&FreeSerifItalic24pt7b);
    tft->fillRect(0, 30, 230, 10, COLOR_ESP_BKGD);
    tft->drawString(string, 5, 90);
    tft->setFont(&FreeSerifItalic9pt7b);
    tft->drawString("Powered by ESP RainMaker", 110, 230);
    return ESP_OK;
}
}
