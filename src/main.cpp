#include <cstdlib>
#include <print>

#include <SDL3/SDL.h>
#include <SDL3/SDL_video.h>

auto main() -> int {

  SDL_SetAppMetadataProperty("December Shader", "1.0");

  if (!SDL_Init(SDL_INIT_VIDEO)) {
    std::println("Could not init SDL video! Error: {}", SDL_GetError());
    return EXIT_FAILURE;
  }

  const auto sdl_window {SDL_CreateWindow("December Shader", 1280, 720, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE)};
  if( sdl_window == nullptr) {
    std::println("Could not create SDL window! Error: {}", SDL_GetError());
    return EXIT_FAILURE;
  }

  auto sdl_gl_context {SDL_GL_CreateContext(sdl_window)};

  bool done {false};

  while (!done)
  {
    SDL_Event event;

    while(SDL_PollEvent(&event))
    {
      if(event.type == SDL_EVENT_QUIT)
      {
        done = true;
      }
    }

    // Logic
    if(!SDL_GL_SwapWindow(sdl_window))
    {
      std::println("Failed to swap window! Error: {}", SDL_GetError());
    }
  }

  if(!SDL_GL_DestroyContext(sdl_gl_context)) 
    std::println("Failed to destroy OpenGL context! Error: {}", SDL_GetError());
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();

  return EXIT_SUCCESS;
}
