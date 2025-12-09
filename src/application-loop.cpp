#include "application-loop.hpp"
#include "extern/glad/glad.h"
#include "shape-primitives.hpp"

#include <SDL3/SDL.h>
#include <print>

App::MainLoop::MainLoop()
{
  // Background: 
  background_program_ = glCreateProgram();
  glAttachShader(background_program_, background_vertex.Id());
  glAttachShader(background_program_, background_fragment.Id());
  glLinkProgram(background_program_);
  
  // Can be deleted after it has been linked.
  glDeleteShader(background_vertex.Id());
  glDeleteShader(background_fragment.Id());

  // Binding rectangle
  gpu_buffer_.bindData(std::span<const float>(Shapes::rectangle));
  
  // Background: 
  triangle_program_ = glCreateProgram();
  glAttachShader(triangle_program_, triangle_vertex.Id());
  glAttachShader(triangle_program_, triangle_fragment.Id());
  glLinkProgram(triangle_program_);
  
  // Can be deleted after it has been linked.
  glDeleteShader(triangle_vertex.Id());
  glDeleteShader(triangle_fragment.Id());

  // Binding rectangle
  gpu_buffer_.bindData(std::span<const float>(Shapes::triangle));
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

      glUseProgram(background_program_);
      background_mesh.bindVAO();
      background_mesh.draw();
      
      glUseProgram(triangle_program_);
      triangle_mesh.bindVAO();
      triangle_mesh.draw();

      current_window_.swapWindow();
    }
  }
  return;
}
