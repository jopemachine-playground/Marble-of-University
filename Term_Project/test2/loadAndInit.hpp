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
	int isWin(Player* player[]);
	sf::Text getText() {
		return text_player;
	}
	sf::Text getCompetitionText() {
		return competitionText;
	}
	sf::Text getMessage() {
		return message;
	}
	sf::Text getGoldKeyMessage() {
		return goldenKeyText;
	}
	sf::Text getPlayerState() {
		return  player_state;
	}
	sf::Text getAbsenceText() {
		return  absenceText;
	}
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



