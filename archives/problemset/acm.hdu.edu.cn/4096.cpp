#include <cstdio>
#include <string>
#include <map>
using namespace std;

enum{MAXN=1000,MAXLENGTH=1024};
struct N
{
    int as,cs,are[MAXN],can[MAXN];
};
struct V
{
    int as,cs,are[MAXN],can[MAXN];
};
int nss,vss;
N ns[MAXN];
V vs[MAXN];
map<string,int> n2i,v2i;
bool nned[MAXN],nved[MAXN],vved[MAXN],vned[MAXN];
bool n_are_n(int,int);
bool n_can_v(int,int);
bool v_can_v(int,int);
bool v_are_n(int,int);
bool n_are_n(int a,int b)
{
    //printf("n%d are n%d\n",a,b);
    if (nned[a]) return false;
    nned[a]=true;
    if (a==b) return true;
    else
    {
        for (int i=0;i<ns[a].as;i++)
            if (n_are_n(ns[a].are[i],b))
                return true;
        for (int i=0;i<ns[a].cs;i++)
            if (v_are_n(ns[a].can[i],b)) return true;
        return false;
    }
}
bool n_can_v(int a,int b)
{
    //printf("n%d can v%d\n",a,b);
    if (nved[a]) return false;
    nved[a]=true;
    for (int i=0;i<ns[a].as;i++)
        if (n_can_v(ns[a].are[i],b))
            return true;
    for (int i=0;i<ns[a].cs;i++)
        if (v_can_v(ns[a].can[i],b)) return true;
    return false;
}
bool v_can_v(int a,int b)
{
    //printf("v%d can v%d\n",a,b);
    if (vved[a]) return false;
    vved[a]=true;
    if (a==b) return true;
    else
    {
        for (int i=0;i<vs[a].as;i++)
            if (n_can_v(vs[a].are[i],b))
                return true;
        for (int i=0;i<vs[a].cs;i++)
            if (v_can_v(vs[a].can[i],b)) return true;
    }
    return false;
}
bool v_are_n(int a,int b)
{
    //printf("v%d are n%d\n",a,b);
    if (vned[a]) return false;
    vned[a]=true;
    for (int i=0;i<vs[a].as;i++)
        if (n_are_n(vs[a].are[i],b))
            return true;
    for (int i=0;i<vs[a].cs;i++)
        if (v_are_n(vs[a].can[i],b)) return true;
    return false;
}
int n_id(string n)
{
    if (!n2i.count(n))
    {
        n2i[n]=nss;
        ns[nss].as=ns[nss].cs=0;
        //printf("%d %s\n",nss,n.c_str());
        nss++;
    }
    return n2i[n];
}
int v_id(string v)
{
    if (!v2i.count(v))
    {
        v2i[v]=vss;
        vs[vss].as=vs[vss].cs=0;
        //printf("%d %s\n",vss,v.c_str());
        vss++;
    }
    return v2i[v];
}

int main()
{
    int T;
    scanf("%d\n",&T);
    for (int t=1;t<=T;t++)
    {
        printf("Case #%d:\n",t);
        n2i.clear();
        v2i.clear();
        nss=0;
        vss=0;
        for (;;)
        {
            char command[MAXLENGTH],a[MAXLENGTH],b[MAXLENGTH];
            gets(command);
            if (strstr(command,"."))
            {
                if (sscanf(command,"everything which can %[a-zA-Z] can %[a-zA-Z].",a,b)==2)
                {
                    int aid=v_id(a),bid=v_id(b);
                    vs[aid].can[vs[aid].cs++]=bid;
                }
                else if (sscanf(command,"everything which can %[a-zA-Z] are %[a-zA-Z].",a,b)==2)
                {
                    int aid=v_id(a),bid=n_id(b);
                    vs[aid].are[vs[aid].as++]=bid;
                }
                else if (sscanf(command,"%[a-zA-Z] are %[a-zA-Z].",a,b)==2)
                {
                    int aid=n_id(a),bid=n_id(b);
                    ns[aid].are[ns[aid].as++]=bid;
                }
                else if (sscanf(command,"%[a-zA-Z] can %[a-zA-Z].",a,b)==2)
                {
                    int aid=n_id(a),bid=v_id(b);
                    ns[aid].can[ns[aid].cs++]=bid;
                }
            }
            else if (strstr(command,"!")) break;
            else
            {
                if (sscanf(command,"can everything which can %[a-zA-Z] %[a-zA-Z]?",a,b)==2)
                {
                    memset(nned,0,sizeof nned);
                    memset(nved,0,sizeof nved);
                    memset(vved,0,sizeof vved);
                    memset(vned,0,sizeof vned);
                    if (v_can_v(v_id(a),v_id(b))) printf("Y");
                    else printf("M");
                }
                else if (sscanf(command,"are everything which can %[a-zA-Z] %[a-zA-Z]?",a,b)==2)
                {
                    memset(nned,0,sizeof nned);
                    memset(nved,0,sizeof nved);
                    memset(vved,0,sizeof vved);
                    memset(vned,0,sizeof vned);
                    if (v_are_n(v_id(a),n_id(b))) printf("Y");
                    else printf("M");
                }
                else if (sscanf(command,"are %[a-zA-Z] %[a-zA-Z]?",a,b)==2)
                {
                    memset(nned,0,sizeof nned);
                    memset(nved,0,sizeof nved);
                    memset(vved,0,sizeof vved);
                    memset(vned,0,sizeof vned);
                    if (n_are_n(n_id(a),n_id(b))) printf("Y");
                    else printf("M");
                }
                else if (sscanf(command,"can %[a-zA-Z] %[a-zA-Z]?",a,b)==2)
                {
                    memset(nned,0,sizeof nned);
                    memset(nved,0,sizeof nved);
                    memset(vved,0,sizeof vved);
                    memset(vned,0,sizeof vned);
                    if (n_can_v(n_id(a),v_id(b))) printf("Y");
                    else printf("M");
                }
            }
        }
        printf("\n");
    }
}

