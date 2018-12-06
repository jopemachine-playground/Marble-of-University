#include "pch.h"

#include "Piece.hpp"
#include "BoardPlate.hpp"

/*
한 칸씩 말을 움직임.
PositionIndex가 발판 갯수보다 커지면 처음으로 돌아옴
*/


void Piece::MovePiece() {
	
	int temp = 0;

	BoardPlate* bp = BoardPlate::getInstance();

	if (positionIndex + 1 < FOOTHOLD_NUMBER) ++positionIndex;

	else positionIndex %= positionIndex;

	sprite.setPosition(bp->getBoard(positionIndex).getPositionX(), (bp->getBoard(positionIndex).getPositionY()) - 20);

}

Piece::Piece(sf::RenderWindow& window, std::string number) {

	positionIndex = 0;
	texture.loadFromFile("images/Piece" + number + ".png");
	texture.setSmooth(true);
	sprite.setTexture(texture);
	sprite.setPosition(792,792);


}
