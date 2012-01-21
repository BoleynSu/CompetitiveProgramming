/*
AUTHOR: Su Jiao
DATE: 2010-7-2
DESCRIPTION:
$DESCRIPTION
*/
//Test#1: USACO Training ditch
namespace sj
{
          template<int MAXV,int MAXEDGE>
          class Relabel_To_Front
          {
                public:
                struct rtf_edge{int v,c;rtf_edge* next;rtf_edge* back;};
                struct rtf_list{int u;rtf_list* next;};
                typedef struct rtf_edge* edge_pointer;
                typedef struct rtf_list* list_pointer;
                typedef struct rtf_edge edge;
                typedef struct rtf_list list;
                static edge_pointer adj[MAXV];
                static edge_pointer current[MAXV];
                static int e[MAXV];
                static int h[MAXV];
                static int hn[MAXV*2];
                void add_list(int u,list_pointer& tail)
                {
                     static list pool[MAXV];
                     static list_pointer top=pool;
                     tail->u=u;
                     tail->next=top++;
                     tail=tail->next;
                }
                static int V,E;
                static int s,t;
                void add_edge(int u,int v,int c)
                {
                     static edge pool[MAXEDGE];
                     static edge_pointer top=pool;
                     top->v=v;
                     top->c=c;
                     top->next=adj[u];
                     adj[u]=top++;
                     top->v=u;
                     top->c=0;
                     top->next=adj[v];
                     adj[v]=top++;
                     adj[u]->back=adj[v];
                     adj[v]->back=adj[u];
                }
                #define min(a,b) (a)<(b)?(a):(b)
                #define relabel(_u)\
                {\
                        /*GAP*/\
                        hn[h[(_u)]]--;\
                        if (hn[h[(_u)]]==0&&0<h[(_u)]&&h[(_u)]<V)\
                        {\
                           for (int i=0;i<V;i++)\
                           if (i!=s&&h[(_u)]<h[i]&&h[i]<V+1)\
                           {\
                              hn[h[i]]--;\
                              h[i]=V+1;\
                              hn[h[i]]++;\
                           }\
                        }\
                        \
                        h[(_u)]=V*2-1;\
                        for (edge_pointer i=adj[(_u)];i;i=i->next)\
                            if (i->c&&h[(_u)]>h[i->v]+1)\
                               h[(_u)]=h[i->v]+1;\
                        \
                        /*GAP*/\
                        hn[h[(_u)]]++;\
                }
                #define push(_u,_v)\
                {\
                        int df=min(e[(_u)],(_v)->c);\
                        e[(_u)]-=df;\
                        e[(_v)->v]+=df;\
                        (_v)->c-=df;\
                        (_v)->back->c+=df;\
                }
                #define discharge(_u)\
                {\
                        while (e[(_u)])\
                        {\
                              if (!current[(_u)])\
                              {\
                                 relabel((_u));\
                                 current[(_u)]=adj[(_u)];\
                              }\
                              else if (h[(_u)]==h[current[(_u)]->v]+1\
                                       &&current[(_u)]->c)\
                              {\
                                   push((_u),current[(_u)]);\
                              }\
                              else current[(_u)]=current[(_u)]->next;\
                        }\
                }
                int relabel_to_front(void (*build_network)(Relabel_To_Front*))
                {
                    build_network(this);
                    
                    for (edge_pointer i=adj[s];i;i=i->next)
                    {
                        e[s]-=i->c;
                        e[i->v]+=i->c;
                        i->back->c=i->c;
                        i->c=0;
                    }
                    
                    h[s]=V;
                    
                    /*GAP*/
                    hn[0]=V-1;
                    hn[V]=1;
                    
                    list L;
                    list_pointer head=&L,tail=&L;
                    for (int i=0;i<V;i++)
                        if (i!=s&&i!=t)
                           add_list(i,tail);
                    
                    for (int i=0;i<V;i++) current[i]=adj[i];
                    
                    list_pointer pre=0,u=head;
                    while (u!=tail)
                    {
                          int old_h=h[u->u];
                          discharge(u->u);
                          if (h[u->u]>old_h)
                             if (pre)
                             {
                                pre->next=u->next;
                                u->next=head;
                                head=u;
                             }
                          pre=u;
                          u=u->next;
                    }
                    return e[t];
                }
                #undef min
                #undef relabel
                #undef push
                #undef discharge
          };
          template<int MAXV,int MAXEDGE>
          int Relabel_To_Front<MAXV,MAXEDGE>::V;
          template<int MAXV,int MAXEDGE>
          int Relabel_To_Front<MAXV,MAXEDGE>::E;
          template<int MAXV,int MAXEDGE>
          int Relabel_To_Front<MAXV,MAXEDGE>::s;
          template<int MAXV,int MAXEDGE>
          int Relabel_To_Front<MAXV,MAXEDGE>::t;
          template<int MAXV,int MAXEDGE>
          typename Relabel_To_Front<MAXV,MAXEDGE>::edge_pointer
          Relabel_To_Front<MAXV,MAXEDGE>::adj[MAXV];
          template<int MAXV,int MAXEDGE>
          typename Relabel_To_Front<MAXV,MAXEDGE>::edge_pointer
          Relabel_To_Front<MAXV,MAXEDGE>::current[MAXV];
          template<int MAXV,int MAXEDGE>
          int Relabel_To_Front<MAXV,MAXEDGE>::e[MAXV];
          template<int MAXV,int MAXEDGE>
          int Relabel_To_Front<MAXV,MAXEDGE>::h[MAXV];
          template<int MAXV,int MAXEDGE>
          int Relabel_To_Front<MAXV,MAXEDGE>::hn[MAXV*2];
}
#include <stdio.h>
#include <string.h>
using namespace sj;

