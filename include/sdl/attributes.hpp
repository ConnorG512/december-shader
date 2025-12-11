#pragma once 

#include <SDL3/SDL.h>
#include <array>
#include <cstdint>
#include <array>
#include <span>

namespace SDL::GL
{
  struct Attributes 
  {
    Attributes();
    static constexpr auto active_list = std::to_array<std::pair<SDL_GLAttr, std::int32_t>>
    ({
      {SDL_GL_CONTEXT_MAJOR_VERSION, 3},
      {SDL_GL_CONTEXT_MINOR_VERSION, 3},
      {SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE},
    });

    auto setSDLAttr(std::span<const std::pair<SDL_GLAttr, std::int32_t>> attr) const noexcept -> void;
  };
}
