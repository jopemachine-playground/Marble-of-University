#ifndef DICE_HPP
#define DICE_HPP

#include "game.hpp"

class Dice {

	private:

		int RandomDiceNumber1;
		int RandomDiceNumber2;
	
	public:
		Dice();
		~Dice();

		// main에서 두 주사위의 눈의 값을 각각 넘겨받을 때 사용하는 메서드
		int getDiceNumber1() { return RandomDiceNumber1; }
		int getDiceNumber2() { return RandomDiceNumber2; }

		int getMoveNumber();

};


#endif