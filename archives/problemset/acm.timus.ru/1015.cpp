/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-3-15
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

struct Dice
{
       static const int SIDE=6;
       static const int TURN=4; 
       int left,//the number of points on the left side of the die,
           right,//then on the right side,
           top,//on the top,
           forward,//on the forward side,
           bottom,//on the bottom
           backward;//and on the backward side
       int id; 
       void read()
       {
            cin>>left>>right>>top>>forward>>bottom>>backward;
       }
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
       void turnLR()
       {
            swap(top,backward,bottom,forward);
       }
       inline
       void turnTB()
       {
            swap(right,forward,left,backward);
       }
       inline
       void turnFB()
       {
            swap(right,top,left,bottom);
       }
       void getid()
       {
            //let top=1
            for (int i=0;(top!=1)&&(i<TURN);i++)
                turnTB();
            for (int i=0;(top!=1)&&(i<TURN);i++)
                turnLR();
            for (int i=0;(top!=1)&&(i<TURN);i++)
                turnFB();
            //assert(top==1);
            
            //let left min
            int min_left=SIDE;
            for (int i=0;i<TURN;i++)
            {
                turnTB();
                if (min_left>left) min_left=left;
            }
            for (int i=0;(left!=min_left)&&(i<TURN);i++)
                turnTB();
            
            id=((((left)*SIDE+right)*SIDE+forward)*SIDE+bottom)*SIDE+backward;
       }
};

class Application
{
      int N;
      vector<Dice> dice;
      public:
      Application() 
      {
                    cin>>N;
                    dice.resize(N);
                    for (int i=0;i<N;i++)
                        dice[i].read();
      }
      int run()
      {
          map<int,vector<int> > idToIndex;
          map<int,vector<int> >::iterator it;
          for (int i=0;i<N;i++)
          {
              dice[i].getid();
              idToIndex[dice[i].id].push_back(i+1);
          }
          
          cout<<idToIndex.size()<<endl;
          for (int i=0;i<N;i++)
              if ((it=idToIndex.find(dice[i].id))!=idToIndex.end())
              {
                 for (int j=0;j<it->second.size();j++)
                     cout<<it->second[j]<<char((j+1==it->second.size())?'\n':' '); 
                 idToIndex.erase(it);
              }
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
