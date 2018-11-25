#ifndef GOLDENKEY_HPP
#define GOLDENKEY_HPP

#include "Player.hpp"
#include "Board.hpp"
#include "Turn.hpp"

class GoldenKey {
private:
	Player & keyPlayer; //황금열쇠와 상호작용하게 될 Player 레퍼런스
	int key; //황금열쇠를 결정하는 key
	int random; //랜덤하게 key 값을 생성하기 위한 값
public:
	GoldenKey(Player &player) : keyPlayer(player) {};
	int getKey() { return key; }
	void setKey(); //key 값을 랜덤하게 생성
	std::string chooseKey(sf::Text *text,Board board[]); //key값을 가지고 함수를 선택해서 실행
	int getRandom() { return random; }
	void setRandom(); //random 값을 결정
	Player& getPlayer() { return keyPlayer; }
	void setPlayer(Player& aPlayer) { keyPlayer = aPlayer; }


	//황금열쇠의 상호작용 함수들
	std::string keyFunction0(sf::Text *text, Board board[]);
	std::string keyFunction1(sf::Text *text, Board board[]);
	std::string keyFunction2(sf::Text *text, Board board[]);
	std::string keyFunction3(sf::Text *text, Board board[]);
	std::string keyFunction4(sf::Text *text, Board board[]);
	std::string keyFunction5(sf::Text *text, Board board[]);
	std::string keyFunction6(sf::Text *text, Board board[]);
	std::string keyFunction7(sf::Text *text, Board board[]);
	std::string keyFunction8(sf::Text *text, Board board[]);
	std::string keyFunction9(sf::Text *text, Board board[]);
	std::string keyFunction10(sf::Text *text, Board board[]);
	std::string keyFunction11(sf::Text *text, Board board[]);
	std::string keyFunction12(sf::Text *text, Board board[]);
	std::string keyFunction13(sf::Text *text, Board board[]);
};
#endif