#include "sdl/window.hpp"
#include "sdl/attributes.hpp"
#include "extern/glad/glad.h"
#include "shape-primitives.hpp"
#include "opengl/opengl.hpp"
#include "opengl/shader.hpp"
#include "opengl/shader-program.hpp"
#include "opengl/vao.hpp"

#include <SDL3/SDL_video.h>
#include <SDL3/SDL_time.h>
#include <print>

auto main() -> int
{
  SDL_SetAppMetadataProperty("December Shader", "1.0");
  
  // Variables 
  SDL::GL::Attributes sdl_attributes{};
  Window current_window{};

  // Setup
  // Rectangle
  
  // Creating a VBO: 
  std::uint32_t VBO_rectangle {};
  OGL::setupVBO(VBO_rectangle);
  
  OGL::Shader rectangle_vertex{OGL::ShaderType::vertex, "data/background.vert"};
  OGL::Shader rectangle_fragment{OGL::ShaderType::fragment, "data/background.frag"};
  OGL::ShaderProgram rectangle_program({rectangle_vertex.GetId(), rectangle_fragment.GetId()});
  OGL::Vao rectangle_vao{};

  glBindBuffer(GL_ARRAY_BUFFER, VBO_rectangle);
  glBufferData(GL_ARRAY_BUFFER, Shapes::rectangle.size() * sizeof(float), Shapes::rectangle.data(), GL_STATIC_DRAW);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  // Triangle
  // Creating a VBO: 
  std::uint32_t VBO_Triangle {};
  OGL::setupVBO(VBO_Triangle);
  
  OGL::Shader triangle_vertex{OGL::ShaderType::vertex, "data/triangle.vert"};
  OGL::Shader triangle_fragment{OGL::ShaderType::fragment, "data/triangle.frag"};
  OGL::ShaderProgram triangle_program({triangle_vertex.GetId(), triangle_fragment.GetId()});
  OGL::Vao triangle_vao{};

  glBindBuffer(GL_ARRAY_BUFFER, VBO_Triangle);
  glBufferData(GL_ARRAY_BUFFER, Shapes::triangle.size() * sizeof(float), Shapes::triangle.data(), GL_STATIC_DRAW);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  OGL::deleteShaders({triangle_vertex.GetId(), triangle_fragment.GetId(), rectangle_vertex.GetId(), rectangle_fragment.GetId()});
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

    rectangle_program.use();
    glBindVertexArray(rectangle_vao.id());
    glDrawArrays(GL_TRIANGLES, 0, 6);
    
    triangle_program.use();
    glBindVertexArray(triangle_vao.id());
    glDrawArrays(GL_TRIANGLES, 0, 3);

    current_window.swapWindow();
  }
  
  return EXIT_SUCCESS;
}
