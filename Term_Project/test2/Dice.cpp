#include "pch.h"

#include "SFML/Graphics.hpp"

#include "Dice.hpp"

#include <random>
#include <iostream>


// Dice 객체는 난수를 생성하고 관리해주는 역할을 함.
Dice::Dice() {

	std::random_device rd;   // non-deterministic generator  
	std::mt19937 gen(rd());  // to seed mersenne twister.  
	
	std::uniform_int_distribution<> dist(MIN_DICE_NUMBER, MAX_DICE_NUMBER);
	// distribute results between 1 and 6 inclusive.  
	RandomDiceNumber1 = dist(gen);
	RandomDiceNumber2 = dist(gen);
}

Dice::~Dice() {
	// 필요한 경우 정의
}

// 
int Dice::getMoveNumber()
{
	// if (RandomDiceNumber1 == RandomDiceNumber2)
	// 주사위 눈이 같으면 한 번 더 턴을 진행, 후에 상황을 봐서 필요하다면 구현
		
	return RandomDiceNumber1 + RandomDiceNumber2;
}


