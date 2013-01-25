#include <algorithm>
#include <utility>
#include <iostream>
#include <queue>
using namespace std;

#define q first
#define p first
#define id second.first
#define n second.second
#define w second.second

int K;
pair<int,pair<int,int> > z[100];
int N;
pair<int,pair<int,int> > s[16000];
int Z[16000];

int main()
{
	cin>>K;
	for (int i=0;i<K;i++) cin>>z[i].n,N+=z[i].n,z[i].id=i;
	for (int i=0;i<K;i++) cin>>z[i].q;
	for (int i=0;i<N;i++) cin>>s[i].p,s[i].id=i;
	for (int i=0;i<N;i++) cin>>s[i].w;
	sort(z,z+K,greater<pair<int,pair<int,int> > >());
	sort(s,s+N,greater<pair<int,pair<int,int> > >());
	int i,j;
	for (i=0,j=0;i<K;i++)
	{
		priority_queue<pair<int,pair<int,int> > > q;
		while (s[j].p>z[i].q&&j<N)
		{
			q.push(make_pair(s[j].w,make_pair(s[j].id,s[j].p)));
			j++;
		}
		while (z[i].n&&!q.empty())
		{
			Z[q.top().id]=z[i].id;
			z[i].n--;
			q.pop();
		}
		while (!q.empty())
		{
			j--;
			s[j].w=q.top().p;
			s[j].p=q.top().w;
			s[j].id=q.top().id;
			q.pop();
		}
	}
	i=0;
	while (j<N)
	{
		while (z[i].n&&j<N) Z[s[j].id]=z[i].id,j++,z[i].n--;
		i++;
	}
	for (int i=0;i<N;i++)
		cout<<Z[i]+1<<char(i+1==N?'\n':' ');
}
