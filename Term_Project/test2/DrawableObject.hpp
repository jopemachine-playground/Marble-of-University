#pragma once

#include "pch.h"
#include "SFML/Graphics.hpp"

/* 
	
	DrawableObject Ŭ������ 
	GameBoard, Button, Piece Ŭ������ �θ� Ŭ���� ������ ��.
	
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