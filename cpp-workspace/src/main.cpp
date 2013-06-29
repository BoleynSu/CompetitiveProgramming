/*
 * Package: StandardCodeLibrary.Core
 * */
//引进常用的头文件并使用std名字空间
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

//用于减少代码量的宏
#define lp for(;;)
#define repf(i,a,b) for (int i=(a);i<(b);++i)
#define rep(i,n) repf(i,0,n)
#define ft(i,a,b) for (int i=(a);i<=(b);++i)
#define fdt(i,a,b) for (int i=(a);i>=(b);--i)
#define fsubset(subset,set) for (int subset=(set)&((set)-1);subset;subset=(subset-1)&(set))
#define forin(i,charset) for (cstr i=(charset);*i;i++)
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

//调试相关的宏
#ifdef DEBUG
#define prt(x) cerr<<#x"="<<(x)<<endl
#define asrtWA(s) do if(!(s))do{cerr<<"assert("#s")"<<endl;}whl(0);whl(0)
#define asrtTLE(s) do if(!(s))do{cerr<<"assert("#s")"<<endl;}whl(0);whl(0)
#define asrtMLE(s) do if(!(s))do{cerr<<"assert("#s")"<<endl;}whl(0);whl(0)
#define asrtOLE(s) do if(!(s))do{cerr<<"assert("#s")"<<endl;}whl(0);whl(0)
#define asrtRE(s) do if(!(s))do{cerr<<"assert("#s")"<<endl;}whl(0);whl(0)
#define runtime() cerr<<"Used: "<<db(clock())/CLOCKS_PER_SEC<<"s"<<endl
#define input(in) do{}whl(0)
#define output(out) do{}whl(0)
#else
#define prt(x) (cerr)
#define asrtWA(s) do if(!(s))exit(0);whl(0)
#define asrtTLE(s) do if(!(s))whl(1);whl(0)
#define asrtMLE(s) do if(!(s))whl(new int);whl(0)
#define asrtOLE(s) do if(!(s))whl(1)puts("OLE");whl(0)
#define asrtRE(s) do if(!(s))*(int*)0=0;whl(0)
#define runtime() (cerr)
#define input(in) freopen(in,"r",stdin)
#define output(out) freopen(out,"w",stdout)
#endif

//常用数据类型
typedef long long int lli;
typedef double db;
typedef const char* cstr;
typedef string str;
typedef vec<int> vi;
typedef vec<vi> vvi;
typedef vec<bool> vb;
typedef vec<vb> vvb;
typedef vec<str> vs;
typedef pr<int,int> pii;
typedef pr<lli,lli> pll;
typedef pr<db,db> pdd;
typedef map<int,int> mii;
typedef map<str,int> msi;
typedef map<char,int> mci;
typedef set<int> si;
typedef set<str> ss;
typedef que<int> qi;
typedef vec<pii> vpii;
typedef vec<pdd> vpdd;

