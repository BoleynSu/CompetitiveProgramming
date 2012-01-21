#include <iostream>
using namespace std;

void qsort(long* s,long* e)
{
     long mid=*(s+(e-s)/2);
     long* _s=s;
     long* _e=e;
     while (s<=e)
     {
           while (*s<mid) s++;
           while (*e>mid) e--;
           if (s<=e)
           {
              long tmp=*s;
              *s=*e;
              *e=tmp;
              s++;
              e--;
           }
     }
     if (_s<e) qsort(_s,e);
     if (s<_e) qsort(s,_e);
}

int main()
{
    int n;
    long* m;
    cin>>n;
    m=new long[n+1];
    for (int i=0;i<n;i++) cin>>m[i];
    m[n]=-1;
    qsort(m,m+n-1);
    for (int i=0;i<n;)
    {
        cout<<m[i]<<' ';
        int j=i++;
        while (m[i]==m[i-1]) i++;
        cout<<i-j<<endl;
    }
    delete[] m;
    //while (cin.get()!='q');
}
