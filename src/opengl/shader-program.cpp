#include "opengl/shader-program.hpp"
#include "extern/glad/glad.h"

OGL::ShaderProgram::ShaderProgram(const std::vector<std::uint32_t> shaders)
  : id_{glCreateProgram()}
  , used_shaders_{shaders}
{
  for(const auto& shader : used_shaders_)
  {
    glAttachShader(id_, shader);
  }

  glLinkProgram(id_);
  glUseProgram(id_);
}

OGL::ShaderProgram::~ShaderProgram()
{
  for(const auto& shader : used_shaders_)
  {
    glAttachShader(id_, shader);
  }
}

auto OGL::ShaderProgram::use() const noexcept -> void
{
  glUseProgram(id_);
}
