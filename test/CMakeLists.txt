# CMakeLists for test

add_executable(server_bin main.cpp)
target_link_libraries(server_bin core)

# compiler settings for test
SET(CMAKE_EXE_LINKER_FLAGS "-lboost_system")
SET(CMAKE_BUILD_TYPE Debug)