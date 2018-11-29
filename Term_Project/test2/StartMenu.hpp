#ifndef STARTMENU_HPP
#define STARTMENU_HPP

#include "Game.hpp"
#include "Menu.hpp"

class StartMenu: public Menu{

private:

	sf::Texture startMenuTexture;
	sf::Sprite startMenuSprite;

	sf::Font Menufont;
	sf::Font GameTitleFont;
	sf::Text GameTitle;
	sf::Text startMenuText[MAX_NUMBER_OF_STARTMENU_ITEMS];
	int selectedItemIndex = 0;

public:

	enum {
		BUTTON_PLAY = 0,
		BUTTON_OPTION = 1,
		BUTTON_QUIT = 2
	};

	StartMenu() {};
	StartMenu(float width, float height);
	void moveUp();
	void moveDown();
	int getSelectedItemIndex() { return selectedItemIndex; }
	void draw(sf::RenderWindow& window);

};






#endif