#include "DrawableObject.hpp"
#include "Game.hpp"
#include "SFML/Graphics.hpp"
#include <string>
#include <comdef.h>
#include <CRTDBG.H>
#include <atlconv.h>

#ifndef BOARD_HPP
#define BOARD_HPP

class Board : public DrawableObject
{
public:
	Board() {}

	Board(std::string type0, int xPosition, int yPosition, std::string name, int score, int _positionNum);

	sf::Sprite getSprite() { return sprite; }

	sf::Texture getTexture() { return texture; }

	void setText(int x, int y, std::string name);

	void setPosition(int xPosition, int yPosition);

	std::string getName() { return name; }

	int getScore() { return score; }

	std::string getType() { return type; }

	void setName(std::string _name) { name = _name; }

	void setScore(int _score) { score = _score; }


	sf::Text getText() {return nameText;}
	sf::Text getScoreText() {return ScoreText;}
	sf::Font getFont() {return font;}
	bool isInBoard(sf::Vector2i mousePosition);

	int getPositionX() {return positionX;}
	int getPositionY() {return positionY;}

private:
	int positionNum;

	int positionX = DrawableObject::getPositionX();
	int positionY = DrawableObject::getPositionY();

	sf::Texture texture = DrawableObject::getTexture();
	sf::Sprite sprite = DrawableObject::getSprite();
	sf::Text nameText;
	sf::Text ScoreText;
	sf::Font font;

	int score;
	std::string name;
	std::string type;

};
#endif


