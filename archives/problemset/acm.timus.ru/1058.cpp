#include <iostream>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;
#define point pair<double,double>
#define x first
#define y second

const int MAXN=50;
int N;
point P[MAXN];

double cross(point a,point b,point c)
{
	return (c.x-a.x)*(b.y-a.y)-(b.x-a.x)*(c.y-a.y);
}
double sqr(double x)
{
	return x*x;
}
double calc(int A,int B,int C,int D,double S,double SAB,double t1)
{
	point M,N;
	M.x=P[B].x*(1-t1)+P[C].x*t1;
	M.y=P[B].y*(1-t1)+P[C].y*t1;
	double S1=abs(cross(P[A],P[B],P[C])/2)*t1;
	double S2=S/2-SAB-S1;
	double t2=S2/(abs(cross(P[A],M,P[D])/2));
	N.x=P[A].x*(1-t2)+P[D].x*t2;
	N.y=P[A].y*(1-t2)+P[D].y*t2;
	return sqrt(sqr(M.x-N.x)+sqr(M.y-N.y));
}
int main()
{
	cin>>N;
	for (int i=0;i<N;i++)
		cin>>P[i].x>>P[i].y;
	double S;
	for (int i=0;i<N;i++)
		S+=abs(cross(P[0],P[i],P[(i+1)%N])/2);
	double answer=1e10;
	for (int A=0;A<N;A++)
	{
		double SAB=0;
		int D=(A+N-1)%N;
		for (int B=(A+1)%N;;B=(B+1)%N)
		{
			int C=(B+1)%N;
			double SCD=S-SAB-abs(cross(P[A],P[B],P[C])/2)-abs(cross(P[A],P[C],P[D])/2);
			if (SAB>S*0.5) break;
			else if (SCD<=S*0.5)
			{
				double L=max(0.0,1.0-(SAB+abs(cross(P[A],P[B],P[C])/2)+abs(cross(P[A],P[C],P[D])/2)-S/2)/abs(cross(P[D],P[B],P[C])/2)),R=min(1.0,(S/2-SAB)/abs(cross(P[A],P[B],P[C])/2));
				for (;;)
				{
					double LM=(L*2+R)/3;
					double RM=(L+R*2)/3;
					double LV=calc(A,B,C,D,S,SAB,LM);
					double RV=calc(A,B,C,D,S,SAB,RM);
					if (abs(LM-RM)<=0.0000001&&abs(LV-RV)<0.0000001)
					{
						if (answer>LV) answer=LV;
						break;
					}
					else if (LV<RV) R=RM;
					else L=LM;
				}
			}
			SAB+=abs(cross(P[A],P[B],P[C])/2);
		}
	}
	cout.setf(ios::fixed);
	cout.precision(4);
	cout<<answer<<endl;
	return 0;
}
