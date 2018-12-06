#include "pch.h"

#include "Text.hpp"
#include "BoardPlate.hpp"

Text* Text::instance = nullptr;

Text::Text() {

	font.loadFromFile(FILE_menuFont);

	text_turn.setFont(font);
	text_turn.setPosition(TEXT_showTurn_X, TEXT_showTurn_Y);
	text_turn.setFillColor(sf::Color::Black);
	text_turn.setCharacterSize(TEXT_showTurn_CharSize);

	text_player1.setFont(font);
	text_player1.setPosition(TEXT_showPlayerInformation_X, TEXT_showPlayerInformation_Y);
	text_player1.setFillColor(sf::Color::Black);
	text_player1.setCharacterSize(TEXT_showPlayerInformation_Size);

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

	//loadAndInit

	text_player.setFont(font);
	text_player.setPosition(TEXT_showPlayerInformation_X, TEXT_showPlayerInformation_Y);
	text_player.setFillColor(sf::Color::Black);
	text_player.setCharacterSize(TEXT_showPlayerInformation_Size);

	player_state.setFont(font);
	player_state.setPosition(TEXT_showPlayerInformation_X + 180, TEXT_showPlayerInformation_Y);
	player_state.setFillColor(sf::Color::Black);
	player_state.setCharacterSize(TEXT_showPlayerInformation_Size);

	competitionText.setFont(font);
	competitionText.setPosition(570, 100);
	competitionText.setFillColor(sf::Color::Black);
	competitionText.setCharacterSize(TEXT_showPlayerInformation_Size);
	competitionText.setString(std::to_wstring(competitonScore) + L" 학점");

	message.setFont(font);
	message.setPosition(250, 300);
	message.setFillColor(sf::Color::Black);
	message.setCharacterSize(TEXT_showPlayerInformation_Size);

	goldenKeyText.setFont(font);
	goldenKeyText.setPosition(150, 400);
	goldenKeyText.setFillColor(sf::Color::Black);
	goldenKeyText.setCharacterSize(TEXT_showPlayerInformation_Size - 10);

}

void Text::drawText(sf::RenderWindow& window) {

	window.draw(text_turn);

	window.draw(text_player1);
	window.draw(text_player2);
	window.draw(text_player3);
	window.draw(text_player4);

	window.draw(text_player);
	window.draw(competitionText);
	window.draw(message);
	window.draw(goldenKeyText);
	window.draw(player_state);
	window.draw(absenceText);

}

void Text::drawTextArgu(int num, int what,int turn) {
	// 이 함수를 what의 값이 몇이냐에 따라 다른 용도로 쓴다.
	// what이 1이면 현재 턴 수 출력할때, 2이면 플레이어 점수 출력할때..
	if (what == TextBranch::TRUN_NUMBER) {
		// "현재 num 턴 입니다."
		// 한글이 깨지는 현상이 있어, 영어로 대체함.
		text_turn.setString(L"현재 Player" + std::to_wstring(num) + L"의 턴입니다\n\n"+
			L"전체 "+std::to_wstring(turn)+L"턴 입니다");

	}
	else if (what == 10) {
		// std::to_string(1) 에서 1은 나중에 코드 짤 때를 위해 분리함.
		text_turn.setString(L"Player " + std::to_wstring(num) + L" 가 우승하였습니다\n 잠시후 창이 닫힙니다");
	}
}

sf::Text Text::getText(int what) {

	if (what == TextBranch::TRUN_NUMBER) {
		// 이때는 text_turn을 return 하자.
		return text_turn;
	}
	else if (what == TextBranch::PLAYER_SCORE) {
		return text_player;
	}


	else {

	}
	
}

