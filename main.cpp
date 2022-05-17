#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

struct FVector2D
{
    int X;
    int Y;
};

char Map[10][10] = {
    {'#','#','#','#','#','#','#','#','#','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ','#',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ','#',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ','G','#'},
    {'#','#','#','#','#','#','#','#','#','#'}
};


bool IsCollide(const FVector2D& PredictPlayerPosition, FVector2D& OutPlayerPosition)
{
    if (Map[PredictPlayerPosition.Y][PredictPlayerPosition.X] == '#')
    {
        return false;
    }
    else
    {
        OutPlayerPosition = PredictPlayerPosition;
        return true;
    }
}

void SetLocation(FVector2D NewLocation);

void DrawBG(FVector2D StartPosition)
{
    for (int Y = 0; Y < 10; ++Y)
    {
        for (int X = 0; X < 10; ++X)
        {
            FVector2D Temp;
            Temp.X = X + StartPosition.X;
            Temp.Y = Y + StartPosition.Y;
            SetLocation(Temp);
            cout << Map[Y][X];
        }
    }

}

int main()
{
   

    bool bRunning = true;
    FVector2D PlayerPosition;
    PlayerPosition.X = 5;
    PlayerPosition.Y = 2;

    
    srand(static_cast<unsigned int>(time(nullptr)));
    FVector2D StartPosition = { 0, 0 };
    StartPosition.X = rand() % 10 + 1;
    StartPosition.Y = rand() % 10 + 1;


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

        
        PlayerPosition.X = PlayerPosition.X < 1 ? 1 : PlayerPosition.X;
        PlayerPosition.Y = PlayerPosition.Y < 1 ? 1 : PlayerPosition.Y;
        PlayerPosition.X = PlayerPosition.X > 17 ? 17 : PlayerPosition.X;
        PlayerPosition.Y = PlayerPosition.Y > 8 ? 8 : PlayerPosition.Y;
        

        system("cls");
        
        DrawBG(StartPosition);
        FVector2D Temp;
        Temp.X = PlayerPosition.X + StartPosition.X;
        Temp.Y = PlayerPosition.Y + StartPosition.Y;
        SetLocation(Temp);
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

