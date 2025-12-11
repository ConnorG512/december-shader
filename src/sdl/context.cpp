#include "sdl/context.hpp"
#include "extern/glad/glad.h"

#include <cassert>
#include <print>
#include <SDL3/SDL.h>

SDL::GL::Context::Context(SDL_Window *window_instance)
  : gl_context_{SDL_GL_CreateContext(window_instance)}
{
  assert(gl_context_ != nullptr);

  // GLAD load
  if(!gladLoadGLLoader((GLADloadproc) SDL_GL_GetProcAddress))
  {
    throw std::runtime_error("Failed to load GLAD!");
  }
}

SDL::GL::Context::~Context()
{
  assert(gl_context_ != nullptr);
  if(!SDL_GL_DestroyContext(gl_context_))
    std::println("[sdl-context.cpp] Failed to destroy gl context!");
}
