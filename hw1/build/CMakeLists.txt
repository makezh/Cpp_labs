cmake_minimum_required(VERSION 3.21)
project(build)

set(CMAKE_CXX_STANDARD 14)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS} "../source/opencv_contrib/modules/aruco/samples")
add_executable(build main.cpp)
target_link_libraries(build ${OpenCV_LIBS})