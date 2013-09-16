#ifndef DEBUG
//https://github.com/boleynsu/acmicpc-codes/blob/master/templates/Core.hpp
/*
 * Package: StandardCodeLibrary.Core
 * */
//引进常用的头文件并使用std名字空间;
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <utility>
#include <vector>
#include <list>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <numeric>
#include <bitset>
#include <complex>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits>
using namespace std;

//用于减少代码量的宏;
#define lp for(;;)
#define repf(i,a,b) for (int i=(a);i<(b);++i)
#define ft(i,a,b) for (int i=(a);i<=(b);++i)
#define fdt(i,a,b) for (int i=(a);i>=(b);--i)
#define rrepf(i,a,b) fdt(i,(a)-1,b)
#define rep(i,n) repf(i,0,n)
#define rrep(i,n) rrepf(i,n,0)
#define for_nonempty_subsets(subset,set) for (int subset=set;subset;subset=(subset-1)&(set))
#define for_in_charset(i,charset) for (cstr i=(charset);*i;i++)
#define whl while
#define rtn return
#define fl(x,y) memset((x),char(y),sizeof(x))
#define clr(x) fl(x,char(0))
#define cpy(x,y) memcpy(x,y,sizeof(x))
#define sf scanf
#define pf printf
#define vec vector
#define pr pair
#define que queue
#define prq priority_queue
#define itr iterator
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define ins insert
#define ers erase
#define lb lower_bound
#define ub upper_bound
#define rnk order_of_key
#define sel find_by_order
#define sz(x) (int((x).size()))
#define all(x) (x).begin(),(x).end()
#define srt(x) sort(all(x))
#define uniq(x) srt(x),(x).erase(unique(all(x)),(x).end())
#define rev(x) reverse(all(x))
#define shf(x) random_shuffle(all(x))
#define nxtp(x) next_permutation(all(x))

//调试相关的宏;
#ifndef DEBUG
#define prt(x) (cerr)
#define asrtWA(s) do if(!(s))exit(0);whl(0)
#define asrtTLE(s) do if(!(s))whl(1);whl(0)
#define asrtMLE(s) do if(!(s))whl(new int);whl(0)
#define asrtOLE(s) do if(!(s))whl(1)puts("OLE");whl(0)
#define asrtRE(s) do if(!(s))*(int*)0=0;whl(0)
#define runtime() (cerr)
#define input(in) freopen(in,"r",stdin)
#define output(out) freopen(out,"w",stdout)
#else
#define prt(x) cerr<<"第"<<__LINE__<<"行\t: "<<#x"\t="<<(x)<<endl
#define asrtWA(s) do if(!(s))cerr<<"assert("#s")"<<endl;whl(0)
#define asrtTLE(s) do if(!(s))cerr<<"assert("#s")"<<endl;whl(0)
#define asrtMLE(s) do if(!(s))cerr<<"assert("#s")"<<endl;whl(0)
#define asrtOLE(s) do if(!(s))cerr<<"assert("#s")"<<endl;whl(0)
#define asrtRE(s) do if(!(s))cerr<<"assert("#s")"<<endl;whl(0)
#define runtime() cerr<<"Used: "<<db(clock())/CLOCKS_PER_SEC<<"s"<<endl
#define input(in)
#define output(out)
#endif

//常用数据类型;
typedef long long int lli;
typedef double db;
typedef const char* cstr;
typedef string str;
typedef vec<int> vi;
typedef vec<vi> vvi;
typedef vec<lli> vl;
typedef vec<vl> vvl;
typedef vec<bool> vb;
typedef vec<vb> vvb;
typedef vec<char> vc;
typedef vec<vc> vvc;
typedef vec<str> vs;
typedef pr<int,int> pii;
typedef pr<lli,lli> pll;
typedef pr<db,db> pdd;
typedef vec<pii> vpii;
typedef vec<pll> vpll;
typedef vec<pdd> vpdd;
typedef map<int,int> mii;
typedef map<str,int> msi;
typedef map<char,int> mci;
typedef set<int> si;
typedef set<str> ss;
typedef que<int> qi;

//常用常量:int的最大值;lli的最大值;db的误差相关常数;欧拉常数;圆周率;移动向量;取模使用的除数;
int oo=(~0u)>>1;
lli ooll=(~0ull)>>1;
db inf=1e+10;
db eps=1e-10;
db gam=0.5772156649015328606;
db pi=acos(-1.0);
int dx[]={1,0,-1,0,1,-1,-1,1,0};
int dy[]={0,1,0,-1,1,1,-1,-1,0};
int MOD=1000000007;

