#include "sdl/window.hpp"
#include "extern/glad/glad.h"

#include <print>
#include <cassert>

Window::Window() 
{
  assert(window_instance_ != nullptr);

  // Init video
  if (!SDL_Init(SDL_INIT_VIDEO))
  {
    throw std::runtime_error("Could not init SDL video!");
  }

  if(window_context_ == NULL)
  {
    std::println(stderr, "Failed to create window context. {}", SDL_GetError());
    throw std::runtime_error("Failed to initialise GL Context!");
  }

  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  
  // GLAD load
  if(!gladLoadGLLoader((GLADloadproc) SDL_GL_GetProcAddress))
  {
    throw std::runtime_error("Failed to load GLAD!");
  }
}

Window::~Window()
{
  if (!SDL_GL_DestroyContext(window_context_))
    std::println("Failed to destroy OpenGL context! Error: {}", SDL_GetError());
}

auto Window::swapWindow() -> void
{
  if (!SDL_GL_SwapWindow(window_instance_.get()))
    std::println(stderr, "Failed to swap window! Error: {}", SDL_GetError());
}

SDL_Window *Window::ptr() { return window_instance_.get(); }
