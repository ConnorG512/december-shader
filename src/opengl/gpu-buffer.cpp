#include "opengl/gpu-buffer.hpp"
#include "extern/glad/glad.h"

OGL::GPUBuffer::GPUBuffer()
{
  glGenBuffers(1, &VBO_);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_);
}

