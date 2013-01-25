#include <algorithm>
#include <utility>
#include <iostream>
#include <queue>
#include <map>
using namespace std;

#define P pair<int,int>
#define x first
#define y second

namespace sj
{
          template<unsigned int size>
          class UFSET
          {
                int p[size];
                int rank[size];
                public:
                void MAKE_SET()
                {
                     for (int i=0;i<size;rank[i++]=0) p[i]=i;
                }
                int FIND_SET(int x)
                {
                    if (p[x]==x) return x;
                    else return p[x]=FIND_SET(p[x]);
                }
                bool UNION(int x,int y)
                {
                     x=FIND_SET(x);
                     y=FIND_SET(y);
                     if (x==y) return false;
                     if (rank[x]<rank[y]) p[x]=y;
                     else
                     {
                        p[y]=x;
                        if (rank[x]==rank[y]) rank[x]++;
                     }
                     return true;
                }
          };
}
using namespace sj;

map<P,int> f;
UFSET<1000000> s;
int st;

int main()
{
	int N;
	cin>>N;
	s.MAKE_SET();
	for (int i=0;i<N;i++)
	{
		P a,b;
		int ai,bi;
		cin>>a.x>>a.y>>b.x>>b.y;
		if (f.find(a)==f.end()) f[a]=++st;
		if (f.find(b)==f.end()) f[b]=++st;
		ai=f[a];
		bi=f[b];
		if (!s.UNION(ai,bi))
		{
			cout<<i+1<<endl;
			return 0;
		}
	}
	cout<<0<<endl;
}
