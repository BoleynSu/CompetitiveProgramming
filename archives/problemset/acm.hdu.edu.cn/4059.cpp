#include <iostream>
using namespace std;

typedef long long int lli;
const lli MODER=1000000007;
const lli MAXLISTS=100;
lli N,answer;
lli lists;
lli list[MAXLISTS];

lli f(lli N)
{
    const lli LENGTH=6;
    lli big[LENGTH],tmp[LENGTH];
    for (lli i=0;i<LENGTH;i++) big[i]=0;
    big[0]+=6;
    for (lli i=0;i<LENGTH;i++) tmp[i]=0;
    for (lli i=0;i<LENGTH;i++)
    {
        tmp[i]+=big[i]*N%MODER;
        if (big[i]*N/MODER) tmp[i+1]=big[i]*N/MODER;
        big[i]=tmp[i];
    }
    big[0]+=9;
    for (lli i=0;i<LENGTH;i++) tmp[i]=0;
    for (lli i=0;i<LENGTH;i++)
    {
        tmp[i]+=big[i]*N%MODER;
        if (big[i]*N/MODER) tmp[i+1]=big[i]*N/MODER;
        big[i]=tmp[i];
    }
    big[0]+=1;
    for (lli i=0;i<LENGTH;i++) tmp[i]=0;
    for (lli i=0;i<LENGTH;i++)
    {
        tmp[i]+=big[i]*N%MODER;
        if (big[i]*N/MODER) tmp[i+1]=big[i]*N/MODER;
        big[i]=tmp[i];
    }
    big[0]+=-1;
    for (lli i=0;i<LENGTH;i++) tmp[i]=0;
    for (lli i=0;i<LENGTH;i++)
    {
        tmp[i]+=big[i]*N%MODER;
        if (big[i]*N/MODER) tmp[i+1]=big[i]*N/MODER;
        big[i]=tmp[i];
    }
    for (lli i=0;i<LENGTH;i++) tmp[i]=0;
    for (lli i=0;i<LENGTH;i++)
    {
        tmp[i]+=big[i]*(N+1)%MODER;
        if (big[i]*(N+1)/MODER) tmp[i+1]=big[i]*(N+1)/MODER;
        big[i]=tmp[i];
    }
    for (lli i=LENGTH-1;i>=0;i--)
    {
        if (i!=0) big[i-1]+=(big[i]%30)*MODER;
        big[i]/=30;
    }
    return big[0];
}
lli F(lli N)
{
    return ((N*N)%MODER)*((N*N)%MODER)%MODER;
}
void dfs(lli i=0,lli g=0,lli n=1)
{
    if (i==lists)
    {
       if ((lists-g)%2==0) answer+=f(N/n)*F(n);
       else answer-=f(N/n)*F(n);
       answer=((answer%MODER)+MODER)%MODER;
    }
    else dfs(i+1,g+1,n),dfs(i+1,g,n*list[i]);
}

int main()
{
    lli T;
    cin>>T;
    for (lli t=0;t<T;t++)
    {
        cin>>N;
        lists=0;
        for (lli i=2,j=N;j!=1;i++)
        {
            if (i*i>N) i=j;
            if (j%i==0)
            {
               list[lists++]=i;
               while (j%i==0) j/=i;
            }
        }
        answer=0;
        dfs();
        cout<<answer<<endl;
    }
}

