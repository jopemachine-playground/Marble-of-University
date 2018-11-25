#ifndef GOLDENKEY_HPP
#define GOLDENKEY_HPP

#include "Player.hpp"
#include "Board.hpp"
#include "Turn.hpp"

class GoldenKey {
private:
	Player & keyPlayer; //Ȳ�ݿ���� ��ȣ�ۿ��ϰ� �� Player ���۷���
	int key; //Ȳ�ݿ��踦 �����ϴ� key
	int random; //�����ϰ� key ���� �����ϱ� ���� ��
public:
	GoldenKey(Player &player) : keyPlayer(player) {};
	int getKey() { return key; }
	void setKey(); //key ���� �����ϰ� ����
	std::string chooseKey(sf::Text *text,Board board[]); //key���� ������ �Լ��� �����ؼ� ����
	int getRandom() { return random; }
	void setRandom(); //random ���� ����
	Player& getPlayer() { return keyPlayer; }
	void setPlayer(Player& aPlayer) { keyPlayer = aPlayer; }


	//Ȳ�ݿ����� ��ȣ�ۿ� �Լ���
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