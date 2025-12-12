#include "opengl/render-target.hpp"

OGL::RenderTarget::RenderTarget(const char * file_path)
  : vertex_{OGL::ShaderType::vertex, file_path}
  , fragment_{OGL::ShaderType::fragment, file_path} {}
