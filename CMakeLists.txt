cmake_minimum_required(VERSION 3.28)
project(DecemberShader C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(EXECUTABLE_NAME decembershader)

set(SOURCE_FILES
  src/main.cpp
  src/sdl/window.cpp
  src/file-operation.cpp
  src/opengl/mesh.cpp
  src/extern/glad/glad.c
)

add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})

target_compile_options(${EXECUTABLE_NAME} PRIVATE
  -Wall
  -Wextra
  -Wpedantic
  
)

if(CMAKE_BUILD_TYPE STREQUAL "Debug" AND UNIX AND NOT APPLE)
  target_compile_options(${EXECUTABLE_NAME} PRIVATE 
    -fsanitize=address,undefined
    -ggdb
  )
  target_link_options(${EXECUTABLE_NAME} PRIVATE 
    -fsanitize=address,undefined
  )
endif()

find_package(SDL3 REQUIRED)
target_link_libraries(${EXECUTABLE_NAME} PRIVATE
  SDL3::SDL3
)

target_include_directories(${EXECUTABLE_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/include")

install(TARGETS ${EXECUTABLE_NAME} RUNTIME DESTINATION bin)
