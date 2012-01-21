/*
ID: sujiao1
PROG: test
LANG: C++
*/
#include <fstream>
using std::endl;
std::ifstream cin("test.in");
std::ofstream cout("test.out");

int main()
{
    int a,b;
    cin>>a>>b;
    cout<<(a+b)<<endl;
    return 0;
}
