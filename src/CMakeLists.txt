cmake_minimum_required(VERSION 3.5)

project(SmartCalc_v_2_0 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets PrintSupport)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets PrintSupport)
find_package(Qt6 REQUIRED COMPONENTS Charts Core Gui)

set(PROJECT_SOURCES
    qt_files/main.cc
    qt_files/mainwindow.cc
    qt_files/mainwindow.h
    qt_files/mainwindow.ui
    qt_files/creditwindow.cc
    qt_files/creditwindow.h
    qt_files/creditwindow.ui
    model/s21_model.h
    model/s21_model.cc
    model/s21_token.h
    model/s21_tokenizer.h
    model/s21_tokenizer.cc
    model/s21_polish_notation.h
    model/s21_polish_notation.cc
    model/s21_credit_calculator.h
    model/s21_credit_calculator.cc
    controller/s21_controller.h
    plot/qcustomplot.cpp
    plot/qcustomplot.h
    qt_files/plotwindow.cc
    qt_files/plotwindow.h
    qt_files/plotwindow.ui
)

include_directories(plot)
include_directories(qt_files)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(SmartCalc_v_2_0
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )

# Define target properties for Android with Qt 6 as:
# set_property(TARGET SmartCalc_v_2_0 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
# ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(SmartCalc_v_2_0 SHARED
            ${PROJECT_SOURCES}
        )

    # Define properties for Android with Qt 5 after find_package() calls as:
    # set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(SmartCalc_v_2_0
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(SmartCalc_v_2_0 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::PrintSupport)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets Qt6::Charts)

set_target_properties(SmartCalc_v_2_0 PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(SmartCalc_v_2_0)
endif()
