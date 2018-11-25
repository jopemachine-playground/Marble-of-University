#ifndef ICON_HPP
#define ICON_HPP

#include "DrawableObject.hpp"
#include "MapPoint.hpp"
#include "Game.hpp"

class Icon : public DrawableObject {

private:


	sf::Texture texture = DrawableObject::getTexture();
	sf::Sprite sprite = DrawableObject::getSprite();
	int positionIndex;

public:

	sf::Sprite getSprite() { return sprite; }
	int getPositionIndex() { return positionIndex; }

	
	Icon(sf::RenderWindow& WindowRef, std::string number,int xPosition,int yPosition) {
		texture.loadFromFile("images/Piece" + number + ".png");
		texture.setSmooth(true);
		sprite.setTexture(texture);
		sprite.setPosition(xPosition, yPosition);
	}



};

#endif