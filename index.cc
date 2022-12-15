#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

// Global Varibles
char m, array[50][50];
int x = 1, y = 10, e = 6, t = 9, score = 0, level = 1;

int movement()
{
    char m, array[50][50];
    int x = 1, y = 1, e = 6, t = 9, score = 0, level = 1;
    bool flag = 0;
    for (int i = 0; i < 14; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            array[i][j] = ' ';
        }
    }
    for (int i = 0; i < 14; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (i == 0 || i == 13 || j == 0 || j == 19)
            {
                array[i][j] = '#';
            }

            else if (i == 2 && j >= 2 && j <= 8)
            {
                array[i][j] = '#';
            }
            else if (i == 2 && j >= 11 && j <= 17)
            {
                array[i][j] = '#';
            }
            else if (i == 4 && j >= 4 && j <= 8)
            {
                array[i][j] = '#';
            }
            else if (i == 4 && j >= 11 && j <= 15)
            {
                array[i][j] = '#';
            }
            else if (i == 6 && j >= 7 && j <= 8)
            {
                array[i][j] = '#';
            }
            else if (i == 6 && j >= 11 && j <= 12)
            {
                array[i][j] = '#';
            }
            else if (i == 11 && j >= 2 && j <= 8)
            {
                array[i][j] = '#';
            }
            else if (i == 11 && j >= 11 && j <= 17)
            {
                array[i][j] = '#';
            }
            else if (i == 9 && j >= 4 && j <= 8)
            {
                array[i][j] = '#';
            }
            else if (i == 9 && j >= 11 && j <= 15)
            {
                array[i][j] = '#';
            }
            else if (i == 7 && j >= 7 && j <= 8)
            {
                array[i][j] = '#';
            }
            else if (i == 7 && j >= 11 && j <= 12)
            {
                array[i][j] = '#';
            }
            else if (j == 2 && i >= 3 && i <= 5)
            {
                array[i][j] = '#';
            }
            else if (j == 2 && i >= 8 && i <= 11)
            {
                array[i][j] = '#';
            }
            else if (j == 4 && i == 5)
            {
                array[i][j] = '#';
            }
            else if (j == 4 && i == 8)
            {
                array[i][j] = '#';
            }
            else if (j == 15 && i == 5)
            {
                array[i][j] = '#';
            }
            else if (j == 15 && i == 8)
            {
                array[i][j] = '#';
            }
            else if (j == 17 && i >= 2 && i <= 5)
            {
                array[i][j] = '#';
            }
            else if (j == 17 && i >= 8 && i <= 10)
            {
                array[i][j] = '#';
            }
            else if (j == 9 || j == 10)
            {
                array[i][j] = ' ';
            }
            else if (i == 6 || i == 7)
            {
                array[i][j] == ' ';
            }
            else if (i == 10 && j == 10)
            {
                array[i][j] = 'o';
            }
            else if (i == 1 || i == 12 || i == 3 || i == 4 || i == 5 || i == 8 || i == 9 || i == 10)
            {
                array[i][j] = '.';
            }
            else if (j == 1)
            {
                array[i][j] = '.';
            }

            else if (j == 18)
            {
                array[i][j] = '.';
            }
            else if (i == 3)
            {
                array[i][j] = '.';
            }
            else if (j == 9 || j == 10)
            {
                array[i][j] = ' ';
            }
            array[x][y] = '@';
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
    while (true)
    {

        cout << "give direction";
        m = _getch();

        if (m == 'd')
        {
            y++;
            e--;
            if (y > 0)
            {
                array[x][y - 1] = ' ';
                array[e][t + 1] = '.';
            }
        }

        if (m == 'a')
        {
            y--;
            e++;
            if (y < 20)
                array[x][y + 1] = ' ';
            array[e][t - 1] = '.';
        }

        if (m == 'w')
        {
            x--;
            array[x + 1][y] = ' ';
            e++;
            array[e - 1][t] = '.';
        }
        if (m == 's')
        {
            x++;
            array[x - 1][y] = ' ';
            e--;
            array[e + 1][t] = ' ';
        }
        if (array[x][y] == '.')
        {
            score++;
        }

        if (array[x][y] == '#')
        {
            system("cls");
            cout << "\n\n\n\t\tYou loss and your score is : " << score;
            flag = 1;
            break;
        }
        system("cls");
        while (flag == 1)
        {
            for (int i = 0; i < 14; i++)
            {
                for (int j = 0; j < 20; i++)
                {
                    if (array[i][j] == '.')
                    {
                        flag == 0;
                    }
                    else
                    {
                        flag == 1;
                    }
                }
            }
        }
        cout << "\t\t\tscore : " << score << endl;
        cout << "\t\t\t\tLevel : " << level << endl;
        array[x][y] = '@';
        array[e][t] = '*';
        for (int i = 0; i < 14; i++)
        {
            for (int j = 0; j < 20; j++)
            {
                cout << array[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 1;
}

int main()
{
    char mode;
    cout << "Instruction: \n1. Use 'a' for left \n 2. Use 'd' for right  \n3.Use "
            "'s' for down \n4. Use 'w' for upper movements of your hero \n5. Eat "
            "the dots to gain points\n6. Don't touch boundary "
         << endl
         << endl;
    cout << "H -> Hard\nN -> Normal\nE -> Easy" << endl
         << endl
         << "Input : " << endl;
    mode = _getch();

    if (mode == 'e')
    {
        movement();
    }
}