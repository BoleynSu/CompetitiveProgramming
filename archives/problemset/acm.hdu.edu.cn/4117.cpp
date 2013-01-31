/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2011-11-10
DESCRIPTION:
$DESCRIPTION
*/
#include <cstdio>
#include <cstring>
using namespace std;

namespace sujiaos_lab
{
const int LOG2_MAXLENGTH=19;
const int MAXLENGTH=320003;
const int MAXALPHABET=129;
typedef char string[MAXLENGTH];
typedef int* int_pointer;
int_pointer sort;
int _SA[MAXLENGTH],_rank[MAXLENGTH],_TSA[MAXLENGTH],_Trank[MAXLENGTH];
int_pointer SA=_SA,rank=_rank,TSA=_TSA,Trank=_Trank;
void get_SA(string s,int length)
{
     sort=Trank;
     for (int i=0;i<MAXALPHABET;i++) sort[i]=0;
     for (int i=1;i<=length;i++) sort[s[i]]++;
     for (int i=1;i<MAXALPHABET;i++) sort[i]+=sort[i-1];
     for (int i=1;i<=length;i++) SA[sort[s[i]]--]=i;
     rank[SA[1]]=1;
     for (int i=2;i<=length;i++)
         if (s[SA[i]]==s[SA[i-1]]) rank[SA[i]]=rank[SA[i-1]];
         else rank[SA[i]]=rank[SA[i-1]]+1;
     for (int block=1;rank[SA[length]]!=length;block<<=1)
     {
         sort=Trank;
         for (int i=1;i<=length;i++) sort[rank[SA[i]]]=i;
         for (int i=length;i>=1;i--)
             if (SA[i]-block>=1)
                TSA[sort[rank[SA[i]-block]]--]=SA[i]-block;
         for (int i=length-block+1;i<=length;i++)
             TSA[sort[rank[i]]--]=i;
         int_pointer swap;
         swap=SA,SA=TSA,TSA=swap;
         swap=rank,rank=Trank,Trank=swap;
         rank[SA[1]]=1;
         for (int i=2;i<=length;i++)
             if (Trank[SA[i]]==Trank[SA[i-1]]
                &&Trank[SA[i]+block]==Trank[SA[i-1]+block])
                rank[SA[i]]=rank[SA[i-1]];
             else rank[SA[i]]=rank[SA[i-1]]+1;
     }
}
int_pointer height;
void get_height(string s,int length)
{
     height=TSA;
     for (int i=1,h=0;i<=length;i++)
     {
         if (h) h--;
         if (rank[i]!=1)
         {
            int j=SA[rank[i]-1];
            while (s[i+h]==s[j+h]) h++;
         }
         height[rank[i]]=h;
     }
}
int_pointer log2;
int rmq[LOG2_MAXLENGTH][MAXLENGTH];
void get_RMQ(int length)
{
     log2=Trank;
     log2[1]=0;
     for (int i=2;i<=length;i++) log2[i]=log2[i-1]+(i==(i&(-i)));
     for (int i=1;i<=length;i++) rmq[0][i]=i;
     for (int log=1;log<=log2[length];log++)
     {
         int exp=1<<log,exp_div_2=exp>>1;
         for (int i=1;i<=length-exp+1;i++)
         {
             int a=rmq[log-1][i];
             int b=rmq[log-1][i+exp_div_2];
             rmq[log][i]=height[a]<height[b]?a:b;
         }
     }
}
int RMQ(int a,int b)
{
    int log=log2[b-a+1];
    int exp=1<<log;
    a=rmq[log][a],b=rmq[log][b-exp+1];
    return height[a]<height[b]?a:b;
}
int LCP(int a,int b)
{
    a=rank[a],b=rank[b];
    if (a>b) return height[RMQ(b+1,a)];
    else return height[RMQ(a+1,b)];
}
}
using namespace sujiaos_lab;
const int MAXN=20003;
sujiaos_lab::string s;
int W[MAXN];
int p[MAXN];
int len[MAXN];

const int MAXNODE=MAXLENGTH*4+1;
int st[MAXNODE];
void insert(int p,int value,int L,int R,int root=1)
{
     if (p<L||R<p) return;
     else
     {
         if (value>st[root])
            st[root]=value;
         if (L==R) return;
         int LL=L,LR=(L+R)>>1,Lroot=root<<1,
             RL=LR+1,RR=R,Rroot=Lroot|1;
         insert(p,value,LL,LR,Lroot);
         insert(p,value,RL,RR,Rroot);
     }
}
int query(int l,int r,int L,int R,int root=1)
{
    if (r<L||R<l||L>R) return 0;
    else if (l<=L&&R<=r) return st[root];
    else
    {
        int LL=L,LR=(L+R)>>1,Lroot=root<<1,
            RL=LR+1,RR=R,Rroot=Lroot|1;
        int LV=query(l,r,LL,LR,Lroot);
        int RV=query(l,r,RL,RR,Rroot);
        return LV>RV?LV:RV;
    }
}
int main()
{
    int TC;
    scanf("%d",&TC);
    for (int tc=1;tc<=TC;tc++)
    {
        int N;
        scanf("%d",&N);
        for (int i=1;i<=N;i++)
        {
            p[i]=p[i-1]+len[i-1];
            s[p[i]++]='#';
            scanf("%s%d",s+p[i],&W[i]);
            len[i]=strlen(s+p[i]);
        }

        int length=strlen(s);
        get_SA(s,length);
        get_height(s,length);
        get_RMQ(length);

        int answer=0;
        memset(st,0,sizeof(st));
        for (int i=N;i>=1;i--)
        {
            int L,R,l,r;
            L=0,R=rank[p[i]];
            while (L+1!=R)
            {
                  int mid=(L+R)>>1;
                  if (height[RMQ(mid+1,rank[p[i]])]>=len[i]) R=mid;
                  else L=mid;
            }
            l=R;
            L=rank[p[i]],R=length+1;
            while (L+1!=R)
            {
                  int mid=(L+R)>>1;
                  if (height[RMQ(rank[p[i]]+1,mid)]>=len[i]) L=mid;
                  else R=mid;
            }
            r=L;
            int get=query(l,r,1,length)+W[i];
            if (get>answer) answer=get;
            for (int j=0;j<len[i];j++)
                insert(rank[p[i]+j],get,1,length);
        }
        printf("Case #%d: %d\n",tc,answer);
    }
}
