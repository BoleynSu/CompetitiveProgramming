/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2011-11-17
DESCRIPTION:
$DESCRIPTION
*/
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXS=10000000+1;
const int MAXM=6;
int N;
bool f[MAXS];
int sl;
char s[MAXS];
char match[MAXM][7]={"out","output","puton","in","input","one"};
int matchl[MAXM]={3,6,5,2,5,3};

int main()
{
	gets(s);
	sscanf(s,"%d",&N);
	for (int n=0;n<N;n++)
	{
		gets(s);
		sl=strlen(s);
		memset(f,0,sizeof(f));
		f[0]=true;
		for (int i=0;i<sl;i++)
			if (f[i])
				for (int j=0;j<MAXM;j++)
					if (i+matchl[j]<=sl)
					{
						bool matched=true;
						for (int k=0;k<matchl[j];k++)
							if (s[i+k]!=match[j][k])
									matched=false;
						if (matched) f[i+matchl[j]]=true;
					}
		if (f[sl]) puts("YES");
		else puts("NO");
	}
	return 0;
}
