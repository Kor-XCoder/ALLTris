#include <iostream>
#include <windows.h>
#include "Window.h"
#include "Input.h"
#include "Tetromino.h"
#include "Board.h"
#include "Bag.h"
#include <thread>
#include <cassert>
using namespace std;


const int Black = 0;
const int Red = 1;
const int Green = 2;
const int Yellow = 3;
const int Blue = 4;
const int Magenta = 5;
const int Cyan = 6;
const int White = 7;
const int Orange = 8;
int screenWidth, screenHeight;

bool single_isGameOver = false;
Tetromino nowTetromino(-1, { -1, -1 });

// TODO: 틱 단위 작업 처리
// TODO: Wall-Kick 처리
// TODO: 테트로미노 보드 2차원 배열 구현
//       - 바뀐 부분만 수정할 수 있게 구현

// TODO: Refactor all code

void lobby();
void singlePlayerGame();
int main() {
	// ------초기화------
	Window::setCursorState(false); // 터미널 커서가 보이지 않게 설정
    screenWidth = 70; screenHeight = 45;

    system("mode con cols=70 lines=45");
    
	
	// ------로비 스크린------
	lobby();
}

void lobby() {
	Window::clearScreen();
    {
        int padding = 17;
        // 1st Line 
        Window::setColor(Red);
        Window::gotoXY(screenWidth / 2 - padding, 1);
        cout << "      ";
        Window::setColor(Yellow);
        cout << "      ";
        Window::setColor(Green);
        cout << "      ";
        Window::setColor(Cyan);
        cout << "      ";
        Window::setColor(Blue);
        cout << "  ";
        Window::setColor(Magenta);
        cout << "      ";

        // 2nd Line 
        Window::setColor(Red);
        Window::gotoXY(screenWidth / 2 - padding + 2, 2);
        cout << "  ";

        Window::setColor(Yellow);
        Window::gotoXY(screenWidth / 2 - padding + 6, 2);
        cout << "  ";

        Window::setColor(Green);
        Window::gotoXY(screenWidth / 2 - padding + 14, 2);
        cout << "  ";

        Window::setColor(Cyan);
        Window::gotoXY(screenWidth / 2 - padding + 18, 2);
        cout << "  ";
        Window::gotoXY(screenWidth / 2 - padding + 22, 2);
        cout << "  ";

        Window::setColor(Blue);
        Window::gotoXY(screenWidth / 2 - padding + 24, 2);
        cout << "  ";

        Window::setColor(Magenta);
        Window::gotoXY(screenWidth / 2 - padding + 26, 2);
        cout << "  ";

        // 3rd Line 
        Window::setColor(Red);
        Window::gotoXY(screenWidth / 2 - padding + 2, 3);
        cout << "  ";

        Window::setColor(Yellow);
        Window::gotoXY(screenWidth / 2 - padding + 6, 3);
        cout << "      ";

        Window::setColor(Green);
        Window::gotoXY(screenWidth / 2 - padding + 14, 3);
        cout << "  ";

        Window::setColor(Cyan);
        Window::gotoXY(screenWidth / 2 - padding + 18, 3);
        cout << "      ";

        Window::setColor(Blue);
        cout << "  ";

        Window::setColor(Magenta);
        cout << "      ";

        // 4th Line
        Window::setColor(Red);
        Window::gotoXY(screenWidth / 2 - padding + 2, 4);
        cout << "  ";

        Window::setColor(Yellow);
        Window::gotoXY(screenWidth / 2 - padding + 6, 4);
        cout << "  ";

        Window::setColor(Green);
        Window::gotoXY(screenWidth / 2 - padding + 14, 4);
        cout << "  ";

        Window::setColor(Cyan);
        Window::gotoXY(screenWidth / 2 - padding + 18, 4);
        cout << "    ";

        Window::setColor(Blue);
        Window::gotoXY(screenWidth / 2 - padding + 24, 4);
        cout << "  ";

        Window::setColor(Magenta);
        Window::gotoXY(screenWidth / 2 - padding + 30, 4);
        cout << "  ";

        // 5th Line
        Window::setColor(Red);
        Window::gotoXY(screenWidth / 2 - padding + 2, 5);
        cout << "  ";

        Window::setColor(Yellow);
        Window::gotoXY(screenWidth / 2 - padding + 6, 5);
        cout << "      ";

        Window::setColor(Green);
        Window::gotoXY(screenWidth / 2 - padding + 14, 5);
        cout << "  ";

        Window::setColor(Cyan);
        Window::gotoXY(screenWidth / 2 - padding + 18, 5);
        cout << "  ";
        Window::gotoXY(screenWidth / 2 - padding + 22, 5);
        cout << "  ";

        Window::setColor(Blue);
        Window::gotoXY(screenWidth / 2 - padding + 24, 5);
        cout << "  ";

        Window::setColor(Magenta);
        Window::gotoXY(screenWidth / 2 - padding + 26, 5);
        cout << "      ";
    }
    Window::setColor(Black);

    // 모드 선택
    const int padding = 12;
    Window::gotoXY(screenWidth / 2 - padding, screenHeight / 2);
    cout << "> SINGLE PLAYER";
    Window::gotoXY(screenWidth / 2 - padding, screenHeight / 2 + 1);
    cout << "MULTI PLAYER(TCP/IP)";

    bool isSinglePlayer = true;

    // 싱글/멀티 플레이어 선택 코드
    while (!Input::isKeyDown(Input::ENTER))
    {
        if (Input::isKeyDown(Input::upArrow) || Input::isKeyDown(Input::downArrow))
        {
            isSinglePlayer = !isSinglePlayer;
            Window::gotoXY(screenWidth / 2 - padding, screenHeight / 2);
            cout << "                         ";
            Window::gotoXY(screenWidth / 2 - padding, screenHeight / 2 + 1);
            cout << "                         ";
            if (isSinglePlayer)
            {
                Window::gotoXY(screenWidth / 2 - padding, screenHeight / 2);
                cout << "> SINGLE PLAYER";
                Window::gotoXY(screenWidth / 2 - padding, screenHeight / 2 + 1);
                cout << "MULTI PLAYER(TCP/IP)";
            }
            else
            {
                Window::gotoXY(screenWidth / 2 - padding, screenHeight / 2);
                cout << "SINGLE PLAYER";
                Window::gotoXY(screenWidth / 2 - padding, screenHeight / 2 + 1);
                cout << "> MULTI PLAYER(TCP/IP)";
            }
            Sleep(100);
        }
    }
    
    Window::clearScreen();
    if (isSinglePlayer)
    {
        // 싱글 플레이어 게임 로직
        singlePlayerGame();
    } else {
        cout << "Sorry, MultiPlayer Game is not supported in this version.";
    }
}

void singlePlayerGame() {
    // 보드 초기화
    Board Visual; // 사용자에게 보여지는 보드
    Board Real; // 현재까지 쌓인 테트로미노 저장

    Bag tetrominoBag;
    // 테트리스 게임 틀 생성
    Window::renderTetrisBorder();
    Sleep(1000);

    single_isGameOver = false;
    while (!single_isGameOver) {
        if (nowTetromino.type == -1) { // 내려오는 테트로미노가 없다면
            nowTetromino.type = tetrominoBag.getTetromino();
            
            // 어디부터 시작 가능한지 검사
            
        }
        Window::updateBoard(Visual, Real);
    }
}

