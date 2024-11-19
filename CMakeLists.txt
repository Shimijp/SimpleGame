
cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(SimpleGame VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(SimpleGame main.cpp
        glad.c) # Replace main.cpp with your source files

# Find the GLFW package
find_package(glfw3 REQUIRED)

# Find and link GLEW
find_package(GLEW REQUIRED)
target_link_libraries(SimpleGame PRIVATE GLEW::GLEW)

# Set OpenGL preference
set(OpenGL_GL_PREFERENCE "GLVND")

# Find and link OpenGL
find_package(OpenGL REQUIRED)
target_link_libraries(SimpleGame PRIVATE OpenGL::GL glfw)
