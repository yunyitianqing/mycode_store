

CMAKE_MINIMUM_REQUIRED(VERSION 2.6.4 FATAL_ERROR)

#####################################################################
#####   - Prepare for building libraries and runtimes files     #####
#####################################################################

##### Set variables of the input or output directories #####
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY .)
SET(PROJECT_LIBRARY_PATH .)
SET(LIBRARY_OUTPUT_PATH .)

#############################################################

INCLUDE_DIRECTORIES(BEFORE .)

#############################################################
##### - build the darwin framework library              #####
#############################################################

SET(WIT_VISION_CAMERA_LIB_SRCS wit_camera.cpp main.cpp)

FIND_LIBRARY(V4LCONVERT v4lconvert "/usr/local/lib")

FIND_PACKAGE(OpenCV REQUIRED)


ADD_EXECUTABLE(wit_vision_camera ${WIT_VISION_CAMERA_LIB_SRCS})

TARGET_LINK_LIBRARIES(wit_vision_camera ${V4LCONVERT} ${OpenCV_LIBS})







