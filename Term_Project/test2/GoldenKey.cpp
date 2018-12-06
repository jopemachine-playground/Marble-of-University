#include "pch.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "GoldenKey.hpp"
#include "Player.hpp"

using namespace std;

void GoldenKey::setKey()
{
	//random 값을 가지고 key를 설정
	setRandom();
	key = getRandom();
}

std::string GoldenKey::chooseKey(sf::Text *text, Board board[])
{
	std::string key;
	int result = 0;
	switch (getKey()) {
	case 0:
		key = keyFunction0(text, board);
		break;
	case 1:
		key = keyFunction1(text, board);
		break;
	case 2:
		key = keyFunction2(text, board);
		break;
	case 3:
		key = keyFunction3(text, board);
		break;
	case 4:
		key = keyFunction4(text, board);
		break;
	case 5:
		key = keyFunction5(text, board);
		break;
	case 6:
		key = keyFunction6(text, board);
		break;
	case 7:
		key = keyFunction7(text, board);
		break;
	case 8:
		key = keyFunction8(text, board);
		break;
	case 9:
		key = keyFunction9(text, board);
		break;
	case 10:
		key = keyFunction10(text, board);
		break;
	case 11:
		key = keyFunction11(text, board);
		break;
	case 12:
		key = keyFunction12(text, board);
		break;
	case 13:
		key = keyFunction13(text, board);
		break;
	default:
		break;
	}
	return key;
}


void GoldenKey::setRandom()
{
	srand((unsigned int)time(NULL));
	random = rand() % NUMBER_OF_GOLDENKEY;
}

