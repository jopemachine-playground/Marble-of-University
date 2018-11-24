#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include "DrawableObject.hpp"
#include "Game.hpp"

class GameBoard: public DrawableObject {

	private:
		sf::Texture texture = DrawableObject::getTexture();
		sf::Sprite sprite = DrawableObject::getSprite();

	public:
		GameBoard(sf::RenderWindow& window);
		sf::Sprite getSprite() { return sprite; }


};

#endif