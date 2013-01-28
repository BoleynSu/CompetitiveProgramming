#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN=100000;
const int MAXP=47;
const int MAXNODE=10000000;

struct Item
{
    int begin,end;
    char s[MAXP+2];
};
Item items[MAXN+2];
int max(int a,int b)
{
    return a>b?a:b;
}
void calculate(int n)
{
    Item& a=items[n-2];
    Item& b=items[n-1];
    Item& c=items[n];
    int end=max(a.end-a.begin,b.end-b.begin);
    int ai=0,bi=0,ci=0;
    if (a.begin!=b.begin) ai++;
    for (;ai<=end||bi<=end;ai++,bi++,ci++)
    {
        c.s[ci]+=a.s[ai]+b.s[bi];
        if (c.s[ci]>=10)
        {
            c.s[ci+1]+=1;
            c.s[ci]-=10;
        }
    }
    if (c.s[ci])
    {
        if (ci<=MAXP) c.begin=b.begin;
        else
        {
            for (int i=0;i<=ci;i++)
                c.s[i]=c.s[i+1];
            ci--,c.begin=b.begin+1;
        }
    }
    else ci--,c.begin=b.begin;
    c.end=c.begin+ci;
}
struct trie_struct
{
    trie_struct* c[10];
    int id;
};
typedef trie_struct* trie;
trie_struct pool[MAXNODE];
trie top=pool;
trie root;
void insert(trie node,int id,char s[],int sl)
{
    for (int i=0;i<sl;i++)
    {
        if (!node->c[int(s[i])])
        {
            top->id=id;
            node->c[int(s[i])]=top++;
        }
        node=node->c[int(s[i])];
    }
}
int find(trie node,char s[],int sl)
{
    for (int i=0;i<sl;i++)
    {
        node=node->c[int(s[i])];
        if (!node) return -1;
    }
    return node->id;
}
int min(int a,int b)
{
    return a<b?a:b;
}
void reverse(char s[],int sl)
{
    for (int i=0;i+i<sl;i++)
    {
        char swap=s[i];
        s[i]=s[sl-i];
        s[sl-i]=swap;
    }
}
void init()
{
    items[0].begin=0;
    items[0].end=0;
    items[0].s[0]=1;
    items[1].begin=0;
    items[1].end=0;
    items[1].s[0]=1;
    for (int i=2;i<MAXN;i++)
        calculate(i);
    root=top++;
    for (int i=0;i<MAXN;i++)
    {
        reverse(items[i].s,items[i].end-items[i].begin);
        insert(root,i,items[i].s,min(items[i].end-items[i].begin+1,40));
    }
}
char s[40+2];
int get()
{
    int sl=strlen(s);
    for (int i=0;i<sl;i++)
        s[i]-='0';
    return find(root,s,sl);
}

int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    init();
    for (int t=1;t<=T;t++)
    {
        gets(s);
        printf("Case #%d: %d\n",t,get());
    }
}

