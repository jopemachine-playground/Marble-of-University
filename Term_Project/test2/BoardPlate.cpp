#include "pch.h"

#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <Windows.h>
#include <comdef.h>
#include <CRTDBG.H>
#include <atlconv.h>

#include "BoardPlate.hpp"
#include "Text.hpp"
#include "GoldenKey.hpp"

/*
	BoardPlate는 Board들의 Composition으로, Singleton으로 구현했습니다.
*/

BoardPlate* BoardPlate::instance = nullptr;

bool BoardPlate::whenPieceOnBoard(Player& player) {

	Text* tm = Text::getInstance();

	tm->goldenKeyText.setString(L"\n");

	int index = player.OwnPiece->getPositionIndex();

	if (board[index].getType() == "1st" ||
		board[index].getType() == "2nd" ||
		board[index].getType() == "3rd" ||
		board[index].getType() == "4rd") {

		player.setScore(player.getScore() + board[index].getScore());

		/*
			ANSI와 UNICODE를 변환하기 위한 매크로
		*/

		USES_CONVERSION;
		std::wstring position(A2W((board[index].getName()).c_str()));
		tm->message.setString(position + L" 과목을 수강하여 " + std::to_wstring(board[index].getScore()) + L"학점을 얻습니다");
	}
	if (board[index].getType() == "Goldenkey" ||
		board[index].getType() == "Goldenkey2" ||
		board[index].getType() == "Goldenkey3" ||
		board[index].getType() == "Goldenkey4") {

		tm->message.setString(L"황금열쇠를 뽑습니다");
		GoldenKey newGold(player);
		newGold.setKey();

		std::string key = newGold.chooseKey(&(tm->goldenKeyText), board);

		if (key == "start")
			player.setScore(player.getScore() + 4);

		if (key == "move")
			player.setScore(player.getScore() + board[index + 3].getScore());

		if (key == "Absence")
			player.setSleep(3);

		if (key == "competition") {
			competitonScore += COMPITITION_SCORE;
			tm->competitionText.setString(std::to_wstring(competitonScore) + L" 학점");
		}
		if (key == "time")
			return true;

		if (key == "money") {
			player.setScore(player.getScore() + competitonScore);
			competitonScore = 0;
		}
	}
	if (board[index].getType() == "start") {


	}
	if (board[index].getType() == "absence") {

		player.setSleep(3);
		tm->message.setString(L"무인도에 갇혔습니다");
	}
	if (board[index].getType() == "competition") {

		competitonScore += 2;
		tm->competitionText.setString(std::to_wstring(competitonScore) + L" 학점");
		tm->message.setString(L"공모전에 참가하여 학점을 적립합니다");
	}
	if (board[index].getType() == "timemachine") {

		tm->message.setString(L"원하는 발판을 클릭하면 이동합니다");
		return true;
	}
	if (board[index].getType() == "book") {

		player.setScore(player.getScore() + board[index].getScore());
		tm->message.setString(L"학점은행을 신청하여 학점을 올렸습니다");
	}
	if (board[index].getType() == "exchange") {

		player.setScore(player.getScore() + board[index].getScore());
		tm->message.setString(L"교환학생을 다녀와 학점이 상승합니다");
	}
	if (board[index].getType() == "money") {

		player.setScore(player.getScore() + competitonScore);
		tm->message.setString(L"공모전 상금" + std::to_wstring(competitonScore) + L"학점을 얻습니다");
		competitonScore = 0;
		tm->competitionText.setString(std::to_wstring(competitonScore) + L" 학점");

	}
	if (board[index].getType() == "intern") {

		player.setScore(player.getScore() + board[index].getScore());
		tm->message.setString(L"백마 인턴십을 수강하였습니다");
	}
	return false;
}

void BoardPlate::whenPassStart(Player& player) {
	Text* tm = Text::getInstance();

	int index = player.OwnPiece->getPositionIndex();
	if (board[index].getType() == "start") {

		player.setScore(player.getScore() + board[index].getScore());

		tm->message.setString(L" 시작점을 지나 학점을 얻습니다");
	}

}

void BoardPlate::drawAllBoard(sf::RenderWindow& window) {

	for (int i = 0; i < 40; i++)
	{
		window.draw(board[i].getSprite());

		/*
		로드한 데이터를 window에 표시합니다
		*/

		if (board[i].getType() == "1st") {
			board[i].setText(board[i].getPositionX() + 3, board[i].getPositionY() + 28, board[i].getName());
			window.draw(board[i].getText());
			window.draw(board[i].getScoreText());
		}
		if (board[i].getType() == "2nd") {
			board[i].setText(board[i].getPositionX() + 10, board[i].getPositionY() + 5, board[i].getName());
			window.draw(board[i].getText());
			window.draw(board[i].getScoreText());
		}
		if (board[i].getType() == "3rd") {
			board[i].setText(board[i].getPositionX() + 3, board[i].getPositionY() + 15, board[i].getName());
			window.draw(board[i].getText());
			window.draw(board[i].getScoreText());
		}
		if (board[i].getType() == "4rd") {
			board[i].setText(board[i].getPositionX() + 30, board[i].getPositionY() + 15, board[i].getName());
			window.draw(board[i].getText());
			window.draw(board[i].getScoreText());
		}
	}
}

BoardPlate::BoardPlate() {

	std::ifstream in(FILE_BOARD_DATA);

	if (in.is_open()) {

		for (int i = 0; i < FOOTHOLD_NUMBER; i++) {

			char* tok_temp;
			/*
				BoardData.txt의 내용을 읽어옵니다.
			*/
			std::string line, row[5];
			getline(in, line);

			char* row_buffer = new char[100];
			strcpy_s(row_buffer, 100, line.c_str());
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

			int x = atoi(row[3].c_str());
			int y = atoi(row[4].c_str());

			if ((i >= 11 && i < 20) || i >= 31) y += VERTICAL_FOOTHOLD_ADD_VALUE;


			board[i] = (Board)*(new Board(type, x, y, row[1], score, i));


		} // end of for

		in.close();
	}
	else {


	}

}

void BoardPlate::playerScore(Player* player[]) {

	Text* tm = Text::getInstance();

	USES_CONVERSION;
	int playerindexes[RULE_playerPlayingNumber + 1];
	std::wstring playerPostion[RULE_playerPlayingNumber + 1];
	for (int i = 1; i <= RULE_playerPlayingNumber; i++) {
		playerindexes[i] = player[i]->OwnPiece->getPositionIndex();
		playerPostion[i] = std::wstring(A2W((board[playerindexes[i]].getName()).c_str()));
	}

	tm->text_player.setString("");
	for (int i = 1; i <= RULE_playerPlayingNumber; i++) {
		tm->text_player.setString(tm->text_player.getString() +
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

	tm->player_state.setString("");
	for (int i = 1; i <= RULE_playerPlayingNumber; i++) {
		tm->player_state.setString(tm->player_state.getString() +
			L"" + pState[i] + pStates[i]
			+ L"\n " + pSleep[i] + pSleep1[i] + pSleep2[i]
			+ L"\n "
			+ L"\n ");
	}

}