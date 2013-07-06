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

//2013-6-30 20:53
#include <stdio.h>
#include <stdlib.h>

struct Area {
    int terrain; //0为土地，1为山地
    int bonus; //土地bonus值
    int belong; //0为无归属，1为玩家一，2为玩家2
    int soldier_num; //该土地上目前的士兵数目
    double value;
    int need;
};

int height, width; //地图高和宽
int my_player_id; //我的玩家编号
int attack_factor; //攻击损失系数
int currentRound; //当前回合数
Area area[6][8]; //地图

int soldier_num; //每回合新出现的士兵

//初始化地图信息和局面信息
void init() {

    //读取地形数据,坐标从(0,0)开始
    scanf("%d%d", &height, &width);
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            scanf("%d", &area[i][j].terrain);
        }
    }
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            scanf("%d", &area[i][j].bonus);
        }
    }
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            scanf("%d", &area[i][j].belong);
        }
    }

    //初始化复制
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            area[i][j].soldier_num = 0;
        }
    }
    currentRound = 0;

    scanf("%d%d", &my_player_id, &attack_factor);
}

//计算bonus总和
int get_bonus(int player_id) {
    int bonus = 0;
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            if (area[i][j].belong == player_id) {
                bonus += area[i][j].bonus;
            }
        }
    }
    return bonus;
}

//检查一区域是否可用
bool check_area(int x, int y) {
    return (x<height && y<width && x>=0 && y>=0 && area[x][y].terrain==0);
}

//检查两区域是否相邻（参数为两区域坐标）
bool check_near(int x1, int y1, int x2, int y2) {
    int dx[]={0, 1, 0, -1};
    int dy[]={1, 0, -1, 0};
    for (int d=0; d<4; d++) {
        if (x1 + dx[d] == x2 && y1 + dy[d] == y2) return true;
    }
    return false;
}

//检查游戏是否结束
bool check_end() {
    if (currentRound > 300) return true;

    //检查是否所有可用土地属于同一个玩家
    int player_id = -1;
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            if (area[i][j].terrain == 0) {
                if (player_id == -1) player_id = area[i][j].belong;
                else if (area[i][j].belong != player_id) return false;
            }
        }
    }

    return true;
}

//放置士兵
void set_soldier(int player_id, int x, int y, int number) {
    area[x][y].soldier_num += number;

    //自己的决策需要打印出来
    if (player_id == my_player_id) {
        soldier_num -= number;
        printf("1 %d %d %d\n", x, y, number);
    }
}

//进行攻击
void attack(int player_id, int x1, int y1, int x2, int y2, int number) {
    int A = number;
    int B = area[x2][y2].soldier_num;
    int S = area[x2][y2].bonus;
    int K = attack_factor;
    int C = (int)(K*B/10+S);
    if (A > C) { //攻击成功
        area[x2][y2].belong = player_id;
        area[x2][y2].soldier_num = A - C;
        area[x1][y1].soldier_num -= A;
    } else { //攻击失败
        int D = (int)((A-1)*10/K);
        if (D > B) D = B;
        area[x2][y2].soldier_num -= D;
        area[x1][y1].soldier_num -= A;
    }

    //自己的决策需要打印出来
    if (player_id == my_player_id) {
        printf("2 %d %d %d %d %d\n", x1, y1, x2, y2, number);
    }
}

//读取对手的操作，维护地图状态
void read_operator(int player_id) {
    while(true) {
        int type,x,y,x1,y1,x2,y2,number;
        scanf("%d", &type); //读类型
        if (type == -1) break;
        if (type == 1) {
            scanf("%d%d%d", &x, &y, &number);
            set_soldier(player_id, x, y, number); //放置士兵操作
        } else if (type == 2) {
            scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &number);
            attack(player_id, x1, y1, x2, y2, number); //攻击操作
        }
    }
}

const int GO_DIS=5;
const int SAFE_DIS=4;
int d_to_me[6][8],d_to_enemy[6][8];
bool dangerous[6][8];
bool isAttack,isDefend;

bool attacked[6][8];
int need[6][8];
int hold[6][8];

const int MAXSTEP=15;
const int MORE=1;
const int IN_THE_WAY_LIMIT=4;
const db NONEED_FACTOR=0.5;
const db SOLDIER_FACTOR=-19930309;
const db IN_THE_WAY_VALUE=-1e20;
vpii path;
bool atked[6][8];
db bst;
vpii bpath;
int brneed;
int bneed;

map<pii,int> attack_num;
map<pii,vpii> attacked_by;
vec<pr<pii,pii> > attack_list;
int rest;

