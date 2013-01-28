

#include<iostream>

#include<stdio.h>

#include<math.h>

#include<algorithm>

#include<string.h>

using namespace std;

#define eps 1e-8

#define pi acos(-1.0)

#define sqr(x) ((x)*(x))

 

int sign(double x){

    if(x<-eps) return -1;

    return x>eps;

}

int zero(double x){

    if(sign(x)==0) return 1;

    return 0;

}

//判两三角形全等 ,三边相等 

bool eq(double a1,double b1,double c1,double a2,double b2,double c2){

    if(zero(a1-a2)&&zero(b1-b2)&&zero(c1-c2)) return true;

    if(zero(a1-a2)&&zero(b1-c2)&&zero(c1-b2)) return true;

    if(zero(a1-b2)&&zero(b1-a2)&&zero(c1-c2)) return true;

    if(zero(a1-b2)&&zero(b1-c2)&&zero(c1-a2)) return true;

    if(zero(a1-c2)&&zero(b1-a2)&&zero(c1-b2)) return true;

    if(zero(a1-c2)&&zero(b1-b2)&&zero(c1-a2)) return true;

    return false;

}

 

struct point{

    double x,y; 

    point(){}

    point(double x,double y):x(x),y(y){}

     bool operator ==(const point &b)const{

       return sign(x-b.x)==0 && sign(y-b.y)==0; 

    }

    void in(){

        scanf("%lf %lf",&x, &y);

    }

    void out(){

        printf("%.2lf %.2lf\n",x ,y);

    }

}T1[10],T2[10],q[10],p[10];

 

double t1a,t1b,t1c,t2a,t2b,t2c;

 

double xmult(point a,point b,point o){

   return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x); 

}

double dis(point a,point b){

   return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));

}

bool cmp(const point &a,const point &b){

   return sign(a.y-b.y)<0 || (sign(a.y-b.y)==0 && sign(a.x-b.x)<0); 

}

point intersection(point u1,point u2,point v1,point v2){

   point ret=u1;

   double t=((u1.x-v1.x)*(v1.y-v2.y)-(u1.y-v1.y)*(v1.x-v2.x))

           /((u1.x-u2.x)*(v1.y-v2.y)-(u1.y-u2.y)*(v1.x-v2.x));

          ret.x+=(u2.x-u1.x)*t;

          ret.y+=(u2.y-u1.y)*t;

    return ret;

}

bool cmp2(const point &a,const point &b){

   double t=xmult(a,b,p[0]);

   if(sign(t)>0) return true;

   if(sign(t)==0 && dis(a,p[0])<dis(b,p[0])) return true;

   return false; 

}

 

void tubao(int &n){

     sort(p ,p + n ,cmp); 

     int cnt=0;

     for(int i=1;i<n;i++){    //去掉相同的点 

        if(p[i]==p[cnt]) continue;     

        p[++cnt]=p[i];      

     }                 

     n=++cnt;

     sort(p + 1, p + n, cmp2); 

     if(n<=2) return; // 只有1个或2个点 

     int j=2;

     while(j<n && sign(xmult(p[j],p[j-1],p[j-2]))==0) j++;

     if(j>=n) {p[1]=p[n-1];n=2;return;}   //所有点共线 

     p[n]=p[0];

     int top=1;

     for(int i=2;i<=n;i++){

        while(top>0 && sign(xmult(p[i],p[top],p[top-1]))>=0) top--;

        p[++top]=p[i];    

     }

     n=top;

}

int next_(int i){

    if(i==3) return 0;

    return i+1;

}

int pre_(int i){

    if(i==0) return 3;

    return i-1;

}

int next(int i){

    if(i==2) return 0;

    return i+1;

}

int pre(int i){

    if(i==0) return 2;

    return i-1;

}

double area(int n,point *k){

    double s=0.0;

    for(int i=0;i<n;i++){

        s+=k[i].x*k[(i+1)%n].y-k[(i+1)%n].x*k[i].y;

    }

    return s;

}

