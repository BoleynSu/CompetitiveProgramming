#include <cstdio>
using namespace std;


int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        double X,Y;
        scanf("%lf%lf",&X,&Y);
        printf("Property %d: This property will begin eroding in year %d.\n",i,int((3.14159265358979323*(X*X+Y*Y))/100.0+0.9999999999999));
    }
    printf("END OF OUTPUT.\n");
    return 0;
}
