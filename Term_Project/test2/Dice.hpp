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

		// main���� �� �ֻ����� ���� ���� ���� �Ѱܹ��� �� ����ϴ� �޼���
		int getDiceNumber1() { return RandomDiceNumber1; }
		int getDiceNumber2() { return RandomDiceNumber2; }

		int getMoveNumber();

};


#endif