cmake_minimum_required(VERSION 3.10)

# Project name
project(BatteryTemperatureStatusMonitoringSystem VERSION 1.0 LANGUAGES CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the main application source files
set(SOURCE_FILES
    src/main.cpp
    src/TemperatureDevice.cpp
    src/VoltageDevice.cpp
    src/DisconnectionDevice.cpp
)

# Add include directories
include_directories(include)

# Add executable for the main application
add_executable(BatteryMonitor ${SOURCE_FILES})

# Add the test executable
add_executable(BatteryMonitorTests
    tests/test.cpp

)

# Include directories for the test executable
target_include_directories(BatteryMonitorTests PRIVATE include)

# Find and link libraries for testing 
find_package(GTest REQUIRED)
target_link_libraries(BatteryMonitorTests GTest::GTest GTest::Main)

# Enable testing
enable_testing()

# Add tests
add_test(NAME SetUpPins COMMAND BatteryMonitorTests --gtest_filter=testSetUpPins)
add_test(NAME SetDownPins COMMAND BatteryMonitorTests --gtest_filter=testSetDownPins)
add_test(NAME TestLowTemperature COMMAND BatteryMonitorTests --gtest_filter=testLowTemperature)
add_test(NAME TestMediumTemperature COMMAND BatteryMonitorTests --gtest_filter=testMediumTemperature)
add_test(NAME TestCriticalTemperature COMMAND BatteryMonitorTests --gtest_filter=testCriticalTemperature)
add_test(NAME TestOffedDevicesCount COMMAND BatteryMonitorTests --gtest_filter=testOffedDevicesCount)
add_test(NAME TestSetupOffedCountDevices COMMAND BatteryMonitorTests --gtest_filter=testSetupOffedCountDevices)
add_test(NAME TestGetNextPriorityForOff COMMAND BatteryMonitorTests --gtest_filter=testGetNextPriorityForOff)
add_test(NAME TestGetDeviceByPriorityOn COMMAND BatteryMonitorTests --gtest_filter=testGetDeviceByPriorityOn)
add_test(NAME TestGetForInit COMMAND BatteryMonitorTests --gtest_filter=testGetForInit)
