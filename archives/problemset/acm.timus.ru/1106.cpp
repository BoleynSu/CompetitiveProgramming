#include <iostream>
using namespace std;

int N;
int adjs[100+1];
int adj[100+1][100];
int BLACKS;
int color[100+1];
void dfs(int u,int c)
{
     if (!color[u])
     {
        color[u]=c;
        if (c==1) BLACKS++;
        for (int e=0;e<adjs[u];e++)
            dfs(adj[u][e],-c);
     }
}

int main()
{
    cin>>N;
    for (int i=1;i<=N;i++)
    {
        for (;;)
        {
            cin>>adj[i][adjs[i]];
            if (adj[i][adjs[i]]) adjs[i]++;
            else break;
        }
    }
    for (int i=1;i<=N;i++) dfs(i,1);
    cout<<BLACKS<<endl;
    for (int i=0,j=0;i<BLACKS;i++)
    {
        while (color[++j]!=1) ;
        cout<<j<<char(i==BLACKS?'\n':' ');
    }
    return 0;
}
