//Computer Science Annual Project
//Riya Jaggi
//Class: XI A
//2016-2017

//This is a digital version of the popular board game "Snakes and Ladders".

#include<iostream>
#include<stdio.h>
#include<stdlib.h>	//contains srand() and rand()
#include<windows.h> //For color attributes
#include<iomanip>
#include<time.h>	//To generate (seed) random number.  srand() should be dependented on time so that it gives different values everytime rand() is used.

using namespace std;

void menu();
void slboard(int);
void board(int, int);
int snakeladder (int, int);
void instructions();

struct player
	{
	char name[50];
	int cpos;	//current position
	int moves;
	int color;
	int flag;
	};


HANDLE hConsole= GetStdHandle(STD_OUTPUT_HANDLE);	//the handle "hConsole" is connected with the standard output device

int main()
{  
int game=1;
srand(time(NULL));
while(game==1)
{
	
system("cls");	//clear screen 
int dice, num, i, six, j=0;
int on=1, k, v=0;
int choice;
SetConsoleTextAttribute(hConsole, 15 ); //color syntax
player p[4];

	{		//colorattribute= foreground + background *16
	p[0].color=159;		// light blue	9	
	p[1].color=224;		// yellow	14	fore: black 0
	p[2].color=223;		// light magenta	13
	p[3].color=63;		// cyan		3
	}

for(i=0; i<4; i++)	//initialise structure variables
	{
	p[i].cpos=0;
	p[i].moves=0;
	p[i].flag=0;
	}	

GAMEMENU: //goto label
menu();
cin>>choice;
if(choice==1)

	{
system("cls");
cout<<"Enter the number of players (2-4 players): ";
cin>>num;
	{ 
		if(num<2 || num>4)
			{
				cout<<endl<<endl<<"Invalid action! You can only choose 2-4 players."<<endl;
				cout<<"Press ENTER to go back to menu "<<endl<<endl;
				cin.get();
				cin.get();
				system("cls");
				goto GAMEMENU;
			}
	}
for(i=0; i<num; i++)
	{
	cout<<"Enter name of player "<<i+1<<" : ";
	cin>>p[i].name;
	cout<<"The token color for "<<p[i].name<<" is ";
	SetConsoleTextAttribute(hConsole, p[i].color );
	cout<<"    "<<endl<<endl;
	SetConsoleTextAttribute(hConsole, 15 );
	}
cout<<"Press ENTER to begin the game. ";
cin.get();
cin.get();
system("cls");

while(on==1)
	{ 
	for(i=0; i<num; i++)
		{ 
		six=0;
		if(p[i].flag==0)
			{
				dice=6;
				board(p[i].cpos, p[i].color);
				cout<<endl<<p[i].name<<", press ENTER to roll the dice."<<endl;
				cin.get();
				p[i].moves++;
				while(dice==6 && six<3)
					{
					dice=(rand()%6)+1;
					
					cout<<"You rolled a "<<dice<<endl;
					if(dice==6)
						{
						cout<<"Press ENTER to roll again"<<endl;
						cin.get();
						}
					p[i].cpos+=dice;
					six++;
					}
			
					if(p[i].cpos<100)
					{
					cout<<"Press ENTER to move your token.";
					cin.get();
					board(p[i].cpos, p[i].color);
					cout<<"You reached position "<<p[i].cpos<<endl;
					p[i].cpos=snakeladder(p[i].cpos, p[i].color);
					}
				else if(p[i].cpos==100)
					{ v=0;
					cout<<"Congrats you have reached the end of the board!"<<endl;
					p[i].flag=5;
					j++;
					if(j==(num-1)) //if only one player left 
						{
							int k;
							for(k=0; k<4; k++)
								if(p[i].flag!=5)
									p[i].flag=5; }
							for(k=0; k<num; k++)
								if(p[i].flag==5)
									v++;
							if(v=num)
								{ 
								int min; on=0;
								cout<<"The scores are: "<<endl;
								for(k=0; k<num; k++)
									{
										cout<<p[k].name<<" reached position "<<p[k].cpos<<" in "<<p[k].moves<<" moves."<<endl;
									}	
								min=p[0].moves; int q;
								for(k=0;k<num; k++) //determines winner
									{
									if(p[k].moves<min && p[k].cpos==100)
									q=k;
									}
								cout<<"The winner is: "<<p[q].name<<endl;
								cout<<"Do you want to play again?"<<endl;
								cout<<"1. Yes"<<endl;
								cout<<"2. No"<<endl;
								cout<<"Enter number of your choice: ";
								cin>>game;
								break;
								}					
						}
				else if(p[i].cpos>100)
							{
								cout<<"Sorry, you need exact number to reach 100";
								p[i].cpos=(p[i].cpos)-dice;
								p[i].cpos=snakeladder(p[i].cpos, p[i].color);
							}
					SetConsoleTextAttribute(hConsole, 15 );
				cout<<"Press ENTER to end your turn."<<endl;
				cin.get();		
					}
				}
			}
				
				
			}
			
else if(choice==2)
	{
	instructions();
	cin.get();
	game=1;
	}
else if(choice==3)
{
  game=0; exit(0);}
else
	{
		cout<<"Invalid option"; 
		cout<<" Press ENTER to go back to menu.";
		cin.get();
	}	
}

return 0;
}


