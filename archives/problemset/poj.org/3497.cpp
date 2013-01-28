#include <cstdio>
#include <string>
#include <map>
using namespace std;

const int MAXN=1000+2;
const int MAXLENGTH=1024;
const int oo=1000000000+1;
struct C{int t,p,q;};
int n,b;
C c[MAXN];


int main()
{
    int T;
    scanf("%d",&T);
    for (int tc=0;tc<T;tc++)
    {
        map<string,int> s2i;
        scanf("%d%d",&n,&b);
        for (int i=0;i<n;i++)
        {
            char type[MAXLENGTH],name[MAXLENGTH];
            scanf("%s%s%d%d",type,name,&c[i].p,&c[i].q);
            if (s2i.find(type)==s2i.end())
            {
               int s=s2i.size();
               s2i[type]=s;
            }
            c[i].t=s2i[type];
        }
        int L=0,R=+oo;
        while (L+1!=R)
        {
              int mid=(L+R)/2;
              bool possible=true;
              int minp[MAXN];
              for (int i=0;i<s2i.size();i++)
                  minp[i]=+oo;
              for (int i=0;i<n;i++)
              {
                  if (c[i].q>=mid&&c[i].p<minp[c[i].t])
                     minp[c[i].t]=c[i].p;
              }
              int totalp=0;
              for (int i=0;i<s2i.size();i++)
              {
                  totalp+=minp[i]; 
                  if (totalp>b) possible=false;
              }
              if (possible) L=mid;
              else R=mid;
        }
        printf("%d\n",L);
    }
}
