#include <SFML/Graphics.hpp>
#include "Menu.h"

Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("fonts/akira.otf"))
	{
		//handle error
	}
	
    logo.loadFromFile("images/title.png");
    logo.setSmooth(true);
    sprite.setTexture(logo);
    sprite.setScale(0.3, 0.3);
    sprite.setPosition(width / 2 - 289, height / 2 - 111 - 100);
	
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Yellow);
	menu[0].setString("PLAY");
	menu[0].setCharacterSize(55);
	menu[0].setPosition(sf::Vector2f(width/2-80,height / (MAX_NUMBER_OF_ITEMS + 1) * 1.7));
	
	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("EXIT");
	menu[1].setCharacterSize(55);
	menu[1].setPosition(sf::Vector2f(width/2-70,height / (MAX_NUMBER_OF_ITEMS + 1) * 2));
	/*
	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("EXIT");
	menu[2].setPosition(sf::Vector2f(width/2,height / (MAX_NUMBER_OF_ITEMS + 1) * 3));
	*/
	selectedItemIndex = 0;
}

Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window)
{
	for(int i=0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
		window.draw(sprite);
	}
}

void Menu::MoveUp()
{
	if(selectedItemIndex-1>=0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Yellow);
	}
}

void Menu::MoveDown()
{
	if(selectedItemIndex+1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Yellow);
	}
}

