#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef long long int lli;
const int MAXN=2500+2;
const int MAXM=100000;
int N,M;
lli ot[MAXN],on[MAXN];
int T,S;
lli p[MAXM];
int qh,qt;
lli Qc[MAXM],Qt[MAXM];

int toInteger(string month,int date,int year,int hour)
{
    int result=0;
    result+=(year-2000)*365*24+(year-2000+4-1)/4*24-(year-2000+100-1)/100*24+(year-2000+400-1)/400*24;
    string months[]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    int monthnumber=find(months,months+12,month)-months+1;
    if (monthnumber>1) result+=31*24;
    if (monthnumber>2) result+=(((year%4==0)-(year%100==0)+(year%400==0))+28)*24;
    if (monthnumber>3) result+=31*24;
    if (monthnumber>4) result+=30*24;
    if (monthnumber>5) result+=31*24;
    if (monthnumber>6) result+=30*24;
    if (monthnumber>7) result+=31*24;
    if (monthnumber>8) result+=31*24;
    if (monthnumber>9) result+=30*24;
    if (monthnumber>10) result+=31*24;
    if (monthnumber>11) result+=30*24;
    result+=(date-1)*24+hour;
    return result;
}

int main()
{
    for (;;)
    {
        cin>>N>>M;
        if (N==0&&M==0) break;
        for (int i=0;i<N;i++)
        {
            string month;
            int date,year,hour;
            cin>>month>>date>>year>>hour>>on[i];
            ot[i]=toInteger(month,date,year,hour);
        }
        cin>>T>>S;
        for (int i=0;i<M;i++)
            cin>>p[i];
        lli answer=0;
        qh=0,qt=-1;
        for (int i=0,oh=0;i<M;i++)
        {
            while (qh<=qt&&Qt[qh]+T<i) qh++;
            while (qh<=qt&&Qc[qt]>=p[i]-i*S) qt--;
            qt++;
            Qc[qt]=p[i]-i*S;
            Qt[qt]=i;
            while (oh<N&&i==ot[oh])
            {
                answer+=(Qc[qh]+ot[oh]*S)*on[oh];
                oh++;
            }
        }
        cout<<answer<<endl;
    }
}

