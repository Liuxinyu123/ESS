cmake_minimum_required(VERSION 2.8.9)

set(target ledmatrix) 

set(sources LEDMatrixWidget.cpp LEDMatrixLogic.cpp)

set(headers factory.h LEDMatrixWidget.h LEDMatrixLogic.h)

set(CMAKE_AUTOMOC ON)

include_directories(../../src)

add_definitions(-DQT_PLUGIN)

find_package(Qt5Widgets)

add_definitions(${Qt5Widgets_DEFINITIONS})

add_definitions(-std=c++0x)

add_library(${target} SHARED ${headers} ${sources})

qt5_use_modules(${target} Widgets)
