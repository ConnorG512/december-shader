cmake_minimum_required(VERSION 3.28)
project(DecemberShader CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(EXECUTABLE_NAME decembershader)

set(SOURCE_FILES
  src/main.cpp
)

add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})

target_compile_options(${EXECUTABLE_NAME} PRIVATE
  -Wall
  -Wextra
  -Wpedantic
  -fsanitize=address,undefined
  -ggdb
)

target_link_options(${EXECUTABLE_NAME} PRIVATE 
  -fsanitize=address,undefined
)

target_include_directories(${EXECUTABLE_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/include")

install(TARGETS ${EXECUTABLE_NAME} RUNTIME DESTINATION bin)
