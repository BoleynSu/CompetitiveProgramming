/*
 * Package: StandardCodeLibrary.StringAlgorithms
 * Description:
 * KMP算法 Knuth-Morris-Pratt Algorithm;
 * Z Algorithm;
 * 最长回文子串 Manacher's Algorithm;
 * 字符串的最小表示法 求 旋转后得到的最小字符串
 * */
#include <Core>
#include <StringAlgorithms.AhoCorasickAlgorithm>
#include <StringAlgorithms.SuffixArray>
#include <StringAlgorithms.SuffixAutomaton>

namespace StandardCodeLibrary
{
namespace StringAlgorithms
{

//KMP算法
void get_pi(const vi& t,vi& pi)
{
	pi.resize(sz(t)),pi[0]=-1;
	int j=-1;
	repf(i,1,sz(t))
	{
		whl(j!=-1&&t[j+1]!=t[i]) j=pi[j];
		if (t[j+1]==t[i]) j++;
		pi[i]=(j!=-1&&i+1<sz(t)&&t[j+1]==t[i+1])?pi[j]:j;
	}
}
void get_match(const vi& t,const vi& pi,const vi& s,vi& match)
{
	match.clear();
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

//Z Algorithm
void z_algorithm(const vi& s,vi& z)
{
	z.resize(sz(s)),z[0]=0;
	int j=0,a=0;
	repf(i,1,sz(s))
	{
		if (i+z[i-a]<a+z[a]) z[i]=z[i-a];
		else
		{
			j=max(a+z[a]-i,0);
			whl(i+j<sz(s)&&s[i+j]==s[j]) j++;
			z[a=i]=j;
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

//字符串的最小表示法 求 旋转后得到的最小字符串
str lexicographically_minimal_string_rotation(str s)
{
	int i=0,j=1;
	whl(i<sz(s)&&j<sz(s))
	{
		int k=0;
		whl(k<sz(s)&&s[(i+k)%sz(s)]==s[(j+k)%sz(s)]) k++;
		if (s[(i+k)%sz(s)]>s[(j+k)%sz(s)]) i+=k+1;
		else if (s[(i+k)%sz(s)]<s[(j+k)%sz(s)]) j+=k+1;
		else break;
		if (i==j) j++;
	}
	int b=min(i,j);
	str ans;
	rep(d,sz(s)) ans.pb(s[(b+d)%sz(s)]);
	rtn ans;
}

}
}
