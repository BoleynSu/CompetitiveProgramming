/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-3-9 
DESCRIPTION:
$DESCRIPTION
*/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <cstring>
using std::memset;
#include <string>
using std::string;
#include <vector>
using std::vector;
using std::pair;
using std::make_pair;
#include <map>
using std::map;

class Question
{
      int length;
      int Q;
      map<int,pair<int,bool> > record_l,record_r;
      bool dfs_judge_l(int l,int r,bool isEven)
      {
           map<int,pair<int,bool> >::iterator it;
           if ((it=record_l.find(l))!=record_l.end())
           {
              if (it->second.first==r)
                 return it->second.second==isEven;
              else if (it->second.first>r)
              {
                   //it->first to it->second.first it->second.second
                   record_l[r+1]=make_pair(it->second.first,isEven xor it->second.second);
                   //it->first to r isEven
                   it->second=make_pair(r,isEven);
                   return dfs_judge_r(r+1,record_l[r+1].first,record_l[r+1].second);
              }
              else
              {
                  return dfs_judge_l(it->second.first+1,r,isEven xor it->second.second);
              }
           }
           else
           {
               record_l[l]=make_pair(r,isEven);
               return true;
           }
      }
      bool dfs_judge_r(int l,int r,bool isEven)
      {
           map<int,pair<int,bool> >::iterator it;
           if ((it=record_r.find(r))!=record_r.end())
           {
              if (it->second.first==l)
                 return it->second.second==isEven;
              else if (it->second.first<l)
              {
                   //it->second.first to it->first it->second.second
                   record_r[l-1]=make_pair(it->second.first,isEven xor it->second.second);
                   //l to it->first isEven
                   it->second=make_pair(l,isEven);
                   return dfs_judge_l(record_r[l-1].first,l-1,record_r[l-1].second);
              }
              else
              {
                  return dfs_judge_r(l,it->second.first-1,isEven xor it->second.second);
              }
           }
           else
           {
               record_r[r]=make_pair(l,isEven);
               return true;
           }
      }
      public:
      bool read()
      {
           cin>>length;
           if (length==-1) return false;
           cin>>Q;
           return true;
      }
      void solve()
      {      
           int l,r;
           string answer;
           
           int answerq=1;
           
           for (;answerq<=Q;answerq++)
           {
               cin>>l>>r>>answer;
               if (!dfs_judge_l(l,r,answer=="odd"))  break;
               if (!dfs_judge_r(l,r,answer=="odd"))  break;
           }
           cout<<answerq-1<<endl;
           
           for (;answerq<Q;answerq++)
               cin>>l>>r>>answer;
           record_l.clear();
           record_r.clear();
      }
};

class Application
{
      public:
      int run()
      {
          Question q;
          while (q.read()) q.solve();
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
