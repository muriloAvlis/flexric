cmake_minimum_required(VERSION 3.15)

project(QMAI-xApp VERSION 0.0.1 LANGUAGES CXX)

## Compile log lib
add_library(logger SHARED libs/logger.cpp)

## Executable
add_executable(xapp_qmai
./src/main.cpp
)

## link header files
target_include_directories(xapp_qmai PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(xapp_qmai
PUBLIC
logger
e42_xapp
-pthread
-lsctp
-ldl
)