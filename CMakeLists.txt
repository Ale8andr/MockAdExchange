cmake_minimum_required(VERSION 3.9)
project(MockAdExchange)

set(PROJECT_SRCS ${PROJECT_SOURCE_DIR}/main.cpp dsp_service.cpp dsp_service.h)

set(CMAKE_CXX_STANDARD 17)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

find_package(Boost COMPONENTS system REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${PROJECT_SRCS})

target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
