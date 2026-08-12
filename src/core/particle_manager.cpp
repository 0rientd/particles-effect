#include "particle_manager.hpp"
#include "particles.hpp"

#include <random>

std::random_device rd;
std::mt19937 gen(rd());

// 4 = total of colors
std::uniform_int_distribution<> random_particle_color(0, 4);
std::uniform_int_distribution<> random_screen_point(0, 150 - 1);

std::vector<Particle *> particlesLoader(int max_particles) {
  std::vector<Particle *> particles = {};

  for (int i = 0; i <= max_particles; i++) {
    Particle *p = new Particle();
    p->initial_position = random_screen_point(gen);
    p->color = PickAColor(random_particle_color(gen));

    particles.push_back(p);
  }

  return particles;
}
