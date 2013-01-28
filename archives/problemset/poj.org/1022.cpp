#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN=1000;
const int D=4;
int n;
int id[MAXN];
int adj[MAXN][D*2];

vector<int> p[MAXN];
bool defined[MAXN];

bool dfs(int i,const vector<int>& point)
{
     if (defined[i])
     {
        for (int j=0;j<D;j++)
            if (point[j]!=p[i][j])
               return false;
        return true;
     }
     else
     {
         defined[i]=true;
         p[i]=point;
         vector<int> next;
         next=point;
         next[0]-=1;
         if (adj[i][0]) if(!dfs(adj[i][0],next)) return false;
         next=point;
         next[0]+=1;
         if (adj[i][1]) if(!dfs(adj[i][1],next)) return false;
         next=point;
         next[1]-=1;
         if (adj[i][2]) if(!dfs(adj[i][2],next)) return false;
         next=point;
         next[1]+=1;
         if (adj[i][3]) if(!dfs(adj[i][3],next)) return false;
         next=point;
         next[2]-=1;
         if (adj[i][4]) if(!dfs(adj[i][4],next)) return false;
         next=point;
         next[2]+=1;
         if (adj[i][5]) if(!dfs(adj[i][5],next)) return false;
         next=point;
         next[3]-=1;
         if (adj[i][6]) if(!dfs(adj[i][6],next)) return false;
         next=point;
         next[3]+=1;
         if (adj[i][7]) if(!dfs(adj[i][7],next)) return false;
         return true;
     }
}
int main()
{
    int T;
    cin>>T;
    for (int t=1;t<=T;t++)
    {
        cin>>n;
        for (int i=0;i<n;i++)
        {
            cin>>id[i];
            for (int j=0;j<D*2;j++) cin>>adj[id[i]][j];
        }
        
        memset(defined,0,sizeof(defined));
        bool inconsistent=false;
        if (dfs(id[0],vector<int>(D,0)))
        {
           for (int i=0;i<n;i++)
               if (!defined[id[i]]) inconsistent=true;
        }
        else inconsistent=true;
        
        if (inconsistent) cout<<"Inconsistent"<<endl;
        else
        {
            const int oo=(~0u)>>1;
            vector<int> max(D,-oo),min(D,+oo);
            for (int i=0;i<n;i++)
            {
                for (int j=0;j<D;j++)
                {
                    if (max[j]<p[id[i]][j])
                       max[j]=p[id[i]][j];
                    if (min[j]>p[id[i]][j])
                       min[j]=p[id[i]][j];
                }
            }
            int answer=1;
            for (int i=0;i<D;i++)
                answer*=max[i]-min[i]+1;
            cout<<answer<<endl;
        }
    }
    return 0;
}
