/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-4-15
DESCRIPTION:
$DESCRIPTION
*/
#include <stdio.h>
#include <string.h>

#define MAXLEN 20

int N;
char num[MAXLEN+1];
int counter[10];

int main()
{
    scanf("%d\n",&N);
    for (int i=0;i<N;i++)
    {
        scanf("%s\n",num);
        memset(counter,0,sizeof(counter));
        for (char* j=num;*j;j++)
            counter[*j-'0']++;
        int mod7=0;
        for (int j=9;j>4;j--)
            for (int k=0;k<counter[j];k++)
            {
                printf("%d",j);
                mod7=(mod7*10+j)%7;
            }
        for (int j=4;j>0;j--)
            for (int k=1;k<counter[j];k++)
            {
                printf("%d",j);
                mod7=(mod7*10+j)%7;
            }
        for (int k=-4;k<counter[0];k++)
            mod7=(mod7*10)%7;
        int mod1234=1;
        for (int k=0;k<counter[0];k++)
            mod1234=(mod1234*10)%7;
        bool printed=false;
        for (int i1=1;i1<=4&&!printed;i1++)
            for (int i2=1;i2<=4&&!printed;i2++)
                for (int i3=1;i3<=4&&!printed;i3++)
                    for (int i4=1;i4<=4&&!printed;i4++)
                        if (i1!=i2&&i1!=i3&&i1!=i4
                            &&i2!=i3&&i2!=i4
                            &&i3!=i4)
                           if (((i1*1000+i2*100+i3*10+i4)*mod1234+mod7)%7==0)
                           {
                              printf("%d%d%d%d",i1,i2,i3,i4);
                              printed=true;
                           }
        for (int k=0;k<counter[0];k++)
            printf("0");
        printf("\n");
    }
    return 0;
}
