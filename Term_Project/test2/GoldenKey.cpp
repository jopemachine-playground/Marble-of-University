#include "pch.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "GoldenKey.hpp"
#include "Player.hpp"
#include "MapPoint.hpp"
#include "loadAndInit.hpp"

using namespace std;

void GoldenKey::setKey()
{
	//random ���� ������ key�� ����
	setRandom();
	key = getRandom();
}
std::string GoldenKey::chooseKey(sf::Text *text,Board board[])
{
	std::string key;
	int result=0;
	switch (getKey()) {
	case 0:
		key = keyFunction0(text,board);
		break;
	case 1:
		key = keyFunction1(text,board);
		break;
	case 2:
		key = keyFunction2(text,board);
		break;
	case 3:
		key = keyFunction3(text,board);
		break;
	case 4:
		key = keyFunction4(text,board);
		break;
	case 5:
		key = keyFunction5(text,board);
		break;
	case 6:
		key = keyFunction6(text,board);
		break;
	case 7:
		key = keyFunction7(text,board);
		break;
	case 8:
		key = keyFunction8(text,board);
		break;
	case 9:
		key = keyFunction9(text,board);
		break;
	case 10:
		key = keyFunction10(text,board);
		break;
	case 11:
		key = keyFunction11(text,board);
		break;
	case 12:
		key = keyFunction12(text,board);
		break;
	case 13:
		key = keyFunction13(text,board);
		break;
	default:
		break;
	}
	return key;
}


void GoldenKey::setRandom()
{
	srand((unsigned int)time(NULL));
	random = rand() % 14;
}

