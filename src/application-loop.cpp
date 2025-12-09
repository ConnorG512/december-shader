#include "application-loop.hpp"
#include "extern/glad/glad.h"
#include "shape-primitives.hpp"

#include <SDL3/SDL.h>
#include <print>

App::MainLoop::MainLoop()
{
  // Binding rectangle
  gpu_buffer_.bindData(std::span<const float>(Shapes::rectangle));
  glAttachShader(shader_program_, background_vertex.Id());
  glAttachShader(shader_program_, background_fragment.Id());

  gpu_buffer_.bindData(std::span<const float>(Shapes::triangle));
  glAttachShader(shader_program_, triangle_vertex.Id());
  glAttachShader(shader_program_, triangle_fragment.Id());

  glLinkProgram(shader_program_);

  background_vertex.deleteShader();
  background_fragment.deleteShader();
  triangle_vertex.deleteShader();
  triangle_fragment.deleteShader();
  
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
      triangle_mesh.bindVAO();

      glUseProgram(shader_program_);
      
      background_mesh.draw();
      triangle_mesh.draw();

      current_window_.swapWindow();
    }
  }
  return;
}
