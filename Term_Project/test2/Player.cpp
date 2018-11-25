#include "pch.h"

#include "Dice.hpp"
#include "Piece.hpp"
#include "Player.hpp"

Player::Player(sf::RenderWindow& window, std::string number)
{
	OwnPiece = new Piece(window, number);
	score = 0;
	sleep = 0;
	setSpecialTurn(0);
}

int Player::getScore() {
	return score;
}

void Player::setScore(int _score) {
	if (getSpecialTurn() == 0) {
		score = _score;
	}
	else if (getSpecialTurn()< 0) {
		setSpecialTurn(getSpecialTurn() + 1);
		score = _score - 1;
	}
	else {
		setSpecialTurn(getSpecialTurn() - 1);
		score = _score + 1;
	}

}
int Player::getSpecialTurn() {
	return specialTurn;
}

void Player::setSpecialTurn(int aTurn) {
	specialTurn = aTurn;
}