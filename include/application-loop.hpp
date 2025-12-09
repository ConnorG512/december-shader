#pragma once

#include "sdl/window.hpp"
#include "opengl/gpu-buffer.hpp"
#include "opengl/gl-shader.hpp"
#include "opengl/mesh.hpp"

namespace App 
{
  class MainLoop 
  {
    public:
      MainLoop();
      ~MainLoop() = default;
      
      auto run() -> void;     

    private:
      Window current_window_ {};
      OGL::GPUBuffer gpu_buffer_{1024};

      OGL::Shader<OGL::VertexShader> background_vertex{"data/background.vert"};
      OGL::Shader<OGL::FragmentShader> background_fragment{"data/background.frag"};
      OGL::Shader<OGL::VertexShader> triangle_vertex{"data/triangle.vert"};
      OGL::Shader<OGL::FragmentShader> triangle_fragment{"data/triangle.frag"};

      OGL::Mesh background_mesh{Shapes::rectangle};
      OGL::Mesh triangle_mesh{Shapes::triangle};

      std::uint32_t shader_program_{glCreateProgram()};
  };
}
