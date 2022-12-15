#include <iostream>
#include <string>
#include <conio.h>
#include <cstdlib>
#include <Windows.h>

using namespace std;

// global shit
const int mapLen = 21, mapBreth = 29;
int i = 0, j = 0, score = 0, level = 1;
string array[mapLen][mapBreth];
// for player
char x = mapLen - 2, y = mapBreth - 13;
// for enemy
char e = mapLen - 2, f = mapBreth - 17, d, n;

// function prototypes
void menu();
void instruction();
void pauseMenu();
void map();
void movement(char d);
void board(char d);

int main()
{
    cout << "\t\t\t <<<<WELCOME TO GAME>>>> \n";

    // displaying menu
    menu();
    d = _getch();
    if (d == 'i')
    {
        instruction();
        cout << "\nenter n to start the game\n";
        d = _getch();
    }

    // controlling the player
    board(d);
    return 0;
}

void menu()
{
    cout << "Start a new game PRESS n\n";
    cout << "How to play? Press i\n";
    cout << "For High score in the game p h\n";
}

void instruction()
{
    cout << "\t\t\tHow to Play!\n\n";
    cout << "Controls:\npress w for up\npress s for down\npress d for right\npress a for left \n";
    cout << "\nThe user have 3 lives, each live will be lost on colliding with the opponent car. the user is required to keep the car in the specified boundaries.\nYou can collect maximum points by collecting the"
         << "dots on its way the next level starts as soon as all dots are collected.The game contains 4 levels after which you win.";
}
void pauseMenu()
{
    char m;
    cout << "Press [n] to start a new game\n";
    cout << "Press[h] to view high score\n";
    cout << "Press any key to resume the game\n";
    m = _getch();
}
// map of the game
void map()
{
    for (int i = 0; i < mapLen; i++)
    {
        for (int j = 0; j < mapBreth; j++)
        {
            array[i][j] = " .";
        }
    }

    for (int i = 0; i < mapLen; i++)
    {
        for (int j = 0; j < mapBreth; j++)
        {
            array[0][j] = "==";
            array[mapLen - 1][j] = "==";
            array[i][0] = "||";
            array[i][mapBreth - 1] = "||";
        }
    }
    for (int i = 2; i < mapLen - 2; i++)
    {
        for (int j = 2; j < mapBreth - 2; j++)
        {
            array[2][j] = "==";
            array[mapLen - 3][j] = "==";
            array[i][2] = "||";
            array[i][mapBreth - 3] = "||";
        }
    }
    for (int i = 4; i < mapLen - 4; i++)
    {
        for (int j = 4; j < mapBreth - 4; j++)
        {
            array[4][j] = "==";
            array[mapLen - 5][j] = "==";
            array[i][4] = "||";
            array[i][mapBreth - 5] = "||";
        }
    }
    for (int i = 6; i < mapLen - 6; i++)
    {
        for (int j = 6; j < mapBreth - 6; j++)
        {
            array[6][j] = "==";
            array[mapLen - 7][j] = "==";
            array[i][6] = "||";
            array[i][mapBreth - 7] = "||";
        }
    }
    for (int i = 0; i < mapLen; i++)
    {
        for (int j = 0; j < mapBreth; j++)
        {
            if ((i > 8 && i < 12) || (j > 12 && j < 16))
            {
                array[i][j] = "  ";
            }
        }
    }
    for (int i = 0; i < mapLen; i++)
    {
        for (int j = 0; j < mapBreth; j++)
        {
            cout << array[i][j];
            array[x][y] = " @";
            array[e][f] = " #";
        }
        cout << endl;
    }

    array[x][y] = " @";
    array[e][f] = " #";
}

void movement(char d)
{
    if (d == 'n')
    {
        system("cls");
        // map of the game
        map();
        cout << "enter direction";
        while (true)
        {
            n = _getch();

            switch (n)
            {
            case 'w':
            {
                x--;
                array[x + 1][y] = "  ";
                e--;
                if (array[e][f] == "  ")
                {
                    array[e + 1][f] = "  ";
                }
                else
                {
                    array[e + 1][f] = " .";
                }

                break;
            }

            case 's':
            {
                x++;
                array[x - 1][y] = "  ";
                e++;
                if (array[e][f] == "  ")
                {
                    array[e - 1][f] = "  ";
                }
                else
                {
                    array[e - 1][f] = " .";
                }

                break;
            }
            case 'd':
            {
                y++;
                array[x][y - 1] = "  ";
                f--;
                if (array[e][f] == "  ")
                {
                    array[e][f + 1] = "  ";
                }
                else
                {
                    array[e][f + 1] = " .";
                }

                break;
            }
            case 'a':
            {
                y--;
                array[x][y + 1] = "  ";
                f++;
                if (array[e][f] == "  ")
                {
                    array[e][f - 1] = "  ";
                }
                else
                {
                    array[e][f - 1] = " .";
                }

                break;
            }
            case 'p':
            {

                system("pause");
                pauseMenu();
                break;
            }
            case 'e':
            {
                break;
            }
            }
            if (array[x][y] == " .")
            {
                score++;
            }
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});
            for (int i = 0; i < mapLen; i++)
            {
                for (int j = 0; j < mapBreth; j++)
                {
                    cout << array[i][j];
                    array[x][y] = " @";
                    array[e][f] = " #";
                }
                cout << endl;
            }
            cout << "the score is " << score << endl;
            if (array[x][y] == " #")
            {
                cout << "\t\t\tend game";
                break;
            }
        }
    }
}

void board(char d)
{
    movement(d);
}