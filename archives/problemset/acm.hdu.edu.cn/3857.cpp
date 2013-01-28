#include <iostream>
using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    int n;
    while (cin>>n)
    {
          bool mistake=false;
          for (int i=1,j;i<=n;i++)
          {
              cin>>j;
              if (i==j)
              {
                 if (!mistake) cout<<j;
                 else cout<<" "<<j;
                 mistake=true;
              }
          }
          if (!mistake) cout<<"No Mistake";
          cout<<endl;
    }
}

