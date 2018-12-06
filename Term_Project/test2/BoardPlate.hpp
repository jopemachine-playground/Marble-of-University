#ifndef NEWBOARD_HPP
#define NEWBOARD_HPP

#include "Board.hpp"
#include "Player.hpp"

static int competitonScore = 0;

/*
	BoardPlate는 Board들의 Aggregate로, Singleton으로 구현했습니다.
*/

class BoardPlate {

private:

	Board board[40];

	BoardPlate();
	
	static BoardPlate* instance;

public:

	static BoardPlate* getInstance() {
		if (instance == 0) {
			instance = new BoardPlate();
		}
		return instance;
	}

	void drawAllBoard(sf::RenderWindow& window);
	void whenPassStart(Player& player);
	bool whenPieceOnBoard(Player& player);
	void playerScore(Player* player[]);

	Board getBoard(int index) {
		return board[index];
	}

};







#endif