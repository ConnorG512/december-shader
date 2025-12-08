#pragma once 

#include "extern/glad/glad.h"
#include "shape-primitives.hpp"

#include <cstdint>
#include <span>

namespace OGL 
{
  template <typename T>
  concept valid_mesh_span = std::same_as<T, int> || std::same_as<T, float> || std::same_as<T, double>;

  class GPUBuffer
  {
    public:
      GPUBuffer();
      ~GPUBuffer() = default;
      
      template<valid_mesh_span T>
      auto bindData(std::span<const T> mesh, const std::uint16_t draw_type = GL_STATIC_DRAW) -> void
      {
        glBufferData(GL_ARRAY_BUFFER, mesh.size() * sizeof(T), mesh.data(), draw_type);
      }

    private:
      GLuint VBO_ {0};
  };
}