//常用函数:最大最小值更新;数学相关函数;输入和输出;树状数组;并查集;可合并堆;
template<typename type>inline bool cmax(type& a,const type& b){rtn a<b?a=b,true:false;}
template<typename type>inline bool cmin(type& a,const type& b){rtn b<a?a=b,true:false;}
template<typename type>inline type sqr(const type& x){rtn x*x;}
template<typename type>inline type mod(const type& x){rtn x%MOD;}
inline int sgn(const db& x){rtn (x>+eps)-(x<-eps);}
inline int dbcmp(const db& a,const db& b){rtn sgn(a-b);}
template<typename type>inline pr<type,type> operator-(const pr<type,type>& x){rtn mp(-x.x,-x.y);}
template<typename type>inline pr<type,type> operator+(const pr<type,type>& a,const pr<type,type>& b){rtn mp(a.x+b.x,a.y+b.y);}
template<typename type>inline pr<type,type> operator-(const pr<type,type>& a,const pr<type,type>& b){rtn mp(a.x-b.x,a.y-b.y);}
template<typename type>inline pr<type,type> operator*(const pr<type,type>& a,const type& b){rtn mp(a.x*b,a.y*b);}
template<typename type>inline pr<type,type> operator/(const pr<type,type>& a,const type& b){rtn mp(a.x/b,a.y/b);}
template<typename type>inline pr<type,type>& operator-=(pr<type,type>& a,const pr<type,type>& b){rtn a=a-b;}
template<typename type>inline pr<type,type>& operator+=(pr<type,type>& a,const pr<type,type>& b){rtn a=a+b;}
template<typename type>inline pr<type,type>& operator*=(pr<type,type>& a,const type& b){rtn a=a*b;}
template<typename type>inline pr<type,type>& operator/=(pr<type,type>& a,const type& b){rtn a=a/b;}
template<typename type>inline type cross(const pr<type,type>& a,const pr<type,type>& b){rtn a.x*b.y-a.y*b.x;}
template<typename type>inline type dot(const pr<type,type>& a,const pr<type,type>& b){rtn a.x*b.x+a.y*b.y;}
template<typename type>inline type gcd(type a,type b){if(b)whl((a%=b)&&(b%=a));rtn a+b;}
template<typename type>inline type lcm(type a,type b){rtn a*b/gcd(a,b);}
inline lli bin_pow(lli x,lli y){lli z=1;whl(y){if(y&1)z=mod(z*x);x=mod(sqr(x)),y>>=1;}rtn z;}
template<typename istream,typename first_type,typename second_type>inline istream& operator>>(istream& cin,pr<first_type,second_type>& x){rtn cin>>x.x>>x.y;}
template<typename ostream,typename first_type,typename second_type>inline ostream& operator<<(ostream& cout,const pr<first_type,second_type>& x){rtn cout<<x.x<<" "<<x.y;}
template<typename istream,typename type>inline istream& operator>>(istream& cin,vec<type>& x){rep(i,sz(x))cin>>x[i];rtn cin;}
template<typename ostream,typename type>inline ostream& operator<<(ostream& cout,const vec<type>& x){rep(i,sz(x))cout<<x[i]<<(i+1==sz(x)?"":" ");rtn cout;}
inline ostream& pdb(int prcs,db x){rtn cout<<setprecision(prcs)<<fixed<<(sgn(x)?(x):0);}
template<typename type>inline void bit_inc(vec<type>& st,int x,type inc){whl(x<sz(st))st[x]+=inc,x|=x+1;}
template<typename type>inline type bit_sum(const vec<type>& st,int x){type s=0;whl(x>=0)s+=st[x],x=(x&(x+1))-1;rtn s;}
template<typename type>inline type bit_kth(const vec<type>& st,int k){int x=0,y=0,z=0;whl((1<<(++y))<=sz(st));rrep(i,y){if((x+=1<<i)>sz(st)||z+st[x-1]>k)x-=1<<i;else z+=st[x-1];}rtn x;}
inline void make_set(vi& st){rep(i,sz(st))st[i]=i;}
inline int find_set(vi& st,int x){int y=x,z;whl(y!=st[y])y=st[y];whl(x!=st[x])z=st[x],st[x]=y,x=z;rtn y;}
inline bool union_set(vi& st,int a,int b){a=find_set(st,a),b=find_set(st,b);rtn a!=b?st[a]=b,true:false;}
inline void make_set(vpii& st){rep(i,sz(st))st[i]=mp(i,1);}
inline int find_set(vpii& st,int x){int y=x,z;whl(y!=st[y].x)y=st[y].x;whl(x!=st[x].x)z=st[x].x,st[x].x=y,x=z;rtn y;}
inline bool union_set(vpii& st,int a,int b){a=find_set(st,a),b=find_set(st,b);rtn a!=b?(st[a].y>st[b].y?st[a].x=b,st[a].y+=st[b].y:st[b].x=a,st[b].y+=st[a].y),true:false;}
template<typename type>inline void merge(type& a,type& b){if(sz(a)<sz(b))swap(a,b);whl(sz(b))a.ins(*b.begin()),b.ers(b.begin());}

