#include <iostream>
using namespace std;

const int MAXN=200;
int n,m,q;
char map[MAXN+2][MAXN+2];

void wrong()
{
     cout<<"There must be something wrong..."<<endl;
     exit(0);
}
void f()
{
     for (int i=1;i<=n;i++)
         for (int j=1;j<=n;j++)
             for (int k=1;k<=n;k++)
             {
                 if ((i==j)||(i==k)||(j==k)) continue;
                 /*ik kj ij*/
                 /*
                   1  1  1
                   1  1  0
                   1  0  1
                   0  1  1
                 */
                 /*
                   1  0  0
                   0  1  0
                   0  0  1
                   0  0  0
                 */
                 if ((map[i][k]!=0)&&(map[j][k]!=0))
                 {
                    if (map[i][k]==map[j][k])
                    {
                       if (map[i][j]=='v') wrong();
                       else map[i][j]=map[j][i]='p';
                    }
                    else
                    {
                         if (map[i][j]=='p') wrong();
                         else map[i][j]=='v';
                    }
                 }
                 else if ((map[i][k]!=0)&&(map[i][j]!=0))
                 {
                      if (map[i][k]==map[i][j])
                         map[k][j]=map[j][k]='p';
                      else
                          map[k][j]=map[j][k]='v';
                 }
                 else if ((map[j][k]!=0)&&(map[i][j]!=0))
                 {
                      if (map[j][k]==map[i][j])
                         map[k][i]=map[i][k]='p';
                      else
                          map[k][i]=map[i][k]='v';
                 }
             }
}

int main()
{
    cin>>n>>m>>q;
    for (int i=0;i<m;i++)
    {
        int a,b;
        char c,l;
        cin>>l>>a>>c>>l>>b;
        if ((map[a][b]!=0)&&(map[a][b]!=c)) wrong();
        map[a][b]=c;
        map[b][a]=c;
    }
    f();
    int total=0;
    for (int i=1;i<=n;i++)
           for (int j=i+1;j<=n;j++)
               if (map[i][j]=='p')
                  total++;
    cout<<total<<endl;
    for (int i=0;i<q;i++)
    {
        
        int a,b;
        char l;
        cin>>l>>a>>l>>b;
        if (map[a][b]=='p')
           cout<<"Parallel."<<endl;
        else if(map[a][b]=='v')
             cout<<"Vertical."<<endl;
        else
            cout<<"No idea."<<endl;
    }
    return 0; 
} 
