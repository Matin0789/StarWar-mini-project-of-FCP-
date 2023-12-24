#include <iostream>
#include <stdlib.h> 
#include <ctime>
#define row 10
#define col 10

using namespace std;

// Our spaceship structure
struct
{
    int x = rand()%10, y= rand()%10;
    char c = '#';
    int heal = 3;
}mySpaceShip;

// function portotype
void grandDraw(int condition[col][row]);
void horizontalDraw(void);
int howManyEnemy(void);

// main function
int main()
{
    srand(time(NULL));
    int NumberOfEnemys = howManyEnemy();
    int condition[col][row];// condition of our game houses 0 for null and 1 for OurSpace ship and 2 for our enemys
    condition[mySpaceShip.x][mySpaceShip.y] = 1;
    for (int i = 0;i < NumberOfEnemys;i++)
    {
        while (true)
        {
            int x = rand()%col,y = rand()%row;
            if (condition[x][y] != 0)
                continue;
            else 
            {
                condition[x][y] = 2;
                break;
            }
        }
    }
    while ( mySpaceShip.heal != 0 )
    { 
        grandDraw(condition);
        getchar();
    }
        
    return 0;
}


// functions  
void horizontalDraw(void)
{
    for (int i=0;i < col;i++)
        cout << " ---";
}

void grandDraw(int condition[col][row])
{
    system("cls");
    cout << "****************************************************STARWAR****************************************************";
    cout << "\nhealth:" << mySpaceShip.heal << endl;
    for (int i = 0;i < row;i++)
    {
        horizontalDraw();
        cout << endl;
        for (int j = 0;j < col;j++)
        {
            cout << "| ";
            if (condition[j][i] == 1)
                cout << "# ";
            else if (condition[j][i] == 2)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << "|" << endl;
    }
    horizontalDraw();
}

int howManyEnemy(void)
{
    int howMany = rand() % (row * (col - 1) - col) +  (col + 1);
    return howMany;
}
