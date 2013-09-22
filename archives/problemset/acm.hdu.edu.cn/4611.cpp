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
//
//const int N=50200;
//struct node
//{
//    int size,s,l,r;
//    node *c[2];
//}mem[N*2];
//node *root,*cur;
//int n,m;
//int L,R;
//inline void pushdown(node *x)
//{
//    if(x->size==x->s)
//    {
//        x->c[0]->s=x->c[0]->size;
//        x->c[1]->s=x->c[1]->size;
//    }
//    else if(!x->s)
//    {
//        x->c[0]->s=0;
//        x->c[1]->s=0;
//    }
//}
//inline void update(node *x)
//{
//    x->s=x->c[0]->s+x->c[1]->s;
//}
//node *init(int l,int r)
//{
//    node *p=cur++;
//    p->l=l;p->r=r;
//    p->size=r-l+1;
//    p->s=0;
//    if(l==r)return p;
//    int mid=l+r>>1;
//    p->c[0]=init(l,mid);
//    p->c[1]=init(mid+1,r);
//    return p;
//}
//int get(node *x,int l,int r)
//{
//    if(l<=x->l&&x->r<=r)
//        return x->s;
//    pushdown(x);
//    int mid=x->l+x->r>>1,s=0;
//    if(l<=mid)s+=get(x->c[0],l,r);
//    if(r>mid)s+=get(x->c[1],l,r);
//    update(x);
//    return s;
//}
//int query(int pos)
//{
//    int s,e,mid;
//    s=pos,e=n;
//    while(s<=e)
//    {
//        mid=s+e>>1;
//        if(get(root,pos,mid)<mid-pos+1)e=mid-1;
//        else s=mid+1;
//    }
//    if(s>n)return -1;
//    return s;
//}
//void change(node *x,int l,int r,int c)
//{
//    if(l<=x->l&&x->r<=r)
//    {
////        L=min(L,x->l);
////        R=max(R,x->r);
//        x->s=c*x->size;
//        return ;
//    }
//    pushdown(x);
//    int mid=x->l+x->r>>1;
//    if(l<=mid)change(x->c[0],l,r,c);
//    if(r>mid)change(x->c[1],l,r,c);
//    update(x);
//}
//int main()
//{
//    int t1,t2;
//    int cas,a,b,c,s,e,mid,bf;
//    scanf("%d",&cas);
//    while(cas--)
//    {
//        scanf("%d%d",&n,&m);
//        cur=mem;
//        root=init(1,n);
//        while(m--)
//        {
//            scanf("%d%d%d",&a,&b,&c);
//            if(a==1)
//            {
//                t1=query(c);
//                s=b;e=n;
//                while(s<=e)
//                {
//                    mid=s+e>>1;
//                    if(get(root,b,mid)+c<=mid-b+1)e=mid-1;
//                    else s=mid+1;
//                }
//                s=min(s,n);
//                L=n+1;R=-1;
//                bf=root->s;
//                change(root,b,s,1);t2=s;
//                if(root->s==bf)puts("Can not put any one.");
//                else printf("%d %d\n",t1,t2);
//            }
//            else
//            {
//                printf("%d\n",get(root,b,c));
//                change(root,b,c,0);
//            }
//
//        }
//        if(cas)puts("");
//    }
//}
