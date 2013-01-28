#include <iostream>
using namespace std;

typedef unsigned long long int ull;

const int MAXK=64;
int k;
char description[MAXK+2];
long long int N;
char bitset[MAXK+2];

void get_bitset(ull number)
{
     for (int i=0;i<k;i++)
         if (number&(((ull)(1))<<i)) bitset[k-1-i]='1';
         else bitset[k-1-i]='0';
}

int main()
{
    int T;
    cin>>T;
    for (int t=1;t<=T;t++)
    {
        cin>>k>>description>>N;
        ull _N;
        int flag;
        if (N>=0) flag=+1,_N=N;
        else flag=-1,_N=-N;
        for (int i=0;i<k;i++)
            if (description[k-1-i]=='n')
               if (flag==+1) _N+=((ull)(1))<<i;
               else
               {
                   if (_N>(((ull)(1))<<i)) _N-=((ull)(1))<<i;
                   else flag=+1,_N=(((ull)(1))<<i)-_N;
               }
        char answer[MAXK+2];
        if ((flag==+1)&&(_N<(((ull)(1))<<k)||k==64))
        {
           get_bitset(_N);
           for (int i=0;i<k;i++)
               if (description[i]=='n') cout<<char('1'-bitset[i]+'0');
               else cout<<char(bitset[i]);
           cout<<endl;
        }
        else cout<<"Impossible"<<endl;
    }
    return 0;
}
