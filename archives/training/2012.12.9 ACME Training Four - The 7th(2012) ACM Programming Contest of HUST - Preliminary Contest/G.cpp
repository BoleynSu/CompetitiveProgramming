//============================================================================
// Name        : G.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <ctime>
#include <map>
using namespace std;

const int MAXN=1000000;
int lsts;
int lst[MAXN+2];
int f[MAXN+2];
int flsts;
int flst[MAXN+2];

int main()
{
	for (int i=1;i*i*i<=MAXN;i++) lst[lsts++]=i*i*i;

	f[0]=1;
	flst[flsts++]=0;

	for (int ii=0;ii<flsts;ii++)
	{
		int i=flst[ii];
		for (int j=0;j<lsts&&i+lst[j]<=MAXN;j++)
			f[i+lst[j]]=f[i+lst[j]]|(f[i]<<1);
	}
	flsts=0;
	for (int i=0;i<=MAXN;i++) if (f[i]) flst[flsts++]=i;

	for (int ii=0;ii<flsts;ii++)
	{
		int i=flst[ii];
		for (int j=0;j<lsts&&i+lst[j]<=MAXN;j++)
			f[i+lst[j]]=f[i+lst[j]]|(f[i]<<1);
	}
	flsts=0;
	for (int i=0;i<=MAXN;i++) if (f[i]) flst[flsts++]=i;

	for (int ii=0;ii<flsts;ii++)
	{
		int i=flst[ii];
		for (int j=0;j<lsts&&i+lst[j]<=MAXN;j++)
			f[i+lst[j]]=f[i+lst[j]]|(f[i]<<1);
	}
	flsts=0;
	for (int i=0;i<=MAXN;i++) if (f[i]) flst[flsts++]=i;
	//cerr<<double(clock())/CLOCKS_PER_SEC<<endl;

	int n;
	while (~scanf("%d",&n))
	{
		if (f[n]&(1<<3)) puts("Yes");
		else puts("No");
	}
	return 0;
}