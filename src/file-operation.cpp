#include "file-operation.hpp"

#include <print>
#include <cassert>

namespace FileOperations {

auto readToMemory(const char* file_path) -> std::expected<std::vector<std::uint8_t>, std::string_view> {
  if (!std::filesystem::exists(file_path))
    return std::unexpected("Directory does not exist!");
  
  std::ifstream opened_file {file_path, std::ios::binary};
  if(!opened_file.is_open())
  {
    return std::unexpected<std::string_view>("Could not open File!");
  }

  const auto file_size = [](std::ifstream& file) -> std::int32_t {
    // Seek to the end of the file, grab the offset, store and seek back to the
    // start.

    file.seekg(0, std::ios_base::end);
    const long file_size{file.tellg()};
    assert(file_size > 0);

    file.seekg(0, std::ios_base::beg);

    return file_size;
  }(opened_file);
  
  std::vector<std::uint8_t> output_data (file_size);
  opened_file.read(reinterpret_cast<char*>(output_data.data()), file_size);
  output_data.push_back('\0');
  
  opened_file.close();
  return output_data;
}
}

