//cURL
#include <curl/curl.h>
#include <curl/easy.h>

//Boost
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/filesystem.hpp>

using boost::property_tree::ptree;
using boost::property_tree::read_json;
using boost::property_tree::write_json;
using boost::property_tree::read_xml;
using boost::property_tree::write_xml;
using boost::filesystem::exists;

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
#define rrepf(i,a,b) for (int i=(a)-1;i>=(b);--i)
#define rep(i,n) repf(i,0,n)
#define rrep(i,n) rrepf(i,n,0)
#define ft(i,a,b) for (int i=(a);i<=(b);++i)
#define fdt(i,a,b) for (int i=(a);i>=(b);--i)
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

//初始化;
struct Initializer{
#ifndef DEBUG
Initializer(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#else
~Initializer(){runtime();}
#endif
}initializer;

//非标准;
#define for_each(e,s) for (__typeof__((s).begin()) e=(s).begin();e!=(s).end();++e)
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
typedef __gnu_cxx::rope<char> rope;
template<typename key,typename value>class ext_map:public __gnu_pbds::tree<key,value,less<key>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>{};
#define ctz __builtin_ctz
#define clz __builtin_clz
#define bc __builtin_popcount

cstr REQUEST_URL="http://strikingly-interview-test.herokuapp.com/guess/process";
cstr USER_ID="boleyn.su@gmail.com";
cstr LOG_FILE="log.txt";
cstr RESULT_FILE="result.txt";
const int ERROR_LIMIT=20;

size_t write_data(char *data,size_t size,size_t num,string* buffer)
{
    buffer->append(data,size*num);
    return size*num;
}
ptree send(ptree& input)
{
	int error=0;
	lp
	{
		stringstream input_stream;
		write_json(input_stream,input,false);

		string input_string=input_stream.str();

		string output_string;
		CURL *curl=curl_easy_init();
		curl_slist* chunk=0;
		curl_easy_setopt(curl,CURLOPT_URL,REQUEST_URL);
		chunk=curl_slist_append(chunk,"Content-Type:application/json");
		curl_easy_setopt(curl,CURLOPT_HTTPHEADER,chunk);
		curl_easy_setopt(curl,CURLOPT_POST,1);
		curl_easy_setopt(curl,CURLOPT_POSTFIELDS,input_string.c_str());
		curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,write_data);
		curl_easy_setopt(curl,CURLOPT_WRITEDATA,&output_string);
		curl_easy_perform(curl);
		curl_easy_cleanup(curl);
		curl_slist_free_all(chunk);

		ptree output;

		try
		{
			stringstream output_stream(output_string);
			read_json(output_stream,output);
			if (output.get<int>("status")!=200) throw exception();
		}
		catch (exception& e)
		{
			cerr<<"Error:"<<endl;
			cerr<<"Response: "<<output_string<<endl;
			cerr<<endl;
			error++;
			if (error>ERROR_LIMIT) throw runtime_error("ERROR LIMIT EXCEEDED!");
			continue;
		}
		ofstream fout(LOG_FILE,ios_base::out|ios::app);
		time_t timer=time(0);
		fout<<ctime(&timer)
			<<input_string
			<<output_string
			<<endl;
		rtn output;
	}
}

