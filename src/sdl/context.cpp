#include "sdl/context.hpp"
#include "extern/glad/glad.h"

#include <cassert>
#include <print>
#include <SDL3/SDL.h>

SDL::GL::Context::Context(SDL_Window *window_instance)
{
  context_.reset(SDL_GL_CreateContext(window_instance));
  assert(context_ != nullptr);

  // GLAD load
  if(!gladLoadGLLoader((GLADloadproc) SDL_GL_GetProcAddress))
  {
    throw std::runtime_error("Failed to load GLAD!");
  }
}
