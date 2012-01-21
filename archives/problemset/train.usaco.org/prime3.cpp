/*
ID: sujiao1
PROG: prime3
LANG: C++
*/
/*
PROGRAM: prime3
AUTHOR: Su Jiao
DATE: 2010-1-7
DESCRIPTION:
在下面的方格中，每行，每列，以及两条对角线上的数字可以看作是五位的素数。方格中的
行按照从左到右的顺序组成一个素数，而列按照从上到下的顺序。两条对角线也是按照从左
到右的顺序来组成。 
+---+---+---+---+---+
| 1 | 1 | 3 | 5 | 1 |
+---+---+---+---+---+
| 3 | 3 | 2 | 0 | 3 |
+---+---+---+---+---+
| 3 | 0 | 3 | 2 | 3 |
+---+---+---+---+---+
| 1 | 4 | 0 | 3 | 3 |
+---+---+---+---+---+
| 3 | 3 | 3 | 1 | 1 |
+---+---+---+---+---+ 
这些素数各个数位上的和必须相等。 
左上角的数字是预先定好的。 
一个素数可能在方阵中重复多次。 
如果不只有一个解，将它们全部输出（按照这25个数字组成的25位数的大小排序）。 
一个五位的素数开头不能为0（例如：00003 不是五位素数） 
*/
#include <fstream>
using std::ifstream;
using std::ofstream;
using std::endl;
#include <cstring>
using std::memset;
#include <ctime>
using std::clock;

class Application
{
      ifstream cin;
      ofstream cout;
      static const int MAXN=100000;
      static const int MAXCAN=1000;
      static const int K=10;
      static const int TABLESIZE=5;
      struct index{int f,t;index():f(0),t(-1){}};
      typedef int Table[TABLESIZE+2][TABLESIZE+2];
      bool is[MAXN];
      int can[MAXCAN];
      int can_len;
      int sum,first;
      typedef int Answer[TABLESIZE+2];
      static const int MAXANSWER=1000;
      Answer answer[MAXANSWER+2];
      int answer_len;
      public:
      Application(char* input,char* output)
      :cin(input),cout(output)
      {
                              cin>>sum>>first;
      }
      ~Application()
      {
                    cin.close();
                    cout.close();
      }
      
      //BEGIN initCanAndIs
      int getSum(int n)
      {
          return ((n/10000)%10
                 +(n/1000)%10
                 +(n/100)%10
                 +(n/10)%10
                 +(n/1)%10);
      }
      void initCanAndIs()
      {
           static const int MINPRIME=2;
           int primeTable[MAXN];
           int top=0;
           primeTable[++top]=MINPRIME;
           for (int j=primeTable[top]+1;j<MAXN;j++)
           {
               bool _is=true;
               for (int i=1;i<=top;i++)
                   if (j%primeTable[i]==0)
                   {
                      _is=false;
                      break;
                   }
               if (_is)
                  primeTable[++top]=j;
           }
           memset(is,false,sizeof(is));
           can_len=0;
           for (int i=1;i<=top;i++)
               if ((getSum(primeTable[i])==sum)&&(primeTable[i]>=MAXN/10))
                  is[can[++can_len]=primeTable[i]]=true;
           
           //cout<<can_len<<"can:"<<endl;
           //for (int i=1;i<=can_len;i++) cout<<i<<":"<<can[i]<<endl;
      }
      //END initCanAndIs
      
      //BEGIN qsort      
      typedef int (*function)(int);
      static function getValue;
      void qsort(int* l,int* r)
      {
           int* i=l;
           int* j=r;
           int k1,k2,k3,k4,k5;
           int mid=getValue(*(l+(r-l)/2));
           while (i<=j)
           {
                 while (getValue(*i)<mid) i++;
                 while (getValue(*j)>mid) j--;
                 if (i<=j)
                 {
                    int swap=*i;
                    *i=*j;
                    *j=swap;
                    i++;
                    j--;
                 }
           }
           if (l<j) qsort(l,j);
           if (i<r) qsort(i,r);
      }
      //END qsort
      
