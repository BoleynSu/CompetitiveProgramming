#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>
#include <cmath>
#include <map>
#define mp make_pair
#define pb push_back
#define x first
#define y second
using namespace std;

const int oo=19930309;
typedef long long big;
typedef pair<int,int> pii;
//const int N=102;
//const int MOD=1000000007;
//int l1,l2,n,m;
//struct node
//{
//    node *c[2],*fail;
//    int id,f;
//}mem[300],*nul,*root,*cur;
//int f[N][N][202];
//node *q[300];
//char str[200];
//int cz(char x){if(x=='R')return 0;return 1;}
//node *newnode()
//{
//    node *p=cur++;
//    p->c[0]=p->c[1]=nul;
//    p->flag=-1;p->id=p-mem;
//    p->fail=root;
//    return p;
//}
//void ins(int x)
//{
//    int i;
//    node *now=root;
//    for(i=0;str[i];i++)
//    {
//        if(now->c[cz(str[i])]==nul)now->c[cz(str[i])]=newnode();
//        now=now->c[cz(str[i])];
//    }
//    now->flag=x;
//}
//void bfs()
//{
//    int i,h,tail;
//    node *s,*v;
//    root->fail=root;
//    q[h=tail=1]=root;
//    while(h<=tail)
//    {
//        s=q[h++];
//        for(i=0;i<2;i++)
//        {
//            if(s->c[i]==nul)s->c[i]=s->fail->c[i];
//            else
//            {
//                q[++tail]=s->c[i];
//                v=s->fail;
//                s->c[i]->fail=v->c[i];
//            }
//        }
//    }
//}
//int main()
//{
//    int cas;
//    scanf("%d",&cas);
//    while(cas--)
//    {
//        scanf("%d%d",&n,&m);
//        nul=root=mem;cur=mem+1;
//        nul->c[0]=nul->c[1]=nul;
//        nul->flag=-1;
//        root->c[0]=newnode();
//        root->c[1]=newnode();
//        scanf("%s",str);
//        ins(0);
//        scanf("%s",str);
//        ins(1);
//    }
//}

map<pii,int> id;
pii rid[24];
map<int,int> dp;

bool check(int st,int a,int b,int c,int d)
{
    if (!id.count(mp(a,b))||(st&(1<<id[mp(a,b)]))) return false;
    if (!id.count(mp(a,c))||(st&(1<<id[mp(a,c)]))) return false;
    if (!id.count(mp(b,d))||(st&(1<<id[mp(b,d)]))) return false;
    if (!id.count(mp(c,d))||(st&(1<<id[mp(c,d)]))) return false;
    return true;
}

int calc(int st)
{
    if (!dp.count(st))
    {
        int& ans=dp[st];
        ans=-oo;
        bool fnd=false;
        for (int i=0;i<24;i++) if ((st>>i)&1)
        {
            st^=1<<i;
            int a=rid[i].x,b=rid[i].y,na,nb;
            fnd=true;
            int get=0;
            if (a+1==b)
            {
                na=a-4,nb=b-4;
                if (check(st,na,nb,a,b))
                {
                    get++;
                }
                na=a+4,nb=b+4;
                if (check(st,a,b,na,nb))
                {
                    get++;
                }
                get-=calc(st);
            }
            else if (a+4==b)
            {
                na=a-1,nb=b-1;
                if (check(st,na,a,nb,b))
                {
                    get++;
                }
                na=a+1,nb=b+1;
                if (check(st,a,na,b,nb))
                {
                    get++;
                }
                get-=calc(st);
            }
            if (ans<get) ans=get;
            st^=1<<i;
        }
        if (!fnd) ans=0;
    }
    return dp[st];
}

int main()
{
    id[mp(1,2)]=0;
    id[mp(2,3)]=1;
    id[mp(3,4)]=2;
    id[mp(1,5)]=3;
    id[mp(2,6)]=4;
    id[mp(3,7)]=5;
    id[mp(4,8)]=6;
    id[mp(5,6)]=7;
    id[mp(6,7)]=8;
    id[mp(7,8)]=9;
    id[mp(5,9)]=10;
    id[mp(6,10)]=11;
    id[mp(7,11)]=12;
    id[mp(8,12)]=13;
    id[mp(9,10)]=14;
    id[mp(10,11)]=15;
    id[mp(11,12)]=16;
    id[mp(9,13)]=17;
    id[mp(10,14)]=18;
    id[mp(11,15)]=19;
    id[mp(12,16)]=20;
    id[mp(13,14)]=21;
    id[mp(14,15)]=22;
    id[mp(15,16)]=23;
    for (map<pii,int>::iterator it=id.begin();it!=id.end();it++) rid[it->y]=it->x;
    int T;
    scanf("%d",&T);
    for (int t=1;t<=T;t++)
    {
        int n;
        scanf("%d",&n);
        int st=(1<<24)-1;
        int ans=0;
        for (int i=0;i<n;i++)
        {
            int a,b,na,nb;
            scanf("%d%d",&a,&b);
            if (a>b) swap(a,b);
            st^=1<<id[mp(a,b)];

            int get=0;
            if (a+1==b)
            {
                na=a-4,nb=b-4;
                if (check(st,na,nb,a,b))
                {
                    get++;
                }
                na=a+4,nb=b+4;
                if (check(st,a,b,na,nb))
                {
                    get++;
                }
            }
            else if (a+4==b)
            {
                na=a-1,nb=b-1;
                if (check(st,na,a,nb,b))
                {
                    get++;
                }
                na=a+1,nb=b+1;
                if (check(st,a,na,b,nb))
                {
                    get++;
                }
            }
            if (i&1) ans-=get;
            else ans+=get;
        }
        if (n&1)
        {
            ans-=calc(st);
        }
        else
        {
            ans+=calc(st);
        }
        cout<<"Case #"<<t<<": ";
        cout<<(ans>0?"Tom200":"Jerry404")<<endl;
    }
}
