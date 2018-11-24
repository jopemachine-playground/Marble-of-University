#include "SFML/Graphics.hpp"
#include "DrawableObject.hpp"
#include "Game.hpp"

/* 
	패널은 버튼과 다르게, 클릭할 수 없고
	플레이어에게 게임에 대한 정보를 나타내 줍니다.
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