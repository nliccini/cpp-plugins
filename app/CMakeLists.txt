project(plugins-app)
cmake_minimum_required(VERSION 3.10)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/build/bin)

# -DBOOST_ROOT=usr/include/boost
# -DINTERFACE_INCLUDE_DIR=~/Desktop/plugins/app/inc
find_package(Boost COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

add_executable(plugins-app src/main.cpp)
target_include_directories(plugins-app PUBLIC ${INTERFACE_INCLUDE_DIR})
target_link_libraries(plugins-app PUBLIC ${Boost_LIBRARIES} ${CMAKE_DL_LIBS})

# IMPORTANT: To use boost/dll/import.hpp, you need to link ${CMAKE_DL_LIBS} for dlopen, dlclose