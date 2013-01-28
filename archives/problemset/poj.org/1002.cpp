#include <iostream>
#include <algorithm>
using namespace std;

char map[256];
char any[100000][512];
int standard[100000];

int main()
{
    map['0']=0;
    map['1']=1;
    map['2']=2;
    map['A']=2;
    map['B']=2;
    map['C']=2;
    map['3']=3;
    map['D']=3;
    map['E']=3;
    map['F']=3;
    map['4']=4;
    map['G']=4;
    map['H']=4;
    map['I']=4;
    map['5']=5;
    map['J']=5;
    map['K']=5;
    map['L']=5;
    map['6']=6;
    map['M']=6;
    map['N']=6;
    map['O']=6;
    map['7']=7;
    map['P']=7;
    map['R']=7;
    map['S']=7;
    map['8']=8;
    map['T']=8;
    map['U']=8;
    map['V']=8;
    map['9']=9;
    map['W']=9;
    map['X']=9;
    map['Y']=9;
    
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    int n;
    cin>>n;
    cin.get();
    for (int i=0;i<n;i++)
        cin>>any[i];
    for (int i=0;i<n;i++)
        for (int j=0;any[i][j];j++)
            if (any[i][j]!='-') (standard[i]*=10)+=map[any[i][j]];
    sort(standard,standard+n);
    bool no_duplicates=true;
    for (int i=1,counter=1;i<=n;i++)
    {
        if (i==n||standard[i-1]!=standard[i])
        {
           if (counter>1)
           {
              cout<<((standard[i-1]/1000000)%10)
                  <<((standard[i-1]/100000)%10)
                  <<((standard[i-1]/10000)%10)
                  <<"-"
                  <<((standard[i-1]/1000)%10)
                  <<((standard[i-1]/100)%10)
                  <<((standard[i-1]/10)%10)
                  <<((standard[i-1]/1)%10)
                  <<" "
                  <<counter<<endl;
                  no_duplicates=false;
           }
           counter=1;
        }
        else counter++;
    }
    if (no_duplicates) cout<<"No duplicates."<<endl;
    return 0;
}
