#pragma once

#include "file-operation.hpp"
#include "shape-primitives.hpp"

#include <cstdint>
#include <expected>
#include <cstddef>
#include <vector>
#include <string>
#include <span>

namespace OGL {
  auto setupVBO(std::uint32_t &VBO, std::span<const float> shape = Shapes::triangle) -> void;
  
  auto attachAndLinkShader(std::vector<std::uint32_t> shader_list, std::uint32_t program) -> void;

  auto deleteShaders(std::vector<std::uint32_t> shader_list) -> void;
}
