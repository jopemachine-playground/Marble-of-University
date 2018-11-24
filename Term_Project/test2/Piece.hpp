#ifndef PIECE_HPP
#define PIECE_HPP

#include "DrawableObject.hpp"
#include "MapPoint.hpp"
#include "Game.hpp"

class Piece : public DrawableObject {

private:

	// �� Piece ���� �ٸ� �� ����
	sf::Texture texture = DrawableObject::getTexture();
	sf::Sprite sprite = DrawableObject::getSprite();
	int positionIndex;

public:

	sf::Sprite getSprite() { return sprite; }
	int getPositionIndex() { return positionIndex; }

	void MovePiece();
	Piece(sf::RenderWindow& WindowRef, std::string number);



};

#endif