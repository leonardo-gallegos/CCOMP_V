#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include <time.h>
#include <list>
#include <cmath>
using namespace sf;

// Entity heritage
class Player : public Entity
{
public:
  bool drive;

  Player()
  {
    name = "player";
  }

  void update()
  {
    // Screen measures
    // Width
    const int W = sf::VideoMode::getDesktopMode().width;
    // Height
    const int H = sf::VideoMode::getDesktopMode().height;
	
	// Angle to radians
    float DEGTORAD = 0.017453f;
    
    if (drive)
    {
      dx += cos(angle * DEGTORAD) * 0.2;
      dy += sin(angle * DEGTORAD) * 0.2;
    }
    // Deceleration of the spaceship
    else
    {
      dx *= 0.96;
      dy *= 0.96;
    }

    int maxSpeed = 30;
    float speed = sqrt(dx * dx + dy * dy);
    if (speed > maxSpeed)
    {
      dx *= maxSpeed / speed;
      dy *= maxSpeed / speed;
    }

    x += dx;
    y += dy;

    // Avoids spaceship exceed screen limits
    if (x > W)
      x = W;
    if (x < 0)
      x = 0;
    if (y > H)
      y = H;
    if (y < 0)
      y = 0;
  }
};
#endif
