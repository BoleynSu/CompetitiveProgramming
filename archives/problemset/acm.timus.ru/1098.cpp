/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: $DATA
DESCRIPTION:
$DESCRIPTION
*/
#include <stdio.h>
#include <string>
using std::string;

class Application
{
      FILE* in;
      FILE* out;
      static const int N=1999;
      static const int MAXLENGTH=30000;
      int length;
      char s[MAXLENGTH+1];
      public:
      Application(const char* input=0,const char* output=0)
                        :in(input?fopen(input,"r"):stdin),
                         out(output?fopen(output,"w"):stdout)
      {
                         char get;
                         length=0;
                         while ((get=fgetc(in))!=EOF)
                               if (get!='\n') s[length++]=get;
                         s[length]=0;
      }
      ~Application()
      {
                    fclose(in);
                    fclose(out);
      }
      int run()
      {
          string S(s);
          int pos=0;
          while (S.length()>1)
          {
                pos+=N-1;
                pos%=S.length();
                S.erase(pos,1);
          }
          if (S=="?") fprintf(out,"Yes\n");
          else if (S==" ") fprintf(out,"No\n");
          else fprintf(out,"No comments\n");
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
