#include <iostream>
#include <cmath>
using namespace std;

#define sq(n) ((n)*(n))
struct point
{
       double x,y;
};

int main()
{
    int n;
    double r;
    point p[100+2];
    double answer=0;
    
    cin>>n>>r;
    for (int i=0;i<n;i++)
        cin>>p[i].x>>p[i].y;
    
    for (int i=0;i<n;i++)
        answer+=sqrt(
        sq(p[i].x-p[(i+1)%n].x)
        +
        sq(p[i].y-p[(i+1)%n].y)
        );
    answer+=2*M_PI*r;
    cout<<int(answer)<<'.'<<(int(answer*100+((int(answer*1000)%10>=5)?1:0))%100)<<endl;
    return 0;
}
