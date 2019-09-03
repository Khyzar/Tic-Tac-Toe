#include <cstdlib> //for rand function
#include <ctime> 
#include <iostream>
using namespace std;
void printboard(char **b,int size)
{
	cout<<" ";
	char v=179,h=196,j=197;
	for(int q=0;q<size;q++)
			cout<<q<<" ";  //q shows the horizontal numbering
	cout<<endl;
	for(int i=0;i<size;i++)
	{
		cout<<i;  //i shows the vertical numbering
		for(int j=0;j<size;j++)
		{
			cout<<b[i][j];
			if(j<size-1)
				cout<<v;  //v use for vertical lining
		}
		cout<<endl<<" ";
		if(i<size-1)
		for(int k=0;k<size-1;k++)
			cout<<h<<j; //h shows horizontal and j shows joining lines
		if(i<size-1)
			cout<<h<<endl;		
	}
}
bool endGame(char **b,int size)
{
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
			if(b[i][j]==' ')//if a box is empty
				return false;
	}
	return true;
}
bool isEmpty(char **b,int r,int c)
{
	if(b[r][c]==' ')
		return true;
	else
		return false;		
}
void winner(char **b,int size)
{
	int countX=0;
	int countO=0;

	for (int i=0;i<size-2;i++)
	{
		for(int j=0;j<size-2;j++)
		{
			if((b[i][j]=='X')&&(b[i+1][j]=='X')&&(b[i+2][j]=='X'))
				countX++;
			if((b[i][j]=='X')&&(b[i][j+1]=='X')&&(b[i][j+2]=='X'))
				countX++;
			if((b[i][j]=='X')&&(b[i+1][j+1]=='X')&&(b[i+2][j+2]=='X'))
				countX++;

			if((b[i][j]=='O')&&(b[i+1][j]=='O')&&(b[i+2][j]=='O'))
				countO++;
			if((b[i][j]=='O')&&(b[i][j+1]=='O')&&(b[i][j+2]=='O'))
				countO++;
			if((b[i][j]=='O')&&(b[i+1][j+1]=='O')&&(b[i+2][j+2]=='O'))
				countO++;
		}
	}

	for(int i=0;i<size-2;i++)//remaining columns
	{
		for(int j=size-2;j<size;j++)
		{
			if((b[i][j]=='X')&&(b[i+1][j]=='X')&&(b[i+2][j]=='X'))
				countX++;
			if((b[i][j]=='O')&&(b[i+1][j]=='O')&&(b[i+2][j]=='O'))
				countO++;			

		}
	}
	for (int i=size-2;i<size;i++)//remaining rows
	{
		for(int j=0;j<size-2;j++)
		{
			if((b[i][j]=='X')&&(b[i][j+1]=='X')&&(b[i][j+2]=='X'))
				countX++;
			if((b[i][j]=='O')&&(b[i][j+1]=='O')&&(b[i][j+2]=='O'))
				countO++;
		}
	}
	cout<<" SCORE : "<<endl<<"Player 'O' : "<<countO<<"Pts"<<endl<<"Player 'X' : "<<countX<<"pts"<<endl;

	if(countO>countX)
		cout<<"Player 'O' WINS "<<endl;
	else if (countX>countO)
		cout<<"Player 'X' WINS "<<endl;
	else if(countX==countO)
		cout<<"GAME DRAW !!!"<<endl;


}
void main()////////////////////////////////////////////////////////////////////////////////////////////
{
	int n;
	cout<<"Enter the size of the board"<<endl;
	cin>>n;
	bool p1=false;
	int players=0;
	cout<<"1 or 2 Players ?"<<endl;
	cin>>players;

	if(players==1)
		p1=true;

	char **board;

	board=new char*[n];
	
	for(int a=0;a<n;a++)
		board[a]=new char[n];
	
	for(int a=0;a<n;a++)
		for(int b=0;b<n;b++)
			board[a][b]=' ';
	
	int inputr=0;
	int inputc=0;
	char turn='O';
	while(1)
	{
		printboard(board,n);
		cout<<" Player : '"<<turn<<"'";	
		while(1)//one turn
		{
			while(1)
			{
				cout<<endl<<"Enter ROW :";
				if((turn=='X')&&(p1))
				{
					srand (clock());
					inputr=(rand()%n);
				}
				else
					cin>>inputr;
				if((inputr>=0)&&(inputr<n))
					break;
				else
					cout<<"INVALID COL Please Try Again"<<endl;
			}
			while(1)
			{
				cout<<endl<<"Enter COL :";
				if((turn=='X')&&(p1))
				{
					srand (clock());
					inputc=(rand()%n);
				}
				else
					cin>>inputc;
				if((inputc>=0)&&(inputc<n))
					break;
				else
					cout<<"INVALID COL Please Try Again"<<endl;
			}
			if(isEmpty(board,inputr,inputc))
				break;
			else
				cout<<"Location not Empty...Please Enter Again"<<endl;
		}

		board[inputr][inputc]=turn;
		if(turn=='X')
			turn='O';
		else
			turn='X';
		if(endGame(board,n))
			break;
		system("cls");
	}
	system("cls");
	printboard(board,n);

	cout<<endl<<"GAME OVER"<<endl;
	
	winner(board,n);
	cout<<endl;

	system("pause");
}