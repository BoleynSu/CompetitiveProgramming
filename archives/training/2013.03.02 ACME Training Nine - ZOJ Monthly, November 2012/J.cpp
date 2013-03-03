//============================================================================
// Name        : test.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstring>
#include <set>
#include<cstdio>
#include<string>
#include<map>
#include <sstream>
using namespace std;

const int N=20,T=20;
string ans;
char str[300];
char type[]={'m','p','s','z'};
int num[]={9,9,9,7};
map<char,int>sum[20];
map<char,int>backup[20],backup2[20];
void bkup()
{
	int i;
	for(i=1;i<=9;i++)
		backup[i]=sum[i];
}

void getbk()
{
	int i;
	for(i=1;i<=9;i++)
		sum[i]=backup[i];
}
void bkup2()
{
	int i;
	for(i=1;i<=9;i++)
		backup2[i]=sum[i];
}
bool ck()
{
	int card,cardnum,i;
	char c;
	for(card=0;card<3;card++)
	{
		c=type[card];
		for(cardnum=1;cardnum<=num[card];cardnum++)
		{
			//printf("%d%c %d\n",cardnum,c,sum[cardnum][c]);
			i=cardnum;
			if(!sum[i][c])continue;
			else if(sum[i][c]==1)sum[i+1][c]--,sum[i+2][c]--;
			else if(sum[i][c]==2)sum[i+1][c]-=2,sum[i+2][c]-=2;
			else if(sum[i][c]==3){sum[i][c]=0;continue;}
			else if(sum[i][c]==4)sum[i][c]-=3,sum[i+1][c]--,sum[i+2][c]--;
			else if(sum[i][c]<0)return false;
		}
	}
	c='z';
	for(i=1;i<=7;i++)
		if(sum[i][c]&&sum[i][c]!=3)return false;
	return true;
}
void getbk2()
{
	int i;
	for(i=1;i<=9;i++)
		sum[i]=backup2[i];
}
void pr(int x,int y)
{
	int card,cardnum;
	char c;
	bkup2();
	for(card=0;card<4;card++)
	{
		c=type[card];
		for(cardnum=1;cardnum<=num[card];cardnum++)
		{
			if(backup2[cardnum][c]>=2)
			{
				getbk2();
				sum[cardnum][c]-=2;
				if(ck())
				{
					ans+='0'+y;
					ans+=type[x];
					return ;
				}
			}
		}
	}
}

void sol()
{
	int card,cardnum;
	string tmp;
	bkup();
	char c;
	for(card=0;card<4;card++)
		for(cardnum=1;cardnum<=num[card];cardnum++)
		{
			getbk();
			c=type[card];
			if(sum[cardnum][c]==4)continue;
			sum[cardnum][c]++;
			pr(card,cardnum);

		}
	printf("%d",ans.size()/2);
	if(ans.size())cout<<" "<<ans;
		puts("");
}
int mainf()
{
	int i,x;
	char c;
	while(~scanf("%s",str+1))
	{
		ans.clear();
		for(i=1;i<=19;i++)
			sum[i].clear();
		for(i=1;i<=13;i++)
		{
			x=str[i*2-1]-'0';
			c=str[i*2];
			sum[x][c]++;
		}
		sol();
	}
	return 0;
}

bool cmin(int& a,int b)
{
	return a>b?a=b,true:false;
}
int main()
{
	int n;
	while (cin>>n)
	{
		string s;
		cin>>s;
		int m;
		cin>>m;
		int b1=0,b2=0;
		for (int i=0;i<n;i++)
			if (s[i]=='.') b1|=1<<i,b2|=1<<(n-1-i);
		int dp[m+n+1][1<<n];
		memset(dp,0x3f,sizeof(dp));
		dp[0][0]=0;
		for (int i=1;i<=m+n;i++)
		{
			int ii=i-1;
			for (int bit=(1<<n)-1;bit>=0;bit--)
			{
				if (!(bit&1))
				{
					cmin(dp[i][((bit>>1)|(1<<(n-1)))&b1],dp[ii][bit]+1);
					cmin(dp[i][((bit>>1)|(1<<(n-1)))&b2],dp[ii][bit]+1);
					cmin(dp[i][(bit>>1)|(1<<(n-1))],dp[ii][bit]);
				}
			}
		}
		int ans=0x3f3f3f3f;
		for (int i=(1<<n)-1;i>=0;i--) cmin(ans,dp[m+n][i]);
		if (ans==0x3f3f3f3f) cout<<-1<<endl;
		else cout<<ans<<endl;
	}
}
