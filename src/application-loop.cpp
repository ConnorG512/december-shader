#include "application-loop.hpp"
#include "extern/glad/glad.h"
#include "shape-primitives.hpp"

#include <SDL3/SDL.h>
#include <print>

App::MainLoop::MainLoop()
{
  // Background: 
}

auto App::MainLoop::run() -> void 
{
  bool is_running {true};
  while(is_running)
  {
    SDL_Event event{};
    while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_EVENT_QUIT)
      {
        is_running = false;
      }
      
      // Main Loop.
      glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT);

      current_window_.swapWindow();
    }
  }
  return;
}
