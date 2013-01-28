#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

#define rep(i,n) for (int i=0;i<(n);i++)
#define rtn return
typedef char* cstr;
//AC自动机  + Trie
#define H(c) ((c)-'A')
const int MAXALPHABET=26;//字母表大小
const int MAXNODE=2500*1100+1993;
typedef int Data;//附加信息类型
typedef struct struct_node* node;
struct struct_node{node f;node n[MAXALPHABET];Data d;};
struct_node pool[MAXNODE];
node top;
node q[MAXNODE];
int qh,qt;
void init_ac_automation()
{
	top=pool;
}
node root_ac_automation()
{
	top->d=-1;
	rep(i,MAXALPHABET) top->n[i]=top;
	top->f=top;
	rtn top++;
}
void insert_ac_automation(node rt,cstr str,int sid)
{
	node u=rt;
	while (*str)
	{
		if (u->n[H(*str)]==rt)
		{
			top->d=-1;
			rep(i,MAXALPHABET) top->n[i]=rt;
			u->n[H(*str)]=top++;
		}
		u=u->n[H(*str)];
		str++;
	}
	u->d=sid;
}
void build_ac_automation(node rt)
{
	qh=0,qt=-1;
	rep(i,MAXALPHABET) if (rt->n[i]!=rt) rt->n[i]->f=rt,q[++qt]=rt->n[i];
	while (qh<=qt)
	{
		node u=q[qh++];
		rep(i,MAXALPHABET)
			if (u->n[i]!=rt)
			{
				node v=u->f;
				while (v!=rt&&v->n[i]==rt) v=v->f;
				u->n[i]->f=v->n[i];
				q[++qt]=u->n[i];
			}
	}
}
int visid;
int vis[MAXNODE];
void query_ac_automation(node const rt,const char* str,int match[],int matchid)
{
	visid++;
	node v=rt;
	while (*str)
	{
		while (v!=rt&&v->n[H(*str)]==rt) v=v->f;
		v=v->n[H(*str)];
		node u=v;
		while (u!=rt)
		{
			if (vis[u-pool]==visid) break;
			vis[u-pool]=visid;
			if (~u->d) match[u->d]=matchid;
			u=u->f;
		}
		str++;
	}
}
void query_delete_ac_automation(node const rt,const char* str,int sid,int match[],int matchid)
{
	visid++;
	node v=rt;
	while (*str)
	{
		while (v!=rt&&v->n[H(*str)]==rt) v=v->f;
		v=v->n[H(*str)];
		node u=v;
		while (u!=rt)
		{
			if (vis[u-pool]==visid) break;
			vis[u-pool]=visid;
			if (~u->d) match[u->d]=0;
			u=u->f;
		}
		str++;
	}
}

char s[5000000+1];
char S[2500][1100+1];
int match[2500];

int main()
{
	int T;
	scanf("%d",&T);
	getchar();
	while (T)
	{
		init_ac_automation();
		node rt=root_ac_automation();
		int n;
		scanf("%d",&n);
		getchar();
		rep(i,n)
		{
			char* p=S[i];
			for (;;)
			{
				char c=getchar();
				if (c=='\n')
				{
					*p=0;
					break;
				}
				else if (c=='[')
				{
					int k;
					scanf("%d",&k);
					c=getchar();
					while (k--) *p++=c;
					getchar();
				}
				else *p++=c;
			}
			insert_ac_automation(rt,S[i],i);
		}
		build_ac_automation(rt);
		char* p=s;
		for (;;)
		{
			char c=getchar();
			if (c=='\n')
			{
				*p=0;
				break;
			}
			else if (c=='[')
			{
				int k;
				scanf("%d",&k);
				c=getchar();
				while (k--) *p++=c;
				getchar();
			}
			else *p++=c;
		}
		query_ac_automation(rt,s,match,T);
		rep(i,n) if (match[i]==T)
		{
			query_delete_ac_automation(rt,S[i],i,match,T);
			match[i]=T;
		}
		int ans=0;
		rep(i,n) if (match[i]==T) ans++;
		printf("%d\n",ans);
		T--;
	}
	return 0;
}
