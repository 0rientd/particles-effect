#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <vector>

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

std::vector<int> PickAColor(int random_number);
void renderParticles(SDL_Renderer *renderer, int position_y,
                     std::vector<Particle *> particles);
