/*
ID: sujiao1
PROG: milk
LANG: C++
*/
#include <iostream>
#include <fstream>
using std::endl;
/*
std::istream& cin(std::cin);
std::ostream& cout(std::cout);
*/
std::ifstream cin("milk.in");
std::ofstream cout("milk.out");

int n,m;
int a[10000];
int p[10000];
double k[10000];
bool mark[10000];
int main()
{
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        cin>>p[i]>>a[i];
    }
    int get=0;
    int total=0;
    while (get<n)
    {
    int min=20000000;
    int minid;
    for (int i=1;i<=m;i++)
    {
        if ((!mark[i])&&(p[i]<min))
        {
           min=p[i];
           minid=i;
        }
    }
    mark[minid]=true;
    //cout<<minid<<"min"<<endl;
    if (get+a[minid]<=n)
    {
       get+=a[minid];
       total+=a[minid]*p[minid];
    }
    else
    {
        total+=(n-get)*p[minid];
        get=n;
    }
    }
    cout<<total<<endl;
    //while (cin.get());
    return 0;
}
