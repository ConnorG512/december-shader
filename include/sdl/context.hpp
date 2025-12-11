#pragma once 

#include <SDL3/SDL_video.h>
#include <memory>

namespace SDL
{
  class Window;
  
  namespace GL {
    class Context
    {
      public:
        explicit Context(SDL_Window *window_instance);
        ~Context();
      
      private:
        SDL_GLContext gl_context_{nullptr};
    };
  }
}
