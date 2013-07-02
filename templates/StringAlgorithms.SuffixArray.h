/*
 * Package: StandardCodeLibrary.StringAlgorithms.SuffixArray
 * Description:
 * 后缀数组倍增法;
 * */
#include <Core>

namespace StandardCodeLibrary
{
namespace StringAlgorithms
{
namespace SuffixArray
{

const int LOG2_MAXLENGTH=20;
const int MAXLENGTH=1<<LOG2_MAXLENGTH;
typedef char string[MAXLENGTH];
string s;
int len;
int _a[MAXLENGTH],_b[MAXLENGTH],_c[MAXLENGTH],_d[MAXLENGTH];
int* srt;
int* SA=_a;
int* rnk=_b;
int* TSA=_c;
int* Trnk=_d;
void get_SA()
{
	srt=Trnk;
	rep(i,len) srt[i]=0;
	rep(i,len) srt[s[i]]++;
	repf(i,1,len) srt[i]+=srt[i-1];
	rep(i,len) SA[--srt[s[i]]]=i;
	rnk[SA[0]]=0;
	repf(i,1,len)
		rnk[SA[i]]=rnk[SA[i-1]]+(s[SA[i]]!=s[SA[i-1]]);
	for (int block=1;rnk[SA[len-1]]!=len-1;block<<=1)
	{
		srt=Trnk;
		rep(i,len) srt[rnk[SA[i]]]=i;
		fdt(i,len-1,0) if (SA[i]-block>=0) TSA[srt[rnk[SA[i]-block]]--]=SA[i]-block;
		repf(i,len-block,len) TSA[srt[rnk[i]]--]=i;
		int* swap;
		swap=SA,SA=TSA,TSA=swap;
		swap=rnk,rnk=Trnk,Trnk=swap;
		rnk[SA[0]]=0;
		repf(i,1,len)
			rnk[SA[i]]=rnk[SA[i-1]]+(Trnk[SA[i]]!=Trnk[SA[i-1]]
									||Trnk[SA[i]+block]!=Trnk[SA[i-1]+block]);
	}
}
int* ht;
void get_height()
{
	ht=TSA;
	int h=0;
	rep(i,len)
	{
		if (h) h--;
		if (rnk[i])
		{
			int j=SA[rnk[i]-1];
			whl(s[i+h]==s[j+h]) h++;
		}
		ht[rnk[i]]=h;
	}
}
int* log2;
int rmq[LOG2_MAXLENGTH+1][MAXLENGTH];
void get_RMQ()
{
	log2=Trnk-1;
	log2[1]=0;
	ft(i,2,len) log2[i]=log2[i>>1]+1;
	rep(i,len) rmq[0][i]=i;
	ft(log,1,log2[len])
	{
		int exp=1<<log,exp_div_2=exp>>1;
		rep(i,len-exp+1)
		{
			int a=rmq[log-1][i];
			int b=rmq[log-1][i+exp_div_2];
			rmq[log][i]=ht[a]<ht[b]?a:b;
		}
	}
}
int RMQ(int a,int b)
{
	int log=log2[b-a+1];
	int exp=1<<log;
	a=rmq[log][a],b=rmq[log][b-exp+1];
	rtn ht[a]<ht[b]?a:b;
}
int LCP(int a,int b)
{
	if (a==b) rtn len-a;
	a=rnk[a],b=rnk[b];
	if (a>b) rtn ht[RMQ(b+1,a)];
	else rtn ht[RMQ(a+1,b)];
}

}
}
}
