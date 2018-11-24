#include "pch.h"

#include "Dice.hpp"
#include "Piece.hpp"
#include "Player.hpp"

Player::Player(sf::RenderWindow& window, std::string number)
{
	OwnPiece = new Piece(window, number);
	score = 0;
	sleep = 0;
}

int Player::getScore() {
	return score;
}

void Player::setScore(int _score) {
	if (getSpecialTurn().getTurn() == 0) {
		score = _score;
	}
	else if (getSpecialTurn().getTurn() < 0) {
		getSpecialTurn().IncTurn();
		score = _score - 1;
	}
	else {
		getSpecialTurn().setTurn(getSpecialTurn().getTurn() - 1);
		score = _score + 1;
	}

}
Turn Player::getSpecialTurn() {
	return specialTurn;
}

void Player::setSpecialTurn(Turn aTurn) {
	specialTurn = aTurn;
}