// matin amir panahfar _40212358003
// nima makhmali _40212358035
// buali sina university

#include <iostream>
#include <windows.h> 
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

// Our spaceship structure
struct spaceship
{
    int xFirst;
    int yFirst;
    int x, y;
    char c = '#';
    int health = 3;
};

// function portotype
void grandDraw(int condition[col][row],spaceship &mySpaceShip);
void horizontalDraw(void);
void action(int condition[col][row],spaceship &mySpaceShip);
void move(int condition[col][row],spaceship &mySpaceShip);
void shoot(int condition[col][row],spaceship &mySpaceShip);
void gameRun(int condition[col][row],spaceship &mySpaceShip);
void lossHealth(int condition[col][row],spaceship &mySpaceShip);

// main function
int main()
{
    system("cls");
    srand(time(NULL));
    spaceship mySpaceShip; 
    int condition[col][row];// condition of our game houses 0 for null and 1 for OurSpace ship and 2 for our enemys
    gameRun(condition,mySpaceShip);
    while ( mySpaceShip.health != 0 )
    { 
        grandDraw(condition,mySpaceShip);
        action(condition,mySpaceShip);
    }
    system("cls");
    cout << RED << "********************************GAME OVER********************************"<< endl << RESET;
    system("pause");
    exit(0);
    return 0;
}

// functions  
void gameRun(int condition[col][row],spaceship &mySpaceShip)
{
    mySpaceShip.xFirst = rand()%col;
    mySpaceShip.yFirst = rand()%row;
    condition[mySpaceShip.xFirst][mySpaceShip.xFirst] = 1;
    mySpaceShip.x = mySpaceShip.xFirst;
    mySpaceShip.y = mySpaceShip.yFirst;
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

    for (int i = 0; i < 32; i++)
    {
        cout << YELLOW << "*" << RESET;
        Sleep(5);
    }
    cout << YELLOW << "STARWARS" << RESET;
    for (int i = 0; i < 32; i++)
    {
        cout << YELLOW << "*" << RESET;
        Sleep(5);
    }
    system("cls");

}

void horizontalDraw(void)
{
    cout << BOLDBLUE;
    for (int i=0;i < col;i++)
        cout << " ---";
    cout << RESET;
}
void grandDraw(int condition[col][row],spaceship &mySpaceShip)
{
    system("cls");
    bool win = false;
    cout << BOLDGREEN <<"********************************STARWARS********************************" << RESET;
    cout << "\nhealth:" << RED << mySpaceShip.health << RESET << endl;
    for (int i = 0;i < row;i++)
    {
        horizontalDraw();
        cout << endl;
        for (int j = 0;j < col;j++)
        {
            cout << BOLDBLUE <<"| " << RESET;
            if (j == mySpaceShip.x &&  i == mySpaceShip.y)
                cout << BOLDGREEN << mySpaceShip.c << ' ' << RESET;
            else if (condition[j][i] == 2)
            {
                cout << BOLDRED << "* " << RESET;
                win = true;
            }
            else
                cout << "  ";
        }
        cout << BOLDBLUE<< "|" << RESET << endl;
    }
    horizontalDraw();
    if (win == false)
    {
        system("cls");
        cout << BOLDGREEN << "********************************YOU WIN********************************"<< endl << RESET;
        system("pause");
        exit(0);
    }
}

void action(int condition[col][row],spaceship &mySpaceShip)
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
            move(condition,mySpaceShip);
            flag = true;
            break;

        case 's':
            shoot(condition,mySpaceShip);
            flag = true;
            break;

        default:
            cout << RED << "undefined please enter to try again" << RESET << endl;
            getchar();
            getchar();
            flag = false;
        }
    } while (flag = false);
}

void move(int condition[col][row],spaceship &mySpaceShip)
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
                lossHealth(condition,mySpaceShip);;
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
                lossHealth(condition,mySpaceShip);
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
                lossHealth(condition,mySpaceShip);
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
                lossHealth(condition,mySpaceShip);
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
            cout << RED << "undefined please enter to try again" << RESET << endl;
            getchar();
            getchar();
            flag = false;
        }
    }while (flag == false);
}

void lossHealth(int condition[col][row],spaceship &mySpaceShip)
{
    mySpaceShip.health--;
    cout << RED << "!--ops--" << RESET;
    getchar();
    getchar();
    condition[mySpaceShip.x][mySpaceShip.y] = 0;
    mySpaceShip.x = mySpaceShip.xFirst;
    mySpaceShip.y = mySpaceShip.yFirst;
    condition[mySpaceShip.x][mySpaceShip.y] = 1;
}

void shoot(int condition[row][col],spaceship &mySpaceShip)
{
    char shoot;
    bool flag = true;
    do
    {
        int x = mySpaceShip.x;
        cout << "\nshoot right or left[r/l]:";
        cin >> shoot;
        switch (shoot)
        {
        case 'r':
            do
            {
                x++;
                if (2 == condition[x][mySpaceShip.y])
                {
                    condition[x][mySpaceShip.y] = 0;
                    break;
                }
            }   while(x < col);
            flag = true;
            break;
        case 'l':
            do
            {
                x--;
                if (2 == condition[x][mySpaceShip.y])
                {
                    condition[x][mySpaceShip.y] = 0;
                    break;
                }
            }while(x >= 0);
            flag = true;
            break;
        default:
            cout << RED << "undefined please enter to try again" << RESET << endl;
            getchar();
            getchar();
            flag = false;
        }          
    }while (flag == false);
}
   
    
