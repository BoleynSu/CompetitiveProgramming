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

int SA[MAXLENGTH],rank[MAXLENGTH],TSA[MAXLENGTH],Trank[MAXLENGTH];

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

         memcpy(SA,TSA,sizeof(SA));

         memcpy(rank,Trank,sizeof(rank));

     }

}

int height[MAXLENGTH];

int get_height(string s,int length)

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

int t,n;

string s;

int length;

int id[MAXLENGTH];

bool check(int value)

{

     int i=1;

     while (i<=length)

     {

           while (i<=length&&height[i]<value) i++;

           bool found[MAXN];

           memset(found,0,sizeof(found));

           if (i!=1) found[id[SA[i-1]]]=true;

           while (i<=length&&height[i]>=value)

           {

                 found[id[SA[i]]]=true;

                 i++;

           }

           bool all_found=true;

           for (int j=1;j<=n;j++) if (!found[j]) all_found=false;

           if (all_found) return true;

     }

     return false;

}

int main()

{

    scanf("%d",&t);

    for (int tt=0;tt<t;tt++)

    {

        length=0;

        scanf("%d",&n);

        for (int i=1;i<=n;i++)

        {

            char input_string[MAXLENGTH];

            char* input=input_string-1;

            scanf("%s",&input_string);

            int dlength=strlen(input_string);

            for (int j=1;j<=dlength;j++)

            {

                s[length+j]=(n<<1)+1+unsigned(input[j]);

                id[length+j]=i;

            }

            length+=dlength+1;

            s[length]=i<<1;

            for (int j=1;j<=dlength;j++)

            {

                s[length+j]=(n<<1)+1+unsigned(input[dlength-j+1]);

                id[length+j]=i;

            }

            length+=dlength+1;

            s[length]=(i<<1)|1;

        }

        s[length+1]=0;

        get_SA(s,length);

        get_height(s,length);

        int L=0,R=length+1;

        while (L+1!=R)

        {

              int mid=(L+R)>>1;

              if (check(mid)) L=mid;

              else R=mid;

        }

        if (n==1) printf("%d\n",(length>>1)-1);

        else printf("%d\n",L);

    }

}
