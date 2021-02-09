#ifndef __ASTEROID_H__
#define __ASTEROID_H__
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include <time.h>
#include <list>
#include <cmath>
using namespace sf;

// Entity heritage
class Asteroid : public Entity
{
public:
  Asteroid()
  {
    dx = rand() % 8 - 4;
    dy = rand() % 8 - 4;
    name = "asteroid";
  }

  void update()
  {
    x += dx;
    y += dy;
    const int W = sf::VideoMode::getDesktopMode().width;
    const int H = sf::VideoMode::getDesktopMode().height;

    if (x > W)
      x = 0;
    if (x < 0)
      x = W;
    if (y > H)
      y = 0;
    if (y < 0)
      y = H;
  }
};
#endif
