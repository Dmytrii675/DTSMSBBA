#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"
#include <Adafruit_Sensor.h>
#include "logic/temperature.h"
#include "logic/voltageControl.h"

#define RelayPin 10
#define BuzzerPin 8
#define DeviceCount 3
#define TemperaturePin 9
#define LCDpin 0x27

const int offset = 20;
byte lcdNumCols = 20; // -- number of columns in the LCD
byte lcdLine = 4;     // -- number of line in the LCD
const int sensor_max = 2500;
bool isCoolerOn = false;
double lastVoltage = 0;

// DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(LCDpin, lcdNumCols, lcdLine);
DHT dht(TemperaturePin, DHT22);
TemperatureStatus lastStatus;
ExtantionDevice ex_devices[DeviceCount] = {
    ExtantionDevice(1, 11),
    ExtantionDevice(2, 12),
    ExtantionDevice(3, 13)};

Devices devices(ex_devices, DeviceCount);
String read(TemperatureStatus status);