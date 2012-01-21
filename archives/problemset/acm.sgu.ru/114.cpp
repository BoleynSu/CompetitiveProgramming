#include <cstdio>
#include <cmath>
#include <cassert>
#include <utility>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	scanf("%d",&N);
	pair<double,double> info[N];
	for (int i=0;i<N;i++)
	{
		scanf("%lf%lf",&info[i].first,&info[i].second);
	}
	sort(info,info+N);
	double sum=0.0;
	for (int i=0;i<N;i++) sum+=info[i].second;
	double get=0.0;
	for (int i=0;i<N;i++)
	{
		get+=info[i].second;
		if (get>sum*0.5)
		{
			printf("%.5f\n",info[i].first);
			break;
		}
	}
}
