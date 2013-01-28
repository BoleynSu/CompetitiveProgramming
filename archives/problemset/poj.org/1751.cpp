#include<stdio.h>
#include<math.h>
#include<iomanip> 
using namespace std;
int a[760][760],b[760],f[760],x[760],y[760],pre[760]; //pre[i]用于记录与第i 个点相连的点,输出时是2到N；
int len(int x1,int y1,int x2,int y2)
{
 return ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));   //刚才开始这里开方，丢精度，影响计算结果，干脆不开方，结果对sum不要求!!!
}
int main()
{
    int i,t,j,k,ival,num1,num2,num, MIN ;  
    scanf("%d",&ival); 
 for(i=1;i<=ival;++i)
 { 
  scanf("%d%d",&x[i],&y[i]);
 }
 for(i=1;i<=ival;++i)
 {
  for(j=1;j<=ival;++j)
  { 
   a[i][j]=len(x[i],y[i],x[j],y[j]);
  }
 }  
 scanf("%d",&num);
 for(i=1;i<=num;++i)
 {
  scanf("%d%d",&num1,&num2);
  a[num1][num2]=a[num2][num1]=0; 
 }    
 for(i=1;i<=ival;++i)
 {
  f[i]=0;
  b[i]=a[i][1];
  pre[i]=1;    //将各个点都与1相连
 }
 f[1]=1;    
 for(t=1;t<ival;++t)
 {
  MIN=2147483640 ;
  for(i=2;i<=ival;++i)
  { 
   if(!f[i]&&MIN>b[i])
   {
    MIN=b[i];
    k=i;
   }
  }  
  f[k]=1; 
  for(i=2;i<=ival;++i)
  { 
   if(b[i]>a[i][k]&&!f[i])
   {
    b[i]=a[i][k];
    pre[i]=k;             //找到与t相连的点，如果没有进行到这一步，则说明t与1相连是最短的
   }                     
  }  
 } 
 for(i=2;i<=ival;i++)
 {
  if(a[pre[i]][i]!=0) 
   printf("%d %d\n",pre[i],i); 
 }  
    return 0;
}