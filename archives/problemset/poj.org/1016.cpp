#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

int main()
{
    for (;;)
    {
        string seq;
        cin>>seq;
        if (seq=="-1") break;
        bool classified=false;
        string now=seq;
        map<string,int> get;
        get[seq]=0;
        for (int i=1;i<=15;i++)
        {
            vector<int> counter(10,0);
            for (int j=0;j<now.length();j++)
                counter[now[j]-'0']++;
            stringstream ss;
            for (int j=0;j<10;j++)
                if (counter[j]) ss<<counter[j]<<j;
            string next(ss.str());
            map<string,int>::iterator it=get.find(next);
            if (it!=get.end())
            {
               if (i-it->second==1)
               {
                  if (it->second==0) cout<<seq<<" is self-inventorying"<<endl;
                  else cout<<seq<<" is self-inventorying after "<<it->second<<" steps"<<endl;
               }
               else
               {
                   cout<<seq<<" enters an inventory loop of length "<<i-it->second<<endl;
               }
               classified=true;
               break;
            }
            get[now=next]=i;
        }
        if (!classified) cout<<seq<<" can not be classified after 15 iterations"<<endl;
    }
    return 0;
}
