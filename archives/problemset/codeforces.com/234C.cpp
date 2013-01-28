#include <cstdio>
#include <iostream>
#include <fstream>
#include <climits>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;


int main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int n;
	cin>>n;
	vector<int> t(n+2),a(n+2),b(n+2);
	for (int i=1;i<=n;i++) cin>>t[i];
	for (int i=1;i<=n;i++) a[i]=a[i-1]+(t[i]>=0);
	for (int i=n;i>=1;i--) b[i]=b[i+1]+(t[i]<=0);
	int ans=min((t[1]>=0)+b[2],(t[n]<=0)+a[n-1]);
	for (int i=2;i<=n-1;i++)
	{
		int get=a[i-1]+b[i+1]+(t[i]==0);
		if (get<ans) ans=get;
	}
	cout<<ans<<endl;
}