//end of main

void menu()
	{ 
	cout<<endl<<"\t\t\t SNAKES AND LADDERS"<<endl;
	cout<<"\t ------------------------------------------------";
	cout<<endl<<endl<<"\t 1. Game "<<endl;
	cout<<endl<<endl<<"\t 2. Instructions "<<endl;
	cout<<endl<<endl<<"\t 3. Exit"<<endl;
	cout<<endl<<endl<<"Enter your choice: "<<endl;
	cout<<endl<<endl;
	}

void board(int x, int y)
{
system("cls");
cout<<endl;
int board[10][10];
int i,j, c=100, n;
for(i=0;i<10; i++)
	{
		for(j=0;j<10;j++)
		{
		board[i][j]=c;
		c--;
		}
	}
	for(i=0;i<10; i++)
		{
		if(board[i][0]%20==0)
			{ for(j=0;j<10;j++)
				{ n=board[i][j];
				if(n==x)
				{ 
				SetConsoleTextAttribute(hConsole, y);
				cout<<setw(5)<<n;}
				else
				slboard(n);
				}
			}
		else
			{ for(j=9;j>=0;j--)
				{
				 n=board[i][j];
				 if(n==x)
				 { 
				 SetConsoleTextAttribute(hConsole, y);
				 cout<<setw(5)<<n;}
				 else
				slboard(n);
				}
			}  cout<<endl;
		}
cout<<endl;
SetConsoleTextAttribute(hConsole, 15);
}
void slboard(int a) //to display green color for ladder and red for snakes
{   
switch(a)
		{
		case 6:
		case 16:
		case 8:
		case 12:
		case 30:
		case 39:
		case 43:
		case 57:
		case 34:
		case 48:
		case 52:
		case 70:
		case 85:
		case 97:
		case 88:
		case 94:
		case 60:
		case 62:
		case 78:
			{ 	SetConsoleTextAttribute(hConsole, 32 );
			cout<<setw(5)<<a;
			}break;
		case 2:
		case 18:
		case 24:
		case 21:
		case 40:
		case 35:
		case 45:
		case 14:
		case 28:
		case 32:
		case 53:
		case 67:
		case 75:
		case 72:
		case 90:
		case 77:
		case 83:
		case 99:
			{
			SetConsoleTextAttribute(hConsole, 64 );
			cout<<setw(5)<<a;
			} break;
		default: 
			{
			SetConsoleTextAttribute(hConsole, 15 );
			cout<<setw(5)<<a;
			} break;
		}
	SetConsoleTextAttribute(hConsole, 15 );
}

