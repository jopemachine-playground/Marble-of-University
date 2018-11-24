#ifndef GOLDENKEY_HPP
#define GOLDENKEY_HPP

#include "Player.hpp"
#include "Board.hpp"
#include "Turn.hpp"

class GoldenKey {
private:
	Player  keyPlayer; //황금열쇠와 상호작용하게 될 Player 포인터
	int key; //황금열쇠를 결정하는 key
	int random; //랜덤하게 key 값을 생성하기 위한 값
	Board frontBoard;//황금열쇠 발판의 앞 발판
	Turn* turnForKey;
public:
	GoldenKey(Player player);
	int getKey() { return key; }
	void setKey(); //key 값을 랜덤하게 생성
	void chooseKey(); //key값을 가지고 함수를 선택해서 실행
	int getRandom() { return random; }
	void setRandom(); //random 값을 결정
	Player getPlayer() { return keyPlayer; }
	void setPlayer(Player aPlayer) { keyPlayer = aPlayer; }
	Board getFrontBoard() { return frontBoard; }
	void setFrontBoard(Board aBoard) { frontBoard = aBoard; }
	Turn* getTurnForKey() { return turnForKey; }
	void setTurnForKey(Turn* aTurn) { turnForKey = aTurn; }

	//황금열쇠의 상호작용 함수들
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