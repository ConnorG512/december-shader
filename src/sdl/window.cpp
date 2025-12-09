#include "sdl/window.hpp"
#include "extern/glad/glad.h"

#include <print>
#include <cassert>
#include <SDL3/SDL_video.h>

Window::Window() 
{
  // Init video
  if (!SDL_Init(SDL_INIT_VIDEO))
  {
    throw std::runtime_error("Could not init SDL video!");
  }
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  
  window_instance_.reset(SDL_CreateWindow("December Shader", 1280, 720, SDL_WINDOW_OPENGL));
  assert(window_instance_ != nullptr);
  
  sdl_context_ = SDL_GL_CreateContext(window_instance_.get());
  if(sdl_context_ == nullptr)
  {
    std::println(stderr, "Failed to create window context. {}", SDL_GetError());
    throw std::runtime_error("Failed to initialise GL Context!");
  }
  
  int gl_min;
  int gl_max;

  SDL_GL_GetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, &gl_max);
  SDL_GL_GetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, &gl_min);
  std::println("compiled with SDL {}.{}", SDL_MAJOR_VERSION, SDL_MINOR_VERSION);
  std::println("GL Max: {}, GL Min {}.", gl_max, gl_min);
  
  // GLAD load
  if(!gladLoadGLLoader((GLADloadproc) SDL_GL_GetProcAddress))
  {
    throw std::runtime_error("Failed to load GLAD!");
  }
}

Window::~Window()
{
}

auto Window::swapWindow() -> void
{
  if (!SDL_GL_SwapWindow(window_instance_.get()))
    std::println(stderr, "Failed to swap window! Error: {}", SDL_GetError());
}

SDL_Window *Window::ptr() { return window_instance_.get(); }
