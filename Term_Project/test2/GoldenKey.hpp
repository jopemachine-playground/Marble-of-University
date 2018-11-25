#ifndef GOLDENKEY_HPP
#define GOLDENKEY_HPP

#include "Player.hpp"
#include "Board.hpp"
#include "Turn.hpp"

class GoldenKey {
private:
	Player &keyPlayer; //Ȳ�ݿ���� ��ȣ�ۿ��ϰ� �� Player ���۷���
	int key; //Ȳ�ݿ��踦 �����ϴ� key
	int random; //�����ϰ� key ���� �����ϱ� ���� ��
public:
	GoldenKey(Player &player) : keyPlayer(player) {};
	int getKey() { return key; }
	void setKey(); //key ���� �����ϰ� ����
	void chooseKey(); //key���� ������ �Լ��� �����ؼ� ����
	int getRandom() { return random; }
	void setRandom(); //random ���� ����
	Player& getPlayer() { return keyPlayer; }
	void setPlayer(Player& aPlayer) { keyPlayer = aPlayer; }
	

	//Ȳ�ݿ����� ��ȣ�ۿ� �Լ���
	void keyFunction0();
	void keyFunction1();
	void keyFunction2();
	void keyFunction3();
	void keyFunction4();
	void keyFunction5();
	void keyFunction6();
	void keyFunction7();
	void keyFunction8();
	void keyFunction9();
	void keyFunction10();
	void keyFunction11();
	void keyFunction12();
	void keyFunction13();
};
#endif