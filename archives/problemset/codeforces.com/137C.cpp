#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int,int> PII;
typedef vector<PII> VPII;

#define a second
#define b first

int main()
{
    int n;
    cin>>n;
    VPII v(n);
    for (int i=0;i<n;i++)
        cin>>v[i].a>>v[i].b;
    sort(v.begin(),v.end());
    int answer=0;
    for (int i=n-1,min=(~0u)>>1;i>=0;i--)
    {
        if (v[i].a>min) answer++;
        else min=v[i].a;
    }
    cout<<answer<<endl;
    return 0;
}

