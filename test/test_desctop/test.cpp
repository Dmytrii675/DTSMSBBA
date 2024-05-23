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