/****************************************************************
	Problem: 1614
	User: RUC_Acme
	Language: C++
	Result: Accepted
	Time:804 ms
	Memory:1472 kb
****************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdio.h>

const int MOD=100000009;
char s[1000000+2];

int main()
{
	int T;
	scanf("%d",&T);
	for (int t=0;t<T;t++)
	{
		scanf("%s",s);
		int cnt[256];
		cnt['O']=0;
		cnt['U']=0;
		cnt['D']=0;
		cnt['L']=0;
		cnt['R']=0;
		for (int i=0;s[i];i++)
		{
			if (s[i]=='U')
			{
				cnt['D']=(cnt['U']+cnt['D'])%MOD;
				cnt['U']=cnt['O'];
				cnt['L']=cnt['L']*2%MOD;
				cnt['R']=cnt['R']*2%MOD;
			}
			if (s[i]=='D')
			{
				cnt['U']=(cnt['U']+cnt['D'])%MOD;
				cnt['D']=cnt['O'];
				cnt['L']=cnt['L']*2%MOD;
				cnt['R']=cnt['R']*2%MOD;
			}
			if (s[i]=='L')
			{
				cnt['R']=(cnt['R']+cnt['L'])%MOD;
				cnt['L']=cnt['O'];
				cnt['U']=cnt['U']*2%MOD;
				cnt['D']=cnt['D']*2%MOD;
			}
			if (s[i]=='R')
			{
				cnt['L']=(cnt['R']+cnt['L'])%MOD;
				cnt['R']=cnt['O'];
				cnt['U']=cnt['U']*2%MOD;
				cnt['D']=cnt['D']*2%MOD;
			}
			if (i) cnt['O']=(cnt['O']+cnt['O'])%MOD;
			else cnt['O']=1;
		}
		printf("%d\n",(cnt['U']+cnt['D']+cnt['L']+cnt['R'])%MOD);
	}
}
