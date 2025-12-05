#include "sdl/window.hpp"

#include <cstdlib>
#include <print>
#include <vector>
#include <expected>
#include <SDL3/SDL.h>
#include <SDL3/SDL_video.h>
#include <iostream>

#include "glad/glad.h"
#include "file-operation.hpp"
#include "shader/gl-shader.hpp"


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
  if(!gladLoadGLLoader((GLADloadproc) SDL_GL_GetProcAddress))
  {
      std::println("Failed to initialise GLAD!");
      return EXIT_FAILURE;
  }

  GLShader vertex_shader ("data/shader/vertex.vert", GL_VERTEX_SHADER);
  GLShader fragment_shader("data/shader/fragment.frag", GL_FRAGMENT_SHADER);
  
  // Triangle vertices.
  constexpr std::array<float, 9> verticies {
    -0.5f, -0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    0.0f, 0.5f, 0.0f
  };

  std::uint32_t VBO {0};
  glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(verticies), &verticies, GL_STATIC_DRAW);

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
      return EXIT_FAILURE;
    }
    
    glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
  }

  if (!SDL_GL_DestroyContext(sdl_gl_context))
    std::println("Failed to destroy OpenGL context! Error: {}", SDL_GetError());

  SDL_Quit();

  return EXIT_SUCCESS;
}
