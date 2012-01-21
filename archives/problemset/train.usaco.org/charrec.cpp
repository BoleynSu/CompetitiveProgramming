/*
ID: sujiao1
PROG: charrec
LANG: C++
*/
/*
PROGRAM: charrec
AUTHOR: Su Jiao
DATE: 2010-1-18
DESCRIPTION:
*/
#include <fstream>
using std::ifstream;
using std::ofstream;
using std::endl;
#include <cstring>
using std::memset;
//#include <string>
//using std::string;

class Application
{
      ifstream cin;
      ofstream cout;
      ifstream fnt;
      static const int CHARSET='z'+2;
      static const int ID_LEN=27;
      static char* const SET;
      static const int MAXLINE=20;
      static const int MAXIN=1200+1;
      static const int MAXLENGTH=20;
      static const int oo=1<<29;
      typedef char string[MAXLENGTH+2];
      string font[CHARSET][MAXLINE];
      int line;
      string in[MAXIN];
      int getId[CHARSET];
      int id_len;
      int dif[MAXIN][ID_LEN][MAXLINE];//dif[i][j][k]=第i行输入 与 第j个字符的第k行的差距  
      struct Dif
      {
             int d,n,m;//分别对应减、不变、增 
             int dis,nis,mis;//分别对应减、不变、增 时最像的字符的id 
             Dif()
                  :d(oo),n(oo),m(oo)
             {
             }
             int toId(int n)
             {
                 if (n==Application::MAXLINE+1) return dis;
                 if (n==Application::MAXLINE) return nis;
                 if (n==Application::MAXLINE-1) return mis;
             }
      };
      Dif d[MAXIN];
      int f[MAXIN+MAXLINE*2];
      int path[MAXIN+MAXLINE*2];
      public:
      Application(char* input,char* output,char* font_file)
                        :cin(input),cout(output),fnt(font_file)
      {
                        fnt>>line;
                        for (char* i=SET;*i;i++)
                            for (int j=0;j<MAXLINE;j++)
                                fnt>>font[*i][j];
                        
                        cin>>line;
                        for (int i=0;i<line;i++)
                            cin>>in[i];
      }
      ~Application()
      {
                    cin.close();
                    cout.close();
      }
      void initGetId()
      {
           id_len=0;
           for (char* i=SET;*i;i++)
           {
               getId[*i]=i-SET;
               id_len++;
               //cout<<*i<<getId[*i]<<endl;
           }
           //cout<<id_len<<endl;
      }
      int different(string a,string b)
      {
          int c=0;
          for (;*a;a++)
              if (*a!=*b++) c++;
          return c;
      }
      void initDif()
      {
           memset(dif,0,sizeof(dif));
           for (int i=0;i<line;i++)
               for (int j=0;j<id_len;j++)
                   for (int k=0;k<MAXLINE;k++)
                       dif[i][j][k]=different(font[SET[j]][k],in[i]);
      }
      void initD()
      {
           for (int i=0;i<line;i++)
           {
               d[i].d=oo;
               for (int itIs=0;itIs<id_len;itIs++)
               {
                   for (int _d=0;_d<MAXLINE;_d++)
                   {
                       int n=0;
                       for (int j=0;j<MAXLINE;j++)
                           if (j<_d) n+=dif[i+j][itIs][j];
                           else if (j>=_d) n+=dif[i+j+1][itIs][j];
                       if (n<d[i].d)
                       {
                          d[i].d=n;
                          d[i].dis=itIs;
                       }
                   }
               }
               d[i].n=oo;
               for (int itIs=0;itIs<id_len;itIs++)
               {
                   int n=0;
                   for (int j=0;j<MAXLINE;j++)
                       n+=dif[i+j][itIs][j];
                   if (n<d[i].n)
                   {
                      d[i].n=n;
                      d[i].nis=itIs;
                   }
               }               
               d[i].m=oo;
               for (int itIs=0;itIs<id_len;itIs++)
               {
                   for (int m=0;m<MAXLINE;m++)
                   {
                       int n=0;
                           for (int j=0;j<MAXLINE;j++)
                               if (j<m) n+=dif[i+j][itIs][j];
                               else if (j>m) n+=dif[i+j-1][itIs][j];
                       if (n<d[i].m)
                       {
                          d[i].m=n;
                          d[i].mis=itIs;
                       }
                   }
               }
           }
      }
      void initF()
      {
           for (int i=0;i<=line;f[i++]=oo) ;
           
           f[0]=0;
           for (int i=0;i<=line;i++)
           {
               if (f[i]>=oo) continue;
               if (f[i+MAXLINE+1]>f[i]+d[i].d)
               {
                  f[i+MAXLINE+1]=f[i]+d[i].d;
                  path[i+MAXLINE+1]=MAXLINE+1;
               }
               if (f[i+MAXLINE]>f[i]+d[i].n)
               {
                  f[i+MAXLINE]=f[i]+d[i].n;
                  path[i+MAXLINE]=MAXLINE;
               }
               if (f[i+MAXLINE-1]>f[i]+d[i].m)
               {
                  f[i+MAXLINE-1]=f[i]+d[i].m;
                  path[i+MAXLINE-1]=MAXLINE-1;
               }
           }
      }
      int run()
      {
          initGetId();
          initDif();
          initD();
          initF();
          int id=line;
          char answer[MAXIN];
          int top=0;
          while (path[id])
          {
                answer[top++]=SET[d[id-path[id]].toId(path[id])];
                id=id-path[id];
          }
          for (;--top>=0;cout<<answer[top]) ;
          cout<<endl;
          return 0;
      }
};
char* const Application::SET=" abcdefghijklmnopqrstuvwxyz";

int main()
{
    static
    Application app("charrec.in","charrec.out","font.in");
    return app.run();
}
