#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

typedef long long int lli;

int main()
{
    lli n;
    cin>>n;
    lli k[n],c[n],tk=0;
    for (lli i=0;i<n;i++)
        cin>>k[i]>>c[i],
        tk+=k[i];
    lli t;
    cin>>t;
    lli p[t+1];
    for (lli i=0;i<t;i++)
        cin>>p[i];
    p[t]=tk;
    for (lli i=t;i>=1;i--)
        p[i]-=p[i-1];
    lli id[n];
    for (lli i=0;i<n;i++)
        id[i]=i;
    for (lli i=0;i<n;i++)
        for (lli j=i+1;j<n;j++)
            if (c[id[i]]>c[id[j]])
            {
               lli swap=id[i];
               id[i]=id[j];
               id[j]=swap;
            }
    lli answer=0;
    for (lli i=0,j=0;i<n;i++)
        while (k[id[i]])
        {
              while (!p[j]) j++;
              lli delta=min(k[id[i]],p[j]);
              answer+=delta*c[id[i]]*(j+1);
              k[id[i]]-=delta;
              p[j]-=delta;
        }
    cout<<answer<<endl;
}

