#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn=200005;
struct node
{
    int left,right;
    int max;
    int lazy;
}t[maxn*4];
int n,m,k;
int d[maxn],sum[maxn];
int max(int a,int b){return (a>b)?a:b;}
void push_up(int i)
{
    t[i].max=max(t[i*2].max,t[i*2+1].max);
}
void push_down(int i)
{
    if(t[i].lazy)
    {
        t[i*2].lazy+=t[i].lazy;
        t[i*2+1].lazy+=t[i].lazy;
        t[i*2].max+=t[i].lazy;
        t[i*2+1].max+=t[i].lazy;
        t[i].lazy=0;
    }
}
void build(int i,int a,int b)
{
    t[i].left=a;t[i].right=b;t[i].lazy=0;
    if(a==b)
    {
        t[i].max=sum[a];return;
    }
    int mid=(a+b)>>1;
    build(i*2,a,mid);
    build(i*2+1,mid+1,b);
    push_up(i);
}
void insert(int i,int a,int b,int data)
{
    push_down(i);
    if(t[i].left==a&&t[i].right==b)
    {
        t[i].max+=data;t[i].lazy+=data;
        return ;
    }
    int mid=(t[i].left+t[i].right)>>1;
    if(b<=mid)insert(i*2,a,b,data);
    else if(a>mid)insert(i*2+1,a,b,data);
    else
    {
        insert(i*2,a,mid,data);
        insert(i*2+1,mid+1,b,data);
    }
    push_up(i);
}
int query(int i,int a,int b)
{
    push_down(i);
    if(t[i].left==a&&t[i].right==b)
    {
        return t[i].max;
    }
    int mid=(t[i].left+t[i].right)>>1;
    if(b<=mid)return query(i*2,a,b);
    else if(a>mid)return query(i*2+1,a,b);
    else return max(query(i*2,a,mid),query(i*2+1,mid+1,b));
}
void solve(int a,int b)//将a位置修改为b
{
    int start=a-k+1,end=a;
    if(start<1)start=1;
    if(end>n-k+1)end=n-k+1;
    insert(1,start,end,-d[a]+b);
    d[a]=b;
}
int main()
{
    //freopen("1.txt","r",stdin);
    int T,op,a,b,i;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d %d",&n,&m,&k);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&d[i]);
        }
  sum[1]=0;
        for(i=1;i<=k;i++)
        sum[1]+=d[i];
  for(i=k+1;i<=n;i++)
   sum[i-k+1]=sum[i-k]+d[i]-d[i-k];
  /*for(i=1;i<=n-k+1;i++)
   cout<<sum[i]<<" ";
  cout<<endl;*/
        build(1,1,n-k+1);
        while(m--)
        {
            scanf("%d %d %d",&op,&a,&b);
            if(op==0)
            {
                solve(a,b);
            }
            else if(op==1)//交换值相当于改变两次
            {
                int v1=d[a],v2=d[b];
                solve(a,v2);
                solve(b,v1);
            }
            else
            {
                printf("%d\n",query(1,a,b-k+1));
            }
        }
    }
    return 0;
}