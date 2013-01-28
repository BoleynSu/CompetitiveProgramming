#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	int a,b;
	while (cin>>a>>b)
	{
		if (a>b) swap(a,b);
		if (int((b-a)*(sqrt(5.0)+1.0)/2.0)==a) cout<<"0"<<endl;
		else cout<<"1"<<endl;
	}
}
