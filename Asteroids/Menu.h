#ifndef __MENU_H__
#define __MENU_H__
#pragma once
#include <SFML/Graphics.hpp>

#define MAX_NUMBER_OF_ITEMS 2

class Menu
{
	public:
		Menu(float width, float height);
		~Menu();
		
		void draw(sf::RenderWindow &window);
		void MoveUp();
		void MoveDown();
		int GetPressedItem() {return selectedItemIndex;}
		
	private:
		int selectedItemIndex;
		sf::Font font;
		sf::Text menu[MAX_NUMBER_OF_ITEMS];
		sf::Texture logo;
		sf::Sprite sprite;
};
#endif

