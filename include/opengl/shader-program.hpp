#pragma once 

#include <cstdint>
#include <vector>

namespace OGL 
{
  class ShaderProgram 
  {
    public:
      explicit ShaderProgram(const std::vector<std::uint32_t> shaders);
      ~ShaderProgram();
    
    private:
      std::uint32_t id_{0};
      std::vector<std::uint32_t> used_shaders_{};
  };
}
