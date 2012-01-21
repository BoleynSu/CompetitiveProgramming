#include <cstdio>
#include <cmath>
#include <cassert>

const double EPS=1e-8,
			INF=1e8;

struct Coordinate
{
	double x,y,z;
	void read()
	{
		scanf("%lf%lf%lf",&x,&y,&z);
	}
	friend Coordinate operator+(const Coordinate& a,const Coordinate& b)
	{
		Coordinate c;
		c.x=a.x+b.x;
		c.y=a.y+b.y;
		c.z=a.z+b.z;
		return c;
	}
	friend Coordinate operator-(const Coordinate& a,const Coordinate& b)
	{
		Coordinate c;
		c.x=a.x-b.x;
		c.y=a.y-b.y;
		c.z=a.z-b.z;
		return c;
	}
	friend Coordinate operator*(const double& a,const Coordinate& b)
	{
		Coordinate c;
		c.x=a*b.x;
		c.y=a*b.y;
		c.z=a*b.z;
		return c;
	}
	friend double operator*(const Coordinate& a,const Coordinate& b)
	{
		double c=0.0;
		c+=a.x*b.x;
		c+=a.y*b.y;
		c+=a.z*b.z;
		return c;
	}
	friend Coordinate X(const Coordinate& a,const Coordinate& b)
	{
		Coordinate c;
		c.x=a.y*b.z-a.z*b.y;
		c.y=a.z*b.x-a.x*b.z;
		c.z=a.x*b.y-a.y*b.x;
		return c;
	}
};
struct Sphere
{
	Coordinate o;
	double r;
	void read()
	{
		o.read();
		scanf("%lf",&r);
	}
};

int main()
{
	int n;
	scanf("%d",&n);
	Sphere s[n];
	for (int i=0;i<n;i++) s[i].read();
	Coordinate a,b;
	a.read(),b.read();
	//X=(a+(b-a)*x) x>=0
	//(X-O)^2=R^2
	//((a-O)+(b-a)*x)^2=R^2
	for (int count=0;;count++)
	{
		double minx=INF;
		int minxi;
		for (int i=0;i<n;i++)
		{
			Coordinate p=a-s[i].o,q=(b-a);
			//(q*x+p)^2=R^2
			double A=q*q;
			double B=2.0*(q*p);
			double C=p*p-s[i].r*s[i].r;
			//A*x^2+B*x+C=0
			assert(A>EPS);
			double delta=B*B-4.0*A*C;
			if (delta>-EPS)
			{
				double x;
				if (delta<EPS) x=(-B)/(2.0*A);
				else x=(-B-sqrt(delta))/(2.0*A);
				if (EPS<x&&x<minx)
				{
					minx=x;
					minxi=i;
				}
			}
		}
		if (minx==INF) break;
		if (count)
		{
			if (count==10)
			{
				printf(" etc.");
				break;
			}
			else printf(" %d",minxi+1);
		}
		else printf("%d",minxi+1);
		Coordinate c=a+minx*(b-a);
		//a'b' oc ab
		Coordinate x=c-s[minxi].o;
		Coordinate z=X((b-a),x);
		Coordinate y=X(z,x);
		//a'b' * z = 0
		//a'b' * x = ba * x
		//a'b' * y = ab * y
		Coordinate ab;
		if (z*z>EPS)
		{
			double m[3][4]={{z.x,z.y,z.z,0},{x.x,x.y,x.z,(a-b)*x},{y.x,y.y,y.z,(b-a)*y}};

			for (int i=0;i<3;i++)
			{
				for (int j=i;j<3;j++)
					if (fabs(m[i][j])>fabs(m[i][i]))
					{
						for (int k=i;k<=3;k++)
						{
							double swap=m[i][k];
							m[i][k]=m[j][k];
							m[j][k]=swap;
						}
					}
				for (int j=i+1;j<3;j++)
					for (int k=3;k>=i;k--)
						m[j][k]-=m[i][k]*m[j][i]/m[i][i];
			}
			ab.z=m[2][3]/m[2][2];
			ab.y=(m[1][3]-ab.z*m[1][2])/m[1][1];
			ab.x=(m[0][3]-ab.z*m[0][2]-ab.y*m[0][1])/m[0][0];
		}
		else ab=a-b;
		a=c;
		b=a+ab;
	}
	puts("");
}
