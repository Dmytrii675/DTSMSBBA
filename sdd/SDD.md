# Introduction

## Purpose
The purpose of this document is to describe the Battery Temperature Status Monitoring System based on Arduino. The system was developed using Visual Studio Code with the Wokwi package. It consists of four main scripts: the main script, a script for temperature device logic, a script for voltage device logic, and a script handling the disconnection logic of a third-party device.

## References 
- Arduino Documentation: https://www.arduino.cc/en/Reference/HomePage
- Wokwi Arduino Simulator: https://wokwi.com/
- Visual Studio Code: https://code.visualstudio.com/

# Terminology 

## Definitions

| Term                       | Definition                                                   |
|----------------------------|--------------------------------------------------------------|
| Temperature Device         | A sensor device that measures the temperature of the battery.|
| Voltage Device             | A sensor device that measures the voltage of the battery.    |
| Disconnection Logic        | The logic that handles the disconnection of a third-party device when certain conditions are met. |
| Wokwi Package              | A simulation tool for Arduino projects.                      |

## Abbreviations

| Abbreviation | Description                                    |
|--------------|------------------------------------------------|
| VS Code      | Visual Studio Code                             |
| MCU          | Microcontroller Unit                           |
| I/O          | Input/Output                                   |
| GUI          | Graphical User Interface                       |

# System Overview 

## Features
- Real-time monitoring of battery temperature and voltage.
- Disconnection of third-party devices based on specific conditions.
- User-friendly interface for monitoring and controlling the system.
- Data logging for temperature and voltage readings.

## System Components
- **Arduino MCU**: The main controller unit for processing the data from sensors.
- **Temperature Sensor**: Measures the temperature of the battery.
- **Voltage Sensor**: Measures the voltage of the battery.
- **Relay Module**: Controls the connection and disconnection of third-party devices.
- **LCD Display**: Displays real-time data and system status.
- **Communication Interface**: Interfaces such as serial communication for data exchange between the Arduino and other systems.

## Communication between Subsystems
The subsystems communicate via I/O pins and serial communication. The sensors send data to the Arduino, which processes this data and triggers the relay module when necessary. The LCD display receives updates from the Arduino to show real-time status.

## System Characteristics
- **Real-time Monitoring**: Continuously monitors battery status.
- **Automated Control**: Automatically disconnects third-party devices when certain thresholds are exceeded.
- **Data Logging**: Records temperature and voltage data for analysis.

## Input/Output
- **Inputs**: Temperature sensor readings, voltage sensor readings.
- **Outputs**: LCD display updates, relay activation signals.

## Software Performance

### Stand Description
The software runs on an Arduino microcontroller, utilizing sensor input to monitor battery conditions and control a relay for third-party device disconnection.

### Metrics

| Type               | Value                                             |
|--------------------|---------------------------------------------------|
| Temperature Range  | -40°C to +125°C                                   |
| Voltage Range      | 0V to 5V                                          |
| Response Time      | < 1 second for sensor reading and relay activation|

### Charts
Charts will display temperature and voltage readings over time, highlighting trends and anomalies.

## Graphical User Interface
The GUI will be displayed on an LCD screen connected to the Arduino, showing real-time temperature, voltage, and system status. It will also include indicators for any disconnection events.

# Sequence Diagrams 
Sequence diagrams will illustrate the interactions between the sensors, Arduino, relay module, and LCD display. These diagrams will detail the data flow and control signals for each component.

# Data Structures 
Data structures will include arrays for storing temperature and voltage readings, as well as flags for indicating system status and disconnection events.

# Interfaces
The interfaces will define how the Arduino communicates with the sensors, relay module, and LCD display. This includes pin assignments, communication protocols (such as I2C or SPI for sensors), and serial communication settings.
