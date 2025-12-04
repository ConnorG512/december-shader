#include "sdl/window.hpp"

Window::Window(){}

SDL_Window* Window::ptr()
{
  return window_instance_.get();
}
