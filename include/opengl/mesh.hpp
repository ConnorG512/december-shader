#pragma once

#include "shape-primitives.hpp"

#include <cstdint>
#include <span>

class Mesh {
  public:
    Mesh(std::span<const float> verticies = Shapes::triangle);
    ~Mesh();

    auto bindVAO() noexcept -> void;
    
  private:
    std::uint32_t VAO_ {0};
    std::uint32_t VBO_ {0};
};
