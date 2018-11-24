#ifndef MENU_H
#define MENU_H

#include "SFML/Graphics.hpp"
#include "Game.hpp"

enum MenuButton {
	BUTTON_PLAY = 0,
	BUTTON_OPTION = 1,
	BUTTON_QUIT = 2
};

class Menu {

	private:
		sf::Font font;
		sf::Text menuText[MAX_NUMBER_OF_MENU_ITEMS];
		int selectedItemIndex = 0;
	
	public:
		Menu(float width, float height);
		void draw(sf::RenderWindow& window);

		void moveUp();
		void moveDown();
		int getSelectedItemIndex() { return selectedItemIndex; }

};




#endif
