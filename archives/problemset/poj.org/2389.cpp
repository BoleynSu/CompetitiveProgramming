//Boleyn Su's Template for Codeforces
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <climits>
using namespace std;

#define lp for(;;)
#define rep(i,n) for (int i=0;i<(n);++i)
#define ft(i,a,b) for (int i=(a);i<=(b);++i)
#define fdt(i,a,b) for (int i=(a);i>=b;--i)
#define feach(e,s,t) for (t::itr e=(s).begin();e!=(s).end();++e)
#define fsubset(subset,set) for (int subset=set&(set-1);subset;subset=(subset-1)&set)
#define whl while
#define rtn return
#define fl(x,y) memset((x),char(y),sizeof(x))
#define clr(x) fl(x,0)
#define cpy(x,y) memcpy((x),(y),sizeof(x))
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(x) ((int)(x).size())
#define len(x) ((int)(x).length())
#define all(x) (x).begin(),(x).end()
#define srt(x) sort(all(x))
#define vec vector
#define pr pair
#define que queue
#define prq priority_queue
#define itr iterator
#define prt(x) cout<<#x<<"="<<(x)<<endl
#define asrtWA(s) do if(!(s))exit(0);whl(0)
#define asrtTLE(s) do if(!(s))whl(1);whl(0)
#define asrtMLE(s) do if(!(s))whl(new int);whl(0)
#define asrtOLE(s) do if(!(s))whl(1)puts("OLE");whl(0)
#define asrtRE(s) do if(!(s))*(int*)0=0;whl(0)

typedef long long int lli;
typedef double db;
typedef char* cstr;
typedef string str;
typedef vec<int> vi;
typedef vec<vi> vvi;
typedef vec<bool> vb;
typedef vec<vb> vvb;
typedef vec<str> vs;
typedef pr<int, int> pii;
typedef pr<db,db> pdd;
typedef pr<str,int> psi;
typedef map<int,int> mii;
typedef map<str,int> msi;
typedef map<char,int> mci;
typedef set<int> si;
typedef set<str> ss;
typedef que<int> qi;
typedef prq<int> pqi;

const int oo=(~0u)>>1;
const lli ooll=(~0ull)>>1;
const db inf=1e+8;
const db eps=1e-8;
const db pi=acos(-1.0);
const int MOD=1000000007;

template<typename type>inline bool cmax(type& a,const type& b){rtn a<b?a=b,true:false;}
template<typename type>inline bool cmin(type& a,const type& b){rtn a>b?a=b,true:false;}
template<typename type>inline type sqr(const type& x){rtn x*x;}
int dbcmp(const db& a,const db& b){rtn (a>b+eps)-(a<b-eps);}
int sgn(const db& x){rtn dbcmp(x,0);}
template<typename type>inline type gcd(type a,type b){if(b)whl((a%=b)&&(b%=a));rtn a+b;}
template<typename type>inline type lcm(type a,type b){rtn a*b/gcd(a,b);}
template<typename type>inline void bit_inc(vec<type>& st,int x,type inc){whl(x<sz(st))st[x]+=inc,x|=x+1;}
template<typename type>inline type bit_sum(const vec<type>& st,int x){type s=0;whl(x>=0)s+=st[x],x=(x&(x+1))-1;rtn s;}
inline void make_set(vi& set,int size){set.resize(size);rep(i,size)set[i]=i;}
inline int find_set(vi& set,int x){if(set[x]!=x)set[x]=find_set(set,set[x]);rtn set[x];}
inline bool union_set(vi& set,int a,int b){a=find_set(set,a),b=find_set(set,b);rtn a==b?false:set[a]=b,true;}

