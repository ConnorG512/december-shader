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
      SDL_CreateWindow("December Shader", 1280, 720, SDL_WINDOW_OPENGL ), &SDL_DestroyWindow};
  SDL_GLContext window_context_{SDL_GL_CreateContext(window_instance_.get())};
};
