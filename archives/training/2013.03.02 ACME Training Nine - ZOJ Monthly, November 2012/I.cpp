//============================================================================
// Name        : test.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstring>
#include <set>
#include<cstdio>
#include<string>
#include<map>
#include <sstream>
using namespace std;

int main()
{
	int n;
	while (cin>>n)
	{
		map<string,set<string> > tips;
		for (int i=0;i<n;i++)
		{
			string w;
			cin>>w,cin.get();
			set<string>& tip=tips[w];
			string line;
			getline(cin,line);
			stringstream sin(line);
			string item;
			while (sin>>item) tip.insert(item);
		}
		int m;
		cin>>m,cin.get();
		for (int i=0;i<m;i++)
		{
			string line;
			getline(cin,line);
			stringstream sin(line);
			string item;
			vector<string> ws;
			while (sin>>item)
				ws.push_back(item);
			set<string> ans;
			ans=tips[ws.front()];
			for (unsigned i=1;i<ws.size();i++)
			{
				set<string>& tip=tips[ws[i]];
				for (set<string>::iterator it=ans.begin();it!=ans.end();)
				{
					if (!tip.count(*it))
					{
						set<string>::iterator tmp=it;
						it++;
						ans.erase(tmp);
					}
					else it++;
				}
			}
			if (ans.empty()) cout<<"NO"<<endl;
			for (set<string>::iterator it=ans.begin();it!=ans.end();)
			{
				cout<<*it;
				cout<<char(++it==ans.end()?'\n':' ');
			}
		}
	}
}
