#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h> 
#include <ctime>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

#define row 10
#define col 10
#define NumberOfEnemys 10

using namespace std;

// global variables
const int xFirst = rand()%col;
const int yFirst = rand()%row;
// Our spaceship structure
struct 
{
    int x, y;
    int health = 3;
}mySpaceShip;

// function portotype
void grandDraw(int condition[col][row]);
void horizontalDraw(void);
int howManyEnemy(void);
void action(int condition[col][row]);
void move(int condition[col][row]);
void shoot(int condition[col][row]);

// main function
int main()
{
    srand(time(NULL));
    int condition[col][row];// condition of our game houses 0 for null and 1 for OurSpace ship and 2 for our enemys
      
    mySpaceShip.x = xFirst;
    mySpaceShip.y = yFirst;
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
    while ( mySpaceShip.health != 0 )
    { 
        grandDraw(condition);
        action(condition);
        getchar();
    }
    system("cls");
    cout << RED << "********************************GAME OVER********************************"<< endl << RESET;
    return 0;
}
int howManyEnemy()
{
	int condition[col][row];
    int count = 0;
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            if (condition[i][j] == 2)
            {
                count++;
            }
        }
    }
    return count;
}

// functions  
void horizontalDraw(void)
{
    cout << BOLDBLUE;
    for (int i=0;i < col;i++)
        cout << " ---";
    cout << RESET;
}
void grandDraw(int condition[col][row])
{
    system("cls");
    cout << BOLDGREEN <<"******************************************STARWAR******************************************" << RESET;
    cout << "\nhealth:" << RED << mySpaceShip.health << RESET << endl;
    for (int i = 0;i < row;i++)
    {
        horizontalDraw();
        cout << endl;
        for (int j = 0;j < col;j++)
        {
            cout << BOLDBLUE <<"| " << RESET;
            if (condition[j][i] == 1)
                cout << BOLDGREEN <<"# " << RESET;
            else if (condition[j][i] == 2)
                cout << BOLDRED << "* " << RESET;
            else
                cout << "  ";
        }
        cout << BOLDBLUE<< "|" << RESET << endl;
    }
    horizontalDraw();
}

void action(int condition[col][row])
{
    char moveOrShoot;
    bool flag =true;
    do
    {
        cout << "\nmove or shoot[m/s]:";
        cin >> moveOrShoot;
        switch (moveOrShoot)
        {
        case 'm':
            move(condition);
            flag = true;
            break;

        case 's':
            shoot(condition);
            flag = true;
            break;

        default:
            cout << RED << "undefined please try again" << RESET << endl;
            flag = false;
        }
    } while (flag = false);
}

void move(int condition[col][row])
{
    char move;
    bool flag = true;
    do
    {
        cout << "up or down or left or right[u/d/l/r]:";
        cin >> move;
        switch (move)
        {
        case 'u':
            if (condition[mySpaceShip.x][mySpaceShip.y - 1] == 2)
            {
                mySpaceShip.health--;
                cout << RED << "!--ops--" << RESET;
                condition[mySpaceShip.x][mySpaceShip.y] = 0;
                mySpaceShip.x = xFirst;
                mySpaceShip.y = yFirst;
                condition[mySpaceShip.x][mySpaceShip.y] = 1;
                getchar();
            }
            else if(mySpaceShip.y - 1 >= 0 && mySpaceShip.y - 1 < row)
            {
                condition[mySpaceShip.x][mySpaceShip.y]=0;
                mySpaceShip.y--;
                condition[mySpaceShip.x][mySpaceShip.y]=1;
                flag = true;
            }
            break;
        case 'd':
            if (condition[mySpaceShip.x][mySpaceShip.y + 1] == 2)
            {
                mySpaceShip.health--;
                cout << RED << "!--ops--" << RESET;
                condition[mySpaceShip.x][mySpaceShip.y] = 0;
                mySpaceShip.x = xFirst;
                mySpaceShip.y = yFirst;
                condition[mySpaceShip.x][mySpaceShip.y] = 1;
                getchar();
            }
            else if(mySpaceShip.y + 1 >= 0 && mySpaceShip.y + 1 < row)
            {
                condition[mySpaceShip.x][mySpaceShip.y]=0;
                mySpaceShip.y++;
                condition[mySpaceShip.x][mySpaceShip.y]=1;
                flag = true;
            }   
            break;
        case 'r':
            if (condition[mySpaceShip.x + 1][mySpaceShip.y] == 2)
            {
                mySpaceShip.health--;
                cout << RED << "!--ops--" << RESET;
                condition[mySpaceShip.x][mySpaceShip.y] = 0;
                mySpaceShip.x = xFirst;
                mySpaceShip.y = yFirst;
                condition[mySpaceShip.x][mySpaceShip.y] = 1;
                getchar();
            }
            else if(mySpaceShip.x + 1 >= 0 && mySpaceShip.x + 1 < col)
            {
                condition[mySpaceShip.x][mySpaceShip.y]=0;
                mySpaceShip.x++;
                condition[mySpaceShip.x][mySpaceShip.y]=1;
                flag = true;
            }
            break;
        case 'l':
            if (condition[mySpaceShip.x - 1][mySpaceShip.y] == 2)
            {
                mySpaceShip.health--;
                cout << RED << "!--ops--" << RESET;
                condition[mySpaceShip.x][mySpaceShip.y] = 0;
                mySpaceShip.x = xFirst;
                mySpaceShip.y = yFirst;
                condition[mySpaceShip.x][mySpaceShip.y] = 1;
                getchar();
            }
            else if(mySpaceShip.x - 1 >= 0 && mySpaceShip.x - 1 < col)
            {
                condition[mySpaceShip.x][mySpaceShip.y]=0;
                mySpaceShip.x--;
                condition[mySpaceShip.x][mySpaceShip.y]=1;
                flag = true;
            }
            break;
        default:
            cout << RED << "undefined please try again" << RESET << endl;
            flag = false;
        }
    }while (flag == false);
    
    
    
}

void shoot(int condition[row][col])
{
    
    int enemyCount = howManyEnemy();
    if (enemyCount == 0)
    {
        cout << YELLOW << "No enemies left to shoot!" << RESET << endl;
        return;
    }

    int targetX, targetY;
    bool flag = false;
    do
    {
        cout << "Enter the target coordinates (x, y): ";
        cin >> targetY >> targetX;

       
        if (targetX < 0 || targetX >= col || targetY < 0 || targetY >= row)
        {
            cout << RED << "Invalid target coordinates. Please try again." << RESET << endl;
            
        }
        else if (condition[targetX][targetY] != 2)
        {
            cout << RED << "There is no enemy at the specified coordinates. Please try again." << RESET << endl;
        }
        else
        {
            flag = true;
        }
    } while (!flag);

    // 
    condition[targetX][targetY] = 0;
    cout << GREEN << "You shot an enemy at coordinates (" << targetX << ", " << targetY << ")!"  << endl;
}
