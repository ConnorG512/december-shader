#pragma once

#include <SDL3/SDL.h>
#include <memory>
#include <expected>
#include <vector>

class Window
{
public:
  Window();
  ~Window() = default;
  
  auto swapWindow() -> void;

  SDL_Window *ptr();

private:
  std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> window_instance_{
      nullptr, &SDL_DestroyWindow};
  SDL_GLContext sdl_context_{nullptr};

  auto setSDLAttr(std::vector<std::pair<SDL_GLAttr, std::int32_t>> attr) const noexcept -> void;
};
