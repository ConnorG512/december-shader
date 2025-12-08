#pragma once

#include "shape-primitives.hpp"

#include <cstdint>
#include <span>

namespace OGL {
class Mesh {
  public:
    Mesh(std::span<const float> verticies = Shapes::triangle);
    ~Mesh();

    auto bindVAO() noexcept -> void;
    auto draw() noexcept -> void;
    
  private:
    std::span<const float> mesh_{};
    std::uint32_t VAO_ {0};
};
}
