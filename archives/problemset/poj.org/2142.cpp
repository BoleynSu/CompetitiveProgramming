#include <iostream>
using namespace std;

typedef long long int lli;
lli lliabs(lli x)
{
	return x>0?x:-x;
}
lli gcd(lli a,lli b,lli& x,lli &y)
{
	if (!b)
	{
		x=1,y=0;
		return a;
	}
	else
	{
		lli a_=b,b_=a%b,x_,y_;
		lli g=gcd(a_,b_,x_,y_);
		x=y_;
		y=x_-(a/b)*y_;
		return g;
	}
}

int main()
{
	for (;;)
	{
		lli a,b,c,x,y;
		cin>>a>>b>>c;
		if (!a&&!b&&!c) break;
		lli g=gcd(a,b,x,y);
		lli l=a*b/g;
		x*=c/g;
		y*=c/g;
		lli ax=199303091993030939ll,ay=199303091993030939ll;
		lli axby=199303091993030939ll;
		for (lli t=-100000;t<=100000;t++)
		{
			lli x_=x+l/a*t;
			lli y_=y-l/b*t;
			if (lliabs(x_)+lliabs(y_)<ax+ay)
					ax=lliabs(x_),ay=lliabs(y_),
					axby=a*lliabs(x_)+b*lliabs(y_);
			else if (lliabs(x_)+lliabs(y_)==ax+ay)
			{
				if (a*lliabs(x_)+b*lliabs(y_)<axby)
					ax=lliabs(x_),ay=lliabs(y_),
					axby=a*lliabs(x_)+b*lliabs(y_);
			}
		}
		cout<<ax<<" "<<ay<<endl;
	}
}