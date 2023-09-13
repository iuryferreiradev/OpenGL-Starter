cmake_minimum_required(VERSION 3.20)

# Sets the path to the vcpkg toolchain
set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")

# Sets the c++ standard
set(CMAKE_CXX_STANDARD 20)

# Project name
project(opengl-starter CXX)

# Source files
set(SRC
  src/main.cpp

  src/file/file.cpp
  src/file/file.hpp

  src/shader/shader.cpp
  src/shader/shader.hpp

  src/state/state.cpp
  src/state/state.hpp

  src/window/window.cpp
  src/window/window.hpp
)

# Finds the packages from vcpkg.json install location
find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

# Create executable with project name based on source files
add_executable(${PROJECT_NAME} ${SRC})

# Link the libraries
target_link_libraries(${PROJECT_NAME} PRIVATE glfw glad::glad glm::glm)

# Custom command to copy the assets folder after the build process
add_custom_command(
  TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory
  ${CMAKE_SOURCE_DIR}/assets ${CMAKE_BINARY_DIR}/Debug/assets
)

# Makes sure the command to copy folder is executed
add_custom_target(
  copy_data_folder ALL
  DEPENDS ${CMAKE_BINARY_DIR}/Debug/assets
)