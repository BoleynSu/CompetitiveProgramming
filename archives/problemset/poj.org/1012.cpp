/*
#include <iostream>
using namespace std;

struct list
{
       list* next;
       int id;
};

bool possible(int k,int m)
{
     list lists[k*2];
     for (int i=0;i<k*2;i++)
     {
         lists[i].next=lists+(i+1)%(k*2);
         lists[i].id=i+1;
     }
     list* pre_position=lists+((m-2)+(k*2))%(k*2);
     for (int i=1;i<=k;i++)
     {
         if (pre_position->next->id<=k) return false;
         pre_position->next=pre_position->next->next;
         for (int j=1;j<=(m-1)%(k*2-i);j++)
             pre_position=pre_position->next;
     }
     return true;
}

int main()
{
    cout<<"int table[]={0";
    for (int i=1;i<=13;i++)
    {
        for (int m=1;;m++)
            if (possible(i,m))
            {
               cout<<","<<m;
               break;
            }
    }
    cout<<"};"<<endl;
    while (cin.get()!='q') ;
    return 0;
}
*/
#include <iostream>
using namespace std;
int table[]={0,2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881};

int main()
{
    int k;
    while (cin>>k)
    {
          if (k) cout<<table[k]<<endl;
          else break;
    }
    return 0;
}
