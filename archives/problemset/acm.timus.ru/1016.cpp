/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-3-16
DESCRIPTION:
$DESCRIPTION
*/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <sstream>
using std::stringstream;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <stack>
using std::stack;
#include <queue>
using std::queue;
#include <map>
using std::map;
using std::pair;
using std::make_pair;
#include <algorithm>
using std::sort;
#include <cassert>
//using std::assert;

struct Cube
{
       int left,right,top,forward,bottom,backward;
       inline
       void swap(int& a,int& b,int& c,int& d)
       {
            int s=a;
            a=b;
            b=c;
            c=d;
            d=s;
       }
       inline
       void goup()
       {
            swap(bottom,backward,top,forward);
       }
       inline
       void godown()
       {
            swap(bottom,forward,top,backward);
       }
       inline
       void goright()
       {
            swap(bottom,right,top,left);
       }
       inline
       void goleft()
       {
            swap(bottom,left,top,right);
       }
};
struct Compare
{
       bool operator()(const pair<pair<Cube,pair<int,int> >,int>& a,
                       const pair<pair<Cube,pair<int,int> >,int>& b)
       {
            return a.second>b.second;
       }
};

class Application
{
      static const int SIDE=6;
      static const int top=0,
                       bottom=SIDE-1-top,
                       left=1,
                       right=SIDE-1-left,
                       forward=2,
                       backward=SIDE-1-forward;
      static const int SIZE=8;
      static const int ID=24;
      static const int oo=1<<29;
      pair<int,int> f,t;
      vector<int> get_point;
      vector<vector<int> > get_id;
      public:
      Application()
                   :get_point(SIDE),get_id(SIDE,vector<int>(SIDE))
      {
                    char x,y;
                    cin>>x>>y;
                    f.first=x-'a';
                    f.second=y-'1';
                    cin>>x>>y;
                    t.first=x-'a';
                    t.second=y-'1';
                    //forward, backward, top, right, bottom and left 
                    cin>>get_point[forward]
                       >>get_point[backward]
                       >>get_point[top]
                       >>get_point[right]
                       >>get_point[bottom]
                       >>get_point[left];
      }
      int run()
      {
          //init get_id
          for (int i=0,id=0;i<SIDE;i++)
              for (int j=0;j<SIDE;j++)
                  if ((j!=i)&&(j+i+1!=SIDE))
                     get_id[i][j]=id++;
          
          //dijkstra
          typedef pair<pair<int,int>,int> pre_type;
          vector<vector<vector<int> > >
          dist(SIZE,vector<vector<int> >(SIZE,vector<int>(ID,oo)));
          vector<vector<vector<pre_type> > >
          pre(SIZE,vector<vector<pre_type> >(SIZE,vector<pre_type>(ID)));
          
          std::priority_queue<pair<pair<Cube,pair<int,int> >,int>,
                              vector<pair<pair<Cube,pair<int,int> >,int> >,
                              Compare> q;
          //push start state
          Cube start;
          start.top=top;
          start.bottom=bottom;
          start.left=left;
          start.right=right;
          start.forward=forward;
          start.backward=backward;
          q.push(make_pair(make_pair(start,f),get_point[start.bottom]));
          
          while (!q.empty())
          {
                pair<pair<Cube,pair<int,int> >,int> now=q.top();
                #define getdist(who) (dist[who.first.second.first]\
                                          [who.first.second.second]\
                                          [get_id[who.first.first.top]\
                                                 [who.first.first.left]]\
                                     )
                
                if (getdist(now)==oo)
                {
                   getdist(now)=now.second;
                   #define assignpre(dir,dx,dy)\
                   from.first.first=now.first.first;\
                   from.first.first.go##dir();\
                   from.first.second=make_pair(now.first.second.first+(dx),\
                                               now.first.second.second+(dy));\
                   if ((from.first.second.first>=0)\
                       &&(from.first.second.first<SIZE)\
                       &&(from.first.second.second>=0)\
                       &&(from.first.second.second<SIZE)\
                       &&(getdist(from)+get_point[now.first.first.bottom]==now.second))\
                   {\
                       pre[now.first.second.first]\
                          [now.first.second.second]\
                          [get_id[now.first.first.top]\
                                 [now.first.first.left]]\
                       =make_pair(from.first.second,\
                                  get_id[from.first.first.top]\
                                        [from.first.first.left]\
                                 );\
                   }
                   pair<pair<Cube,pair<int,int> >,int> from;
                   assignpre(left,-1,0);
                   assignpre(right,1,0);
                   assignpre(up,0,1);
                   assignpre(down,0,-1);                   
                   #undef assignpre
                   
                   #define letusgo(dir,dx,dy)\
                   go.first.first=now.first.first;\
                   go.first.first.go##dir();\
                   go.first.second=make_pair(now.first.second.first+(dx),\
                                             now.first.second.second+(dy));\
                   if ((go.first.second.first>=0)\
                       &&(go.first.second.first<SIZE)\
                       &&(go.first.second.second>=0)\
                       &&(go.first.second.second<SIZE)\
                       &&(getdist(go)==oo))\
                   {\
                      go.second=now.second+get_point[go.first.first.bottom];\
                      q.push(go);\
                   }
                   pair<pair<Cube,pair<int,int> >,int> go;
                   letusgo(left,-1,0);
                   letusgo(right,1,0);
                   letusgo(up,0,1);
                   letusgo(down,0,-1);
                   #undef letusgo
                }
                if (now.first.second==t) break;
                q.pop();
                #undef getdist
          }
          stack<pre_type> s;
          s.push(make_pair(q.top().first.second,
                           get_id[q.top().first.first.top]
                                 [q.top().first.first.left]));
          for (pre_type from=make_pair(f,get_id[start.top][start.left]);
               s.top()!=from;)
          {
              pre_type getpre=pre[s.top().first.first]
                        [s.top().first.second]
                        [s.top().second];
              s.push(getpre);
          }
          cout<<q.top().second<<" ";
          while (!s.empty())
          {
                cout<<char(s.top().first.first+'a')
                    <<char(s.top().first.second+'1');
                s.pop();
                if (s.empty()) cout<<endl;
                else cout<<" ";
          }
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