void calc_value_and_need()
{
	rep(i,height) rep(j,width)
	{
		if (area[i][j].terrain==1)
		{
			area[i][j].need=+oo/2;
		}
		else
		{
			if (area[i][j].belong==my_player_id)
			{
			    int B = area[i][j].soldier_num;
			    int S = area[i][j].bonus;
			    int K = attack_factor;
			    int C = (int)(K*B/10+S);
				area[i][j].need=C;
			}
			else if (area[i][j].belong==3-my_player_id)
			{
			    int B = area[i][j].soldier_num;
			    int S = area[i][j].bonus;
			    int K = attack_factor;
			    int C = (int)(K*B/10+S);
				area[i][j].need=C;
			}
			else
			{
			    int B = area[i][j].soldier_num;
			    int S = area[i][j].bonus;
			    int K = attack_factor;
			    int C = (int)(K*B/10+S);
				area[i][j].need=C;
			}
		}
	}

	queue<pii> q;
	fl(d_to_me,0x0f),fl(d_to_enemy,0x0f);
	rep(i,height) rep(j,width) if (area[i][j].belong==my_player_id)
	{
		q.push(mp(i,j));
		d_to_me[i][j]=0;
	}
	whl(sz(q))
	{
		int i=q.front().x;
		int j=q.front().y;
		q.pop();
		rep(d,4)
		{
			int ni=i+dx[d];
			int nj=j+dy[d];
			if (check_area(ni,nj)&&cmin(d_to_me[ni][nj],d_to_me[i][j]+area[ni][nj].need))
			{
				q.push(mp(ni,nj));
			}
		}
	}
	rep(i,height) rep(j,width) if (area[i][j].belong==3-my_player_id)
	{
		q.push(mp(i,j));
		d_to_enemy[i][j]=0;
	}
	whl(sz(q))
	{
		int i=q.front().x;
		int j=q.front().y;
		q.pop();
		rep(d,4)
		{
			int ni=i+dx[d];
			int nj=j+dy[d];
			if (check_area(ni,nj)&&cmin(d_to_enemy[ni][nj],d_to_enemy[i][j]+area[ni][nj].need))
			{
				q.push(mp(ni,nj));
			}
		}
	}

	int mb=0;
	rep(i,height) rep(j,width) if (area[i][j].belong==my_player_id) cmax(mb,area[i][j].soldier_num);
	mb+=get_bonus(3-my_player_id);
	isAttack=false,isDefend=true;
	rep(i,height) rep(j,width) if (area[i][j].belong==my_player_id&&d_to_enemy[i][j]<=max(GO_DIS,mb/3))
		isAttack=true,isDefend=false;

	clr(dangerous);

	if (isAttack)
	{
		rep(i,height) rep(j,width)
		{
			if (area[i][j].terrain==1)
			{
				area[i][j].value=-oo;
			}
			else
			{
				if (area[i][j].belong==my_player_id)
				{
					area[i][j].value=-oo;
				}
				else if (area[i][j].belong==3-my_player_id)
				{
					area[i][j].value=(area[i][j].soldier_num*SOLDIER_FACTOR)+area[i][j].bonus;
				}
				else
				{
					area[i][j].value=-oo*area[i][j].bonus;
				}
			}
		}
	}

	int eb=get_bonus(3-my_player_id);
	if (isDefend)
	{
		rep(i,height) rep(j,width) if (d_to_enemy[i][j]<=eb-max(GO_DIS,eb/3)&&d_to_me[i][j]>SAFE_DIS)
		{
			dangerous[i][j]=true;
		}
		rep(i,height) rep(j,width)
		{
			if (area[i][j].terrain==1)
			{
				area[i][j].value=-oo;
			}
			else
			{
				if (area[i][j].belong==my_player_id)
				{
					area[i][j].value=-oo;
				}
				else if (area[i][j].belong==3-my_player_id)
				{
					area[i][j].value=-oo*area[i][j].bonus;
				}
				else
				{
					area[i][j].value=area[i][j].bonus;
				}
			}
		}
	}
}

