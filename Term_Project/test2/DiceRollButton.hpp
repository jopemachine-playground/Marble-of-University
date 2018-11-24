#ifndef DICEBUTTON_H
#define DICEBUTTON_H

#include "Button.hpp"
#include "Game.hpp"

class DiceRollButton : public Button {
	
	private:

		int positionX = Dice_Button_POSITION_X;
		int positionY = Dice_Button_POSITION_Y;

		sf::Texture texture = Button::getTexture();
		sf::Sprite sprite = Button::getSprite();

	public:
		DiceRollButton(sf::RenderWindow& window);
		bool isInButton(sf::Vector2i mousePosition) override;
		sf::Sprite getSprite() { return sprite; }
		sf::Texture getTexture() { return texture; }

};



#endif