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
//
//const int N=20,T=20;
//string ans;
//char str[300];
//char type[]={'s','p','m','z'};
//int num[]={9,9,9,7};
//map<char,int>sum[20];
//map<char,int>backup[20],backup2[20];
//void bkup()
//{
//	int i;
//	for(i=1;i<=9;i++)
//		backup[i]=sum[i];
//}
//
//void getbk()
//{
//	int i;
//	for(i=1;i<=9;i++)
//		sum[i]=backup[i];
//}
//void bkup()
//{
//	int i;
//	for(i=1;i<=9;i++)
//		backup2[i]=sum[i];
//}
//
//void getbk2()
//{
//	int i;
//	for(i=1;i<=9;i++)
//		sum[i]=backup2[i];
//}
//void pr()
//{
//	int card,cardnum;
//	char c;
//	for(card=0;card<4;card++)
//	{
//		c=type[card];
//		for(cardnum=1;cardnum<=num[card];cardnum++)
//		{
//			if(sum[cardnum][c]>=2)
//			{
//				get
//				sum[cardnum][c]-=2;
//			}
//		}
//	}
//}
//bool ck()
//{
//	int card,cardnum,i;
//	char c;
//	for(card=0;card<3;card++)
//	{
//		c=type[card];
//		for(cardnum=1;cardnum<=num[card];cardnum++)
//		{
//			//printf("%d%c %d\n",cardnum,c,sum[cardnum][c]);
//			i=cardnum;
//			if(!sum[i][c])continue;
//			else if(sum[i][c]==1)sum[i+1][c]--,sum[i+2][c]--;
//			else if(sum[i][c]==2)sum[i+1][c]-=2,sum[i+2][c]-=2;
//			else if(sum[i][c]==3){sum[i][c]=0;continue;}
//			else if(sum[i][c]==4)sum[i][c]-=3,sum[i+1][c]--,sum[i+2][c]--;
//			else if(sum[i][c]<1)return false;
//		}
//	}
//	c='z';
//	for(i=1;i<=7;i++)
//		if(sum[i][c]&&sum[i][c]!=3)return false;
//	return true;
//}
//void sol()
//{
//	int card,cardnum;
//	string tmp;
//	bkup();
//	char c;
//	for(card=0;card<4;card++)
//		for(cardnum=1;cardnum<=num[card];cardnum++)
//		{
//			getbk();
//			c=type[card];
//			sum[cardnum][c]++;
//			pr();
//			if(ck())
//			{
//				ans+='0'+cardnum;
//				ans+=c;
//			}
//		}
//	printf("%d",ans.size()/2);
//	cout<<" "<<ans;
//		puts("");
//}
//int main()
//{
//	int i,x;
//	char c;
//	while(~scanf("%s",str+1))
//	{
//		ans.clear();
//		for(i=1;i<=19;i++)
//			sum[i].clear();
//		for(i=1;i<=13;i++)
//		{
//			x=str[i*2-1]-'0';
//			c=str[i*2];
//			sum[x][c]++;
//		}
//		sum[2]['z']++;
//		pr();
//		printf("%d ",ck());
//		//sol();
//	}
//}
typedef long long lli;
const lli oo=(~0ull)>>1;
int main()
{
	int n;
	while (cin>>n)
	{
		vector<lli> c(n);
		lli sum=0;
		for (int i=0;i<n;i++)
		{
			lli a,b;
			cin>>a>>b;
			c[i]=a-b;
			sum+=c[i];
		}
		if (sum&1) cout<<"NO"<<endl;
		else
		{
			vector<lli> max(n),min(n);
			for (int i=n-2;i>=0;i--)
			{
				if (c[i+1]>=min[i+1])
				{
					if (max[i+1]>=c[i+1]) min[i]=0;
					else min[i]=min[i+1]+c[i+1]-2*max[i+1];
				}
				else min[i]=min[i+1]-c[i+1];
				max[i]=c[i+1]+max[i+1];
				//cout<<min[i]<<endl;
			}
			if (min[0]<=c[0]&&c[0]<=max[0]) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
}
