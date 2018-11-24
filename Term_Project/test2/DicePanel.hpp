#include "Game.hpp"
#include "Panel.hpp"
#include "Dice.hpp"

class DicePanel : public Panel {

	private:

		// 패널 위치

		int positionX = Dice_Panel_POSITION_X;
		int positionY = Dice_Panel_POSITION_Y;

		// 두 주사위 이미지 파일이 위치할 좌표

		int dice1PositionX = Dice1_POSITION_X;
		int dice1PositionY = Dice1_POSITION_Y;
		int dice2PositionX = Dice2_POSITION_X;
		int dice2PositionY = Dice2_POSITION_Y;

		// 주사위 이미지 파일을 나타낼 패널 이미지 파일

		sf::Texture texture = Panel::getTexture();
		sf::Sprite sprite = Panel::getSprite();

		// 주사위들의 면을 나타내는 이미지 파일들
			
		sf::Texture diceNumberTexture[6];
		sf::Sprite diceNumberSprite[6];

	public:

		DicePanel(sf::RenderWindow& window);
		sf::Sprite getSprite() { return sprite; }
		sf::Texture getTexture() { return texture; }
		sf::Sprite getDice1Sprite(Dice dice);
		sf::Sprite getDice2Sprite(Dice dice);

};