#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void answer(int n);

int main()
{
    int n;
    for (;;)
    {
        cin>>n;
        if (n==0) break;
        answer(n);
    }
    return 0;
}

void answer(int n)
{
     unsigned int map['Z'+1]['Z'+1];
     for (char i='A';i<'A'+n;i++)
         for (char j='A';j<'A'+n;j++)
             map[i][j]=unsigned(-1);
     for (char i='A';i<='A'+n;i++) map[i][i]=0;
     
     for (int c=1;c<n;c++)
     {
         char from,to;
         int k,length;
         cin>>from>>k;
         for (int i=0;i<k;i++)
         {
             cin>>to>>length;
             map[from][to]=length;
             map[to][from]=length;
         }
     }
     /*
     bool put['Z'+1];
     for (int i='A';i<='Z';i++) put[i]=false;
     
     int total=0;
     put['A']=true;
     
     char min_from,min_to;
     unsigned int min_length;
     for (;;)
     {
         min_length=unsigned(-1);
         for (char i='A';i<'A'+n;i++)
         {
             if (put[i])
                for (char j='A';j<'A'+n;j++)
                    if ((!put[j])&&(map[i][j]<min_length))
                    {
                       min_from=i;
                       min_to=j;
                       min_length=map[i][j];
                    }
         }
     
         put[min_to]=true;
         total+=min_length;
       
         bool end=true;
         for (char j='A';j<'A'+n;j++)
             if (!put[j]) end=false;      
         if (end) break;
     }
     
     cout<<total<<endl;
     */
     bool put['Z'+1];
     for (char i='A';i<'A'+n;i++) put[i]=false;
     int total=0;
     int lowcost['Z'+1];
     
     put['A']=true;
     for (char i='A';i<='Z';i++) lowcost[i]=map['A'][i];
     
     for (char i='B';i<'A'+n;i++)
     {
         unsigned int min=unsigned(-1);
         char to;
         for (char j='A';j<'A'+n;j++)
             if (!put[j]&&lowcost[j]<min)
             {
                min=lowcost[j];
                to=j;
             }
         
         total+=min;
         put[to]=true;
         
         for (char j='A';j<'A'+n;j++)
             if ((!put[j])&&(map[j][to]<lowcost[j]))
                lowcost[j]=map[j][to];
     }
     
     cout<<total<<endl;
}
