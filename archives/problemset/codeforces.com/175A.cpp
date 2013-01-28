#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int n(string s)
{
    stringstream cin(s);
    int get;
    cin>>get;
    return get;
}

int main()
{
    string s;
    cin>>s;
    int answer=-1;
    for (int i=1;i<s.length();i++)
        for (int j=i+1;j<s.length();j++)
        {
            string a=s.substr(0,i);
            string b=s.substr(i,j-i);
            string c=s.substr(j,s.length()-j);
            if ((a[0]!='0'||a.length()==1)&&(b[0]!='0'||b.length()==1)&&(c[0]!='0'||c.length()==1)&&a.length()<9&&b.length()<9&&c.length()<9&&n(a)<=1000000&&n(b)<=1000000&&n(c)<=1000000)
            {
               int get=n(a)+n(b)+n(c);
               if (get>answer) answer=get;
            }
        }
    cout<<answer<<endl;
}

