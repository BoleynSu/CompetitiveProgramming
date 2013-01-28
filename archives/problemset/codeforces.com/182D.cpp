#include <string>
#include <iostream>
using namespace std;

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int maxl=min(s1.length(),s2.length()),answer=0;
    for (int i=0;i<maxl;)
    {
        if (s1[i]!=s2[i]) break;
            i++;
            if (s1.length()%i==0&&s2.length()%i==0)
            {
               bool plus=true;
               for (int j=0;j<s1.length()&&plus;j++)
                   if (s1[j]!=s1[j%i]) plus=false;
               for (int j=0;j<s2.length()&&plus;j++)
                   if (s2[j]!=s2[j%i]) plus=false;
               if (plus) answer++;
            }
    }
    cout<<answer<<endl;
}