/*
Package:
数学.多项式乘法

Description:
利用FFT实现的O(nlogn)的多项式乘法

Interface:
multiply:{
输入vector<int> p1,p2
输出vector<double>
multiply(p1,p2)=p1*p2
p1,p2,multiply(p1,p2)分别表示多项式 sum{x^k*p1[k]},sum{x^k*p2[k]},sum{x^k*multiply(p1,p2)[k]}
Warning:
如果多项式的系数过大会失去精度
}

Include:
#include <my_template_for_codeforces>

Test:
POJ2389
JOJ1013
HDU1402

References:
《算法导论》(第30章 多项式与快速傅里叶变换)

Latest Update:
2011-10-27
*/
typedef complex<double> cpx;
typedef vec<cpx> vc;
typedef vec<db> vdb;
void FFT(vc& p,int flag=+1,bool aFFT=false)
{
	if (sz(p)!=1)
	{
		cpx w=1,wn=cpx(cos(flag*2*pi/sz(p)),sin(flag*2*pi/sz(p)));
		vc p1(sz(p)/2),p2(sz(p)/2);
		rep(i,sz(p1)) p1[i]=p[i*2],p2[i]=p[i*2+1];
		FFT(p1,flag,false),FFT(p2,flag,false);
		rep(k,sz(p1)) p[k]=p1[k]+w*p2[k],p[k+sz(p1)]=p1[k]-w*p2[k],w*=wn;
		if (aFFT) rep(k,sz(p)) p[k]/=cpx(sz(p));
	}
}
vdb multiply(vi& p1,vi& p2)
{
	int ps=sz(p1)+sz(p2),rps=1;
	whl(rps<ps) rps*=2;
	vdb p(rps);
	p1.resize(sz(p)),p2.resize(sz(p));
	vc pc1(sz(p)),pc2(sz(p)),pc(sz(p));
	rep(i,sz(p)) pc1[i]=cpx(p1[i]),pc2[i]=cpx(p2[i]);
	FFT(pc1),FFT(pc2);
	rep(i,sz(p)) pc[i]=pc1[i]*pc2[i];
	FFT(pc,-1,true);
	rep(i,sz(p)) p[i]=pc[i].real();
	rtn p;
}
class BigUnsignedInteger
{
	enum{BASE=10000};
	vi data;
	void delete_useless_zero()
	{
		whl(sz(data)>1&&!data.back()) data.pop_back();
	}
	void shiftLeft(int x)
	{
		if (x<0) shiftRight(-x);
		else
		{
			data.resize(sz(data)+x);
			fdt(i,sz(data)-1,x) data[i]=data[i-x];
			rep(i,x) data[i]=0;
		}
	}
	void shiftRight(int x)
	{
		if (x<0) shiftLeft(-x);
		else
		{
			if (sz(data)<=x) data.clear(),data.pb(0);
			else
			{
				rep(i,sz(data)-x) data[i]=data[i+x];
				data.resize(sz(data)-x);
			}
		}
	}
public:
	BigUnsignedInteger(unsigned int value=0)
	{
		if (value) whl (value) data.pb(value%BASE),value/=BASE;
		else data.pb(0);
	}
	friend BigUnsignedInteger operator+(const BigUnsignedInteger& a,const BigUnsignedInteger& b)
	{
		BigUnsignedInteger c;
		c.data.resize(max(sz(a.data),sz(b.data)));
		int t=0;
		rep(i,sz(c.data))
		{
			t+=(i<sz(a.data)?a.data[i]:0)+(i<sz(b.data)?b.data[i]:0);
			if (t<BASE) c.data[i]=t,t=0;
			else c.data[i]=t-BASE,t=1;
		}
		if (t) c.data.pb(t);
		c.delete_useless_zero();
		rtn c;
	}
	friend BigUnsignedInteger operator-(const BigUnsignedInteger& a,const BigUnsignedInteger& b)
	{
		if (a<b) throw "subtract overflows";
		BigUnsignedInteger c;
		c.data.resize(sz(a.data));
		int t=0;
		rep(i,sz(c.data))
		{
			t+=a.data[i]-(i<sz(b.data)?b.data[i]:0);
			if (t<0) c.data[i]=t+BASE,t=-1;
			else c.data[i]=t,t=0;
		}
		c.delete_useless_zero();
		rtn c;
	}
	friend BigUnsignedInteger operator*(const BigUnsignedInteger& a,const BigUnsignedInteger& b)
	{
		vi ad=a.data,bd=b.data;
		vdb cd=multiply(ad,bd);
		BigUnsignedInteger c;
		c.data.resize(sz(cd));
		lli t=0;
		rep(i,sz(cd)) t+=lli(cd[i]+0.5),c.data[i]=t%BASE,t/=BASE;
		whl(t) c.data.pb(t%BASE),t/=BASE;
		c.delete_useless_zero();
		rtn c;
	}
	friend BigUnsignedInteger operator/(const BigUnsignedInteger& a,const BigUnsignedInteger& b)
	{
		if (b==0) throw "division by zero";
		int k=sz(a.data)+1;
		BigUnsignedInteger x=1;
		x.shiftLeft(k-sz(b.data));
		lp
		{
			BigUnsignedInteger y=b*x*x;
			y.shiftRight(k),y=2*x-y;
			if (x==y) break;
			x=y;
		}
		BigUnsignedInteger c=a*x;
		c.shiftRight(k);
		rtn c;
	}
	friend BigUnsignedInteger operator%(const BigUnsignedInteger& a,const BigUnsignedInteger& b)
	{
 		if (b==0) throw "modulo by zero";
		rtn a-a/b*b;
	}
	friend BigUnsignedInteger sqrt(const BigUnsignedInteger& x)
	{
		if (x==0) rtn 0;
		else
		{
			BigUnsignedInteger y=1;
			y.shiftLeft((sz(x.data)+1)/2);
			lp
			{
				BigUnsignedInteger z=(y+x/y)/2;
				if (y<=z) break;
				y=z;
			}
			rtn y;
		}
	}
	friend bool operator<(const BigUnsignedInteger& a,const BigUnsignedInteger& b)
	{
		if (sz(a.data)!=sz(b.data)) rtn sz(a.data)<sz(b.data);
		else
		{
			fdt(i,sz(a.data)-1,0) if (a.data[i]!=b.data[i]) rtn a.data[i]<b.data[i];
			rtn false;
		}
	}
	friend bool operator==(const BigUnsignedInteger& a,const BigUnsignedInteger& b)
	{
		if (sz(a.data)!=sz(b.data)) rtn false;
		else
		{
			fdt(i,sz(a.data)-1,0) if (a.data[i]!=b.data[i]) rtn false;
			rtn true;
		}
	}
	inline friend bool operator>(const BigUnsignedInteger& a,const BigUnsignedInteger& b){rtn b<a;}
	inline friend bool operator<=(const BigUnsignedInteger& a,const BigUnsignedInteger& b){rtn !(a>b);}
	inline friend bool operator>=(const BigUnsignedInteger& a,const BigUnsignedInteger& b){rtn !(a<b);}
	inline friend bool operator!=(const BigUnsignedInteger& a,const BigUnsignedInteger& b){rtn !(a==b);}
	template<typename ostream>
	friend ostream& operator<<(ostream& cout,const BigUnsignedInteger& number)
	{
		int pos=sz(number.data);
		cout<<number.data[--pos];
		whl(pos--)
		{
			int t=BASE;
			whl(t/=10) cout.put((number.data[pos]/t)%10+'0');
		}
		rtn cout;
	}
	template<typename istream>
	friend istream& operator>>(istream& cin,BigUnsignedInteger& number)
	{
		string ns;
		cin>>ns;
		int pos=sz(ns);
		rep(i,pos) if (ns[i]<'0'||ns[i]>'9')
		{
			whl(--pos>=i) cin.putback(ns[pos]);
			if (++pos) ns=ns.substr(0,pos);
			else rtn cin.setstate(ios::badbit),cin;
		}
		number=0;
		int t=1;
		whl(--pos>=0)
		{
			if (t==BASE) t=1,number.data.pb(0);
			number.data.back()+=(ns[pos]-'0')*t;
			t*=10;
		}
		rtn cin;
	}
};
class BigInteger
{
	bool sign;
	BigUnsignedInteger number;
	BigInteger(bool sign,BigUnsignedInteger value):sign(sign),number(value){}
public:
	BigInteger(int value=0):sign(value>=0),number(sign?value:-value){}
	BigInteger(const BigUnsignedInteger& value):sign(true),number(value){}
	friend BigInteger operator+(const BigInteger& a,const BigInteger& b)
	{
		if (a.sign)
		{
			if (b.sign) rtn BigInteger(true,a.number+b.number);
			else
			{
				if (a.number>=b.number) rtn BigInteger(true,a.number-b.number);
				else rtn BigInteger(false,b.number-a.number);
			}
		}
		else
		{
			if (b.sign)
			{
				if (a.number<=b.number) rtn BigInteger(true,b.number-a.number);
				else rtn BigInteger(false,a.number-b.number);
			}
			else rtn BigInteger(false,a.number+b.number);
		}
	}
	friend BigInteger operator-(const BigInteger& a,const BigInteger& b)
	{
		if (a.sign)
		{
			if (!b.sign) rtn BigInteger(true,a.number+b.number);
			else
			{
				if (a.number>=b.number) rtn BigInteger(true,a.number-b.number);
				else rtn BigInteger(false,b.number-a.number);
			}
		}
		else
		{
			if (!b.sign)
			{
				if (a.number<=b.number) rtn BigInteger(true,b.number-a.number);
				else rtn BigInteger(false,a.number-b.number);
			}
			else rtn BigInteger(false,a.number+b.number);
		}
	}
	friend BigInteger operator*(const BigInteger& a,const BigInteger& b)
	{
		rtn BigInteger(!(a.sign^b.sign),a.number*b.number);
	}
	friend BigInteger operator/(const BigInteger& a,const BigInteger& b)
	{
		BigUnsignedInteger c=a.number/b.number;
		rtn BigInteger(c==0?true:!(a.sign^b.sign),c);
	}
	friend BigInteger operator%(const BigInteger& a,const BigInteger& b)
	{
		BigUnsignedInteger c=a.number%b.number;
		rtn BigInteger(c==0?true:a.sign,c);
	}
	friend BigInteger sqrt(const BigInteger& x)
	{
		if (!x.sign) throw "sqrt() argument cannot be negative";
		rtn BigInteger(true,sqrt(x.number));
	}
	friend bool operator<(const BigInteger& a,const BigInteger& b)
	{
		if (a.sign^b.sign) rtn b.sign;
		else rtn a.sign?a.number<b.number:a.number>b.number;
	}
	friend bool operator==(const BigInteger& a,const BigInteger& b)
	{
		if (a.sign^b.sign) rtn false;
		else rtn a.number==b.number;
	}
	inline friend bool operator>(const BigInteger& a,const BigInteger& b){rtn b<a;}
	inline friend bool operator<=(const BigInteger& a,const BigInteger& b){rtn !(a>b);}
	inline friend bool operator>=(const BigInteger& a,const BigInteger& b){rtn !(a<b);}
	inline friend bool operator!=(const BigInteger& a,const BigInteger& b){rtn !(a==b);}
	template<typename ostream>
	friend ostream& operator<<(ostream& cout,const BigInteger& number)
	{
		if (!number.sign) cout<<"-";
		cout<<number.number;
		rtn cout;
	}
	template<typename istream>
	friend istream& operator>>(istream& cin,BigInteger& number)
	{
		char sc;
		cin>>sc;
		if (sc=='+') number.sign=true;
		else if (sc=='-') number.sign=false;
		else number.sign=true,cin.putback(sc);
		cin>>number.number;
		rtn cin;
	}
};

BigInteger a,b;
int main()
{
	whl(cin>>a>>b)
	{
		try
		{
cout<<a*b<<endl;		}
		catch (const char* x)
		{
			prt(x);
		}
	}
}
