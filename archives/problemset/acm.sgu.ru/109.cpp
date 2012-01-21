/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2011-12-03
DESCRIPTION:
$DESCRIPTION
*/
#include <iostream>
using namespace std;

int main()
{
    int N;
    cin>>N;
    int K=N;
    cout<<K;
    for (int x=1;x<=N;x++)
        for (int y=1;y<=N;y++)
            if (x+y>=N+3)
               cout<<" "<<(x-1)*N+y;
    cout<<endl;
    for (int XpY=N+2;XpY>2;XpY--)
    {
        while ((++K)%2==0);
        cout<<K;
        for (int x=1;x<=N;x++)
            for (int y=1;y<=N;y++)
                if (x+y==XpY)
                   cout<<" "<<(x-1)*N+y;
        cout<<endl;
    }
    return 0;
}
