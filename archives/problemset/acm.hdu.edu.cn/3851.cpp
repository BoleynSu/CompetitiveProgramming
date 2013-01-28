#include <iostream>
using namespace std;

const long long int MAXN=1000+2;
const long long int MAXT=10000000+2;

long long int Q;
long long int N,T,PD,PN;
long long int T1[MAXN],T2[MAXN];
long long int _f[MAXT];

int main()
{
    cin>>Q;
    for (int q=1;q<=Q;q++)
    {
        cin>>N>>T>>PD>>PN;
        for (int i=0;i<N;i++)
            cin>>T1[i]>>T2[i];
        
        long long int* f=_f+T;
        for (int i=-T;i<=0;i++) f[i]=0;
        
        int now=0;
        
        long long int delta=0;
        for (int i=0;i<N;i++)
        {
            long long int ch;
            
            if (T1[i]/T>=2) ch=T1[i]%T+T*2;
            else ch=T1[i];
            delta+=(T1[i]-ch)/T*PD;
            T1[i]=ch;
            
            if (T2[i]/T>=2) ch=T2[i]%T+T*2;
            else ch=T2[i];
            delta+=(T2[i]-ch)/T*PN;
            T2[i]=ch;
        }
        
        for (int i=0;i<N;i++)
        {
            /*
            for (int j=0;j<T1[i];j++)
            {
                now++;
                f[now%9000000]=f[(now-1)%9000000];
                if (f[now%9000000]<f[(now-T)%9000000]+PD) f[now%9000000]=f[(now-T)%9000000]+PD;
            }
            for (int j=0;j<T2[i];j++)
            {
                now++;
                f[now%9000000]=f[(now-1)%9000000];
                if (f[now%9000000]<f[(now-T)%9000000]+PN) f[now%9000000]=f[(now-T)%9000000]+PN;
            }
            */
            for (int j=0;j<T1[i];j++)
            {
                now++;
                f[now]=f[now-1];
                if (f[now]<f[now-T]+PD) f[now]=f[now-T]+PD;
            }
            
            for (int j=0;j<T2[i];j++)
            {
                now++;
                f[now]=f[now-1];
                if (f[now]<f[now-T]+PN) f[now]=f[now-T]+PN;
            }
        }
        cout<<"Case "<<q<<": "<<f[now]+delta<<endl;
    }
}

