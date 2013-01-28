#include <cstdio>
#include <cstring>
using namespace std;
struct Treap
{
       static const int MAXNODE=100002;
       struct struct_node{struct_node* c[1<<1];int p,s,k;};
       typedef struct_node* node;
       static struct_node pool[MAXNODE];
       static node top;
       node root,null;
       Treap()
       {
              top=pool;
              null=top++;
              null->c[0]=null->c[1]=null;
              null->p=(~0u)>>1;
              null->s=0;
              null->k=0;
              root=null;
       }
       int rand()
       {
           const int a=0x19930309,b=19930309;
           static int c,d;
           c^=d;
           return d=(b*d)+(a^c);
       }
       void resize(node x)
       {
            if (x!=null) x->s=x->c[0]->s+x->c[1]->s+1;
       }
       void rotate(node& x,bool d)
       {
            node y=x->c[!d];
            x->c[!d]=y->c[d];
            y->c[d]=x;
            resize(x),resize(y);
            x=y;
       }
       void insert(node& x,int k)
       {
            if (x==null)
            {
               x=top++;
               while (top==pool+MAXNODE);
               x->c[0]=x->c[1]=null;
               x->p=rand();
               x->k=k;
               resize(x);
            }
            else
            {
                if (x->k==k) return;
                bool d=x->k<k;
                insert(x->c[d],k);
                if (x->c[d]->p<x->p) rotate(x,!d);
                else resize(x);
            }
       }
       void remove(node& x,int k)
       {
            if (x!=null)
            {
               if (x->k==k)
               {
                  if (x->c[0]==null&&x->c[1]==null) x=null;
                  else if (x->c[0]==null) x=x->c[1];
                  else if (x->c[1]==null) x=x->c[0];
                  else
                  {
                      bool d=x->c[0]->p<x->c[1]->p;
                      rotate(x,d);
                      remove(x->c[d],k);
                  }
               }
               else remove(x->c[x->k<k],k);
               resize(x);
            }
       }
       node search(node x,int k)
       {
            if (x==null) return null;
            if (x->k==k) return x;
            else return search(x->c[x->k<k],k);
       }
       node select(node x,int k)
       {
            if (x==null) return x;
            if (x->c[0]->s>=k) return select(x->c[0],k);
            k-=x->c[0]->s;
            if (k==1) return x;
            k-=1;
            return select(x->c[1],k);
       }
       int rank(node x,int k)
       {
           if (x==null) return 0;
           if (k<x->k) return rank(x->c[0],k);
           else if (k==x->k) return x->c[0]->s+1;
           else return x->c[0]->s+1+rank(x->c[1],k);
       }
       void for_each(node x,void (*function)(node))
       {
            if (x==null) return;
            for_each(x->c[0],function);
            function(x);
            for_each(x->c[1],function);
       }
       void insert(int k)
       {
            insert(root,k);
       }
       void remove(int k)
       {
            remove(root,k);
       }
       node search(int k)
       {
            return search(root,k);
       }
       node select(int k)
       {
            return select(root,k);
       }
       int rank(int k)
       {
           return rank(root,k);
       }
       void for_each(void (*function)(node))
       {
            for_each(root,function);
       }
};
Treap::struct_node Treap::pool[Treap::MAXNODE];
Treap::node Treap::top;
typedef Treap::node node;
#include <algorithm>
const int MAXSTEP=20;
const int MAXN=100002;
int sorted[MAXN];
int sortlist[MAXSTEP][MAXN];
int gotoleft[MAXSTEP][MAXN];
void build_RKthQ(int L,int R,int step=0)
{
     if (L!=R)
     {
        int mid=(L+R)>>1;
        int l=L,r=mid+1;
        int nextstep=step+1;
        for (int i=L;i<=R;i++)
        {
            gotoleft[step][i]=i==L?0:gotoleft[step][i-1];
            if (sortlist[step][i]<sorted[mid]) sortlist[nextstep][l++]=sortlist[step][i],gotoleft[step][i]++;
            else if (sortlist[step][i]>sorted[mid]) sortlist[nextstep][r++]=sortlist[step][i];
            else if (l<=mid) sortlist[nextstep][l++]=sortlist[step][i],gotoleft[step][i]++;
            else sortlist[nextstep][r++]=sortlist[step][i];
        }
        build_RKthQ(L,mid,nextstep);
        build_RKthQ(mid+1,R,nextstep);
     }
}
int RKthQ(int L,int R,int l,int r,int k,int step=0)
{
    while (l!=r)
    {
          int mid=(L+R)>>1;
          int lp=(l==L)?0:gotoleft[step][l-1],c=gotoleft[step][r]-lp;
          if (k<=c) R=mid,l=L+lp,r=L+lp+c-1,step++;
          else
          {
              k=k-c,lp=l-L-lp,c=r-l+1-c;
              L=mid+1,l=mid+1+lp,r=mid+1+lp+c-1,step++;
          }
    }
    return sortlist[step][l];
}

enum{MAXQ=100000+35000*3};
bool A[MAXQ];
int s[MAXQ],t[MAXQ],k[MAXQ];
int main()
{
    int N;
    while (scanf("%d",&N)!=EOF)
    {
          Treap T;
          int n=0;
          long long int A1=0,A2=0,A3=0; 
          for (int i=0;i<N;i++)
          {
              char q[1024];
              scanf("%s",q);
              if (strcmp(q,"Insert")==0)
              {
                 scanf("%d",sorted+n);
                 T.insert(sorted[n]);
                 n++;
                 A[i]=false;
              }
              else if (strcmp(q,"Query_1")==0)
              {
                   scanf("%d%d%d",s+i,t+i,k+i);
                   A[i]=true;
              }
              else if (strcmp(q,"Query_2")==0)
              {
                   int x;
                   scanf("%d",&x);
                   A2+=T.rank(x);
                   A[i]=false;
              }
              else
              {
                  int k;
                  scanf("%d",&k);
                  A3+=T.select(k)->k;
                  A[i]=false;
              }
          }
          for (int i=0;i<n;i++) sortlist[0][i]=sorted[i];
          sort(sorted,sorted+n);
          build_RKthQ(0,n-1,0);
          for (int i=0;i<N;i++)
              if (A[i]) A1+=RKthQ(0,n-1,--s[i],--t[i],k[i]);
          static int tc;
          tc++;
          printf("Case %d:\n%I64d\n%I64d\n%I64d\n",tc,A1,A2,A3);
    }
}