      //BEGIN initIndex
      index indexOfA[K];
      index indexOfC[K];
      index indexOfACE[K][K][K];
      index indexOfBCD[K][K][K];
      int canC[MAXCAN];
      int canACE[MAXCAN];
      int canBCD[MAXCAN];
      static
      int getA(int v);
      static
      int getC(int v);
      static
      int getACE(int v);
      static
      int getBCD(int v);
      void getK(int n,int& k1,int& k2,int& k3,int& k4,int& k5)
      {
           k1=(n/10000)%10;
           k2=(n/1000)%10;
           k3=(n/100)%10;
           k4=(n/10)%10;
           k5=(n/1)%10;
      }
      void initIndex()
      {
           //init index of A
           for (int i=1;i<=can_len;i++)
           {
               int k1=getA(can[i]);
               if (indexOfA[k1].f==0)
                  indexOfA[k1].f=i;
               indexOfA[k1].t=i;
           }
           
           //init index of C
           for (int i=1;i<=can_len;canC[i]=can[i++]) ;
           getValue=getC;
           qsort(&canC[1],&canC[can_len]);
           //cout<<can_len<<"canC:"<<endl;
           //for (int i=1;i<=can_len;i++) cout<<i<<":"<<canC[i]<<endl;
           for (int i=1;i<=can_len;i++)
           {
               int k3=getC(canC[i]);
               if (indexOfC[k3].f==0)
                  indexOfC[k3].f=i;
               indexOfC[k3].t=i;
           }
           
           //init index of ACE
           for (int i=1;i<=can_len;canACE[i]=can[i++]) ;
           getValue=getACE;
           qsort(&canACE[1],&canACE[can_len]);
           //cout<<can_len<<"canACE:"<<endl;
           //for (int i=1;i<=can_len;i++) cout<<i<<":"<<canACE[i]<<endl;
           for (int i=1;i<=can_len;i++)
           {
               int k1,k2,k3,k4,k5;
               getK(canACE[i],k1,k2,k3,k4,k5);
               if (indexOfACE[k1][k3][k5].f==0)
                  indexOfACE[k1][k3][k5].f=i;
               indexOfACE[k1][k3][k5].t=i;
           }
                  
           //init index of BCD
           for (int i=1;i<=can_len;canBCD[i]=can[i++]) ;
           getValue=getBCD;
           qsort(&canBCD[1],&canBCD[can_len]);
           //cout<<can_len<<"canBCD:"<<endl;
           //for (int i=1;i<=can_len;i++) cout<<i<<":"<<canBCD[i]<<endl;
           for (int i=1;i<=can_len;i++)
           {
               int k1,k2,k3,k4,k5;
               getK(canBCD[i],k1,k2,k3,k4,k5);
               if (indexOfBCD[k2][k3][k4].f==0)
                  indexOfBCD[k2][k3][k4].f=i;
               indexOfBCD[k2][k3][k4].t=i;
           }
      }
      //END initIndex
      