//常用常量:int的最大值;lli的最大值;db的误差相关常数;欧拉常数;圆周率;移动向量;取模使用的除数
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
template<typename istream,typename first_type,typename second_type>inline istream& operator>>(istream& cin,pr<first_type,second_type>& x){rtn cin>>x.x>>x.y;}
template<typename ostream,typename first_type,typename second_type>inline ostream& operator<<(ostream& cout,const pr<first_type,second_type>& x){rtn cout<<x.x<<" "<<x.y;}
template<typename istream,typename type>inline istream& operator>>(istream& cin,vec<type>& x){rep(i,sz(x))cin>>x[i];rtn cin;}
template<typename ostream,typename type>inline ostream& operator<<(ostream& cout,const vec<type>& x){rep(i,sz(x))cout<<x[i]<<(i+1==sz(x)?"":" ");rtn cout;}
inline ostream& pdb(int prcs,db x){rtn cout<<setprecision(prcs)<<fixed<<(sgn(x)?(x):0);}
template<typename type>inline void bit_inc(vec<type>& st,int x,type inc){whl(x<sz(st))st[x]+=inc,x|=x+1;}
template<typename type>inline type bit_sum(const vec<type>& st,int x){type s=0;whl(x>=0)s+=st[x],x=(x&(x+1))-1;rtn s;}
template<typename type>inline type bit_kth(const vec<type>& st,int k){int x=0,y=0,z=0;whl((1<<(++y))<=sz(st));fdt(i,y-1,0){if((x+=1<<i)>sz(st)||z+st[x-1]>k)x-=1<<i;else z+=st[x-1];}rtn x;}
inline void make_set(vi& st){rep(i,sz(st))st[i]=i;}
inline int find_set(vi& st,int x){int y=x,z;whl(y!=st[y])y=st[y];whl(x!=st[x])z=st[x],st[x]=y,x=z;rtn y;}
inline bool union_set(vi& st,int a,int b){a=find_set(st,a),b=find_set(st,b);rtn a!=b?st[a]=b,true:false;}
template<typename type>inline void merge(type& a,type& b){if(sz(a)<sz(b))swap(a,b);whl(sz(b))a.ins(*b.begin()),b.ers(b.begin());}

//初始化
struct Initializer{Initializer(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}~Initializer(){runtime();}}initializer;

//非标准
#define feach(e,s) for (__typeof__((s).begin()) e=(s).begin();e!=(s).end();++e)
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
using __gnu_cxx::rope;
template<typename key,typename value>class ext_map:public __gnu_pbds::tree<key,value,less<key>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>{};

const db TIME_LIMIT=0.1;
const int MAX_ROUND=300;

class Json
{
	enum TYPE
	{
		VAL = 0,
		LIST = 1,
		MAP = 2
	};
	TYPE type;
	string value;
	map<string, Json> *d;

	string intToString(int x)
	{
		string s = "";
		if (!x) s.push_back('0');
		for (;x;x/=10)
		{
			s.insert(s.begin(),'0'+(x%10));
		}
		return s;
	}


	public:
	Json(const string &_value)
	{
		type = VAL;
		value = _value;
		d = NULL;
	}
	Json(const int &_intValue)
	{
		type = VAL;
		value = intToString(_intValue);
		d = NULL;
	}
	Json()
	{
		type = MAP;
		d = NULL;
	}
	~Json()
	{
		if (d) delete d;
	}

	Json &operator[](const string &_key)
	{
		type = MAP;
		if (!d) d = new map<string, Json>;
		if (!d->count(_key)) d->insert(pair<string, Json>(_key, Json()));
		return (*d)[_key];
	}

	Json &operator[](const int &_keyInt)
	{
		type = LIST;
		if (!d) d = new map<string, Json>;
		string _key = intToString(_keyInt);

		if (!d->count(_key)) d->insert(pair<string, Json>(_key, Json()));
		return (*d)[_key];
	}

	Json &operator=(Json json)
	{
		type = json.type;
		d = json.d;
		value = json.value;
		return *this;
	}

	int size()
	{
		if (!d) return 0;
		return d->size();
	}

	string toString()
	{
		string res = "";
		if (type == VAL)
		{
			res.append("\"");
			res.append(value);
			res.append("\"");
		}
		else if (type == LIST)
		{
			if (!d) return "";
			res.append("[");
			int l = d->size();
			rep(i, l)
			{
				if (i>0) res.append(",");
				int len = (*d)[intToString(i)].size();
				if (len == 1) res.append("{");
				res.append((*d)[intToString(i)].toString());
				if (len == 1) res.append("}");
			}
			res.append("]");
		}
		else if (type == MAP)
		{
			if (!d) return "";
			int l = d->size();
			if (l>1) res.append("{");
			map<string, Json>::iterator it = d->begin();
			for (;it!=d->end();it++)
			{
				if (it != d->begin()) res.append(",");
				res.append("\"");
				res.append(it->first);
				res.append("\":");
				res.append(it->second.toString());
			}
			if (l>1) res.append("}");
		}
		return res;
	}
}gameLog;

