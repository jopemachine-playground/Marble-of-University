#include "pch.h"

#include "Windows.h"

#include "SFML/Graphics.hpp"
#include "Menu.hpp"

/* 
	Menu는 게임 플레이 중 게임 메뉴를 호출해 이용할 수 있습니다.
	ESC : 게임 메뉴 호출
	Enter : 메뉴 선택
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
	// Menu의 경우 한 번의 함수 호출로 menu 객체들을 그리기 위해
	// getSprite 대신 draw를 정의했습니다.

	// 사용 예시 : menu.draw(window);
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