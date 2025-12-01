# Soil Moisture Detection using ESP8266

This project is a soil moisture detection system using the **ESP8266** microcontroller integrated with the **Blynk** Internet of Things (IoT) platform for real-time monitoring and notifications.

### Video Demo

[Video Demo : https://drive.google.com/file/d/1NH-eNUd9j\_osaeVyNQhcLEDfqCPG6kF3/view?usp=sharing](https://drive.google.com/file/d/1NH-eNUd9j_osaeVyNQhcLEDfqCPG6kF3/view?usp=sharing)

-----

## Key Features

  * **Real-time Monitoring:** Sends soil moisture percentage and voltage data in real-time to the Blynk application.
  * **Automatic Calculation:** Calculates soil moisture percentage from the analog reading (A0).
      * Moisture percentage is sent to Virtual PIN V0.
      * Voltage is sent to Virtual PIN V1.
  * **Local Status Indication:** Uses an LED (D4) to provide a visual indication of the moisture status:
      * LED is OFF (`LOW`) if the soil is Wet (`analogRead(A0) <= 500`).
      * LED Blinks (`HIGH/LOW` with 500ms delay) if the soil is getting Dry (`analogRead(A0) > 500`).

-----

## Technology Used

| Category | Technology | Description |
| :--- | :--- | :--- |
| **Microcontroller** | ESP8266 (e.g., NodeMCU) | Used as the brain of the system, connecting to WiFi. |
| **IoT Platform** | Blynk | Application and server for data visualization and control. |
| **Sensor** | Soil Moisture Sensor | Measures soil moisture and produces an analog signal. |
| **Programming** | Arduino IDE (C/C++) | Development environment for uploading code to the ESP8266. |

-----

## Installation Prerequisites

### 1\. Hardware

  * ESP8266 Module (e.g., NodeMCU or Wemos D1 Mini).
  * Soil Moisture Sensor.
  * LED and resistor (optional, if not using onboard LED).
  * Jumper Wires.

### 2\. Software & Libraries

  * **Arduino IDE** installed on your computer.
  * **ESP8266 Board Support Package** installed in the Arduino IDE.
  * **Blynk Library** installed in the Arduino IDE. This project uses the `BlynkSimpleEsp8266.h` library.
  * **Blynk** account and application on a mobile device.

-----

## Project Structure

```
.
├── Soil_Monitoring_Sensor_BLYNK.ino   # Main code file for ESP8266 and Blynk.
└── README.md                          # Project description file.
```

-----

## Example Usage

Here are the steps to run this project:

1.  **Get Blynk Auth Token:** Create a new project in your Blynk application and obtain the **Auth Token**, which will be sent to your email.

2.  **Configure Code:** Open the `Soil_Monitoring_Sensor_BLYNK.ino` file and replace the following lines with your credentials:

    ```cpp
    char auth[] ="YOUR_AUTH_TOKEN"; // Replace with your Auth Token
    char ssid[] ="YOUR_WIFI_NAME"; // Replace with your WiFi Name
    char pass[] ="YOUR_WIFI_PASS"; // Replace with your WiFi Password
    ```

    (Note: The default values in the file should be replaced before public use).

3.  **Wiring:**

      * Connect the Analog pin of the Soil Moisture Sensor to pin **A0** on the ESP8266.
      * The LED pin (if external) or other indicator light is connected to pin **D4** (as per the `#define LED D4` definition).
      * Connect the VCC and GND of the sensor to the 3.3V/5V power source and GND of the ESP8266.

4.  **Upload Code:** Select the correct Board and Port in the Arduino IDE, and upload the code to the ESP8266.

5.  **Blynk Monitoring:** Add widgets in your Blynk application and configure them to:

      * Read from pin **V0** (for Moisture Percentage).
      * Read from pin **V1** (for Voltage).

-----

## Contribution

Contributions are welcome\! If you have suggestions or find bugs, please open an *issue* or submit a *pull request*.

-----

## License

This project is licensed under the MIT License. See the `LICENSE` file (if available) or the text below for details.

```
MIT License

Copyright (c) [Year] [Name of Copyright Holder]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```
