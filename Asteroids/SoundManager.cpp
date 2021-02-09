#include "SoundManager.h"
#include <iostream>

using namespace sf;
using namespace std;

// Constructor
SoundManager::SoundManager()
{
    if (!sb_fire.loadFromFile("shoot.wav"))
    {
        cout << "ERROR: sounds/fire.wav didn't load" << endl;
    }
    else
    {
        s_fire.setBuffer(sb_fire);
    }

    if (!sb_astHit.loadFromFile("expl1.wav"))
    {
        cout << "ERROR: sounds/explo_asteroid.wav didn't load" << endl;
    }
    else
    {
        s_astHit.setBuffer(sb_astHit);
    }

    if (!sb_back.loadFromFile("background.wav"))
    {
        cout << "ERROR: sounds/explo_asteroid.wav didn't load" << endl;
    }
    else
    {
        s_back.setBuffer(sb_back);
    }
    if (!sb_end.loadFromFile("end.wav"))
    {
        cout << "ERROR: sounds/explo_asteroid.wav didn't load" << endl;
    }
    else
    {
        s_end.setBuffer(sb_end);
    }
}

//Functions for every sound
void SoundManager::Fire()
{
    s_fire.play();
}

void SoundManager::AstHit()
{
    s_astHit.play();
}

void SoundManager::Back()
{
    s_back.play();
}

void SoundManager::End()
{
    s_end.play();
}
