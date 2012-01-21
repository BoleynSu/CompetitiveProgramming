/*
ID: sujiao1
PROG: sort3
LANG: C++
*/
#include <iostream>
#include <fstream>
using std::endl;
/*
std::istream& cin(std::cin);
std::ostream& cout(std::cout);
*/
std::ifstream cin("sort3.in");
std::ofstream cout("sort3.out");

const int MAXN=1000;
const int MAX=3;
int n;
int a[MAXN+2];
int b[MAXN+2];
int total=0;
int f[MAX+2][MAX+2];

inline 
int min(int a,int b)
{
    return a<b?a:b;
}
inline 
int max(int a,int b)
{
    return a>b?a:b;
}
//#include <time.h>
int main()
{
    //cout<<clock()<<endl;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    //sort
    for (int i=1;i<n;i++)
    {
        for (int j=i+1;j<=n;j++)
        {
            if (b[j]<b[i])
            {
               int s=b[i];
               b[i]=b[j];
               b[j]=s;
            }
        }
    }
    //get f
    for (int i=1;i<=n;i++)
        f[a[i]][b[i]]++;
    /*
    for (int i=1;i<=3;i++)
        for (int j=1;j<=3;j++)
            cout<<"f["<<i<<","<<j<<"]="<<f[i][j]<<endl;
    */
    int step;
    step=min(f[1][2],f[2][1]);
    total+=step;
    f[1][2]-=step;
    f[2][1]-=step;
    step=min(f[1][3],f[3][1]);
    total+=step;
    f[1][3]-=step;
    f[3][1]-=step;
    step=min(f[2][3],f[3][2]);
    total+=step;
    f[2][3]-=step;
    f[3][2]-=step;
    /*
    for (int i=1;i<=3;i++)
        for (int j=1;j<=3;j++)
            cout<<"f["<<i<<","<<j<<"]="<<f[i][j]<<endl;
    */
    step=max(f[2][3],f[3][2]);
    total+=2*step;
    /*
    for (int i=1;i<=3;i++)
        for (int j=1;j<=3;j++)
            cout<<"f["<<i<<","<<j<<"]="<<f[i][j]<<endl;
    */
    cout<<total<<endl;
    //cout<<clock()<<endl;
    return 0;
}
