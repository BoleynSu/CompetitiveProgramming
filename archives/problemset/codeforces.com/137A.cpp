#include <string>
#include <iostream>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int answer=0;
    for (int i=0,j;i<s.length();)
    {
        for (j=i;j<i+5&&j<s.length();j++)
            if (s[i]!=s[j]) break;
        answer++;
        i=j;
    }
    cout<<answer<<endl;
    return 0;
}

