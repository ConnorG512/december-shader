#include "opengl/gpu-buffer.hpp"
#include "extern/glad/glad.h"

OGL::GPUBuffer::GPUBuffer(const std::int32_t allocation_size, const std::uint16_t draw_type)
{
  // Bind the VBO to the VBO_ int. 
  glGenBuffers(1, &VBO_);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_);
  
  // Allocate a size to the buffer 
  glBufferData(GL_ARRAY_BUFFER, allocation_size, nullptr, draw_type);
}