//计时器
class PlayerTimer
{
	int counter;
	int startTime;
	public:
	PlayerTimer(int total):counter(total)
	{
	}
	void start()
	{
		startTime=clock();
	}
	void finish()
	{
		//cerr<<clock()-startTime<<"!!!"<<endl;
		counter-=max<int>(clock()-startTime,1);
	}
	bool tle()
	{
		rtn counter<0;
	}
};

//管道通信
class PlayerIO
{
	const str cmd;
	FILE* out;
	FILE* outBackup;//和out中写入的内容一样但是是存在文件中的
	FILE* in;
	deque<char> buffer;
	int getNextInt;
	char getNextChar;
	public:
	PlayerIO(const str& cmd)
	:cmd(cmd)
	{
		remove((cmd+".out").c_str());//删除.out
		remove((cmd+".in").c_str());//删除.in
		out = popen((cmd+" > "+cmd+".out").c_str(),"w");
		outBackup = fopen((cmd+".in").c_str(),"w");
		in = 0;
		whl(!in) in=fopen((cmd+".out").c_str(),"r");
	}
	~PlayerIO()
	{
		close();
	}
	char getc(PlayerTimer& timer)
	{
		if (isClosed()) rtn -1;
		char c=-1;
		if (!sz(buffer))
		{
			timer.start();
			whl((c=fgetc(in))==-1)
			{
				if (cmd=="2") cerr<<("here")<<endl;
				//fseek(in, ftell(in), SEEK_SET);
				timer.finish();
				if (timer.tle()) break;
				timer.start();
			}
			timer.finish();
			if (c!=-1) buffer.push_front(c);
		}
		if (sz(buffer))
		{
			c=buffer.front();
			buffer.pop_front();
		}
		rtn c;
	}
	void ungetc(char c)
	{
		if (c!=-1) buffer.push_front(c);
	}
	bool hasNextChar(PlayerTimer& timer)
	{
		if (isClosed()) rtn false;
		getNextChar=getc(timer);
		rtn getNextChar!=-1;
	}
	char nextChar()
	{
		rtn getNextChar;
	}
	bool hasNextInt(PlayerTimer& timer)
	{
		if (isClosed()) rtn false;
		bool hasDigit=false;
		int sign=+1;
		lli value=0;
		char c=getc(timer);
		if (isdigit(c))
			value=c-'0',hasDigit=true;
		else if (c=='-')
			sign=-1;
		else if (c!='+')
		{
			ungetc(c);
			rtn false;
		}
		vec<char> s;
		s.pb(c);
		whl((c=getc(timer))!=-1)
		{
			s.pb(c);
			if (isdigit(c)) value=value*10+c-'0';
			else if (hasDigit)
			{
				ungetc(c);
				getNextInt=sign*value;
				rtn true;
			}
			else break;
			hasDigit=true;
		}
		whl(sz(s)) ungetc(s.back()),s.pop_back();
		rtn false;
	}
	int nextInt()
	{
		if (cmd=="1") cerr<<":::"<<getNextInt<<endl;
		rtn getNextInt;
	}
	void putInt(int x)
	{
		if (!isClosed())
		{
			if (cmd=="1") cerr<<"!!!"<<x<<endl;
			if (out) fprintf(out,"%d",x);
			if (outBackup) fprintf(outBackup,"%d",x);
		}
	};
	void putChar(char x)
	{
		if (!isClosed())
		{
			if (out) fprintf(out,"%c",x);
			if (outBackup) fprintf(outBackup,"%c",x);
		}
	}
	void flush()
	{
		if (!isClosed())
		{
			fflush(out);
			fflush(outBackup);
		}
	}
	void close()
	{
		if (in)
		{
			fclose(in);
			in=0;
		}
		if (outBackup)
		{
			fclose(outBackup);
			outBackup=0;
		}
		if (out)
		{
			cerr<<"terminate"<<cmd<<endl;
			system(("killall "+getName()).c_str());
			pclose(out);
			cerr<<"here!!"<<endl;
			out=0;
		}
	}
	bool isClosed()
	{
		rtn !out;
	}
	str getName()
	{
		str name = cmd;
		int pos = name.rfind("/");
		if (pos != -1) name = name.erase(0, pos+1);
		rtn name;
	}
};

