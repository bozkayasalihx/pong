#include <curses.h>
#include <iostream>
#include <ncurses.h>
#include <cstdlib>

using namespace std;

bool gameOver;
const int width = 40;
const int height = 20;
int x, y,  aiY, middleX, middleY;
int score;
enum Direction { STOP = 0, LEFT, RIGHT, UPLEFT, DOWNLEFT, UPRIGHT, DOWNRIGHT};
Direction ballDir;

void Setup()
{
    gameOver = false;
    ballDir = STOP;
    x = 1;
    y = 1;
    aiY = height / 2; 
    score = 0;
    ballDir = DOWNLEFT; 
    middleX = width /2; 
    middleY = height /2;

}


void Draw()
{
    clear(); 
    for (int i = 0; i < width+2; i++)
        printw("#");
    printw("\n");

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                printw("#"); 
            else if (j == x && i == y)
                printw("|");
            else if (j == middleX)
                printw("||");
            else if (j == width - 1 && i == aiY)
                printw("|"); 
            else
                printw(" ");

            if (j == width - 1)
                printw("#");
        }
        printw("\n");
    }

    for(int i =0;i<width+2;++i)
    {
        printw("#");
    }
    printw("\n");
    printw("Score: %d", score);
    refresh();
}

void logic()
{
}

void Input() 
{
    int ch = getch(); 
    switch(ch)
    {
        case 'w': 
        y--; 
        break; 
        case 's': 
        y++; 
        break; 
        case 'q': 
        gameOver = true;
        break;
    }

}



int main()
{
    initscr(); // Initialize the window
    nodelay(stdscr, TRUE); // Doesn't wait for user input in getch()
    keypad(stdscr, TRUE); // Initialize keypad
    noecho(); // Doesn't show the input from user
    curs_set(0); // Makes cursor invisible

    Setup();
    while (!gameOver)
    {
        Draw();
        Input();
        // Logic();
        napms(50); // sleep for 50 milliseconds
    }

    endwin(); // End the window
    return 0;
}

    

