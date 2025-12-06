#pragma once

#include <array>

namespace Shapes {
  inline constexpr std::array<float, 9> triangle {
    -0.5f, -0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    0.0f, 0.5f, 0.0f
  };
  
  inline constexpr std::array<std::uint32_t, 6> rectangle {
    0, 1, 2,
    1, 2, 3,
  };
}
