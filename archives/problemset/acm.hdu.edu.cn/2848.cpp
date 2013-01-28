#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

unsigned long long N;
int K;
map<unsigned long long,bool> f;
unsigned long long ce[20];
bool win(unsigned long long N);
bool cut(unsigned long long N,int p=0,unsigned long long sum=0,int c=0)
{
    if (c==K) return N<ce[p]&&!win(sum);
    if (N/ce[p]>=ce[K-c-1])
        for (int i=p;ce[i]<=N;i++)
            if (cut(N,i+1,sum+(N/ce[p])%ce[i-p+1],c+1))
                return true;
    return false;
}
bool win(unsigned long long N)
{
    map<unsigned long long,bool>::iterator it=f.find(N);
    if (it==f.end())
    {
        if (N<ce[K-1]) it=f.insert(make_pair(N,false)).first;
        else
        {
            bool result=cut(N);
            it=f.insert(make_pair(N,result)).first;
        }
    }
    return it->second;
}

int main()
{
    ce[0]=1;
    for (int i=1;i<20;i++) ce[i]=10*ce[i-1];
    while (cin>>N>>K)
    {
        f.clear();
        cout<<win(N)<<endl;
    }
}

