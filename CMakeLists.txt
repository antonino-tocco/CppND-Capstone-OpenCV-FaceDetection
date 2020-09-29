cmake_minimum_required(VERSION 3.7)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(FaceDetection)

find_package(OpenCV REQUIRED )
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(FaceDetection src/main.cpp src/FaceDetector.cpp src/FaceDetector.h src/CustomVideoCapture.cpp src/CustomVideoCapture.h)

target_link_libraries(FaceDetection ${OpenCV_LIBS})
