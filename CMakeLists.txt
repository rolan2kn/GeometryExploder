cmake_minimum_required(VERSION 3.13)
project(GeometryExploder)

find_package(OpenCV REQUIRED)
set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp ~/glad/src/glad.c util.cpp util.hpp shader_controller.cpp shader_program_controller.cpp model_settings_controller.cpp)
set(HEADER_FILES mesh.h camera.h model.h shader_controller.h model_settings_controller.h shader_program_controller.h  data_buffer.cpp data_buffer.h)

set(dir ${CMAKE_CURRENT_SOURCE_DIR})

#Include library files
include_directories(include)

include_directories(GL/)

include_directories(GeometryExploder ${OpenCV_INCLUDE_DIRS})


add_executable(GeometryExploder ${SOURCE_FILES} ${HEADER_FILES} )

target_link_libraries(GeometryExploder GL GLU glfw assimp X11 Xxf86vm Xrandr pthread Xi dl Xinerama Xcursor ${OpenCV_LIBS} )



