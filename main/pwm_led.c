/**
 * @file main.c
 * @brief This code to control an LED using PWM with a 75% duty cycle on and 25% off with ESP-IDF.
 */

#include <stdio.h>
#include "driver/ledc.h"
#include "esp_err.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

/** 
 * @brief LEDC timer configuration parameters.
 */


/**< Timer number for LEDC */
#define LEDC_HS_TIMER         0   
/**< LEDC mode */          
#define LEDC_HS_MODE          LEDC_HIGH_SPEED_MODE 
/**< LEDC channel */
#define LEDC_HS_CH0_CHANNEL   LEDC_CHANNEL_0 
/**< GPIO number for LED */
#define LEDC_HS_CH0_GPIO      18          
 /**< Duty cycle for LED on (75% of 255) */  
#define LEDC_HS_CH0_DUTY_ON   (191)        
 /**< Duty cycle for LED off (25% of 255) */
#define LEDC_HS_CH0_DUTY_OFF  (64)         
/**< Frequency in Hz (1 kHz for 1-second cycle) */
#define LEDC_HS_CH0_FREQ      (1000)        
 /**< Total cycle duration in milliseconds */
#define CYCLE_DURATION_MS     (5000)      

/**
 * @brief Initializes LEDC timer and channel.
 */
void ledc_init()
{
    // Configure the LEDC timer
    ledc_timer_config_t ledc_timer = {
        .speed_mode       = LEDC_HS_MODE,
        .timer_num        = LEDC_HS_TIMER,
        /**< 8-bit resolution */
        .duty_resolution  = LEDC_TIMER_8_BIT, 
        .freq_hz          = LEDC_HS_CH0_FREQ,
        .clk_cfg          = LEDC_AUTO_CLK
    };
    
    /**< Initialize timer with configured settings */
    ESP_ERROR_CHECK(ledc_timer_config(&ledc_timer)); 

    // Configure the LEDC channel
    ledc_channel_config_t ledc_channel = {
        .speed_mode     = LEDC_HS_MODE,
        .channel        = LEDC_HS_CH0_CHANNEL,
        .gpio_num       = LEDC_HS_CH0_GPIO,
        /**< Start with the LED off */
        .duty           = LEDC_HS_CH0_DUTY_OFF,  
        .hpoint         = 0,
        .timer_sel      = LEDC_HS_TIMER
    };
    /**< Initialize channel with configured settings */
    ESP_ERROR_CHECK(ledc_channel_config(&ledc_channel)); 
}

/**
 * @brief Sets the PWM duty cycle for the LED.
 * @param duty Duty cycle value (0-255).
 */
void set_pwm_duty(uint32_t duty)
{
    /**< Set the duty cycle */
    ledc_set_duty(LEDC_HS_MODE, LEDC_HS_CH0_CHANNEL, duty); 
    /**< Apply the duty cycle */
    ledc_update_duty(LEDC_HS_MODE, LEDC_HS_CH0_CHANNEL); 
}

/**
 * @brief Main application entry point.
 */
void app_main()
{
    // Initialize LEDC
    ledc_init();

    // Main loop
    while (1)
    {
        // Turn LED on (75% duty cycle)
        set_pwm_duty(LEDC_HS_CH0_DUTY_ON);
        vTaskDelay((CYCLE_DURATION_MS * 0.75) / portTICK_PERIOD_MS); /**< LED on for 75% of the cycle */

        // Turn LED off (25% duty cycle)
        set_pwm_duty(LEDC_HS_CH0_DUTY_OFF);
        vTaskDelay((CYCLE_DURATION_MS * 0.25) / portTICK_PERIOD_MS); /**< LED off for 25% of the cycle */
    }
}
