#include <stdio.h>
#include <string.h>

inline int H(char x)
{
	switch (x)
	{
	case 'A':return 0;
	case 'T':return 1;
	case 'C':return 2;
	case 'G':return 3;
	}
	return -1;
}
const int MAXALPHABET=4;
const int MAXNODE=2000;
typedef struct struct_node* node;
struct struct_node{node fail;node next[MAXALPHABET];bool flag;};
struct_node pool[MAXNODE];
node top=pool;
node q[MAXNODE];
int head,tail;
void insert(node const root,const char* str)
{
node p=root;
 while (*str)
{
 if (!p->next[H(*str)]) p->next[H(*str)]=top++;
p=p->next[H(*str)];
str++;
}
p->flag=true;
}
int L;
typedef long long lli;
lli A[200][200];
void build_ac_automation(node const root)
{
q[head=tail=0]=root;
 while (head<=tail)
{
node qh=q[head++];
node p;
 for (int c=0;c<MAXALPHABET;c++)
 {
	if (qh->next[c])
	{
		if (qh==root) qh->next[c]->fail=root;
		else
		{
				p=qh->fail;
				while (p)
				{
					if (p->next[c])
					{
					qh->next[c]->fail=p->next[c];
					break;
					}
					p=p->fail;
				}
				if (!p) qh->next[c]->fail=root;
		}
		if (qh->next[c]->fail->flag ) qh->next[c]->flag=true;
		q[++tail]=qh->next[c];
	}
	else qh->next[c]=qh==root?root:qh->fail->next[c];
 	 if (!qh->next[c]->flag) A[qh->next[c]-pool][qh-pool]++;
 }
}
}

void ass(lli a[200][200],lli b[200][200])
{
	memcpy(a,b,sizeof(lli)*40000);
}
void mul(lli a[200][200],lli b[200][200],lli c[200][200])
{
	for (int i=0;i<L;i++)
		for (int j=0;j<L;j++)
		{
			c[i][j]=0;
			for (int k=0;k<L;k++)
			{
				c[i][j]=(lli(c[i][j])+lli(a[i][k])*lli(b[k][j]))%100000ll;
			}
		}
}
void pow(lli a[200][200],lli b)
{
	lli i[200][200];
	memset(i,0,sizeof(lli)*40000);
	for (int j=0;j<L;j++) i[j][j]=1;
	while (b)
	{
		lli t[200][200];
		if (b&1)
		{
			mul(i,a,t);
			ass(i,t);
		}
		mul(a,a,t);
		ass(a,t);
		b>>=1;
	}
	ass(a,i);
}

int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	node root=top++;
	for (int i=0;i<m;i++)
	{
		char s[13];
		scanf("%s",s);
		insert(root,s);
	}
	build_ac_automation(root);
	//printf("%d\n",top-pool);
	L=top-pool;
	//for (int i=0;i<L;i++)
	//	for (int j=0;j<L;j++)
	//		if (A[j][i]) printf("%d%d\n",i,j);//printf("%d%c",int(A[j][i]),(j+1==L?'\n':' '));
	pow(A,n);
	//for (int i=0;i<L;i++)
	//	for (int j=0;j<L;j++)
	//		printf("%d%c",int(A[j][i]),j+1==L?'\n':' ');
	lli answer=0;
	for (int i=0;i<L;i++) answer+=A[i][0];
	printf("%d\n",int(answer%100000ll));
}