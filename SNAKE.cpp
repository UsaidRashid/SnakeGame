#include<iostream>
#include<conio.h>
#include<windows.h>
#include<time.h>
using namespace std;

bool gameOver;
const int width=20;
const int height=20;
int x,y,fruitX,fruitY,score;
int tailX[100],tailY[100];
int nTail;
enum eDirection{STOP=0,LEFT,RIGHT,UP,DOWN};
eDirection dir;

void Setup()
{
    gameOver=false;
    dir=STOP;
    x=width/2;
    y=height/2;
    fruitX= rand() % width;
    fruitY= rand() % height;
    score=0;
}

void Draw()
{
    system("cls");
    for(int i=0;i<width+2;i++)
    {
        cout<<"#";
    }
    cout<<endl;

    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            if(j==0)
            {
                cout<<"#";
            }
            if(i==y && j== x)
            {
                cout<<"O";
            }
            else if(i==fruitY  && j==fruitX)
            {
                cout<<"*";
            }
            else
            {
               //bool print = false;
               int Z=0;
                for(int k=0;k<nTail;k++)
                {
                    if(tailX[k]==j && tailY[k]==i)
                    {
                        cout<<"o";
                    //    print=true;
                    Z++;
                    }
                }
                // if(!print)
                if(Z==0)
                cout<<" ";
            }
                
            if(j==width-1)
            {
                cout<<"#";
            }
        }
        cout<<endl;
    }
    for(int i=0;i<width+2;i++)
    {
        cout<<"#";
    }
    cout<<endl;
    cout<< "SCORE "<<score<<endl;
}

void Input()
{
    if (_kbhit())
    {
        switch(_getch())
        {
            case 'a':
            {
                dir=LEFT;
                break;
            }
            case 'w':
            {
                dir=UP;
                break;
            }
            case 's':
            {
                dir=DOWN;
                break;
            }
            case 'd':
            {
                dir=RIGHT;
                break;
            }
            case 'x':
            {
                gameOver=true;
                break;
            }
        }
    }
}

void Logic()
{
    int Px=tailX[0];
    int Py=tailY[0];
    tailX[0]=x;
    tailY[0]=y;
    int Qx,Qy;
    for(int i=1;i< nTail;i++)
    {
        Qx=tailX[i];
        Qy=tailY[i];
        tailX[i]=Px;
        tailY[i]=Py;
        Px=Qx;
        Py=Qy;
    }

    switch(dir)
    {
        case LEFT:
        {
            x--;
            break;
        }

        case RIGHT:
        {
            x++;
            break;
        }
        
        case UP:
        {
            y--;
            break;
        }
    
        case DOWN:
        {
            y++;
            break;
        }
        default:
        break;
    }
    if(x>width-1 || x<0 || y>height-1 || y<0)
    {
        gameOver=true;
    }

    for(int i=0;i<nTail;i++)
    {
        if(tailX[i]==x && tailY[i]==y)
        {
            gameOver=true;
        }
    }

    if(x==fruitX && y==fruitY)
    {
        score++;
        fruitX= rand() % width;
        fruitY= rand() % height;
        nTail++;
    }
}

int main()
{
    srand(time(NULL));
    Setup();
    while(!gameOver)
    {
        Draw();
        Input();
        Logic();
        if(dir==UP || dir==DOWN)
        {
            Sleep(80);
        }
        if(dir==RIGHT || dir == LEFT)
        Sleep(60);
    }
    return 0;
}