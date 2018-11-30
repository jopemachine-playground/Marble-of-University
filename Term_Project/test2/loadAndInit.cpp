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
	competitionText.setString(std::to_wstring(competitonScore) + L" ����");

	message.setFont(font);
	message.setPosition(250, 300);
	message.setFillColor(sf::Color::Black);
	message.setCharacterSize(TEXT_showPlayerInformation_Size);

	goldenKeyText.setFont(font);
	goldenKeyText.setPosition(150, 400);
	goldenKeyText.setFillColor(sf::Color::Black);
	goldenKeyText.setCharacterSize(TEXT_showPlayerInformation_Size - 10);

}

/* �Ʒ� �޼���� ������ ���� */
void LoadAndInit::boardDraw(sf::RenderWindow& window) {
	for (int i = 0; i < 10; i++)
		window.draw(allBoard[i].getSprite());
}

/*

	WinMain���� ���ѷ����� ���� DataLoad�� �ݺ��մϴ�.

	=> �����͸� �� ���� �ε��� ��� ����� �� �����??
	(�������� ���� �ٸ� �������)

*/
void LoadAndInit::boardDataLoad(sf::RenderWindow& window) {

	std::ifstream in(FILE_BOARD_DATA);

	if (window.isOpen()) {

		if (in.is_open()) {

			for (int i = 0; i < FOOTHOLD_NUMBER; i++) {

				int x = MapPoint[i].x;
				int y = MapPoint[i].y;

				/*
					data.txt�� ������ �о�ɴϴ�.
				*/
				std::string line, row[5];
				char* tok_temp;
				getline(in, line);

				char* row_buffer = new char[100];

				/*
					Data�� ���� �� ���� : 1st,�ý��� ���α׷���,3
					= NULL���� 24 ����Ʈ�� ������
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
					���� ������ ���
					���� ������ ���� �ٸ���,
					ĳ���͸� �� �� ����� �մϴ�.

					�� ��ġ�� VERTICAL_FOOTHOLD_ADD_VALUE�̰� 32�Դϴ�.
				*/

				if ((i >= 11 && i < 20) || i >= 31) y += VERTICAL_FOOTHOLD_ADD_VALUE;


				allBoard[i] = (Board)*(new Board(window, type, x, y, row[1], score));

				window.draw(allBoard[i].getSprite());

				/*
					�ε��� �����͸� window�� ǥ���մϴ�
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

		message.setString(L" �������� ���� ������ ����ϴ�");
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
			ANSI�� UNICODE�� ��ȯ�ϱ� ���� ��ũ��
		*/

		USES_CONVERSION;
		std::wstring position(A2W((allBoard[index].getName()).c_str()));
		message.setString(position + L" ������ �����Ͽ� " + std::to_wstring(allBoard[index].getScore()) + L"������ ����ϴ�");
	}
	if (allBoard[index].getType() == "Goldenkey" ||
		allBoard[index].getType() == "Goldenkey2" ||
		allBoard[index].getType() == "Goldenkey3" ||
		allBoard[index].getType() == "Goldenkey4") {

		message.setString(L"Ȳ�ݿ��踦 �̽��ϴ�");
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
			competitionText.setString(std::to_wstring(competitonScore) + L" ����");
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
		message.setString(L"���ε��� �������ϴ�");
	}
	if (allBoard[index].getType() == "competition") {

		competitonScore += 2;
		competitionText.setString(std::to_wstring(competitonScore) + L" ����");
		message.setString(L"�������� �����Ͽ� ������ �����մϴ�");
	}
	if (allBoard[index].getType() == "timemachine") {

		message.setString(L"���ϴ� ������ Ŭ���ϸ� �̵��մϴ�");
		return true;
	}
	if (allBoard[index].getType() == "book") {

		player.setScore(player.getScore() + allBoard[index].getScore());
		message.setString(L"���������� ��û�Ͽ� ������ �÷Ƚ��ϴ�");
	}
	if (allBoard[index].getType() == "exchange") {

		player.setScore(player.getScore() + allBoard[index].getScore());
		message.setString(L"��ȯ�л��� �ٳ�� ������ ����մϴ�");
	}
	if (allBoard[index].getType() == "money") {

		player.setScore(player.getScore() + competitonScore);
		message.setString(L"������ ���" + std::to_wstring(competitonScore) + L"������ ����ϴ�");
		competitonScore = 0;
		competitionText.setString(std::to_wstring(competitonScore) + L" ����");

	}
	if (allBoard[index].getType() == "intern") {

		player.setScore(player.getScore() + allBoard[index].getScore());
		message.setString(L"�鸶 ���Ͻ��� �����Ͽ����ϴ�");
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
			+ L" ����: " + std::to_wstring(player[i]->getScore())
			+ L"\n������ġ:" + playerPostion[i]
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
			pState[i] = L" �߰� ���� ������: ";
		}
		if (player[i]->getSpecialTurn() < 0) {
			pTurn[i] = -1 * player[i]->getSpecialTurn();
			pState[i] = L" �߰� ���� ������: ";
		}
		pStates[i] = L" ";
		if (pTurn[i] != 0)
			pStates[i] = std::to_wstring(pTurn[i]);

		pSleep[i] = L" ";
		pSleep1[i] = L" ";
		pSleep2[i] = L" ";
		if (player[i]->getSleep() > 0) {
			pSleep[i] = L" ���ε� Ż����� ";
			pSleep1[i] = std::to_wstring(player[i]->getSleep());
			pSleep2[i] = L" �� ���ҽ��ϴ�";
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