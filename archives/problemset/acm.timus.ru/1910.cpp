#include <iostream>
#include <cstdio>
using namespace std;

int n;
int a[1000000+2];
int sum;
int ans,ansi;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",a+i);
	for (int i=1;i<3;i++) sum+=a[i];
	for (int i=3;i<=n;i++)
	{
		sum+=a[i]-a[i-3];
		if (sum>ans) ans=sum,ansi=i-1;
	}
	printf("%d %d\n",ans,ansi);
}