void initiate_game(str& secret,int& number_of_words_to_guess,int& number_of_guess_allowed_for_each_word)
{
	ptree pt;
	pt.put("action","initiateGame");
	pt.put("userId",USER_ID);
	pt=send(pt);
	secret=pt.get<str>("secret");
	cout<<"secret: "<<secret<<endl;
	number_of_words_to_guess=pt.get<int>("data.numberOfWordsToGuess");
	number_of_guess_allowed_for_each_word=pt.get<int>("data.numberOfGuessAllowedForEachWord");
}
str next_word(str& secret)
{
	ptree pt;
	pt.put("action","nextWord");
	pt.put("userId",USER_ID);
	pt.put("secret",secret);
	pt=send(pt);
	rtn pt.get<str>("word");
}
char calculate(str& s,list<char>& c,list<char>& f);
str guess_word(str& secret,str& s,list<char>& c,list<char>& f)
{
	char i=calculate(s,c,f);
	cout<<"guess "<<i<<endl;
	c.ers(find(all(c),i));

	ptree pt;
	pt.put("action","guessWord");
	pt.put("userId",USER_ID);
	pt.put("secret",secret);
	pt.put("guess",i);
	pt=send(pt);

	str ns=pt.get<str>("word");
	if (ns==s) f.pb(i);
	rtn ns;
}
int get_test_results(str& secret)
{
	ptree pt;
	pt.put("action","getTestResults");
	pt.put("userId",USER_ID);
	pt.put("secret",secret);
	pt=send(pt);
	cout<<"numberOfWordsTried: "<<pt.get<str>("data.numberOfWordsTried")<<endl;
	cout<<"numberOfCorrectWords: "<<pt.get<str>("data.numberOfCorrectWords")<<endl;
	cout<<"numberOfWrongGuesses: "<<pt.get<str>("data.numberOfWrongGuesses")<<endl;
	rtn pt.get<int>("data.totalScore");
}
void submit_test_results(str& secret)
{
	ptree pt;
	pt.put("action","submitTestResults");
	pt.put("userId",USER_ID);
	pt.put("secret",secret);
	pt=send(pt);

	stringstream stream;
	write_json(stream,pt);
	cout<<stream.str()<<endl;

	ofstream fout(RESULT_FILE);
	fout<<pt.get<int>("data.totalScore")<<endl
		<<stream.str()<<endl;
}

int main()
{
	int best_score=-oo;
	ifstream fin(RESULT_FILE);
	fin>>best_score;
	lp
	{
		try
		{
			str secret;
			int number_of_words_to_guess,number_of_guess_allowed_for_each_word;
			initiate_game(secret,number_of_words_to_guess,number_of_guess_allowed_for_each_word);
			int score=0;
			bool impossible=false;
			rep(cnt,number_of_words_to_guess)
			{
				cout<<(cnt+1)<<"th round begins:"<<endl;
				str s=next_word(secret);
				list<char> c,f;
				ft(i,'A','Z') c.pb(i);
				rep(i,number_of_guess_allowed_for_each_word)
				{
					str ns=guess_word(secret,s,c,f);
					if (ns!=s) i--;
					else score--;
					s=ns;
					cout<<s<<"-->"<<ns<<endl;
					if (s.find('*')==str::npos) break;
					int highest_possible_score=(number_of_words_to_guess-cnt)*20+score;
					cout<<"Highest possible score:"<<highest_possible_score<<endl;
					if (highest_possible_score<=best_score)
					{
						impossible=true;
						break;
					}
					if (cnt<10&&highest_possible_score<1600-60) throw runtime_error("Impossible to get a higher score!");
					if (cnt<20&&highest_possible_score<1600-120) throw runtime_error("Impossible to get a higher score!");
				}
				if (s.find('*')==str::npos) score+=20;
				else throw runtime_error("Impossible to get a higher score!");
				cout<<"//this round ends"<<endl;
				if (impossible) break;
			}
			if (impossible)
			{
				cout<<"Impossible to get a better score! Why not restart?"<<endl;
			}
			else
			{
				int total_score=get_test_results(secret);
				cout<<"totalScore: "<<total_score<<endl;
				if (cmax(best_score,total_score)) submit_test_results(secret);
			}
		}
		catch(exception& e)
		{
			cerr<<"ERROR: "<<e.what()<<endl;
			continue;
		}
	}
}

//Reference:
//http://www.ibiblio.org/webster/ USED TO GENERATE qcide_dict.txt
//http://zyzzyva.net/wordlists.shtml
//http://www.infochimps.com/datasets/word-list-350000-words

const int MAX_ALPHABET=256;
const int MAX_LENGTH=1024;

