#include "SFML/Graphics.hpp"
#include "DrawableObject.hpp"

class Button: public DrawableObject{
	
	private:

		int positionX = DrawableObject::getPositionX();
		int positionY = DrawableObject::getPositionY();

		sf::Texture texture = DrawableObject::getTexture();
		sf::Sprite sprite = DrawableObject::getSprite();
	
	public:

		virtual bool isInButton(sf::Vector2i mousePosition) = 0;
		sf::Sprite getSprite() { return sprite; }
		sf::Texture getTexture() { return texture; }

};

