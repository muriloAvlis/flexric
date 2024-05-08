cmake_minimum_required(VERSION 3.15)

project(QMAI-xApp VERSION 0.0.1 LANGUAGES CXX)

## Libraries fonts
set(LIBS_SOURCES
    libs/logger.cpp
)

## Libraries headers
set(LIBS_HEADERS
    include/logger.hpp
)

## Compile libs as shared objects
add_library(logger SHARED ${LIBS_SOURCES} ${LIBS_HEADERS})

## Executable
add_executable(xapp_qmai 
./src/main.cpp
)

target_link_libraries(xapp_qmai
                      PUBLIC
                      e42_xapp
                      logger
                      -pthread
                      -lsctp
                      -ldl
                      )

# target_link_libraries(xapp_qmai
#                       PUBLIC
#                       logger                
#                       )
                      
target_include_directories(xapp_qmai PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)              