//操作
struct PlayerAction
{
	vec<pr<pii,int> > distribute;
	vec<pr<pr<pii,pii>,int> > attack;
};

//玩家
class Player
{
	PlayerIO io;
	FILE* config;
public:
	Player(const str& cmd,const str& cfg):io(cmd),config(fopen(cfg.c_str(),"r"))
	{
	}
	~Player()
	{
		if (config) fclose(config);
	}
	void setPlayer(int playerNum)
	{
		gameLog["users"][playerNum-1]["name"] = (Json)io.getName();
		int height,width;
		fscanf(config,"%d%d",&height,&width);
		io.putInt(height);
		io.putChar(' ');
		io.putInt(width);
		io.putChar('\n');
		rep(i,height)
			rep(j,width)
			{
				int terrain;
				fscanf(config,"%d",&terrain);
				io.putInt(terrain);
				io.putChar(j+1==width?'\n':' ');
			}
		rep(i,height)
			rep(j,width)
			{
				int bonus;
				fscanf(config,"%d",&bonus);
				io.putInt(bonus);
				io.putChar(j+1==width?'\n':' ');
			}
		rep(i,height)
			rep(j,width)
			{
				int owner;
				fscanf(config,"%d",&owner);
				io.putInt(owner);
				io.putChar(j+1==width?'\n':' ');
			}
		int attackFactor;
		fscanf(config,"%d",&attackFactor);
		io.putInt(playerNum);
		io.putChar(' ');
		io.putInt(attackFactor);
		io.putChar('\n');
		io.flush();
	}

