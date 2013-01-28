/*
AUTHOR: Su Jiao
DATE: 2010-7-23
DESCRIPTION:
$DESCRIPTION
*/
#include <stdio.h>
#include <string.h>

#define max(a,b) ((a)>(b)?(a):(b))
const int LOG2_MAXLENGTH=20;
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

const int MAXN=1000;
int n;
int length;
int id[MAXLENGTH];
string s;
char input_string[MAXLENGTH];
char* input=input_string-1;
int times;
int found[MAXN];
bool check(int value)
{
     int i=1;
     while (i<=length)
     {
           times++;
           while (i<=length&&height[i]<value) i++;
           int found_count=0;
           if (i!=1) found[id[SA[i-1]]]=times,found_count++;
           while (i<=length&&height[i]>=value)
           {
                 if (found[id[SA[i]]]!=times)
                    found[id[SA[i]]]=times,found_count++;
                 i++;
           }
           if (found_count*2>n) return true;
     }
     return false;
}
void print(int value)
{
     int i=1;
     while (i<=length)
     {
           times++;
           while (i<=length&&height[i]<value) i++;
           int found_count=0;
           if (i!=1) found[id[SA[i-1]]]=times,found_count++;
           while (i<=length&&height[i]>=value)
           {
                 if (found[id[SA[i]]]!=times)
                    found[id[SA[i]]]=times,found_count++;
                 i++;
           }
           if (found_count*2>n)
           {
              for (int j=SA[i-1];j<SA[i-1]+value;j++) printf("%c",s[j]-n);
              printf("\n");
           }
     }
}
int main()
{
    bool first=true;
    for (;;)
    {
        scanf("%d",&n);
        if (!n) break;
        length=0;
        for (int i=1;i<=n;i++)
        {
            scanf("%s",&input_string);
            int dlength=strlen(input_string);
            for (int j=1;j<=dlength;j++)
                s[length+j]=n+input[j],
                id[length+j]=i;
            length+=dlength+1;
            s[length]=i;
            id[length]=0;
        }
        s[length+1]=0;
        get_SA(s,length);
        get_height(s,length);
        int L=0,R=length;
        while (L+1!=R)
        {
              int mid=(L+R)>>1;
              if (check(mid)) L=mid;
              else R=mid;
        }
        if (first) first=false;
        else printf("\n");
        if (n==1)
        {
           for (int i=1;i<length;i++) printf("%c",s[i]-n);
           printf("\n");
        }
        else if (L) print(L);
        else printf("?\n");        
    }
}
