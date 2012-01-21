/*
ID: sujiao1
PROG: lgame
LANG: C++
*/
/*
PROGRAM: lgame
AUTHOR: Su Jiao
DATE: 2010-1-9
DESCRIPTION:
描述
在家里用电视机做字母游戏是很流行的，其中一种玩法是:每一个字母有一个数值与之对
应.你收集字母组成一个或多个字以得到尽可能高的得分.除非你已有了 “找字的方法”
(“a way with words”)，你会把你知道的字都试一遍.有时你也许会查阅其拼写，然后计
算得分。显然可以用计算机更为准确地完成此任务。上图示出了英文字母及其所对应的值，
当给出英文字(word) 的表列及收集的字母时，请找出所能形成的得分最高的字或字对
(pairs of words)。 
*/
#include <fstream>
using std::ifstream;
using std::ofstream;
using std::endl;
#include <cstring>
using std::memset;
using std::memcpy;
using std::strcmp;
using std::strcpy;
using std::strlen;

class Application
{
      ifstream cin;
      ofstream cout;
      ifstream dict;
      static const int MAXDICT=40000;
      static const int CHARSET='z'+2;
      static int p[CHARSET];
      static const int MAXLEN=7+1;
      typedef char string[MAXLEN];
      typedef int Counter[MAXLEN];
      static const int MAXANSWER=1000;
      struct Answer{string l,r;};
      int d_len;
      string d[MAXDICT+2];
      string in;
      int counter_len;
      Counter d_counter[MAXDICT+2];
      Counter in_counter;
      int d_p[MAXDICT+2];
      int getid[CHARSET];
      char getchar[MAXLEN];      
      int maxp;
      Answer answer[MAXANSWER];
      int answer_len;
      public:
      Application(char* input,char* output,char* dictionary)
      :cin(input),cout(output),dict(dictionary)
      {
                                               d_len=0;
                                               while (dict>>d[++d_len]) ;
                                               while (d[d_len--][0]!='.') ;
                                               cin>>in;
      }
      ~Application()
      {
                    cin.close();
                    cout.close();
                    dict.close();
      }
      void initP()
      {
           p['q']=p['j']=p['z']=p['x']=7;
	       p['w']=p['f']=p['k']=p['v']=6;
	       p['y']=p['p']=p['g']=p['h']=p['b']=p['m']=5;
	       p['u']=p['d']=p['c']=4;
	       p['o']=p['l']=3;
	       p['r']=p['t']=p['a']=p['n']=2;
	       p['e']=p['i']=p['s']=1;
      }
      void initIn()
      {
           int set[CHARSET];
           memset(set,0,sizeof(set));
           for (char* i=in;*i;set[*i++]++) ;
           memset(getid,0,sizeof(getid));
           counter_len=0;
           for (char i='a';i<='z';i++)
               if (set[i])
               {
                  getid[i]=++counter_len;
                  getchar[counter_len]=i;
               }
           //for (int i='a';i<='z';i++) if (getid[i]) cout<<getchar[getid[i]]<<endl;
           memset(in_counter,0,sizeof(in_counter));
           for (char* i=in;*i;in_counter[getid[*i++]]++) ;
           //for (int i=1;i<=counter_len;i++) cout<<in_counter[i]<<getchar[i]<<i<<endl;
      }
      void initD()
      {
           for (int i=1;i<=d_len;i++)
           {
               memset(d_counter[i],0,sizeof(d_counter[i]));
               for (char* j=d[i];*j;j++)
               {
                   int id=getid[*j];
                   bool can=true;
                   
                   if (id)
                   {
                      if (++d_counter[i][id]>in_counter[id]) can=false;
                   }
                   else can=false;
                   
                   if (!can)
                   {
                       for (int k=0;k<MAXLEN;k++)
                           d[i][k]=d[d_len][k];
                       d_len--;
                       i--;
                       break;
                   }
               }
           }
           for (int i=1;i<=d_len;i++)
           {
               d_p[i]=0;
               for (char* j=d[i];*j;d_p[i]+=p[*j++]) ;
           }
           //for (int i=1;i<=d_len;i++)
           //{
           //    cout<<d[i]<<":"<<d_p[i]<<endl;
           //    for (int j=1;j<=counter_len;j++) cout<<d_counter[i][j];cout<<endl;
           //}
      }
      void sort()
      {
           for (int i=1;i<=answer_len;i++)
               for (int j=i+1;j<=answer_len;j++)
               {
                   int cmp;
                   switch (cmp=strcmp(answer[i].l,answer[j].l))
                   {
                          case 0:
                               //if i.l==j.l but  i.r<j.r then do not change
                               if (strcmp(answer[i].r,answer[j].r)<0) break;
                               //else i>j
                          case 1:
                               Answer swap;
                               memcpy(&swap,&answer[i],sizeof(Answer));
                               memcpy(&answer[i],&answer[j],sizeof(Answer));
                               memcpy(&answer[j],&swap,sizeof(Answer));
                               break;
                          case -1:
                          break;
                   }
               }
      }
      int run()
      {
          initP();
          initIn();
          initD();
          maxp=0;
          answer_len=0;
          for (int i=1;i<=d_len;i++)
          {
              if (d_p[i]>=maxp)
              {
                 if (d_p[i]>maxp)
                 {
                    maxp=d_p[i];
                    answer_len=0;
                 }
                 answer_len++;
                 strcpy(answer[answer_len].l,d[i]);
                 answer[answer_len].r[0]='\0';
              }
              for (int j=i+1;j<=d_len;j++)
              {
                  bool can=(d_p[i]+d_p[j]>=maxp);
                  if (can)
                     for (int k=1;k<=counter_len;k++)
                         if (d_counter[i][k]+d_counter[j][k]>in_counter[k])
                         {
                            can=false;
                            break;
                         }
                  if (can)
                  {
                     if (d_p[i]+d_p[j]>maxp)
                     {
                        maxp=d_p[i]+d_p[j];
                        answer_len=0;
                     }
                     answer_len++;
                     if (strcmp(d[i],d[j])>0)//d[i]>d[j]
                     {
                        strcpy(answer[answer_len].l,d[j]);
                        strcpy(answer[answer_len].r,d[i]);
                     }
                     else
                     {
                        strcpy(answer[answer_len].l,d[i]);
                        strcpy(answer[answer_len].r,d[j]);
                     }
                  }
              }
          }
          cout<<maxp<<endl;
          sort();
          for (int i=1;i<=answer_len;i++)
          {
              cout<<answer[i].l;
              if (strlen(answer[i].r))
                 cout<<" "<<answer[i].r;
              cout<<endl;
          }
          return 0;
      }
};
int Application::p['z'+2];

int main()
{
    Application app("lgame.in","lgame.out","lgame.dict");
    return app.run();
}
