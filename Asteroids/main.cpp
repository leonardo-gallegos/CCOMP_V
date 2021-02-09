#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Menu.h"
#include "Animation.h"
#include "Entity.h"
#include "Asteroid.h"
#include "Bullet.h"
#include "Player.h"
#include "SoundManager.h"
#include <time.h>
#include <list>
#include <cmath>
#include <string>

using namespace std;

using namespace sf;

const int W = sf::VideoMode::getDesktopMode().width;
const int H = sf::VideoMode::getDesktopMode().height;

float DEGTORAD = 0.017453f;

bool isCollide(Entity *a, Entity *b)
{
  // Boolean: shows if difference x^2 + y^2 < R^2
  return (b->x - a->x) * (b->x - a->x) +
         (b->y - a->y) * (b->y - a->y) <
         (a->R + b->R) * (a->R + b->R);
}

////////////////////////////////////////////////////////////////////
int main()
{
  bool turn_on = 0;
  // score
  int score = 0;
  SoundManager gameSounds;
  gameSounds.Back();
  srand(time(0));

  //ventana menu//
  sf::RenderWindow menu_ventana(sf::VideoMode(W, H), "Asteroids!", sf::Style::Fullscreen); //sf::Style::Fullscreen
  menu_ventana.setFramerateLimit(60);
  Menu menu(menu_ventana.getSize().x, menu_ventana.getSize().y);

  Texture sp, sp_go, bg, ex, rk, bt, rs, se;
  sp.loadFromFile("images/spaceship5_f.png");
  sp_go.loadFromFile("images/sps1.png");
  bg.loadFromFile("images/background.png");
  ex.loadFromFile("images/explosions/type_C.png");
  rk.loadFromFile("images/rock.png");
  bt.loadFromFile("images/fire_red.png");
  rs.loadFromFile("images/rock_small.png");
  se.loadFromFile("images/explosions/type_B.png");

  // Smoothing
  sp.setSmooth(true);
  bg.setSmooth(true);
  rk.setSmooth(true);

  Sprite background(bg);
	
  double W_screen = sf::VideoMode::getDesktopMode().width;
  double H_screen = sf::VideoMode::getDesktopMode().height;
  double factor_x = W_screen / 3840;
  double factor_y = H_screen / 2160;
  background.setScale(factor_x, factor_y);

  Animation sExplosion(ex, 0, 0, 256, 256, 48, 0.5);
  Animation sRock(rk, 0, 0, 53, 63, 30, 0.2);
  Animation sRock_small(rs, 0, 0, 64, 64, 16, 0.2);
  Animation sBullet(bt, 0, 0, 32, 64, 16, 0.8);
  Animation sPlayer(sp, 0, 0, 70, 90, 1, 0);
  Animation sPlayer_go(sp_go, 0, 0, 70, 90, 4, 0.1);
  Animation sExplosion_ship(se, 0, 0, 192, 192, 64, 0.5);

  std::list<Entity *> entities;

  // Respawn in screen a maximum of 35 asteroids
  for (int i = 0; i < 35; i++)
  {
    Asteroid *a = new Asteroid();
    // Position each asteroid at a random location
    a->settings(sRock, rand() % W, rand() % H, rand() % 360, 25);
    entities.push_back(a);
  }
  
  // Respawn sapceship in the middle of the screen
  Player *p = new Player();
  p->settings(sPlayer, W / 2, H / 2, 0, 20);
  entities.push_back(p);

  //score///
  sf::Text text;
  sf::Font font;
  sf::Text text_esc;
  if (!font.loadFromFile("fonts/BittypixMonospace.otf"))
  {
    //handle error
  }

  while (menu_ventana.isOpen() && turn_on == 0)
  {
    sf::Event event;
    
    while (menu_ventana.pollEvent(event))
    {
      switch (event.type)
      {
      case sf::Event::KeyReleased:
        switch (event.key.code)
        {
        case sf::Keyboard::Up:
          menu.MoveUp();
          break;

        case ::sf::Keyboard::Down:
          menu.MoveDown();
          break;

        case sf::Keyboard::Return:
          switch (menu.GetPressedItem())
          {
          case 0:
            cout << "Enter play" << endl;
            turn_on = 1;
            menu_ventana.close();
            break;
          case 1:
            menu_ventana.close();
            break;
          }

          break;
        }
        break;

      case sf::Event::Closed:
        menu_ventana.close();

        break;
      }

      menu_ventana.clear();
      menu_ventana.draw(background);
      menu.draw(menu_ventana);
      menu_ventana.display();
    }
  }

  //ventana juego///
  sf::RenderWindow app(sf::VideoMode(W, H), "Asteroids!", sf::Style::Fullscreen); //sf::Style::Fullscreen
  app.setFramerateLimit(60);
  app.draw(background);
  /////main loop/////
  while (app.isOpen() && turn_on == 1)
  {
    Event event;
    while (app.pollEvent(event))
    {

      Vector2i m_position;
      m_position = Mouse::getPosition(app);

      double dif_x, dif_y;
      dif_x = m_position.x - p->x;
      dif_y = m_position.y - p->y;
      p->angle = (-atan2(dif_x, dif_y) * 180 / 3.14) + 90;

      text_esc.setFont(font);
      text_esc.setString("Press ESC to exit");
      text_esc.setFillColor(sf::Color::White);
      text_esc.setCharacterSize(20);
      text_esc.setPosition(10, 10);

      text.setFont(font);
      if (score == 0)
        text.setString("00000000" + to_string(score));
      else if ((score < 100) && (score > 0))
        text.setString("0000000" + to_string(score));
      else if (score < 1000)
        text.setString("000000" + to_string(score));
      else if (score < 10000)
        text.setString("00000" + to_string(score));
      else if (score < 100000)
        text.setString("0000" + to_string(score));
      else if (score < 1000000)
        text.setString("000" + to_string(score));
      else if (score < 10000000)
        text.setString("00" + to_string(score));
      else if (score < 100000000)
        text.setString("0" + to_string(score));
      else if (score < 1000000000)
      text.setString(to_string(score));
      text.setFillColor(sf::Color::White);
      text.setCharacterSize(30);
      text.setPosition(W / 2 - 135, 10);

      if (event.type == Event::Closed)
        app.close();

      // Fire bullet
      if (event.type == Event::MouseButtonPressed) {
        // Using left click button
        if (event.mouseButton.button == Mouse::Left)
        {
          // New bullet
          Bullet *b = new Bullet();
          // Fire sound
          gameSounds.Fire();
          b->settings(sBullet, p->x, p->y, p->angle, 10);
          entities.push_back(b);
        }
      }
    }

    // Bool drive ->  up key is pressed
    if (Keyboard::isKeyPressed(Keyboard::Up))
      // Drive -> true 
      p->drive = true;
    else
      // Drive -> false (Decelerate)
      p->drive = false;

    for (auto a : entities)
    {
      for (auto b : entities)
      {
        // Coliision between asteroid and bullet
        if (a->name == "asteroid" && b->name == "bullet")
          if (isCollide(a, b))
          {
			// Object ready to be deleted from memory
            a->life = false;
            b->life = false;
            // Sound of bullet hit on asteroid
			gameSounds.AstHit();
        	Entity *e = new Entity();
            e->settings(sExplosion, a->x, a->y);
            e->name = "explosion";
            entities.push_back(e);
            score = score + 10;
			
			if (rand() % 5 == 0) {
	            for (int i = 0; i < 2; i++)
	            {
	              // Dynamic memory allocation of object Asteroid 
	              Entity *e = new Asteroid();
	              // Creates new small Asteroid
	              e->settings(sRock_small, a->x, a->y, rand() % 360, 15);
	              entities.push_back(e);
	            }
	    	}
          }

        if (a->name == "player" && b->name == "asteroid")
          if (isCollide(a, b))
          {
            gameSounds.AstHit();
            b->life = false;
            // Dynamic memory allocation of object Entity
            Entity *e = new Entity();
            e->settings(sExplosion_ship, a->x, a->y);
            e->name = "explosion";
            entities.push_back(e);
            p->settings(sPlayer, W / 2, H / 2, 0, 20);
            p->dx = 0;
            p->dy = 0;
            score = 0;
          }
      }
    }

    if (p->drive)
      p->anim = sPlayer_go;
    else
      p->anim = sPlayer;

    for (auto e : entities)
      if (e->name == "explosion")
        if (e->anim.isEnd())
          e->life = 0;

    if (rand() % 150 == 0)
    {
    	// Respawn two asteroids randomly (rand() % 150) == 0
    	for (int i = 0; i < 3; i++)
	    { 
		  // Dynamic memory allocation of object asteroid  	
	      Asteroid *a = new Asteroid();
	      a->settings(sRock, 0, rand() % H, rand() % 360, 25);
	      entities.push_back(a);
		}
    }

    for (auto i = entities.begin(); i != entities.end();)
    {
      Entity *e = *i;

      e->update();
      e->anim.update();
		
	  // Deletes object when life == false
	  // life == false, means object has exploded (ending explosion animation)
      if (e->life == false)
      {
        i = entities.erase(i);
        // Deallocates memory from heap
        delete e;
      }
      else
        i++;
    }

    //Usar la tecla Esc para cerrar el juego////
    if (Keyboard::isKeyPressed(Keyboard::Escape))
      app.close();

    //////draw//////
    app.draw(background);

    app.draw(text);
    app.draw(text_esc);

    for (auto i : entities)
      i->draw(app);
    app.display();
  }

  return 0;
}