void dfs(int step,int soldier_num,int hold,int need,db value,int i,int j)
{
	if (step==MAXSTEP)
	{
		int cnt=0;
		rep(i,height) rep(j,width) if (attacked[i][j])
		{
			bool itw=true;
			rep(d,4)
			{
				int ni=i+dx[d];
				int nj=j+dy[d];
				if (check_area(ni,nj)&&!attacked[ni][nj])
				{
					itw=false;
				}
			}
			if (itw) cnt-=::hold[i][j];
		}
		rep(i,height) rep(j,width) if (attacked[i][j]||atked[i][j])
		{
			bool itw=true;
			rep(d,4)
			{
				int ni=i+dx[d];
				int nj=j+dy[d];
				if (check_area(ni,nj)&&!(attacked[ni][nj]||atked[ni][nj]))
				{
					itw=false;
				}
			}
			if (itw) cnt+=::hold[i][j];
		}
		db delta=0;
		if (cnt>IN_THE_WAY_LIMIT)
		{
			delta=IN_THE_WAY_VALUE*cnt;
		}
		if (cmax(bst,value/max(db(need+MORE-hold),NONEED_FACTOR)+delta))
		{
			bneed=need+MORE;
			bpath=path;
		}
	}
	else
	{
		bool go=false;
		rep(d,4)
		{
			int ni=i+dx[d];
			int nj=j+dy[d];
			if (check_area(ni,nj)&&!dangerous[ni][nj]&&!attacked[ni][nj]&&!atked[ni][nj]&&max(need+area[ni][nj].need+MORE-hold,0)<=soldier_num)
			{
				go=true;
				path.pb(mp(ni,nj));
				atked[ni][nj]=true;
				dfs(step+1,soldier_num,hold,need+area[ni][nj].need,value+area[ni][nj].value,ni,nj);
				atked[ni][nj]=false;
				path.pop_back();
			}
		}
		if (!go)
		{
			int cnt=0;
			rep(i,height) rep(j,width) if (attacked[i][j])
			{
				bool itw=true;
				rep(d,4)
				{
					int ni=i+dx[d];
					int nj=j+dy[d];
					if (check_area(ni,nj)&&!attacked[ni][nj])
					{
						itw=false;
					}
				}
				if (itw) cnt-=::hold[i][j];
			}
			rep(i,height) rep(j,width) if (attacked[i][j]||atked[i][j])
			{
				bool itw=true;
				rep(d,4)
				{
					int ni=i+dx[d];
					int nj=j+dy[d];
					if (check_area(ni,nj)&&!(attacked[ni][nj]||atked[ni][nj]))
					{
						itw=false;
					}
				}
				if (itw) cnt+=::hold[i][j];
			}
			db delta=0;
			if (cnt>IN_THE_WAY_LIMIT)
			{
				delta=IN_THE_WAY_VALUE*cnt;
			}
			if (cmax(bst,value/max(db(need+MORE-hold),NONEED_FACTOR)+delta))
			{
				bneed=need+MORE;
				bpath=path;
			}
		}
	}
}
void calc_action()
{
    clr(attacked),clr(need),clr(hold);
	rep(i,height) rep(j,width)
		if (area[i][j].belong==my_player_id)
		{
			attacked[i][j]=true;
			need[i][j]=0;
			hold[i][j]=area[i][j].soldier_num;
		}

	rest=get_bonus(my_player_id);
	attack_num.clear();
	attack_list.clear();
	attacked_by.clear();
    for (;;)
    {
    	db best=-inf;
    	pii beststart;
    	vpii bestpath;
    	int bestneed=+oo/2;
    	rep(i,height) rep(j,width) if (attacked[i][j])
		{
    		bst=-inf;
    		dfs(0,rest,hold[i][j],0,0,i,j);
    		if (sz(bpath)&&cmax(best,bst))
    		{
    			beststart=mp(i,j);
    			bestpath=bpath;
    			bestneed=bneed;
    		}
		}
    	if (best==-inf) break;
    	rest-=max(bestneed-hold[beststart.x][beststart.y],0);
    	hold[beststart.x][beststart.y]-=min(hold[beststart.x][beststart.y],bestneed);
    	attacked_by[bestpath.front()].pb(beststart),
    	attack_num[beststart]++,
    	attack_list.pb(mp(beststart,bestpath.front()));
    	attacked[bestpath.front().x][bestpath.front().y]=true;
    	rep(i,sz(bestpath)-1)
    		attacked_by[bestpath[i+1]].pb(bestpath[i]),
    		attack_num[bestpath[i]]++,
    		attack_list.pb(mp(bestpath[i],bestpath[i+1])),
    		attacked[bestpath[i+1].x][bestpath[i+1].y]=true;
    	attack_num[bestpath.back()];
    	rep(i,sz(bestpath)) need[bestpath[i].x][bestpath[i].y]=area[bestpath[i].x][bestpath[i].y].need;
    	hold[bestpath.back().x][bestpath.back().y]=MORE;
    }
}

