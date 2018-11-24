#include "Board.hpp"
#include "Player.hpp"
#include "GoldenKey.hpp"
#pragma once
class loadAndInit
{
public:
	
	loadAndInit(sf::RenderWindow& window);
	void load(sf::RenderWindow& window);
	void init(sf::RenderWindow& window);
	bool BoardWithPlayer(Player& player);
	void passStart(Player& player);
	void playerScore(Player* player[]);
	sf::Text getText() {
		return text_player;
	}
	sf::Text getCompetitionText() {
		return competitionText;
	}
	sf::Text getMessage() {
		return message;
	}
	Board* getBoard() {
		return allBoard;
	}

private:
	
	sf::Text message;
	sf::Text competitionText;
	sf::Text text_player;
	sf::Font font;
	Board allBoard[50];
	int competitonScore;
};



