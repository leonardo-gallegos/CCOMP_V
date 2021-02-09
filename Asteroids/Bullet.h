#ifndef __BULLET_H__
#define __BULLET_H__
#include <SFML/Graphics.hpp>
#include "Entity.h"	
#include <time.h>
#include <list>
#include <cmath>
using namespace sf;

// Entity heritage
class Bullet: public Entity
{
   public:
   Bullet()
   {
     name="bullet";
   }

   void  update()
   {
	const int W = sf::VideoMode::getDesktopMode().width;
	const int H = sf::VideoMode::getDesktopMode().height;
	float DEGTORAD = 0.017453f;
     dx=cos(angle*DEGTORAD)*25;
     dy=sin(angle*DEGTORAD)*25;
     // angle+=rand()%7-3;
     x+=dx;
     y+=dy;

     if (x>W || x<0 || y>H || y<0) life=0;
   }

};
#endif


