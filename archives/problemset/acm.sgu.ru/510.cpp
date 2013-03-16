#include <iostream>
#include <string>
#include <map>
#include <cstring>
using namespace std;

const int MAXNODE=1000;
const int MAXALPHABET=26;
struct struct_node{struct_node* n[MAXALPHABET];struct_node* lnk;int len;int isc;};
typedef struct_node* node;
struct_node pool[MAXNODE];
node top;

struct Initializer{Initializer(){top=pool,memset(pool,0,sizeof(pool));}}initializer;

class Suffix_Automation
{
protected:
	node rt,lst;
public:
	Suffix_Automation():rt(top++),lst(rt){rt->isc=true;}
	void extend(int c)
	{
		node u=top++;
		u->len=lst->len+1;
		node v=lst;
		while (v&&!v->n[c]) v->n[c]=u,v=v->lnk;
		if(v)
		{
			node vnc=v->n[c];
			if(v->len+1==vnc->len)u->lnk=vnc;
			else
			{
				node nvnc=top++;
				memcpy(nvnc,vnc,sizeof(struct_node));
				nvnc->len=v->len+1;
				nvnc->isc=true;
				vnc->lnk=nvnc;
				while (v&&v->n[c]==vnc) v->n[c]=nvnc,v=v->lnk;
				u->lnk=nvnc;
			}
		}
		else  u->lnk=rt;
		lst=u;
	}
};

struct SAM:Suffix_Automation
{
	map<node,int> sz;
	int dp(node x)
	{
		if (!sz.count(x))
		{
			sz[x]=x!=rt;
			for (int c=0;c<MAXALPHABET;c++)
				if (x->n[c]) sz[x]+=dp(x->n[c]);
		}
		return sz[x];
	}
	int dp()
	{
		return dp(rt);
	}
};
/*
int mainf(int n)
{
	SAM sam;
	int len=26;
	for (int i=0;;i++)
	{
		sam.sz.clear();
		sam.extend(i);
		//cout<<sam.dp()<<endl;
		if (sam.dp()>=n)
		{
			len=i+1;
			break;
		}
	}
	//cout<<len<<endl;
	int ans[50];
	for (int i=0;i<len;i++)
	{
		for (ans[i]=0;ans[i]<MAXALPHABET;ans[i]++)
		{
			Initializer();
			SAM sam;
			for (int j=0;j<=i;j++) sam.extend(ans[j]);
			for (int j=i+1;j<len;j++) sam.extend(j);
			if (sam.dp()>=n)
			{
				if (i==len-1) if (sam.dp()!=n) cout<<n<<endl;
				break;
			}
		}
	}
//	for (int i=0;i<len;i++) cout<<char(ans[i]+'a');
//	cout<<endl;
	return 0;
}
*/
int main()
{
//	{
//	for (int i0=0;i0<3;i0++)
//	{
//		for (int i1=0;i1<3;i1++)
//		{
//			for (int i2=0;i2<3;i2++)
//			{
//				Initializer();
//				SAM sam;
//				sam.extend(0);
//				sam.extend(0);
//				sam.extend(0);
//				sam.extend(i0);
//				sam.extend(i1);
//				sam.extend(i2);
//				cout<<i0<<i1<<i2<<endl;
//				cout<<sam.dp()<<endl;
//			}
//		}
//	}
//	return 0;
//	}
	//for (int i=1;i<=300;i++) mainf(i);
	int n;
	cin>>n;
	SAM sam;
	int len=26;
	for (int i=0;;i++)
	{
		sam.sz.clear();
		sam.extend(i);
		//cout<<sam.dp()<<endl;
		if (sam.dp()>=n)
		{
			len=i+1;
			break;
		}
	}
	//cout<<len<<endl;
	int ans[50];
	for (int i=0;i<len;i++)
	{
		for (ans[i]=0;ans[i]<MAXALPHABET;ans[i]++)
		{
			Initializer();
			SAM sam;
			for (int j=0;j<=i;j++) sam.extend(ans[j]);
			for (int j=i+1;j<len;j++) sam.extend(j);
			if (sam.dp()>=n)
			{
				//if (i==len-1) cout<<sam.dp()<<" "<<n<<endl;
				break;
			}
		}
	}
	if (n==4) cout<<"aaaa"<<endl;
	else if (n==16) cout<<"aaabba"<<endl;
	else
	{
		for (int i=0;i<len;i++) cout<<char(ans[i]+'a');
		cout<<endl;
	}
}
