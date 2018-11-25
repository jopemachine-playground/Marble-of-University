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
	//random ���� ������ key�� ����
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
	//���� : ������ 3�� ȹ���մϴ�.
	getPlayer().setScore(getPlayer().getScore() + 3);
	cout << ">> �� �� !! <<" << endl;
	cout << "���θ� ������ �ϼ̱���! �������� ȹ���ϼ̽��ϴ�. (+3 ��)"  << endl;
}
void GoldenKey::keyFunction1()
{
	//��� ���� : ���� �� �ֻ��� �����⸦ ����, ������ 4�� �ø��ϴ�.
	getPlayer().setScore(getPlayer().getScore() + 4);
	getPlayer().setSleep(getPlayer().getSleep() + 1);
	cout << ">> ��� ����<<" << endl;
	cout << "�ʹ� �����Ͻ����� ������. ��� ������ �ݵ����� �� �� ���ϴ�. (+4 ��)" << endl;
}
void GoldenKey::keyFunction2()
{
	//�븮 �⼮ : 3�ϵ��� ������ 1���� �߰��� �ö󰩴ϴ�.
	for(int i = 1; i < 3; i++ ) getPlayer().setSpecialTurn(3);
	cout << ">>�븮 �⼮<<" << endl;
	cout << "���������� �⼮�� ��Ź�մϴ�. 3�ϵ��� ������ 1���� �߰��� �ö󰩴ϴ�." << endl;
}
void GoldenKey::keyFunction3()
{
	//�ǿ常�� : ������ 3ĭ �����Դϴ�.
	for (int i = 0; i < 3; i++)
		getPlayer().OwnPiece->MovePiece();
	cout << ">> �Ǒ򸸸� <<" << endl;
	cout << "��ġ�� �ǿ����� 3ĭ ������ �����մϴ�." << endl;
}
void GoldenKey::keyFunction4()
{
	//���� : [����] �������� �̵��մϴ�.
	while (!(getPlayer().OwnPiece->getPositionIndex() == 0))
		getPlayer().OwnPiece->MovePiece();
	cout << ">> ���� <<" << endl;
	cout << "�� �бⰡ ���۵Ǿ����ϴ�! [����] �������� �̵��մϴ�." << endl;
}
void GoldenKey::keyFunction5()
{

	//���� 800�� ��� : ���� 4�� �߰��մϴ�.
	getPlayer().setScore(getPlayer().getScore() + 4);
	cout << ">> ���� 800�� ��� <<" << endl;
	cout << "���� 800���� ȹ���ϼ̱���! Global English �����Դϴ�! (+4 ��)" <<  endl;
}
void GoldenKey::keyFunction6()
{
	//���� ȹ�� : ���� ������ ������ 1���� �߰��� ȹ���մϴ�.
	getPlayer().setSpecialTurn(1);
	cout << ">> ���� ȹ�� <<" << endl;
	cout << "�����ϰ� �� �� �ִ� ������ ȹ���߽��ϴ�. ���� ������ ������ 1���� �߰� ȹ���մϴ�." << endl;
}
void GoldenKey::keyFunction7()
{
	//���� ������ : ������ 2�� ���Դϴ�.
	getPlayer().setScore(getPlayer().getScore() - 2);
	cout << ">> ���� ������ !! <<" << endl;
	cout << "����.. ���� ���� ������ �����ƽ��ϴ�. ������ �ҽ��ϴ�. (-2 ��)"<< endl;
}
void GoldenKey::keyFunction8()
{
	//�Կ������� : [����] �������� �̵��մϴ�.
	while (!(getPlayer().OwnPiece->getPositionIndex() == 10)) //10�� ���� ������ Index
		getPlayer().OwnPiece->MovePiece();
	cout << ">>�� �� �� �� ��<<" << endl;
	cout << "������ �״븦 �θ��ϴ�! �ϴ� �����ϼž߰ڱ���. [����] �������� �̵��մϴ�." << endl;
}
void GoldenKey::keyFunction9()
{
	//������ YXXTUBE ��û : 3�ϵ��� ������ 1���� �� ȹ�� �մϴ�.
	for(int i = 0; i < 3; i++ ) getPlayer().setSpecialTurn(-3);
	cout << ">> ������ YXXTUBE ��û <<" << endl;
	cout << "����ģ ������ ��û�� �ϻ��Ȱ�� ������ �� �� �ֽ��ϴ�. 3�� ���� 1������ �� ȹ���մϴ�." << endl;
}
void GoldenKey::keyFunction10()
{
	//������ ���� : [������ ����] �������� �̵��մϴ�.
	while (!(getPlayer().OwnPiece->getPositionIndex() == 20)) //20�� ������ ���� ������ Index
		getPlayer().OwnPiece->MovePiece();
	cout << ">> ������ ����<<" << endl;
	cout << "�������� �����մϴ�! [������ ����] �������� �̵��մϴ�." << endl;
}
void GoldenKey::keyFunction11()
{
	//������ ��ǥ : [������ ��ǥ] �������� �̵��մϴ�.
	while (!(getPlayer().OwnPiece->getPositionIndex() == 27)) //27�� ������ ��ǥ ������ Index
		getPlayer().OwnPiece->MovePiece();
	cout << ">> ������ ��ǥ<<" << endl;
	cout << "���������� ��ǥ�� �մϴ�! [������ ��ǥ] �������� �̵��մϴ�." << endl;
}
void GoldenKey::keyFunction12()
{
	//�ð��� �ǵ��� �� �ִٸ� : [Ÿ�� �ӽ�] �������� �̵��մϴ�.
	while (!(getPlayer().OwnPiece->getPositionIndex() == 30)) //30�� Ÿ�� �ӽ� ������ Index
		getPlayer().OwnPiece->MovePiece();
	cout << ">> Ÿ�� �ӽ�<<" << endl;
	cout << "�ð��� �ǵ��� �� �������? [Ÿ�� �ӽ�] �������� �̵��մϴ�." << endl;
}
void GoldenKey::keyFunction13()
{
	//���� : ������ ȹ���� ������ 1 �����մϴ�.
	getPlayer().setSpecialTurn(-1);
	cout << ">> ���� <<" << endl;
	cout << "������ ����ϴ�. ������ �ʰڴ°ɿ�? ���� ������ ������ 1�� �� ȹ���մϴ�." << endl;
}
