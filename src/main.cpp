#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <random>
#include <vector>

const int WINDOW_WIDTH = 150;
const int WINDOW_HEIGHT = 150;
const int MAX_PARTICLES = 10;
float position = 0.0f;

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> dist(0, WINDOW_WIDTH - 1);
std::uniform_int_distribution<> dist2(0, 4);

struct Particle_Color {
  std::vector<int> color1 = {35, 61, 77, 255};
  std::vector<int> color2 = {254, 127, 45, 255};
  std::vector<int> color3 = {234, 236, 240, 255};
  std::vector<int> color4 = {236, 91, 56, 255};
};

struct Particle {
  int initial_position;
  std::vector<int> color;
};

std::vector<int> PickAColor(int random_number) {
  Particle_Color colors;

  switch (random_number) {
  case 1:
    return colors.color1;
    break;
  case 2:
    return colors.color2;
    break;
  case 3:
    return colors.color3;
    break;
  case 4:
    return colors.color4;
    break;
  }

  return std::vector<int>{255, 255, 255, 255};
}

int main() {
  srand(static_cast<unsigned>(SDL_GetTicks()));
  bool running = true;

  std::vector<Particle *> particles = {};

  SDL_Window *window = nullptr;
  SDL_Renderer *renderer = nullptr;

  SDL_CreateWindowAndRenderer(WINDOW_WIDTH * 5, WINDOW_HEIGHT * 5, 0, &window,
                              &renderer);
  SDL_RenderSetScale(renderer, 5, 5);

  for (int i = 0; i <= MAX_PARTICLES; i++) {
    Particle *p = new Particle();
    p->initial_position = dist(gen);
    p->color = PickAColor(dist2(gen));
    particles.push_back(p);
  }

  while (running) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT ||
          (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)) {
        running = false;
      }
    }

    for (auto *p : particles) {
      SDL_SetRenderDrawColor(renderer, p->color[0], p->color[1], p->color[2],
                             p->color[3]);
      SDL_RenderDrawPoint(renderer, p->initial_position,
                          position += 1.0f / 100.0f);

      SDL_RenderPresent(renderer);
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    position++;
    SDL_Delay(50);
  }

  return 0;
}
