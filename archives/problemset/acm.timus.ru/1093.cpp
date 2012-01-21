/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-4-14
DESCRIPTION:
$DESCRIPTION
*/
#include <stdio.h>
#include <math.h>

#define g 10.0f
#define zero(n) (-1e-9<=n&&n<=1e-9)
#define oo 1e16

struct Point
{
       double x,y,z;
       Point(){}
       Point(double _x,double _y,double _z):x(_x),y(_y),z(_z){}
};

Point C,N,S,V;
double R;

bool check(double t)
{
     if (t<0) return false;
     Point M(S.x+V.x*t,S.y+V.y*t,S.z+V.z*t-(g*t*t)/2);
     Point d(M.x-C.x,M.y-C.y,M.z-C.z);
     double distance_sqr=d.x*d.x+d.y*d.y+d.z*d.z;
     if (distance_sqr<R*R) return true;
     else return false;
}

int main()
{
    scanf("%lf %lf %lf %lf %lf %lf %lf\n"
          "%lf %lf %lf %lf %lf %lf\n",
          &C.x,&C.y,&C.z,&N.x,&N.y,&N.z,&R,
          &S.x,&S.y,&S.z,&V.x,&V.y,&V.z);
    /*
    M=S+V*t+(0,0,-(g*t^2)/2)
    (M-C)*N=0
    distance(M,C)<R
    сп╫Б?HIT:MISSED
    
    (M-C)*N=0
    => (Mx-Cx)*(Nx)+(My-Cy)*(Ny)+(Mz-Cz)*(Nz)=0
    => (Sx+Vx*t-Cx)*(Nx)+(Sy+Vy*t-Cy)*(Ny)+(Sz+Vz*t-(g*t^2)/2-Cz)*(Nz)=0
    => (-g*Nz)/2*t^2
       +(Vx*Nx+Vy*Ny+Vz*Nz)*t
       +(Sx*Nx+Sy*Ny+Sz*Nz-Cx*Nx-Cy*Ny-Cz*Nz)
       =0
    */
    bool have_answer=false;
    double a=(-g*N.z)/2,
           b=(V.x*N.x+V.y*N.y+V.z*N.z),
           c=(S.x*N.x+S.y*N.y+S.z*N.z-C.x*N.x-C.y*N.y-C.z*N.z);
    double t;
    if (!zero(a))
    {
       double delta=b*b-4.0*a*c;
       if (delta>0||zero(delta))
       {
          if (zero(delta)) delta=0;
          double t1=(-b+sqrt(delta))/(2*a),
                 t2=(-b-sqrt(delta))/(2*a);
          if (t1>=0)
            if (check(t=t1))
               have_answer=true;
          if (t2>=0)
            if (check(t=t2))
               have_answer=true;
       }
    }
    else
    {
        if (!zero(b))
           if (check(t=-c/b))
              have_answer=true;
    }
    
    if (have_answer) printf("HIT\n");
    else printf("MISSED\n");
    return 0;
}
