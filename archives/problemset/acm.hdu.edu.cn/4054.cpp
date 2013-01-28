#include <cstdio>
using namespace std;

char s[1025*1025*17];

int main()
{
    while (gets(s))
    {
          for (int i=0;s[i];i+=16)
          {
              printf("%04x: ",i);
              bool end=false;
              for (int j=i;j<i+16;j+=2)
              {
                  if (!s[j])
                  {
                     for (int k=j;k<i+16;k+=2)
                         printf("     ");
                     end=true;
                     break;
                  }
                  else if (!s[j+1])
                  {
                       printf("%02x   ",s[j]);
                       for (int k=j+2;k<i+16;k+=2)
                           printf("     ");
                       end=true;
                       break;
                  }
                  else
                  {
                      printf("%02x%02x ",s[j],s[j+1]);
                  }
              }
              for (int j=i;j<i+16;j++)
                  if ('a'<=s[j]&&s[j]<='z') printf("%c",s[j]-'a'+'A');
                  else if ('A'<=s[j]&&s[j]<='Z') printf("%c",s[j]-'A'+'a');
                  else if (s[j]==0) break;
                  else printf("%c",s[j]);
              printf("\n");
              if (end) break;
          }
    }
}

