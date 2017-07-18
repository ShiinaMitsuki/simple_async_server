# CMakeLists for src derictory

set(PRJ_NAME core)

project(${PRJ_NAME})

aux_source_directory(core SRCS)
aux_source_directory(proto SRCS)

message(STATUS "src SRCS = ${SRCS}")

# compiled as shared library
add_library(${PRJ_NAME} SHARED ${SRCS})
set_target_properties(${PRJ_NAME} PROPERTIES LINKER_LANGUAGE CXX)

# compiled as static library
#add_library(${PRJ_NAME} STATIC ${SRCS})