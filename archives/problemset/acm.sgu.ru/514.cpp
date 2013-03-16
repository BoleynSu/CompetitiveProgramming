#include <iostream>
#include <string>
#include <map>
#include<queue>
#include<cstdio>
#include<algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int n;
int a[11];
int f[1<<11];

void calc(int& ans,int set)
{
	static bool f[1000+1];
	memset(f,0,sizeof(f));
	f[0]=true;
	int sum=0;
	for (int i=0;i<n;i++) if ((set>>i)&1)
	{
		sum+=a[i];
		for (int j=1000;j>=a[i];j--) if (f[j-a[i]]) f[j]=true;
	}
	for (int i=sum/2;i>=0;i--) if (f[i])
	{
		//cout<<i<<"i"<<endl;
		ans=sum-i*2;
		break;
	}
	//cout<<set<<" "<<ans<<endl;
}
double ans=19930309;
void dfs(int aset,int bset,int cset,int dep)
{
	if (dep==n)
	{
		double a=f[aset];
		double b=f[bset];
		double c=f[cset];
		double p=(a+b+c)/2;
		if (a+b>=c&&a+c>=b&&b+c>=a)
		{
			//cout<<aset<<" "<<bset<<" "<<cset<<endl;
			//cout<<a<<" "<<b<<" "<<c<<endl;
			//cout<<p*(p-a)*(p-b)*(p-c)<<endl;
			double get=sqrt(p*(p-a)*(p-b)*(p-c));
			if (get<ans) ans=get;
		}
	}
	else
	{
		dfs(aset|(1<<dep),bset,cset,dep+1);
		dfs(aset,bset|(1<<dep),cset,dep+1);
		dfs(aset,bset,cset|(1<<dep),dep+1);
	}
}

int main()
{
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=0;i<(1<<n);i++) calc(f[i],i);
	dfs(1,0,0,1);
	printf("%.10f\n",ans);
}
