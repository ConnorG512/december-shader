#pragma once

#include <cstdint>

namespace OGL 
{
  struct Vao
  {
    public:
      Vao();
      ~Vao() = default;
      
      auto id() const noexcept -> std::uint32_t;

    private:
      std::uint32_t id_{};
  };
}
