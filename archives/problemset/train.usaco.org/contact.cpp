/*
ID: sujiao1
PROG: contact
LANG: C++
*/
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using std::endl;
using std::string;
using std::sqrt;
#include <cassert>
#include <cstdio>
#include <cstring>
using std::memset;

//std::istream& cin(std::cin);
//std::ostream& cout(std::cout);
std::ifstream cin("contact.in");
std::ofstream cout("contact.out");

struct Program
{
       static const int MAXN=50;//1 to 50
       static const int MAXA=12;//1 to 12
       static const int MAXLEN=200000;//1 to 200000
       static const int __EOF__=-1;
       static const int COUNTERSIZE=(1<<(MAXA+1))-1;
       struct Point
       {
              int x,y;
              int print()
              {
                  for (int i=x-1;i>=0;i--)
                      cout<<bool(y&(1<<i));
                  return 0;
              }
       };
       int A,B;
       int N;
       int len;
       int counter[MAXA+2][COUNTERSIZE+2];
       int answer;
       int answerl;
       Point answerList[COUNTERSIZE+2];
       unsigned int code[MAXLEN+2];
       Program():len(0)
       {
                memset(counter,0,sizeof(counter));
                
                cin>>A>>B>>N;
                for (char got=cin.get();got!=__EOF__;got=cin.get())
                {
                    if (got=='0')
                       code[++len]=0;
                    if (got=='1')
                       code[++len]=1;
                }
                //cout<<A<<" "<<B<<" "<<N<<endl;
                //for (int i=1;i<=len;i++) cout<<code[i];cout<<endl;
       }
       
       int printAnswer()
       {
           cout<<answer<<endl;
           for (int j=6,i;(i=j-5)<=answerl;j+=6)
           {
               bool breakout=false;
               for (i=j-5;i<j;i++)
               {
                   counter[answerList[i].x][answerList[i].y]=0;
                   answerList[i].print();
                   if (i==answerl)
                   {
                      breakout=true;
                      break;
                   }
                   cout<<" ";
               }
               if (breakout)
               {
                  cout<<endl;
                  break;
               }
               else if (i<=answerl)
               {
                  counter[answerList[i].x][answerList[i].y]=0;
                  answerList[i].print();
                  cout<<endl;
               }
               else
               {
                   cout<<endl;
                   break;
               }
           }
           return 0;
       }
       
       int run()
       {
           unsigned int value=0;
           if (B>len)
           {
              for (int i=1;i<=len;i++)
              {
                  value=(value<<1)|code[i];
                  for (int k=A;k<=i;k++)
                  {
                      unsigned int cut=~((~0)<<k);
                      //for (int j=cut;j>=0;j--)
                            //if ((value&cut)==j) counter[k][j]++;
                      counter[k][value&cut]++;
                  }
              }
           }
           else //if (B<=len)
           {
                for (int i=1;i<B;i++)
                {
                    value=(value<<1)|code[i];
                    for (int k=A;k<=i;k++)
                    {
                        unsigned int cut=~((~0)<<k);
                        //for (int j=cut;j>=0;j--)
                              //if ((value&cut)==j) counter[k][j]++;
                        counter[k][value&cut]++;
                    }
                }
                for (int i=B;i<=len;i++)
                {
                    value=(value<<1)|code[i];
                    for (int k=A;k<=B;k++)
                    {
                        unsigned int cut=~((~0)<<k);
                        //for (int j=cut;j>=0;j--)
                              //if ((value&cut)==j) counter[k][j]++;
                        counter[k][value&cut]++;
                    }
                }
           }
           /*
           for (int i=A;i<=B;i++)
               for (int j=0;j<(1<<i);j++)
                   cout<<"f["<<i<<","<<j<<"]="<<counter[i][j]<<endl;
           */
           for (int n=1;n<=N;n++)
           {
               answer=0;
               answerl=0;
               for (int i=A;i<=B;i++)
                   for (int j=0;j<(1<<i);j++)
                       if (counter[i][j]>answer)
                       {
                          answer=counter[i][j];
                          answerl=1;
                          answerList[answerl].x=i;
                          answerList[answerl].y=j;
                       }
                       else if (counter[i][j]==answer)
                       {
                          answer=counter[i][j];
                          answerl++;
                          answerList[answerl].x=i;
                          answerList[answerl].y=j;
                       }
               if (answer==0) break;
               else printAnswer();
           }
           
           //cout<<clock()<<endl;
           return 0;
       }
       /*
       inline
       int count(const unsigned int value)
       {
           for (int i=A;i<=B;i++)
           {
               unsigned int cut=~((~0)<<i);
               for (int j=cut;j>=0;j--)
                   if ((value&cut)==j) counter[i][j]++;
           }
           return 0;
       }
       inline
       int count2(const unsigned int value,const int c)
       {
           for (int i=A;i<=c;i++)
           {
               unsigned int cut=~((~0)<<i);
               for (int j=cut;j>=0;j--)
                   if ((value&cut)==j) counter[i][j]++;
           }
           return 0;
       }
       */
};

#include <time.h>
int main()
{
    //cout<<clock()<<endl;
    Program app;
    return app.run();
}
