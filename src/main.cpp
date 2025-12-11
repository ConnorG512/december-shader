#include "sdl/window.hpp"
#include "extern/glad/glad.h"
#include "shape-primitives.hpp"
#include "opengl/opengl.hpp"
#include "opengl/shader.hpp"

#include <SDL3/SDL_video.h>
#include <SDL3/SDL_time.h>
#include <print>

auto main() -> int
{
  SDL_SetAppMetadataProperty("December Shader", "1.0");
  
  // Variables 
  Window current_window{};

  // Setup
  // Rectangle
  
  // Creating a VBO: 
  std::uint32_t VBO_rectangle {};
  OGL::setupVBO(VBO_rectangle);
  
  OGL::Shader rectangle_vertex{OGL::ShaderType::vertex, "data/background.vert"};
  OGL::Shader rectangle_fragment{OGL::ShaderType::fragment, "data/background.frag"};
  
  // Shader Program
  std::uint32_t shader_program_rectangle{glCreateProgram()};
  OGL::attachAndLinkShader({rectangle_vertex.GetId(), rectangle_fragment.GetId()}, shader_program_rectangle);
  glUseProgram(shader_program_rectangle);
  
  // VAO_rectangle:
  std::uint32_t VAO_rectangle {};
  glGenVertexArrays(1, &VAO_rectangle);
  glBindVertexArray(VAO_rectangle);
  
  glBindBuffer(GL_ARRAY_BUFFER, VBO_rectangle);
  glBufferData(GL_ARRAY_BUFFER, Shapes::rectangle.size() * sizeof(float), Shapes::rectangle.data(), GL_STATIC_DRAW);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  // Triangle
  // Creating a VBO: 
  std::uint32_t VBO_Triangle {};
  OGL::setupVBO(VBO_Triangle);
  
  // Vertex Shader:
  std::uint32_t vertex_shader_triangle{glCreateShader(GL_VERTEX_SHADER)};
  auto shader_data{FileOperations::readToMemory("data/triangle.vert")};
  if(!shader_data.has_value())
  {
    std::println("Failed to read shader file! {}", shader_data.error());
    return EXIT_FAILURE;
  }
  const char* shader_source{reinterpret_cast<const char*>(shader_data->data())};
  glShaderSource(vertex_shader_triangle, 1, &shader_source, NULL);
  glCompileShader(vertex_shader_triangle);

  // Fragment Shader
  std::uint32_t fragment_shader_triangle{glCreateShader(GL_FRAGMENT_SHADER)};
  auto frag_shader_data{FileOperations::readToMemory("data/triangle.frag")};
  if(!frag_shader_data.has_value())
  {
    std::println("Failed to read shader file! {}", shader_data.error());
    return EXIT_FAILURE;
  }
  const char* frag_shader_source{reinterpret_cast<const char*>(frag_shader_data->data())};
  glShaderSource(fragment_shader_triangle, 1, &frag_shader_source, NULL);
  glCompileShader(fragment_shader_triangle);

  // Shader Program
  std::uint32_t shader_program_triangle{glCreateProgram()};
  OGL::attachAndLinkShader({vertex_shader_triangle, fragment_shader_triangle}, shader_program_triangle);
  glUseProgram(shader_program_triangle);
  
  // VAO:
  std::uint32_t VAO {};
  glGenVertexArrays(1, &VAO);
  glBindVertexArray(VAO);
  
  glBindBuffer(GL_ARRAY_BUFFER, VBO_Triangle);
  glBufferData(GL_ARRAY_BUFFER, Shapes::triangle.size() * sizeof(float), Shapes::triangle.data(), GL_STATIC_DRAW);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  OGL::deleteShaders({vertex_shader_triangle, fragment_shader_triangle, rectangle_vertex.GetId(), rectangle_fragment.GetId()});
  // Loop
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
      
    }

    // Main Loop.
    glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(shader_program_rectangle);
    glBindVertexArray(VAO_rectangle);
    glDrawArrays(GL_TRIANGLES, 0, 6);

    glUseProgram(shader_program_triangle);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    current_window.swapWindow();
  }
  
  return EXIT_SUCCESS;
}
