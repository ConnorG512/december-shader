#include "opengl/mesh.hpp"

#include "extern/glad/glad.h"

Mesh::Mesh(std::span<const float> verticies)
{
  glGenVertexArrays(1, &VAO_);
  glGenBuffers(1, &VBO_);
  
  glBindVertexArray(VAO_);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_);
  glBufferData(GL_ARRAY_BUFFER, verticies.size() * sizeof(float), verticies.data(), GL_STATIC_DRAW);
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
