#pragma once

#include <fstream>
#include <filesystem>
#include <expected>
#include <vector>

namespace FileOperations {

auto readToMemory(const char* file_path) -> std::expected<std::vector<std::uint8_t>, std::string_view>;

}
