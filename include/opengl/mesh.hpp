#pragma once

#include <cstdint>

class Mesh {
  public:
    Mesh();
    ~Mesh();

    auto bindVAO() noexcept -> void;
    
  private:
    std::uint32_t VAO_ {0};
    std::uint32_t VBO_ {0};
};
