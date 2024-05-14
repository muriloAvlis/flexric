#### QMAI-xApp Libraries ####

cmake_minimum_required(VERSION 3.15)

# source files
set(SOURCES
    kpmManager.cpp
    rnib.cpp
)

# header files
set(HEADERS
    ../include/kpmManager.hpp
    ../include/rnib.hpp
)

## Compile libs
add_library(qmai_libs SHARED ${SOURCES} ${HEADERS})

## link header files
target_include_directories(qmai_libs PUBLIC ../include
                            ${CMAKE_CURRENT_SOURCE_DIR}/spdlog/include)

target_link_libraries(qmai_libs
PUBLIC
e42_xapp
spdlog::spdlog $<$<BOOL:${MINGW}>:ws2_32>
-pthread
-lsctp
-ldl
)
