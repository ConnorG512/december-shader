#include "sdl/window.hpp"

#include <cstdlib>
#include <print>
#include <vector>
#include <expected>
#include <SDL3/SDL.h>
#include <SDL3/SDL_video.h>
#include <iostream>
#include <array>

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

  GLShader vertex_shader ("data/vertex.vert", GL_VERTEX_SHADER);
  GLShader fragment_shader("data/fragment.frag", GL_FRAGMENT_SHADER);
  
  std::uint32_t shader_program{glCreateProgram()};
  glAttachShader(shader_program, vertex_shader.GetId());
  glAttachShader(shader_program, fragment_shader.GetId());
  glLinkProgram(shader_program);

  std::int32_t success{0};
  std::array<char, 512> info_log{};
  glGetProgramiv(shader_program, GL_LINK_STATUS, &success);
  if (!success)
  {
    glGetProgramInfoLog(shader_program, 512, nullptr, info_log.data());
    std::println("ERROR::SHADER::PROGRAM::LINKING_FAILED {}", info_log.data());
    return EXIT_FAILURE;
  }
  vertex_shader.deleteShader();
  fragment_shader.deleteShader();
  
  // Triangle vertices.
  constexpr std::array<float, 9> verticies {
    -0.5f, -0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    0.0f, 0.5f, 0.0f
  };
  
  std::uint32_t VAO {0};
  std::uint32_t VBO {0};
  
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);

  glBindVertexArray(VAO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(verticies), &verticies, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);
  
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);

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
    glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(shader_program);
    glBindVertexArray(VAO);

    glDrawArrays(GL_TRIANGLES, 0, 3);
    
    if (!SDL_GL_SwapWindow(current_window.ptr()))
    {
      std::println("Failed to swap window! Error: {}", SDL_GetError());
      return EXIT_FAILURE;
    }

  }

  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
  glDeleteProgram(shader_program);

  if (!SDL_GL_DestroyContext(sdl_gl_context))
    std::println("Failed to destroy OpenGL context! Error: {}", SDL_GetError());

  SDL_Quit();

  return EXIT_SUCCESS;
}
