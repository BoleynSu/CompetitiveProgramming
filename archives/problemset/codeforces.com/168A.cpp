#include <iostream>
using namespace std;

int main()
{
	const long long int MAX=100000000;
	long long int n,x,y;
	cin>>n>>x>>y;
	long long int L=-1,R=MAX;
	while (L+1!=R)
	{
		int mid=(L+R)>>1;
		if ((x+mid)*100>=y*n) R=mid;
		else L=mid;
	}
	cout<<R<<endl;
}

