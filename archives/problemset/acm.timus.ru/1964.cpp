#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

#define rep(i,n) for (int i=0;i<int(n);i++)
#define pb push_back
#define mp make_pair
typedef vector<int> vi;
typedef long long int lli;

int main()
{
//	lli n,m,N;
//	cin>>n>>m>>N;
//	lli M0=N*m/n;
//	lli M1=N*m/n;
//	if (m*N-M0*n<M1*n-m*N) cout<<M0<<endl;
//	else cout<<M1<<endl;
	lli n,k;
	cin>>n>>k;
	vector<lli> a(k);
	rep(i,k) cin>>a[i];
	lli delta=0;
	rep(i,k) delta+=n-a[i];
	cout<<max(n-delta,0ll)<<endl;
}