#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;

int top=-1;
int stack[100000000];

int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		int op;
		scanf("%d",&op);
		if (op==-1)
		{
			while (stack[top]<=0)
			{
				int j=-stack[top];
				top--;
				if (j-1>=0) stack[++top]=-(j-1);
				stack[++top]=stack[j];
				//for (int k=0;k<=j;k++)
				//	stack[++top]=stack[k];
			}
			printf("%d\n",stack[top--]);
		}
		else if (op==0)
		{
			if (top>=0) stack[top+1]=-top,top++;
		}
		else stack[top+1]=op,top++;
		//for (int i=0;i<=top;i++) cout<<stack[i]<<";";cout<<endl;
	}
}
