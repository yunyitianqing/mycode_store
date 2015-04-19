CMAKE_MINIMUM_REQUIRED(VERSION 2.6.4 FATAL_ERROR)
set(root ${CMAKE_SOURCE_DIR}/..)
set(source_dir ${CMAKE_SOURCE_DIR})
set(head_dir ${CMAKE_SOURCE_DIR})

set(source ${source_dir}/findcolor.cpp ${source_dir}/imgpro.cpp)

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${root}/bin)
SET(PROJECT_LIBRARY_PATH ${root}/bin)

SET(LIBRARY_OUTPUT_PATH ${root}/bin) 
FIND_PACKAGE(OpenCV REQUIRED)
FIND_LIBRARY(CVBLOB cvblob ${PROJECT_LIBRARY_PATH})
INCLUDE_DIRECTORIES(${head_dir} ${root}/blob)

ADD_LIBRARY(imgpro_thresh SHARED ${source})

target_link_libraries(imgpro_thresh ${CVBLOB} ${OpenCV_LIBS})     
