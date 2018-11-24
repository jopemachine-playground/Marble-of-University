#include "pch.h"
#include "DicePanel.hpp"

DicePanel::DicePanel(sf::RenderWindow& window) {
	
	texture.loadFromFile(FILE_DicePanel);
	sprite.setTexture(texture);
	sprite.setPosition(Dice_Panel_POSITION_X, Dice_Panel_POSITION_Y);
	
	diceNumberTexture[0].loadFromFile(File_DiceNumber1);
	diceNumberTexture[1].loadFromFile(File_DiceNumber2);
	diceNumberTexture[2].loadFromFile(File_DiceNumber3);
	diceNumberTexture[3].loadFromFile(File_DiceNumber4);
	diceNumberTexture[4].loadFromFile(File_DiceNumber5);
	diceNumberTexture[5].loadFromFile(File_DiceNumber6);

	for (int i = 0; i < 6; i++) {
		diceNumberSprite[i].setTexture(diceNumberTexture[i]);
	}


}

sf::Sprite DicePanel::getDice1Sprite(Dice dice) {

	switch (dice.getDiceNumber1()) {

	case 1:
		diceNumberSprite[0].setPosition(Dice1_POSITION_X, Dice1_POSITION_Y);
		return diceNumberSprite[0];
		break;
	case 2:
		diceNumberSprite[1].setPosition(Dice1_POSITION_X, Dice1_POSITION_Y);
		return diceNumberSprite[1];
		break;
	case 3:
		diceNumberSprite[2].setPosition(Dice1_POSITION_X, Dice1_POSITION_Y);
		return diceNumberSprite[2];
		break;
	case 4:
		diceNumberSprite[3].setPosition(Dice1_POSITION_X, Dice1_POSITION_Y);
		return diceNumberSprite[3];
		break;
	case 5:
		diceNumberSprite[4].setPosition(Dice1_POSITION_X, Dice1_POSITION_Y);
		return diceNumberSprite[4];
		break;
	case 6:
		diceNumberSprite[5].setPosition(Dice1_POSITION_X, Dice1_POSITION_Y);
		return diceNumberSprite[5];
		break;

	}
}

sf::Sprite DicePanel::getDice2Sprite(Dice dice) {

	switch (dice.getDiceNumber2()) {

	case 1:
		diceNumberSprite[0].setPosition(Dice2_POSITION_X, Dice2_POSITION_Y);
		return diceNumberSprite[0];
		break;
	case 2:
		diceNumberSprite[1].setPosition(Dice2_POSITION_X, Dice2_POSITION_Y);
		return diceNumberSprite[1];
		break;
	case 3:
		diceNumberSprite[2].setPosition(Dice2_POSITION_X, Dice2_POSITION_Y);
		return diceNumberSprite[2];
		break;
	case 4:
		diceNumberSprite[3].setPosition(Dice2_POSITION_X, Dice2_POSITION_Y);
		return diceNumberSprite[3];
		break;
	case 5:
		diceNumberSprite[4].setPosition(Dice2_POSITION_X, Dice2_POSITION_Y);
		return diceNumberSprite[4];
		break;
	case 6:
		diceNumberSprite[5].setPosition(Dice2_POSITION_X, Dice2_POSITION_Y);
		return diceNumberSprite[5];
		break;

	}
}