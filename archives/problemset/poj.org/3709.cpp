#include <iostream>
using namespace std;

const long long int oo=0X19930309*19930309;
const int MAXN=500000+2;
int T;
int n,k;
long long int a[MAXN];
long long int s[MAXN];
long long int f[MAXN];
int q[MAXN];
int head,tail;

int main()
{
    ios::sync_with_stdio(false);
    cin>>T;
    for (int t=0;t<T;t++)
    {
        cin>>n>>k;
        for (int i=1;i<=n;i++) cin>>a[i];
        for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
        f[0]=0;
        q[head=tail=0]=0;
        for (int i=1;i<=n;i++)
        {
            #define value(i,j) ((i-j>=k)?(f[j]+s[i]-s[j]-(i-j)*a[j+1]):(oo))
            #define ky(j,k) (f[j]-f[k]+s[k]-s[j]+(j)*a[j+1]-(k)*a[k+1])
            #define kx(j,k) (a[j+1]-a[k+1])
            if (i-k>0)
            {
               while (head<tail
                      &&ky(q[tail-1],q[tail])*kx(q[tail],i-k)
                        >=kx(q[tail-1],q[tail])*ky(q[tail],i-k))
                     tail--;
               q[++tail]=i-k;
            }
            while (head<tail&&value(i,q[head])>value(i,q[head+1])) head++;
            f[i]=value(i,q[head]);
        }
        cout<<f[n]<<endl;
    }
}
