#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
#include <windows.h>
#include <list>

long int scor=0;
int ok=1,j;
bool efruit;

struct corp	{
			int i,j;
			corp *urm;
			}*cap,*coada;
corp *p,*q;

char mapa[24][60] = {"###########################################################",
                    "#                                                         #",
                    "#                                                         #",
                    "#                                                         #",
                    "#                                                         #",
                    "#                                                         #",
                    "#                                                         #",
                    "#                                                         #",
                    "#                                                         #",
                    "#                                                         #",
                    "#                                                         #",
                    "#                                                         #",
                    "#                                                         #",
                    "#                                                         #",
                    "#                                                         #",
                    "#                                                         #",
                    "#                                                         #",
                    "#                                                         #",
                    "#                                                         #",
                    "###########################################################",
					"#                                                         #",	
					"#                                                         #",
					"#Scor:                                                    #",
					"###########################################################",};

void fruit()
{
    srand(GetTickCount());
    int Fruitx = rand() % 57 +1;
    int Fruity = rand() % 18 +1;

    if(mapa[Fruity][Fruitx] == 'o')
    {
        fruit();
    }else
    {
        mapa[Fruity][Fruitx] = '*';
    }
  efruit=true;
}
void gotoxy(unsigned short x, unsigned short y)
{
    static HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    static COORD WritePos;
    WritePos.X = x; 
    WritePos.Y = y;
    SetConsoleCursorPosition(hStdOut,WritePos);
}					
void initsnake()
{gotoxy(10,10);

coada=new corp;
coada->i=10;
coada->j=10;
p=new corp;
p->i=10;
p->j=11;
coada->urm=p;
cap=new corp;
cap->i=10;
cap->j=12;
p->urm=cap;
cap->urm=NULL;
mapa[coada->i][coada->j]='o';
mapa[p->i][p->j]='o';
mapa[cap->i][cap->j]='o';
}

void initmapa()
{ for(j=0;j<24;j++)
	cout<<mapa[j]<<endl;
	 //Meniu
    /*cout << "#                                                         #\n";
    cout << "#                                                         #\n";
    cout << "#                                                         #\n"; 
    cout << "###########################################################";  */
    gotoxy(6,22);
    cout << scor;
	
	
}
					
int main()
{
    SetConsoleTitleA("Serpisor");
 system("color 70");
 initsnake();
fruit();
while(ok)
{ Sleep(10);
 if(!efruit) fruit(); 
    if(GetAsyncKeyState(VK_UP)!=0)
	   if(mapa[cap->i-1][cap->j]=='#') ok=0;
	 else   if(mapa[cap->i-1][cap->j]=='*')
		{q=new corp;
		   q->i=cap->i-1;
			q->j=cap->j;
			cap->urm=q;
			cap=q;
			mapa[cap->i][cap->j]='o';
			efruit=false;
			scor+=1000;
			
		}
    else { q=new corp;
		   q->i=cap->i-1;
			q->j=cap->j;
			cap->urm=q;
			cap=q;
			p=new corp;
			p=coada;
			coada=coada->urm;
			mapa[p->i][p->j]=' ';
			delete p;
			mapa[cap->i][cap->j]='o';
		   
          }
	else if(GetAsyncKeyState(VK_DOWN)!=0)
	   if(mapa[cap->i+1][cap->j]=='#') ok=0;
			else   if(mapa[cap->i+1][cap->j]=='*')
					{q=new corp;
					q->i=cap->i+1;
					q->j=cap->j;
					cap->urm=q;
					cap=q;
					mapa[cap->i][cap->j]='o';
					efruit=false;
					scor+=1000;
					
					}
					
    else { q=new corp;
		   q->i=cap->i+1;
			q->j=cap->j;
			cap->urm=q;
			cap=q;
			mapa[cap->i][cap->j]='o';
			p=new corp;
			p=coada;
			coada=coada->urm;
			mapa[p->i][p->j]=' ';
			delete p;
			
		   
          }
	else if(GetAsyncKeyState(VK_LEFT)!=0)
	   if(mapa[cap->i][cap->j-1]=='#') ok=0;
			else if(mapa[cap->i][cap->j-1]=='*')
			{q=new corp;
		   q->i=cap->i;
			q->j=cap->j-1;
			cap->urm=q;
			cap=q;
			mapa[cap->i][cap->j]='o';
			efruit=false;
			scor+=1000;
			
			}
    else { q=new corp;
		   q->i=cap->i;
			q->j=cap->j-1;
			cap->urm=q;
			cap=q;
			p=new corp;
			p=coada;
			coada=coada->urm;
			mapa[p->i][p->j]=' ';
			delete p;
			mapa[cap->i][cap->j]='o';
		   
          }
 else if(GetAsyncKeyState(VK_RIGHT)!=0)
	 if(mapa[cap->i][cap->j+1]=='#') ok=0;
       else if (mapa[cap->i][cap->j+1]=='*')
	   {q=new corp;
		 q->j=cap->j+1;
		 q->i=cap->i;
		 cap->urm=q;
		 cap=q;
		 mapa[cap->i][cap->j]='o';
		 scor+=1000;
		 efruit=false;
		 
	   }
	else{
	 q=new corp;
	 q->j=cap->j+1;
	 q->i=cap->i;
	 cap->urm=q;
	 cap=q;
	 p=new corp;
	 p=coada;
	 coada=coada->urm;
	 mapa[p->i][p->j]=' ';
	 delete p;
	 mapa[cap->i][cap->j]='o';
		
	 }
 

gotoxy(0,0);
initmapa();
}

return 0;
}
 
//start();
