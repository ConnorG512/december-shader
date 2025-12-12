#include "opengl/shader.hpp"
#include "file-operation.hpp"

#include <utility>
#include <cassert>

OGL::Shader::Shader(const OGL::ShaderType shader_type, const char * shader_path)
  : shader_id_{glCreateShader(std::to_underlying(shader_type))}
{
  assert(shader_path != nullptr); 
  auto raw_shader_data {FileOperations::readToMemory(shader_path)};

  if (!raw_shader_data.has_value())
    throw std::runtime_error(std::format("shader.cpp {}", raw_shader_data.error()));
  const char* shader_source {reinterpret_cast<const char*>(raw_shader_data.value().data())};

  glShaderSource(shader_id_, 1, &shader_source, NULL);
  glCompileShader(shader_id_);
}

auto OGL::Shader::GetId() const noexcept ->  std::uint32_t 
{
  return shader_id_;
}
