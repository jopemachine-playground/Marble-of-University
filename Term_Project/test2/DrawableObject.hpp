#pragma once

#include "pch.h"
#include "SFML/Graphics.hpp"

/* 
	
	DrawableObject 클래스는 
	GameBoard, Button, Piece 클래스의 부모 클래스 역할을 함.
	
*/

class DrawableObject {

	private:

		int positionX;
		int positionY;

		sf::Texture texture;
		sf::Sprite sprite;

	public:

		virtual sf::Sprite getSprite() { return sprite; }
		virtual sf::Texture getTexture() { return texture; }
		int getPositionX() { return positionX; }
		int getPositionY() { return positionY; }

		
};