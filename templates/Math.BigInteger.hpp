/*
 * Package: StandardCodeLibrary.Math.BigInteger
 * Description:
 * 用FFT实现的O(nlogn)的多项式乘法;
 * 用FFT来实现高精度乘法;
 * 用牛顿迭代法实现高精度除法,高精度取余数,高精度开平方;
 * 用快速幂实现指数函数;
 * Usage:
 * multiply:
 * 输入vector<int> p1,p2
 * 输出vector<double>
 * multiply(p1,p2)=p1*p2
 * p1,p2,multiply(p1,p2)分别表示多项式 sum{x^k*p1[k]},sum{x^k*p2[k]},sum{x^k*multiply(p1,p2)[k]}
 * 如果多项式的系数过大会失去精度
 *
 * */
#include <Core>

namespace StandardCodeLibrary
{
namespace Math
{
namespace BigInteger
{

typedef complex<db> cpx;
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
	friend BigUnsignedInteger pow(const BigUnsignedInteger& x,unsigned int y)
	{
		BigUnsignedInteger z=1,w=x;
		whl(y)
		{
			if (y&1) z=z*w;
			w=w*w;
			y>>=1;
		}
		rtn z;
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
	friend BigInteger pow(const BigInteger& x,unsigned int y)
	{
		rtn BigInteger(x.sign?true:!(y&1),pow(x.number,y));
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

}
}
}
