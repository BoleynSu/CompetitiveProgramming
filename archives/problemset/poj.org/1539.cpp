#include <cstdio>
#include <cstring>
using namespace std;

const int MAXLENGTH=80+2;
const int MAXVAR='z'+2;
char es[MAXLENGTH];
int m[MAXVAR];
bool h[MAXVAR];

int calc(char* i)
{
    int value=0;
    int op=+1;
    while (*i)
    {
          int delta=0;
          while (*i)
          {
                if ((*i)=='+'&&(*(i+1))=='+')
                {
                   delta++;
                   i+=2;
                }
                else if ((*i)=='-'&&(*(i+1))=='-')
                {
                     delta--;
                     i+=2;
                }
                else break;
          }
          m[*i]+=delta;
          char var=*i++;
          value=value+op*m[var];
          while (*i)
          {
                if ((*i)=='+'&&(*(i+1))=='+')
                {
                   m[var]++;
                   i+=2;
                }
                else if ((*i)=='-'&&(*(i+1))=='-')
                {
                     m[var]--;
                     i+=2;
                }
                else break;
          }
          if (*i=='+') op=+1,i++;
          else if (*i=='-') op=-1,i++;
          else ;
    }
    return value;
}

int main()
{
    while (gets(es))
    {
          for (int i='a';i<='z';i++)
              m[i]=i-'a'+1,
              h[i]=false;
          for (char* i=es;*i;i++)
              if ('a'<=(*i)&&(*i)<='z')
                 h[*i]=true;
          printf("Expression: ");
          puts(es);
          char* i=es;
          char* j=es;
          while (*j)
          {
                if (*j==' ') ;
                else (*(i++))=(*j);
                j++;
          }
          *i=0;
          printf("    value = %d\n",calc(es));
          for (int i='a';i<='z';i++)
              if (h[i]) printf("    %c = %d\n",i,m[i]);
    }
}
