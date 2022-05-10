#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

int map[10][10] = {
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
{1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};


struct FVector2D
{
    int X;
    int Y;
};

void Map();
void SetLocation(FVector2D NewLocation);


int main()
{
   

    bool bRunning = true;
    FVector2D PlayerPosition;
    PlayerPosition.X = 5;
    PlayerPosition.Y = 2;

    Map();

    while (bRunning)
    {
        int KeyCode = _getch();

        switch (KeyCode)
        {
        case 'w':
        case 'W':
            PlayerPosition.Y--;
            break;
        case 's':
        case 'S':
            PlayerPosition.Y++;
            break;
        case 'a':
        case 'A':
            PlayerPosition.X--;
            break;
        case 'd':
        case 'D':
            PlayerPosition.X++;
            break;
        case 27:
            bRunning = false;
            break;

        }

        PlayerPosition.X = PlayerPosition.X < 2 ? 2 : PlayerPosition.X;
        PlayerPosition.Y = PlayerPosition.Y < 2 ? 2 : PlayerPosition.Y;
        PlayerPosition.X = PlayerPosition.X > 16 ? 16 : PlayerPosition.X;
        PlayerPosition.Y = PlayerPosition.Y > 7 ? 7 : PlayerPosition.Y;

        system("cls");
        
        Map();
        SetLocation(PlayerPosition);
        cout << "P";
    }


    return 0;
    
}

//이동 구현
void SetLocation(FVector2D NewLocation)
{
    COORD Cur;
    Cur.X = NewLocation.X;
    Cur.Y = NewLocation.Y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}


void Map()
{
    for (int X = 0; X < 10; ++X)
    {
        for (int Y = 0; Y < 10; ++Y)
        {
            if (map[X][Y] == 1)
            {
                cout << '#' << ' ';
            }
            else
            {
                cout << ' ' << ' ';
            }
        }
        cout << '\n';

    }

}
