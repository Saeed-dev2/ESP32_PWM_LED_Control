# ESP32 PWM LED Control

## Project Overview

This project showcases how to control an LED using Pulse Width Modulation (PWM) with the ESP32 microcontroller and ESP-IDF framework. The LED is programmed to be on for 75% of the time and off for 25% of the time, repeating this cycle every 5 seconds.

## Features

- Configures PWM for precise LED control.
- Duty cycle set to 75% on and 25% off.
- Complete on-off cycle duration of 5 second.

## Components

- **ESP32 Development Board**
- **LED**
- **Current-Limiting Resistor** (220Ω to 1kΩ)

## Prerequisites

1. **ESP-IDF:** Ensure you have ESP-IDF v4.4.4 or later installed. Follow the [ESP-IDF Getting Started Guide](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/) for installation instructions.

## Hardware Connections

### **Connecting the LED to ESP32**

1. **ESP32 GPIO to LED:**
   - **LED Anode (Longer Leg)**: Connect to GPIO 18 on the ESP32.
   - **LED Cathode (Shorter Leg)**: Connect to one end of the current-limiting resistor.

2. **Current-Limiting Resistor to Ground:**
   - Connect the other end of the current-limiting resistor to the GND pin on the ESP32.



**Note:**
- **GPIO 18**: Used for PWM output.
- **Current-Limiting Resistor**: Protects the LED by limiting current.
- **GND**: Common ground to complete the circuit.

Ensure to use a current-limiting resistor between 220Ω and 1kΩ to prevent damage to the LED and ensure correct operation.

## Installation and Setup

1. **Clone the Repository:**

   ```sh
   git clone https://github.com/Saeed-dev2/ESP32_PWM_LED_Control.git
    ```
2. **Install Dependencies:**

    Install the required libraries and components:
    ```
    idf.py install
    ```
3. **Configure the Project:**

    Configure project settings with:
    ```
    idf.py menuconfig
    ```
 4. **Build the Project:**

    Compile the project using:
    ```
    idf.py build
    ```
5. **Flash the Firmware:**

    Upload the firmware to your ESP32 board:
    ```
    idf.py flash
    ```
6. **Monitor Serial Output:**

    Observe the serial output:
    ```
    idf.py monitor
    ```
    Exit the monitor by pressing `Ctrl+]`.

## Author:
`M.Saeed`
