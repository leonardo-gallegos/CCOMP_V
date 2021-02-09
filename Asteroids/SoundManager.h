#ifndef SOUNDMANAGER
#define SOUNDMANAGER

#include <iostream>
#include <SFML/Audio.hpp>

class SoundManager
{
public:
    SoundManager();
    void Fire();
    void AstHit();
    void Back();
    void End();

private:
    sf::SoundBuffer sb_fire;
    sf::Sound s_fire;
    sf::SoundBuffer sb_astHit;
    sf::Sound s_astHit;
    sf::SoundBuffer sb_back;
    sf::Sound s_back;
    sf::SoundBuffer sb_end;
    sf::Sound s_end;
};

#endif
