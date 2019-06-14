# Marble-of-University
2018 CNU Object Oriented Programming Term Project

# Development Environment
C++, SFML 2.5.1을 사용해 구현했고, Windows10의 Visual Studio 2017에서 작업했다.

참여인원:
201302435 유영근, 201300995 이상건, 201502094 이재호, 201502085 이규봉

# Game Manual

<게임의 진행>

한 턴에 한 번씩 주사위를 2개 굴려 눈의 합만큼 말을 이동 시키며 게임을 진행

<승리조건>

플레이어 중 한명이 기준 학점을 다 채우면 승리.

<학점을 올리는 규칙>

발판을 밟으면 해당 학생의 학점이 올라감.

1. 일반 발판은 1~3학점을 가짐.

2. 보드의 각 모서리에 존재하는 특수발판으로 시작점, 무인도, 타임머신, 공모전 발판이 있음. 

=> 시작 발판  : 한 바퀴 돌면 일정 포인트를 받음.  

=> 무인도 : 해당 플레이어는 3턴 동안 주사위를 굴릴 수 없음

=> 타임 머신 : 원하는 발판으로 이동할 수 있음.

=> 공모전 참가발판 : 나중에 공모전 발표발판을 밟은 사람이 받을 상금 액수를 추가.   
(공모전 발표발판은 모서리에 있지 않지만, 편의성을 위해 모서리발판 종류에 추가.)


# Screen shot

![Alt Text](https://github.com/jopemachine/Marble-of-University/blob/master/Term_Project/screenshot.gif)



# Part of Report

<img src="./Marble UML.png">

### **게임 내 구현된 각 클래스들에 대해**

```
• WinMain (Entry Point) : 프로그램의 시작점입니다.

• Player : 하나의 Piece (말) 객체를 가지며 점수를 얻어 관리하는 플레이어 객체를 만듭니다.

• DrawableObject : 저희는 게임에 그림 파일로 그려질 객체들의 부모 클래스로 DrawableObject 클래스를 만들었습니다. 
DrawableObject 클래스는 Piece, Board, Panel, Botton 등 다양한 자식 클래스들을 가지고 있습니다.

• Piece : 플레이어가 게임을 진행하며 움직일 수 있는 말에 해당합니다. 

• GameBoard : 게임 판에 해당합니다. DrawableObject를 상속합니다. 

• Button : 버튼을 눌러 플레이어와 상호작용할 수 있게 합니다. DrawableObject를 상속합니다. 
Button을 상속하는 자식클래스는 isInButton() 메서드를 구현해야 하며, main함수에서 마우스 클릭 이벤트가 발생하고, 
isInButton() 이 True를 리턴할 때 버튼이 눌러진 것으로 간주합니다. 

• DiceRollButton : Button을 상속받으며, 게임 창에 주사위 굴리기 버튼을 그리고 관리합니다.

• Panel : 화면에 창을 띄웁니다. DrawableObject를 상속합니다. 

• DicePanel : 주사위가 굴러가는 패널입니다. Panel을 상속합니다. Sprite와 Texture를 넣어 패널 자체의 이미지도 넣으려 했으나,
좋은 이미지 파일이 없어 넣지 않았습니다.

• Sound : 효과음, 배경음 등을 관리합니다. 모든 사운드를 하나의 객체로 관리하도록 했습니다.

• Menu : main에서 키보드 입력 이벤트가 발생하고, 이벤트가 ESC키에 해당할 때 메뉴를 호출합니다. 
Menu.cpp에 정의된 moveUp(), moveDown()으로 메뉴 항목을 선택하고 엔터키로 결정할 수 있습니다. 
게임 도중 Menu를 호출하여 다시 game으로 돌아갈 수 있으며, StartMenu 화면으로 돌아갈 수 있고 Exit로 게임을 종료할 수 있음.

• StartMenu : Menu를 상속하여 moveUp, moveDown등의 메서드를 그대로 이용합니다. 
StartMenu는 게임을 처음 실행했을 때 나오는 메뉴 창의 클래스입니다.

• Dice : 주사위에서 사용할 난수를 생성하고 관리하는 클래스로, 난수는 std::uniform_int_distribution<>를 사용해 생성합니다.

• Turn : 게임의 턴 수를 관리합니다. 주사위를 한 번 굴릴 때 마다 턴 수가 1씩 증가합니다.

• Text : DrawableObject 와는 별개로 게임 창에 들어가는 텍스트들을 관리합니다.

• GoldenKey : srand()를 이용해 랜덤으로 keyFuction0~ keyFunction13을 호출합니다. 각 메서드는 황금열쇠 이벤트에 대응합니다.

• LoadAndInit : 발판을 초기화 합니다. 초기화할 땐, BoardData.txt의 정보를 가져와 게임에 이용하고, 
발판의 맵 좌표는 MapPoint.hpp에서 가져옵니다. 

• PlayerIcon : 플레이어들의 아이콘 클래스입니다. 
``` 

헤더 파일 

(cpp 파일의 선언부에 해당하는 헤더파일들은 제외했습니다.)

```
• pch.h : 미리 정의된 헤더파일. 

• Game.hpp : 모든 헤더파일에 들어가는 상수 값들을 명시하고, 주석으로 헤더파일들 이름을 명시함으로써, 
상수 값들을 용이하게 수정할 수 있도록 했습니다. 그 외에 게임 플레이에 이용하는 파일의 이름, 경로 역시 
모두 Game.hpp에 명시했습니다. 

• MapPoint.hpp : Piece와 main에서 사용하는 발판의 좌표값들을 명시한 헤더파일입니다. 
좌표값들은 sf::Vector2f 객체들의 배열로 이뤄져 있습니다. 

• Board.hpp : 각 보드들의 정보를 담는 클래스입니다. 
ASNI와 유니코드 사이의 변환을 위해 USES_CONVERSION 매크로를 사용합니다. 
```

#### *※* *SFML* *클래스에 대한 간략한 설명*

( ※공식 홈페이지 주소 : https://www.sfml-dev.org/index.php)

• sf - sfml의 네임스페이스입니다. 

• sf::Texture – 그림 파일을 읽어와 저장하고 관리할 Texture 객체를 만듭니다. 

• sf::Sprite – 텍스쳐를 등록하고 window 창에 등록할 수 있게 합니다.

• sf::RenderWindow – 그림을 그릴 Window 창을 띄우고, 관리합니다.

• sf::Vector2f – 게임 창의 좌표를 나타냅니다. 

• sf::Font – Text객체에 폰트에 관련된 속성들을 주거나, 변경할 수 있습니다. 

• sf::Text – RenderWindow 객체에 텍스트를 그릴 수 있게 하는 객체를 만들 수 있게 합니다. 
