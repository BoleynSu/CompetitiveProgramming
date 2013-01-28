/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2011-11-09
DESCRIPTION:
$DESCRIPTION
*/
#include <iostream>
using namespace std;
 
bool calced[51][51][51][51];
bool f[51][51][51][51];
int F(int a,int b,int c,int d)
{
    if (!calced[a][b][c][d])
    {
       if (a>=1&&!F(a-1,b,c,d)) f[a][b][c][d]=true;
       if (b>=1&&!F(a+1,b-1,c,d)) f[a][b][c][d]=true;
       if (c>=1&&!F(a,b+1,c-1,d)) f[a][b][c][d]=true;
       if (d>=1&&!F(a,b,c+1,d-1)) f[a][b][c][d]=true;
      
       if (a>=2&&!F(a-2,b+1,c,d)) f[a][b][c][d]=true;
       if (b>=2&&!F(a,b-2,c,d+1)) f[a][b][c][d]=true;
       if (c>=2&&!F(a,b,c-2,d+1)) f[a][b][c][d]=true;
       if (d>=2&&!F(a,b,c,d-2+1)) f[a][b][c][d]=true;
      
       if (a>=1&&b>=1&&!F(a-1,b-1,c+1,d)) f[a][b][c][d]=true;
       if (a>=1&&c>=1&&!F(a-1,b,c-1,d+1)) f[a][b][c][d]=true;
       if (a>=1&&d>=1&&!F(a-1,b,c+1,d-1)) f[a][b][c][d]=true;
       if (b>=1&&c>=1&&!F(a,b-1,c-1+1,d)) f[a][b][c][d]=true;
       if (b>=1&&d>=1&&!F(a,b-1,c,d-1+1)) f[a][b][c][d]=true;
       if (c>=1&&d>=1&&!F(a,b,c-1+1,d-1)) f[a][b][c][d]=true;
      
       calced[a][b][c][d]=true;
    }
    return f[a][b][c][d];
}
 
int main()
{
    int TC;
    cin>>TC;
    for (int tc=1;tc<=TC;tc++)
    {
        int N,a=0,b=0,c=0,d=0;
        cin>>N;
        for (int i=0;i<N;i++)
        {
            int t;
            cin>>t;
            if (t==1) a++;
            else if (t==2) b++;
            else if (t%2==1) c++;
            else d++;
        }
        cout<<"Case #"<<tc<<": "<<(F(a,b,c,d)?"Alice":"Bob")<<endl;
    }
    return 0;
}
 

