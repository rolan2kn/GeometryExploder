cmake_minimum_required(VERSION 3.13)
project(GeometryExploder)

find_package(OpenCV REQUIRED)
set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp ~/glad/src/glad.c ogl_shader_API/util.cpp ogl_shader_API/util.hpp ogl_shader_API/shader_controller.cpp ogl_shader_API/shader_program_controller.cpp model_settings_controller.cpp)
set(HEADER_FILES mesh.h camera.h model.h ogl_shader_API/shader_controller.h ogl_shader_API/shader_program_controller.h  ogl_shader_API/data_buffer.cpp ogl_shader_API/data_buffer.h model_settings_controller.h)

set(dir ${CMAKE_CURRENT_SOURCE_DIR})

#Include library files
include_directories(include)

include_directories(GL/)

include_directories(GeometryExploder ${OpenCV_INCLUDE_DIRS})


add_executable(GeometryExploder ${SOURCE_FILES} ${HEADER_FILES} )

target_link_libraries(GeometryExploder GL GLU glfw assimp X11 Xxf86vm Xrandr pthread Xi dl Xinerama Xcursor ${OpenCV_LIBS} )



