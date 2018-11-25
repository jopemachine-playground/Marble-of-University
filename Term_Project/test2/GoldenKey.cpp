#include "pch.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "GoldenKey.hpp"
#include "Player.hpp"
#include "MapPoint.hpp"

using namespace std;

void GoldenKey::setKey()
{
	//random 값을 가지고 key를 설정
	setRandom();
	key = getRandom();
}
void GoldenKey::chooseKey()
{
	switch (getKey()) {
	case 0:
		keyFunction0();
		break;
	case 1:
		keyFunction1();
		break;
	case 2:
		keyFunction2();
		break;
	case 3:
		keyFunction3();
		break;
	case 4:
		keyFunction4();
		break;
	case 5:
		keyFunction5();
		break;
	case 6:
		keyFunction6();
		break;
	case 7:
		keyFunction7();
		break;
	case 8:
		keyFunction8();
		break;
	case 9:
		keyFunction9();
		break;
	case 10:
		keyFunction10();
		break;
	case 11:
		keyFunction11();
		break;
	case 12:
		keyFunction12();
		break;
	case 13:
		keyFunction13();
		break;
	default:
		break;
	}
}


void GoldenKey::setRandom()
{
	srand((unsigned int)time(NULL));
	random = rand() % 14;
}

void GoldenKey::keyFunction0()
{
	//빡공 : 가산점 3점 획득합니다.
	getPlayer().setScore(getPlayer().getScore() + 3);
	cout << ">> 빡 공 !! <<" << endl;
	cout << "공부를 열심히 하셨군요! 가산점을 획득하셨습니다. (+3 점)"  << endl;
}
void GoldenKey::keyFunction1()
{
	//밤샘 공부 : 다음 턴 주사위 굴리기를 쉬고, 학점을 4점 올립니다.
	getPlayer().setScore(getPlayer().getScore() + 4);
	getPlayer().setSleep(getPlayer().getSleep() + 1);
	cout << ">> 밤샘 공부<<" << endl;
	cout << "너무 무리하시지는 마세요. 밤샘 공부의 반동으로 한 턴 쉽니다. (+4 점)" << endl;
}
void GoldenKey::keyFunction2()
{
	//대리 출석 : 3턴동안 학점이 1점씩 추가로 올라갑니다.
	for(int i = 1; i < 3; i++ ) getPlayer().setSpecialTurn(3);
	cout << ">>대리 출석<<" << endl;
	cout << "누군가에게 출석을 부탁합니다. 3턴동안 학점이 1점씩 추가로 올라갑니다." << endl;
}
void GoldenKey::keyFunction3()
{
	//의욕만만 : 앞으로 3칸 움직입니다.
	for (int i = 0; i < 3; i++)
		getPlayer().OwnPiece->MovePiece();
	cout << ">> 의묙만만 <<" << endl;
	cout << "넘치는 의욕으로 3칸 앞으로 전진합니다." << endl;
}
void GoldenKey::keyFunction4()
{
	//개강 : [시작] 발판으로 이동합니다.
	while (!(getPlayer().OwnPiece->getPositionIndex() == 0))
		getPlayer().OwnPiece->MovePiece();
	cout << ">> 개강 <<" << endl;
	cout << "새 학기가 시작되었습니다! [시작] 발판으로 이동합니다." << endl;
}
void GoldenKey::keyFunction5()
{

	//토익 800점 취득 : 학점 4점 추가합니다.
	getPlayer().setScore(getPlayer().getScore() + 4);
	cout << ">> 토익 800점 취득 <<" << endl;
	cout << "토익 800점을 획득하셨군요! Global English 면제입니다! (+4 점)" <<  endl;
}
void GoldenKey::keyFunction6()
{
	//족보 획득 : 다음 강의의 학점을 1학점 추가로 획득합니다.
	getPlayer().setSpecialTurn(1);
	cout << ">> 족보 획득 <<" << endl;
	cout << "유용하게 쓸 수 있는 족보를 획득했습니다. 다음 강의의 학점을 1학점 추가 획득합니다." << endl;
}
void GoldenKey::keyFunction7()
{
	//과제 미제출 : 학점이 2점 깎입니다.
	getPlayer().setScore(getPlayer().getScore() - 2);
	cout << ">> 과제 미제출 !! <<" << endl;
	cout << "저런.. 과제 제출 마감을 지나쳤습니다. 학점을 잃습니다. (-2 점)"<< endl;
}
void GoldenKey::keyFunction8()
{
	//입영통지서 : [휴학] 발판으로 이동합니다.
	while (!(getPlayer().OwnPiece->getPositionIndex() == 10)) //10은 휴학 발판의 Index
		getPlayer().OwnPiece->MovePiece();
	cout << ">>입 영 통 지 서<<" << endl;
	cout << "국가가 그대를 부릅니다! 일단 휴학하셔야겠군요. [휴학] 발판으로 이동합니다." << endl;
}
void GoldenKey::keyFunction9()
{
	//과도한 YXXTUBE 시청 : 3턴동안 학점을 1학점 덜 획득 합니다.
	for(int i = 0; i < 3; i++ ) getPlayer().setSpecialTurn(-3);
	cout << ">> 과도한 YXXTUBE 시청 <<" << endl;
	cout << "지나친 동영상 시청은 일상생활에 지장을 줄 수 있습니다. 3턴 동안 1학점을 덜 획득합니다." << endl;
}
void GoldenKey::keyFunction10()
{
	//공모전 참가 : [공모전 참가] 발판으로 이동합니다.
	while (!(getPlayer().OwnPiece->getPositionIndex() == 20)) //20은 공모전 참가 발판의 Index
		getPlayer().OwnPiece->MovePiece();
	cout << ">> 공모전 참가<<" << endl;
	cout << "공모전에 참가합니다! [공모전 참가] 발판으로 이동합니다." << endl;
}
void GoldenKey::keyFunction11()
{
	//공모전 발표 : [공모전 발표] 발판으로 이동합니다.
	while (!(getPlayer().OwnPiece->getPositionIndex() == 27)) //27은 공모전 발표 발판의 Index
		getPlayer().OwnPiece->MovePiece();
	cout << ">> 공모전 발표<<" << endl;
	cout << "공모전에서 발표를 합니다! [공모전 발표] 발판으로 이동합니다." << endl;
}
void GoldenKey::keyFunction12()
{
	//시간을 되돌릴 수 있다면 : [타임 머신] 발판으로 이동합니다.
	while (!(getPlayer().OwnPiece->getPositionIndex() == 30)) //30은 타임 머신 발판의 Index
		getPlayer().OwnPiece->MovePiece();
	cout << ">> 타임 머신<<" << endl;
	cout << "시간을 되돌릴 수 있을까요? [타임 머신] 발판으로 이동합니다." << endl;
}
void GoldenKey::keyFunction13()
{
	//늦잠 : 다음의 획득할 학점이 1 감소합니다.
	getPlayer().setSpecialTurn(-1);
	cout << ">> 늦잠 <<" << endl;
	cout << "늦잠을 잤습니다. 수업에 늦겠는걸요? 다음 강의의 학점을 1점 덜 획득합니다." << endl;
}
