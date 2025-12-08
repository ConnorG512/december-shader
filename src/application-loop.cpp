#include "application-loop.hpp"
#include "extern/glad/glad.h"
#include "shape-primitives.hpp"

#include <SDL3/SDL.h>
#include <print>

App::MainLoop::MainLoop()
{
  gpu_buffer_.bindData(std::span<const float>(Shapes::rectangle));

  glAttachShader(shader_program_, background_vertex.Id());
  glAttachShader(shader_program_, background_fragment.Id());
  glLinkProgram(shader_program_);

  background_vertex.deleteShader();
  background_fragment.deleteShader();
  
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
      
      background_mesh.bindVAO();
      background_mesh.draw();

      glUseProgram(shader_program_);

      current_window_.swapWindow();
    }
  }
  return;
}
