#include "pch.h"

#include "SFML/Graphics.hpp"

#include "Dice.hpp"
#include "Piece.hpp"
#include "MapPoint.hpp"

#include <iostream>

/*
�� ĭ�� ���� ������.
PositionIndex�� ���� �������� Ŀ���� ó������ ���ƿ�
*/

void Piece::MovePiece() {

	if (positionIndex + 1 < FOOTHOLD_NUMBER) ++positionIndex;

	else positionIndex %= positionIndex;

	//std::cout << "in function x value : " << MapPointArray[positionIndex].x << std::endl;
	//std::cout << "in function y value : " << MapPointArray[positionIndex].y << std::endl;

	sprite.setPosition(MapPoint[positionIndex]);

}

Piece::Piece(sf::RenderWindow& window, std::string number) {

	positionIndex = 0;
	texture.loadFromFile("images/Piece" + number + ".png");
	texture.setSmooth(true);
	sprite.setTexture(texture);
	sprite.setPosition(MapPoint[0]);


}
