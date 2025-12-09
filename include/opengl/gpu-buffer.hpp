#pragma once 

#include "extern/glad/glad.h"
#include "shape-primitives.hpp"

#include <cstdint>
#include <span>
#include <print>

namespace OGL 
{
  template <typename T>
  concept valid_mesh_span = std::same_as<T, int> || std::same_as<T, float> || std::same_as<T, double>;

  class GPUBuffer
  {
    public:
      GPUBuffer(const std::int32_t allocation_size = 1024, const std::uint16_t draw_type = GL_STATIC_DRAW);
      ~GPUBuffer() = default;
      
      template<valid_mesh_span T>
      auto bindData(std::span<const T> mesh) -> void
      {
        glBufferSubData(GL_ARRAY_BUFFER, total_allocated_bytes_, mesh.size() * sizeof(T), mesh.data());
        total_allocated_bytes_ += mesh.size() * sizeof(T);
        std::println("VRAM Bytes used {}", total_allocated_bytes_);
      }

    private:
      GLuint VBO_ {0};
      std::uint32_t total_allocated_bytes_{0};
  };
}
