cmake_minimum_required(VERSION 3.15)

project(QMAI-xApp VERSION 0.0.1 LANGUAGES CXX)

## Add libs
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/libs) ## local libs
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/libs/spdlog) ## scplog

## Executable
add_executable(xapp_qmai
./src/main.cpp
)

## link header files
target_include_directories(xapp_qmai PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include 
                        ${CMAKE_CURRENT_SOURCE_DIR}/libs/spdlog/include)

target_link_libraries(xapp_qmai
PUBLIC
qmai_libs
spdlog::spdlog $<$<BOOL:${MINGW}>:ws2_32>
e42_xapp
-pthread
-lsctp
-ldl
)