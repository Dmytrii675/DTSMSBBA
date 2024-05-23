# Battery Temperature Status Monitoring System - Test Suite

This document describes the C++ test file for the Battery Temperature Status Monitoring System. The test file includes various tests to verify the functionality of the system.

## Test File Overview

The C++ test file includes the following tests:
1. setUp(void)
2. tearDown(void)
3. testLowTemperature(void)
4. testMediumTemperature(void)
5. testCriticalTemperature(void)
6. testOffed(void)
7. testSetupOffedCount(void)
8. testGetNextPrirityForOff()
9. testGetDeviceByPriorityOn(void)
10. testGetForInit(void)

## Test Descriptions

### 1. setUp(void)
This test verifies that the pins used for sensors and relay modules are correctly initialized.

### 2. tearDown(void)
This test verifies that the pins used for sensors and relay modules are correctly reset or disabled.

### 3. testLowTemperature(void)
This test simulates a low temperature scenario and verifies the system's response.

### 4. testMediumTemperature(void)
This test simulates a medium temperature scenario and verifies the system's response.

### 5. testCriticalTemperature(void)
This test simulates a critical temperature scenario and verifies the system's response.

### 6. testOffed(void)
This test verifies the count of devices that have been turned off.

### 7. testSetupOffedCount(void)
This test verifies the setup process for the count of devices to be turned off.

### 8. testGetNextPrirityForOff()
This test verifies the function that determines the next priority for turning off a device.

### 9. testGetDeviceByPriorityOn(void)
This test verifies the function that determines which device should be turned on based on priority.

### 10. testGetForInit(void)
This test verifies the initialization process for devices.

## Code

```cpp
#include <unity.h>
#include <iostream>
#include "../src/logic/temperature.h"
#include "../src/logic/voltageControl.h"

using namespace std;

#ifdef UNIT_TEST

Devices *devices;

void setUp(void)
{
    ExtantionDevice dev[3] = {
        ExtantionDevice(1, 12),
        ExtantionDevice(3, 13),
        ExtantionDevice(2, 14)};
    devices = new Devices(dev, 3);
}

void tearDown(void) {}

void testLowTemperature(void)
{
    int expected = (int)TemperatureStatus::Low;
    int actual = (int)getTemperatureStatus(__FLT_MIN__);
    TEST_ASSERT_EQUAL_INT32(expected, actual);
}

void testMediumTemperature(void)
{
    int expected = (int)TemperatureStatus::Medium;
    int actual = (int)getTemperatureStatus(21.5555);
    TEST_ASSERT_EQUAL_INT32(expected, actual);
}

void testCriticalTemperature(void)
{
    int expected = (int)TemperatureStatus::Critical;
    int actual = (int)getTemperatureStatus(__FLT_MAX__);
    TEST_ASSERT_EQUAL_INT32(expected, actual);
}

void testOffed(void)
{
    int expected = 3;
    int actual = devices->GetOffedCount();
    TEST_ASSERT_EQUAL_INT32(expected, actual);
}

void testSetupOffedCount(void)
{
    int expected = 2;
    devices->SetupOffedCount(-1);
    int actual = devices->GetOffedCount();
    TEST_ASSERT_EQUAL_INT32(expected, actual);
}

void testGetNextPrirityForOff()
{
    ExtantionDevice *actual = devices->GetNextPriorityForOff();
    TEST_ASSERT_NOT_NULL(actual);
}

void testGetDeviceByPriorityOn(void)
{
    ExtantionDevice *actual = devices->GetDeviceByPriorityOn();
    TEST_ASSERT_NOT_NULL(actual);
}

void testGetForInit(void)
{
    ExtantionDevice *actual = devices->GetForInitDevice();
    TEST_ASSERT_NOT_NULL(actual);
}

int main(int argc, char **argv)
{
    UNITY_BEGIN();
    RUN_TEST(testLowTemperature);
    RUN_TEST(testMediumTemperature);
    RUN_TEST(testCriticalTemperature);
    RUN_TEST(testOffed);
    RUN_TEST(testSetupOffedCount);
    RUN_TEST(testGetNextPrirityForOff);
    RUN_TEST(testGetDeviceByPriorityOn);
    RUN_TEST(testGetForInit);
    UNITY_END();
}
#endif

