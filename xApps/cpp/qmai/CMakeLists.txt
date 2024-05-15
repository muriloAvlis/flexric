cmake_minimum_required(VERSION 3.15)

project(QMAI-xApp VERSION 0.0.1 LANGUAGES CXX)

## spdlog log level env
add_compile_definitions(SPDLOG_ACTIVE_LEVEL)

## Add libs
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/libs) ## local libs

## build external libs
Include(FetchContent)
FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG v1.x
)
FetchContent_MakeAvailable(spdlog)
include_directories(${spdlog_SOURCE_DIR}/include/spdlog)

## Executable
add_executable(xapp_qmai
./src/main.cpp
)

## link header files
target_include_directories(xapp_qmai PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(xapp_qmai
PUBLIC
qmai_libs
spdlog::spdlog $<$<BOOL:${MINGW}>:ws2_32>
e42_xapp
-pthread
-lsctp
-ldl
)