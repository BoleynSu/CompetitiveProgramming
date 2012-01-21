/*
ID: sujiao1
PROG: milk3
LANG: C++
*/
#include <iostream>
#include <fstream>
using std::endl;
/*
std::istream& cin(std::cin);
std::ostream& cout(std::cout);
*/
std::ifstream cin("milk3.in");
std::ofstream cout("milk3.out");

const int MAXN=20;//1 to 20
int A,B,C;
bool f[MAXN+2][MAXN+2];
bool mark[MAXN+2][MAXN+2];

void mdfs(int a,int b)
{
     //cout<<a<<" "<<b<<endl;
     int c=C-a-b;
     if ((a<0)||(b<0)||(c<0)||(a>A)||(b>B)||(c>C)||mark[a][b]) return;
     else
     {
     f[a][b]=true;
     mark[a][b]=true;
     int da=A-a;
     int db=B-b;
     int dc=C-c;
     mdfs(A,b-da);
     mdfs(A,b);
     mdfs(a-db,B);
     mdfs(a,B);
     mdfs(a-dc,b);
     mdfs(a,b-dc);
     mdfs(0,b);
     mdfs(0,b+a);
     mdfs(a,0);
     mdfs(a+b,0);
     mdfs(a+c,b);
     mdfs(a,b+c);
     }
}
int main()
{
    cin>>A>>B>>C;
    mdfs(0,0);
    for (int i=0;i<C;i++)
    {
        if (f[0][C-i]) cout<<i<<" ";
    }
    cout<<C<<endl;
    return 0;
}
