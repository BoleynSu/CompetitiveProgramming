/*
ID: sujiao1
PROG: concom
LANG: C++
*/
#include <iostream>
#include <string>
#include <fstream>
using std::endl;
using std::string;
/*
std::istream& cin(std::cin);
std::ostream& cout(std::cot);
*/
std::ifstream cin("concom.in");
std::ofstream cout("concom.out");

struct Program
{
       static const int MAXN=100;//1 to 100
       static const int CONTROL=50;
       int N;
       int control[MAXN+2][MAXN+2];//control[i][j]=how many i controls j if i!=j
                                   //control[i][j] has no meaning if i=j
       bool child[MAXN+2][MAXN+2];//child[i][j] means j is under i's control
       //bool mark[MAXN+2][MAXN+2][MAXN+2];
       Program()
       {
                cin>>N;
                for (int i=1;i<=MAXN;i++)
                    for (int j=1;j<=MAXN;j++)
                    {
                        control[i][j]=0;
                        child[i][j]=(i==j);
                        /*
                        for (int k=1;k<MAXN;k++)
                            mark[i][j][k]=false;
                        */
                    }
                
                for (int i=1;i<=N;i++)
                {
                    int a,b,c;
                    cin>>a>>b>>c;
                    control[a][b]=c;
                }
       }
       /*
       bool addChild(int fh,int ch)
       {
            if (control[fh][ch]>=CONTROL)
            {
               //cout<<"add("<<fh<<","<<ch<<")\n";
               for (int i=1;i<=MAXN;i++)
               {
                   if ((ch!=i)&&(fh!=i)&&(addChild(ch,i)))
                   {
                      for (int j=1;j<=MAXN;j++)
                      {
                          //cout<<"to add("<<ch<<","<<j<<")="<<control[i][j]<<endl;
                          if ((!mark[ch][i][j])&&(ch!=j)&&(i!=j))
                          {
                             control[ch][j]+=control[i][j];
                             mark[ch][i][j]=true;
                          }
                      }
                   }
               }
               return true;
            }
            else return false;
       }
       */
       /*
       bool addChild(int fh,int ch)
       {
            if (control[fh][ch]>=CONTROL)
            {
               //cout<<"add("<<fh<<","<<ch<<")\n";
               for (int i=1;i<=MAXN;i++)
               {
                   if ((ch!=i)&&(fh!=i)&&(addChild(ch,i))&&(!mark[fh][ch][i]))
                   {
                      control[fh][i]+=control[ch][i];
                      mark[fh][ch][i]=true;
                   }
               }
               return true;
            }
            else return false;
       }
       */
       /*
       void deal()
       {
            //0 is the super company
            for (int i=1;i<=MAXN;i++)
                control[0][i]=100;
            
            for (int i=1;i<=MAXN;i++)
                addChild(0,i);
            //for (int i=1;i<=MAXN;i++)
            //    for (int j=1;j<=MAXN;j++)
            //        cout<<"control["<<i<<","<<j<<"]="<<control[i][j]<<endl;
            for (int i=1;i<=MAXN;i++)
                for (int j=1;j<=MAXN;j++)
                if (control[i][j]>=CONTROL)
                {
                   cout<<i<<" "<<j<<endl;
                }
       }
       */
       int run()
       {
           bool finish=false;
           while (!finish)
           {
                 finish=true;
                 for (int i=1;i<=MAXN;i++)
                     for (int j=1;j<=MAXN;j++)
                         if (!child[i][j])
                         {
                            int total=control[i][j];
                            for (int k=1;k<=MAXN;k++)
                            {
                                if ((child[i][k])&&(i!=k)&&(j!=k))
                                   total+=control[k][j];
                            }
                            if (total>=CONTROL)
                            {
                               child[i][j]=true;
                               //cout<<i<<" "<<j<<" "<<total<<endl;
                               finish=false;
                            }
                         }
           }
           for (int i=1;i<=MAXN;i++)
               for (int j=1;j<=MAXN;j++)
                   if ((i!=j)&&child[i][j])
                      cout<<i<<" "<<j<<endl;
           //deal();
           //cout<<clock()<<endl;
           return 0;
       }
};

//#include <time.h>
int main()
{
    //cout<<clock()<<endl;
    Program app;
    return app.run();
}
