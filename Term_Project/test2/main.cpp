#include "pch.h"

#include <iostream>
#include <Windows.h>

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include "Dice.hpp"
#include "Piece.hpp"
#include "Player.hpp"
#include "MapPoint.hpp"
#include "GameBoard.hpp"
#include "Menu.hpp"
#include "Sound.hpp"
#include "Text.hpp"
#include "Game.hpp"
#include "DiceRollButton.hpp"
#include "DicePanel.hpp"
#include "Turn.hpp"
#include "playericon.hpp"
#include "loadAndInit.hpp"

// person 1
// person 2
// 판 크기 770*770. 한칸당 90*120 위치 0,0 ~ 700,700
// 주사위 버튼 크기 228*88px. 위치 879,634 ~ 1106,721

// testsetestest
int main()
{
	// 게임 초기화
	sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), GAME_TITLE);
	sf::Vector2i MousePosition;
	sf::Event event;
	Menu menu(WINDOW_SIZE_X, WINDOW_SIZE_Y);

	//	MapPoint::MapPointInitate();
	//	std::cout << "test x[11]: " << MapPointArray[11].x << std::endl;
	//	std::cout << "test y[15]: " << MapPointArray[15].y << std::endl;

	// 사운드 관리 객체
	Sound soundManage;
	soundManage.PlayBackGroundMusic();

	// 각 플레이어, 게임 보드, 말, 턴
	Icon icon1(window,"1", TEXT_showPlayerInformation_X-95, TEXT_showPlayerInformation_Y);
	Icon icon2(window, "2", TEXT_showPlayerInformation_X-95, TEXT_showPlayerInformation_Y+120);
	Icon icon3(window, "3", TEXT_showPlayerInformation_X-95, TEXT_showPlayerInformation_Y+240);
	Icon icon4(window, "4", TEXT_showPlayerInformation_X-95, TEXT_showPlayerInformation_Y+360);



	Player *player[5];

	player[1] = new Player(window, "1");
	player[2] = new Player(window, "2");
	player[3] = new Player(window, "3");
	player[4] = new Player(window, "4");

	GameBoard background(window);
	Turn turn_ins;
	Dice *rollDice;

	// 주사위 버튼
	DiceRollButton diceButton(window);

	// 주사위 패널
	DicePanel dicePanel(window);

	// 폰트, 텍스트 관리 객체
	Text textManage;
	textManage.drawTextArgu(turn_ins.getTurn(), TRUN_NUMBER);
	;
	//textManage.drawTextArgu(player[1]->getScore(), PLAYER_SCORE);

	/*
	DrawableObject *palete[100];

	{
	palete[GAME_BOARD] = &background;


	}
	*/

	loadAndInit loadandinit(window);
	loadandinit.playerScore(player);
	bool istime = false;
