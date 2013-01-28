#include <iostream>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <cstring>
using namespace std;

enum{ALL_PLAYER=23,PLAYING_PLAYER=11};

int main()
{
    for (;;)
    {
        vector<pair<string,int> > d,m,s,g;
        map<string,int> id;
        for (int i=0;i<ALL_PLAYER;i++)
        {
            string name,position;
            int ability;
            if (cin>>name>>ability>>position)
            {
                if (position=="defender")
                    d.push_back(make_pair(name,ability));
                else if (position=="midfielder")
                    m.push_back(make_pair(name,ability));
                else if (position=="striker")
                    s.push_back(make_pair(name,ability));
                else
                    g.push_back(make_pair(name,ability));
            }
            else return 0;
        }
        vector<int> a;
        vector<pair<string,int> >::iterator it;
        int ds=0,ms,ss,gs;
        ds=0;
        for (it=d.begin();it!=d.end();it++)
        {
            a.push_back(it->second);
            id[it->first]=ds;
            ds++;
        }
        ms=ds;
        for (it=m.begin();it!=m.end();it++)
        {
            a.push_back(it->second);
            id[it->first]=ms;
            ms++;
        }
        ss=ms;
        for (it=s.begin();it!=s.end();it++)
        {
            a.push_back(it->second);
            id[it->first]=ss;
            ss++;
        }
        gs=ss;
        for (it=g.begin();it!=g.end();it++)
        {
            a.push_back(it->second);
            id[it->first]=gs;
            gs++;
        }
        int p[ALL_PLAYER][ALL_PLAYER];
        memset(p,0,sizeof p);
        int M;
        cin>>M;
        for (int i=0;i<M;i++)
        {
            string a,b;
            int profit;
            cin>>a>>b>>profit;
            p[id[a]][id[b]]=profit;
        }
        if (g.size()<1||d.size()<4||m.size()<4||s.size()<2) cout<<"impossible"<<endl;
        else
        {
            int answer=-((~0u)>>1);
            int player[PLAYING_PLAYER];
            for (player[0]=0;player[0]<ds;player[0]++)
            for (player[1]=0;player[1]<player[0];player[1]++)
            for (player[2]=0;player[2]<player[1];player[2]++)
            for (player[3]=0;player[3]<player[2];player[3]++)
            for (player[4]=ds;player[4]<ms;player[4]++)
            for (player[5]=ds;player[5]<player[4];player[5]++)
            for (player[6]=ds;player[6]<player[5];player[6]++)
            for (player[7]=ds;player[7]<player[6];player[7]++)
            for (player[8]=ms;player[8]<ss;player[8]++)
            for (player[9]=ms;player[9]<player[8];player[9]++)
            for (player[10]=ss;player[10]<gs;player[10]++)
            {
                int get=0;
                for (int i=0;i<PLAYING_PLAYER;i++)
                    get+=a[player[i]];
                for (int i=0;i<PLAYING_PLAYER;i++)
                    for (int j=0;j<i;j++)
                    {
                        get+=p[player[i]][player[j]]+p[player[j]][player[i]];
                    }
                if (get>answer) answer=get;
            }
            cout<<answer<<endl;
        }
    }
    return 0;
}

