cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project("PandaRun")

FIND_LIBRARY(OPENGL_LIBRARY OpenGL)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include /usr/local/include ${CMAKE_CURRENT_SOURCE_DIR})
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib} /usr/local/lib)

add_executable(PandaRun main.cpp Camera.cpp DrawPanda.h DrawPrimitives.h GLUtility.hpp MarkerTracker.cpp MarkerTracker.h PoseEstimation.cpp)

target_link_libraries(PandaRun opencv_core opencv_highgui opencv_imgproc ${OPENGL_LIBRARY} glfw)