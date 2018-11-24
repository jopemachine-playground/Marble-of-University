#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "SFML/Graphics.hpp"
#include "Piece.hpp"
#include "Turn.hpp"

class Player {

private:
	int score;
	int sleep;
	Turn specialTurn;
public:
	Player() {

	}
	Player(sf::RenderWindow& window, std::string number);
	Piece *OwnPiece;
	void setScore(int _score);
	int getScore();
	int getSleep() {
		return sleep;
	}
	void setSleep(int _sleep) {
		sleep = _sleep;
	}
	void setSpecialTurn(Turn aTurn);
	Turn getSpecialTurn();
};

#endif

