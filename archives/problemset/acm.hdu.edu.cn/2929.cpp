#include <iostream>
using namespace std;
#include <cstdlib>

class BigInteger
{
    static const int size=7,base=100000000;
    typedef long long int lli;
    int d[size];
public:
    bool isNull;
    inline
    BigInteger(int x=0)
    {
        isNull=false;
        for (int i=0;i<size;i++)
        {
            d[i]=x%base;
            x/=base;
        }
    }
    inline
    friend bool operator<(const BigInteger& a,const BigInteger& b)
    {
        if (a.isNull) return true;
        if (b.isNull) return false;
        else
        {
            for (int i=size-1;i>=0;i--)
                if (a.d[i]!=b.d[i]) return a.d[i]<b.d[i];
            return false;
        }
    }
    inline
    friend BigInteger operator*(const BigInteger& a,int k)
    {
        BigInteger c=a;
        for (int i=0;i<size;i++)
            c.d[i]*=k;
        for (int i=0;i<size;i++)
            if (c.d[i]>=base)
            {
                c.d[i+1]+=c.d[i]/base;
                c.d[i]%=base;
            }
        return c;
    }
    inline
    friend BigInteger operator+(const BigInteger& a,int k)
    {
        BigInteger c=a;
        c.d[0]+=k;
        for (int i=0;i<size;i++)
            if (c.d[i]>=base)
            {
                c.d[i]-=base;
                c.d[i+1]++;
            }
        return c;
    }
    inline
    friend ostream& operator<<(ostream& cout,const BigInteger& x)
    {
        if (x.isNull) cout<<-1;
        else
        {
            int i=size;
            while (i>0&&!x.d[--i]);
            cout<<x.d[i];
            while (--i>=0)
                for (int k=base/10;k;k/=10)
                    cout<<(x.d[i]/k)%10;
        }
        return cout;
    }
};

const int need[]={6,2,5,5,4,5,6,3,7,6};
BigInteger f[101][3000];

int main()
{
    for (int t=1;;t++)
    {
        int n;
        cin>>n;
        if (n==0) break;
        int m;
        cin>>m;
        for (int i=0;i<=n;i++)
            for (int j=0;j<m;j++)
                f[i][j].isNull=true;
        f[0][0]=0;
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                for (int k=0;k<10;k++)
                    if (i+need[k]<=n&&!f[i][j].isNull)
                    {
                        BigInteger get=f[i][j]*10+k;
                        BigInteger& old=f[i+need[k]][(j*10+k)%m];
                        if (old<get) old=get;
                    }
        BigInteger answer;
        answer.isNull=true;
        for (int i=1;i<=n;i++)
            if (answer<f[i][0])
                answer=f[i][0];
        cout<<"Case "<<t<<": "<<answer<<endl;
    }
}

