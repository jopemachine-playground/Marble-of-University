#include "pch.h"

#include "Text.hpp"

Text::Text() {

	font.loadFromFile(FILE_menuFont);

	//sf::Text text_turn;
	text_turn.setFont(font);
	text_turn.setPosition(TEXT_showTurn_X, TEXT_showTurn_Y);
	text_turn.setFillColor(sf::Color::Black);
	text_turn.setCharacterSize(TEXT_showTurn_CharSize);

	text_player.setFont(font);
	text_player.setPosition(TEXT_showPlayerInformation_X, TEXT_showPlayerInformation_Y);
	text_player.setFillColor(sf::Color::Black);
	text_player.setCharacterSize(TEXT_showPlayerInformation_Size);

	text_player2.setFont(font);
	text_player2.setPosition(TEXT_showPlayerInformation_X, TEXT_showPlayerInformation_Y+100);
	text_player2.setFillColor(sf::Color::Black);
	text_player2.setCharacterSize(TEXT_showPlayerInformation_Size);

	text_player3.setFont(font);
	text_player3.setPosition(TEXT_showPlayerInformation_X, TEXT_showPlayerInformation_Y+200);
	text_player3.setFillColor(sf::Color::Black);
	text_player3.setCharacterSize(TEXT_showPlayerInformation_Size);

	text_player4.setFont(font);
	text_player4.setPosition(TEXT_showPlayerInformation_X, TEXT_showPlayerInformation_Y+300);
	text_player4.setFillColor(sf::Color::Black);
	text_player4.setCharacterSize(TEXT_showPlayerInformation_Size);
}

void Text::drawTextArgu(int num, int what,int turn) {
	// �� �Լ��� what�� ���� ���̳Ŀ� ���� �ٸ� �뵵�� ����.
	// what�� 1�̸� ���� �� �� ����Ҷ�, 2�̸� �÷��̾� ���� ����Ҷ�..
	if (what == TextBranch::TRUN_NUMBER) {
		// "���� num �� �Դϴ�."
		// �ѱ��� ������ ������ �־�, ����� ��ü��.
		text_turn.setString(L"���� Player" + std::to_wstring(num) + L"�� ���Դϴ�\n\n"+
			L"��ü "+std::to_wstring(turn)+L"�� �Դϴ�");

	}
	else if (what == 10) {
		// std::to_string(1) ���� 1�� ���߿� �ڵ� © ���� ���� �и���.
		text_turn.setString(L"Player " + std::to_wstring(num) + L" �� ����Ͽ����ϴ�\n ����� â�� �����ϴ�");
	}
}

sf::Text Text::getText(int what) {

	if (what == TextBranch::TRUN_NUMBER) {
		// �̶��� text_turn�� return ����.
		return text_turn;
	}
	else if (what == TextBranch::PLAYER_SCORE) {
		return text_player;
	}


	else {

	}
	
}