bool initialized;
bool accepted[MAX_ALPHABET];
bool forbidden[MAX_ALPHABET];
vs words;
vs words_of_length[MAX_LENGTH];
db frq_of_length[MAX_LENGTH][MAX_ALPHABET];
void add_word(const str& word)
{
	bool fb=false;
	rep(i,sz(word)) if (forbidden[word[i]]) fb=true;
	if (!fb)
	{
		str real_word;
		rep(i,sz(word)) if (accepted[word[i]]) real_word.pb(toupper(word[i]));
		if (sz(real_word)) words.pb(real_word);
	}
}
/* USED TO GENERATE qcide_dict.txt
cstr DATABASE_PATH="./xml_files/";
void dfs(ptree& u)
{
	for_each(it,u)
	{
		ptree& v=it->y;
		if (it->x=="hw") add_word(u.get<str>(it->x));
		dfs(v);
	}
}
void initialize()
{
	initialized=true;
	if (!exists("dict.txt"))
	{
		ft(i,'a','z') accepted[i]=true;
		ft(i,'A','Z') accepted[i]=true;
		ft(i,'0','9') forbidden[i]=true;
		ft(i,'a','z')
		{
			str file_path="gcide_";
			file_path+=i;
			file_path+=".xml";
			ptree pt;
			ifstream fin((DATABASE_PATH+file_path).c_str());
			read_xml(fin,pt);
			dfs(pt);
		}
		uniq(words);
		ofstream fout("dict.txt");
		rep(i,sz(words)) words_of_length[sz(words[i])].pb(words[i]),fout<<words[i]<<endl;
	}
	else
	{
		ifstream fin("dict.txt");
		str line;
		whl(getline(fin,line))
			words_of_length[sz(line)].pb(line);
	}
}
*/
const int DATABASE_NUMBER=4;
cstr DATABASE_PATH[DATABASE_NUMBER]={"gcide_dict.txt","OSPD4.txt","CSW12.txt","word_list_moby_all_moby_words.flat.txt"};
void initialize()
{
	initialized=true;
	if (!exists("dict.txt"))
	{
		ft(i,'a','z') accepted[i]=true;
		ft(i,'A','Z') accepted[i]=true;
		ft(i,'0','9') forbidden[i]=true;
		rep(i,DATABASE_NUMBER)
		{
			ifstream fin(DATABASE_PATH[i]);
			str line;
			whl(getline(fin,line))
			{
				stringstream sin(line);
				str word;
				sin>>word;
				add_word(word);
			}
		}
		uniq(words);
		sort(all(words),[](const str& a,const str& b){rtn sz(a)==sz(b)?a<b:sz(a)<sz(b);});
		ofstream fout("dict.txt");
		rep(i,sz(words)) words_of_length[sz(words[i])].pb(words[i]),fout<<words[i]<<endl;
	}
	else
	{
		ifstream fin("dict.txt");
		str line;
		whl(getline(fin,line))
			words_of_length[sz(line)].pb(line);
	}
	rep(l,MAX_LENGTH) if (sz(words_of_length[l]))
	{
		vs& words=words_of_length[l];
		int cnt[MAX_ALPHABET];
		clr(cnt);
		int ocr[MAX_ALPHABET];
		fl(ocr,-1);
		rep(i,sz(words))
		{
			rep(j,l) ocr[words[i][j]]=i;
			ft(j,'A','Z') if (ocr[j]==i)
				cnt[j]++;
		}
		ft(i,'A','Z') frq_of_length[l][i]=db(cnt[i])/sz(words);
	}
}
bool match(str& t,str& s,bool fail[MAX_ALPHABET],bool success[MAX_ALPHABET])
{
	rep(i,sz(t)) if ((t[i]!='*'&&t[i]!=s[i])||(t[i]=='*'&&success[s[i]])||fail[s[i]]) rtn false;
	rtn true;
}
char calculate(str& s,list<char>& c,list<char>& f)
{
	if (!initialized) initialize();
	bool fail[MAX_ALPHABET],success[MAX_ALPHABET];
	clr(fail),clr(success);
	for_each(it,f) fail[*it]=true;
	rep(i,sz(s)) if (s[i]!='*') success[s[i]]=true;
	int cnt[MAX_ALPHABET];
	clr(cnt);
	int ocr[MAX_ALPHABET];
	fl(ocr,-1);
	vs& words=words_of_length[sz(s)];
	rep(i,sz(words))
		if (match(s,words[i],fail,success))
		{
			rep(j,sz(s))
				if (s[j]=='*')
					ocr[words[i][j]]=i;
			ft(j,'A','Z') if (ocr[j]==i)
				cnt[j]++;
		}
	pr<int,db> maxcnt=mp(0,0.0);
	char ans;
	db* frq=frq_of_length[sz(s)];
	ft(i,'A','Z') if (find(all(c),i)!=c.end()&&cmax(maxcnt,mp(cnt[i],frq[i]))) ans=i;
	rtn ans;
}
