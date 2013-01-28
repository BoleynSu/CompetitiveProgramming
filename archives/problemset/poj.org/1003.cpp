#include <iostream>
using namespace std;

double sum;
int i;

int main()
{
    for (;;)
    {
        cin>>sum;
        if (sum==0.0) break;
        for (i=2;sum>0;i++)
            sum-=1.0/i;
        cout<<(i-2)<<" card(s)\n";
    }
    return 0;
}