#define MAXN 100
#define MAXM 10000

typedef Relabel_To_Front<MAXN+2,4*(MAXN+2)*(MAXN+2)> RTF;

int N,M;
int U[MAXM],V[MAXM],Z[MAXM],C[MAXM];
RTF rtf;
int total;
int first_flow;
RTF::edge* edg1[MAXM];
RTF::edge* edg2[MAXM];
RTF::edge* edg3[MAXM];
RTF::edge* edg4;

void build_network(RTF* that)
{
     scanf("%d%d",&N,&M);
     that->V=N+2;
     that->s=0;
     that->t=N+1;
     for (int i=0;i<M;i++)
     {
         scanf("%d%d%d%d",U+i,V+i,Z+i,C+i);
         if (C[i])
         {
            that->add_edge(that->s,V[i],Z[i]);
            that->add_edge(U[i],that->t,Z[i]);
            total+=Z[i];
            edg1[i]=that->adj[that->s];
            edg2[i]=that->adj[U[i]];
         }
         else
         {
             that->add_edge(U[i],V[i],Z[i]);
             edg3[i]=that->adj[U[i]];
         }
     }
     const int oo=~(1<<31);
     that->add_edge(N,1,oo);
     edg4=that->adj[N];
}
void rebuild_network(RTF* that)
{
     first_flow=edg4->back->c;
     edg4->c=edg4->back->c=0;
     for (int i=0;i<M;i++)
         if (C[i])
         {
            edg1[i]->c=edg1[i]->back->c=0;
            edg2[i]->c=edg2[i]->back->c=0;
         }
     memset(RTF::e,0,sizeof(RTF::e));
     memset(RTF::h,0,sizeof(RTF::h));
     memset(RTF::hn,0,sizeof(RTF::hn));
     that->s=0;
     that->t=1;
     that->V=N+1;
     that->add_edge(that->s,N,first_flow);
}

int main()
{
    int flow=rtf.relabel_to_front(build_network);
    if (flow!=total) printf("Impossible\n");
    else
    {
        int flow=rtf.relabel_to_front(rebuild_network);
        printf("%d\n",first_flow-flow);
        for (int i=0;i<M;i++)
            if (C[i]) printf("%d%c",Z[i],i+1==M?'\n':' ');
            else printf("%d%c",edg3[i]->back->c,i+1==M?'\n':' ');
    }
    return 0;
}
