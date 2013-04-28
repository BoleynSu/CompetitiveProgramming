#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using std::sort;

int n;
double x[2000],y[2000];
double lst[2000];

void doit()
{
	n=2000;//scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		double xi,yi;
		xi=rand()%100000,yi=rand();//scanf("%lf%lf",&xi,&yi);
		y[i]=yi/xi,x[i]=xi;
	}
	double pi=acos(-1);
	double dd=pi/180/40;
	double eps=1e-4;
	int ans=0;
	for (double d=pi/2+dd;d<pi;d+=dd)
	{
		double k=tan(d);
		for (int i=0;i<n;i++)
			lst[i]=y[i]-k*x[i];
		sort(lst,lst+n);
		for (int i=0;i<n;i++)
		{
			int j=i;
			while (j+1<n&&lst[j+1]-lst[i]<eps) j++;
			if (j-i+1>ans) ans=j-i+1;
		}
	}
	printf("%d\n",ans);
}

int main()
{
	int t;
	t=10;//scanf("%d",&t);
	while (t--) doit();
}
