#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <cmath>
using namespace std;
int in[7];
int C[78];
int d[10009];
void init()
{
    C[0]=1;
    for(int i=1;i<70;i++)
    C[i]=6+6*(i-1);
    for(int i=1;i<70;i++)
    C[i]+=C[i-1];

    for(int i=1;i<=5;i++)
    {
        d[i]=i;
        in[i]=1;
    }
	in[6]=1<<25;
    d[6]=2,d[7]=3;
    in[2]++,in[3]++;
    int c=2,num=1; 
    int pre,L,R;
    L=7,R=2;  
    for(int i=8;i<=10000;i++)
    {
        if(num==1) 
        {
            int min=6;
            for(int j=1;j<=5;j++)
            if(in[j]<in[min]&&j!=d[C[c-1]]&&j!=d[C[c-2]+1])
            {
                min=j;
            }
            d[i]=min;
            in[min]++;
            num++;
            pre=i;
            L=R;
            R=L+1;
        }
        else if(num%c!=0)  
        {
            int min=6;
            for(int j=1;j<=5;j++)
            if(in[j]<in[min]&&j!=d[L]&&j!=d[R]&&j!=d[pre])
            {
                min=j;
            }
            d[i]=min;
            in[min]++;
            num++;
            L++;
            R++;
            pre=i;
        }
        else if(i==C[c])  
        {
            int min=6;
            for(int j=1;j<=5;j++)
            if(j!=d[L]&&j!=d[pre]&&in[j]<in[min]&&j!=d[C[c-1]+1])
            {
                min=j;
            }
            d[i]=min;
            in[min]++;
            pre=i;
            num=1;
            L=i;
            c++;
        }
        else  
        {
            int min=6;
            for(int j=1;j<=5;j++)
            if(j!=d[L]&&j!=d[pre]&&in[j]<in[min])
             min=j;

            d[i]=min;
            in[min]++;
            num++;
            pre=i;
            if(i>=C[c])
            {
                num=1;
                L=i;
                c++;

            }
        }
    }
}
int main()
{
    int n,ca;
    init();
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d",&n);
        printf("%d\n",d[n]);
    }
    return 0;
}
