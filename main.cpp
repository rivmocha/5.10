#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

struct FVector2D
{
    int X;
    int Y;
};


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


bool IsCollide(const FVector2D& NewPlayerPosition, FVector2D& OutPlayerPosition)
{
    if (map[NewPlayerPosition.Y][NewPlayerPosition.X] == '1')
    {
        return false;
    }
    else
    {
        OutPlayerPosition = NewPlayerPosition;
        return true;
    }
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

        FVector2D NewPlayerPosition = PlayerPosition;

        switch (KeyCode)
        {
        case 'w':
        case 'W':
            NewPlayerPosition.Y--;
             break;
        case 's':
        case 'S':
            NewPlayerPosition.Y++;
             break;
        case 'a':
        case 'A':
            NewPlayerPosition.X--;
             break;
        case 'd':
        case 'D':
            NewPlayerPosition.X++;
             break;
        case 27:
            bRunning = false;
            break;

        }

        IsCollide(NewPlayerPosition, PlayerPosition);

        /*
        PlayerPosition.X = PlayerPosition.X < 1 ? 1 : PlayerPosition.X;
        PlayerPosition.Y = PlayerPosition.Y < 1 ? 1 : PlayerPosition.Y;
        PlayerPosition.X = PlayerPosition.X > 17 ? 17 : PlayerPosition.X;
        PlayerPosition.Y = PlayerPosition.Y > 8 ? 8 : PlayerPosition.Y;
        */

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
