#ifndef TURN_HPP
#define TURN_HPP

#include "SFML/Graphics.hpp"

class Turn {
private:
	int turn_num;
public:

	Turn() { turn_num = 1; };
	void IncTurn() { ++turn_num; }
	int getTurn() { return turn_num; }
	void setTurn(int num) { turn_num = num; }

};



#endif 