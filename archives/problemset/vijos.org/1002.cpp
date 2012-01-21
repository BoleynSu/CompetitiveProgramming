#include <iostream>
using namespace std;

__int64 L,S,T,M,P[100+2];
#define f(a) (a+100)%100
__int64 F[100];
//F[a] //on the way to P[a] you must touch F[a] stone(s);
//F[a]=F[a-i]+(if (some P[x]=a)then 1;else 0) {for i=S to T}

void ini()
{
     cin>>L>>S>>T>>M;
     for (__int64 i=1;i<=M;i++)
         cin>>P[i];
}

void sort()
{
     for (__int64 i=1;i<=M;i++)
         for (__int64 j=i+1;j<=M;j++)
             if (P[i]>P[j])
             {
                __int64 swap=P[i];
                P[i]=P[j];
                P[j]=swap;
             }
}

int gcd(int a,int b)
{
    if (!(a%b)) return b;
    else return gcd(b,a%b);
}

int isStone(int pos)
{
    for (int i=1;i<=M;i++)
        if (P[i]==pos)
           return 1;
    return 0;
}

void del()
{
     while (P[M]>L) M--;
     
     int delDis=S;
     for (int i=S+1;i<=T;i++)
         delDis=(delDis*i)/gcd(delDis,i);
     P[0]=0;
     P[M+1]=L;
     for (int i=0;i<=M;i++)
     {
         int times=(P[i+1]-P[i])/delDis;
         if (((P[i+1]-P[i])/delDis)>0) times--;
         int newDis=delDis*times;
         if (newDis!=0)
         {
            for (int j=i+1;j<=M+1;j++)
                P[j]-=newDis;
         }
     }
     L=P[M+1];
}

void DP()
{
     F[f(0)]=isStone(0);
     for (int k=1;k<=L+T-1;k++)
     {
         F[f(k)]=102;
         for (int i=S;i<=T;i++)
         {
             if ((k-i)>=0)
                F[f(k)]=min(F[f(k-i)]+isStone(k),F[f(k)]);
         }
     }
}

void output()
{
     int answer=102;
     for (int i=L;i<=L+T-1;i++)
         if (F[f(i)]<answer)
            answer=F[f(i)];
     cout<<answer<<endl;
}

void get()
{
     ini();
     sort();
     del();
     DP();
     output();
}

int main()
{
    get();
    return 0;
}
