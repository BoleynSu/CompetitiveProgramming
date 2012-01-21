/*
AUTHOR: Su Jiao
DATE: 2010-8-24
DESCRIPTION:
$DESCRIPTION
*/
#include <iostream>
using namespace std;

int main()
{
    int N,answer=0;
    cin>>N;
    for (int i=1;i<=N;i++)
    {
        int a=N,b=i,t;
        while (b) t=a,a=b,b=t%b;
        if (a==1) answer++;
    }
    cout<<answer<<endl;
}
