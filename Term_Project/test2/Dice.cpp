#include "pch.h"

#include "SFML/Graphics.hpp"

#include "Dice.hpp"

#include <random>
#include <iostream>


// Dice ��ü�� ������ �����ϰ� �������ִ� ������ ��.
Dice::Dice() {

	std::random_device rd;   // non-deterministic generator  
	std::mt19937 gen(rd());  // to seed mersenne twister.  
	
	std::uniform_int_distribution<> dist(MIN_DICE_NUMBER, MAX_DICE_NUMBER);
	// distribute results between 1 and 6 inclusive.  
	RandomDiceNumber1 = dist(gen);
	RandomDiceNumber2 = dist(gen);
}

Dice::~Dice() {
	// �ʿ��� ��� ����
}

// 
int Dice::getMoveNumber()
{
	// if (RandomDiceNumber1 == RandomDiceNumber2)
	// �ֻ��� ���� ������ �� �� �� ���� ����, �Ŀ� ��Ȳ�� ���� �ʿ��ϴٸ� ����
		
	return RandomDiceNumber1 + RandomDiceNumber2;
}


