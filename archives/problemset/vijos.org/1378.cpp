#include <iostream>
using std::cin;
using std::cout;
using std::endl;

const int MAX=30;
const int K=1000;
typedef int big[MAX];

big F[100][100];
bool flag=0;
int n,m;
int a[100][100];
big f[100];

void print(big);

void set(big num)
{
     //out<<"set"<<endl;
       for (int i=0;i<MAX;i++)
           num[i]=0;
}


void x(big to,big from,int num)
{
     //out<<"x"<<endl;
     set(to);
     int end=MAX-1;
     for (int i=0;i<end;i++)
     {
         to[i]+=(from[i]*num)%K;
         to[i+1]=(from[i]*num)/K;
     }
}
big to2;
void x2(big from,int num)
{
     set(to2);
     int end=MAX-1;
     for (int i=0;i<end;i++)
     {
         to2[i]+=(from[i]*num)%K;
         to2[i+1]=(from[i]*num)/K;
     }
}
big to3;
void x3(big from,int num)
{
     set(to3);
     int end=MAX-1;
     for (int i=0;i<end;i++)
     {
         to3[i]+=(from[i]*num)%K;
         to3[i+1]=(from[i]*num)/K;
     }
}

void addTo(big to,big from)
{
     int end=MAX-1;
     //cout<<"addTo"<<endl;
     //print(to);
     //print(from);
     for (int i=0;i<end;i++)
       {
           to[i]+=from[i];
           to[i+1]+=to[i]/K;
           to[i]%=K;
       }
     //print(to);
}
big add2;
int* ad2(big a,big b)
{
    set(add2);
     int end=MAX-1;
     for (int i=0;i<end;i++)
       {
           add2[i]+=a[i]+b[i];
           add2[i+1]+=add2[i]/K;
           add2[i]%=K;
       }
     return add2;
}
big add3;
int* ad3(big a,big b)
{
    set(add3);
     int end=MAX-1;
     for (int i=0;i<end;i++)
       {
           add3[i]+=a[i]+b[i];
           add3[i+1]+=add3[i]/K;
           add3[i]%=K;
       }
     return add3;
}

void equal(big a,big b)
{
     for (int i=0;i<MAX;i++)
     {
         a[i]=b[i];
     }
}

int* max2(big a,big b)
{
     for (int i=MAX-1;i>=0;i--)
     {
         if (a[i]>b[i]) return a;
         if (a[i]<b[i]) return b;
     }
     return a;
}

void get(int line)
{
     for (int i=0;i<m;i++)
     {
         x(F[m][i],f[m],a[line][i]);
     }
     
     for (int depth=m-1;depth>0;depth--)
     {
         for (int j=0;j<depth;j++)
         {
             x2(f[depth],a[line][j+m-depth]);
             x3(f[depth],a[line][j]);
             
             equal(F[depth][j],
             max2(
             ad2(F[depth+1][j],to2),
             ad3(F[depth+1][j+1],to3)
             )
             );
             //cout<<"d"<<depth<<"["<<j<<","<<j+m-depth<<"]"<<"=";print(F[depth][j]);
         }
     }
}

int* points(int line)//////////////////////////////////
{
    get(line);
    return F[1][0];
}

void print(big num)//////////////////////////////////////////////
{
     int from=MAX-1;
     while((num[from]==0)&&(from>=0)) from--;
     if (from<0) {cout<<0<<endl;return;}
     int flag=0;
     if (num[from]/100){cout<<num[from]/100;flag=1;}
     if (flag||(num[from]%100)/10){ cout<<(num[from]%100)/10;flag=1;}
     if (flag||(num[from]%10))      cout<<(num[from]%10);
     for (int i=from-1;i>=0;i--)
     {
         cout<<num[i]/100;
         cout<<(num[i]%100)/10;
         cout<<num[i]%10;
     }
     cout<<endl;
}

int main()
{
    cin>>n>>m;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            cin>>a[i][j];
    
    big point;
    set(point);
    set(f[1]);
    f[1][0]=2;
    for (int i=2;i<=m;i++)
    {
        x(f[i],f[i-1],2);
    }
    for (int i=0;i<n;i++)
        addTo(point,points(i));
    
    print(point);
    
    while (cin.get()!='q');
    return 0;
}
