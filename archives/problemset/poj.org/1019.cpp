#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAXK=35276;
unsigned int length_of_s[MAXK];
unsigned int sum[MAXK];


int length_of(int i)
{
    if (i>=10000) return 5;
    if (i>=1000) return 4;
    if (i>=100) return 3;
    if (i>=10) return 2;
    if (i>=1) return 1;
}
int f(int i)
{
    if (i==1) return 1;
    if (i==2) return 10;
    if (i==3) return 100;
    if (i==4) return 1000;
    if (i==5) return 10000;
}

int get(int i)
{
    int find;
    find=(lower_bound(sum,sum+MAXK,i)-sum)-1;
    i-=sum[find];
    find=(lower_bound(length_of_s,length_of_s+MAXK,i)-length_of_s)-1;
    i-=length_of_s[find];
    return int((find+1)/f(length_of(find+1)+1-i))%10;
}

int main()
{
    for (int i=1;i<MAXK;i++)
        sum[i]=sum[i-1]+(length_of_s[i]=length_of_s[i-1]+length_of(i));
    int T;
    cin>>T;
    for (int t=1;t<=T;t++)
    {
        int i;
        cin>>i;
        cout<<get(i)<<endl;
    }
    return 0;
}