	PlayerAction getAction()
	{
		PlayerTimer timer(CLOCKS_PER_SEC*TIME_LIMIT);
		PlayerAction action;
		if (!isTerminated())
		{
			lp
			{
				int type;
				if (io.hasNextInt(timer)) type=io.nextInt();
				else
				{
					terminate();
					rtn PlayerAction();
				}
				if (type==-1)
				{
					if (io.hasNextChar(timer))
					{
						if (io.nextChar()!='\n')
						{
							terminate();
							rtn PlayerAction();
						}
					}
					else
					{
						terminate();
						rtn PlayerAction();
					}
					break;
				}
				else if (type==1)
				{
					int x,y,number;
					if (io.hasNextChar(timer))
					{
						if (io.nextChar()!=' ')
						{
							terminate();
							rtn PlayerAction();
						}
					}
					if (io.hasNextInt(timer)) x=io.nextInt();
					else
					{
						terminate();
						rtn PlayerAction();
					}
					if (io.hasNextChar(timer))
					{
						if (io.nextChar()!=' ')
						{
							terminate();
							rtn PlayerAction();
						}
					}
					if (io.hasNextInt(timer)) y=io.nextInt();
					else
					{
						terminate();
						rtn PlayerAction();
					}
					if (io.hasNextChar(timer))
					{
						if (io.nextChar()!=' ')
						{
							terminate();
							rtn PlayerAction();
						}
					}
					if (io.hasNextInt(timer)) number=io.nextInt();
					else
					{
						terminate();
						rtn PlayerAction();
					}
					if (io.hasNextChar(timer))
					{
						if (io.nextChar()!='\n')
						{
							terminate();
							rtn PlayerAction();
						}
					}
					action.distribute.pb(mp(mp(x,y),number));
				}
				else if (type==2)
				{
					int x1,y1,x2,y2,number;
					if (io.hasNextChar(timer))
					{
						if (io.nextChar()!=' ')
						{
							terminate();
							rtn PlayerAction();
						}
					}
					if (io.hasNextInt(timer)) x1=io.nextInt();
					else
					{
						terminate();
						rtn PlayerAction();
					}
					if (io.hasNextChar(timer))
					{
						if (io.nextChar()!=' ')
						{
							terminate();
							rtn PlayerAction();
						}
					}
					if (io.hasNextInt(timer)) y1=io.nextInt();
					else
					{
						terminate();
						rtn PlayerAction();
					}
					if (io.hasNextChar(timer))
					{
						if (io.nextChar()!=' ')
						{
							terminate();
							rtn PlayerAction();
						}
					}
					if (io.hasNextInt(timer)) x2=io.nextInt();
					else
					{
						terminate();
						rtn PlayerAction();
					}
					if (io.hasNextChar(timer))
					{
						if (io.nextChar()!=' ')
						{
							terminate();
							rtn PlayerAction();
						}
					}
					if (io.hasNextInt(timer)) y2=io.nextInt();
					else
					{
						terminate();
						rtn PlayerAction();
					}
					if (io.hasNextChar(timer))
					{
						if (io.nextChar()!=' ')
						{
							terminate();
							rtn PlayerAction();
						}
					}
					if (io.hasNextInt(timer)) number=io.nextInt();
					else
					{
						terminate();
						rtn PlayerAction();
					}
					if (io.hasNextChar(timer))
					{
						if (io.nextChar()!='\n')
						{
							terminate();
							rtn PlayerAction();
						}
					}
					action.attack.pb(mp(mp(mp(x1,y1),mp(x2,y2)),number));
				}
				else
				{
					terminate();
					rtn PlayerAction();
				}
			}
		}
		rtn action;
	}
	void putAction(const PlayerAction& action)
	{
		rep(i,sz(action.distribute))
		{
			io.putInt(1);
			io.putChar(' ');
			io.putInt(action.distribute[i].x.x);
			io.putChar(' ');
			io.putInt(action.distribute[i].x.y);
			io.putChar(' ');
			io.putInt(action.distribute[i].y);
			io.putChar('\n');
		}
		rep(i,sz(action.attack))
		{
			io.putInt(2);
			io.putChar(' ');
			io.putInt(action.attack[i].x.x.x);
			io.putChar(' ');
			io.putInt(action.attack[i].x.x.y);
			io.putChar(' ');
			io.putInt(action.attack[i].x.y.x);
			io.putChar(' ');
			io.putInt(action.attack[i].x.y.y);
			io.putChar(' ');
			io.putInt(action.attack[i].y);
			io.putChar('\n');
		}
		io.putInt(-1);
		io.putChar('\n');
		io.flush();
	}
	void terminate()
	{
		io.close();
	}
	bool isTerminated()
	{
		rtn io.isClosed();
	}
};

//游戏状态
class GameState
{
	struct Info
	{
		int terrain;//0为土地，1为山地
		int bonus;//奖励
		int owner;//0为无归属，1为玩家一，2为玩家二
		int soldierNumber;//驻军数量
	};

	FILE* config;
	int height,width;//地图高和宽
	int attackFactor;//攻击损失系数
	vec<vec<Info> > area;//地图
	int currentPlayerId;//当前玩家id
	int currentRound;//当前回合数
	int soldierNumber;//每回合新出现的士兵
	int operatorLen;

