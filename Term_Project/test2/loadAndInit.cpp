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

	player_state.setFont(font);
	player_state.setPosition(TEXT_showPlayerInformation_X+180, TEXT_showPlayerInformation_Y);
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
	goldenKeyText.setCharacterSize(TEXT_showPlayerInformation_Size-10);
	
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
	goldenKeyText.setString(L"\n");

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
		
		string key =newGold.chooseKey(&goldenKeyText,allBoard);
		if(key == "start")
			player.setScore(player.getScore() + 4);
		if(key == "move")
			player.setScore(player.getScore() + allBoard[index+3].getScore());
		if(key == "Absence")
			player.setSleep(3);
		if (key == "competition") {
			competitonScore += 2;
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
		message.setString(L"������ ���" + std::to_wstring(competitonScore)+ L"������ ����ϴ�");
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


	int p1Turn=0;
	wstring p1State=L" ";
	if (player[1]->getSpecialTurn() > 0) {
		p1Turn = player[1]->getSpecialTurn();
		p1State = L" �߰� ���� ������: ";
	}
	if (player[1]->getSpecialTurn() < 0) {
		p1Turn = -1*player[1]->getSpecialTurn();
		p1State = L" �߰� ���� ������: ";
	}
	wstring p1States = L" ";
	if (p1Turn != 0)
		p1States = std::to_wstring(p1Turn);
	
	wstring p1Sleep = L" ";
	wstring p1Sleep1 = L" ";
	wstring p1Sleep2 = L" ";
	if (player[1]->getSleep() > 0) {
		p1Sleep = L" ���ε� Ż����� ";
		p1Sleep1 = std::to_wstring(player[1]->getSleep());
		p1Sleep2 = L" �� ���ҽ��ϴ�";
	}


	int p2Turn = 0;
	wstring p2State = L" ";
	if (player[2]->getSpecialTurn() > 0) {
		p2Turn = player[2]->getSpecialTurn();
		p2State = L" �߰� ���� ������: ";
	}
	if (player[2]->getSpecialTurn() < 0) {
		p2Turn = -1 * player[2]->getSpecialTurn();
		p2State = L" �߰� ���� ������: ";
	}
	wstring p2States = L" ";
	if (p2Turn != 0)
		p2States = std::to_wstring(p2Turn);

	wstring p2Sleep = L" ";
	wstring p2Sleep1 = L" ";
	wstring p2Sleep2 = L" ";
	if (player[2]->getSleep() > 0) {
		p2Sleep = L" ���ε� Ż����� ";
		p2Sleep1 = std::to_wstring(player[2]->getSleep());
		p2Sleep2 = L" �� ���ҽ��ϴ�";
	}


	int p3Turn = 0;
	wstring p3State = L"";
	if (player[3]->getSpecialTurn() > 0) {
		p3Turn = player[3]->getSpecialTurn();
		p3State = L" �߰� ���� ������: ";
	}
	if (player[3]->getSpecialTurn() < 0) {
		p3Turn = -1 * player[3]->getSpecialTurn();
		p3State = L" �߰� ���� ������: ";
	}
	wstring p3States = L" ";
	if (p3Turn != 0)
		p3States = std::to_wstring(p3Turn);

	wstring p3Sleep = L" ";
	wstring p3Sleep1 = L" ";
	wstring p3Sleep2 = L" ";
	if (player[3]->getSleep() > 0) {
		p3Sleep = L" ���ε� Ż����� ";
		p3Sleep1 = std::to_wstring(player[3]->getSleep());
		p3Sleep2 = L" �� ���ҽ��ϴ�";
	}

	int p4Turn = 0;
	wstring p4State = L" ";
	if (player[4]->getSpecialTurn() > 0) {
		p4Turn = player[4]->getSpecialTurn();
		p4State = L" �߰� ���� ������: ";
	}
	if (player[4]->getSpecialTurn() < 0) {
		p4Turn = -1 * player[4]->getSpecialTurn();
		p4State = L" �߰� ���� ������: ";
	}
	wstring p4States = L" ";
	if (p4Turn != 0)
		p4States = std::to_wstring(p4Turn);

	wstring p4Sleep = L" ";
	wstring p4Sleep1 = L" ";
	wstring p4Sleep2 = L" ";
	if (player[4]->getSleep() > 0) {
		p4Sleep = L" ���ε� Ż����� ";
		p4Sleep1 = std::to_wstring(player[4]->getSleep());
		p4Sleep2 = L" �� ���ҽ��ϴ�";
	}





	player_state.setString
		(	  L""+p1State+p1States
			+ L"\n "+p1Sleep+p1Sleep1+p1Sleep2
			+ L"\n "
			+ L"\n "
			+p2State + p2States
			+ L"\n " + p2Sleep + p2Sleep1 + p2Sleep2
			+ L"\n "
			+ L"\n "
			+p3State + p3States
			+ L"\n " + p3Sleep + p3Sleep1 + p3Sleep2
			+ L"\n "
			+ L"\n "
			+p4State + p4States
			+ L"\n " + p4Sleep + p4Sleep1 + p4Sleep2
			+ L"\n "
			+ L"\n "
		
		);

}
int loadAndInit::isWin(Player* player[]) {

	for (int i = 1; i < 5; i++)
	{
		if (player[i]->getScore() >= 120)
			return i;
	}
	return 0;
}
