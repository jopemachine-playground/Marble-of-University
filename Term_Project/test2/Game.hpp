#ifndef GAME_HPP
#define GAME_HPP

/*
Game.hpp는 모든 헤더파일에 들어가는 상수 값들을 모아놓았습니다.

주석으로 Game.hpp를 사용하는 헤더파일들을 명시했습니다.
*/

// ※ Dice.hpp
#define MIN_DICE_NUMBER 1
#define MAX_DICE_NUMBER 6

// ※ DiceRollButton.hpp
#define FILE_DiceRollButton "images/DiceButton.png" 
#define Dice_Button_POSITION_X 550 // 버튼 위치 (X)
#define Dice_Button_POSITION_Y 620 // 버튼 위치 (Y)
#define Dice_Button_LENGTH_X 233 // 주사위 굴리기 버튼 파일의 가로 길이
#define Dice_Button_LENGTH_Y 144 // 주사위 굴리기 버튼 파일의 세로 길이

// ※ DicePanel.hpp
#define FILE_DicePanel "images/DicePanel.png" // 파일 없음
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

// ※ Piece.hpp
#define FILE_PIECE_IMAGE "images/Piece.png"

// ※ GameBoard.hpp
#define FILE_gameBoard "images/GameBoard.png"

// ※ Menu.hpp
#define WINDOW_SIZE_X 1400
#define WINDOW_SIZE_Y 900
#define GAME_TITLE "Blue Marble!"

// ※ MapPoint.hpp
#define HEIGHT_NUMBER 11 // 발판 가로 세로의 길이를 나타냄.
#define WIDTH_NUMBER 11
#define FOOTHOLD_NUMBER ((HEIGHT_NUMBER+WIDTH_NUMBER)*2 - 4) // 전체 발판의 길이, 갯수는 (가로 + 세로) * 2 - 4. 현재 40개고, Index가 39를 넘으면 0으로 돌아오는 구조.
#define nd 76 // 일반 발판 당 픽셀 변화량, NORMAL_FOOTHOLD_DIFF_PIXEL
#define sd 108 // 특수 발판 당 픽셀 변화량, SPECIAL_FOOTHOLD_DIFF_PIXEL
//#define PIECE_PIXEL 150 // 캐릭터의 가로, 세로 픽셀 (쓰이지 않음)
#define _X 792 // 캐릭터가 시작하는 점의 좌표
#define _Y 792

// ※ Menu.hpp
#define FILE_mainFont "fonts/godoMaum.ttf" // 메뉴 폰트 경로
#define MAX_NUMBER_OF_MENU_ITEMS 3 // 메뉴 선택 갯수
#define MENU_TEXT_POSITION_X 550 // 메뉴 좌표
#define MENU_TEXT_POSITION_Y (WINDOW_SIZE_Y) / (MAX_NUMBER_OF_MENU_ITEMS + 1)
#define DEFAULT_ITEM_COLOR sf::Color::White // 메뉴 색깔 
#define SELECTED_ITEM_COLOR sf::Color::Cyan // 메뉴 색깔
#define MENU_FONTSIZE 120 // 메뉴 폰트 크기

// ※ Sound.hpp
#define FILE_pieceMoveSound "sounds/PieceMoveSound.ogg"
#define FILE_buttonClickedSound "sounds/ButtonClicked.ogg"
#define FILE_backGroundMusic "sounds/BGM.ogg"
#define VOLUME_pieceMoveSound 100.f
#define VOLUME_buttonClickedSound 40.f
#define VOLUME_backGroundMusic 40.f

// ※ Text.hpp
#define FILE_menuFont "fonts/godoMaum.ttf" // 일단 mainFont와 같은 파일
#define TEXT_showTurn_X 900
#define TEXT_showTurn_Y 500
#define TEXT_showTurn_CharSize 40
#define TEXT_showPlayerInformation_X 1000
#define TEXT_showPlayerInformation_Y 0
#define TEXT_showPlayerInformation_Size 35

// ※ RULE
#define RULE_playerPlayingNumber 4 // 게임에 참가하는 플레이어 수. 1~4
#define RULE_WinScore 120

#endif