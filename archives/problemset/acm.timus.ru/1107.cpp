#include <cstdio>
using namespace std;

int main()
{
    int n,k,m;
    scanf("%d%d%d",&n,&k,&m);
    printf("YES\n");
    for (int i=0;i<k;i++)
    {
        int sum=0,l;
        scanf("%d",&l);
        for (int j=0;j<l;j++)
        {
            int t;
            scanf("%d",&t);
            sum+=t;
        }
        printf("%d\n",sum%(n+1)+1);
    }
}
