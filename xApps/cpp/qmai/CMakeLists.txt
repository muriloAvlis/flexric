project(QMAI-xApp VERSION 0.0.1 LANGUAGES CXX)

add_executable(xapp_qmai 
		main.cpp
                ../../../../src/util/alg_ds/alg/defer.c
              )

 target_link_libraries(xapp_qmai
                      PUBLIC
                      e42_xapp
                      -pthread
                      -lsctp
                      -ldl
                      )