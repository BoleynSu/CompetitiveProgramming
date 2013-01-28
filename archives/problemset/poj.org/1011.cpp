#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

int n;
int l[1024];
bool used[1024];
int length;

bool possible(int used_count=0,int current_length=0)
{
     if (used_count==n) return true;
     
     if (current_length==length) current_length=0;
     
     for (int i=0;i<n;i++)
         if (!used[i])
         {
            if (current_length+l[i]>length) continue;
            used[i]=true;
            if (possible(used_count+1,current_length+l[i])) return true;
            used[i]=false;
            if (l[i]+current_length==length||current_length==0) break;
         }
     return false;
}

int main()
{
    for (;;)
    {
        scanf("%d",&n);
        if (!n) break;
        int sum=0;
        int max=0;
        for (int i=0;i<n;i++)
        {
            scanf("%d",l+i);
            sum+=l[i];
            if (l[i]>max) max=l[i];
        }
        for (int i=0;i<n;i++) used[i]=false;
        sort(l,l+n,greater<int>());
        
        for (length=max;;length++)
            if (sum%length==0)
               if (possible())
               {
                  printf("%d\n",length);
                  break;
               }
    }
    return 0;
}
