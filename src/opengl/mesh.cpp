#include "opengl/mesh.hpp"

#include "extern/glad/glad.h"

Mesh::Mesh(std::span<const float> verticies)
  : mesh_{verticies}
{
  glGenVertexArrays(1, &VAO_);
  glGenBuffers(1, &VBO_);
  
  glBindVertexArray(VAO_);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_);
  glBufferData(GL_ARRAY_BUFFER, mesh_.size() * sizeof(float), mesh_.data(), GL_STATIC_DRAW);
  
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);
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

auto Mesh::draw() noexcept -> void 
{
  glDrawArrays(GL_TRIANGLES, 0, mesh_.size() / 3);
}
