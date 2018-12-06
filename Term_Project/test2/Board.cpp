#include "pch.h"
#include "Board.hpp"

void Board::setText(int x, int y, std::string name) {
	USES_CONVERSION;

	std::wstring ws(A2W(name.c_str()));


	font.loadFromFile(FILE_menuFont);
	sf::Text txt(ws, font);
	txt.setPosition(x, y);
	txt.setFillColor(sf::Color::Black);
	txt.setCharacterSize(18);
	//nameText.setString(name);
	nameText = txt;


	sf::Text scoreTxt(std::to_wstring(score) + L" ÇÐÁ¡", font);
	scoreTxt.setPosition(x, y + 15);
	scoreTxt.setFillColor(sf::Color::Black);
	scoreTxt.setCharacterSize(18);
	ScoreText = scoreTxt;
}

void Board::setPosition(int xPosition, int yPosition) {
	//texture.loadFromFile("images/" + type + ".png");
		//texture.setSmooth(true);
	sprite.setTexture(texture);
	positionX = xPosition;
	positionY = yPosition;
	sprite.setPosition(xPosition, yPosition);
}

bool Board::isInBoard(sf::Vector2i mousePosition) {

	if (mousePosition.x > positionX && mousePosition.x < positionX + 76 && mousePosition.y > positionY && mousePosition.y < positionY + 108)
		return true;
	else
		return false;

}


Board::Board(std::string type0, int xPosition, int yPosition, std::string name, int score, int _positionNum) {

	positionNum = _positionNum;
	texture.loadFromFile("images/" + type0 + ".png");
	texture.setSmooth(true);
	sprite.setTexture(texture);
	setPosition(xPosition, yPosition);
	setName(name);
	setScore(score);
	//setText(xPosition,yPosition,name);

	type = type0;
}