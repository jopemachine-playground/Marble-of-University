#ifndef TURN_HPP
#define TURN_HPP

#include <iostream>
#include "SFML/Graphics.hpp"

class Turn {

public:
	int turn_num;
	Turn() { turn_num = 1; };
	void IncTurn() { ++turn_num; }
	int getTurn() { return turn_num; }
};



#endif 