# Battery temperature status monitoring system based on Arduino
## Overview
This  system is  an Arduino-based battery status monitoring system that allows you to monitor temperature, humidity and battery charging status  of several devices.

## System components
* **Dynamic:** Gives a sound signal when the indicators have reached critical values.
* **Potentiometer:** Used to measure voltage.
* **Temperature sensor:** Used to measure temperature.
* **4 relays:** A device that cuts off the voltage to the corresponding device if it exceeds the set limits.
* **Cooler:** Used to cool the system.
* **LED:**  Start to light up when the indicators have reached critical values.
* **Screen:** Displays the current values of the voltage temperature and the status of the cooler operation.
* **11 external sensors:** This system supports exactly this number of additional third-party sensors.

## Using technologies
### Visual Studio Code
 VS Code is a source-code editor developed by Microsoft for Windows, Linux, macOS and web browsers.
 Visual Studio Code is a source-code editor that can be used with a variety of programming languages, including C, C#, C++, Fortran, Go, Java, JavaScript, Node.js, Python, Rust, and Julia

### Wokwi
Wokwi is an online platform designed for electronics enthusiasts, hobbyists, and students to simulate and experiment with hardware projects. It offers a virtual environment where users can design, test, and debug their electronic circuits and embedded systems without the need for physical hardware. Wokwi supports a wide range of components, including microcontrollers, sensors, actuators, and displays, allowing users to create various projects such as Arduino-based gadgets, IoT devices, and more. It's a great tool for learning, prototyping, and sharing electronic projects with others.

## Installation
* VS Code
* VS Code packages: Platform I.O. and Workwi Simulator / physical Arduino
### Dependencies
*  #include <Arduino.h> 
* #include <LiquidCrystal_I2C.h>
* #include "DHT.h"
* #include <Adafruit_Sensor.h>
* #include <WString.h>


