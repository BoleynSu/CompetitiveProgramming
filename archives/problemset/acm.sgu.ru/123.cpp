#include <cstdio>
int main()
{
	int k;
	scanf("%d",&k);
	long long a=1,b=1,c,s=0;
	for (int i=1;i<=k;i++) s+=a,c=a+b,a=b,b=c;
	printf("%I64d\n",s);
}
