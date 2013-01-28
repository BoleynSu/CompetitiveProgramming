#include <iostream>
#include <utility>
using namespace std;

typedef pair<int,int> Point;
#define x first
#define y second

enum{MAXN=200};
int N;
Point p[MAXN];
int counter;

int main()
{
    cin>>N;
    for (int i=0;i<N;i++)
        cin>>p[i].x>>p[i].y;
    for (int i=0;i<N;i++)
    {
        bool dir[]={false,false,false,false};
        for (int j=0;j<N;j++)
            if (p[i].x==p[j].x)
            {
               if (p[i].y<p[j].y) dir[0]=true;
               if (p[i].y>p[j].y) dir[1]=true;
            }
            else if (p[i].y==p[j].y)
            {
                 if (p[i].x<p[j].x) dir[2]=true;
                 if (p[i].x>p[j].x) dir[3]=true;
            }
        int dir_counter=0;
        for (int t=0;t<4;t++) if (dir[t]) dir_counter++;
        if (dir_counter==4) counter++;
    }
    cout<<counter<<endl;
    return 0;
}
 

