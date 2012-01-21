/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-4-14
DESCRIPTION:
$DESCRIPTION
*/
#include <stdio.h>
#include <string.h>

#define WIDTH 80

int pos;
char get;
char screen[WIDTH];

int main()
{
    memset(screen,' ',sizeof(screen));
    while (scanf("%c",&get)!=EOF)
    {
          if (get=='\n') continue;
          if (get=='<') pos--;
          else if (get=='>') pos++;
          else screen[pos++]=get;
          if (pos==-1) pos++;
          if (pos==WIDTH) pos-=WIDTH;
    }
    printf("%s\n",screen);
} 
