#include <cstdio>
#include <algorithm>
using namespace std;

struct Data
{
       char s[128];
       int unsortedness;
};

int n,m;
Data data[1024];

void get_unsortedness(Data& data)
{
     int A=0,C=0,G=0,T=0;
     data.unsortedness=0;
     for (int i=0;i<n;i++)
     {
         switch (data.s[i])
         {
                case 'A':
                     data.unsortedness+=C;
                case 'C':
                     data.unsortedness+=G;
                case 'G':
                     data.unsortedness+=T;
                case 'T':
                     ;
         }
         switch (data.s[i])
         {
                case 'A':
                     A++;
                     break;
                case 'C':
                     C++;
                     break;
                case 'G':
                     G++;
                     break;
                case 'T':
                     T++;
                     break;
         }
     }
}
bool operator<(const Data& a,const Data& b)
{
     return a.unsortedness<b.unsortedness;
}

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++)
    {
        scanf("%s",data[i].s);
        get_unsortedness(data[i]);
    }
    stable_sort(data,data+m);
    for (int i=0;i<m;i++)
        printf("%s\n",data[i].s);
    return 0;
}
