/****************************************************************
	Problem: 1615
	User: RUC_Acme
	Language: C++
	Result: Accepted
	Time:124 ms
	Memory:8512 kb
****************************************************************/

//============================================================================
// Name        : t.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;


int N,M;
pair<int,int> A[1000];
pair<int,int> AT[1000];
pair<int,int> B[1000000];

int main() {
	int C;
	scanf("%d",&C);
	for (int i=0;i<C;i++)
	{
		scanf("%d%d",&N,&M);
		for (int i=0;i<M;i++) scanf("%d%d",&A[i].first,&A[i].second),AT[i]=make_pair(A[i].second,A[i].first);
		sort(A,A+M);
		sort(AT,AT+M);

		int ans=0;
		for (int i=0;i<M;i++)
		{
			for (int j=0;j<M;j++)
				if (A[i].second==AT[j].first)
					B[ans++]=make_pair(A[i].first,AT[j].second);
		}
		sort(B,B+ans);
		printf("%d\n",unique(B,B+ans)-B);
	}
	return 0;
}