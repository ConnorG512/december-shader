#include "shader/gl-shader.hpp"

#include <print>

GLShader::GLShader(const char* shader_path, std::uint32_t shader_type)
  : shader_data_{FileOperations::readToMemory(shader_path)}
  , id_ {glCreateShader(shader_type)}
{
  if(!shader_data_.has_value())
  {
    throw std::runtime_error(shader_data_.error().data());
  }
  
  const char* shader_source {reinterpret_cast<const char*>(shader_data_->data())};
  glShaderSource(id_, 1, &shader_source, nullptr);
  glCompileShader(id_);
  
  if(const auto result = validateShader(); !result.has_value())
  {
    throw std::runtime_error(result.error().data());
  }
}

auto GLShader::validateShader() noexcept -> std::expected<void, std::string_view>
{
  std::int32_t success {-1};
  std::array<char, 512> info_log {};
  glGetShaderiv(id_, GL_COMPILE_STATUS, &success);
  if (!success)
  {
    glGetShaderInfoLog(id_, 512, NULL, info_log.data());
    std::println(stderr, "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n {}" , info_log.data());
    return std::unexpected<std::string_view>("Failed to valid_ate shader!");
  }

  return {};
}

auto GLShader::GetId() noexcept -> const std::uint32_t&
{
  return id_;
}

auto GLShader::deleteShader() noexcept -> void 
{
  glDeleteShader(id_);
}
