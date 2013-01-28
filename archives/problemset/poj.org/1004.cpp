#include <cstdio>
#include <iostream>
using namespace std;


int main()
{
    double sum=0.0,temp;
    for (int i=0;i<12;i++)
    {
        scanf("%lf",&temp);
        sum+=temp;
    }
    printf("$%.2f",sum/12);
    return 0;
}
