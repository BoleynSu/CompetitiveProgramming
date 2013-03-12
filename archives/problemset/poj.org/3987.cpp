#include <stdio.h>
#include <string.h>

#define H(c) ((c)-'A')
const int MAXALPHABET=26;
const int MAXNODE=1000000;
typedef struct struct_node* node;
struct struct_node{node fail;node next[MAXALPHABET];int count;};
struct_node pool[MAXNODE];
node top;
node q[MAXNODE];
int head,tail;
void insert(node const root,const char* str,int c)
{
node p=root;
 while (*str)
{
 if (!p->next[H(*str)]) p->next[H(*str)]=top++;
p=p->next[H(*str)];
str++;
}
p->count=c;
}
void build_ac_automaton(node const root)
{
q[head=tail=0]=root;
 while (head<=tail)
{
node qh=q[head++];
node p;
 for (char i='A';i<='Z';i++)
 if (qh->next[H(i)])
{
 if (qh==root) qh->next[H(i)]->fail=root;
 else
{
p=qh->fail;
 while (p)
{
 if (p->next[H(i)])
{
qh->next[H(i)]->fail=p->next[H(i)];
 break;
}
p=p->fail;
}
 if (!p) qh->next[H(i)]->fail=root;
}
q[++tail]=qh->next[H(i)];
}
}
}
bool g[1000];
		int n;
int query(node const root,const char* str)
{
 int result=0;
node p=root;
 while (*str)
{
 while (!p->next[H(*str)]&&p!=root) p=p->fail;
p=p->next[H(*str)];
 if (!p) p=root;
node t=p;
 while (t!=root)
{
 int delta=t->count;
 if (!g[delta]) g[delta]=true,result++;
t=t->fail;
}
str++;
if (result==n) break;
}
 return result;
}

char si[5100000+2];
char so[5100000+2];
char ts[5100000+2];

int main()
{
	int T;
	scanf("%d",&T);
	for (int t=0;t<T;t++)
	{
		memset(pool,0,sizeof pool);
		memset(g,0,sizeof g);
		g[0]=true;
		top=pool;
		node root=top++;
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
		{
			char s[1024];
			scanf("%s",s);
			insert(root,s,i);
			int l=strlen(s);
			for (int k=0;k<l-1-k;k++)
			{
				char sw=s[k];
				s[k]=s[l-1-k];
				s[l-1-k]=sw;
			}
			insert(root,s,i);
		}
		build_ac_automaton(root);
		scanf("%s",si);
		char* j=so;
		for (char* i=si;*i;i++)
		{
			if (*i=='[')
			{
				int x=0;
				while (*++i<='9'&&*i>='0') x=x*10+*i-'0';
				char* k=ts;
				while (*i!=']') *k++=*i++;
				for (int y=0;y<x;y++)
					for (char* q=ts;q!=k;q++)
						*j++=*q;
			}
			else *j++=*i;
		}
		*j=0;
		printf("%d\n",query(root,so));
	}
}
