#ifndef TURN_HPP
#define TURN_HPP

#include <iostream>
#include "SFML/Graphics.hpp"

class Turn {

public:

	Turn() { turn_num = 1; };
	void IncTurn() { ++turn_num; }
	int getTurn() { return turn_num; }
	void setTurn(int num) { turn_num = num; }
	int turn_num;
};



#endif 