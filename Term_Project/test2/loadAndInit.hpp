#include "Board.hpp"
#include "Player.hpp"
#include "GoldenKey.hpp"
#pragma once
class LoadAndInit
{
public:
	
	LoadAndInit(sf::RenderWindow& window);
	void boardDataLoad(sf::RenderWindow& window);
	void boardDraw(sf::RenderWindow& window);
	bool BoardWithPlayer(Player& player);
	void passStart(Player& player);
	void playerScore(Player* player[]);
	void drawText(sf::RenderWindow& window);
	int isWin(Player* player[]);

	Board* getBoard() {
		return allBoard;
	}

private:
	sf::Text absenceText;
	sf::Text goldenKeyText;
	sf::Text message;
	sf::Text competitionText;
	sf::Text text_player;
	sf::Text player_state;
	sf::Font font;
	Board allBoard[50];
	int competitonScore;
};