void do_action()
{
    queue<pii> q;
    feach(i,attack_num)
        if (i->y==0)
        	q.push(i->x);
    pii put=mp(-1,-1);
    rep(i,height) rep(j,width) if (attacked[i][j])
    {
    	if (put==mp(-1,-1)||d_to_enemy[put.x][put.y]>d_to_enemy[i][j])
    		put=mp(i,j);
    }
    prt(put);
    int mind=d_to_enemy[put.x][put.y];
    rep(bi,height) rep(bj,width)
    {
    	//TODO
		bool itw=true;
		rep(d,4)
		{
			int ni=bi+dx[d];
			int nj=bj+dy[d];
			if (check_area(ni,nj)&&!attacked[ni][nj])
			{
				itw=false;
			}
		}
		if (itw) continue;
    	queue<pii> q;
    	fl(d_to_enemy,0x0f);
    	rep(i,height) rep(j,width) if (area[i][j].belong==3-my_player_id)
    	{
    		q.push(mp(i,j));
    		d_to_enemy[i][j]=0;
    	}
    	whl(sz(q))
    	{
    		int i=q.front().x;
    		int j=q.front().y;
    		q.pop();
    		rep(d,4)
    		{
    			int ni=i+dx[d];
    			int nj=j+dy[d];
    			if (check_area(ni,nj)&&!(ni==bi&&nj==bj)&&cmin(d_to_enemy[ni][nj],d_to_enemy[i][j]+area[ni][nj].need))
    			{
    				q.push(mp(ni,nj));
    			}
    		}
    	}
    	int get=+oo;
    	rep(i,height) rep(j,width) if (attacked[i][j])
        {
    		cmin(get,d_to_enemy[i][j]);
        }
    	if (cmin(mind,get)) put=mp(bi,bj);
    }

    need[put.x][put.y]+=rest,rest=0;
    whl(sz(q))
    {
    	pii u=q.front();
    	need[u.x][u.y]+=hold[u.x][u.y];
    	q.pop();
    	feach(i,attacked_by[u])
    	{
    		pii v=*i;
    		need[v.x][v.y]+=need[u.x][u.y];
    		if (--attack_num[v]==0)
    			q.push(v);
    	}
    }
    soldier_num=get_bonus(my_player_id);
    bool fnd=false;
    rep(i,sz(attack_list))
    	if (attack_list[i].x==put||attack_list[i].y==put) fnd=true;
    if (!fnd)
    {
		set_soldier(my_player_id,put.x,put.y,need[put.x][put.y]);
	    rep(i,6) rep(j,8) cerr<<(area[i][j].belong!=my_player_id?"e":"m")<<area[i][j].soldier_num<<char(j==7?'\n':' ');
	    cerr<<endl;
    }
    feach(i,attacked_by)
    		if (sz(i->y)==0&&area[i->x.x][i->x.y].belong==my_player_id)
    		{
    			set_soldier(my_player_id,i->x.x,i->x.y,need[i->x.x][i->x.y]-area[i->x.x][i->x.y].soldier_num);
    		    rep(i,6) rep(j,8) cerr<<(area[i][j].belong!=my_player_id?"e":"m")<<area[i][j].soldier_num<<char(j==7?'\n':' ');
    		    cerr<<endl;
    		}
    rep(i,sz(attack_list))
    {
    	attack(my_player_id,attack_list[i].x.x,attack_list[i].x.y,attack_list[i].y.x,attack_list[i].y.y,need[attack_list[i].y.x][attack_list[i].y.y]);
        rep(i,6) rep(j,8) cerr<<(area[i][j].belong!=my_player_id?"e":"m")<<area[i][j].soldier_num<<char(j==7?'\n':' ');
        cerr<<endl;
    }
    prt(soldier_num);
}

void go()
{
	inf=1e100;
	calc_value_and_need();
	calc_action();
	do_action();
}

int main() {
    init(); //初始化
    int cur_player_id = 1;
    while (!check_end()) { //如果游戏没有结束
        currentRound++;
        if (cur_player_id == my_player_id) {
            //自己行动
            //set_all_soldier(); //进行放置士兵决策
            //do_all_attack(); //进行攻击决策
        	go();
            printf("-1\n");
            fflush(stdout); //注意！此句在每回合输出后必须加，以刷新缓冲区。
        } else {
            //读取对手行动
            read_operator(cur_player_id);
        }
        if (cur_player_id == 1) cur_player_id = 2;
        else cur_player_id = 1; //交换行动者
    }
	return 0;
}
