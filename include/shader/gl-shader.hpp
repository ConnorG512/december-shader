#pragma once

#include "file-operation.hpp"
#include "extern/glad/glad.h"

#include <vector>
#include <cstdlib>
#include <cstdint>
#include <string_view>

class GLShader   
{
  public:
    GLShader(const char* shader_path, const std::uint32_t shader_type = GL_VERTEX_SHADER);
    ~GLShader() = default;

    auto validateShader() noexcept -> std::expected<void, std::string_view>;
    auto GetId() noexcept -> const std::uint32_t&;
    auto deleteShader() noexcept -> void;

  private:
    std::expected<std::vector<std::uint8_t>, std::string_view> shader_data_{FileOperations::readToMemory("")};
    std::uint32_t id_ {0};
    std::uint32_t VAO_{0};
    std::uint32_t VBO_{0};
};
