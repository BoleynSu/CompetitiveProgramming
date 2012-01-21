/*
AUTHOR: Su Jiao
DATE: 2010-9-11
DESCRIPTION:
$DESCRIPTION
*/
#include <stdio.h>

int main()
{
    /*
    for (long long int i=0;i<1000000000;i++)
        if (i*i%1000000000==987654321) printf("%d\n",int(i));
    output:
    111111111
    119357639
    380642361
    388888889
    611111111
    619357639
    880642361
    888888889
    */
    int n;
    scanf("%d",&n);
    if (n<=8) printf("%d\n",0);
    else if (n==9) printf("%d\n",8);
    else
    {
        printf("%d",72);
        for (int i=10;i<n;i++) printf("%d",0);
        printf("\n");
    }
}
