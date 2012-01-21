/*
ID: sujiao1
PROG: butter
LANG: C++
*/
#include <fstream>
using std::ifstream;
using std::ofstream;
using std::endl;
#include <ctime>
using std::clock;
#include <cstring>
using std::memset;

struct List
{
       List* next;
       int data;
       List(int _data):next(0),data(_data){}
       ~List()
       {
              delete[] next;
       }
       List& insert(int _data)
       {
             delete[] next;
             next=new List(_data);
             return *this;
       }
};

class Application
{
      ifstream cin;
      ofstream cout;
      static const int MAXN=500;//1 to 500
      static const int MAXP=800;//2 to 800
      static const int MAXC=1450;//1 to 1450
      static const int oo=2147483647;
      int N,P,C;
      int* cow;
      int** map;
      List** link;
      int* dist;
      bool* visited;
      int* q;
      int answer;
      public:
      Application() :cin("butter.in"),cout("butter.out"),answer(oo)   
      {
                    cin>>N>>P>>C;
                    
                    cow=new int[N+2];
                    map=new int*[P+2];
                    for (int i=1;i<=P;i++)
                        map[i]=new int[P+2];
                    link=new List*[P+2];
                    dist=new int[P+2];
                    visited=new bool[P+2];
                    q=new int[P+2];
                    memset(link,0,sizeof(List*)*(P+2));
                    
                    for (int i=1;i<=N;i++)
                        cin>>cow[i];
                    for (int i=1;i<=C;i++)
                    {
                        int a,b,c;
                        cin>>a>>b>>c;
                        map[a][b]=c;
                        map[b][a]=c;
                        
                        if (link[a]==0)
                        {
                           link[a]=new List(b);
                        }
                        else
                        {
                            List* j;
                            for (j=link[a];j->next!=0;j=j->next) ;//do nothing
                            j->insert(b);
                        }
                        
                        if (link[b]==0)
                        {
                           link[b]=new List(a);
                        }
                        else
                        {
                            List* j;
                            for (j=link[b];j->next!=0;j=j->next) ;//do nothing
                            j->insert(a);
                        }
                    }
      }
      ~Application()
      {
                    delete[] q;
                    delete[] visited;
                    delete[] dist;
                    delete[] link;
                    for (int i=1;i<=P;i++)
                        delete[] map[i];
                    delete[]map;
                    delete[] cow;
                    cin.close();
                    cout.close();
      }
      void SPFA(int source)
      {
           memset(visited,false,sizeof(bool)*(P+2));
           int close,open;
           close=1;
           open=1;
           q[close]=source;
           visited[source]=true;
		   for (int i=1;i<=P;i++) dist[i]=oo;
           dist[source]=0;
           
           while (close<=open)
           {
                 //cout<<close<<"cl"<<open<<"op"<<endl;
                 int now=q[close%P];
                 close++;
                 visited[now]=false;
                 for (List* i=link[now];i!=0;i=i->next)
                 {
                     int next=i->data;
                     if ((dist[now]!=oo)&&(dist[next]>dist[now]+map[now][next]))
                     {
                        dist[next]=dist[now]+map[now][next];
                        if (!visited[next])
                        {
                           //cout<<next<<" "<<now<<endl;
                           visited[next]=true;
                           open++;
                           q[open%P]=next;
                        }
                     }
                 }
           }
           //for (int i=1;i<=P;i++) cout<<dist[i]<<" ";cout<<endl;
      }
      int run()
      {
          for (int i=1;i<=P;i++)
          {
              SPFA(i);
              int nanswer=0;
              for (int j=1;j<=N;j++)
              {
                  nanswer+=dist[cow[j]];
                  if (dist[cow[j]]==oo)
                  {
                     nanswer=oo;
                     break;
                  }
              }
              if (nanswer<answer) answer=nanswer;
          }
          cout<<answer<<endl;
          //cout<<clock()<<endl;
          return 0;
      }
};

int main()
{
    Application app;
    return app.run();
}
