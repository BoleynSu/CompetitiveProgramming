#include <stdio.h>

void convert(int *p)
{
	int tmp[9],i,j;
	for (i=0;i<3;i++)
		for (j=0;j<3;j++)
			tmp[j*3+i]=p[i*3+j];
	for (i=0;i<9;i++) p[i]=tmp[i];
}

int main()
{
	int m[9],i;
	for (i=0;i<9;i++) scanf("%d,",&m[i]);
	convert(m);
	for (i=0;i<9;i++)
	{
		printf("%d,",m[i]);
		if (i%3==2) printf("\n");
	}
}
