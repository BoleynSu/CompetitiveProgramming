#include <iostream>
using namespace std;
int n;
char name[10][20];
int give[10];
int to[10][10];
int get[10];
int getID(char* p)
{
    for (int i=0;i<n;i++)
    {
        bool is;
        for (int j=0;j<20;j++)
        {
            is=false;
            if (p[j]!=name[i][j]) break;
            is=true;
            if (p[j]=='\0') break;
        }
        if (is) return i;
    }
}

void o()
{
         for (int i=0;i<n;i++)
         {
             int hm=to[i][9];
             int toG;
             if (hm!=0)
               toG=give[i]/hm;
             else toG=0;
             
             give[i]=toG*hm;
             
             for (int j=0;j<hm;j++)
             {
                 get[to[i][j]]+=toG;
             }
         }
         
         for (int i=0;i<n;i++)
         {
            cout<<name[i]<<' '<<(get[i]-give[i])<<endl;
         }
}

void getAns()
{
     cin>>n;
     while (cin.get()!='\n');
     for (int i=0;i<n;i++)
         cin.getline(name[i],20);
     for (int i=0;i<n;i++)
     {
         char _p[20];
         cin.getline(_p,20);
         int p=getID(_p);
         cin>>give[p];
         int ht;
         cin>>ht;
         while (cin.get()!='\n');
         to[p][9]=ht;
         for (int j=0;j<ht;j++)
         {
             char _p2[20];
             cin.getline(_p2,20);
             to[p][j]=getID(_p2);
         }
     }
     o();
}

int main()
{
    getAns();    
}
