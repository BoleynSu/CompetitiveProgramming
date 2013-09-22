#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int _A,_B,_N;
        scanf("%d%d%d",&_N,&_A,&_B),_N--;
        long long A=_A,B=_B,N=_N;
        if (A<B) swap(A,B);
        long long x=0;
        long long f=0,ans=0;
        for (long long i=0;;i++)
        {
            if (N<=A-1)
            {
                for (long long i=0;i<=N;i++)
                {
                    f+=abs((x+i)%B-i);
                }
                ans+=f;
                break;
            }
            //0->B-x-1
            //x->B-1
            f+=(B-x)*(B-1+x)/2-(B-x)*(B-x-1)/2;
            //printf("f=%lld\n",f);
            //B-x->B-x+kB-1
            //0->B-1 k times
            long long k=(A-1-(B-x))/B;
            f+=(B-x+B-x+k*B-1)*(k*B)/2-(B*(B-1)/2*k);
            //printf("f=%lld\n",f);
            //B-x+kB->A-1
            //0->A-1-(B-x+kB)
            f+=((B-x+k*B)+A-1)*(A-1-(B-x+k*B)+1)/2-(0+A-1-(B-x+k*B))*(A-1-(B-x+k*B)+1)/2;
            //printf("f=%lld\n",f);
            x=(A-1-(B-x+k*B)+1)==B?0:(A-1-(B-x+k*B)+1);
            N-=A-1+1;
            if (x==0)
            {
                ans+=N/(A*(i+1))*f;
                N%=A*(i+1);
            }
            //printf("%d %lld\n",N,f);
        }
        cout<<ans<<endl;//printf("%lld\n",ans);
    }
}
