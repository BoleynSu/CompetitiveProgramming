#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int main()
{
    int n;
    cin>>n;
    map<string,int> point;
    for (int i=0;i<n;i++)
    {
        string u;
        int p;
        cin>>u>>p;
        point[u]=max(point[u],p);
    }
    vector<pair<string,int> > pv;
    for (map<string,int>::iterator it=point.begin();it!=point.end();it++)
        pv.push_back(make_pair(it->first,it->second));
    cout<<pv.size()<<endl;
    for (int i=0;i<pv.size();i++)
    {
        int b=0,w=0,e=0;
        for (int j=0;j<pv.size();j++)
            if (pv[j].second>pv[i].second) b++;
            else if (pv[j].second<pv[i].second) w++;
            else e++;
        cout<<pv[i].first<<" ";
        if (b*2>pv.size()) cout<<"noob"<<endl;
        else if ((w+e)*2>=pv.size()&&b*5>pv.size()) cout<<"random"<<endl;
        else if ((w+e)*5>=pv.size()*4&&b*10>pv.size()) cout<<"average"<<endl;
        else if ((w+e)*10>=pv.size()*9&&b*100>pv.size()) cout<<"hardcore"<<endl;
        else if ((w+e)*100>=pv.size()*99) cout<<"pro"<<endl;
    }
}

