#include <iostream>
using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    long long T;
    cin>>T;
    for (long long t=1;t<=T;t++)
    {
        long long N,S1,V1,S2,V2;
        cin>>N>>S1>>V1>>S2>>V2;
        long long swap;
        if (V1*S2<V2*S1)
            swap=S1,S1=S2,S2=swap,
            swap=V1,V1=V2,V2=swap;
        long long a=S1,b=S2,LCM;
        while (a) swap=a,a=b%a,b=swap;
        LCM=S1/b*S2;
        long long A=N/LCM?N/LCM-1:0;
        long long lcmpart=A*LCM*V1/S1;
        N-=A*LCM;
        if (S1<S2)
        {
            swap=S1,S1=S2,S2=swap;
            swap=V1,V1=V2,V2=swap;
        }
        long long max=0;
        for (long long i1=0;i1*S1<=N;i1++)
        {
            long long i2=(N-S1*i1)/S2;
            if (max<V1*i1+V2*i2) max=V1*i1+V2*i2;
        }
        cout<<"Case #"<<t<<": "<<lcmpart+max<<endl;
    }
}

