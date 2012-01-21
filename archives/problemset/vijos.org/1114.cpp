#include <iostream>
#include <string>
using namespace std;

int n;
string s;
int f[10+2];
char tree[1024*2+2];

void inif()
{
     f[0]=1;
     for (int i=1;i<=11;i++)
         f[i]=f[i-1]*2;
}

void get()
{
     cin>>n>>s;
}

void iniLeaves()
{
     for (int i=f[n];i<f[n+1];i++)
         if (s[i-f[n]]=='0') tree[i]='B';
         else tree[i]='I';
}

void iniTree()
{
     for (int level=n;level>=1;level--)
         for (int i=f[level-1];i<f[level];i++)
         {
             if ((tree[i*2]=='B')&&(tree[i*2+1]=='B')) tree[i]='B';
             else if ((tree[i*2]=='I')&&(tree[i*2+1]=='I')) tree[i]='I';
             else tree[i]='F';
         }
}

void printTree(int i)
{
     if (i>=f[n+1]) return;
     printTree(i*2);
     printTree(i*2+1);
     cout<<tree[i];
}

int main()
{
    inif();
    get();
    iniLeaves();
    iniTree();
    printTree(1);
    //while (1);
    return 0;
}
