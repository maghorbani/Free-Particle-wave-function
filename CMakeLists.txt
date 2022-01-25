cmake_minimum_required(VERSION 3.10)

project(QM)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)

find_package(Qt5 COMPONENTS Widgets PrintSupport)

set(target SE-Visualizer)

set(SOURCES main.cpp
            mainwindow.cpp
            qcustomplot.cpp
            consts.h)

set(UI mainwindow.ui)

add_executable(${target} ${SOURCES}
                        ${UI})

target_link_libraries(${target} Qt5::Widgets Qt5::PrintSupport)
