/*
ID: sujiao1
PROG: lamps
LANG: C++
*/
#include <iostream>
#include <fstream>
using std::endl;
/*
std::istream& cin(std::cin);
std::ostream& cout(std::cout);
*/
std::ifstream cin("lamps.in");
std::ofstream cout("lamps.out");

struct Program
{
       static const int MAXN=100;//1 to 100
       static const int MAXC=10000;//0 to 10000
       static const int MAXSTATE=2*2*2*2; 
       typedef bool state[MAXN+2];
       int N,C;
       state on,off;
       int answerl;
       state answer[MAXSTATE+2];
       Program():answerl(0)
       {
                cin>>N>>C;
                for (int i=1;i<=N;i++)
                    on[i]=off[i]=false;
                int get;
                cin>>get;
                while (get!=-1)
                {
                      on[get]=true;
                      cin>>get;
                }
                cin>>get;
                while (get!=-1)
                {
                      off[get]=true;
                      cin>>get;
                }
       }
       void dfs(state now,int c,int depth,bool push1=false,
                                          bool push2=false,
                                          bool push3=false,
                                          bool push4=false)
       {
            switch (depth)
            {
                   //Button 1: When this button is pressed,
                   //all the lamps change their state: 
                   //those that are ON are turned OFF and 
                   //those that are OFF are turned ON. 
                   case 1:
                   {
                        dfs(now,c,depth+1,false,push2,push3,push4);
                        for (int i=1;i<=N;i++)
                            now[i]=!now[i];
                        dfs(now,c+1,depth+1,true,push2,push3,push4);
                        for (int i=1;i<=N;i++)
                            now[i]=!now[i];
                   }
                   break;
                   //Button 2: Changes the state of all the odd numbered lamps. 
                   case 2:
                   {
                        dfs(now,c,depth+1,push1,false,push3,push4);
                        for (int i=1;i<=N;i++)
                            if (i%2==1)
                               now[i]=!now[i];
                        dfs(now,c+1,depth+1,push1,true,push3,push4);
                        for (int i=1;i<=N;i++)
                            if (i%2==1)
                               now[i]=!now[i];
                   }
                   break;
                   //Button 3: Changes the state of all the even numbered lamps. 
                   case 3:
                   {
                        dfs(now,c,depth+1,push1,push2,false,push4);
                        for (int i=1;i<=N;i++)
                            if (i%2==0)
                               now[i]=!now[i];
                        dfs(now,c+1,depth+1,push1,push2,true,push4);
                        for (int i=1;i<=N;i++)
                            if (i%2==0)
                               now[i]=!now[i];
                   }
                   break;
                   //Button 4: Changes the state of the lamps whose number 
                   //is of the form 3xK+1 (with K>=0), i.e., 1,4,7,... 
                   case 4:
                   {
                        dfs(now,c,depth+1,push1,push2,push3,false);
                        for (int i=1;i<=N;i++)
                            if (i%3==1)
                               now[i]=!now[i];
                        dfs(now,c+1,depth+1,push1,push2,push3,true);
                        for (int i=1;i<=N;i++)
                            if (i%3==1)
                               now[i]=!now[i];
                   }
                   break;
                   case 5:
                   {
                        //1-2-3 = no operate
                        //1-1 = no operate
                        bool is=true;
                        for (int i=1;i<=N;i++)
                        {
                            if (on[i]&&(!now[i])) is=false;
                            if (off[i]&&now[i]) is=false;
                        }
                        if (is)
                        {
                           if (push1+push2+push3+push4>C) is=false;
                           else
                           {
                               is=false;
                               if ((C-(push1+push2+push3+push4))%2==0) is=true;
                               if ((C-(push1+push2+push3+push4))%3==0) is=true;
                           }
                        }
                        if (is)
                        {
                           answerl++;
                           for (int i=1;i<=N;i++)
                               answer[answerl][i]=now[i];
                        }
                   }
            }
       }
       void sort()
       {
            for (int i=1;i<answerl;i++)
                for (int j=i+1;j<=answerl;j++)
                {
                    bool same=true;
                    for (int k=1;k<=N;k++)
                        if (answer[i][k]!=answer[j][k]) same=false;
                    if (same)
                    {
                       for (int k=1;k<=N;k++)
                           answer[j][k]=answer[answerl][k];
                       answerl--;
                    }                    
                }
            for (int i=1;i<answerl;i++)
                for (int j=i+1;j<=answerl;j++)
                {
                    bool change=false;
                    for (int k=1;k<=N;k++)
                    {
                        if (answer[i][k]>answer[j][k])
                        {
                           change=true;
                           break;
                        }
                        if (answer[i][k]<answer[j][k])
                        {
                           change=false;
                           break;
                        }
                    }
                    if (change)
                    {
                       for (int k=1;k<=N;k++)
                       {
                           int swap=answer[i][k];
                           answer[i][k]=answer[j][k];
                           answer[j][k]=swap;
                       }
                    }
                }
       }
       int run()
       {
           int c=0;
           state now;
           for (int i=1;i<=N;i++)
               now[i]=true;
           dfs(now,c,1);
           sort();
           for (int i=1;i<=answerl;i++)
           {
               for (int j=1;j<=N;j++)
                   cout<<answer[i][j];
               cout<<endl;
           }
           if (answerl==0) cout<<"IMPOSSIBLE"<<endl;
           return 0;
       }
};

//#include <time.h>
int main()
{
    //cout<<clock()<<endl;
    Program app;
    return app.run();
    //cout<<clock()<<endl;
}
