#include <cstdio>
using namespace std;

int stampc,needc;
int stamps[1024];
int needs[1024];

bool tie;
int answer_count;
int answer_kind;
int answer_max_stamp;
int answer_stamp[1024];
int dfs_cache[1024];

int max(int a,int b)
{
    return a>b?a:b;
}

void dfs(int need,int current=0,int count=0,int kind=0,int max_stamp=0)
{
     if (count>4) return;
     if (need<0) return;
     
     if (need==0)
     {
        bool update=false;
        if (kind>answer_kind) update=true;
        else if (kind==answer_kind)
        {
             if (count<answer_count) update=true;
             else if (count==answer_count)
             {
                  if (max_stamp>answer_max_stamp) update=true;
                  else if (max_stamp==answer_max_stamp) tie=true;
             }
        }
        
        if (update)
        {
           answer_count=count;
           answer_kind=kind;
           answer_max_stamp=max_stamp;
           for (int i=0;i<count;i++) answer_stamp[i]=dfs_cache[i];
           tie=false;
        }
        return;
     }
     
     for (int i=current;i<stampc;i++)
         for (int j=1;j<=4-count;j++)
         {
             for (int k=count;k<count+j;k++) dfs_cache[k]=stamps[i];
             dfs(need-stamps[i]*j,i+1,count+j,kind+1,max(max_stamp,stamps[i]));
         }
}

int main()
{
    while (scanf("%d",stamps)!=EOF)
    {
          for (int i=0;stamps[stampc=i];scanf("%d",stamps+(++i))) ;
          for (int i=0;;i++)
          {
              scanf("%d",needs+i);
              if (!needs[needc=i]) break;
          }
          for (int i=0;i<needc;i++)
          {
              tie=false;
              answer_count=0;
              answer_kind=0;
              answer_max_stamp=0;
              dfs(needs[i]);
              if (!answer_count) printf("%d ---- none\n",needs[i]);
              else if (tie)
              {
                   printf("%d (%d): tie\n",needs[i],answer_kind);
              }
              else
              {
                  printf("%d (%d):",needs[i],answer_kind);
                  for (int i=0;i<answer_count;i++) printf(" %d",answer_stamp[i]);
                  printf("\n");
              }
          }
    }
    return 0;
}
