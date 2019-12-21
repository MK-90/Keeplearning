cmake_minimum_required(VERSION 2.8)
add_compile_options(-std=c++11)

aux_source_directory(. SRC_LIST)

project(getPosition)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS} ${SOURCE_DIR} )
add_executable(${PROJECT_NAME}  "main.cpp")
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
