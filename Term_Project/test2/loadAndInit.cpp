#include "pch.h"
#include "loadAndInit.hpp"

#include <string>
#include <cstring>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <comdef.h>
#include <CRTDBG.H>
#include <atlconv.h>


using namespace std;

loadAndInit::loadAndInit(sf::RenderWindow& window)
{
	load(window);
	competitonScore = 0;

	font.loadFromFile(FILE_menuFont);

	//sf::Text text_turn;
	text_player.setFont(font);
	text_player.setPosition(TEXT_showPlayerInformation_X, TEXT_showPlayerInformation_Y);
	text_player.setFillColor(sf::Color::Black);
	text_player.setCharacterSize(TEXT_showPlayerInformation_Size);

	competitionText.setFont(font);
	competitionText.setPosition(570, 100);
	competitionText.setFillColor(sf::Color::Black);
	competitionText.setCharacterSize(TEXT_showPlayerInformation_Size);
	competitionText.setString(std::to_wstring(competitonScore) + L" ����");

	message.setFont(font);
	message.setPosition(300, 300);
	message.setFillColor(sf::Color::Black);
	message.setCharacterSize(TEXT_showPlayerInformation_Size);
}

void loadAndInit::init(sf::RenderWindow& window) {
	for (int i = 0; i < 10; i++)
		window.draw(allBoard[i].getSprite());
}

