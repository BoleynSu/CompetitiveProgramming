#include <iostream>
#include <queue>
#include <utility>
using namespace std;

typedef pair<int,int> P;
typedef pair<int,P> STATE;
const int oo=19930309;
const int DIRS=4;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
const int QSIZE=(1<<5)*(50+2)*(50+2);

int R,C,K;
char M[50+2][50+2];
int KEY[50+2][50+2];
STATE S,T;
/*
int d[1<<5][50+2][50+2];

int dijkstra()
{
    priority_queue<pair<int,STATE>,vector<pair<int,STATE> >,less<pair<int,STATE> > > q;
    for (int i=0;i<(1<<K);i++)
        for (int j=1;j<=R;j++)
            for (int k=1;k<=C;k++)
                d[i][j][k]=oo;
    #define D(STATE) d[STATE.first][STATE.second.first][STATE.second.second]
    #define PUSH(STATE,DIST) q.push(make_pair(D(STATE)=DIST,STATE))
    PUSH(S,0);
    while (!q.empty())
    {
        STATE u=q.top().second;
        q.pop();
        for (int i=0;i<DIRS;i++)
        {
            STATE v=u;
            v.second.first+=dx[i];
            v.second.second+=dy[i];
            char m=M[v.second.first][v.second.second];
            if ((m!='#'&&(m<'A'||'E'<m))||('A'<=m&&m<='E'&&((1<<(m-'A'))&v.first)))
            {
                int DIST=D(u);
                if ('0'<=m&&m<='9') DIST+=m-'0';
                if (KEY[v.second.first][v.second.second]!=-1)
                    v.first|=1<<KEY[v.second.first][v.second.second];
                if (D(v)>DIST) PUSH(v,DIST);
            }
        }
        while (!q.empty()&&D(q.top().second)!=q.top().first) q.pop();
    }
    int DT=oo;
    for (T.first=0;T.first<(1<<K);T.first++)
            if (DT>D(T)) DT=D(T);
    if (DT==oo) DT=-1;
    return DT;
}
*/

int d[1<<5][50+2][50+2];
int qh,qt;
STATE q[QSIZE];
bool inq[1<<5][50+2][50+2];
int SPFA()
{
    for (int i=0;i<(1<<K);i++)
        for (int j=1;j<=R;j++)
            for (int k=1;k<=C;k++)
                d[i][j][k]=oo;
    #define D(STATE) d[STATE.first][STATE.second.first][STATE.second.second]
    #define INQ(STATE) inq[STATE.first][STATE.second.first][STATE.second.second]
    #define PUSH(STATE,DIST) D(STATE)=DIST,INQ(STATE)=true,q[(++qt)%(QSIZE)]=STATE
    qh=0,qt=-1;
    PUSH(S,0);
    while (qh<=qt)
    {
        STATE u=q[(qh++)%QSIZE];
        INQ(u)=false;
        for (int i=0;i<DIRS;i++)
        {
            STATE v=u;
            v.second.first+=dx[i];
            v.second.second+=dy[i];
            char m=M[v.second.first][v.second.second];
            if ((m!='#'&&(m<'A'||'E'<m))||('A'<=m&&m<='E'&&((1<<(m-'A'))&v.first)))
            {
                int DIST=D(u);
                if ('0'<=m&&m<='9') DIST+=m-'0';
                if (KEY[v.second.first][v.second.second]!=-1)
                    v.first|=1<<KEY[v.second.first][v.second.second];
                if (D(v)>DIST)
                    if (!INQ(v)) PUSH(v,DIST);
                    else D(v)=DIST;
            }
        }
    }
    int DT=oo;
    for (T.first=0;T.first<(1<<K);T.first++)
            if (DT>D(T)) DT=D(T);
    if (DT==oo) DT=-1;
    return DT;
}

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        cin>>R>>C>>K;
        cin.get();
        for (int i=0;i<=R+1;i++)
            for (int j=0;j<=C+1;j++)
                M[i][j]='#';
        for (int i=1;i<=R;i++)
        {
            for (int j=1;j<=C;j++)
            {
                cin>>M[i][j];
                if (M[i][j]=='S')
                    S=STATE(0,P(i,j));
                if (M[i][j]=='T')
                    T=STATE(0,P(i,j));
                KEY[i][j]=-1;
            }
            cin.get();
        }
        for (int i=0;i<K;i++)
        {
            int x,y;
            cin>>x>>y;
            KEY[x][y]=i;
            cin.get();
        }
        cout<<SPFA()<<endl;
    }
}

