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
// TODO: Refactor all code

void lobby();
void singlePlayerGame();
int main() {
	// initalizing
	Window::setCursorState(false); // set terminal cursor to be invisible
    screenWidth = 70; screenHeight = 45;

    system("mode con cols=70 lines=45");
    
	
	// lobby screen
	lobby();
}

void lobby() {
	Window::clearScreen();
    // TETRIS LOGO
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

    // Selecting Modes
    const int padding = 12;
    Window::gotoXY(screenWidth / 2 - padding, screenHeight / 2);
    cout << "> SINGLE PLAYER";
    Window::gotoXY(screenWidth / 2 - padding, screenHeight / 2 + 1);
    cout << "MULTI PLAYER(TCP/IP)";

    bool isSinglePlayer = true;

    // Single/MultiPlayer Selecting Code
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
        // SinglePlayer Game Logic
        singlePlayerGame();
    } else {
        cout << "Sorry, MultiPlayer Game is not supported in this version.";
    }
}

void singlePlayerGame() {
    // Initalizing Board
    Board Visual; // Visible to User.
    Board Real; // Real Board(except current Tetromino)

    Bag tetrominoBag;
    // Render Tetris Border
    Window::renderTetrisBorder();
    Sleep(1000);

    single_isGameOver = false;
    while (!single_isGameOver) {
        if (nowTetromino.type == -1) { // if there's no coming down tetromino
            nowTetromino.type = tetrominoBag.getTetromino(); // get Tetromino from 7-bag system
            
            // TODO: find the spot where we can start at
            
        }
        Window::updateBoard(Visual, Real); // update the board, this will update the block that differs from previous board

    }
}

