/*
 * Package: StandardCodeLibrary.StringAlgorithms
 * Description:
 * KMP算法;
 * 扩展KMP算法;
 * AC自动机;
 * 后缀数组DC3;
 * */
#include <Core>

namespace StandardCodeLibrary
{
namespace StringAlorithm
{

typedef char Char;
typedef vec<Char> String;

//KMP算法
void get_pi(const String t,vi& pi)
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
void get_match(const String& t,const vi& pi,const String& s,vi& match)
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
int KMP(const String& t,const String& s)
{
	vi pi;
	get_pi(t,pi);
	vi match;
	get_match(t,pi,s,match);
	if (sz(match)) rtn match.front();
	else rtn -1;
}

//扩展KMP算法
void get_ext(const String& t,vi ext)
{
	ext.resize(sz(t)),ext[0]=sz(t);
	int j=sz(t);
	repf(i,1,sz(t))
	{

	}
}

}
}
