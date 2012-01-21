/*
ID: sujiao1
PROG: cowcycle
LANG: C
*/
/*
PROGRAM: cowcycle
AUTHOR: Su Jiao
DATE: 2010-1-6
DESCRIPTION:
秀·谢夫（小奶牛）在花花公子杂志上中了大奖，于是她从农村搬到了城郊的一座别墅中。
可是她还常常怀念乡村的生活，总想回到原来的农村逛逛。为了环保，秀决定骑上为她量身
定做的奶牛自行车（特殊的自行车，专门为牛蹄设计）。 
秀大约有一吨重。同样的，秀在普通的奶牛自行车上，要想骑得平平稳稳，也不是一件容易
的事。因此，调节奶牛自行车的变速器让秀心力交瘁。 
帮助秀选择她的奶牛自行车前面 F （1 <= F <= 5）个齿轮和后面 R （1 <= R <= 10）个
齿轮，使她的 F*R 奶牛自行车符合下面的标准： 
前面齿轮的型号（齿的数量）必须在给定的范围内。 
后面齿轮的型号（齿的数量）必须在给定的范围内。 
在每一种齿轮组合中，传动比率就是前面齿轮的齿数除以后面齿轮的齿数所得的商。 
最大的传动比率至少是最小的三倍。 
齿轮组合（已排好序）相邻两项的差的的方差（见下面的例子） 应该达到最小。 
按照下面的公式计算平均数与方差（xi 代表数据） ： 
                      1    n
          平均数 = ---  SUM xi
                   n   i=1   
                 1    n    
          方差 = ---  SUM (xi - 平均数)^2
                 n   i=1   
计算并确定最佳齿轮组合（其中 F 个前齿轮，R 个后齿轮），使方差最小（传动比率至少
是 3x）。 
*/
#include <stdio.h>
/*
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
      static const int MAXF=5;
      static const int MAXR=10;*/
      #define MAXF 5
      #define MAXR 10
      static const float oo=1024*1024*1024;
      int F,R,F1,F2,R1,R2;
      int fv[MAXF+2];
      int rv[MAXR+2];
      double answer;
      int answerF[MAXF+2];
      int answerR[MAXR+2];
      //public:
      /*Application(char* input,char* output)
      :cin(input),cout(output)
      {
                              cin>>F>>R>>F1>>F2>>R1>>R2;
      }
      ~Application()
      {
                    cin.close();
                    cout.close();
      }*/
      double get()
      {             
             if ((fv[1]*rv[1])<(rv[R]*fv[F])*3)
                return oo;
             
             double got[MAXF*MAXR+2];
             int len=0;
             int i,j;
             for (i=1;i<=F;i++)
                 for (j=1;j<=R;j++)
                     got[++len]=((double)fv[i])/((double)rv[j]);
             
             
             for (i=1;i<=len;i++)
                 for (j=i+1;j<=len;j++)
                     if (got[i]>got[j])
                     {
                        double swap=got[i];
                        got[i]=got[j];
                        got[j]=swap;
                     }
             
             len--;
             for (i=1;i<=len;i++) got[i]=got[i+1]-got[i];             
             //for (int i=1;i<=len;i++) cout<<got[i]<<endl;
             //exit(0);
             
             double sum=0;
             for (i=1;i<=len;i++)
                 sum+=got[i];
             
             double avg=sum/len;             
             //cout<<avg<<endl;
             //exit(0);
             
             double value=0;
             for (i=1;i<=len;i++)
                 value+=(got[i]-avg)*(got[i]-avg);
             value/=len;
             //cout<<value<<endl;
             //exit(0);
             
             return value;
      }
      void saveAnswerList()
      {
           int i;
           for (i=1;i<=F;i++)// cout<<
               (answerF[i]=fv[i])
               //<<" ";cout<<endl
               ;
           for (i=1;i<=R;i++)// cout<<
               (answerR[i]=rv[i])
               //<<" ";cout<<endl
               ;
      }
      void rsearch(int n,int f)
      {
           int i;
           if (n==0)
           {              
              double nanswer=get();
              if (nanswer<answer)
              {
                 answer=nanswer;
                 saveAnswerList();
              }
           }
           else
               for (i=f;i<=R2;i++)
               {
                   rv[n]=i;
                   rsearch(n-1,i+1);
               }
      }
      void fsearch(int n,int f)
      {
           int i;
           if (n==0)
              rsearch(R,R1);
           else
               for (i=f;i<=F2;i++)
               {
                   fv[n]=i;
                   fsearch(n-1,i+1);
               }
      }
      void printAnswerList()
      {
           //cout<<answerF[F];
           int i;
           printf("%d",answerF[F]);
           for (i=F-1;i>=1;i--) printf(" %d",answerF[i]);//cout<<" "<<answerF[i];
           printf("\n");//cout<<endl;
           printf("%d",answerR[R]);//cout<<answerR[R];
           for (i=R-1;i>=1;i--) printf(" %d",answerR[i]);//cout<<" "<<answerR[i];
           printf("\n");//cout<<endl;
      }
      int run()
      {
          answer=oo;
          fsearch(F,F1);
          printAnswerList();
          //cout<<clock()<<endl;
          return 0;
      }
