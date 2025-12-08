#include "sdl/window.hpp"
#include "application-loop.hpp"

#include <SDL3/SDL_video.h>
#include <SDL3/SDL_time.h>

auto main() -> int
{
  SDL_SetAppMetadataProperty("December Shader", "1.0");
  App::MainLoop application_loop{};
  
  application_loop.run();
  
  return EXIT_SUCCESS;
}
    //Getting Time for the phasing colour:
    //std::uint64_t current_time {SDL_GetTicks() / 1000};
    //std::int32_t time_location {glGetUniformLocation(shader_program, "time")};
    //glUniform1f(time_location, current_time);
    
    // Logic

