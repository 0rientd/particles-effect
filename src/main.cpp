#include "../include/particles.hpp"
#include <../include/particle_manager.hpp>

#include <vector>

// frame time 16ms = 60fps
const int FRAME_TIME = 16;
const int WINDOW_WIDTH = 150;
const int WINDOW_HEIGHT = 150;
const int MAX_PARTICLES = 20;

float position_y = 0.0f;

int main() {
  SDL_Window *window = nullptr;
  SDL_Renderer *renderer = nullptr;

  std::vector<Particle *> particles = {};

  bool running = true;

  srand(static_cast<unsigned>(SDL_GetTicks()));

  SDL_CreateWindowAndRenderer(WINDOW_WIDTH * 5, WINDOW_HEIGHT * 5, 0, &window,
                              &renderer);
  SDL_RenderSetScale(renderer, 5, 5);

  particles = particlesLoader(MAX_PARTICLES);

  while (running) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT ||
          (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)) {
        running = false;
      }
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    renderParticles(renderer, position_y, particles);

    if (position_y >= WINDOW_HEIGHT) {
      position_y = 1.0f;

      particles.clear();
      particles = particlesLoader(MAX_PARTICLES);
    } else {
      position_y++;
    }

    SDL_Delay(FRAME_TIME);
  }

  return 0;
}
