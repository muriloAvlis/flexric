cmake_minimum_required(VERSION 3.15)

project(QMAI-xApp VERSION 0.0.1 LANGUAGES CXX)

add_executable(xapp_qmai 
		main.cpp
              )

 target_link_libraries(xapp_qmai
                      PUBLIC
                      e42_xapp
                      -pthread
                      -lsctp
                      -ldl
                      )