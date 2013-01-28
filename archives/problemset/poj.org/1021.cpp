#include <iostream>
#include <utility>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

#define Point pair<int,int>
#define x first
#define y second

const int MAXW=100;
const int MAXH=100;
const int MAXN=MAXW*MAXH;
const int KIND=8;
int W,H,n;
Point L[MAXN],R[MAXN];

bool Lrest[MAXW][MAXH],Rrest[MAXW][MAXH];
vector<vector<Point > > Lblocks,Rblocks;
vector<vector<Point > > RE[KIND];
vector<bool> RE_matched;
const int ds=4;
Point d[ds]={Point(1,0),Point(-1,0),Point(0,1),Point(0,-1)};

void dfs(bool rest[MAXW][MAXH],vector<Point >& block,Point now)
{
     if (now.x>W||now.x<0||now.y>H||now.y<0||!rest[now.x][now.y]) return;
     rest[now.x][now.y]=false;
     block.push_back(now);
     for (int i=0;i<ds;i++)
         dfs(rest,block,Point(now.x+d[i].x,now.y+d[i].y));
}
void process(vector<Point >& E,int i)
{
     for (vector<Point >::iterator it=E.begin();it!=E.end();it++)
     {
         switch (i)
         {
                case 0://(x,y)-(x,y)
                     *it=Point(it->x,it->y);
                     break;
                case 1://(x,y)-(-y,x)
                     *it=Point(-it->y,it->x);
                     break;
                case 2://(x,y)-(-x,-y)
                     *it=Point(-it->x,-it->y);
                     break;
                case 3://(x,y)-(y,-x)
                     *it=Point(it->y,-it->x);
                     break;
                case 4://(x,y)-(-x,y)
                     *it=Point(-it->x,it->y);
                     break;
                case 5://(x,y)-(-y,-x)
                     *it=Point(-it->y,-it->x);
                     break;                     
                case 6://(x,y)-(x,-y)
                     *it=Point(it->x,-it->y);
                     break;
                case 7://(x,y)-(y,x)
                     *it=Point(it->y,it->x);
                     break;                     
         }
     }
     sort(E.begin(),E.end());
     Point base=E.front();
     for (vector<Point >::iterator it=E.begin();it!=E.end();it++)
     {
         it->x-=base.x;
         it->y-=base.y;
     }
}
bool is_same(vector<Point >& block,int i)
{
     if (block.size()!=Rblocks[i].size()) return false;
     for (int j=0;j<KIND;j++)
     {
         bool matched=true;
         for (int k=0;k<block.size();k++)
             if (block[k]!=RE[j][i][k]) matched=false;
         if (matched) return true;
     }
     return false;
}
bool is_same()
{
     memset(Lrest,0,sizeof(Lrest));
     memset(Rrest,0,sizeof(Rrest));
     Lblocks.clear();
     Rblocks.clear();
     RE_matched.clear();
     for (int i=0;i<KIND;i++) RE[i].clear();
     for (int i=0;i<n;i++)
         Lrest[L[i].x][L[i].y]=true;
     for (int i=0;i<n;i++)
         if (Lrest[L[i].x][L[i].y])
         {
            Lblocks.push_back(vector<Point >());
            dfs(Lrest,Lblocks.back(),L[i]);
            sort(Lblocks.back().begin(),Lblocks.back().end());
            Point base=Lblocks.back().front();
            for (vector<Point >::iterator it=Lblocks.back().begin();it!=Lblocks.back().end();it++)
            {
                it->x-=base.x;
                it->y-=base.y;
            }
         }
     for (int i=0;i<n;i++)
         Rrest[R[i].x][R[i].y]=true;
     for (int i=0;i<n;i++)
         if (Rrest[R[i].x][R[i].y])
         {
            Rblocks.push_back(vector<Point >());
            dfs(Rrest,Rblocks.back(),R[i]);
            RE_matched.push_back(false);
            for (int i=0;i<KIND;i++)
            {
                RE[i].push_back(Rblocks.back());
                process(RE[i].back(),i);
            }
         }
     if (Lblocks.size()!=Rblocks.size()) return false;
     for (vector<vector<Point > >::iterator it=Lblocks.begin();it!=Lblocks.end();it++)
     {
         bool matched=false;
         for (int i=0;i<Rblocks.size();i++)
             if (!RE_matched[i])
                if (is_same(*it,i))
                {
                   RE_matched[i]=true;
                   matched=true;
                   break;
                }
         if (!matched) return false;
     }
     return true;
}

int main()
{
    int T;
    cin>>T;
    for (int t=1;t<=T;t++)
    {
        cin>>W>>H>>n;
        for (int i=0;i<n;i++)
            cin>>L[i].x>>L[i].y;
        for (int i=0;i<n;i++)
            cin>>R[i].x>>R[i].y;
        if (is_same()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