//初始化;
struct Initializer{
#ifndef DEBUG
Initializer(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#else
~Initializer(){runtime();}
#endif
}initializer;

////非标准;
//#define for_each(e,s) for (__typeof__((s).begin()) e=(s).begin();e!=(s).end();++e)
//#include <ext/rope>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/tag_and_trait.hpp>
//typedef __gnu_cxx::rope<char> rope;
//template<typename key,typename value>class ext_map:public __gnu_pbds::tree<key,value,less<key>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>{};
//#define ctz __builtin_ctz
//#define clz __builtin_clz
//#define bc __builtin_popcount
#else
//上面部分的代码生成的Precompiled Headers
#include <Core>
#endif

void read(vvi& c,cstr path)
{
	FILE* file=fopen(path,"r+b");

	char header[54];
	fread(header,sizeof (char),54,file);

	int w=*(int*)&header[18],h=*(int*)&header[22];

	char tab[1024];
	fread(tab,sizeof (char),1024,file);

	char* data=new char[w*h];
	fread(data,sizeof (char),w*h,file);
	c=vvi(h,vi(w));
	rep(i,h)
		rep(j,w)
			c[h-1-i][j]=(unsigned char)data[i*w+j];
	delete[] data;
	fclose(file);
}

void write(vec<vvi>& cs,vvi& lst)
{
	ofstream tout("output/table.txt");
	rep(i,sz(lst)) tout<<lst[i]<<endl;
	FILE* file=fopen("output/picture.bmp","w+b");
	char header[54]={
		'B','M',
		0,0,0,0,
		0,0,
		0,0,
		54,0,0,0,
		40,0,0,0,
		0,0,0,0,
		0,0,0,0,
		1,0,
		8,0,
		0,0,0,0,
		0,0,0,0,
		0x13,0x0B,0,0,
		0x13,0x0B,0,0,
		0,0,0,0,
		0,0,0,0
	};
	int w=0,h=0;
	rep(i,sz(lst)) h+=sz(cs[lst[i].front()]);
	rep(i,sz(lst.front())) w+=sz(cs[lst.front()[i]].front());
	*(int*)&header[18]=w;
	*(int*)&header[22]=h;
	*(int*)&header[2]=54+1024+w*h;
	*(int*)&header[46]=w*h;
	fwrite(header,sizeof (char),54,file);

	rep(i,256)
	{
		char palette[4]={(char)i,(char)i,(char)i,0};
		fwrite(palette,sizeof (char),4,file);
	}

	rrep(l,sz(lst))
		rrep(i,sz(cs[lst[l].front()]))
			rep(j,sz(lst[l]))
				rep(k,sz(cs[lst[l][j]][i]))
					fwrite(&cs[lst[l][j]][i][k],sizeof (char),1,file);
	fclose(file);
}

void write(vec<vvi>& cs,vvi& lst,cstr path)
{
	FILE* file=fopen(path,"w+b");
	char header[54]={
		'B','M',
		0,0,0,0,
		0,0,
		0,0,
		54,0,0,0,
		40,0,0,0,
		0,0,0,0,
		0,0,0,0,
		1,0,
		8,0,
		0,0,0,0,
		0,0,0,0,
		0x13,0x0B,0,0,
		0x13,0x0B,0,0,
		0,0,0,0,
		0,0,0,0
	};
	int w=0,h=0;
	rep(i,sz(lst)) h+=sz(cs[lst[i].front()]);
	rep(i,sz(lst.front())) w+=sz(cs[lst.front()[i]].front());
	*(int*)&header[18]=w;
	*(int*)&header[22]=h;
	*(int*)&header[2]=54+1024+w*h;
	*(int*)&header[46]=w*h;
	fwrite(header,sizeof (char),54,file);

	rep(i,256)
	{
		char palette[4]={(char)i,(char)i,(char)i,0};
		fwrite(palette,sizeof (char),4,file);
	}

	rrep(l,sz(lst))
		rrep(i,sz(cs[lst[l].front()]))
			rep(j,sz(lst[l]))
				rep(k,sz(cs[lst[l][j]][i]))
					fwrite(&cs[lst[l][j]][i][k],sizeof (char),1,file);
	fclose(file);
}

vec<vvi> tab;
vi tabw,tabh;
void show(vvi& c)
{
	rep(i,sz(c))
	{
		rep(j,sz(c[i]))
		{
			if (c[i][j]) fprintf(stderr,"*",c[i][j]);
			else fprintf(stderr," ");
		}
		fprintf(stderr,"\n");
	}
}
bool match(vvi m,vvi& t)
{
	int h=sz(m),w=sz(m[0]);
	m.ins(m.begin(),vi(w,255));
	m.ins(m.begin(),vi(w,255));
	m.pb(vi(w,255));
	m.pb(vi(w,255));
	h+=4;
	rep(i,h)
	{
		m[i].ins(m[i].begin(),255);
		m[i].ins(m[i].begin(),255);
		m[i].pb(255);
		m[i].pb(255);
	}
	w+=4;
	const db FACTOR=0.7;
	rep(y,h-sz(t)+1) rep(x,w-sz(t[0])+1)
	{
		int un=0,in=0;
		rep(i,sz(t)) rep(j,sz(t[i]))
		{
			if (m[y+i][x+j]==0||t[i][j]==0) un++;
			if (m[y+i][x+j]==0&&t[i][j]==0) in++;
		}
		if (in>=un*FACTOR) rtn true;
	}
	rtn false;
}
void floodfill(vvi& rc)
{
	const int FACTOR=50;
	vvi c=rc;
	rep(i,sz(c)) rep(j,sz(c[i])) if (c[i][j]<FACTOR)
	{
		vpii lst;
		int h=0;
		lst.pb(mp(i,j));
		whl(h<sz(lst))
		{
			pii u=lst[h++];
			rep(i,8)
			{
				pii v=u+mp(dx[i],dy[i]);
				if (v.x>=0&&v.x<sz(c)&&v.y>=0&&v.y<sz(c[v.x])&&c[v.x][v.y]<FACTOR)
				{
					c[v.x][v.y]=255;
					lst.pb(v);
				}
			}
		}
		int l=+oo,r=-oo,u=+oo,d=-oo;
		rep(i,sz(lst)) cmin(l,lst[i].x),cmax(r,lst[i].x),cmin(u,lst[i].y),cmax(d,lst[i].y);
		vvi get(r-l+1,vi(d-u+1,255));
		rep(i,sz(lst)) get[lst[i].x-l][lst[i].y-u]=rc[lst[i].x][lst[i].y];
		bool fnd=false;
		const int FACTOR=2;
		rep(i,sz(tab)) if (abs(tabw[i]-(d-u+1))<FACTOR&&abs(tabh[i]-(r-l+1))<FACTOR&&(match(get,tab[i])||match(tab[i],get))) fnd=true;
		if (!fnd)
		{
			tab.pb(get);
			tabw.pb(d-u+1);
			tabh.pb(r-l+1);
		}
	}
}
void init_tab()
{
	vvi c;
	char path[1024];
	sprintf(path,"input/alphabet.bmp");
	read(c,path);
	sprintf(path,"output/alphabet.txt");
	ofstream fout(path);
	rep(i,sz(c))
	{
		rep(j,sz(c[i])) fout<<(c[i][j]?'*':' ');
		fout<<endl;
	}
	floodfill(c);
}

int calc(int a,int b)
{
	if (a==b) rtn a;
	else rtn min(max((a*3-b)/2,5),250);
}
int func(int x)
{
	rtn pow(pow(100.0,1.0/255.0),abs(x))*1e4;
}
int LRmatch_floodfill(vvi& rc,int height,int width)
{
	const int FACTOR=50;
	int ttl=0,cnt=0,little=0;
	vvi c=rc;
	rep(i,height) ft(j,width-1,width) if (c[i][j]<FACTOR)
	{
		vpii lst;
		int h=0;
		lst.pb(mp(i,j));
		whl(h<sz(lst))
		{
			pii u=lst[h++];
			rep(i,8)
			{
				pii v=u+mp(dx[i],dy[i]);
				if (v.x>=0&&v.x<sz(c)&&v.y>=0&&v.y<sz(c[v.x])&&c[v.x][v.y]<FACTOR)
				{
					c[v.x][v.y]=255;
					lst.pb(v);
				}
			}
		}
		int l=+oo,r=-oo,u=+oo,d=-oo;
		rep(i,sz(lst)) cmin(l,lst[i].x),cmax(r,lst[i].x),cmin(u,lst[i].y),cmax(d,lst[i].y);
		if (l!=0&&r!=height-1&&sz(lst)<10) rtn 0;
		vvi get(r-l+1,vi(d-u+1,255));
		rep(i,sz(lst)) get[lst[i].x-l][lst[i].y-u]=rc[lst[i].x][lst[i].y];
		bool fnd=false;
		const int FACTOR=2;
		rep(i,sz(tab)) if (abs(tabw[i]-(d-u+1))<FACTOR&&abs(tabh[i]-(r-l+1))<FACTOR&&(match(get,tab[i])||match(tab[i],get)))
			fnd=true;
		if (fnd&&r-l+1>20&&u<width&&d>=width)
		{
			cnt++;
			if (min(d-width,width-1-u)<3) little++;
		}
		ttl++;
	}
	if (ttl<=2) rtn max(1,cnt);
	if (little) rtn max(1,cnt-little+little/2);
	rtn cnt;
}
int UDmatch_floodfill(vvi& rc,int height,int width)
{
	const int FACTOR=50;
	int ttl=0,cnt=0,little=0;
	vvi c=rc;
	ft(i,height-1,height) rep(j,width) if (c[i][j]<FACTOR)
	{
		vpii lst;
		int h=0;
		lst.pb(mp(i,j));
		whl(h<sz(lst))
		{
			pii u=lst[h++];
			rep(i,8)
			{
				pii v=u+mp(dx[i],dy[i]);
				if (v.x>=0&&v.x<sz(c)&&v.y>=0&&v.y<sz(c[v.x])&&c[v.x][v.y]<FACTOR)
				{
					c[v.x][v.y]=255;
					lst.pb(v);
				}
			}
		}
		int l=+oo,r=-oo,u=+oo,d=-oo;
		rep(i,sz(lst)) cmin(l,lst[i].x),cmax(r,lst[i].x),cmin(u,lst[i].y),cmax(d,lst[i].y);
		if (u!=0&&d!=width-1&&sz(lst)<10) rtn 0;
		vvi get(r-l+1,vi(d-u+1,255));
		rep(i,sz(lst)) get[lst[i].x-l][lst[i].y-u]=rc[lst[i].x][lst[i].y];
		bool fnd=false;
		const int FACTOR=2;
		rep(i,sz(tab)) if (abs(tabw[i]-(d-u+1))<FACTOR&&abs(tabh[i]-(r-l+1))<FACTOR&&(match(get,tab[i])||match(tab[i],get)))
			fnd=true;
		if (fnd&&r-l+1>20&&l<height&&r>=height)
		{
			cnt++;
			if (min(r-height,height-1-l)<3) little++;
		}
		ttl++;
	}
	if (ttl<=2) rtn max(1,cnt);
	if (little) rtn max(1,cnt-little+little/2);
	rtn cnt;
}
int LRmatch(vvi& l,vvi& r,int height,int width)
{
	vvi m(height,vi(width*2));
	rep(i,height) rep(j,width)
		m[i][j]=l[i][j],m[i][j+width]=r[i][j];
	rtn LRmatch_floodfill(m,height,width);
}
int UDmatch(vvi& u,vvi& d,int height,int width)
{
	vvi m(height*2,vi(width));
	rep(i,height) rep(j,width)
		m[i][j]=u[i][j],m[i+height][j]=d[i][j];
	rtn UDmatch_floodfill(m,height,width);
}

void out(int n,int height,int width,vec<vvi>& cs,vi& l,vi& r,vi& u,vi& d)
{
	vpii p(n);
	vi bl(n,-1);
	vvi nds;
	rep(i,n) if (bl[i]==-1)
	{
		vi q;
		int qh=0;
		q.pb(i);
		bl[i]=sz(nds);
		p[i]=mp(0,0);
		whl(qh<sz(q))
		{
			int v=q[qh++];
			if (l[v]!=-1&&bl[l[v]]==-1)
			{
				q.pb(l[v]);
				bl[l[v]]=sz(nds);
				p[l[v]]=p[v]+mp(0,-1);
			}
			if (r[v]!=-1&&bl[r[v]]==-1)
			{
				q.pb(r[v]);
				bl[r[v]]=sz(nds);
				p[r[v]]=p[v]+mp(0,+1);
			}
			if (u[v]!=-1&&bl[u[v]]==-1)
			{
				q.pb(u[v]);
				bl[u[v]]=sz(nds);
				p[u[v]]=p[v]+mp(-1,0);
			}
			if (d[v]!=-1&&bl[d[v]]==-1)
			{
				q.pb(d[v]);
				bl[d[v]]=sz(nds);
				p[d[v]]=p[v]+mp(+1,0);
			}
		}
		nds.pb(q);
	}
	rep(i,sz(nds))
	{
		vpii ps;
		rep(j,sz(nds[i]))
			ps.pb(p[nds[i][j]]);
		int l=+oo,r=-oo,u=+oo,d=-oo;
		rep(j,sz(ps)) cmin(l,ps[j].y),cmax(r,ps[j].y),cmin(u,ps[j].x),cmax(d,ps[j].x);
		char path[1024];
		sprintf(path,"output/%03d.bmp",i);
		vvi lst(d-u+1,vi(r-l+1,n));
		rep(j,sz(ps)) lst[ps[j].x-u][ps[j].y-l]=nds[i][j];
		cs.pb(vvi(height,vi(width)));
		write(cs,lst,path);
		sprintf(path,"output/table%03d.txt",i);
		ofstream tout(path);
		rep(i,sz(lst)) tout<<lst[i]<<endl;
		cs.pop_back();
	}
	prt(sz(nds));
}
void cut(int n,int height,int width,vec<vvi>& cs,vi& l,vi& r,vi& u,vi& d,vvi& LRcost,vvi& UDcost,int row,int column)
{
	vpii p(n);
	vi bl(n,-1);
	vvi nds;
	rep(i,n) if (bl[i]==-1)
	{
		vi q;
		int qh=0;
		q.pb(i);
		bl[i]=sz(nds);
		p[i]=mp(0,0);
		whl(qh<sz(q))
		{
			int v=q[qh++];
			if (l[v]!=-1&&bl[l[v]]==-1)
			{
				q.pb(l[v]);
				bl[l[v]]=sz(nds);
				p[l[v]]=p[v]+mp(0,-1);
			}
			if (r[v]!=-1&&bl[r[v]]==-1)
			{
				q.pb(r[v]);
				bl[r[v]]=sz(nds);
				p[r[v]]=p[v]+mp(0,+1);
			}
			if (u[v]!=-1&&bl[u[v]]==-1)
			{
				q.pb(u[v]);
				bl[u[v]]=sz(nds);
				p[u[v]]=p[v]+mp(-1,0);
			}
			if (d[v]!=-1&&bl[d[v]]==-1)
			{
				q.pb(d[v]);
				bl[d[v]]=sz(nds);
				p[d[v]]=p[v]+mp(+1,0);
			}
		}
		nds.pb(q);
	}
	rep(i,sz(nds))
	{
		vpii ps;
		rep(j,sz(nds[i]))
			ps.pb(p[nds[i][j]]);
		int _l=+oo,_r=-oo,_u=+oo,_d=-oo;
		rep(j,sz(ps)) cmin(_l,ps[j].y),cmax(_r,ps[j].y),cmin(_u,ps[j].x),cmax(_d,ps[j].x);
		vec<vvi> lsts(_d-_u+1,vvi(_r-_l+1));
		rep(j,sz(ps)) lsts[ps[j].x-_u][ps[j].y-_l].pb(nds[i][j]);
		rep(i,sz(lsts)) rep(j,sz(lsts[i]))
		{
			rep(k,sz(lsts[i][j]))
			{
				int x=lsts[i][j][k];
				if (i>0)
				{
					int min=+oo,miny=-1;
					rep(l,sz(lsts[i-1][j]))
					{
						int y=lsts[i-1][j][l];
						if (cmin(min,UDcost[y][x]))
							miny=y;
					}
					if (miny!=-1)
					{
						d[miny]=x;
						u[x]=miny;
					}
				}
				if (j>0)
				{
					int min=+oo,miny=-1;
					rep(l,sz(lsts[i][j-1]))
					{
						int y=lsts[i][j-1][l];
						if (cmin(min,LRcost[y][x]))
							miny=y;
					}
					if (miny!=-1)
					{
						r[miny]=x;
						l[x]=miny;
					}
				}
			}
		}
		repf(i,1,sz(lsts))
		{
			int b=+oo,e=-oo;
			rep(j,sz(lsts[i])) if (sz(lsts[i-1][j])||sz(lsts[i][j]))
			{
				cmin(b,j),cmax(e,j);
			}
			if (e-b+1>column)
			{
				rep(j,sz(lsts[i]))
				{
					rep(k,sz(lsts[i][j]))
						u[lsts[i][j][k]]=-1;
					rep(k,sz(lsts[i-1][j]))
						d[lsts[i-1][j][k]]=-1;
				}
			}
		}
	}
}

int main()
{
	init_tab();

	int row,column,height,width;
	row=11,column=19,height=180,width=72;
	int n=row*column;

	vec<vvi> acs(n);
	vec<vvi> bcs(n);
	rep(i,n)
	{
		vvi& ac=acs[i];
		char path[1024];
		sprintf(path,"input/%03da.bmp",i);
		read(ac,path);
		vvi& bc=bcs[i];
		sprintf(path,"input/%03db.bmp",i);
		read(bc,path);
	}
	vec<vvi> backup=acs;
	acs.ins(acs.end(),all(bcs));
	bcs.ins(bcs.end(),all(acs));
	n*=2;

	vvi LRcost(n,vi(n)),UDcost(n,vi(n));
	vvi aLRcost(n,vi(n)),aUDcost(n,vi(n)),bLRcost(n,vi(n)),bUDcost(n,vi(n));
	rep(i,n)
	{
		cout<<i<<".bmp ..."<<endl;
		rep(j,n) rep(k,height) aLRcost[i][j]+=func(calc(acs[i][k][width-1],acs[i][k][width-2])-calc(acs[j][k][0],acs[j][k][1]));
		rep(j,n) rep(k,width) aUDcost[i][j]+=func(calc(acs[i][height-1][k],acs[i][height-2][k])-calc(acs[j][0][k],acs[j][1][k]));
		rep(j,n)
		{
			int cnt=LRmatch(acs[i],acs[j],height,width);
			if (!cnt) aLRcost[i][j]=height*func(255);
			else aLRcost[i][j]-=(cnt-1)*func(255)*30;
		}
		rep(j,n)
		{
			int cnt=UDmatch(acs[i],acs[j],height,width);
			if (!cnt) aUDcost[i][j]=width*func(255);
			else aUDcost[i][j]-=(cnt-1)*func(255)*20;
		}
		rep(j,n) rep(k,height) bLRcost[i][j]+=func(calc(bcs[i][k][width-1],bcs[i][k][width-2])-calc(bcs[j][k][0],bcs[j][k][1]));
		rep(j,n) rep(k,width) bUDcost[i][j]+=func(calc(bcs[i][height-1][k],bcs[i][height-2][k])-calc(bcs[j][0][k],bcs[j][1][k]));
		rep(j,n)
		{
			int cnt=LRmatch(bcs[i],bcs[j],height,width);
			if (!cnt) bLRcost[i][j]=height*func(255);
			else bLRcost[i][j]-=(cnt-1)*func(255)*30;
		}
		rep(j,n)
		{
			int cnt=UDmatch(bcs[i],bcs[j],height,width);
			if (!cnt) bUDcost[i][j]=width*func(255);
			else bUDcost[i][j]-=(cnt-1)*func(255)*20;
		}
	}
	rep(i,n) rep(j,n) LRcost[i][j]=aLRcost[i][j]+bLRcost[j][i],UDcost[i][j]=aUDcost[i][j]+bUDcost[i][j];
	ofstream fout("output/cost.txt");
	fout<<"LRcost:"<<endl;
	rep(i,n) rep(j,n) fout<<i<<"->"<<j<<": "<<LRcost[i][j]<<endl;
	fout<<"UDcost:"<<endl;
	rep(i,n) rep(j,n) fout<<i<<"\\"<<j<<": "<<UDcost[i][j]<<endl;

	vec<vpii> ln(n),rn(n),un(n),dn(n);
	vi l(n,-1),r(n,-1),u(n,-1),d(n,-1);
	rep(i,n)
	{
		ln[i].clear(),rn[i].clear(),un[i].clear(),dn[i].clear();
		rep(j,n) if (r[j]==-1&&j!=i) ln[i].pb(mp(LRcost[j][i],j));
		rep(j,n) if (l[j]==-1&&j!=i) rn[i].pb(mp(LRcost[i][j],j));
		rep(j,n) if (d[j]==-1&&j!=i) un[i].pb(mp(UDcost[j][i],j));
		rep(j,n) if (u[j]==-1&&j!=i) dn[i].pb(mp(UDcost[i][j],j));
		srt(ln[i]),srt(rn[i]),srt(un[i]),srt(dn[i]);
	}
	rep(i,n)
	{
		if (l[i]==-1&&(ln[i][1].x>ln[i][0].x*2||(ln[i][1].x!=ln[i][0].x&&rn[ln[i][0].y][0].x!=rn[ln[i][0].y][1].x&&rn[ln[i][0].y][0].y==i))) l[i]=ln[i][0].y;
		if (r[i]==-1&&(rn[i][1].x>rn[i][0].x*2||(rn[i][1].x!=rn[i][0].x&&ln[rn[i][0].y][0].x!=ln[rn[i][0].y][1].x&&ln[rn[i][0].y][0].y==i))) r[i]=rn[i][0].y;
		if (u[i]==-1&&(un[i][1].x>un[i][0].x*2||(un[i][1].x!=un[i][0].x&&dn[un[i][0].y][0].x!=dn[un[i][0].y][1].x&&dn[un[i][0].y][0].y==i))) u[i]=un[i][0].y;
		if (d[i]==-1&&(dn[i][1].x>dn[i][0].x*2||(dn[i][1].x!=dn[i][0].x&&un[dn[i][0].y][0].x!=un[dn[i][0].y][1].x&&un[dn[i][0].y][0].y==i))) d[i]=dn[i][0].y;
	}
	rep(i,n)
	{
		if (l[i]!=-1&&i!=r[l[i]]) l[i]=-1;
		if (r[i]!=-1&&i!=l[r[i]]) r[i]=-1;
		if (u[i]!=-1&&i!=d[u[i]]) u[i]=-1;
		if (d[i]!=-1&&i!=u[d[i]]) d[i]=-1;
	}
	rep(itr,10)
	{
		cut(n,height,width,acs,l,r,u,d,LRcost,UDcost,row,column);
		rep(i,n)
		{
			ln[i].clear(),rn[i].clear(),un[i].clear(),dn[i].clear();
			rep(j,n) if (r[j]==-1&&j!=i) ln[i].pb(mp(LRcost[j][i],j));
			rep(j,n) if (l[j]==-1&&j!=i) rn[i].pb(mp(LRcost[i][j],j));
			rep(j,n) if (d[j]==-1&&j!=i) un[i].pb(mp(UDcost[j][i],j));
			rep(j,n) if (u[j]==-1&&j!=i) dn[i].pb(mp(UDcost[i][j],j));
			srt(ln[i]),srt(rn[i]),srt(un[i]),srt(dn[i]);
		}
		rep(i,n)
		{
			if (l[i]==-1&&(ln[i][1].x>ln[i][0].x||(ln[i][1].x!=ln[i][0].x&&rn[ln[i][0].y][0].x!=rn[ln[i][0].y][1].x&&rn[ln[i][0].y][0].y==i))) l[i]=ln[i][0].y;
			if (r[i]==-1&&(rn[i][1].x>rn[i][0].x||(rn[i][1].x!=rn[i][0].x&&ln[rn[i][0].y][0].x!=ln[rn[i][0].y][1].x&&ln[rn[i][0].y][0].y==i))) r[i]=rn[i][0].y;
			if (u[i]==-1&&(un[i][1].x>un[i][0].x||(un[i][1].x!=un[i][0].x&&dn[un[i][0].y][0].x!=dn[un[i][0].y][1].x&&dn[un[i][0].y][0].y==i))) u[i]=un[i][0].y;
			if (d[i]==-1&&(dn[i][1].x>dn[i][0].x||(dn[i][1].x!=dn[i][0].x&&un[dn[i][0].y][0].x!=un[dn[i][0].y][1].x&&un[dn[i][0].y][0].y==i))) d[i]=dn[i][0].y;
		}
		rep(i,n)
		{
			if (l[i]!=-1&&u[l[i]]!=-1&&r[u[l[i]]]!=-1&&d[r[u[l[i]]]]==-1) d[r[u[l[i]]]]=i;
			if (u[i]!=-1&&r[u[i]]!=-1&&d[r[u[i]]]!=-1&&l[d[r[u[i]]]]==-1) l[d[r[u[i]]]]=i;
			if (r[i]!=-1&&d[r[i]]!=-1&&l[d[r[i]]]!=-1&&u[l[d[r[i]]]]==-1) u[l[d[r[i]]]]=i;
			if (d[i]!=-1&&l[d[i]]!=-1&&u[l[d[i]]]!=-1&&r[u[l[d[i]]]]==-1) r[u[l[d[i]]]]=i;
			if (l[i]!=-1&&d[l[i]]!=-1&&r[d[l[i]]]!=-1&&u[r[d[l[i]]]]==-1) u[r[d[l[i]]]]=i;
			if (d[i]!=-1&&r[d[i]]!=-1&&u[r[d[i]]]!=-1&&l[u[r[d[i]]]]==-1) l[u[r[d[i]]]]=i;
			if (r[i]!=-1&&u[r[i]]!=-1&&l[u[r[i]]]!=-1&&d[l[u[r[i]]]]==-1) d[l[u[r[i]]]]=i;
			if (u[i]!=-1&&l[u[i]]!=-1&&d[l[u[i]]]!=-1&&r[d[l[u[i]]]]==-1) r[d[l[u[i]]]]=i;
		}
		rep(i,n)
		{
			if (l[i]!=-1&&u[l[i]]!=-1&&r[u[l[i]]]!=-1&&d[r[u[l[i]]]]!=i) d[r[u[l[i]]]]=-1;
			if (u[i]!=-1&&r[u[i]]!=-1&&d[r[u[i]]]!=-1&&l[d[r[u[i]]]]!=i) l[d[r[u[i]]]]=-1;
			if (r[i]!=-1&&d[r[i]]!=-1&&l[d[r[i]]]!=-1&&u[l[d[r[i]]]]!=i) u[l[d[r[i]]]]=-1;
			if (d[i]!=-1&&l[d[i]]!=-1&&u[l[d[i]]]!=-1&&r[u[l[d[i]]]]!=i) r[u[l[d[i]]]]=-1;
			if (l[i]!=-1&&d[l[i]]!=-1&&r[d[l[i]]]!=-1&&u[r[d[l[i]]]]!=i) u[r[d[l[i]]]]=-1;
			if (d[i]!=-1&&r[d[i]]!=-1&&u[r[d[i]]]!=-1&&l[u[r[d[i]]]]!=i) l[u[r[d[i]]]]=-1;
			if (r[i]!=-1&&u[r[i]]!=-1&&l[u[r[i]]]!=-1&&d[l[u[r[i]]]]!=i) d[l[u[r[i]]]]=-1;
			if (u[i]!=-1&&l[u[i]]!=-1&&d[l[u[i]]]!=-1&&r[d[l[u[i]]]]!=i) r[d[l[u[i]]]]=-1;
		}
		rep(i,n)
		{
			if (l[i]!=-1&&i!=r[l[i]]) l[i]=-1;
			if (r[i]!=-1&&i!=l[r[i]]) r[i]=-1;
			if (u[i]!=-1&&i!=d[u[i]]) u[i]=-1;
			if (d[i]!=-1&&i!=u[d[i]]) d[i]=-1;
		}
	}
	out(n,height,width,acs,l,r,u,d);
}