int snakeladder(int a, int b)
{
 int flag=0;
cout<<endl;
	switch(a)
		{
			case 6:
				{
				cout<<"Congrats! You got a ladder to 16!";
				a=16;	
				break;
				}
			case 8:
				{
				cout<<"Congrats! You got a ladder to 30!";
				a=30;
				break;	
				}
			case 39:
				{
				cout<<"Congrats! You got a ladder to 57!";
				a=57;
				break;	
				}
			case 34:
				{
				cout<<"Congrats! You got a ladder to 70!";
				a=70;
				break;
				}
			case 60:
				{
				cout<<"Congrats! You got a ladder to 78!";
				a=78;
				break;
				}
			case 85:
				{
				cout<<"Congrats! You got a ladder to 97!";
				a=97;
				break;
				}
			case 88:
				{
				cout<<"Congrats! You got a ladder to 94!";
				a=94;
				break;
				}
			case 99:
				{
				cout<<"Oops! The snake caught you! You are going down to 77. ";
				a=77;
				flag=1;
				break;
				}
			case 90:
				{
				cout<<"Oops! The snake caught you! You are going down to 72. ";
				a=72;
				flag=1;
				break;
				}
			case 75:
				{
				cout<<"Oops! The snake caught you! You are going down to 53. ";
				a=53;
				flag=1;
				break;
				}
			case 45:
				{
				cout<<"Oops! The snake caught you! You are going down to 35. ";
				a=35;
				flag=1;
				break;
				}
			case 40:
				{
				cout<<"Oops! The snake caught you! You are going down to 21. ";
				a=21;
				flag=1;
				break;
				}
			case 32:
				{
				cout<<"Oops! The snake caught you! You are going down to 14. ";
				a=14;
				flag=1;
				break;
				}
			case 24:
				{
				cout<<"Oops! The snake caught you! You are going down to 2. ";
				a=2;
				flag=1;
				break;
				}
			default: flag=2; break;
		}
	cout<<endl;
	if(flag==0)
	{
		cout<<"Press enter to go up the ladder.";
		cin.get();
		board(a, b);
		cout<<"You are now at position "<<a<<endl;
	}
	else if(flag==1)
	{
		cout<<"Press enter to go down the snake.";
		cin.get();
		board(a, b);
		cout<<"You are now at position "<<a<<endl;
	}
return(a);
}

void instructions()
{
	system("cls");
	cout<<endl<<"\t\t\t INSTRUCTIONS"<<endl;
	cout<<"\t --------------------------------------------------"<<endl<<endl;
	cout<<"This is the digital version of the popular board game- Snakes and Ladders. "<<endl<<endl;
	cout<<"OBJECTIVE: The objective of the game is to be the first player to reach the end by moving across the board from first square (1) to the last square (100)."<<endl<<endl;
	cout<<"SETUP:  The board is set up such that the numbers are left to right in the first row (bottom of the screen) and then in the next row above it, right to left. "<<endl<<endl;
	cout<<"PLAYERS:  This game is meant for 2 to 4 players. Each player is assigned a color: light blue, yellow, light magenta and cyan respectively."<<endl<<endl;
	cout<<"GAME PLAY:  Follow the instructions on the screen.  The dice is rolled by pressing the ENTER key on the keyboard.  To move your token, press ENTER key.  The token is automatically moved to the respective box."<<endl<<endl;
	cout<<"The green colored boxes represent LADDERS. If you land on the bottom green box of the ladder, then you will go up to the last green box in that ladder."<<endl<<endl;
	cout<<"The red colored boxes represent SNAKES. If you land on the top box of the snake, then you will go down to the last red box in that snake."<<endl<<endl;
	cout<<"The token will automatically go up the ladder or down the snake, after you press ENTER."<<endl<<endl;
	cout<<"WINNING: In order to win, the player must get exactly the same number of boxes to 100.  For example, if Player 1 at box 96 gets 4, then only he/she will go to 100.  The token will not move if it is 5 or 6"<<endl<<endl;
	cout<<"RESULTS: When only one player is left and rest all players have passed hundred, the game will terminate and the results will be shown.  The rankings are based on who got to box 100 in less moves."<<endl<<endl;
	cout<<"NOTE: If your roll a 6, you get another dice throw. But, you cannot get more than three 6s in a row."<<endl<<endl<<endl<<endl;
	cout<<"\t\t Press ENTER to go back to menu.";
	cin.get();

}

//end of code