//};

int main()
{
    //Application app("cowcycle.in","cowcycle.out");
    freopen("cowcycle.in","r",stdin);
    freopen("cowcycle.out","w",stdout);
    scanf("%d %d %d %d %d %d",&F,&R,&F1,&F2,&R1,&R2);//cin>>F>>R>>F1>>F2>>R1>>R2;
    return /*app.*/run();
}

/*
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
      static const int MAXF=5;
      static const int MAXR=10;
      static const float oo=1024*1024*1024;
      int F,R,F1,F2,R1,R2;
      int fv[MAXF+2];
      int rv[MAXR+2];
      double answer;
      int answerF[MAXF+2];
      int answerR[MAXR+2];
      public:
      Application(char* input,char* output)
      :cin(input),cout(output)
      {
                              cin>>F>>R>>F1>>F2>>R1>>R2;
      }
      ~Application()
      {
                    cin.close();
                    cout.close();
      }
      double get()
      {             
             if ((fv[1]*rv[1])<(rv[R]*fv[F])*3)
                return oo;
             
             double got[MAXF*MAXR+2];
             int len=0;
             
             for (int i=1;i<=F;i++)
                 for (int j=1;j<=R;j++)
                     got[++len]=double(fv[i])/double(rv[j]);
             
             
             for (int i=1;i<=len;i++)
                 for (int j=i+1;j<=len;j++)
                     if (got[i]>got[j])
                     {
                        double swap=got[i];
                        got[i]=got[j];
                        got[j]=swap;
                     }
             
             len--;
             for (int i=1;i<=len;i++) got[i]=got[i+1]-got[i];             
             //for (int i=1;i<=len;i++) cout<<got[i]<<endl;
             //exit(0);
             
             double sum=0;
             for (int i=1;i<=len;i++)
                 sum+=got[i];
             
             double avg=sum/len;             
             //cout<<avg<<endl;
             //exit(0);
             
             double value=0;
             for (int i=1;i<=len;i++)
                 value+=(got[i]-avg)*(got[i]-avg);
             value/=len;
             //cout<<value<<endl;
             //exit(0);
             
             return value;
      }
      void saveAnswerList()
      {
           for (int i=1;i<=F;i++)// cout<<
               (answerF[i]=fv[i])
               //<<" ";cout<<endl
               ;
           for (int i=1;i<=R;i++)// cout<<
               (answerR[i]=rv[i])
               //<<" ";cout<<endl
               ;
      }
      void rsearch(int n,int f)
      {
           if (n==0)
           {              
              double nanswer=get();
              if (nanswer<answer)
              {
                 answer=nanswer;
                 saveAnswerList();
              }
           }
           else
               for (int i=f;i<=R2;i++)
               {
                   rv[n]=i;
                   rsearch(n-1,i+1);
               }
      }
      void fsearch(int n,int f)
      {
           if (n==0)
              rsearch(R,R1);
           else
               for (int i=f;i<=F2;i++)
               {
                   fv[n]=i;
                   fsearch(n-1,i+1);
               }
      }
      void printAnswerList()
      {
           cout<<answerF[F];
           for (int i=F-1;i>=1;i--) cout<<" "<<answerF[i];
           cout<<endl;
           cout<<answerR[R];
           for (int i=R-1;i>=1;i--) cout<<" "<<answerR[i];
           cout<<endl;
      }
      int run()
      {
          answer=oo;
          fsearch(F,F1);
          printAnswerList();
          //cout<<clock()<<endl;
          return 0;
      }
};

int main()
{
    Application app("cowcycle.in","cowcycle.out");
    return app.run();
}
*/
