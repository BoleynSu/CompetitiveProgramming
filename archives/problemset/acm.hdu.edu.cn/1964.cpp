/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2011-11-26
DESCRIPTION:
$DESCRIPTION
*/
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long int lli;
const int MAXN=12;
const int MAXSTATE=300001;
int N,M;
int mapd[MAXN][MAXN];
int mapr[MAXN][MAXN];
int sc,SC;
int s_[MAXSTATE],S_[MAXSTATE];
lli f_[MAXSTATE],F_[MAXSTATE];
int* s=s_;
int* S=S_;
lli* f=f_;
lli* F=F_;
void qsort(int l,int r)
{
     int i=l,j=r;
     int mid=S[(l+r)>>1];
     while (i<=j)
     {
           while (S[i]<mid) i++;
           while (S[j]>mid) j--;
           if (i<=j)
           {
              int SS;
              lli SF;
              SS=S[i],S[i]=S[j],S[j]=SS,SF=F[i],F[i]=F[j],F[j]=SF;
              i++,j--;
           }
     }
     if (l<j) qsort(l,j);
     if (i<r) qsort(i,r);
}
lli min(lli a,lli b)
{
    return a<b?a:b;
}
bool read(int& x)
{
     char get;
     for (;;)
     {
         get=getchar();
         if (get==EOF) return false;
          if (get>='0'&&get<='9')
          {
              x=get-'0';
              for (;;)
             {
                 get=getchar();
                 if (get>='0'&&get<='9') x=x*10+get-'0';
                 else return true;
             }
         }
     }
}

int run()
{
    read(N);
    read(M);
    for (int i=0;i<N-1;i++)
    {
        for (int j=0;j<M-1;j++)
            read(mapr[i][j]);
        for (int j=0;j<M;j++)
            read(mapd[i][j]);
    }
    for (int j=0;j<M-1;j++)
        read(mapr[N-1][j]);

    lli answer=(~0u);

    SC=0;
    S[SC]=0;
    F[SC]=0;
    SC++;
    for (int i=0;i<N;i++)
    {
        for (int j=0;j<M;j++)
        {
            int* ss;
            lli* sf;
            ss=s,s=S,S=ss,sf=f,f=F,F=sf;
            sc=SC,SC=0;

            #define getp(state,p) (((state)>>((p)<<1))&3)
            #define replace(state,p,n) (((state)&(~(3<<((p)<<1))))|n<<((p)<<1))
            #define getl(state) getp(state,j)
            #define getu(state) getp(state,j+1)
            #define replacedr(state,d,r) replace(replace(state,j,d),j+1,r)
            #define getcl(state,p,ns)\
            do\
            {\
              ns=replacedr(state,0,0);\
              int get=2;\
              for (int i=p+2;i<=M;i++)\
              {\
                  if (getp(ns,i)==1) get++;\
                  else if (getp(ns,i)==2) get--;\
                  if (get==1)\
                  {\
                     ns=replace(ns,i,1);\
                     break;\
                  }\
              }\
            }\
            while (false)
            #define getcr(state,p,ns)\
            do\
            {\
              ns=replacedr(state,0,0);\
              int get=2;\
              for (int i=p-1;i>=0;i--)\
              {\
                  if (getp(ns,i)==2) get++;\
                  else if (getp(ns,i)==1) get--;\
                  if (get==1)\
                  {\
                     ns=replace(ns,i,2);\
                     break;\
                  }\
              }\
            }\
            while (false)
            for (int si=0;si<sc;si++)
            {
                int l=getl(s[si]),u=getu(s[si]);
                if (l&&u)
                {
                   int ns;
                   if (l==2&&u==1) ns=replacedr(s[si],0,0);
                   else if (l==1&&u==1) getcl(s[si],j,ns);
                   else if (l==2&&u==2) getcr(s[si],j,ns);
                   else
                   {
                       if (i==N-1&&j==M-1&&replacedr(s[si],0,0)==0) answer=min(answer,f[si]);
                         continue;
                   }
                   S[SC]=ns;
                   F[SC]=f[si];
                   SC++;
                }
                else if (l)
                {
                     int ns;
                     ns=replacedr(s[si],l,u);
                     S[SC]=ns;
                     F[SC]=f[si]+mapd[i][j];
                     SC++;
                     ns=replacedr(s[si],u,l);
                     S[SC]=ns;
                     F[SC]=f[si]+mapr[i][j];
                     SC++;
                }
                else if (u)
                {
                     int ns;
                     ns=replacedr(s[si],l,u);
                     S[SC]=ns;
                     F[SC]=f[si]+mapr[i][j];
                     SC++;
                     ns=replacedr(s[si],u,l);
                     S[SC]=ns;
                     F[SC]=f[si]+mapd[i][j];
                     SC++;
                }
                else
                {
                     int ns;
                     /*
                     //there can not be a box without plug
                     ns=replacedr(s[si],0,0);
                     S[SC]=ns;
                     F[SC]=f[si];
                     SC++;
                     */
                     ns=replacedr(s[si],1,2);
                     S[SC]=ns;
                     F[SC]=f[si]+mapr[i][j]+mapd[i][j];
                     SC++;
                }
            }
            {
                qsort(0,SC-1);
                int RSC=0;
                int i=0;
                while (i<SC)
                {
                      int j=i+1;
                      while (j<SC&&S[i]==S[j]) F[i]=min(F[j],F[i]),j++;
                      S[RSC]=S[i];
                      F[RSC++]=F[i];
                      i=j;
                }
                SC=RSC;
            }
        }
        {
            int RSC=0;
            int i=0;
            while (i<SC)
            {
                  while (i<SC&&getp(S[i],M)) i++;
                  if (i<SC) S[RSC]=S[i]<<(1<<1),F[RSC++]=F[i++];
            }
            SC=RSC;
        }
    }
    printf("%d\n",int(answer));
    return 0;
}

int main()
{
    int T;
    for (read(T);T;T--) run();
}