std::string GoldenKey::keyFunction0(sf::Text *text, Board board[])
{
	//빡공 : 가산점 3점 획득합니다.
	getPlayer().setScore(getPlayer().getScore() + 3);
	//cout << ">> 빡 공 !! <<" << endl;
	//cout << "공부를 열심히 하셨군요! 가산점을 획득하셨습니다. (+3 점)" << endl;
	text->setString(L"공부를 열심히 하셨군요! 가산점을 획득하셨습니다. (+3 점)");
	return "score";
}
std::string GoldenKey::keyFunction1(sf::Text *text, Board board[])
{
	//밤샘 공부 : 다음 턴 주사위 굴리기를 쉬고, 학점을 4점 올립니다.
	getPlayer().setScore(getPlayer().getScore() + 4);
	getPlayer().setSleep(getPlayer().getSleep() + 1);
	//cout << ">> 밤샘 공부<<" << endl;
	//cout << "너무 무리하시지는 마세요. 밤샘 공부의 반동으로 한 턴 쉽니다. (+4 점)" << endl;
	text->setString(L"너무 무리하시지는 마세요. 밤샘 공부의 반동으로 한 턴 쉽니다. (+4 점)");
	return "scoreAndSleep";
}
std::string GoldenKey::keyFunction2(sf::Text *text, Board board[])
{
	//대리 출석 : 3턴동안 학점이 1점씩 추가로 올라갑니다.
	for (int i = 1; i < 3; i++) getPlayer().setSpecialTurn(3);
	//cout << ">>대리 출석<<" << endl;
	//cout << "누군가에게 출석을 부탁합니다. 3턴동안 학점이 1점씩 추가로 올라갑니다." << endl;
	text->setString(L"누군가에게 출석을 부탁합니다. 3턴동안 학점이 1점씩 추가로 올라갑니다.");
	return "addScore";
}
std::string GoldenKey::keyFunction3(sf::Text *text, Board board[])
{
	//의욕만만 : 앞으로 3칸 움직입니다.
	for (int i = 0; i < 3; i++)
		getPlayer().OwnPiece->MovePiece();
	//getPlayer().setScore(getPlayer().getScore() + board[getPlayer().OwnPiece->getPositionIndex() + 3].getScore());
	//cout << ">> 의욕만?<<" << endl;
	//cout << "넘치는 의욕으로 3칸 앞으로 전진합니다." << endl;
	text->setString(L"넘치는 의욕으로 3칸 앞으로 전진합니다.");
	return "move";
}
std::string GoldenKey::keyFunction4(sf::Text *text, Board board[])
{
	//개강 : [시작] 발판으로 이동합니다.
	while (!(getPlayer().OwnPiece->getPositionIndex() == 0))
		getPlayer().OwnPiece->MovePiece();
	//cout << ">> 개강 <<" << endl;
	//cout << "새 학기가 시작되었습니다! [시작] 발판으로 이동합니다." << endl;
	text->setString(L"새 학기가 시작되었습니다! [시작] 발판으로 이동합니다.");
	return "start";
}
std::string GoldenKey::keyFunction5(sf::Text *text, Board board[])
{

	//토익 800점 취득 : 학점 4점 추가합니다.
	getPlayer().setScore(getPlayer().getScore() + 4);
	//cout << ">> 토익 800점 취득 <<" << endl;
	//cout << "토익 800점을 획득하셨군요! Global English 면제입니다! (+4 점)" << endl;
	text->setString(L"토익 800점을 획득하셨군요! Global English 면제입니다! (+4 점)");
	return "English";
}
std::string GoldenKey::keyFunction6(sf::Text *text, Board board[])
{
	//족보 획득 : 다음 강의의 학점을 1학점 추가로 획득합니다.
	getPlayer().setSpecialTurn(1);
	//cout << ">> 족보 획득 <<" << endl;
	//cout << "유용하게 쓸 수 있는 족보를 획득했습니다. 다음 강의의 학점을 1학점 추가 획득합니다." << endl;
	text->setString(L"유용하게 쓸 수 있는 족보를 획득했습니다. 다음 강의의 학점을 1학점 추가 획득합니다.");
	return "AddScore";
}
std::string GoldenKey::keyFunction7(sf::Text *text, Board board[])
{
	//과제 미제출 : 학점이 2점 깎입니다.
	getPlayer().setScore(getPlayer().getScore() - 2);
	//cout << ">> 과제 미제출 !! <<" << endl;
	//cout << "저런.. 과제 제출 마감을 지나쳤습니다. 학점을 잃습니다. (-2 점)" << endl;
	text->setString(L"저런.. 과제 제출 마감을 지나쳤습니다. 학점을 잃습니다. (-2 점)");
	return "loseScore";
}
std::string GoldenKey::keyFunction8(sf::Text *text, Board board[])
{
	//입영통지서 : [휴학] 발판으로 이동합니다.
	while (!(getPlayer().OwnPiece->getPositionIndex() == 10)) //10은 휴학 발판의 Index
		getPlayer().OwnPiece->MovePiece();
	//cout << ">>입 영 통 지 서<<" << endl;
	//cout << "국가가 그대를 부릅니다! 일단 휴학하셔야겠군요. [휴학] 발판으로 이동합니다." << endl;
	text->setString(L"국가가 그대를 부릅니다! 일단 휴학하셔야겠군요. [휴학] 발판으로 이동합니다.");
	return "Absence";
}
std::string GoldenKey::keyFunction9(sf::Text *text, Board board[])
{
	//과도한 YXXTUBE 시청 : 3턴동안 학점을 1학점 덜 획득 합니다.
	for (int i = 0; i < 3; i++) getPlayer().setSpecialTurn(-3);
	cout << ">> 과도한 YXXTUBE 시청 <<" << endl;
	cout << "지나친 동영상 시청은 일상생활에 지장을 줄 수 있습니다. 3턴 동안 1학점을 덜 획득합니다." << endl;
	text->setString(L"지나친 동영상 시청은 일상생활에 지장을 줄 수 있습니다. 3턴 동안 1학점을 덜 획득합니다.");
	return "loseAdd";
}
std::string GoldenKey::keyFunction10(sf::Text *text, Board board[])
{
	//공모전 참가 : [공모전 참가] 발판으로 이동합니다.
	while (!(getPlayer().OwnPiece->getPositionIndex() == 20)) //20은 공모전 참가 발판의 Index
		getPlayer().OwnPiece->MovePiece();
	//cout << ">> 공모전 참가<<" << endl;
	//cout << "공모전에 참가합니다! [공모전 참가] 발판으로 이동합니다." << endl;
	text->setString(L"공모전에 참가합니다! [공모전 참가] 발판으로 이동합니다.");
	return "competition";
}
std::string GoldenKey::keyFunction11(sf::Text *text, Board board[])
{
	//공모전 발표 : [공모전 발표] 발판으로 이동합니다.
	while (!(getPlayer().OwnPiece->getPositionIndex() == 27)) //27은 공모전 발표 발판의 Index
		getPlayer().OwnPiece->MovePiece();
	//cout << ">> 공모전 발표<<" << endl;
	//cout << "공모전에서 발표를 합니다! [공모전 발표] 발판으로 이동합니다." << endl;
	text->setString(L"공모전에서 발표를 합니다! [공모전 발표] 발판으로 이동합니다.");
	return "money";
}
std::string GoldenKey::keyFunction12(sf::Text *text, Board board[])
{
	//시간을 되돌릴 수 있다면 : [타임 머신] 발판으로 이동합니다.
	while (!(getPlayer().OwnPiece->getPositionIndex() == 30)) //30은 타임 머신 발판의 Index
		getPlayer().OwnPiece->MovePiece();
	//cout << ">> 타임 머신<<" << endl;
	//cout << "시간을 되돌릴 수 있을까요? [타임 머신] 발판으로 이동합니다." << endl;
	text->setString(L"시간을 되돌릴 수 있을까요? [타임 머신] 발판으로 이동합니다.");
	return "time";
}
std::string GoldenKey::keyFunction13(sf::Text *text, Board board[])
{
	//늦잠 : 다음의 획득할 학점이 1 감소합니다.
	getPlayer().setSpecialTurn(-1);
	//cout << ">> 늦잠 <<" << endl;
	//cout << "늦잠을 잤습니다. 수업에 늦겠는걸요? 다음 강의의 학점을 1점 덜 획득합니다." << endl;
	text->setString(L"늦잠을 잤습니다. 수업에 늦겠는걸요? 다음 강의의 학점을 1점 덜 획득합니다.");
	return "loseAdd";
}
