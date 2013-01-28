#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

struct node_struct{node_struct* l;node_struct* r;int v;};
typedef node_struct* node;
node_struct pool[600000+2];
node top;
int sl,tl;
char s[20*600000],t[7000+2];
char* st;
node insert(node& n,int v)
{
    if (n)
    {
        if (v<n->v) return insert(n->l,v);
        else return insert(n->r,v);
    }
    else
    {
        top->v=v;
        return n=top++;
    }
}
void search(node root)
{
    enum State{ENTER,LGO,RGO};
    static node stack[600000+2];
    static int stacktop;
    static State stackstate[600000+2];
    stacktop=0;
    stack[stacktop]=root;
    stackstate[stacktop]=ENTER;
    while (stacktop>=0)
    {
        int oldtop=stacktop;
        switch (stackstate[oldtop])
        {
        case ENTER:
            if (stack[oldtop]->l)
            {
                *st++=stack[oldtop]->v%2;
                stacktop++;
                stack[stacktop]=stack[oldtop]->l;
                stackstate[stacktop]=ENTER;
            }
            stackstate[oldtop]=LGO;
            break;
        case LGO:
            *st++=stack[oldtop]->v%2;
            if (stack[oldtop]->r)
            {
                stacktop++;
                stack[stacktop]=stack[oldtop]->r;
                stackstate[stacktop]=ENTER;
                stackstate[oldtop]=RGO;
            }
            else stacktop--;
            break;
        case RGO:
            *st++=stack[oldtop]->v%2;
            stacktop--;
            break;
        }
    }
}
int kmp()
{
    static int pi[20*600000];
    int answer=0;
    pi[0]=-1;
    for (int i=1,p=-1;i<tl;i++)
    {
        while (p>=0&&t[i]!=t[p+1]) p=pi[p];
        if (t[i]==t[p+1]) p++;
        pi[i]=p;
    }
    for (int i=0,p=-1;i<sl;i++)
    {
        while (p>=0&&s[i]!=t[p+1]) p=pi[p];
        if (s[i]==t[p+1]) p++;
        if (p==tl-1)
        {
            answer++;
            p=pi[p];
        }
    }
    return answer;
}

int main()
{
    int TC;
    scanf("%d",&TC);
    for (int tc=1;tc<=TC;tc++)
    {
        int n;
        scanf("%d",&n);
        top=pool;
        memset(pool,0,sizeof(pool));
        node root=0;
        map<int,node> f;
        map<int,node>::iterator it;
        for (int i=0;i<n;i++)
        {
            int v;
            scanf("%d",&v);
            getchar();
            if (f.empty()) f.insert(make_pair(v,insert(root,v)));
            else if ((it=f.upper_bound(v))!=f.end())
            {
                if (!it->second->l) f.insert(make_pair(v,insert(it->second,v)));
                else f.insert(make_pair(v,insert((--it)->second,v)));
            }
            else f.insert(make_pair(v,insert(f.rbegin()->second,v)));
        }
        gets(t);
        tl=strlen(t);
        for (int i=0;i<tl;i++) t[i]-='0';
        st=s;
        search(root);
        s[sl=st-s]=0;
        printf("Case #%d: %d\n",tc,kmp());
    }
}

