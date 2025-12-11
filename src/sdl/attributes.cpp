#include "sdl/attributes.hpp"

SDL::GL::Attributes::Attributes()
{
  setSDLAttr(active_list);
}

auto SDL::GL::Attributes::setSDLAttr(std::span<const std::pair<SDL_GLAttr, std::int32_t>> attr) const noexcept -> void
{
  for( const auto& [attribute, value] : attr)
  {
    SDL_GL_SetAttribute(attribute, value);
  }
}
