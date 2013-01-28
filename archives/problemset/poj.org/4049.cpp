/*
 * f.cpp
 *
 *  Created on: 2012-10-20
 *      Author: sujiao
 */



#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

short calcedf[1<<20],calcedg[1<<20];
bool f[1<<20],g[1<<20];
int T;
int target;
char board[4][4];
int bcnt;
int bx[10],by[10];
bool ff;

int calc(int state)
{
	char brd[4][4];
	for (int i=0;i<4;i++)
		for (int j=0;j<4;j++)
			brd[i][j]=board[i][j];
	int pcnt=0;
	for (int i=0;i<bcnt;i++)
	{
		int s=state&3;
		state>>=2;
		if (s==1) brd[bx[i]][by[i]]='o',pcnt++;
		if (s==2) brd[bx[i]][by[i]]='x',pcnt++;
	}
	for (int i=0;i<4;i++)
	{
		bool win=true;
		for (int j=0;j<4;j++) if (brd[i][j]!='o') win=false;
		if (win) return 3;
	}
	for (int i=0;i<4;i++)
	{
		bool win=true;
		for (int j=0;j<4;j++) if (brd[j][i]!='o') win=false;
		if (win) return 3;
	}
	{
		bool win=true;
		for (int i=0;i<4;i++) if (brd[i][i]!='o') win=false;
		if (win) return 3;
	}
	{
		bool win=true;
		for (int i=0;i<4;i++) if (brd[i][3-i]!='o') win=false;
		if (win) return 3;
	}
	for (int i=0;i<4;i++)
	{
		bool win=true;
		for (int j=0;j<4;j++) if (brd[i][j]!='x') win=false;
		if (win) return 2;
	}
	for (int i=0;i<4;i++)
	{
		bool win=true;
		for (int j=0;j<4;j++) if (brd[j][i]!='x') win=false;
		if (win) return 2;
	}
	{
		bool win=true;
		for (int i=0;i<4;i++) if (brd[i][i]!='x') win=false;
		if (win) return 2;
	}
	{
		bool win=true;
		for (int i=0;i<4;i++) if (brd[i][3-i]!='x') win=false;
		if (win) return 2;
	}
	if (pcnt==bcnt) return 1;
	return 0;
}
bool dfsf(int);
bool dfsg(int);
bool dfsf(int state)
{
	if (calcedf[state]==T) return f[state];
	calcedf[state]=T;
	int rst=calc(state);
	if (rst) return f[state]=(ff?rst==target:rst!=target);
	else
	{
		for (int i=0;i<bcnt;i++)
			if (!(state&(3<<(i*2))))
			{
				if (!dfsg(state|(1<<(i*2)))) return f[state]=true;
			}
		return f[state]=false;
	}
}
bool dfsg(int state)
{
	if (calcedg[state]==T) return g[state];
	calcedg[state]=T;

	int rst=calc(state);
	/*
	int ss=state;
	for (int i=0;i<bcnt;i++)
	{
		int s=ss&3;
		ss>>=2;
		if (s==1) cout<<bx[i]<<" "<<by[i]<<":o"<<endl;
		if (s==2) cout<<bx[i]<<" "<<by[i]<<":x"<<endl;
	}
	cout<<"rst:"<<rst<<endl;
	*/
	if (rst) return g[state]=(ff?rst!=target:rst==target);
	else
	{
		for (int i=0;i<bcnt;i++)
			if (!(state&(3<<(i*2))))
				if (!dfsf(state|(2<<(i*2)))) return g[state]=true;
		return g[state]=false;
	}
}

int main()
{
	cin>>T;
	while (T)
	{
		string trg;
		cin>>trg;
		bcnt=0;
		int o=0,x=0;
		for (int i=0;i<4;i++)
			for (int j=0;j<4;j++)
			{
				cin>>board[i][j];
				if (board[i][j]=='.') bx[bcnt]=i,by[bcnt]=j,bcnt++;
				else if (board[i][j]=='x') x++;
				else o++;
			}
		if (x!=o)
		{
			if (trg=="WIN") target=3;
			else if (trg=="LOSE") target=2;
			else target=1;
			ff=true;
		}
		else
		{
			if (trg=="WIN") target=2;
			else if (trg=="LOSE") target=3;
			else target=1;
			ff=false;
		}
		cout<<((x!=o?dfsf(0):dfsg(0))?"YES":"NO")<<endl;
		T--;
	}
}
