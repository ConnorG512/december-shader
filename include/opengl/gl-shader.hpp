#pragma once

#include "file-operation.hpp"
#include "extern/glad/glad.h"

#include <string_view>
#include <print>

namespace OGL {

struct FragmentShader;
struct VertexShader;

template <typename T>
concept isShader = std::same_as<T, FragmentShader> || std::same_as<T, VertexShader>;

template <isShader T>
class Shader {
  public: 
    Shader(const char* file_path) 
      : shader_data_{FileOperations::readToMemory(file_path)}
      , id_ {shaderId()} 
      {
        const char* shader_source{reinterpret_cast<const char*>(shader_data_->data())};

        glShaderSource(id_, 1, &shader_source, nullptr);
        glCompileShader(id_);
        
        if(const auto result = validate(); !result.has_value())
          throw std::runtime_error(result.error());
      };

    ~Shader() = default;
    
    auto deleteShader() noexcept -> void
    {
      glDeleteShader(id_);
    }

    auto Id() noexcept -> std::int32_t
    {
      return id_;
    }

  private:
    std::expected<std::vector<std::uint8_t>, std::string_view> shader_data_ {};
    std::int32_t id_{-1};
    
    auto shaderId() -> std::int32_t
    {
      if (!shader_data_.has_value())
        throw std::runtime_error("Could not get shader data!");
     
      if constexpr (std::same_as<T, FragmentShader>)
      {
        return glCreateShader(GL_FRAGMENT_SHADER);
      }
      else if constexpr (std::same_as<T, VertexShader>)
      {
        return glCreateShader(GL_VERTEX_SHADER);
      }
    }

    auto validate() noexcept -> std::expected<void, const char*>
    {
      std::int32_t success {-1};
      std::array<char, 512> info_log {};

      glGetShaderiv(id_, GL_COMPILE_STATUS, &success);
      
      if (!success)
      {
        glGetShaderInfoLog(id_, 512, NULL, info_log.data());
        return std::unexpected<const char*>("Failed to validate shader!");

        if constexpr (std::same_as<T, FragmentShader>)
        {
          std::println(stderr, "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n {}" , info_log.data());
        }
        else if constexpr (std::same_as<T, VertexShader>)
        {
          std::println(stderr, "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n {}" , info_log.data());
        }
      }

      return {};
    }
};
}