	//计算新兵数量总和
	int getBonus(int playerId)
	{
		int bonus=0;
		rep(i,height)
			rep(j,width)
				if (area[i][j].owner==playerId)
					bonus+=area[i][j].bonus;
		gameLog["rounds"][currentRound-1]["bonus_all"] = (Json)bonus;
		rtn bonus;
	}
	//检查区域是否可用
	bool isAvailable(int x,int y)
	{
		rtn x<height&&y<width&&x>=0&&y>=0&&area[x][y].terrain==0;
	}
	//检查区域是否相邻
	bool isAdjacentTo(int x1,int y1,int x2,int y2)
	{
		rep(d,4)
			if (x1+dx[d]==x2&&y1+dy[d]==y2)
				rtn true;
		rtn false;
	}
	//放置士兵
	str distribute(int playerId,int x,int y,int number)
	{
		gameLog["rounds"][currentRound-1]["operators"][operatorLen]["operator"] = (Json)"add";
		gameLog["rounds"][currentRound-1]["operators"][operatorLen]["to"]["x"] = (Json)x;
		gameLog["rounds"][currentRound-1]["operators"][operatorLen]["to"]["y"] = (Json)y;
		gameLog["rounds"][currentRound-1]["operators"][operatorLen]["num"] = (Json)number;
		operatorLen++;
		if (!isAvailable(x,y)) rtn "Not a free area.";
		if (area[x][y].owner!=playerId) rtn "Belong of area not right.";
		soldierNumber-=number;
		if (soldierNumber<0) rtn "Do not have enough soldier.";
		area[x][y].soldierNumber+=number;
		rtn "OK";
	}
	//进行攻击
	str attack(int playerId,int x1,int y1,int x2,int y2,int number)
	{
		gameLog["rounds"][currentRound-1]["operators"][operatorLen]["operator"] = (Json)"attack";
		gameLog["rounds"][currentRound-1]["operators"][operatorLen]["to"]["x"] = (Json)x2;
		gameLog["rounds"][currentRound-1]["operators"][operatorLen]["to"]["y"] = (Json)y2;
		gameLog["rounds"][currentRound-1]["operators"][operatorLen]["from"]["x"] = (Json)x1;
		gameLog["rounds"][currentRound-1]["operators"][operatorLen]["from"]["y"] = (Json)y1;
		gameLog["rounds"][currentRound-1]["operators"][operatorLen]["num"] = (Json)number;
		operatorLen++;
		if (!isAvailable(x1,y1)||!isAvailable(x2,y2)) rtn "Not a free area.";
		if (area[x1][y1].owner!=playerId||area[x2][y2].owner==playerId) rtn "Belong of area not right.";
		if (!isAdjacentTo(x1,y1,x2,y2)) rtn "Info not near.";
		if (area[x1][y1].soldierNumber<number) rtn "Do not have enough soldier.";
		operatorLen--;

		int A=number;
		int B=area[x2][y2].soldierNumber;
		int K=attackFactor;
		int C=(int)(K*B/10+1);
		if (A>C)
		{
			gameLog["rounds"][currentRound-1]["operators"][operatorLen]["result"] = (Json)"win";
			gameLog["rounds"][currentRound-1]["operators"][operatorLen]["cost"] = (Json)C;
			area[x2][y2].owner=playerId;
			area[x2][y2].soldierNumber=A-C;
			area[x1][y1].soldierNumber-=A;
		}
		else
		{
			int D=(int)((A-1)*10/K);
			gameLog["rounds"][currentRound-1]["operators"][operatorLen]["result"] = (Json)"lose";
			gameLog["rounds"][currentRound-1]["operators"][operatorLen]["cost"] = (Json)D;
			area[x2][y2].soldierNumber-=D;
			area[x1][y1].soldierNumber-=A;
		}
		operatorLen++;
		rtn "OK";
	}
public:
	GameState(const str& cfg):config(fopen(cfg.c_str(),"r"))
	{
	}
	~GameState()
	{
		if (config) fclose(config);
	}
	//初始化地图信息和局面信息
	void initialize()
	{
		fscanf(config,"%d%d",&height,&width);
		gameLog["height"] = (Json)height;
		gameLog["width"] = (Json)width;
		area=vec<vec<Info> >(height,vec<Info>(width));
		rep(i,height)
			rep(j,width)
				fscanf(config,"%d",&area[i][j].terrain);
		rep(i,height)
			rep(j,width)
				fscanf(config,"%d",&area[i][j].bonus);
		rep(i,height)
			rep(j,width)
				fscanf(config,"%d",&area[i][j].owner);
		rep(i,height)
			rep(j,width)
				area[i][j].soldierNumber=0;
		rep(i,height)
			rep(j,width)
			{
				gameLog["map"][i][j]["terrain"] = (Json)area[i][j].terrain;
				gameLog["map"][i][j]["bonus"] = (Json)area[i][j].bonus;
				gameLog["map"][i][j]["belong"] = (Json)area[i][j].owner;
			}
		fscanf(config,"%d",&attackFactor);
		gameLog["factor"] = (Json)attackFactor;
		currentPlayerId=1;
		currentRound=1;
	}
	int getCurrentRound()
	{
		gameLog["rounds"][currentRound-1]["round_num"] = (Json)(currentRound/2);
		gameLog["rounds"][currentRound-1]["player"] = (Json)currentPlayerId;
		rtn currentRound;
	}
	bool putAction(const PlayerAction& action)
	{
		soldierNumber=getBonus(currentPlayerId);
		rep(i,sz(action.distribute))
			prt(distribute(currentPlayerId,
					action.distribute[i].x.x,
					action.distribute[i].x.y,
					action.distribute[i].y));
		rep(i,sz(action.attack))
			prt(attack(currentPlayerId,
					action.attack[i].x.x.x,
					action.attack[i].x.x.y,
					action.attack[i].x.y.x,
					action.attack[i].x.y.y,
					action.attack[i].y));
		gameLog["rounds"][currentRound-1]["operators"][operatorLen]["operator"] = (Json)"end";

		cerr<<currentPlayerId<<"'s round is ended"<<endl;
		currentPlayerId=3-currentPlayerId;
		currentRound++;
		operatorLen = 0;
		return true;
	}

