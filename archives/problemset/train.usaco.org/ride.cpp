/*
ID: sujiao1
PROG: ride
LANG: C++
*/
//#include <iostream>
//using namespace std;

#include <fstream>
using std::endl;
std::ifstream cin("ride.in");
std::ofstream cout("ride.out");

#include <string>
using std::string;

int main()
{
    string a,b;
    cin>>a>>b;
    int ga=1,gb=1;
    for (int i=0;i<a.length();i++)
    {
        ga=(ga*(a[i]-'A'+1))%47;
    }
    for (int i=0;i<b.length();i++)
    {
        gb=(gb*(b[i]-'A'+1))%47;
    }
    if (ga==gb) cout<<"GO"<<endl;
    else cout<<"STAY"<<endl;
    //while (cin.get()!='q');
    return 0;
}