int main(){

    int ca;

    cin>>ca;

    double a,b,c,aa,bb,cc;

    for(int cas=1;cas<=ca;cas++){

        printf("Case #%d: ",cas);

        for(int i=0;i<=2;i++) T1[i].in();

        for(int i=0;i<=2;i++) T2[i].in();

        

        t1a=dis(T1[0],T1[1]);

        t1b=dis(T1[1],T1[2]);

        t1c=dis(T1[2],T1[0]);

        t2a=dis(T2[0],T2[1]);

        t2b=dis(T2[1],T2[2]);

        t2c=dis(T2[2],T2[0]);

        

        for(int i=0;i<=3;i++) {

           p[i].in();

           q[i]=p[i]; 

        }

        int n=4;

        tubao(n);

        if(n==4){

            int f=0;

            aa=a=dis(p[0],p[2]);

            b=dis(p[0],p[1]);

            c=dis(p[1],p[2]);

            bb=dis(p[0],p[3]);

            cc=dis(p[2],p[3]);

            if(eq(a,b,c,t1a,t1b,t1c) && eq(aa,bb,cc,t2a,t2b,t2c)){

               f=1; 

            }

            if(eq(aa,bb,cc,t1a,t1b,t1c) && eq(a,b,c,t2a,t2b,t2c)){

               f=1; 

            }

            aa=a=dis(p[1],p[3]);

            b=dis(p[0],p[1]);

            c=dis(p[3],p[0]);

            bb=dis(p[1],p[2]);

            cc=dis(p[2],p[3]);

            if(eq(a,b,c,t1a,t1b,t1c) && eq(aa,bb,cc,t2a,t2b,t2c)){

               f=1; 

            }

            if(eq(aa,bb,cc,t1a,t1b,t1c) && eq(a,b,c,t2a,t2b,t2c)){

               f=1; 

            }

            if(f) puts("Yes");

            else puts("No");

        }

        else {

            int index=-1;

            for(int i=0;i<4;i++){

               if(zero(xmult(q[i],q[(i+1)%4],q[(i+2)%4]))){

                  index=i;break;  

               } 

            }

            if(index==-1){  //没有退化, 是凹的 

               double s=area(4,q);

               if(sign(s)<0) reverse(q,q+4);

               //for(int i=0;i<4;i++) q[i].out();

               int now=-1;

               //找到凹的那个点 让它做第二个点 

               for(int i=0;i<=3;i++){

                  if(sign(xmult(q[next_(i)],q[pre_(i)],q[i]))<0){

                     now=i;break;   

                  } 

               }

               if(now==-1) while(1);

               p[2]=q[now];  

               int tag=2;

               for(int i=1;i<=3;i++){

                  p[next_(tag)]=q[next_(now)];    

                  tag=next_(tag); 

                  now=next_(now);

               } 

               int f=0;

               aa=a=dis(p[0],p[2]);

               b=dis(p[0],p[1]);

               c=dis(p[1],p[2]);

               bb=dis(p[0],p[3]);

               cc=dis(p[2],p[3]);

               if(eq(a,b,c,t1a,t1b,t1c) && eq(aa,bb,cc,t2a,t2b,t2c)){

                 f=1; 

               }

               if(eq(aa,bb,cc,t1a,t1b,t1c) && eq(a,b,c,t2a,t2b,t2c)){

                 f=1; 

               }  

                            

               point ret=intersection(p[0],p[1],p[2],p[3]);

               a=dis(ret,p[1]);b=dis(p[1],p[2]);c=dis(ret,p[2]);

               aa=dis(ret,p[0]);bb=dis(p[0],p[3]);cc=dis(ret,p[3]);

               if(eq(a,b,c,t1a,t1b,t1c) && eq(aa,bb,cc,t2a,t2b,t2c)){

                 f=1; 

               }

               if(eq(aa,bb,cc,t1a,t1b,t1c) && eq(a,b,c,t2a,t2b,t2c)){

                 f=1; 

               }

               

               ret=intersection(p[0],p[3],p[1],p[2]);

               a=dis(p[0],p[1]);b=dis(p[0],ret);c=dis(p[1],ret);

               aa=dis(p[2],p[3]);bb=dis(p[2],ret);cc=dis(p[3],ret);

               if(eq(a,b,c,t1a,t1b,t1c) && eq(aa,bb,cc,t2a,t2b,t2c)){

                 f=1; 

               }

               if(eq(aa,bb,cc,t1a,t1b,t1c) && eq(a,b,c,t2a,t2b,t2c)){

                 f=1; 

               }

               if(f) puts("Yes");

               else  puts("No");

            }

            else{//退化成三角形 

                int f=0;

                 a=dis(p[0],p[1]);

                 b=dis(p[1],p[2]);

                 c=dis(p[2],p[0]);

                 

                double s=area(3,T2);

                if(sign(s)<0) reverse(T2,T2+3);

                

                for(int i=0;i<3;i++)

                {  double len2=dis(T2[i],T2[next(i)]);

                   for(int j=0;j<3;j++)

                   {

                     double len1=dis(T1[j],T1[next(j)]);

                     if(sign(len1-len2)) continue;

                     int i2=next(i);

                     int i3=next(i2);

                     int j2=next(j);

                     int j3=next(j2);

                     

                     double k1=dis(T1[j],T1[j2]);

                     double k2=dis(T1[j2],T1[j3]);    

                     double k3=dis(T1[j],T1[j3]);    

                     double aph1=acos((sqr(k1)+sqr(k3)-sqr(k2))/(2.0*k1*k3));

                     double aph2=acos((sqr(k1)+sqr(k2)-sqr(k3))/(2.0*k1*k2));

                     

                     

                     double kk1=dis(T2[i],T2[i2]);

                     double kk2=dis(T2[i2],T2[i3]);

                     double kk3=dis(T2[i],T2[i3]);

                     double aph11=acos((sqr(kk1)+sqr(kk3)-sqr(kk2))/(2.0*kk1*kk3));

                     double aph22=acos((sqr(kk1)+sqr(kk2)-sqr(kk3))/(2.0*kk1*kk2));

                     

                     if(zero(aph1+aph11-pi)){

                        if(eq(a,b,c,k2,kk2,k3+kk3)){

                           f=1; 

                        }    

                     }

                     if(zero(aph2+aph22-pi)){

                        if(eq(k2+kk2,k3,kk3,a,b,c)){

                           f=1; 

                        }    

                     }

                     if(zero(aph2+aph11-pi)){

                        if(eq(k3,kk2,k2+kk3,a,b,c)){

                           f=1; 

                        }    

                     }

                     if(zero(aph1+aph22-pi)){

                        if(eq(k3+kk2,k2,kk3,a,b,c)){

                           f=1; 

                        }    

                     }

                   }  

                }

                if(f) puts("Yes"); 

                else puts("No");

            }

        }

    }

}

