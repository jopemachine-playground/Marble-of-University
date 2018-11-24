#include "pch.h"


#include "DiceRollButton.hpp"

DiceRollButton::DiceRollButton(sf::RenderWindow& window) {

	// 주사위 굴리기 버튼
	texture.loadFromFile(FILE_DiceRollButton);
	sprite.setTexture(texture);
	sprite.setPosition(Dice_Button_POSITION_X, Dice_Button_POSITION_Y);

}

bool DiceRollButton::isInButton(sf::Vector2i mousePosition) {

	if (mousePosition.x > Dice_Button_POSITION_X && mousePosition.x < Dice_Button_POSITION_X + Dice_Button_LENGTH_X && mousePosition.y > Dice_Button_POSITION_Y && mousePosition.y < Dice_Button_POSITION_Y + Dice_Button_LENGTH_Y) return true;
	else return false;

}
