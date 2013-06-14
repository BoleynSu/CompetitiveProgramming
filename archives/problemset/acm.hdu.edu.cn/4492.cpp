#include <stdio.h>
#include <map>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <string>
#include <iostream>
using namespace std;
#define sf scanf
#define pf printf

string str;
char buffer[1000000];
int main()
{
    int i,cass,cas,n,x,len,s;
    {gets(buffer);
    stringstream sin(buffer);
    sin>>cas;}
    for(cass=1;cass<=cas;cass++)
    {
        {gets(buffer);
            stringstream sin(buffer);
            sin>>i;}
        {gets(buffer);
            stringstream sin(buffer);
            getline(sin,str);}//cout<<str<<endl;}
        {gets(buffer);
                    stringstream sin(buffer);
                    sin>>n;}
        gets(buffer);
        stringstream sin(buffer);
        printf("%d ",cass);s=0;
        for(int j=1;j<=n;j++)
        {
            sin>>x;//scanf("%d",&x);
            s=(s+x+str.length())%str.length();
            printf("%c",str[s]);
        }
        puts("");
    }
}

