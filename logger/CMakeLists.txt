project(logger)
cmake_minimum_required(VERSION 3.10)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/build/bin)

set(HEADERS
    logger.h
)

set(SOURCE
    logger.cpp
)

add_library(logger SHARED ${HEADERS} ${SOURCE})

# -DINTERFACE_INCLUDE_DIR=~/Desktop/plugins/app/inc
target_include_directories(logger PUBLIC ${INTERFACE_INCLUDE_DIR})