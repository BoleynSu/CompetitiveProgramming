/*
ID: sujiao1
PROG: calfflac
LANG: C++
*/
#include <cstring>
#include <iostream>
#include <fstream>
using std::endl;
using std::strlen;
/*
using std::cin;
using std::cout;
*/
std::ifstream cin("calfflac.in");
std::ofstream cout("calfflac.out");


struct Program
{
       typedef char* charpointer;
       struct Answer
       {
              int n;
              charpointer begin,end;
              Answer():n(0){}
       };
       static const int MAXLEN=20000;
       static const int __EOF__=-1;
       char input[MAXLEN+2];
       int inl;
       char processed[MAXLEN+2];
       charpointer mark[MAXLEN+2];
       int prol;
       Answer answer;
       Program()
       {
                cin.getline(input,MAXLEN,__EOF__);
                inl=strlen(input);
                //cout<<input;
       }
       inline
       bool is(char c)
       {
            return (((c<='z')&&(c>='a'))||((c<='Z')&&(c>='A')));
       }
       inline
       char lower(char c)
       {
            if ((c<='Z')&&(c>='A'))
               return c-'A'+'a';
            else return c;
       }
       void process()
       {
            char* end=&input[inl];
            char* pro=processed;
            charpointer* ma=mark;
            for (char* i=input;i<end;i++)
            {
                if (is(*i))
                {
                   *(pro++)=lower(*i);
                   *(ma++)=i;
                }
            }
            *pro='\0';
            prol=strlen(processed);
            /*
            for (int i=0;i<prol;i++)
                cout<<processed[i];
            cout<<endl;
            for (int i=0;i<prol;i++)
                cout<<int(mark[i]);
            */
       }
       void get(char* pos,char* begin,char* end,Answer& ans)
       {
            int i;
            for (i=0;;i++)
            {
                if ((pos+i>=end)||(pos-i<begin)) break;
                if (pos[i]!=pos[-i]) break;
            }
            if (answer.n<i*2-1)
            {
               answer.n=i*2-1;
               answer.begin=&pos[-i+1];
               answer.end=&pos[i-1];
            }
            if ((pos+i>=end)||(pos-i-1<begin)) i--;
            for (i=0;;i++)
            {
                if ((pos+i>=end)||(pos-i-1<begin)) break;
                if (pos[i]!=pos[-i-1]) break;
            }
            if (answer.n<i*2)
            {
               answer.n=i*2;
               answer.begin=&pos[-i];
               answer.end=&pos[i-1];
            }
       }
       void getAnswer()
       {
            charpointer begin,end;
            begin=processed;
            end=&processed[prol];
            for (char* i=begin;i<end;i++)
            {
                get(i,processed,end,answer);
            }
            cout<<answer.n<<endl;
            begin=mark[answer.begin-processed];
            end=mark[answer.end-processed];
            for (char* i=begin;i<=end;i++)
                cout<<*i;
            cout<<endl;
       }
       int run()
       {
           process();
           getAnswer();
           return 0;
       }
};

int main()
{
    Program app;
    return app.run();
}
