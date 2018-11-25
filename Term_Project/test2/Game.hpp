#ifndef GAME_HPP
#define GAME_HPP

/*
Game.hpp�� ��� ������Ͽ� ���� ��� ������ ��Ƴ��ҽ��ϴ�.

�ּ����� Game.hpp�� ����ϴ� ������ϵ��� ����߽��ϴ�.
*/

// �� Dice.hpp
#define MIN_DICE_NUMBER 1
#define MAX_DICE_NUMBER 6

// �� DiceRollButton.hpp
#define FILE_DiceRollButton "images/DiceButton.png" 
#define Dice_Button_POSITION_X 550 // ��ư ��ġ (X)
#define Dice_Button_POSITION_Y 620 // ��ư ��ġ (Y)
#define Dice_Button_LENGTH_X 233 // �ֻ��� ������ ��ư ������ ���� ����
#define Dice_Button_LENGTH_Y 144 // �ֻ��� ������ ��ư ������ ���� ����

// �� DicePanel.hpp
#define FILE_DicePanel "images/DicePanel.png" // ���� ����
#define Dice_Panel_POSITION_X 900
#define Dice_Panel_POSITION_Y 200

#define Dice1_POSITION_X 401 
#define Dice1_POSITION_Y 420
#define Dice2_POSITION_X 460
#define Dice2_POSITION_Y 420

#define File_DiceNumber1 "images/DiceNumber/Number1.png"
#define File_DiceNumber2 "images/DiceNumber/Number2.png"
#define File_DiceNumber3 "images/DiceNumber/Number3.png"
#define File_DiceNumber4 "images/DiceNumber/Number4.png"
#define File_DiceNumber5 "images/DiceNumber/Number5.png"
#define File_DiceNumber6 "images/DiceNumber/Number6.png"

// �� Piece.hpp
#define FILE_PIECE_IMAGE "images/Piece.png"

// �� GameBoard.hpp
#define FILE_gameBoard "images/GameBoard.png"

// �� Menu.hpp
#define WINDOW_SIZE_X 1400
#define WINDOW_SIZE_Y 900
#define GAME_TITLE "Blue Marble!"

// �� MapPoint.hpp
#define HEIGHT_NUMBER 11 // ���� ���� ������ ���̸� ��Ÿ��.
#define WIDTH_NUMBER 11
#define FOOTHOLD_NUMBER ((HEIGHT_NUMBER+WIDTH_NUMBER)*2 - 4) // ��ü ������ ����, ������ (���� + ����) * 2 - 4. ���� 40����, Index�� 39�� ������ 0���� ���ƿ��� ����.
#define nd 76 // �Ϲ� ���� �� �ȼ� ��ȭ��, NORMAL_FOOTHOLD_DIFF_PIXEL
#define sd 108 // Ư�� ���� �� �ȼ� ��ȭ��, SPECIAL_FOOTHOLD_DIFF_PIXEL
//#define PIECE_PIXEL 150 // ĳ������ ����, ���� �ȼ� (������ ����)
#define _X 792 // ĳ���Ͱ� �����ϴ� ���� ��ǥ
#define _Y 792

// �� Menu.hpp
#define FILE_mainFont "fonts/godoMaum.ttf" // �޴� ��Ʈ ���
#define MAX_NUMBER_OF_MENU_ITEMS 3 // �޴� ���� ����
#define MENU_TEXT_POSITION_X 550 // �޴� ��ǥ
#define MENU_TEXT_POSITION_Y (WINDOW_SIZE_Y) / (MAX_NUMBER_OF_MENU_ITEMS + 1)
#define DEFAULT_ITEM_COLOR sf::Color::White // �޴� ���� 
#define SELECTED_ITEM_COLOR sf::Color::Cyan // �޴� ����
#define MENU_FONTSIZE 120 // �޴� ��Ʈ ũ��

// �� Sound.hpp
#define FILE_pieceMoveSound "sounds/PieceMoveSound.ogg"
#define FILE_buttonClickedSound "sounds/ButtonClicked.ogg"
#define FILE_backGroundMusic "sounds/BGM.ogg"
#define VOLUME_pieceMoveSound 100.f
#define VOLUME_buttonClickedSound 40.f
#define VOLUME_backGroundMusic 40.f

// �� Text.hpp
#define FILE_menuFont "fonts/godoMaum.ttf" // �ϴ� mainFont�� ���� ����
#define TEXT_showTurn_X 900
#define TEXT_showTurn_Y 500
#define TEXT_showTurn_CharSize 40
#define TEXT_showPlayerInformation_X 1000
#define TEXT_showPlayerInformation_Y 0
#define TEXT_showPlayerInformation_Size 35

// �� RULE
#define RULE_playerPlayingNumber 4 // ���ӿ� �����ϴ� �÷��̾� ��. 1~4
#define RULE_WinScore 120

#endif