	void winner(int playerNum)
	{
		gameLog["result"]["winner"] = gameLog["users"][playerNum-1]["name"];
		vi cnt(3);
		rep(i,height)
			rep(j,width)
				cnt[area[i][j].owner]++;
		gameLog["result"]["area_num"][0] = cnt[1];
		gameLog["result"]["area_num"][1] = cnt[0];
	}

	bool isFinished()
	{
		if (currentRound>MAX_ROUND) rtn true;
		vb s(3);
		rep(i,height)
			rep(j,width)
				s[area[i][j].owner]=true;
		int cnt=0;
		ft(i,1,2) if (s[i]) cnt++;
		if (cnt==1) {
			if (s[1]) winner(1);
			else if (s[2]) winner(2);
		}
		rtn cnt==1;
	}
};

//游戏
class Game
{
	Player firstPlayer,secondPlayer;
	GameState state;
	FILE* json;
public:
	Game(const str& cfg,const str& fpcmd,const str& spcmd,const str& json):firstPlayer(fpcmd,cfg),secondPlayer(spcmd,cfg),state(cfg),json(fopen(json.c_str(),"w"))
	{
	}
	~Game()
	{
		if (json) fclose(json);
	}
	void play()
	{
		state.initialize();
		firstPlayer.setPlayer(1);
		secondPlayer.setPlayer(2);
		do
		{
			if (state.getCurrentRound()%2==1)
			{
				PlayerAction action=firstPlayer.getAction();
				if (!state.putAction(action)) firstPlayer.terminate();
				secondPlayer.putAction(action);
			}
			else
			{
				PlayerAction action=secondPlayer.getAction();
				if (!state.putAction(action)) secondPlayer.terminate();
				firstPlayer.putAction(action);
			}
			if (firstPlayer.isTerminated()&&secondPlayer.isTerminated()) break;
		}
		whl(!state.isFinished()&&(!firstPlayer.isTerminated()||!secondPlayer.isTerminated()));
		firstPlayer.terminate();
		secondPlayer.terminate();
		fprintf(json, "%s\n", gameLog.toString().c_str());
	}
};

int main(int argc,char* argv[])
{
	if (argc!=5)
	{
		cout<<"Usage:"<<endl;
		cout<<"judge /path/to/config /path/to/palyer1 /path/to/player2 /path/to/json"<<endl;
	}
	else
	{
		Game game(argv[1],argv[2],argv[3],argv[4]);
		game.play();
	}
}
