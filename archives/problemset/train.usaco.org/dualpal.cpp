/*
ID: sujiao1
PROG: dualpal
LANG: C++
*/
//#include <string>
//using std::string;
/*
#include <iostream>
using std::cin;
using std::cout;
*/
#include <fstream>
std::ifstream cin("dualpal.in");
std::ofstream cout("dualpal.out");
using std::endl;

int B,N,S;

int t[1024];
int t2[1024];
int l,l2;

bool is2(int a)
{
     l=1;
     for (;a>0;)
     {
         t[l]=a%B;
         l++;
         a/=B;
     }
     l--;
     for (int i=1;i<=l;i++)
     {
         if (t[i]!=t[l+1-i]){/*if (bak==264) while(cin.get()!='q');*/ return false;}
     }
     /*
     cout<<a<<":";
     for (int i=l;i>=1;i--)
         cout<<t[i];
     cout<<endl;
     */
     return true;
}
bool is(int a)
{
     //cout<<"is()\n";
     //while (cin.get()!='q');
     int c=0;
     for (B=2;B<=10;B++)
         if (is2(a)) c++;
     if (c>=2) return true;
     else return false;
}
void print(int a)
{
     cout<<a<<endl;     
}

int main()
{
    cin>>N>>S;
    
    int c=0;
    for (int i=S+1;c<N;i++)
    {
        if (is(i))
        {
           print(i);
           c++;
        }
    }
    //while (cin.get()!='q');
    return 0;
}
