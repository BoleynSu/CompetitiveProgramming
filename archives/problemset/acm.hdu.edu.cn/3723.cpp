#include <cstdio>
#include <cstring>
using namespace std;

class BigInteger
{
    static const int LENGTH=6;
    static const long long int BASE=100000000000000000ll;
    static const int LOG10_BASE=17;
    long long int digit[LENGTH];
    public:
    BigInteger(long long int x=0)
    {
        memset(digit,0,sizeof(digit));
        digit[0]=x;
    }
    BigInteger& operator += (BigInteger& plus)
    {
#define i 0
        digit[i]+=plus.digit[i];
        if (digit[i]>=BASE)
        {
            digit[i+1]++;
            digit[i]-=BASE;
        }
#undef i
#define i 1
        digit[i]+=plus.digit[i];
        if (digit[i]>=BASE)
        {
            digit[i+1]++;
            digit[i]-=BASE;
        }
#undef i
#define i 2
        digit[i]+=plus.digit[i];
        if (digit[i]>=BASE)
        {
            digit[i+1]++;
            digit[i]-=BASE;
        }
#undef i
#define i 3
        digit[i]+=plus.digit[i];
        if (digit[i]>=BASE)
        {
            digit[i+1]++;
            digit[i]-=BASE;
        }
#undef i
#define i 4
        digit[i]+=plus.digit[i];
        if (digit[i]>=BASE)
        {
            digit[i+1]++;
            digit[i]-=BASE;
        }
#undef i
#define i LENGTH-1
        digit[i]+=plus.digit[i];
        if (digit[i]>=BASE)
            digit[i]-=BASE;
#undef i
        return *this;
    }
    void print()
    {
        int i=LENGTH-1;
        digit[i]%=1000000000000000ll;
        while (!digit[i]&&i>=0) i--;
        printf("%I64d",digit[i--]);
        while (i>=0) printf("%017I64d",digit[i--]);
        printf("\n");
    }
};

const int MAXN=10000;
BigInteger f[2][MAXN+1];
BigInteger g[MAXN+1];
int end[MAXN+1];

int main()
{
    #define min(a,b) ((a)<(b)?(a):(b))
    for (int i=0;i<=MAXN;i++) end[i]=min(i,MAXN+1-i);
    #define K(x) ((x)&1)
    f[K(0)][0]=1;
    g[K(0)]=f[K(0)][0];
    for (int i=1;i<=MAXN;i++)
    {
        for (int j=0;j<=end[i];j++)
        {
            if (j<end[i]) f[K(i)][j]=f[K(i-1)][j];
            else f[K(i)][(j)]=0;
            if (j<end[i-1]) f[K(i)][j]+=f[K(i-1)][j+1];
            if (0<j) f[K(i)][j]+=f[K(i-1)][j-1];
        }
        g[i]=f[K(i)][0];
    }
    int N;
    while (scanf("%d",&N)!=EOF)
        g[N].print();
    return 0;
}
