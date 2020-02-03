#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
#include <random>

using namespace std;
random_device device;
mt19937 generator(device());
uniform_int_distribution<int> distrbution1(1,38);
uniform_int_distribution<int> distrbution2(1,18);


bool koniecgry = false;
string plansza [20][40];
string c = "nie";
int owocX = 8 ;
int owocY=15;
int score = 0;
int length = 0;
char kierunek = 's';
int wonrzTabX[100]= {7};
int wonrzTabY[100]= {3};

void input()
{
        if(_kbhit())
        {
            switch(_getch())
            {
                case 'a':
                    kierunek = 'a';
                    break;
                case 's':
                    kierunek = 's';
                    break;
                case 'd':
                    kierunek = 'd';
                    break;
                case 'w':
                    kierunek = 'w';
                    break;

            }
        }

}

void draw()
{
        for(int i = 0;i<20;i++)
        {
            for(int j=0;j<40;j++)
            {
                if(i==0 || i==19)
                {
                    plansza[i][j] = "#";
                } else if (i>0 && i<19 && (j==0 || j==39))
                {
                    plansza[i][j] = "#";

                } else
                {
                    plansza[i][j] = " ";
                }
            }
        }
}
void drawSnake()
{
    plansza[owocY][owocX] = "R";
    for(int i =0;i<=length;i++)
    {
        plansza[wonrzTabY[i]][wonrzTabX[i]] = "O";
    }

    switch(kierunek){
                case 'a':

                    for(int i=length;i>=1;i--)
                    {
                        wonrzTabX[i] = wonrzTabX[i-1];
                        wonrzTabY[i] = wonrzTabY[i-1];
                    }
                    if(plansza[wonrzTabY[0]][wonrzTabX[0]-1] == "#" || plansza[wonrzTabY[0]][wonrzTabX[0]-1] == "O")
                    {
                        koniecgry = true;
                    }
                    wonrzTabX[0] -=1;
                    break;
                case 's':

                      for(int i=length;i>=1;i--)
                    {
                        wonrzTabY[i] = wonrzTabY[i-1];
                        wonrzTabX[i] = wonrzTabX[i-1];
                    }
                    if(plansza[wonrzTabY[0]+1][wonrzTabX[0]] == "#" || plansza[wonrzTabY[0]+1][wonrzTabX[0]] == "O")
                    {
                        koniecgry = true;
                    }
                    wonrzTabY[0] +=1;

                    break;
                case 'd':

                    for(int i=length;i>=1;i--)
                    {
                        wonrzTabX[i] = wonrzTabX[i-1];
                        wonrzTabY[i] = wonrzTabY[i-1];
                    }
                    if(plansza[wonrzTabY[0]][wonrzTabX[0]+1] == "#" || plansza[wonrzTabY[0]][wonrzTabX[0]+1] == "O")
                    {
                        koniecgry = true;
                    }
                    wonrzTabX[0] +=1;
                    break;
                case 'w':

                    for(int i=length;i>=1;i--)
                    {
                        wonrzTabY[i] = wonrzTabY[i-1];
                        wonrzTabX[i] = wonrzTabX[i-1];
                    }
                    if(plansza[wonrzTabY[0]-1][wonrzTabX[0]] == "#" || plansza[wonrzTabY[0]-1][wonrzTabX[0]] == "O")
                    {
                        koniecgry = true;
                    }
                    wonrzTabY[0] -=1;
                    break;
    }
}
void owocRandomize()
{
    do{
        owocX=distrbution1(generator);
        owocY=distrbution2(generator);
   }while(plansza[owocY][owocX] == "O");

}
void show()
{
    system("cls");
   for(int i = 0;i<20;i++)
   {
       for(int j=0;j<40;j++)
       {
                cout<<plansza[i][j];
       }
       cout<<""<<endl;
   }
}

void ogon()
{
        switch(kierunek){
                case 'a':
                    wonrzTabX[length] = wonrzTabX[0]+1;
                    wonrzTabY[length] = wonrzTabY[0];
                    break;
                case 's':
                    wonrzTabX[length] = wonrzTabX[0];
                    wonrzTabY[length] = wonrzTabY[0]-1;

                    break;
                case 'd':
                    wonrzTabX[length] = wonrzTabX[0]-1;
                    wonrzTabY[length] = wonrzTabY[0];

                    break;
                case 'w':
                    wonrzTabX[length] = wonrzTabX[0];
                    wonrzTabY[length] = wonrzTabY[0]+1;

                    break;
    }
}

void logika() {
    if(plansza[wonrzTabY[0]][wonrzTabX[0]]== plansza[owocY][owocX])
    {
        score++;
        length++;
        owocRandomize();
        ogon();
    }
}

int main()
{
    do{
        while(!koniecgry)
        {
            Sleep(100);
            input();
            draw();
            drawSnake();
            logika();
            show();
            cout<<"Punkty: "<<score;
        }
        system("cls");
        cout<<"Zdoby³es "<<score<<" punktow"<<endl;
        cout<<"czy chcesz zagraæ jeszcze raz? (nie): "<<endl;
        cin>>c;
        if(c=="tak")
        {
            koniecgry = false;
            owocX = 8;
            owocY=15;
            score = 0;
            length = 0;
            kierunek = 's';
            wonrzTabX[0]= 7;
            wonrzTabY[0]= 3;
        }
    }while(c=="tak");
    system("pause");
}
