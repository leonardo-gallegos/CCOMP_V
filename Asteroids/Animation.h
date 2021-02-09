#ifndef __ANIMATION_H__
#define __ANIMATION_H__
#include <SFML/Graphics.hpp>
#include <time.h>
#include <list>
#include <cmath>
using namespace sf;

class Animation
{
public:
  float Frame, speed;
  Sprite sprite;
  std::vector<IntRect> frames;

  Animation() {}
	
  
  Animation(Texture &t, int x, int y, int w, int h, int count, float Speed)
  {
  	// Default Frame and speed
    Frame = 0;
    speed = Speed;

    for (int i = 0; i < count; i++)
      frames.push_back(IntRect(x + i * w, y, w, h));

    sprite.setTexture(t);
    sprite.setOrigin(w / 2, h / 2);
    sprite.setTextureRect(frames[0]);
  }

  // Updates animation
  void update()
  {
    Frame += speed;
    int n = frames.size();
    if (Frame >= n)
      Frame -= n;
    if (n > 0)
      sprite.setTextureRect(frames[int(Frame)]);
  }
	
  // End of animation
  bool isEnd()
  {
    return Frame + speed >= frames.size();
  }
};
#endif
