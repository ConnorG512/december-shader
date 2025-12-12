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
      
      private:
        std::unique_ptr<SDL_GLContextState, decltype(&SDL_GL_DestroyContext)> context_ {nullptr, &SDL_GL_DestroyContext}; 
    };
  }
}
