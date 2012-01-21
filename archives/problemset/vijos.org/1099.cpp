#include <iostream>
using namespace std;

#define have(__N__) ((f[__N__[s]])!=-1)
#define get(__N__) (f[__N__[s]])
#define what(__N__) (__N__[s])
typedef char String[1024];
void _trya(int);
void _tryb(int);
void _tryc(int);

int n;
String a,b,c;
int f['Z'+1];
char g[26+1];
void print()
{
     for (int i=0;i<n;i++)
         cout<<f['A'+i]<<" ";
     cout<<endl;
     exit(0);
}
bool check(int pos)
{
     int up=0;
     for (int s=n;s>pos;s--)
     {
         int get=get(a)+get(b)+up;
         if ((get%n)!=get(c)) return false;
         up=get/n;
     }
     for (int s=pos;s>=1;s--)
         if (have(a)&&have(b)&&have(c))
            if ((((get(a)+get(b)+1)%n)!=get(c))&&(((get(a)+get(b))%n)!=get(c)))
               return false;
     return true;
}
void _trya(int s)
{
     if (s==0) print();
     if (have(a))
     {
        if (check(s))
           _tryb(s);
     }
     else
         for (int v=n-1;v>=0;v--)
             if (g[v]==0)
             {
                g[v]=what(a);
                get(a)=v;
                if (check(s))
                   _tryb(s);
                get(a)=-1;
                g[v]=0;
             }
}
void _tryb(int s)
{
     if (have(b))
     {
        if (check(s))
           _tryc(s);
     }
     else
         for (int v=n-1;v>=0;v--)
             if (g[v]==0)
             {
                g[v]=what(b);
                get(b)=v;
                if (check(s))
                   _tryc(s);
                get(b)=-1;
                g[v]=0;
             }
}
void _tryc(int s)
{
     if (have(c))
     {
        if (check(s))
           _trya(s-1);
     }
     else
         for (int v=n-1;v>=0;v--)
             if (g[v]==0)
             {
                g[v]=what(c);
                get(c)=v;
                if (check(s))
                   _trya(s-1);
                get(c)=-1;
                g[v]=0;
             }
}
int main()
{
    cin>>n>>&a[1]>>&b[1]>>&c[1];
    memset(f,-1,sizeof(f));
    _trya(n);
    return 0;
}
