#pragma once

#include <SDL3/SDL.h>
#include <memory>
#include <expected>
#include <vector>

namespace SDL {
class Window
{
public:
  Window();
  auto swapWindow() -> void;
  auto ptr() const noexcept -> SDL_Window*;

private:
  std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> window_instance_{
      nullptr, &SDL_DestroyWindow};

  auto setSDLAttr(std::vector<std::pair<SDL_GLAttr, std::int32_t>> attr) const noexcept -> void;
};
}
