/*
ID: sujiao1
PROG: castle
LANG: C++
*/
#include <iostream>
#include <fstream>
using std::endl;
/*
std::istream& cin(std::cin);
std::ostream& cout(std::cout);
*/
std::ifstream cin("castle.in");
std::ofstream cout("castle.out");

const int MAXN=50;//1 to 50
int M,N;
short wall[MAXN+2][MAXN+2];
short map[MAXN+2][MAXN+2];
short size[MAXN*MAXN+2];
int color=0;

int mark(int x,int y,int color)
{
    if ((x<=0)||(y<=0)||(x>N)||(y>M)) return 0;
    if (map[x][y]!=0) return 0;
    
    map[x][y]=color;
    
    //cout<<"mark("<<x<<","<<y<<")\n";
    int ret=1;
    if ((wall[x][y]/8)%2!=1)//1000
       ret+=mark(x+1,y,color);
    if ((wall[x][y]/4)%2!=1)//0100
       ret+=mark(x,y+1,color);
    if ((wall[x][y]/2)%2!=1)//0010
       ret+=mark(x-1,y,color);
    if ((wall[x][y]/1)%2!=1)//0001
       ret+=mark(x,y-1,color);
    //cout<<"mark("<<x<<","<<y<<")="<<ret<<"\n";
    return ret;
}

int main()
{
    cin>>M>>N;
    for (int i=1;i<=N;i++)
        for (int j=1;j<=M;j++)
            cin>>wall[i][j];
    int max=0;
    for (int i=1;i<=N;i++)
        for (int j=1;j<=M;j++)
        {
            int now=mark(i,j,color+1);
            if (now!=0)
            {
               color++;
               size[color]=now;
               if (now>max) max=now;
            }
        }
    /*
    for (int i=1;i<=N;i++)
    {
        for (int j=1;j<=M;j++)
            cout<<map[i][j]<<" ";
        cout<<endl;
    }
    */
    cout<<color<<endl<<max<<endl;
    size[0]=-MAXN*MAXN;
    int mi,mj,max2=0;
    char mf;
    for (int i=1;i<=N;i++)
        for (int j=1;j<=M;j++)
        {
            int ni=0,nj=0,m=0;
            char nf=0;
            if (i>1)
            {
               ni=i;
               nj=j;
               nf='N';
               if (map[i][j]!=map[i-1][j])
                  m=size[map[i][j]]+size[map[i-1][j]];
               else m=0;
            }
            if (
               (m>max2)
               ||
                (
                 (m==max2)
                 &&
                 ((nj<mj)||((nj==mj)&&((ni>mi)||mf=='E')))
                )
               )
            {
               max2=m;
               mi=ni;
               mj=nj;
               mf=nf;
            }
    //cout<<max2<<endl<<mi<<" "<<mj<<" "<<mf<<endl;
            if (j>1)
            {
               ni=i;
               nj=j-1;
               nf='E';
               if (map[i][j]!=map[i][j-1])
                  m=size[map[i][j]]+size[map[i][j-1]];
               else m=0;
            }
            if (
               (m>max2)
               ||
                (
                 (m==max2)
                 &&
                 ((nj<mj)||((nj==mj)&&((ni>mi)||mf=='E')))
                )
               )
            {
               max2=m;
               mi=ni;
               mj=nj;
               mf=nf;
            }
    //cout<<max2<<endl<<mi<<" "<<mj<<" "<<mf<<endl;
            if (i<N)
            {
               ni=i+1;
               nj=j;
               nf='N';
               if (map[i][j]!=map[i+1][j])
                  m=size[map[i][j]]+size[map[i+1][j]];
               else m=0;
            }
            if (
               (m>max2)
               ||
                (
                 (m==max2)
                 &&
                 ((nj<mj)||((nj==mj)&&((ni>mi)||mf=='E')))
                )
               )
            {
               max2=m;
               mi=ni;
               mj=nj;
               mf=nf;
            }
    //cout<<max2<<endl<<mi<<" "<<mj<<" "<<mf<<endl;
            if (j<M)
            {
               ni=i;
               nj=j;
               nf='E';
               if (map[i][j]!=map[i][j+1])
                  m=size[map[i][j]]+size[map[i][j+1]];
               else m=0;
            }
            if (
               (m>max2)
               ||
                (
                 (m==max2)
                 &&
                 ((nj<mj)||((nj==mj)&&((ni>mi)||mf=='E')))
                )
               )
            {
               max2=m;
               mi=ni;
               mj=nj;
               mf=nf;
            }
    //cout<<max2<<endl<<mi<<" "<<mj<<" "<<mf<<endl;
        }
    cout<<max2<<endl<<mi<<" "<<mj<<" "<<mf<<endl;
    return 0;
}
