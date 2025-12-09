#include "opengl/mesh.hpp"

#include "extern/glad/glad.h"

OGL::Mesh::Mesh(std::span<const float> verticies, std::size_t offset)
  : mesh_{verticies}
{
  glGenVertexArrays(1, &VAO_);
  
  glBindVertexArray(VAO_);
  glBufferData(GL_ARRAY_BUFFER, mesh_.size() * sizeof(float), mesh_.data(), GL_STATIC_DRAW);
  
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)offset);
  glEnableVertexAttribArray(0);
}

OGL::Mesh::~Mesh()
{
  glDeleteVertexArrays(1, &VAO_);
}

auto OGL::Mesh::bindVAO() noexcept -> void
{
    glBindVertexArray(VAO_);
}

auto OGL::Mesh::draw() noexcept -> void 
{
  glDrawArrays(GL_TRIANGLES, 0, mesh_.size() / 3);
}
