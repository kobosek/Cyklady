cmake_minimum_required(VERSION 2.8)

project(ControlBoard)

add_definitions("-std=c++14 -Ofast")

set(LIBRARY_NAME ControlBoard)
set(SOURCE_DIR source)
set(INCLUDE_DIR include)

AUX_SOURCE_DIRECTORY(${SOURCE_DIR} SRC_LIST)

FILE (GLOB INCLUDE_LIST include/*.hpp)

ADD_LIBRARY(${PROJECT_NAME} STATIC ${SRC_LIST} ${INCLUDE_LIST})

TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)

ADD_SUBDIRECTORY(test)
