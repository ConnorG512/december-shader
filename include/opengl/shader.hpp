#pragma once 

#include "extern/glad/glad.h"

#include <cstdint>

namespace OGL {
enum class ShaderType 
{
  vertex = GL_VERTEX_SHADER,
  fragment = GL_FRAGMENT_SHADER,
};

class Shader 
{
  public:
    Shader(OGL::ShaderType shader_type);
    ~Shader() = default;

    auto GetId() const noexcept ->  std::uint32_t;

  private:
    std::uint32_t shader_id_ {0};
};
}
