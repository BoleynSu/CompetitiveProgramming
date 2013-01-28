#include <cstdio>
#include <cstring>
using namespace std;

#define f(x) ((x)-'a')
const int MAXNODE=100000;
struct Trie
{
    Trie* c[26];
    int counter;
};
Trie pool[MAXNODE];
Trie* top;
Trie* root;
void init()
{
    memset(pool,0,sizeof(pool));
    top=pool;
    root=top++;

}
void insert(Trie* node,char* s)
{
    while (*s)
    {
        if (!node->c[f(*s)])
            node->c[f(*s)]=top++;
        node=node->c[f(*s)];
        node->counter++;
        s++;
    }
}

int main()
{
    int N,M;
    while (scanf("%d%d",&N,&M)!=EOF)
    {
        char s[1025];
        init();
        for (int i=0;i<N;i++)
        {
            scanf("%s",s);
            insert(root,s);
        }
        int total=0;
        for (int i=0;i<M;i++)
        {
            int K;
            scanf("%d",&K);
            Trie* node=root;
            for (int j=0;j<K;j++)
            {
                char c=0;
                double bar[8];
                double narrower=1e100;
                for (int k=0;k<8;k++)
                {
                    scanf("%lf",&bar[k]);
                    narrower=narrower>bar[k]?bar[k]:narrower;
                }
                for (int k=0;k<8;k++)
                {
                    c<<=1;
                    if (narrower/bar[k]>=0.95/1.05&&narrower/bar[k]<=1)
                        ;
                    else
                        c|=1;
                }
                if (node) node=node->c[f(c)];
            }
            if (node) total+=node->counter;
        }
        printf("%d\n",total);
    }
}
