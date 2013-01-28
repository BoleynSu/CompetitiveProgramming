#include <iostream>
#include <string>
using namespace std;

enum{MAXLENGTH=1000000+2};
int k;
string s;
long long sum[MAXLENGTH];
long long p[MAXLENGTH];
long long answer;

int main()
{
    cin>>k>>s;
    if (k==0)
    {
       long long i=0;
       for (;;)
       {
           while (i<s.length()&&s[i]!='0') i++;
           if (i<s.length())
           {
              long long t=i;
              while (i<s.length()&&s[i]=='0') i++;
              answer+=(i-t+1)*(i-t)/2;
           }
           else break;
       }
    }
    else
    {
        for (int i=0;i<s.length();i++) sum[i+1]=sum[i]+s[i]-'0';
        for (int i=0;i<=s.length();i++) p[sum[i]]=i;
        for (int i=0;i+k<=sum[s.length()];i++)
        {
            if (i==0) answer+=(p[i]+1)*(p[i+k]-p[i+k-1]);
            else answer+=(p[i]-p[i-1])*(p[i+k]-p[i+k-1]);
        }
    }
    cout<<answer<<endl;
}

