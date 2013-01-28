#include <cstdio>
#include <cstring>
using namespace std;

typedef int State[8][8];
int N;
State state[8*8];
int answer;

int stamp;
void floodfill(State state,int color,int x=0,int y=0)
{
    static int visited[8][8];
    if (0<=x&&x<N&&0<=y&&y<N&&(visited[x][y]!=stamp)&&(state[x][y]==6||state[x][y]==color))
    {
        visited[x][y]=stamp;
        state[x][y]=6;
        floodfill(state,color,x+1,y);
        floodfill(state,color,x-1,y);
        floodfill(state,color,x,y+1);
        floodfill(state,color,x,y-1);
    }
}
int count(State state)
{
    static int color[7];
    stamp++;
    for (int i=0;i<N;i++)
        for (int j=0;j<N;j++)
            color[state[i][j]]=stamp;
    int counter=0;
    for (int i=0;i<6;i++)
        if (color[i]==stamp) counter++;
    return counter;
}
void neighbor(State state,bool nb[6],int x=0,int y=0)
{
    static int visited[8][8];
    if (0<=x&&x<N&&0<=y&&y<N&&(visited[x][y]!=stamp))
    {
        visited[x][y]=stamp;
        if (state[x][y]==6)
        {
            neighbor(state,nb,x+1,y);
            neighbor(state,nb,x-1,y);
            neighbor(state,nb,x,y+1);
            neighbor(state,nb,x,y-1);
        }
        else nb[state[x][y]]=true;
    }
}
bool IDAStar(int depth)
{
    if (depth<answer)
    {
        if (depth+count(state[depth])>answer) return false;
        bool nb[6];
        memset(nb,0,sizeof(nb));
        stamp++;
        neighbor(state[depth],nb);
        int olddepth=depth++;
        for (int i=0;i<6;i++)
            if (nb[i])
            {
                memcpy(state[depth],state[olddepth],sizeof(State));
                stamp++;
                floodfill(state[depth],i);
                if (IDAStar(depth)) return true;
            }
        return false;
    }
    else return count(state[depth])==0;
}

int main()
{
    for (;;)
    {
        scanf("%d",&N);
        if (!N) break;
        for (int i=0;i<N;i++)
            for (int j=0;j<N;j++)
                scanf("%d",&state[0][i][j]);
        answer=0;
        stamp++;
        floodfill(state[0],state[0][0][0]);
        while (!IDAStar(0)) answer++;
        printf("%d\n",answer);
    }
}