void loadAndInit::load(sf::RenderWindow& window) {
	ifstream in("data.txt");
	int x = 792;
	int y = 792;

	if (window.isOpen()) {

		if (in.is_open()) {
			for (int i = 0; i < 40; i++) {
				string line;
				string row[5];
				getline(in, line);

				char* row_buffer = new char[100];
				strcpy(row_buffer, line.c_str());
				char* tok = strtok(row_buffer, ",");
				int j = 0;
				while (tok != NULL) {
					row[j++] = tok;
					tok = strtok(NULL, ",");
				}
				string type = row[0];
				int score = atoi(row[2].c_str());

				if (i == 0) {
					
				}
				if (i < 10 && i>0) {
					x -= 76;
				}
				if (i == 10) {
					x -= 108;
				}
				if (i > 10 && i < 20)
					y -= 76;
				if (i == 20)
					y -= 108;
				if (i > 20 && i < 31) {
					x += 76;
					if (i == 21)
						x += 32;
				}
				if (i == 31)
					y += 32;
				if (i > 30)
					y += 76;

				Board b(window, type, x, y, row[1], score);
				allBoard[i] = b;


				window.draw(allBoard[i].getSprite());
				if (allBoard[i].getType() == "1st"){
					allBoard[i].setText(x+3,y+28,allBoard[i].getName());
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
			}
			in.close();
		}
		else {
			std::cout << "Cannot Found File" << endl;
		}
	}
}
void loadAndInit::passStart(Player& player){
	int index = player.OwnPiece->getPositionIndex();
	if (allBoard[index].getType() == "start") {
		std::cout << "����" << endl;
		player.setScore(player.getScore() + allBoard[index].getScore());
		std::cout <<" �÷��̾��� ����" << player.getScore() << endl;
		message.setString(L" �������� ���� ������ ����ϴ�");
	}
}
bool loadAndInit::BoardWithPlayer(Player& player) {
	int index = player.OwnPiece->getPositionIndex();
	//std::cout << index << endl;
	//std:cout << allBoard[index].getType()<< endl;
	if (allBoard[index].getType() == "1st"||
		allBoard[index].getType() == "2nd"||
		allBoard[index].getType() == "3rd"||
		allBoard[index].getType() ==  "4rd") {
		
		player.setScore(player.getScore() + allBoard[index].getScore());
		std::cout << "�������: "<<allBoard[index].getName() << endl;
		std::cout <<" �÷��̾��� ����"<<player.getScore() << endl;
		USES_CONVERSION;
		std::wstring position(A2W((allBoard[index].getName()).c_str()));
		message.setString(position+L" ������ �����Ͽ� "+std::to_wstring(allBoard[index].getScore())+L"������ ����ϴ�");
	}
	if (allBoard[index].getType() == "Goldenkey" ||
		allBoard[index].getType() == "Goldenkey2" ||
		allBoard[index].getType() == "Goldenkey3" ||
		allBoard[index].getType() == "Goldenkey4") {
		std::cout << "Ȳ�ݿ���" << endl;
		message.setString(L"Ȳ�ݿ��踦 �̽��ϴ�");
		GoldenKey newGold(player);
		newGold.setKey();
		newGold.chooseKey();


	}
	if (allBoard[index].getType() == "start") {
		std::cout << "������" << endl;

	}
	if (allBoard[index].getType() == "absence") {
		std::cout << "���ε�" << endl;
		player.setSleep(3);
		message.setString(L"���ε��� �������ϴ�");
	}
	if (allBoard[index].getType() == "competition") {
		std::cout << "������" << endl;
		competitonScore+=2;
		competitionText.setString(std::to_wstring(competitonScore)+L" ����");
		message.setString(L"�������� �����Ͽ� ������ �����մϴ�");
	}
	if (allBoard[index].getType() == "timemachine") {
		std::cout << "Ÿ�Ӹӽ�" << endl;
		message.setString(L"���ϴ� ������ Ŭ���ϸ� �̵��մϴ�");
		return true;
	}
	if (allBoard[index].getType() == "book") {
		std::cout << "��������" << endl;
		player.setScore(player.getScore() + allBoard[index].getScore());
		message.setString(L"���������� ��û�Ͽ� ������ �÷Ƚ��ϴ�");
	}
	if (allBoard[index].getType() == "exchange") {
		std::cout << "��ȯ�л�" << endl;
		player.setScore(player.getScore() + allBoard[index].getScore());
		message.setString(L"��ȯ�л��� �ٳ�� ������ ����մϴ�");
	}
	if (allBoard[index].getType() == "money") {
		std::cout << "���������" << endl;
		player.setScore(player.getScore() + competitonScore);
		message.setString(L"������ ���" + std::to_wstring(competitonScore)+ L"������ ŉ���մϴ�");
		competitonScore = 0;
		competitionText.setString(std::to_wstring(competitonScore) + L" ����");
		
	}
	if (allBoard[index].getType() == "intern") {
		std::cout << "���Ͻ�" << endl;
		player.setScore(player.getScore() + allBoard[index].getScore());
		message.setString(L"�鸶���ӽ��� �����Ͽ����ϴ�");
	}
	return false;
}
void loadAndInit::playerScore(Player* player[]) {
	
	int player1index = player[1]->OwnPiece->getPositionIndex();
	USES_CONVERSION;
	std::wstring player1Postion(A2W((allBoard[player1index].getName()).c_str()));
	int player2index = player[2]->OwnPiece->getPositionIndex();
	std::wstring player2Postion(A2W(allBoard[player2index].getName().c_str()));
	int player3index = player[3]->OwnPiece->getPositionIndex();
	std::wstring player3Postion(A2W(allBoard[player3index].getName().c_str()));
	int player4index = player[4]->OwnPiece->getPositionIndex();
	std::wstring player4Postion(A2W(allBoard[player4index].getName().c_str()));


	text_player.setString
		( L" Player 1  ����: " + std::to_wstring(player[1]->getScore())
		+ L"\n������ġ:"+ player1Postion
		+ L"\n "
		+ L"\n "
		+ L"Player 2  ����: " + std::to_wstring(player[2]->getScore())
		+ L"\n������ġ:"+ player2Postion
		+ L"\n"
		+ L"\n "
		+ L"Player 3  ����: " + std::to_wstring(player[3]->getScore())
		+ L"\n������ġ:" + player3Postion
		+ L"\n"
		+ L"\n "
		+ L"Player 4  ����: " + std::to_wstring(player[4]->getScore())
		+ L"\n������ġ:" + player4Postion
		+ L"\n"
		);
	
	
}