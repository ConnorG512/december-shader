#include "opengl/vao.hpp"
#include "extern/glad/glad.h"

OGL::Vao::Vao()
{
  glGenVertexArrays(1, &id_);
  glBindVertexArray(id_);
}

auto OGL::Vao::id() const noexcept -> std::uint32_t
{
  return id_;
}
