#pragma once

#include <SDL3/SDL.h>
#include <memory>
#include <expected>

class Window
{
public:
  Window();
  ~Window();
  
  auto swapWindow() -> void;

  SDL_Window *ptr();

private:
  std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> window_instance_{
      nullptr, &SDL_DestroyWindow};
  SDL_GLContext sdl_context_{nullptr};
};
