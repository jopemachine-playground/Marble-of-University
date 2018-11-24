#include "Game.hpp"
#include "Panel.hpp"
#include "Dice.hpp"

class DicePanel : public Panel {

	private:

		// �г� ��ġ

		int positionX = Dice_Panel_POSITION_X;
		int positionY = Dice_Panel_POSITION_Y;

		// �� �ֻ��� �̹��� ������ ��ġ�� ��ǥ

		int dice1PositionX = Dice1_POSITION_X;
		int dice1PositionY = Dice1_POSITION_Y;
		int dice2PositionX = Dice2_POSITION_X;
		int dice2PositionY = Dice2_POSITION_Y;

		// �ֻ��� �̹��� ������ ��Ÿ�� �г� �̹��� ����

		sf::Texture texture = Panel::getTexture();
		sf::Sprite sprite = Panel::getSprite();

		// �ֻ������� ���� ��Ÿ���� �̹��� ���ϵ�
			
		sf::Texture diceNumberTexture[6];
		sf::Sprite diceNumberSprite[6];

	public:

		DicePanel(sf::RenderWindow& window);
		sf::Sprite getSprite() { return sprite; }
		sf::Texture getTexture() { return texture; }
		sf::Sprite getDice1Sprite(Dice dice);
		sf::Sprite getDice2Sprite(Dice dice);

};