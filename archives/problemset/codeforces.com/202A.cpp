#include <iostream>
#include <cstring>
using namespace std;

enum{MAXLENGTH=10+1};
char S[MAXLENGTH];
char get[MAXLENGTH];
char answer[MAXLENGTH];

void dfs(char* sp,int getl)
{
	if (*sp)
	{
		dfs(sp+1,getl);
		get[getl]=*sp;
		dfs(sp+1,getl+1);
	}
	else
	{
		get[getl]=0;
		for (int i=0;i<getl-1-i;i++)
			if (get[i]!=get[getl-1-i])
				return;
		if (strcmp(get,answer)>0)
			strcpy(answer,get);
	}
}

int main()
{
	cin>>S;
	dfs(S,0);
	cout<<answer<<endl;
}

