#include "../../include/particles.hpp"

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
