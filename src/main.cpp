#include "sdl/window.hpp"

#include <cstdlib>
#include <print>

#include <SDL3/SDL.h>
#include <SDL3/SDL_video.h>

auto main() -> int
{

  SDL_SetAppMetadataProperty("December Shader", "1.0");

  if (!SDL_Init(SDL_INIT_VIDEO))
  {
    std::println("Could not init SDL video! Error: {}", SDL_GetError());
    return EXIT_FAILURE;
  }

  Window current_window{};

  auto sdl_gl_context{SDL_GL_CreateContext(current_window.ptr())};

  bool done{false};

  while (!done)
  {
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_EVENT_QUIT)
      {
        done = true;
      }
    }

    // Logic
    if (!SDL_GL_SwapWindow(current_window.ptr()))
    {
      std::println("Failed to swap window! Error: {}", SDL_GetError());
    }
  }

  if (!SDL_GL_DestroyContext(sdl_gl_context))
    std::println("Failed to destroy OpenGL context! Error: {}", SDL_GetError());

  SDL_Quit();

  return EXIT_SUCCESS;
}
