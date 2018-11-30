#include "pch.h"

#include "MapPoint.hpp"
#include "LoadAndInit.hpp"

#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <Windows.h>
#include <comdef.h>
#include <CRTDBG.H>
#include <atlconv.h>


LoadAndInit::LoadAndInit(sf::RenderWindow& window)
{
	boardDataLoad(window);
	competitonScore = 0;

	font.loadFromFile(FILE_menuFont);

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

/* 아래 메서드는 사용되지 않음 */
void LoadAndInit::boardDraw(sf::RenderWindow& window) {
	for (int i = 0; i < 10; i++)
		window.draw(allBoard[i].getSprite());
}

/*

	WinMain에서 무한루프를 돌며 DataLoad를 반복합니다.

	=> 데이터를 한 번만 로드해 계속 끌어다 쓸 방법은??
	(전역변수 말고 다른 방법으로)

*/
void LoadAndInit::boardDataLoad(sf::RenderWindow& window) {

	std::ifstream in(FILE_BOARD_DATA);

	if (window.isOpen()) {

		if (in.is_open()) {

			for (int i = 0; i < FOOTHOLD_NUMBER; i++) {

				int x = MapPoint[i].x;
				int y = MapPoint[i].y;

				/*
					data.txt의 내용을 읽어옵니다.
				*/
				std::string line, row[5];
				char* tok_temp;
				getline(in, line);

				char* row_buffer = new char[100];

				/*
					Data중 가장 긴 라인 : 1st,시스템 프로그래밍,3
					= NULL까지 24 바이트를 차지함
				*/

				strcpy_s(row_buffer, 24, line.c_str());

				/*
					delimiter = ","
				*/

				char* tok = strtok_s(row_buffer, ",", &tok_temp);

				int j = 0;
				while (tok != NULL) {
					row[j++] = tok;
					tok = strtok_s(NULL, ",", &tok_temp);
				}
				std::string type = row[0];

				int score = atoi(row[2].c_str());

				/*
					세로 발판의 경우
					가로 발판의 경우와 다르게,
					캐릭터를 좀 더 띄워야 합니다.

					그 수치가 VERTICAL_FOOTHOLD_ADD_VALUE이고 32입니다.
				*/

				if ((i >= 11 && i < 20) || i >= 31) y += VERTICAL_FOOTHOLD_ADD_VALUE;


				allBoard[i] = (Board)*(new Board(window, type, x, y, row[1], score));

				window.draw(allBoard[i].getSprite());

				/*
					로드한 데이터를 window에 표시합니다
				*/

				if (allBoard[i].getType() == "1st") {
					allBoard[i].setText(x + 3, y + 28, allBoard[i].getName());
					window.draw(allBoard[i].getText());
					window.draw(allBoard[i].getScoreText());
				}
				if (allBoard[i].getType() == "2nd") {
					allBoard[i].setText(x + 10, y + 5, allBoard[i].getName());
					window.draw(allBoard[i].getText());
					window.draw(allBoard[i].getScoreText());
				}
				if (allBoard[i].getType() == "3rd") {
					allBoard[i].setText(x + 3, y + 15, allBoard[i].getName());
					window.draw(allBoard[i].getText());
					window.draw(allBoard[i].getScoreText());
				}
				if (allBoard[i].getType() == "4rd") {
					allBoard[i].setText(x + 30, y + 15, allBoard[i].getName());
					window.draw(allBoard[i].getText());
					window.draw(allBoard[i].getScoreText());
				}
			} // end of for

			in.close();
		}
		else {

		}
	}
}
void LoadAndInit::passStart(Player& player) {
	int index = player.OwnPiece->getPositionIndex();
	if (allBoard[index].getType() == "start") {

		player.setScore(player.getScore() + allBoard[index].getScore());

		message.setString(L" 시작점을 지나 학점을 얻습니다");
	}
}

bool LoadAndInit::BoardWithPlayer(Player& player) {
	goldenKeyText.setString(L"\n");

	int index = player.OwnPiece->getPositionIndex();

	if (allBoard[index].getType() == "1st" ||
		allBoard[index].getType() == "2nd" ||
		allBoard[index].getType() == "3rd" ||
		allBoard[index].getType() == "4rd") {

		player.setScore(player.getScore() + allBoard[index].getScore());

		/*
			ANSI와 UNICODE를 변환하기 위한 매크로
		*/

		USES_CONVERSION;
		std::wstring position(A2W((allBoard[index].getName()).c_str()));
		message.setString(position + L" 과목을 수강하여 " + std::to_wstring(allBoard[index].getScore()) + L"학점을 얻습니다");
	}
	if (allBoard[index].getType() == "Goldenkey" ||
		allBoard[index].getType() == "Goldenkey2" ||
		allBoard[index].getType() == "Goldenkey3" ||
		allBoard[index].getType() == "Goldenkey4") {

		message.setString(L"황금열쇠를 뽑습니다");
		GoldenKey newGold(player);
		newGold.setKey();

		std::string key = newGold.chooseKey(&goldenKeyText, allBoard);

		if (key == "start")
			player.setScore(player.getScore() + 4);

		if (key == "move")
			player.setScore(player.getScore() + allBoard[index + 3].getScore());

		if (key == "Absence")
			player.setSleep(3);

		if (key == "competition") {
			competitonScore += COMPITITION_SCORE;
			competitionText.setString(std::to_wstring(competitonScore) + L" 학점");
		}
		if (key == "time")
			return true;

		if (key == "money") {
			player.setScore(player.getScore() + competitonScore);
			competitonScore = 0;
		}
	}
	if (allBoard[index].getType() == "start") {


	}
	if (allBoard[index].getType() == "absence") {

		player.setSleep(3);
		message.setString(L"무인도에 갇혔습니다");
	}
	if (allBoard[index].getType() == "competition") {

		competitonScore += 2;
		competitionText.setString(std::to_wstring(competitonScore) + L" 학점");
		message.setString(L"공모전에 참가하여 학점을 적립합니다");
	}
	if (allBoard[index].getType() == "timemachine") {

		message.setString(L"원하는 발판을 클릭하면 이동합니다");
		return true;
	}
	if (allBoard[index].getType() == "book") {

		player.setScore(player.getScore() + allBoard[index].getScore());
		message.setString(L"학점은행을 신청하여 학점을 올렸습니다");
	}
	if (allBoard[index].getType() == "exchange") {

		player.setScore(player.getScore() + allBoard[index].getScore());
		message.setString(L"교환학생을 다녀와 학점이 상승합니다");
	}
	if (allBoard[index].getType() == "money") {

		player.setScore(player.getScore() + competitonScore);
		message.setString(L"공모전 상금" + std::to_wstring(competitonScore) + L"학점을 얻습니다");
		competitonScore = 0;
		competitionText.setString(std::to_wstring(competitonScore) + L" 학점");

	}
	if (allBoard[index].getType() == "intern") {

		player.setScore(player.getScore() + allBoard[index].getScore());
		message.setString(L"백마 인턴십을 수강하였습니다");
	}
	return false;
}
void LoadAndInit::playerScore(Player* player[]) {

	USES_CONVERSION;
	int playerindexes[RULE_playerPlayingNumber + 1];
	std::wstring playerPostion[RULE_playerPlayingNumber + 1];
	for (int i = 1; i <= RULE_playerPlayingNumber; i++) {
		playerindexes[i] = player[i]->OwnPiece->getPositionIndex();
		playerPostion[i] = std::wstring(A2W((allBoard[playerindexes[i]].getName()).c_str()));
	}

	text_player.setString("");
	for (int i = 1; i <= RULE_playerPlayingNumber; i++) {
		text_player.setString(text_player.getString() +
			L" Player " + std::to_wstring(i)
			+ L" 학점: " + std::to_wstring(player[i]->getScore())
			+ L"\n현재위치:" + playerPostion[i]
			+ L"\n "
			+ L"\n ");
	}

	int pTurn[RULE_playerPlayingNumber + 1];
	std::wstring pState[RULE_playerPlayingNumber + 1];
	std::wstring pStates[RULE_playerPlayingNumber + 1];
	std::wstring pSleep[RULE_playerPlayingNumber + 1];
	std::wstring pSleep1[RULE_playerPlayingNumber + 1];
	std::wstring pSleep2[RULE_playerPlayingNumber + 1];

	for (int i = 1; i <= RULE_playerPlayingNumber; i++) {
		pTurn[i] = 0;
		pState[i] = L" ";
		if (player[i]->getSpecialTurn() > 0) {
			pTurn[i] = player[i]->getSpecialTurn();
			pState[i] = L" 추가 증가 남은턴: ";
		}
		if (player[i]->getSpecialTurn() < 0) {
			pTurn[i] = -1 * player[i]->getSpecialTurn();
			pState[i] = L" 추가 감소 남은턴: ";
		}
		pStates[i] = L" ";
		if (pTurn[i] != 0)
			pStates[i] = std::to_wstring(pTurn[i]);

		pSleep[i] = L" ";
		pSleep1[i] = L" ";
		pSleep2[i] = L" ";
		if (player[i]->getSleep() > 0) {
			pSleep[i] = L" 무인도 탈출까지 ";
			pSleep1[i] = std::to_wstring(player[i]->getSleep());
			pSleep2[i] = L" 턴 남았습니다";
		}
	}

	player_state.setString("");
	for (int i = 1; i <= RULE_playerPlayingNumber; i++) {
		player_state.setString(player_state.getString() +
			L"" + pState[i] + pStates[i]
			+ L"\n " + pSleep[i] + pSleep1[i] + pSleep2[i]
			+ L"\n "
			+ L"\n ");
	}

}
int LoadAndInit::isWin(Player* player[]) {

	for (int i = 1; i <= RULE_playerPlayingNumber; i++)
	{
		if (player[i]->getScore() >= RULE_WinScore)
			return i;
	}
	return 0;
}


void LoadAndInit::drawText(sf::RenderWindow& window) {

	window.draw(text_player);
	window.draw(competitionText);
	window.draw(message);
	window.draw(goldenKeyText);
	window.draw(player_state);
	window.draw(absenceText);

}