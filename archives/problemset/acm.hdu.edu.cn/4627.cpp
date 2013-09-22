#include <cstdio>
#include <iostream>
using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define rep(i,n) for (int i=0;i<(n);i++)
#define sz(x) (int((x).size()))

const int MOD=1000000007;

int gcd(int a,int b)
{
    return a?gcd(b%a,a):b;
}

int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        long long n;
        cin>>n;
        for (long long i=n/2;i<=n;i++)
        {
            if (gcd(n,i)==1)
            {
                cout<<i*(n-i)<<endl;
                break;
            }
        }
    }
}
