#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace sf;
using namespace std;

const int M = 26;
const int N = 16;

int gamegrid[M][N];
int gamegrid2[M][N];

float x = 1;
float y = 2;

void movepillar(int&);
void movepillar2();
void countscore(int&);


void fallbird(float &delay, float &timer, bool flap, int newgrid[][16] , int &score)
{
    if (timer > delay)
    {
        if (flap == true)
        {
            x -= 1.5;
        }
        else
            x += 0.6;
        movepillar(score);
        timer = 0;
    }
}

void movepillar(int &score)
{
    static int j = N - 1;
    static bool check = false;
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            gamegrid[i][j] = 0;
        }
    }
    
    static int space = 4;

    for (int i = 0; i < M / 2 - space; ++i)
    {
        gamegrid[i][j] = 1;
    }
    static int space2 = 0;
    space2 = (M / 2 - space) + 6;

    for (space2; space2 < M; ++space2)
    {
        gamegrid[space2][j] = 1;
    }
    static int speed = 0;
    if (speed > 3)
    {
        --j;
        countscore(score);
        speed = 0;
    }
    if (j < 0)
    {
        space = rand() % 10;
        j = N - 1;
    }
    speed++;
    if (j < 8)
        check = true;
    if (check == true)
    {
        movepillar2();
    }   
}

void movepillar2()
{
    static int j = N - 1;
    static int speed = 0;
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            gamegrid2[i][j] = 0;
        }
    }

    static int space = 4;
    for (int i = 0; i < M / 2 - space; ++i)
    {
        gamegrid2[i][j] = 1;
    }

    static int space2 = 0;
    space2 = (M / 2 - space) + 6;

    for (space2; space2 < M; ++space2)
    {
        gamegrid2[space2][j] = 1;
    }
    static int num = 0;
    if (speed > 3)
    {
        --j;
        
        speed = 0;
    }
   
    if (j < 0)
    {
        space = rand() % 10;
        j = N - 1;
    }
    speed++;
}

bool gamelose()
{
    if (x > 22.3)
    {
        return true;
    }
    return false;
}

bool hitpillar()
{
    if (gamegrid[int(x)+1][2] == 1 || gamegrid[int(x)+1][3] == 1)
    {
        return true;
    }
    if (gamegrid2[int(x)+1][2] == 1 || gamegrid[int(x)+1][3] == 1)
    {
        return true;
    }
    return false;
}

void birdfall()
{
    y +=1;
    for(x ; x <= 22.3 ; x += 0.3)
    {
    }
    while(1)
    {

    }

}

void countscore(int &score)
{
    for(int i = int(x) ; i >= 0 ; --i)
    {
        if(gamegrid[i][2] == 1)
        { 
            score +=1;
            cout << score << endl;
            break;
        }
        else if(gamegrid2[i][2] == 1)
        {
            score +=1;
            cout << score << endl;
            break;  
        }
    }  
    
}
