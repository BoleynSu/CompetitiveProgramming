/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2011-11-22
DESCRIPTION:
$DESCRIPTION
*/
#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

#define end first
#define begin second
#define segment first
#define id second
typedef pair<double,double> segment;
typedef pair<segment,int> segment_with_id;

int N;
segment_with_id one[10000+1];
double t[2][10000+1];
int rid[10000+1];
int d2ic;
pair<int,int> d2i[20000+2];
int tidc;
int tid[2][10000+1];
double i2d[20000+2];
double f[10000+1];
int pre[10000+1];
int best_id;
int st1[(20000+2)*4];
int st2[(20000+2)*4];
int answerc;
int answer[10000+1];

bool sort_rule(const pair<int,int>& a,const pair<int,int>& b)
{
    return t[a.first][a.second]<t[b.first][b.second];
}
void insert1(int L,int R,int p,int v,int root=1)
{
    if (L<=p&&p<=R)
    {
        if (f[st1[root]]<f[v])
            st1[root]=v;
        if (L==R) return;
        int LL=L,LR=(L+R)>>1,Lroot=root<<1;
        int RL=LR+1,RR=R,Rroot=Lroot|1;
        insert1(LL,LR,p,v,Lroot);
        insert1(RL,RR,p,v,Rroot);
    }
}
int query1(int L,int R,int p,int root=1)
{
    if (p<L) return 0;
    else if (R<=p) return st1[root];
    else
    {
        int LL=L,LR=(L+R)>>1,Lroot=root<<1;
        int RL=LR+1,RR=R,Rroot=Lroot|1;
        int a=query1(LL,LR,p,Lroot),b=query1(RL,RR,p,Rroot);
        return f[a]>f[b]?a:b;
    }
}
void insert2(int L,int R,int p,int v,int root=1)
{
    if (L<=p&&p<=R)
    {
        if (f[st2[root]]-i2d[tid[1][st2[root]]]*2.0<f[v]-i2d[tid[1][v]]*2.0)
            st2[root]=v;
        if (L==R) return;
        int LL=L,LR=(L+R)>>1,Lroot=root<<1;
        int RL=LR+1,RR=R,Rroot=Lroot|1;
        insert2(LL,LR,p,v,Lroot);
        insert2(RL,RR,p,v,Rroot);
    }
}
int query2(int L,int R,int p,int root=1)
{
    if (R<p) return 0;
    else if (p<=L) return st2[root];
    else
    {
        int LL=L,LR=(L+R)>>1,Lroot=root<<1;
        int RL=LR+1,RR=R,Rroot=Lroot|1;
        int a=query2(LL,LR,p,Lroot),b=query2(RL,RR,p,Rroot);
        return f[a]-i2d[tid[1][a]]*2.0>f[b]-i2d[tid[1][b]]*2.0?a:b;
    }
}

int main()
{
    cin>>t[0][0]>>t[1][0]
       >>N;
    d2i[d2ic++]=make_pair(0,0),
    d2i[d2ic++]=make_pair(1,0);
    for (int i=1;i<=N;i++)
    {
        cin>>one[i].segment.begin>>one[i].segment.end;
        one[i].id=i;
    }
    sort(one+1,one+N+1);
    for (int i=1;i<=N;i++)
    {
        t[0][i]=one[i].segment.begin,
        t[1][i]=one[i].segment.end;
        rid[i]=one[i].id;
        d2i[d2ic++]=make_pair(0,i),
        d2i[d2ic++]=make_pair(1,i);
    }
    sort(d2i,d2i+d2ic,sort_rule);
    for (int i=0;i<d2ic;i++)
    {
        if (i&&t[d2i[i].first][d2i[i].second]!=t[d2i[i-1].first][d2i[i-1].second]) tidc++;
        tid[d2i[i].first][d2i[i].second]=tidc;
        i2d[tidc]=t[d2i[i].first][d2i[i].second];
    }
    f[best_id=0]=0;
    for (int i=1;i<=N;i++)
    {
        int npre;
        double nf;
        npre=0;
        nf=i2d[tid[1][i]]-i2d[tid[0][i]];
        if (nf>f[i])
        {
            pre[i]=npre;
            f[i]=nf;
        }
        npre=query1(0,tidc,tid[0][i]);
        nf=i2d[tid[1][i]]-i2d[tid[0][i]]+f[npre];
        if (nf>f[i])
        {
            pre[i]=npre;
            f[i]=nf;
        }
        npre=query2(0,tidc,tid[0][i]);
        nf=f[npre]-i2d[tid[1][npre]]*2.0+i2d[tid[0][i]]+i2d[tid[1][i]];
        if (nf>f[i])
        {
            pre[i]=npre;
            f[i]=nf;
        }
        if (f[i]>f[best_id]) best_id=i;
        insert1(0,tidc,tid[1][i],i);
        insert2(0,tidc,tid[1][i],i);
    }
    if (f[best_id]>=(i2d[tid[1][0]]-i2d[tid[0][0]])*2.0/3.0)
    {
        answer[answerc=1]=best_id;
        while (pre[answer[answerc]])
        {
            answer[answerc+1]=pre[answer[answerc]];
            answerc++;
        }
        cout<<answerc<<endl;
        for (int i=1;i<=answerc;i++)
            cout<<rid[answer[i]]<<endl;
    }
    else cout<<0<<endl;
    return 0;
}
