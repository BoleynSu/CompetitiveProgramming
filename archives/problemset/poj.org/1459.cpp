#include <iostream>
#define Max 65535
using namespace std;
int s,t,n,np,nc,m,level;
int h[103],e[103],d[103],list[103][103],f[103][103],c[103][103];
char str[50];
bool visit[103];
int min(int x,int y)
{
  return x<y? x:y;    
}
int max(int x,int y)
{
  return x>y? x:y;    
}
void bfs()
{
  int head,tail,i,x;
  memset(d,0,sizeof(d));
  memset(visit,false,sizeof(visit));
  memset(h,0,sizeof(h));
  d[0]=t;
  head=tail=0;
  visit[t]=true;
  while(head<=tail)
  {
    x=d[head++];
    for(i=0;i<n;i++)
      if(!visit[i]&&c[i][x]>0)
      {
        d[++tail]=i;
        visit[i]=true;
        h[i]=h[x]+1;
      }                 
  }   
  h[s]=n-1;  
}
void init()
{
  int i,x,y,z;
  memset(f,0,sizeof(f));
  memset(c,0,sizeof(c));
  memset(e,0,sizeof(e));
  s=n;
  t=n+1;
  n+=2;
  for(i=1;i<=m;i++)
  {
    scanf("%s",&str);
    sscanf(str,"(%d,%d)%d",&x,&y,&z);
    c[x][y]=z;                 
  }     
  for(i=1;i<=np;i++)
  {
    scanf("%s",&str);
    sscanf(str,"(%d)%d",&x,&z);
    c[s][x]=z;                
  }
  for(i=1;i<=nc;i++)
  {
    scanf("%s",&str);
    sscanf(str,"(%d)%d",&x,&z);
    c[x][t]=z;                
  }
  bfs();
  memset(list,0,sizeof(list));
  for(i=0;i<n;i++)
    if(c[s][i]>0)
    {
      e[s]-=c[s][i];
      e[i]+=c[s][i];
      f[s][i]+=c[s][i];
      f[i][s]=-f[s][i];             
    }
  for(i=0;i<n-2;i++)
  if(e[i]>0)
  {
    list[h[i]][0]++;
    x=list[h[i]][0];
    list[h[i]][x]=i; }
}
void push(int u,int v)
{
  int tem,x;
  tem=min(e[u],c[u][v]-f[u][v]);
  if(e[v]==0&&v!=s&&v!=t)
  {
    list[h[v]][0]++;
    x=list[h[v]][0];
    list[h[v]][x]=v;
    if(h[v]>level)
      level=h[v];           
  }
  e[u]-=tem;
  e[v]+=tem;
  f[u][v]+=tem;
  f[v][u]=-f[u][v];     
}
void relabel(int v)
{
  int i,mh=Max;
  for(i=0;i<n;i++)
    if(i!=v&&h[i]>=h[v]&&c[v][i]-f[v][i]>0)
      mh=min(mh,h[i]);
  h[v]=mh+1;
  level=h[v];
  list[level][0]++;
  list[level][1]=v; 
}
void push_relabel()
{
  int i,v,tem,flag;
  level=0;
  for(i=0;i<n-2;i++)
    if(e[i]>0)
      level=max(level,h[i]);
  while(level)
  {
    tem=list[level][0];
    v=list[level][tem];
    list[level][0]--;
    while(level>0&&list[level][0]==0)
      level--;
    flag=false;
    for(i=0;i<n;i++)
    {
      if(e[v]==0) break;
      if(h[i]+1==h[v]&&c[v][i]-f[v][i]>0)
      {
        push(v,i);
        flag=true;
      }
    }
    if(!flag||e[v]>0)
      relabel(v);
  }
}
int main()
{
  while(scanf("%d%d%d%d",&n,&np,&nc,&m)!=EOF)
  {
    init();
    push_relabel();    
    cout<<e[t]<<endl;                                      
  }    
  return 0;
}