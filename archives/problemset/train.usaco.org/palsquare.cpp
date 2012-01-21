/*
ID: sujiao1
PROG: palsquare
LANG: C++
*/
//#include <string>
//using std::string;

//#include <iostream>
//using std::cin;
//using std::cout;
#include <fstream>
std::ifstream cin("palsquare.in");
std::ofstream cout("palsquare.out");
using std::endl;

int B;

int t[1024];
int t2[1024];
int l,l2;

bool is(int a)
{
     int bak=a;
     int k=1,j=1,c=0;
     for (;k<=a;k*=10) c++;
     k/=10;
     /*
     for (int i=0;i<c;i++)
     {
         if (((a/k)%10)!=((a/j)%10)) return false;
         k/=10;
         j*=10;
     }*/
     l2=1;
     for (;a>0;)
     {
         t2[l2]=a%B;
         l2++;
         a/=B;
     }
     l2--;
     a=bak*bak;
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
     cout<<bak<<":";
     for (int i=l;i>=1;i--)
         cout<<t[i];
     cout<<endl;*/
     
     return true;
}
char C(int i)
{
     if (i<10) return '0'+i;
     else return 'A'+i-10;
}
void print(int a)
{
     for (int i=l2;i>=1;i--)
     {
         cout<<C(t2[i]);
     }
     cout<<" ";
     for (int i=l;i>=1;i--)
         cout<<C(t[i]);
     cout<<endl;     
}
int main()
{
    cin>>B;
    for (int i=1;i<=300;i++)
        if (is(i)) print(i);
    //while (cin.get()!='q');
    return 0;
}
