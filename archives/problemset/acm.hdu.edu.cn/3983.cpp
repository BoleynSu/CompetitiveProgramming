#include <cstdio>
#include <map>
#include <cstring>
using namespace std;

typedef long long int lli;
enum{MAXBITLENGTH=17};
lli delta;
map<lli,lli> count;
lli* st[MAXBITLENGTH+1];
#define R(x) ((1<<(x+1))-1)

void inc(lli i,lli x,lli value)
{
     for (;x<=(1<<(i+1));x+=(x)&(-x)) st[i][x]+=value;
}
lli sum(lli i,lli x)
{
    lli value=0;
    for (;x;x-=(x)&(-x)) value+=st[i][x];
    return value;
}

int main()
{
    for (lli i=0;i<=MAXBITLENGTH;i++)
        st[i]=new lli[(1<<(i+1))+1];
    lli T;
    scanf("%I64d",&T);
    for (lli t=1;t<=T;t++)
    {
        delta=0;
        count.clear();
        for (lli i=0;i<=MAXBITLENGTH;i++)
            memset(st[i],0,((1<<(i+1))+1)*sizeof(lli));
        printf("Case %I64d:\n",t);
        lli M;
        scanf("%I64d",&M);
        for (lli i=0;i<M;i++)
        {
            char cmd[1024];
            lli M;
            scanf("%s%I64d",cmd,&M);
            switch (cmd[0])
            {
            case 'I':
                if (count.find(M-delta)!=count.end()) count[M-delta]++;
                else count[M-delta]=1;
                for (lli i=0;i<=MAXBITLENGTH;i++)
                {
                    lli x=(M-delta)&R(i);
                    inc(i,x+1,1);
                }
                break;
            case 'D':
                if (count.find(M-delta)!=count.end())
                {
                    for (lli i=0;i<=MAXBITLENGTH;i++)
                    {
                        lli x=(M-delta)&R(i);
                        inc(i,x+1,-count[M-delta]);
                    }
                    count.erase(M-delta);
                }
                else puts("Del error");
                break;
            case 'A':
                delta+=M;
                break;
            case 'S':
                if (count.begin()!=count.end()&&count.begin()->first+delta-M<0) puts("Sub error");
                else delta-=M;
                break;
            case 'Q':
                if (cmd[1]=='N')
                {
                    if (count.find(M-delta)!=count.end())
                        printf("%I64d\n",count[M-delta]);
                    else
                        puts("0");
                }
                else
                {
                    lli l=((1<<M)-delta)&R(M);
                    lli r=(((1<<(M+1))-1)-delta)&R(M);
                    lli L=0,R=(1<<(M+1))-1;
                    if (l<=r) printf("%I64d\n",sum(M,r+1)-sum(M,l));
                    else printf("%I64d\n",sum(M,R+1)-sum(M,l)+sum(M,r+1)-sum(M,L));
                }
                break;
            }
        }
        printf("\n");
    }
}

