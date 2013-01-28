#include <stdio.h>
#include <string.h>

const int LOG2_MAXLENGTH=16;
const int MAXLENGTH=1<<LOG2_MAXLENGTH;
const int MAXALPHABET=1000002;
typedef int string[MAXLENGTH];
int sort[MAXLENGTH];
int _SA[MAXLENGTH],_rank[MAXLENGTH],_TSA[MAXLENGTH],_Trank[MAXLENGTH];
int* SA=_SA;
int* rank=_rank;
int* TSA=_TSA;
int* Trank=_Trank;
void quick_sort(string s,int L,int R)
{
     int i=L,j=R,mid=s[SA[(L+R)>>1]],swap;
     while (i<=j)
     {
           while (s[SA[i]]<mid) i++;
           while (s[SA[j]]>mid) j--;
           if (i<=j)
           {
              swap=SA[i],SA[i]=SA[j],SA[j]=swap;
              i++,j--;
           }
     }
     if (L<j) quick_sort(s,L,j);
     if (i<R) quick_sort(s,i,R);
}
void get_SA(string s,int length)
{
     for (int i=1;i<=length;i++) SA[i]=i;
     quick_sort(s,1,length);
     rank[SA[1]]=1;
     for (int i=2;i<=length;i++)
         if (s[SA[i]]==s[SA[i-1]]) rank[SA[i]]=rank[SA[i-1]];
         else rank[SA[i]]=rank[SA[i-1]]+1;
     for (int block=1;block<length;block<<=1)
     {
         for (int i=1;i<=length;i++) sort[rank[SA[i]]]=i;
         for (int i=length;i>=1;i--)
             if (SA[i]-block>=1) TSA[sort[rank[SA[i]-block]]--]=SA[i]-block;
         for (int i=length-block+1;i<=length;i++)
             TSA[sort[rank[i]]--]=i;
         int* swap;
         swap=SA,SA=TSA,TSA=swap;
         swap=rank,rank=Trank,Trank=swap;
         rank[SA[1]]=1;
         for (int i=2;i<=length;i++)
             if (Trank[SA[i]]==Trank[SA[i-1]]
                 &&Trank[SA[i]+block]==Trank[SA[i-1]+block])
                rank[SA[i]]=rank[SA[i-1]];
             else rank[SA[i]]=rank[SA[i-1]]+1;         
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

int N,K;
string a;
bool check(int value)
{
     int i=1;
     while (i<=N)
     {
           while (i<=N&&height[i]<value) i++;
           int repeat=1;
           while (i<=N&&height[i]>=value)
           {
                 repeat++;
                 i++;
           }
           if (repeat>=K) return true;
     }
     return false;
}
int main()
{
    scanf("%d%d",&N,&K);
    for (int i=1;i<=N;i++) scanf("%d",a+i);
    get_SA(a,N);
    get_height(a,N);
    int L=0,R=N;
    while (L+1!=R)
    {
          int mid=(L+R)>>1;
          if (check(mid)) L=mid;
          else R=mid;
    }
    printf("%d\n",L);
}