      //BEGIN search
      int getSum(int k1,int k2,int k3,int k4,int k5)
      {
          return k1*10000+k2*1000+k3*100+k4*10+k5*1;
      }
      void search()
      {
           Table table;
           memset(table,0,sizeof(table));
           /* 
            * 11 21 31 41 51
            * 12 22 32 42 52
            * 13 23 33 43 43
            * 14 24 34 44 54
            * 15 25 35 45 55
            */
           for (int i=indexOfA[first].f;i<=indexOfA[first].t;i++)
           {
               getK(can[i],table[1][1],table[2][2],table[3][3],table[4][4],table[5][5]);
               for (int j=indexOfC[table[3][3]].f;j<=indexOfC[table[3][3]].t;j++)
               {
                   getK(canC[j],table[1][5],table[2][4],table[3][3],table[4][2],table[5][1]);
                   for (int k=indexOfC[table[3][3]].f;k<=indexOfC[table[3][3]].t;k++)
                   {
                       getK(canC[k],table[3][1],table[3][2],table[3][3],table[3][4],table[3][5]);
                       for (int l=indexOfACE[table[1][1]][table[3][1]][table[5][1]].f;
                            l<=indexOfACE[table[1][1]][table[3][1]][table[5][1]].t;
                            l++)
                       {
                            getK(canACE[l],table[1][1],table[2][1],table[3][1],table[4][1],table[5][1]);
                            for (int m=indexOfACE[table[1][5]][table[3][5]][table[5][5]].f;
                                 m<=indexOfACE[table[1][5]][table[3][5]][table[5][5]].t;
                                 m++)
                            {
                                 getK(canACE[m],table[1][5],table[2][5],table[3][5],table[4][5],table[5][5]);
                                 table[2][3]=sum-table[2][1]-table[2][2]-table[2][4]-table[2][5];
                                 if ((table[2][3]>=0)&&is[getSum(table[2][1],table[2][2],table[2][3],table[2][4],table[2][5])])
                                 {
                                    table[4][3]=sum-table[4][1]-table[4][2]-table[4][4]-table[4][5];
                                    if ((table[4][3]>=0)&&is[getSum(table[4][1],table[4][2],table[4][3],table[4][4],table[4][5])])
                                    {
                                       for (int n=indexOfBCD[table[2][2]][table[3][2]][table[4][2]].f;
                                            n<=indexOfBCD[table[2][2]][table[3][2]][table[4][2]].t;
                                            n++)
                                       {
                                            getK(canBCD[n],table[1][2],table[2][2],table[3][2],table[4][2],table[5][2]);
                                            for (int o=indexOfBCD[table[2][4]][table[3][4]][table[4][4]].f;
                                                 o<=indexOfBCD[table[2][4]][table[3][4]][table[4][4]].t;
                                                 o++)
                                            {
                                                 getK(canBCD[o],table[1][4],table[2][4],table[3][4],table[4][4],table[5][4]);
                                                 table[1][3]=sum-table[1][1]-table[1][2]-table[1][4]-table[1][5];
                                                 if ((table[1][3]>=0)&&is[getSum(table[1][1],table[1][2],table[1][3],table[1][4],table[1][5])])
                                                 {
                                                    table[5][3]=sum-table[5][1]-table[5][2]-table[5][4]-table[5][5];
                                                    if ((table[5][3]>=0)&&is[getSum(table[5][1],table[5][2],table[5][3],table[5][4],table[5][5])])
                                                    {
                                                       if (is[getSum(table[1][3],table[2][3],table[3][3],table[4][3],table[5][3])])
                                                          getAnswer(table);
                                                    }
                                                 }
                                            }
                                       }
                                    }
                                 }
                            }
                       }
                   }
               }
           }
      }
      //END search
      inline
      void getAnswer(Table table)
      {
           answer_len++;
           for (int i=1;i<=TABLESIZE;i++)
                answer[answer_len][i]=getSum(table[1][i],table[2][i],table[3][i],table[4][i],table[5][i]);
           /*
           for (int c=1;c<=TABLESIZE;c++)
               cout<<c<<"c:"<<is[getSum(table[c][1],table[c][2],table[c][3],table[c][4],table[c][5])]<<endl;
           for (int c=1;c<=TABLESIZE;c++)
               cout<<c<<"r:"<<is[getSum(table[1][c],table[2][c],table[3][c],table[4][c],table[5][c])]<<endl;
           cout<<"cross:"<<is[getSum(table[1][1],table[2][2],table[3][3],table[4][4],table[5][5])]<<endl;
           cout<<"cross:"<<is[getSum(table[1][5],table[2][4],table[3][3],table[4][2],table[5][1])]<<endl;
           */
                                                       
      }
      void printAnswer()
      {
           if (answer_len==0) cout<<"NONE"<<endl;
           else
           {
               for (int i=1;i<answer_len;i++)
               {
                   for (int j=i+1;j<=answer_len;j++)
                   {
                       
                       bool bigger;
                       for (int k=1;k<=TABLESIZE;k++)
                       {
                           if (answer[i][k]>answer[j][k])
                           {
                              bigger=true;
                              break;
                           }
                           else if (answer[i][k]<answer[j][k])
                           {
                                bigger=false;
                                break;
                           }
                       }
                       if (bigger)
                       {
                          for (int k=1;k<=TABLESIZE;k++)
                          {
                              int swap=answer[i][k];
                              answer[i][k]=answer[j][k];
                              answer[j][k]=swap;
                          }
                       }
                       
                   }
               }
               
               cout
               <<answer[1][1]<<endl
               <<answer[1][2]<<endl
               <<answer[1][3]<<endl
               <<answer[1][4]<<endl
               <<answer[1][5]<<endl;
               for (int i=2;i<=answer_len;i++)
               {
                   cout
                   <<endl
                   <<answer[i][1]<<endl
                   <<answer[i][2]<<endl
                   <<answer[i][3]<<endl
                   <<answer[i][4]<<endl
                   <<answer[i][5]<<endl;
               }
           }
      }
      int run()
      {
          initCanAndIs();
          initIndex();
          answer_len=0;
          search();
          printAnswer();
          //cout<<clock()<<endl;
          return 0;
      }
};
Application::function Application::getValue;
int Application::getA(int v)
{
    return (v/10000)%10;
}
int Application::getC(int v)
{
    return (v/100)%10;
}
int Application::getACE(int v)
{
    return ((v/10000)%10)*10000+((v/100)%10)*100+((v/1)%10)*1;
}
int Application::getBCD(int v)
{
    return ((v/1000)%10)*1000+((v/100)%10)*100+((v/10)%10)*10;
}

int main()
{
    Application app("prime3.in","prime3.out");
    return app.run();
}
