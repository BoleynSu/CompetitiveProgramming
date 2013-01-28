#include <set>
#include <map>
#include <queue>
#include <stack>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <limits.h>
#include <string.h>
#include <string>
#include <algorithm>
#define MID(x,y) ( ( x + y ) >> 1 )
#define L(x) ( x << 1 )
#define R(x) ( x << 1 | 1 )
#define FOR(i,s,t) for(int i=(s); i<(t); i++)
#define BUG puts("here!!!")
#define STOP system("pause")
#define file_r(x) freopen(x, "r", stdin)
#define file_w(x) freopen(x, "w", stdout)

using namespace std;

const int MAX = 20;
struct point{
    int x, y;
    void get()
    {
        scanf("%d%d", &x, &y);
    }
};
struct triangle{
    double l[4];
};
triangle t[MAX*MAX*MAX];
point p[MAX];
const double eps = 1e-8;
bool dy(double x,double y)    {    return x > y + eps;}    // x > y 
bool xy(double x,double y)    {    return x < y - eps;}    // x < y 
bool dyd(double x,double y)    {     return x > y - eps;}    // x >= y 
bool xyd(double x,double y)    {    return x < y + eps;}     // x <= y 
bool dd(double x,double y)     {    return fabs( x - y ) < eps;}  // x == y
double disp2p(point a, point b)
{
    return sqrt((a.x - b.x)*(a.x - b.x)*1.0 + (a.y - b.y)*(a.y - b.y));
}
bool cmp_ang(triangle a, triangle b)
{
    FOR(i, 0, 3)
        if( !dd(a.l[i], b.l[i]) )
            return xy(a.l[i], b.l[i]);
}
bool cmp(point a, point b)
{
    if( a.x == b.x )
        return a.y < b.y;
    return a.x < b.x;
}
bool cmp_equal(point a, point b)
{
    return dd(a.x, b.x) && dd(a.y, b.y);
}
double angle(double a, double b, double c)
{
    return (b*b + c*c - a*a)/(2*b*c);
}
bool check(double *l)
{
    FOR(i, 0, 3)
        if( l[i] == 1 || l[i] == -1 )
            return false;
    return true;
}
bool similar(double *a, double *b)
{
    FOR(i, 0, 3)
        if( !dd(a[i], b[i]) )
            return false;
    return true;
}

int solve( int n )
{
    sort(p, p+n, cmp);
    n = unique(p, p+n, cmp_equal) - p;
    
    int cnt = 0;
    FOR(i, 0, n)
        FOR(k, i+1, n)
            FOR(j, k+1, n)
            {
                double a = disp2p(p[i], p[k]);
                double b = disp2p(p[k], p[j]);
                double c = disp2p(p[i], p[j]);
                
                t[cnt].l[0] = angle(a, b, c);
                t[cnt].l[1] = angle(b, a, c);
                t[cnt].l[2] = angle(c, b, a);
            
                sort(t[cnt].l, t[cnt].l+3);    
                
                if( !check(t[cnt].l) )
                    continue;
                cnt++;
            }
    
    if( cnt == 0 ) return 0;
    
    sort(t, t+cnt, cmp_ang);
    int mmax = 1, ans = 1;
    FOR(i, 1, cnt)
        if( similar(t[i].l, t[i-1].l) )
            ans++;
        else
        {
            mmax = max(mmax, ans);
            ans = 1;
        }
    mmax = max(mmax, ans);
    return mmax;
}

int main()
{
    int n;
    
    while( ~scanf("%d", &n) && n )
    {
        FOR(i, 0, n)
            p[i].get();
        
        int ans = solve( n );
        printf("%d\n", ans);
    }

return 0;
}

