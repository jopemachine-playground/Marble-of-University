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
	Board() {

	}

	Board(sf::RenderWindow& window, std::string type0, int xPosition, int yPosition, std::string name, int score) {

		texture.loadFromFile("images/" + type0 + ".png");
		texture.setSmooth(true);
		sprite.setTexture(texture);
		setPosition(xPosition, yPosition);
		setName(name);
		setScore(score);
		//setText(xPosition,yPosition,name);

		type = type0;
	}
	//Board(sf::RenderWindow& window);

	//virtual bool isInButton(sf::Vector2i mousePosition) = 0;
	sf::Sprite getSprite() { return sprite; }
	sf::Texture getTexture() { return texture; }

	void setText(int x, int y, std::string name) {
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
	void setPosition(int xPosition, int yPosition) {
		//texture.loadFromFile("images/" + type + ".png");
		//texture.setSmooth(true);
		sprite.setTexture(texture);
		positionX = xPosition;
		positionY = yPosition;
		sprite.setPosition(xPosition, yPosition);
	}

	std::string getName() { return name; }

	int getScore() { return score; }

	std::string getType() { return type; }

	void setName(std::string _name) { name = _name; }

	void setScore(int _score) { score = _score; }


	sf::Text getText() {
		return nameText;
	}
	sf::Text getScoreText() {
		return ScoreText;
	}
	sf::Font getFont() {
		return font;
	}
	bool isInBoard(sf::Vector2i mousePosition) {

		if (mousePosition.x > positionX && mousePosition.x < positionX + 76 && mousePosition.y > positionY && mousePosition.y < positionY + 108)
			return true;
		else
			return false;

	}
	int getPositionX() {
		return positionX;
	}
	int getPositionY() {
		return positionY;
	}
private:
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


