#include "pch.h"

#include "Windows.h"

#include "StartMenu.hpp"

StartMenu::StartMenu(float width, float height) {

	startMenuTexture.loadFromFile("images/StartMenu.png");
	startMenuSprite.setTexture(startMenuTexture);
	startMenuSprite.setPosition(0,0);
	
	font.loadFromFile(FILE_menuFont);

	startMenuText[0].setFont(font);
	startMenuText[0].setFillColor(SELECTED_STARTMENU_ITEM_COLOR);
	startMenuText[0].setString("Play");
	startMenuText[0].setCharacterSize(70);
	startMenuText[0].setPosition(sf::Vector2f(100, 420));

	startMenuText[1].setFont(font);
	startMenuText[1].setFillColor(DEFAULT_STARTMENU_ITEM_COLOR);
	startMenuText[1].setString("Options");
	startMenuText[1].setCharacterSize(70);
	startMenuText[1].setPosition(sf::Vector2f(100, 490));

	startMenuText[2].setFont(font);
	startMenuText[2].setFillColor(DEFAULT_STARTMENU_ITEM_COLOR);
	startMenuText[2].setString("Exit");
	startMenuText[2].setCharacterSize(70);
	startMenuText[2].setPosition(sf::Vector2f(100, 560));

	GameTitle.setFont(font);
	GameTitle.setString("Marble of University!");
	GameTitle.setFillColor(GAME_TITLE_COLOR);
	GameTitle.setCharacterSize(130);
	GameTitle.setPosition(sf::Vector2f(150, 100));

}

void StartMenu::moveUp() {
	startMenuText[selectedItemIndex].setFillColor(DEFAULT_STARTMENU_ITEM_COLOR);

	if (selectedItemIndex <= 0) selectedItemIndex = MAX_NUMBER_OF_STARTMENU_ITEMS - 1;
	else selectedItemIndex--;

	startMenuText[selectedItemIndex].setFillColor(SELECTED_STARTMENU_ITEM_COLOR);

	Sleep(120);
}

void StartMenu::moveDown() {
	startMenuText[selectedItemIndex].setFillColor(DEFAULT_STARTMENU_ITEM_COLOR);

	if (selectedItemIndex >= MAX_NUMBER_OF_STARTMENU_ITEMS - 1) selectedItemIndex = 0;
	else selectedItemIndex++;

	startMenuText[selectedItemIndex].setFillColor(SELECTED_STARTMENU_ITEM_COLOR);

	Sleep(120);
}

void StartMenu::draw(sf::RenderWindow& window) {

	window.draw(startMenuSprite);

	window.draw(GameTitle);

	for (int i = 0; i < MAX_NUMBER_OF_STARTMENU_ITEMS; i++)
	{
		window.draw(startMenuText[i]);
	}

}