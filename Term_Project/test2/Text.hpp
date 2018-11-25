#ifndef TEXT_HPP
#define TEXT_HPP

#include "SFML/Graphics.hpp"
#include "Player.hpp"
#include "Game.hpp"

enum TextBranch {

// what�� ���� ���̳Ŀ� ���� �ٸ� �뵵�� ����.
// what�� 1�̸� ���� �� �� ����Ҷ�, 2�̸� �÷��̾� ���� ����Ҷ�..

	TRUN_NUMBER = 1,
	PLAYER_SCORE = 2
};

class Text {

private:
	sf::Font font;
	sf::Text text_turn;
	


public:
	Text();
	sf::Font getMenuFont() { return font; }
	void drawTextArgu(int num, int what,int turn);
	
	sf::Text getText(int num);
	sf::Text text_player;
	sf::Text text_player2;
	sf::Text text_player3;
	sf::Text text_player4;
};


#endif
