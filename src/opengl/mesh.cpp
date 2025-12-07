#include "opengl/mesh.hpp"

#include "extern/glad/glad.h"
#include "shape-primitives.hpp"


Mesh::Mesh()
{
  glGenVertexArrays(1, &VAO_);
  glGenBuffers(1, &VBO_);
  
  glBindVertexArray(VAO_);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_);
  glBufferData(GL_ARRAY_BUFFER, sizeof(Shapes::triangle), &Shapes::triangle, GL_STATIC_DRAW);
}

Mesh::~Mesh()
{
  glDeleteVertexArrays(1, &VAO_);
  glDeleteBuffers(1, &VBO_);
}

auto Mesh::bindVAO() noexcept -> void
{
    glBindVertexArray(VAO_);
}
