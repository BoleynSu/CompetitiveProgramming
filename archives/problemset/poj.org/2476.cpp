#include <cstdio>
#include <string>
#include <map>
using namespace std;

const int MAXN=1000;
const int MAXLENGTH=1024;
int n;
char i2s[MAXN][MAXLENGTH];
int adjs[MAXN];
int adj[MAXN][MAXN];


int main()
{
    for (;;)
    {
        map<string,int> s2i;
        scanf("%d",&n);
        if (n==0) break;
        for (int i=0;i<n;i++)
            scanf("%s",i2s[i]),
            s2i[i2s[i]]=i,
            adjs[i]=0;
        for (int i=1;i<n;i++)
        {
            char a[MAXLENGTH],b[MAXLENGTH];
            scanf("%s%s",a,b);
            int ai=s2i[a],bi=s2i[b];
            adj[ai][adjs[ai]++]=bi;
            adj[bi][adjs[bi]++]=ai;
        }
        
        bool lose[MAXN];
        for (int i=0;i<n;i++) lose[i]=false;
        
        for (int round=1,gamer=n;;round++)
        {
            printf("Round #%d\n",round);
            
            int match=gamer/2;
            bool gamed[MAXN];
            for (int i=0;i<n;i++) gamed[i]=lose[i];
            
            for (int i=0;i<n;i++)
            {
                if (adjs[i]==1)
                {
                   int i_=adj[i][0];
                   if (!gamed[i]&&!gamed[i_]&&adjs[i_]==2)
                   {
                      adjs[i]--;
                      printf("%s defeats %s\n",i2s[i_],i2s[i]);
                      for (int j=0;j<adjs[i_];j++)
                          if (adj[i_][j]==i)
                             adj[i_][j]=adj[i_][--adjs[i_]];
                      match--;
                      gamed[i]=gamed[i_]=true;
                      lose[i]=true;
                   }
                }
                if (match==0) break;
            }
            if (match!=0)
               for (int i=0;i<n;i++)
               {
                   if (adjs[i]==1)
                   {
                      int i_=adj[i][0];
                      if (!gamed[i]&&!gamed[i_])
                      {
                         adjs[i]--;
                         printf("%s defeats %s\n",i2s[i_],i2s[i]);
                         for (int j=0;j<adjs[i_];j++)
                             if (adj[i_][j]==i)
                                adj[i_][j]=adj[i_][--adjs[i_]];
                         match--;
                         gamed[i]=gamed[i_]=true;
                         lose[i]=true;
                      }
                   }
                   if (match==0) break;
               }
            if (gamer%2==1)
            {
               gamer=gamer/2+1;
               for (int i=0;i<n;i++)
                   if (!gamed[i])
                      printf("%s advances with wildcard\n",i2s[i]);
            }
            else gamer=gamer/2;
            if (gamer==1)
            {
               for (int i=0;i<n;i++)
                   if (!lose[i])
                      printf("Winner: %s\n\n",i2s[i]);
               break;
            }
        }
    }
}
