cmake_minimum_required(VERSION 3.15)

project(QMAI-xApp VERSION 0.0.1 LANGUAGES CXX)


add_executable(xapp_qmai 
./src/main.cpp
)

## ADD Libs
include_directories(${CMAKE_SOURCE_DIR}/include)
link_directories(${CMAKE_SOURCE_DIR}/libs)

target_link_libraries(xapp_qmai
                      PUBLIC
                      e42_xapp
                      logger
                      -pthread
                      -lsctp
                      -ldl
                      )