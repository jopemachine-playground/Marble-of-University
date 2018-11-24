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
	competitionText.setString(std::to_wstring(competitonScore) + L" 학점");

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
		std::cout << "월급" << endl;
		player.setScore(player.getScore() + allBoard[index].getScore());
		std::cout <<" 플레이어의 학점" << player.getScore() << endl;
		message.setString(L" 시작점을 지나 학점을 얻습니다");
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
		std::cout << "현재발판: "<<allBoard[index].getName() << endl;
		std::cout <<" 플레이어의 학점"<<player.getScore() << endl;
		USES_CONVERSION;
		std::wstring position(A2W((allBoard[index].getName()).c_str()));
		message.setString(position+L" 과목을 수강하여 "+std::to_wstring(allBoard[index].getScore())+L"학점을 얻습니다");
	}
	if (allBoard[index].getType() == "Goldenkey" ||
		allBoard[index].getType() == "Goldenkey2" ||
		allBoard[index].getType() == "Goldenkey3" ||
		allBoard[index].getType() == "Goldenkey4") {
		std::cout << "황금열쇠" << endl;
		message.setString(L"황금열쇠를 뽑습니다");
		GoldenKey newGold(player);
		newGold.setKey();
		newGold.chooseKey();


	}
	if (allBoard[index].getType() == "start") {
		std::cout << "시작점" << endl;

	}
	if (allBoard[index].getType() == "absence") {
		std::cout << "무인도" << endl;
		player.setSleep(3);
		message.setString(L"무인도에 갇혔습니다");
	}
	if (allBoard[index].getType() == "competition") {
		std::cout << "공모전" << endl;
		competitonScore+=2;
		competitionText.setString(std::to_wstring(competitonScore)+L" 학점");
		message.setString(L"공모전에 참가하여 학점을 적립합니다");
	}
	if (allBoard[index].getType() == "timemachine") {
		std::cout << "타임머신" << endl;
		message.setString(L"원하는 발판을 클릭하면 이동합니다");
		return true;
	}
	if (allBoard[index].getType() == "book") {
		std::cout << "학점은행" << endl;
		player.setScore(player.getScore() + allBoard[index].getScore());
		message.setString(L"학점은행을 신청하여 학점을 올렸습니다");
	}
	if (allBoard[index].getType() == "exchange") {
		std::cout << "교환학생" << endl;
		player.setScore(player.getScore() + allBoard[index].getScore());
		message.setString(L"교환학생을 다녀와 학점이 상승합니다");
	}
	if (allBoard[index].getType() == "money") {
		std::cout << "공모전상금" << endl;
		player.setScore(player.getScore() + competitonScore);
		message.setString(L"공모전 상금" + std::to_wstring(competitonScore)+ L"학점을 흭득합니다");
		competitonScore = 0;
		competitionText.setString(std::to_wstring(competitonScore) + L" 학점");
		
	}
	if (allBoard[index].getType() == "intern") {
		std::cout << "인턴십" << endl;
		player.setScore(player.getScore() + allBoard[index].getScore());
		message.setString(L"백마인텁십을 수강하였습니다");
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
		( L" Player 1  학점: " + std::to_wstring(player[1]->getScore())
		+ L"\n현재위치:"+ player1Postion
		+ L"\n "
		+ L"\n "
		+ L"Player 2  학점: " + std::to_wstring(player[2]->getScore())
		+ L"\n현재위치:"+ player2Postion
		+ L"\n"
		+ L"\n "
		+ L"Player 3  학점: " + std::to_wstring(player[3]->getScore())
		+ L"\n현재위치:" + player3Postion
		+ L"\n"
		+ L"\n "
		+ L"Player 4  학점: " + std::to_wstring(player[4]->getScore())
		+ L"\n현재위치:" + player4Postion
		+ L"\n"
		);
	
	
}