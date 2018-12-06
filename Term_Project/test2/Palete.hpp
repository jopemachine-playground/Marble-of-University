#include "SFML/Graphics.hpp"

#include "DrawableObject.hpp"
#include "loadAndInit.hpp"

DrawableObject palete[100];

enum paleteNumber {

	// ※ 0 : 게임판
	GAME_BOARD = 0,

	// ※ 1 ~ 4 : 플레이어 Piece 객체 상수, 최대 4명.
	PLAYER1_PIECE = 1,
	PLAYER2_PIECE = 2,
	PLAYER3_PIECE = 3,
	PLAYER4_PIECE = 4,

	// ※ 5, 6, 7 : 주사위 2개와 주사위 패널
	DICE_PANEL = 5,
	DICE1 = 6,
	DICE2 = 7,

	TEXT_TURN_NUMBER = 8,
	TEXT_PLAYER_SCORE = 9,

	BUTTON_DICE = 10,

	ICON_PLAYER1 = 11,
	ICON_PLAYER2 = 12,
	ICON_PLAYER3 = 13,
	ICON_PLAYER4 = 14,

};

void DrawAfterRollDice(sf::RenderWindow& window, DrawableObject* obj[], LoadAndInit load) {

	window.clear();
	// 0
	window.draw(obj[GAME_BOARD]->getSprite());

	// 1 ~ 4
	for (int i = PLAYER1_PIECE; i <= PLAYER1_PIECE + RULE_playerPlayingNumber; i++) {
		window.draw(obj[i]->getSprite());
	}

	// 5 ~ 10
	window.draw(obj[DICE_PANEL]->getSprite());
	window.draw(obj[DICE1]->getSprite());
	window.draw(obj[DICE2]->getSprite());
	window.draw(obj[TEXT_TURN_NUMBER]->getSprite());
	window.draw(obj[TEXT_PLAYER_SCORE]->getSprite());
	window.draw(obj[BUTTON_DICE]->getSprite());

	// 11 ~ 14
	for (int i = ICON_PLAYER1; i <= ICON_PLAYER1 + RULE_playerPlayingNumber; i++) {
		window.draw(obj[i]->getSprite());
	}

	// loadAndInit
	load.drawText(window);
	window.display();

}