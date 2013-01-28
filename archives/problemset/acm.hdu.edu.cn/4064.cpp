#include <cstdio>
#include <cstring>
using namespace std;

const int MODER=1000000007;
const int MAXN=12,MAXM=12;
const int SIDE=4;
static const int MAXSTATE=531441;
int N,M;
char map[MAXN][MAXM][SIDE+1];
int N_backup,M_backup;
char map_backup[MAXN][MAXM][SIDE+1];
int f[MAXN][MAXSTATE];

void init(int now=0,int last=0,int state=0)
{
     if (now==0)
     {
        if (M==1) for (int i=0;i<SIDE;i++)
                      f[0][map[0][now][(i+1)%4]]++,
                      f[0][map[0][now][(i+1)%4]]%=MODER;
        else for (int i=0;i<SIDE;i++)
                 init(now+1,map[0][now][i],state*3+map[0][now][(i+1)%4]);
     }
     else if (now+1==M)
     {
          for (int i=0;i<SIDE;i++)
              if (map[0][now][(i+2)%4]==last)
                 f[0][state*3+map[0][now][(i+1)%4]]++,
                 f[0][state*3+map[0][now][(i+1)%4]]%=MODER;
     }
     else for (int i=0;i<SIDE;i++)
              if (map[0][now][(i+2)%4]==last)
                 init(now+1,map[0][now][i],state*3+map[0][now][(i+1)%4]);
}
void calc(int line,int now=0,int last=0,int pre_state=0,int state=0)
{
     if (now==0)
     {
        if (M==1) for (int i=0;i<SIDE;i++)
                      f[line][map[line][now][(i+1)%4]]+=f[line-1][map[line][now][(i+3)%4]],
                      f[line][map[line][now][(i+1)%4]]%=MODER;
        else for (int i=0;i<SIDE;i++)
                 calc(line,now+1,map[line][now][i],pre_state*3+map[line][now][(i+3)%4],state*3+map[line][now][(i+1)%4]);
     }
     else if (now+1==M)
     {
          for (int i=0;i<SIDE;i++)
              if (map[line][now][(i+2)%4]==last)
                 f[line][state*3+map[line][now][(i+1)%4]]+=f[line-1][pre_state*3+map[line][now][(i+3)%4]],
                 f[line][state*3+map[line][now][(i+1)%4]]%=MODER;
     }
     else for (int i=0;i<SIDE;i++)
              if (map[line][now][(i+2)%4]==last)
                 calc(line,now+1,map[line][now][i],pre_state*3+map[line][now][(i+3)%4],state*3+map[line][now][(i+1)%4]);
}
int get()
{
    memset(f,0,sizeof(f));
    init();
    for (int i=1;i<N;i++) calc(i);
    int maxstate=1;
    for (int i=0;i<M;i++)
        maxstate*=3;
    int answer=0;
    for (int i=0;i<maxstate;i++) answer+=f[N-1][i],
                                 answer%=MODER;
    return answer;
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int t=1;t<=T;t++)
    {
        scanf("%d%d",&N,&M);
        for (int i=0;i<N;i++)
            for (int j=0;j<M;j++)
            {
                scanf("%s",map[i][j]);
                for (int s=0;s<SIDE;s++)
                    if (map[i][j][s]=='C') map[i][j][s]=0;
                    else if (map[i][j][s]=='R') map[i][j][s]=1;
                    else map[i][j][s]=2;
            }
        if (N<M)
        {
           N_backup=N,M_backup=M;
           memcpy(map_backup,map,sizeof(map));
           for (int i=0;i<N;i++)
               for (int j=0;j<M;j++)
                   for (int s=0;s<SIDE;s++)
                       map[j][i][s]=map_backup[i][j][3-s];
           M=N_backup,N=M_backup;
        }
        printf("Case %d: %d\n",t,get());
    }
}

