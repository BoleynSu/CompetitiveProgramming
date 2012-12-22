/****************************************************************
	Problem: 1611
	User: RUC_Acme
	Language: C++
	Result: Accepted
	Time:4 ms
	Memory:1868 kb
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
#include <cmath>
using namespace std;


int N,M;
pair<pair<int,int>,int> A[100000];

bool my_cmp(const pair<pair<int,int>,int>& a,const pair<pair<int,int>,int>& b)
{
	return max(a.first.first*a.first.second,b.first.second)<max(b.first.first*b.first.second,a.first.second);
}

int main() {
	while (~scanf("%d",&N)){
		for (int i=0;i<N;i++){
			scanf("%d",&A[i].first.first);
		}
		for (int i=0;i<N;i++){
			scanf("%d",&A[i].first.second);
		}
		for (int i=0;i<N;i++){
			A[i].second=i;
		}
		sort(A,A+N,my_cmp);

		double max=-1e10;
		double get=0;
		int ans;
		for (int i=0;i<N;i++)
		{
			if (get-log(A[i].first.second)>max)
			{
				max=get-log(A[i].first.second);
				ans=A[i].second;
			}
			get+=log(A[i].first.first);
		}
		printf("%d\n",ans+1);
	}
	return 0;
}