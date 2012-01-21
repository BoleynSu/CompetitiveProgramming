#include<stdio.h> 
int N; 
int a[2000]={6,2,5,5,4,5,6,3,7,6}; 
int n,total=0; 
void pre_doing() 
{ 
   int i; 
   for (i=10;i<=99;i++) a[i]=a[i%10]+a[i/10]; 
   for (i=100;i<=999;i++) a[i]=a[i/100]+a[(i%100)/10]+a[i%10]; 
   for (i=1000;i<=1999;i++) a[i]=a[i/1000]+a[(i%1000)/100]+a[(i%100)/10]+a[i%10]; 
} 
void doit() 
{ 
   int i,j; 
   for (i=0;i<N;i++) 
     for (j=0;j<N;j++) 
     if (a[i]+a[j]+a[i+j]==n) total++; 
   printf("%d",total); 
} 

int main() 
{ 
  pre_doing(); 
  scanf("%d",&n); 
  if (n>=23) N=712;else N=112; 
  n-=4; 
  doit(); 
} 
