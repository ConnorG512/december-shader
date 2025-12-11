#pragma once

#include "opengl/shader.hpp"

namespace OGL 
{
  class RenderTarget 
  {
    public:
      RenderTarget(const char * file_path);
      
    private:
      Shader vertex_{OGL::ShaderType::vertex, "data/triangle.vertex"};
      Shader fragment_{OGL::ShaderType::fragment, "data/triangle.fragment"};
  };
}
