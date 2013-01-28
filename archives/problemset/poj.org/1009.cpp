#include <cstdio>
using namespace std;

int width;
int counter;
int c[1024*1024],p[1024*1024];
int sp[1024*1024];
int otop;
int oc[1024*1024],op[1024*1024];
const int ds=9;
const int dx[ds]={-1,-1,-1,0,0,0,1,1,1};
const int dy[ds]={-1,0,1,-1,0,1,-1,0,1};

int abs(int n)
{
    return n>=0?n:-n;
}
int max(int a,int b)
{
    return a>b?a:b;
}

int get_color(int n)
{
    int base;
    {
        int L=0,R=counter;
        while (L+1!=R)
        {
              int mid=(L+R)/2;
              if (sp[mid]-p[mid]>n) R=mid;
              else L=mid;
        }
        base=c[L];
    }
    int x=n/width,y=n%width;
    int color=0;
    for (int i=0;i<ds;i++)
    {
        int nx=x+dx[i],ny=y+dy[i];
        if (ny>=width||ny<0||nx<0||nx*width+ny>=sp[counter]) continue;
        int nn=nx*width+ny;
        int L=0,R=counter;
        while (L+1!=R)
        {
              int mid=(L+R)/2;
              if (sp[mid]-p[mid]>nn) R=mid;
              else L=mid;
        }
        color=max(abs(c[L]-base),color);
    }
    return color;
}

void sort(int l,int r)
{
     int i=l,j=r;
     int mid=op[(i+j)>>1];
     while (i<=j)
     {
           while (op[i]<mid) i++;
           while (op[j]>mid) j--;
           if (i<=j)
           {
              int swap;
              swap=op[i];
              op[i]=op[j];
              op[j]=swap;
              swap=oc[i];
              oc[i]=oc[j];
              oc[j]=swap;
              i++;
              j--;
           }
     }
     if (l<j) sort(l,j);
     if (i<r) sort(i,r);
}

int main()
{
    for (;;)
    {
        scanf("%d",&width);
        if (!width) break;
        for (counter=0;;counter++)
        {
            scanf("%d%d",c+counter,p+counter);
            if (counter) sp[counter]=sp[counter-1]+p[counter];
            else sp[counter]=p[counter];
            if (!c[counter]&&!p[counter]) break;
        }
        
        otop=0;
        for (int t=0;t<counter;t++)
        {
            int x=(sp[t]-p[t])/width,y=(sp[t]-p[t])%width;
            for (int i=0;i<ds;i++)
            {
                int nx=x+dx[i],ny=y+dy[i];
                if (ny>=width||ny<0||nx<0||nx*width+ny>=sp[counter]) continue;
                int nn=nx*width+ny;
                oc[otop]=get_color(nn);
                op[otop]=nn;
                otop++;
            }
        }
        int x=sp[counter]/width,y=sp[counter]%width;
        for (int i=0;i<ds;i++)
        {
            int nx=x+dx[i],ny=y+dy[i];
            if (ny>=width||ny<0||nx<0||nx*width+ny>=sp[counter]) continue;
            int nn=nx*width+ny;
            oc[otop]=get_color(nn);
            op[otop]=nn;
            otop++;
        }
        sort(0,otop-1);
        
        int ntop=0;
        for (int i=0,j;i<otop;i=j)
        {
            oc[ntop]=oc[i];
            op[ntop]=op[i];
            for (j=i;j<otop;j++)
                if (oc[i]!=oc[j]) break;
            ntop++;
        }
        op[ntop]=sp[counter];
        printf("%d\n",width);
        for (int i=0;i<ntop;i++)
            printf("%d %d\n",oc[i],op[i+1]-op[i]);
        printf("0 0\n");
    }
    printf("0\n");
    return 0;
}
