#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int oo=(~0u)>>1;
const int NOT_ASSIGN=-1;
int n,m;
int P[200+2],D[200+2];
int delta[200+2],sum[200+2];
int positive,negative;

typedef int set_size_data[200+2];
typedef bool in_set_data[200+2];
typedef short set_data[200+2][20+2];
set_size_data set_size;
set_size_data set_element[20*20*2+2];
in_set_data _in_set[20*20*2+2];
in_set_data* in_set=_in_set+20*20;
set_data _set[20*20*2+2];
set_data* set=_set+20*20;

void print_answre(int answer)
{
     int answer_list[20+2];
     bool in_answer_list[200+2];
     memset(in_answer_list,0,sizeof(in_answer_list));
     int opt=n;
     for (int i=m;i>=1;i--)
     {
         while (set[answer][opt][i]==set[answer][opt-1][i]) opt--;
         in_answer_list[answer_list[i]=opt]=true;
         answer-=delta[opt];
         opt--;
     }
     sort(answer_list+1,answer_list+m+1);
     int psum=0,dsum=0;
     for (int i=1;i<=m;i++)
     {
         psum+=P[answer_list[i]];
         dsum+=D[answer_list[i]];
     }
     cout<<"Best jury has value "<<psum<<" for prosecution and value "<<dsum<<" for defence:"<<endl;
     for (int i=1;i<=m;i++) cout<<" "<<answer_list[i];
     cout<<endl;
}

int main()
{
    for (int t=1;;t++)
    {
        cin>>n>>m;
        if (n==0&&m==0) break;
        for (int i=1;i<=n;i++)
            cin>>P[i]>>D[i];
        while (cin.get()!='\n');
        for (int i=1;i<=n;i++)
        {
            delta[i]=P[i]-D[i];
            sum[i]=P[i]+D[i];
        }
        memset(set_size,0,sizeof(set_size));
        memset(_in_set,0,sizeof(_in_set));
        memset(_set,NOT_ASSIGN,sizeof(_set));
        in_set[set_element[set_size[0]++][0]=0][0]=true;
        set[0][0][0]=0;
        for (int i=1;i<=n;i++)
        {
            for (int k=m-1;k>=0;k--)
                for (int j=0;j<set_size[i-1];j++)
                {
                    int now=set_element[j][i-1];
                    int next=now+delta[i];
                    if ((set[now][i-1][k]!=NOT_ASSIGN)&&(set[next][i][k+1]<set[now][i-1][k]+sum[i]))
                    {
                       if (!in_set[next][i]) in_set[set_element[set_size[i]++][i]=next][i]=true;
                       set[next][i][k+1]=set[now][i-1][k]+sum[i];
                    }
                }
            for (int k=m;k>=0;k--)
                for (int j=0;j<set_size[i-1];j++)
                {
                    int now=set_element[j][i-1];
                    int next=now;
                    if (set[next][i][k]<set[now][i-1][k])
                    {
                       if (!in_set[next][i]) in_set[set_element[set_size[i]++][i]=next][i]=true;
                       set[next][i][k]=set[now][i-1][k];
                    }
                }
        }
        int positive=+oo,negative=-oo;
        for (int i=0;i<set_size[n];i++)
            if (set[set_element[i][n]][n][m]!=NOT_ASSIGN)
            {
               if (set_element[i][n]>=0&&set_element[i][n]<positive) positive=set_element[i][n];
               if (set_element[i][n]<=0&&set_element[i][n]>negative) negative=set_element[i][n];
            }
        int answer;
        if (positive==-negative) answer=set[positive][n][m]>set[negative][n][m]?positive:negative;
        else answer=positive<-negative?positive:negative;
        cout<<"Jury #"<<t<<endl;
        print_answre(answer);
    }
    return 0;
}
