#include "pch.h"

#include "Windows.h"

#include "SFML/Graphics.hpp"
#include "Menu.hpp"

/* 
	Menu�� ���� �÷��� �� ���� �޴��� ȣ���� �̿��� �� �ֽ��ϴ�.
	ESC : ���� �޴� ȣ��
	Enter : �޴� ����
*/

Menu::Menu(float width, float height) {

	font.loadFromFile(FILE_menuFont);

	menuText[0].setFont(font);
	menuText[0].setFillColor(SELECTED_ITEM_COLOR);
	menuText[0].setString("Play");
	menuText[0].setCharacterSize(MENU_FONTSIZE);
	menuText[0].setPosition(sf::Vector2f(MENU_TEXT_POSITION_X, MENU_TEXT_POSITION_Y * 1));

	menuText[1].setFont(font);
	menuText[1].setFillColor(DEFAULT_ITEM_COLOR);
	menuText[1].setString("Options");
	menuText[1].setCharacterSize(MENU_FONTSIZE);
	menuText[1].setPosition(sf::Vector2f(MENU_TEXT_POSITION_X, MENU_TEXT_POSITION_Y * 2));

	menuText[2].setFont(font);
	menuText[2].setFillColor(DEFAULT_ITEM_COLOR);
	menuText[2].setString("Exit");
	menuText[2].setCharacterSize(MENU_FONTSIZE);
	menuText[2].setPosition(sf::Vector2f(MENU_TEXT_POSITION_X, MENU_TEXT_POSITION_Y * 3));

}

void Menu::draw(sf::RenderWindow& window)
{
	// Menu�� ��� �� ���� �Լ� ȣ��� menu ��ü���� �׸��� ����
	// getSprite ��� draw�� �����߽��ϴ�.

	// ��� ���� : menu.draw(window);
	for (int i = 0; i < MAX_NUMBER_OF_MENU_ITEMS; i++)
	{
		window.draw(menuText[i]);
	}
}

void Menu::moveUp()
{
		menuText[selectedItemIndex].setFillColor(DEFAULT_ITEM_COLOR);

		if (selectedItemIndex <= 0) selectedItemIndex = MAX_NUMBER_OF_MENU_ITEMS - 1;
		else selectedItemIndex--;

		menuText[selectedItemIndex].setFillColor(SELECTED_ITEM_COLOR);

		Sleep(120);
	
}

void Menu::moveDown()
{
		menuText[selectedItemIndex].setFillColor(DEFAULT_ITEM_COLOR);

		if (selectedItemIndex >= MAX_NUMBER_OF_MENU_ITEMS - 1) selectedItemIndex = 0;
		else selectedItemIndex++;

		menuText[selectedItemIndex].setFillColor(SELECTED_ITEM_COLOR);

		Sleep(120);
	
}