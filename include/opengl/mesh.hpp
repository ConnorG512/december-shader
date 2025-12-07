#pragma once

#include <cstdint>

class Mesh {
  public:
    Mesh();
    ~Mesh();
    
  private:
    std::uint32_t VAO_ {0};
    std::uint32_t VBO_ {0};
};
