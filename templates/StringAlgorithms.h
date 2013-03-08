/*
 * Package: StandardCodeLibrary.StringAlgorithms
 * Description:
 * KMP算法;
 * 扩展KMP算法;
 * 最长回文子串 Manacher's Algorithm;
 * AC自动机 Aho-Corasick Algorithm;
 * 后缀数组倍增法;
 * */
#include <Core>
#include <StringAlgorithms.AhoCorasickAlgorithm>
#include <StringAlgorithms.SuffixArray>

namespace StandardCodeLibrary
{
namespace StringAlgorithms
{

//KMP算法
void get_pi(const vi t,vi& pi)
{
	pi.resize(sz(t)),pi[0]=-1;
	int j=-1;
	repf(i,1,sz(t))
	{
		whl(j!=-1&&t[j+1]!=t[i]) j=pi[j];
		if (t[j+1]==t[i]) j++;
		pi[i]=j;
	}
}
void get_match(const vi& t,const vi& pi,const vi& s,vi& match)
{
	int j=-1;
	rep(i,sz(s))
	{
		whl(j!=-1&&t[j+1]!=s[i]) j=pi[j];
		if (t[j+1]==s[i]) j++;
		if (j==sz(t)-1)
		{
			match.pb(i-j);
			j=pi[j];
		}
	}
}
int KMP(const vi& t,const vi& s)
{
	vi pi;
	get_pi(t,pi);
	vi match;
	get_match(t,pi,s,match);
	if (sz(match)) rtn match.front();
	else rtn -1;
}

//扩展KMP算法
void get_ext(const vi& t,vi& ext)
{
	ext.resize(sz(t)),ext[0]=sz(t);
	if (sz(t)==1) rtn;
	int j=0,a=1;
	whl(1+j<sz(t)&&t[1+j]==t[j]) j++;
	ext[1]=j;
	repf(i,2,sz(t))
	{
		if (i+ext[i-a]<a+ext[a]) ext[i]=ext[i-a];
		else
		{
			j=max(a+ext[a]-i,0);
			whl(i+j<sz(t)&&t[i+j]==t[j]) j++;
			ext[a=i]=j;
		}
	}
}
void get_extend(const vi& t,const vi& ext,const vi& s,vi& extend)
{
	extend.resize(sz(s));
	int j=0,a=0;
	whl(j<sz(s)&&j<sz(t)&&s[j]==t[j]) j++;
	extend[0]=j;
	repf(i,1,sz(s))
	{
		if (i+ext[i-a]<a+extend[a]) extend[i]=ext[i-a];
		else
		{
			j=max(a+extend[a]-i,0);
			whl(i+j<sz(s)&&j<sz(t)&&s[i+j]==t[j]) j++;
			extend[a=i]=j;
		}
	}
}

//最长回文子串 Manacher's Algorithm
void longest_palindromic_substring(const vi& str,vi& ans_str,int split=0)
{
	vi S;
	rep(i,sz(str)) S.pb(split),S.pb(str[i]);
	S.pb(split);
	vi p(sz(S));
	int ans,ansi,mid;
	ans=(p[mid=0]=1)-1;
	repf(i,1,sz(S))
	{
	    p[i]=p[mid]+mid>i?min(p[mid]+mid-i,p[mid*2-i]):1;
	    whl(i>=p[i]&&i+p[i]<sz(S)&&S[i-p[i]]==S[i+p[i]]) p[i]++;
	    if (cmax(ans,p[i]-1)) ansi=i;
	    if (p[i]+i>p[mid]+mid) mid=i;
	}
	ans_str.clear();
	ft(i,ansi-ans,ansi+ans)
		if (S[i]!=split) ans_str.pb(S[i]);
}

}
}
