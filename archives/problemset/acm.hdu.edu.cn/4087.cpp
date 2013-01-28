#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

typedef double Matrix[4][4];
void translate(Matrix m,double x,double y,double z)
{
    for (int i=0;i<4;i++)
        for (int j=0;j<4;j++)
        {
            if (j==3)
            {
                if (i==0) m[i][j]=x;
                else if (i==1) m[i][j]=y;
                else if (i==2) m[i][j]=z;
                else m[i][j]=1.0;
            }
            else if (i==j) m[i][j]=1.0;
            else m[i][j]=0.0;
        }
}
void scale(Matrix m,double x,double y,double z)
{
    for (int i=0;i<4;i++)
        for (int j=0;j<4;j++)
        {
            if (i==j)
            {
                if (i==0) m[i][j]=x;
                else if (i==1) m[i][j]=y;
                else if (i==2) m[i][j]=z;
                else m[i][j]=1.0;
            }
            else m[i][j]=0.0;
        }
}
void rotate(Matrix m,double x,double y,double z,double d)
{
    double s=sin(d/180.0*acos(-1));
    double c=cos(d/180.0*acos(-1));
    double length=sqrt(x*x+y*y+z*z);
    x/=length;
    y/=length;
    z/=length;
    m[0][0]=x*x*(1.0-c)+c;
    m[0][1]=x*y*(1.0-c)-z*s;
    m[0][2]=x*z*(1.0-c)+y*s;
    m[1][0]=y*x*(1.0-c)+z*s;
    m[1][1]=y*y*(1.0-c)+c;
    m[1][2]=y*z*(1.0-c)-x*s;
    m[2][0]=z*x*(1.0-c)-y*s;
    m[2][1]=z*y*(1.0-c)+x*s;
    m[2][2]=z*z*(1.0-c)+c;
    m[3][3]=1.0;
    m[3][0]=m[3][1]=m[3][2]=m[0][3]=m[1][3]=m[2][3]=0.0;
}
void identity(Matrix m)
{
    for (int i=0;i<4;i++)
        for (int j=0;j<4;j++)
        {
            if (i==j) m[i][j]=1.0;
            else m[i][j]=0.0;
        }
}
void copy(Matrix m,Matrix a)
{
    for (int i=0;i<4;i++)
        for (int j=0;j<4;j++)
            m[i][j]=a[i][j];
}
void multiply(Matrix m,Matrix b,Matrix a)
{
    for (int i=0;i<4;i++)
        for (int j=0;j<4;j++)
        {
            m[i][j]=0.0;
            for (int k=0;k<4;k++)
                m[i][j]+=a[i][k]*b[k][j];
        }
}
void power(Matrix m,Matrix a,unsigned n)
{
    Matrix u;
    copy(u,a);
    identity(m);
    for (unsigned i=1;i<=n;i<<=1)
    {
        Matrix t;
        if (i&n)
        {
            multiply(t,m,u);
            copy(m,t);
        }
        multiply(t,u,u);
        copy(u,t);
    }
}

const int MAXDEPTH=1024;
int top;
Matrix stack[MAXDEPTH];
unsigned repeat[MAXDEPTH];

int main()
{
    for (;;)
    {
        int n;
        scanf("%d",&n);
        if (n==0) break;
        identity(stack[top=0]);
        for (;;)
        {
            char s[1024];
            scanf("%s",s);
            Matrix t,tt;
            double x,y,z,d;
            if (strcmp(s,"end")==0)
            {
                if (top==0) break;
                else
                {
                    power(tt,stack[top],repeat[top]);
                    top--;
                    multiply(t,stack[top],tt);
                }
            }
            else if (strcmp(s,"translate")==0)
            {
                scanf("%lf%lf%lf",&x,&y,&z);
                translate(tt,x,y,z);
                multiply(t,stack[top],tt);
            }
            else if (strcmp(s,"scale")==0)
            {
                scanf("%lf%lf%lf",&x,&y,&z);
                scale(tt,x,y,z);
                multiply(t,stack[top],tt);
            }
            else if (strcmp(s,"rotate")==0)
            {
                scanf("%lf%lf%lf%lf",&x,&y,&z,&d);
                rotate(tt,x,y,z,d);
                multiply(t,stack[top],tt);
            }
            else
            {
                top++;
                scanf("%u",&repeat[top]);
                identity(t);
            }
            copy(stack[top],t);
        }
        for (int t=0;t<n;t++)
        {
            double v[4]={0.0,0.0,0.0,1.0};
            for (int i=0;i<3;i++)
                scanf("%lf",&v[i]);
            for (int i=0;i<3;i++)
            {
                double get=0.0;
                for (int j=0;j<4;j++)
                    get+=stack[top][i][j]*v[j];
                if (fabs(get)<0.0001) printf("0.00%c",i+1==3?'\n':' ');
                else printf("%.2f%c",get,i+1==3?'\n':' ');
            }
        }
        printf("\n");
    }
    return 0;
}

