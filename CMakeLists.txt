cmake_minimum_required(VERSION 3.16.3)

project(FRIClient LANGUAGES C CXX)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

# Options
option(FRI_BUILD_EXAMPLES "Build the example executables (Default ON)." ON)

# Setup
set(FRI_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/fri)
set(FRI_LIB_SRC_DIR ${FRI_LIB_DIR}/src)
set(EXAMPLE_DIR ${FRI_LIB_DIR}/example)

# Unzip FRI
if(EXISTS "${FRI_LIB_DIR}")
  message("Removing ${FRI_LIB_DIR} directory ...")
  execute_process(COMMAND ${CMAKE_COMMAND} -E remove_directory "${FRI_LIB_DIR}")
endif()
execute_process(COMMAND unzip -q ${CMAKE_CURRENT_SOURCE_DIR}/FRI-Client-SDK_Cpp_v2.5.zip -d ${FRI_LIB_DIR})

# FRIClient library
set(
  FRI_LIB_SRC_FILES
  ${FRI_LIB_SRC_DIR}/base/friClientApplication.cpp
  ${FRI_LIB_SRC_DIR}/base/friDataHelper.cpp
  ${FRI_LIB_SRC_DIR}/client_lbr/friLBRClient.cpp
  ${FRI_LIB_SRC_DIR}/client_lbr/friLBRCommand.cpp
  ${FRI_LIB_SRC_DIR}/client_lbr/friLBRState.cpp
  ${FRI_LIB_SRC_DIR}/client_trafo/friTransformationClient.cpp
  ${FRI_LIB_SRC_DIR}/connection/friUdpConnection.cpp
  ${FRI_LIB_SRC_DIR}/nanopb-0.2.8/pb_decode.c
  ${FRI_LIB_SRC_DIR}/nanopb-0.2.8/pb_encode.c
  ${FRI_LIB_SRC_DIR}/protobuf/friCommandMessageEncoder.cpp
  ${FRI_LIB_SRC_DIR}/protobuf/friMonitoringMessageDecoder.cpp
  ${FRI_LIB_SRC_DIR}/protobuf/pb_frimessages_callbacks.c
  ${FRI_LIB_SRC_DIR}/protobuf_gen/FRIMessages.pb.c
)

add_library(
  FRIClient
  ${FRI_LIB_SRC_FILES}
)

target_include_directories(
  FRIClient
  PUBLIC
  ${FRI_LIB_DIR}/include
)

target_include_directories(
  FRIClient
  PRIVATE
  ${FRI_LIB_SRC_DIR}/base
  ${FRI_LIB_SRC_DIR}/nanopb-0.2.8
  ${FRI_LIB_SRC_DIR}/protobuf
  ${FRI_LIB_SRC_DIR}/protobuf_gen
)

target_compile_options(FRIClient
  PRIVATE
  -O2
  -Wall
  -DHAVE_SOCKLEN_T
  -DPB_SYSTEM_HEADER="pb_syshdr.h"
  -DPB_FIELD_16BIT
  -DHAVE_STDINT_H
  -DHAVE_STDDEF_H
  -DHAVE_STDBOOL_H
  -DHAVE_STDLIB_H
  -DHAVE_STRING_H
)

# Examples
function(build_example name)

  set(dirname ${EXAMPLE_DIR}/${name})

  add_executable(
    ${name}
    ${dirname}/${name}App.cpp
    ${dirname}/${name}Client.cpp
  )

  target_link_libraries(${name} FRIClient)

endfunction()

if(FRI_BUILD_EXAMPLES)

  build_example(IOAccess)
  build_example(LBRJointSineOverlay)
  build_example(LBRWrenchSineOverlay)
  build_example(TransformationProvider)
  build_example(LBRTorqueSineOverlay)
  build_example(SimulatedTransformationProvider)

endif()
