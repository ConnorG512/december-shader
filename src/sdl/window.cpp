#include "sdl/window.hpp"
#include "extern/glad/glad.h"

#include <print>
#include <cassert>
#include <SDL3/SDL_video.h>

SDL::Window::Window() 
{
  // Init video
  if (!SDL_Init(SDL_INIT_VIDEO))
  {
    throw std::runtime_error("Could not init SDL video!");
  }

  window_instance_.reset(SDL_CreateWindow("December Shader", 1600, 900, SDL_WINDOW_OPENGL));
  assert(window_instance_ != nullptr);
}

auto SDL::Window::swapWindow() -> void
{
  if (!SDL_GL_SwapWindow(window_instance_.get()))
    std::println(stderr, "Failed to swap window! Error: {}", SDL_GetError());
}

auto SDL::Window::ptr() const noexcept -> SDL_Window* { return window_instance_.get(); };
