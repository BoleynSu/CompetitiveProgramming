#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

enum{MAXALPHABET=4,MAXNODE=1000};
typedef struct struct_node* node;
struct struct_node{node fail;node next[MAXALPHABET];int id;};
struct_node pool[MAXNODE];
node top;
node q[MAXNODE];
int head,tail;
int H(char c)
{
    switch (c)
    {
    case 'A':
        return 0;
        break;
    case 'T':
        return 1;
        break;
    case 'C':
        return 2;
    case 'G':
        return 3;
    }
}
void insert(node root,char* str,int id)
{
    node p=root;
    while (*str)
    {
        if (!p->next[H(*str)])
        {
            top->id=-1;
            p->next[H(*str)]=top++;
        }
        p=p->next[H(*str)];
        str++;
    }
    p->id=id;
}
void build_ac_automaton(node root)
{
    q[head=tail=0]=root;
    while (head<=tail)
    {
        node qh=q[head++];
        node p;
        for (int i=0;i<MAXALPHABET;i++)
            if (qh->next[i])
            {
                if (qh==root) qh->next[i]->fail=root;
                else
                {
                    p=qh->fail;
                    while (p)
                    {
                        if (p->next[i])
                        {
                            qh->next[i]->fail=p->next[i];
                            break;
                        }
                        p=p->fail;
                    }
                    if (!p) qh->next[i]->fail=root;
                }
                q[++tail]=qh->next[i];
            }
    }
}

enum{MAXDNA=10,MAXL=100};
int n,l;
char DNA[MAXDNA][MAXL];
int w[MAXDNA];
bool f[2][1<<MAXDNA][MAXNODE];
int sum[1<<MAXDNA];

int main()
{
    while (cin>>n>>l)
    {
        for (int i=0;i<n;i++)
            cin>>DNA[i]>>w[i];

        memset(sum,0,sizeof sum);
        for (int i=0;i<(1<<n);i++)
            for (int j=0;j<n;j++)
                if (i&(1<<j))
                    sum[i]+=w[j];

        top=pool;
        memset(pool,0,sizeof pool);

        top->id=-1;
        node root=top++;
        for (int i=0;i<n;i++) insert(root,DNA[i],i);
        build_ac_automaton(root);
        #define P(x) ((x)-pool)
        #define rP(x) (pool+(x))
        #define L(x) ((x)&1)
        memset(f[L(0)],0,sizeof f[L(0)]);
        f[L(0)][0][P(root)]=true;
        for (int i=0;i<l;i++)
        {
            int ni=i+1;
            memset(f[L(ni)],0,sizeof f[L(ni)]);
            for (int bitset=0;bitset<(1<<n);bitset++)
                for (int p=P(pool);p<P(top);p++)
                    if (f[L(i)][bitset][p])
                        for (int c=0;c<MAXALPHABET;c++)
                        {
                            node current;
                            int nbitset=bitset;
                            current=rP(p);
                            while (current)
                            {
                                if (current->next[c]&&current->next[c]->id!=-1)
                                    nbitset|=1<<current->next[c]->id;
                                current=current->fail;
                            }
                            current=rP(p);
                            while (!current->next[c]&&current!=root)
                                current=current->fail;
                            if (current->next[c]) f[L(ni)][nbitset][P(current->next[c])]=true;
                            else f[L(ni)][nbitset][P(root)]=true;
                            //cout<<ni<<" "<<l<<" "<<nbitset<<" "<<c<<" "<<(current->next[c]?P(current->next[c]):0)<<endl;
                        }
        }
        int answer=-1;
        for (int bitset=0;bitset<(1<<n);bitset++)
            for (int p=0;p<P(top);p++)
                if (f[L(l)][bitset][p]&&answer<sum[bitset]) answer=sum[bitset];
        if (answer==-1) cout<<"No Rabbit after 2012!"<<endl;
        else cout<<answer<<endl;
    }
}

