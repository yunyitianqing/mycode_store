CMAKE_MINIMUM_REQUIRED(VERSION 2.6.4 FATAL_ERROR)
set(root ${CMAKE_SOURCE_DIR}/..)
set(source_dir ${CMAKE_SOURCE_DIR})
set(head_dir ${CMAKE_SOURCE_DIR})

set(source ${source_dir}/blob.cpp ${source_dir}/BlobContour.cpp ${source_dir}/BlobOperators.cpp ${source_dir}/BlobProperties.cpp ${source_dir}/BlobResult.cpp ${source_dir}/ComponentLabeling.cpp)

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${root}/bin)
SET(PROJECT_LIBRARY_PATH ${root}/bin)

SET(LIBRARY_OUTPUT_PATH ${root}/bin) 
FIND_PACKAGE(OpenCV REQUIRED)

INCLUDE_DIRECTORIES(${head_dir} ${root}/blob)

ADD_LIBRARY(cvblob SHARED ${source})

target_link_libraries(cvblob ${OpenCV_LIBS})     
