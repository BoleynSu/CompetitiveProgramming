#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	double a,d;
	cin>>n>>a>>d;
	vector<double> t(n),v(n);
	for (int i=0;i<n;i++)
		cin>>t[i]>>v[i];
	double answer=0;
	for (int i=0;i<n;i++)
	{
        double t0=v[i]/a;
        if (a*t0*t0/2.0>d) answer=max(answer,t[i]+sqrt(d*2.0/a));
        else answer=max(answer,t[i]+t0+(d-a*t0*t0/2.0)/v[i]);
        printf("%.6f\n",answer);
    }
}

