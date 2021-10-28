cmake_minimum_required(VERSION 3.16)
project(Tarot VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_PREFIX_PATH "F:/Qt/6.1.3/mingw81_64")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})

find_package(Qt6 REQUIRED COMPONENTS Widgets)

set(SOURCES
    src/main.cpp
    src/mainwindow.cpp)

set(HEADERS
    src/mainwindow.h)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets)
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/src)

if(CMAKE_BUILD_TYPE STREQUAL "Release")
  set_property(TARGET ${PROJECT_NAME} PROPERTY WIN32_EXECUTABLE true)
endif()

if (WIN32)
    find_program(WINDEPLOYQT_EXECUTABLE NAMES windeployqt HINTS ${CMAKE_PREFIX_PATH} bin)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${WINDEPLOYQT_EXECUTABLE} '${CMAKE_RUNTIME_OUTPUT_DIRECTORY}')
endif()