std::string GoldenKey::keyFunction0(sf::Text *text, Board board[])
{
	//���� : ������ 3�� ȹ���մϴ�.
	getPlayer().setScore(getPlayer().getScore() + 3);
	cout << ">> �� �� !! <<" << endl;
	cout << "���θ� ������ �ϼ̱���! �������� ȹ���ϼ̽��ϴ�. (+3 ��)" << endl;
	text->setString(L"���θ� ������ �ϼ̱���! �������� ȹ���ϼ̽��ϴ�. (+3 ��)");
	return "score";
}
std::string GoldenKey::keyFunction1(sf::Text *text, Board board[])
{
	//��� ���� : ���� �� �ֻ��� �����⸦ ����, ������ 4�� �ø��ϴ�.
	getPlayer().setScore(getPlayer().getScore() + 4);
	getPlayer().setSleep(getPlayer().getSleep() + 1);
	cout << ">> ��� ����<<" << endl;
	cout << "�ʹ� �����Ͻ����� ������. ��� ������ �ݵ����� �� �� ���ϴ�. (+4 ��)" << endl;
	text->setString(L"�ʹ� �����Ͻ����� ������. ��� ������ �ݵ����� �� �� ���ϴ�. (+4 ��)");
	return "scoreAndSleep";
}
std::string GoldenKey::keyFunction2(sf::Text *text, Board board[])
{
	//�븮 �⼮ : 3�ϵ��� ������ 1���� �߰��� �ö󰩴ϴ�.
	for (int i = 1; i < 3; i++) getPlayer().setSpecialTurn(3);
	cout << ">>�븮 �⼮<<" << endl;
	cout << "���������� �⼮�� ��Ź�մϴ�. 3�ϵ��� ������ 1���� �߰��� �ö󰩴ϴ�." << endl;
	text->setString(L"���������� �⼮�� ��Ź�մϴ�. 3�ϵ��� ������ 1���� �߰��� �ö󰩴ϴ�.");
	return "addScore";
}
std::string GoldenKey::keyFunction3(sf::Text *text, Board board[])
{
	//�ǿ常�� : ������ 3ĭ �����Դϴ�.
	for (int i = 0; i < 3; i++)
		getPlayer().OwnPiece->MovePiece();
	//getPlayer().setScore(getPlayer().getScore() + board[getPlayer().OwnPiece->getPositionIndex() + 3].getScore());
	cout << ">> �Ǒ򸸸� <<" << endl;
	cout << "��ġ�� �ǿ����� 3ĭ ������ �����մϴ�." << endl;
	text->setString(L"��ġ�� �ǿ����� 3ĭ ������ �����մϴ�.");
	return "move";
}
std::string GoldenKey::keyFunction4(sf::Text *text, Board board[])
{
	//���� : [����] �������� �̵��մϴ�.
	while (!(getPlayer().OwnPiece->getPositionIndex() == 0))
		getPlayer().OwnPiece->MovePiece();
	cout << ">> ���� <<" << endl;
	cout << "�� �бⰡ ���۵Ǿ����ϴ�! [����] �������� �̵��մϴ�." << endl;
	text->setString(L"�� �бⰡ ���۵Ǿ����ϴ�! [����] �������� �̵��մϴ�.");
	return "start";
}
std::string GoldenKey::keyFunction5(sf::Text *text, Board board[])
{

	//���� 800�� ��� : ���� 4�� �߰��մϴ�.
	getPlayer().setScore(getPlayer().getScore() + 4);
	cout << ">> ���� 800�� ��� <<" << endl;
	cout << "���� 800���� ȹ���ϼ̱���! Global English �����Դϴ�! (+4 ��)" << endl;
	text->setString(L"���� 800���� ȹ���ϼ̱���! Global English �����Դϴ�! (+4 ��)");
	return "English";
}
std::string GoldenKey::keyFunction6(sf::Text *text, Board board[])
{
	//���� ȹ�� : ���� ������ ������ 1���� �߰��� ȹ���մϴ�.
	getPlayer().setSpecialTurn(1);
	cout << ">> ���� ȹ�� <<" << endl;
	cout << "�����ϰ� �� �� �ִ� ������ ȹ���߽��ϴ�. ���� ������ ������ 1���� �߰� ȹ���մϴ�." << endl;
	text->setString(L"�����ϰ� �� �� �ִ� ������ ȹ���߽��ϴ�. ���� ������ ������ 1���� �߰� ȹ���մϴ�.");
	return "AddScore";
}
std::string GoldenKey::keyFunction7(sf::Text *text, Board board[])
{
	//���� ������ : ������ 2�� ���Դϴ�.
	getPlayer().setScore(getPlayer().getScore() - 2);
	cout << ">> ���� ������ !! <<" << endl;
	cout << "����.. ���� ���� ������ �����ƽ��ϴ�. ������ �ҽ��ϴ�. (-2 ��)" << endl;
	text->setString(L"����.. ���� ���� ������ �����ƽ��ϴ�. ������ �ҽ��ϴ�. (-2 ��)");
	return "loseScore";
}
std::string GoldenKey::keyFunction8(sf::Text *text, Board board[])
{
	//�Կ������� : [����] �������� �̵��մϴ�.
	while (!(getPlayer().OwnPiece->getPositionIndex() == 10)) //10�� ���� ������ Index
		getPlayer().OwnPiece->MovePiece();
	cout << ">>�� �� �� �� ��<<" << endl;
	cout << "������ �״븦 �θ��ϴ�! �ϴ� �����ϼž߰ڱ���. [����] �������� �̵��մϴ�." << endl;
	text->setString(L"������ �״븦 �θ��ϴ�! �ϴ� �����ϼž߰ڱ���. [����] �������� �̵��մϴ�.");
	return "Absence";
}
std::string GoldenKey::keyFunction9(sf::Text *text, Board board[])
{
	//������ YXXTUBE ��û : 3�ϵ��� ������ 1���� �� ȹ�� �մϴ�.
	for (int i = 0; i < 3; i++) getPlayer().setSpecialTurn(-3);
	cout << ">> ������ YXXTUBE ��û <<" << endl;
	cout << "����ģ ������ ��û�� �ϻ��Ȱ�� ������ �� �� �ֽ��ϴ�. 3�� ���� 1������ �� ȹ���մϴ�." << endl;
	text->setString(L"����ģ ������ ��û�� �ϻ��Ȱ�� ������ �� �� �ֽ��ϴ�. 3�� ���� 1������ �� ȹ���մϴ�.");
	return "loseAdd";
}
std::string GoldenKey::keyFunction10(sf::Text *text, Board board[])
{
	//������ ���� : [������ ����] �������� �̵��մϴ�.
	while (!(getPlayer().OwnPiece->getPositionIndex() == 20)) //20�� ������ ���� ������ Index
		getPlayer().OwnPiece->MovePiece();
	cout << ">> ������ ����<<" << endl;
	cout << "�������� �����մϴ�! [������ ����] �������� �̵��մϴ�." << endl;
	text->setString(L"�������� �����մϴ�! [������ ����] �������� �̵��մϴ�.");
	return "competition";
}
std::string GoldenKey::keyFunction11(sf::Text *text, Board board[])
{
	//������ ��ǥ : [������ ��ǥ] �������� �̵��մϴ�.
	while (!(getPlayer().OwnPiece->getPositionIndex() == 27)) //27�� ������ ��ǥ ������ Index
		getPlayer().OwnPiece->MovePiece();
	cout << ">> ������ ��ǥ<<" << endl;
	cout << "���������� ��ǥ�� �մϴ�! [������ ��ǥ] �������� �̵��մϴ�." << endl;
	text->setString(L"���������� ��ǥ�� �մϴ�! [������ ��ǥ] �������� �̵��մϴ�.");
	return "money";
}
std::string GoldenKey::keyFunction12(sf::Text *text, Board board[])
{
	//�ð��� �ǵ��� �� �ִٸ� : [Ÿ�� �ӽ�] �������� �̵��մϴ�.
	while (!(getPlayer().OwnPiece->getPositionIndex() == 30)) //30�� Ÿ�� �ӽ� ������ Index
		getPlayer().OwnPiece->MovePiece();
	cout << ">> Ÿ�� �ӽ�<<" << endl;
	cout << "�ð��� �ǵ��� �� �������? [Ÿ�� �ӽ�] �������� �̵��մϴ�." << endl;
	text->setString(L"�ð��� �ǵ��� �� �������? [Ÿ�� �ӽ�] �������� �̵��մϴ�.");
	return "time";
}
std::string GoldenKey::keyFunction13(sf::Text *text, Board board[])
{
	//���� : ������ ȹ���� ������ 1 �����մϴ�.
	getPlayer().setSpecialTurn(-1);
	cout << ">> ���� <<" << endl;
	cout << "������ ����ϴ�. ������ �ʰڴ°ɿ�? ���� ������ ������ 1�� �� ȹ���մϴ�." << endl;
	text->setString(L"������ ����ϴ�. ������ �ʰڴ°ɿ�? ���� ������ ������ 1�� �� ȹ���մϴ�.");
	return "loseAdd";
}
