/*
AUTHOR: Su Jiao
DATE: 2010-7-23
DESCRIPTION:
$DESCRIPTION
*/
#include <stdio.h>
#include <string.h>

#define max(a,b) ((a)>(b)?(a):(b))
const int LOG2_MAXLENGTH=16;
const int MAXLENGTH=1<<LOG2_MAXLENGTH;
const int MAXALPHABET=1024;
typedef int string[MAXLENGTH];
int sort[max(MAXLENGTH,MAXALPHABET)];
int _SA[MAXLENGTH],_rank[MAXLENGTH],_TSA[MAXLENGTH],_Trank[MAXLENGTH];
int* SA=_SA;
int* rank=_rank;
int* TSA=_TSA;
int* Trank=_Trank;
void get_SA(string s,int length)
{
     memset(sort,0,sizeof(sort));
     for (int i=1;i<=length;i++) sort[s[i]]++;
     for (int i=1;i<MAXALPHABET;i++) sort[i]+=sort[i-1];
     for (int i=1;i<=length;i++) SA[sort[s[i]]--]=i;
     rank[SA[1]]=1;
     for (int i=2;i<=length;i++)
         if (s[SA[i]]==s[SA[i-1]]) rank[SA[i]]=rank[SA[i-1]];
         else rank[SA[i]]=rank[SA[i-1]]+1;
     for (int block=1;block<length;block<<=1)
     {
         for (int i=1;i<=length;i++) sort[rank[SA[i]]]=i;
         for (int i=length;i>=1;i--)
             if (SA[i]-block>=1)
                TSA[sort[rank[SA[i]-block]]--]=SA[i]-block;
         for (int i=length-block+1;i<=length;i++)
             TSA[sort[rank[i]]--]=i;
         Trank[TSA[1]]=1;
         for (int i=2;i<=length;i++)
             if (rank[TSA[i]]==rank[TSA[i-1]]
                 &&rank[TSA[i]+block]==rank[TSA[i-1]+block])
                Trank[TSA[i]]=Trank[TSA[i-1]];
             else Trank[TSA[i]]=Trank[TSA[i-1]]+1;
         int* swap;
         swap=SA,SA=TSA,TSA=swap;
         swap=rank,rank=Trank,Trank=swap;
     }
}
int height[MAXLENGTH];
void get_height(string s,int length)
{
     for (int h=0,i=1;i<=length;i++)
     {
         if (h) h--;
         if (rank[i]!=1)
         {
            int j=SA[rank[i]-1];
            while (s[i+h]==s[j+h]) h++;
         }
         height[rank[i]]=h;
     }
}

int n,a,b;
string s;
bool check(int value)
{
     #define abs(a) ((a)>=0?(a):-(a))
     int i=1;
     while (i<n)
     {
           while (i<n&&height[i]<value) i++;
           int first=n,last=0;
           if (i!=1) first=SA[i-1],last=SA[i-1];
           while (i<n&&height[i]>=value)
           {
                 if (SA[i]<first) first=SA[i];
                 if (SA[i]>last) last=SA[i];
                 i++;
           }
           if (last-first>=value) return true;
     }
     return false;
}
int main()
{
    for (;;)
    {
        scanf("%d",&n);
        if (!n) break;
        scanf("%d",&b);
        for (int i=1;i<n;i++)
            a=b,scanf("%d",&b),s[i]=(MAXALPHABET>>1)+b-a;
        s[n]=0;
        get_SA(s,n-1);
        get_height(s,n-1);
        int L=0,R=n;
        while (L+1!=R)
        {
              int mid=(L+R)>>1;
              if (check(mid)) L=mid;
              else R=mid;
        }
        if (L+1>=5) printf("%d\n",L+1);
        else printf("%d\n",0);
    }
}
