#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstdio>
using namespace std;

int s;
int ce[8];
bool f[2000000];
bool calced[2000000];
bool win(int s)
{
    if (!calced[s])
    {
        bool result=false;
        for (int i=0;ce[i+1]<=s;i++)
        {
            int ns;
            int digit=(s/ce[i])%10;
            if (digit==0)
            {
                ns=s/ce[i+1];
                if (!win(ns))
                {
                    result=true;
                    break;
                }
            }
            else
            {
                ns=s%ce[i]+(s/ce[i+1])*ce[i+1];
                for (int j=0;j<digit;j++)
                {
                    if (!win(ns))
                    {
                        result=true;
                        break;
                    }
                    ns+=ce[i];
                }
            }
            if (result) break;
        }
        calced[s]=true;
        f[s]=result;
    }
    return f[s];
}

int main()
{
    ce[0]=1;
    for (int i=1;i<8;i++) ce[i]=ce[i-1]*10;
    char str[8];
    while (gets(str))
    {
        s=1;
        for (char* i=str;*i;i++)
            s=s*10+(*i-'0');
        puts(win(s)?"Yes":"No");
    }
}

