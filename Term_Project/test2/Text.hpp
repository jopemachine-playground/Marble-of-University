#ifndef TEXT_HPP
#define TEXT_HPP

#include "SFML/Graphics.hpp"
#include "Player.hpp"
#include "Game.hpp"

enum TextBranch {

// what�� ���� ���̳Ŀ� ���� �ٸ� �뵵�� ����.
// what�� 1�̸� ���� �� �� ����Ҷ�, 2�̸� �÷��̾� ���� ����Ҷ�..

	TURN_NUMBER = 1,
	PLAYER_SCORE = 2
};

class Text {

private:
	Text();
	sf::Font font;
	
	//loadAndInit
	
	static Text* instance;

public:

	void drawTextArgu(int num, int what,int turn);

	static Text* getInstance() {
		if (instance == 0) {
			instance = new Text();
		}
		return instance;
	}
	
	sf::Text getText(int num);
	sf::Font getMenuFont() { return font; }
	void drawText(sf::RenderWindow& window);

	sf::Text absenceText;
	sf::Text goldenKeyText;
	sf::Text message;
	sf::Text competitionText;
	sf::Text text_player;
	sf::Text player_state;

	sf::Text text_player1;
	sf::Text text_player2;
	sf::Text text_player3;
	sf::Text text_player4;

	sf::Text text_turn;
};


#endif
