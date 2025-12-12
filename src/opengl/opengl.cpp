#include "opengl/opengl.hpp"
#include "extern/glad/glad.h"


auto OGL::setupVBO(std::uint32_t &VBO, std::span<const float> shape) -> void 
{
  glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);  
  glBufferData(GL_ARRAY_BUFFER, shape.size() * sizeof(float), shape.data(), GL_STATIC_DRAW);
}

auto OGL::attachAndLinkShader(std::vector<std::uint32_t> shader_list, std::uint32_t program) -> void
{
  for(const auto& shader : shader_list)
  {
    glAttachShader(program, shader);
  }
  
  glLinkProgram(program);
}

auto OGL::deleteShaders(std::vector<std::uint32_t> shader_list) -> void
{
  for(const auto& shader : shader_list)
  {
    glDeleteShader(shader);
  }
}
