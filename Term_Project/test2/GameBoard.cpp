#include "pch.h"

#include "SFML/Graphics.hpp"

#include "GameBoard.hpp"

GameBoard::GameBoard(sf::RenderWindow& window) {
	
	texture.loadFromFile(FILE_gameBoard);
	sprite.setTexture(texture);

}