outside:

	while (window.isOpen())
	{

		while (window.pollEvent(event))
		{
			switch (event.type)
			{

				// 창 닫기 이벤트
			case sf::Event::Closed: {

				window.close();
				break;

			}

									// 키보드 클릭 이벤트
			case sf::Event::KeyPressed: {

				// 게임 메뉴 호출
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {

					soundManage.PauseBackGroundMusic();

					while (window.isOpen()) {

						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) menu.moveUp();

						else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) menu.moveDown();

						else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {

							switch (menu.getSelectedItemIndex()) {

							case BUTTON_PLAY:
								soundManage.PlayBackGroundMusic();
								goto outside;
								break;

							case BUTTON_OPTION:
								std::cout << "Options has been pressed" << std::endl;
								Sleep(140);
								break;

							case BUTTON_QUIT:
								window.close();
								break;
							}

						}

						window.clear();
						menu.draw(window);
						window.display();

					}
				} // end of 게임 메뉴 호출

			} // end of 키보드 클릭 이벤트


			  // 마우스 클릭 이벤트
			case sf::Event::MouseButtonPressed:
				std::cout << "Moust button has been pressed" << std::endl;
				MousePosition = sf::Mouse::getPosition(window);

				textManage.drawTextArgu(player[1]->getScore(), PLAYER_SCORE);
				// test code
				std::cout << "현재 마우스 좌표: " << MousePosition.x << ", " << MousePosition.y << std::endl;


				// '주사위 굴리기' 버튼 클릭
				if (istime) {
				
					for (int i = 0; i < 40; i++)
						if (loadandinit.getBoard()[i].isInBoard(MousePosition)) {

							for (int j = 0; j < (i + 10) % 40; j++) {

								//rollDice->getMoveNumber()
								switch ((turn_ins.getTurn() - 1) % 4) {
								case 1:
									player[1]->OwnPiece->MovePiece();
									loadandinit.passStart(*player[1]);
									break;
								case 2:
									player[2]->OwnPiece->MovePiece();
									loadandinit.passStart(*player[2]);
									break;
								case 3:
									player[3]->OwnPiece->MovePiece();
									loadandinit.passStart(*player[3]);
									break;
								case 0:
									player[4]->OwnPiece->MovePiece();
									loadandinit.passStart(*player[4]);
									break;
								}
							}
							switch ((turn_ins.getTurn() - 1) % 4) {
							case 1:
								std::cout << "플레이어 1 ";
								istime = loadandinit.BoardWithPlayer(*player[1]);
								break;
							case 2:
								std::cout << "플레이어 2 ";
								istime = loadandinit.BoardWithPlayer(*player[2]);
								break;
							case 3:
								std::cout << "플레이어 3 ";
								istime = loadandinit.BoardWithPlayer(*player[3]);
								break;
							case 0:
								std::cout << "플레이어 4 ";
								istime = loadandinit.BoardWithPlayer(*player[4]);
								break;
							}
							loadandinit.playerScore(player);

							//istime = false;
							window.draw(player[1]->OwnPiece->getSprite());
						}
				}


				if (diceButton.isInButton(MousePosition)) {

					soundManage.PlayButtonClickedSound();

					rollDice = new Dice();
				
					int turn= turn_ins.getTurn() % 4;

					if (turn == 0)
						turn = 4;
					if ((player[turn]->getSleep()) == 0) {

						for (int i = 0; i <  4; i++) {
							//rollDice->getMoveNumber()
							switch (turn_ins.getTurn() % 4) {
							case 1:
								player[1]->OwnPiece->MovePiece();
								loadandinit.passStart(*player[1]);
								break;
							case 2:
								player[2]->OwnPiece->MovePiece();
								loadandinit.passStart(*player[2]);
								break;
							case 3:
								player[3]->OwnPiece->MovePiece();
								loadandinit.passStart(*player[3]);
								break;
							case 0:
								player[4]->OwnPiece->MovePiece();
								loadandinit.passStart(*player[4]);
								break;
							}
							
							window.clear();
							window.draw(background.getSprite());
							loadandinit.load(window);
							window.draw(player[1]->OwnPiece->getSprite());
							window.draw(player[2]->OwnPiece->getSprite());
							window.draw(player[3]->OwnPiece->getSprite());
							window.draw(player[4]->OwnPiece->getSprite());
							window.draw(icon1.getSprite());
							window.draw(icon2.getSprite());
							window.draw(icon3.getSprite());
							window.draw(icon4.getSprite());
							//window.draw(diceButton.getSprite());

							// 주사위 패널
							//window.draw(dicePanel.getSprite());
							window.draw(dicePanel.getDice1Sprite(*rollDice));
							window.draw(dicePanel.getDice2Sprite(*rollDice));
							window.draw(textManage.getText(TRUN_NUMBER));
							//window.draw(textManage.getText(PLAYER_SCORE));
							window.draw(loadandinit.getText());
							window.draw(loadandinit.getCompetitionText());
							window.draw(loadandinit.getMessage());
							window.display();
							soundManage.PlayPieceMoveSound();
							Sleep(40);
						}
						switch ((turn_ins.getTurn()) % 4) {
						case 1:
							std::cout << "플레이어 1 ";
							istime =loadandinit.BoardWithPlayer(*player[1]);
							break;
						case 2:
							std::cout << "플레이어 2 ";
							istime = loadandinit.BoardWithPlayer(*player[2]);
							break;
						case 3:
							std::cout << "플레이어 3 ";
							istime =loadandinit.BoardWithPlayer(*player[3]);
							break;
						case 0:
							std::cout << "플레이어 4 ";
							istime = loadandinit.BoardWithPlayer(*player[4]);
							break;
						}
						loadandinit.playerScore(player);

					}
					else {
						player[turn]->setSleep(player[turn]->getSleep() - 1);
						std::cout << player[turn]->getSleep() << std::endl;
					}
					// test code
					std::cout << "1번 주사위 : " << rollDice->getDiceNumber1() << std::endl;
					std::cout << "2번 주사위 : " << rollDice->getDiceNumber2() << std::endl;
					std::cout << "현재 위치: " << player[1]->OwnPiece->getPositionIndex() << std::endl;

					delete rollDice;

					turn_ins.IncTurn();
					
				}

				
				
				

				textManage.drawTextArgu(player[1]->getScore(), PLAYER_SCORE);
				textManage.drawTextArgu(turn_ins.getTurn(), TRUN_NUMBER);

				std::cout << "현재 " << turn_ins.getTurn() << "턴 입니다." << std::endl;

				// test code
				//std::cout << "test : " << player1->OwnPiece->getPositionIndex() << " : " << MapPointArray[player1->OwnPiece->getPositionIndex()].x << std::endl;
				//	std::cout << "test : " << player1->OwnPiece->getPositionIndex() << " : " << MapPointArray[player1->OwnPiece->getPositionIndex()].y << std::endl;

				break;
			}

		} // end of while (window.pollEvent(event))

		window.clear();

		window.draw(background.getSprite());
		loadandinit.load(window);



		window.draw(player[1]->OwnPiece->getSprite());
		window.draw(player[2]->OwnPiece->getSprite());
		window.draw(player[3]->OwnPiece->getSprite());
		window.draw(player[4]->OwnPiece->getSprite());
		//window.draw(dicePanel.getSprite());
		window.draw(diceButton.getSprite());
		window.draw(textManage.getText(TRUN_NUMBER));
		window.draw(loadandinit.getText());
		window.draw(loadandinit.getCompetitionText());
		window.draw(loadandinit.getMessage());
		window.draw(icon1.getSprite()); 
		window.draw(icon2.getSprite());
		window.draw(icon3.getSprite());
		window.draw(icon4.getSprite());
		window.display();

	} // end of while (window.isOpen())

}

