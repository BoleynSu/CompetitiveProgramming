#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
using namespace std;

int n,m;
int b[51][51];
map<vector<pair<int,int> >,bool> f;

bool operator<(const vector<pair<int,int> >& a,const vector<pair<int,int> >& b)
{
    if (a.size()==b.size())
    {
        for (unsigned i=0;i<a.size();i++)
            if (a[i]!=b[i]) return a[i]<b[i];
        return false;
    }
    else return a.size()<b.size();
}

bool win(const vector<pair<int,int> >& state)
{
    map<vector<pair<int,int> >,bool>::iterator it=f.find(state);
    if (it==f.end())
    {
        bool result=false;
        for (int i=1;i<n;i++)
            for (int j=1;j<m;j++)
                if (!b[i][j]&&!b[i][j+1]&&!b[i+1][j]&&!b[i+1][j+1])
                {
                    b[i][j]=b[i][j+1]=b[i+1][j]=b[i+1][j+1]=1;
                    vector<pair<int,int> > newstate=state;
                    newstate.push_back(make_pair(i,j));
                    sort(newstate.begin(),newstate.end());
                    bool get=!win(newstate);
                    if (get) result=true;
                    b[i][j]=b[i][j+1]=b[i+1][j]=b[i+1][j+1]=0;
                }
        it=f.insert(make_pair(state,result)).first;
    }
    return it->second;
}

int main()
{
    while (cin>>n>>m)
    {
        cin.get();
        for (int i=0;i<=n+1;i++)
            for (int j=0;j<=m+1;j++)
                b[i][j]=1;
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
                b[i][j]=cin.get()-'0';
            cin.get();
        }
        f.clear();
        cout<<(win(vector<pair<int,int> >())?"Yes":"No")<<endl;
    }
}

