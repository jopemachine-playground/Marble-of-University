#include "SFML/Graphics.hpp"
#include "DrawableObject.hpp"
#include "Game.hpp"

/* 
	�г��� ��ư�� �ٸ���, Ŭ���� �� ����
	�÷��̾�� ���ӿ� ���� ������ ��Ÿ�� �ݴϴ�.
*/

class Panel : public DrawableObject {
	
	private:
		
		int positionX = DrawableObject::getPositionX();
		int positionY = DrawableObject::getPositionY();
		sf::Texture texture = DrawableObject::getTexture();
		sf::Sprite sprite = DrawableObject::getSprite();

	public:

		sf::Sprite getSprite() { return sprite; }
		sf::Texture getTexture() { return texture; }

};