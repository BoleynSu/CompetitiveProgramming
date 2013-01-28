#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

int S[1000000];
int L[1000000];
int answer[1000000];
pair<pair<int,int>,int> q[1000000];
pair<int,int> pq[1000000];
int Lst[1000000];
int Sst[1000000];

void insert(int* st,int L,int R,int p,int v,int root=1)
{
     if (p<=L&&R<=p) st[root]=v;
     else if (p<L||R<p) ;
     else
     {
         int LL=L,LR=(L+R)>>1,Lroot=root<<1;
         int RL=LR+1,RR=R,Rroot=Lroot|1;
         insert(st,LL,LR,p,v,Lroot);
         insert(st,RL,RR,p,v,Rroot);
         st[root]=max(st[Lroot],st[Rroot]);
     }
}
int query(int* st,int L,int R,int l,int r,int root=1)
{
    if (l<=L&&R<=r) return st[root];
    else if (r<L||R<l) return 0;
    else
    {
        int LL=L,LR=(L+R)>>1,Lroot=root<<1;
        int RL=LR+1,RR=R,Rroot=Lroot|1;
        return max(query(st,LL,LR,l,r,Lroot),query(st,RL,RR,l,r,Rroot));
    }
}

int main()
{
    int N,M;
    while (~scanf("%d",&N))
    {
          map<int,int> pre;
          for (int i=1;i<=N;i++)
          {
              scanf("%d",&S[i]);
              L[i]=min(i-pre[S[i]],L[i-1]+1);
              pre[S[i]]=i;
          }
          scanf("%d",&M);
          for (int i=0;i<M;i++)
          {
              int a,b;
              scanf("%d%d",&a,&b);
              if (a>b) swap(a,b);
              q[i]=make_pair(make_pair(a,b),i);
          }
          sort(q,q+M);
          int top=0;
          for (int i=1;i<=N;i++)
              pq[top++]=make_pair(i-L[i],i);
          sort(pq,pq+top);
          top--;
          
          for (int i=1;i<=N;i++) insert(Sst,1,N,i,i),insert(Lst,1,N,i,0);
          
          for (int i=M-1;i>=0;i--)
          {
              int a=q[i].first.first,b=q[i].first.second,id=q[i].second;
              while (top>=0&&pq[top].first>a-1)
              {
                    int i=pq[top].second;
                    insert(Lst,1,N,i,L[i]);
                    insert(Sst,1,N,i,0);
                    top--;
              }
              answer[id]=max(query(Lst,1,N,a,b),query(Sst,1,N,a,b)-a+1);
          }
          for (int i=0;i<M;i++) printf("%d\n",answer[i]);
    }
    return 0;
}

